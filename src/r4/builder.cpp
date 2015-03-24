/*
	$ [KiPHP] /r4/builder.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			4

#include "../kiviuq.h"




/* 获取全局变量 */
r2_variable_t r4_builder::variable_fetch (const STR1 *name) {
	r2_variable_t	node	= (* RCD4::table_variable) [name];

	// 判断变量是否不存在
	if(node == NULL) {
		node		= newz r2_variable_o;

		node->name	= new STR1 (name);

		// 保存到全局变量表
		RCD4::table_variable->write (name, node);
	}

	return node;
}


/* 导出全局变量 */
void r4_builder::variable_export (const STR1 *name) {
	r2_variable_t	node	= r4_builder::variable_fetch (name);

	if(node->visible == false) {
		node->visible		= true;
		node->line_export	= RCD4::line;
	}
}




/* 进入函数 */
void r4_builder::function_enter (const STR1 *name) {
	if(RCD4::function != NULL) {
		O0::runtime ("进入函数定义失败，其它函数正在被定义。");
	}

	if(RCD4::cls == NULL) {
		RCD4::function	= r4_builder::function_fetch (name);

		// 根据函数入口判断是否已被定义
		if(RCD4::function->entry != NULL) {
			RCD4::error (true, "函数 %s 重复定义，上一次定义位于第 %u 行。", name->pointer ( ), RCD4::function->line_declare);
		}

		// 判断是否默认为内联函数
		if(C3(enable_inline) == false) {
			RCD4::function->visible		= true;
		}

		// 创建函数变量分配器
		RCD4::var	= new VAR4 (NULL, name);
	} else {
		r2_class_method_t	method	= (* RCD4::cls->_method) [name];

		// 判断方法是否已被定义
		if(method != NULL) {
			RCD4::error (true, "方法 %s::%s 重复定义，上一次定义位于第 %u 行。", RCD4::cls->name->pointer ( ), name->pointer ( ), method->line_declare);
		}

		// 创建方法
		method	= newz r2_class_method_o;

		method->name	= new STR1 (name);

		method->feature (RCD4::class_feature);

		// 保存到方法表
		RCD4::cls->_method->write (name, method);

		// 指向方法
		RCD4::function	= method;

		// 当前代码指向入口代码
		RCD4::code		= RCD4::cls->code_entry;

		// 创建方法变量分配器
		RCD4::var		= new VAR4 (RCD4::cls->name, name);
	}

	// 入口标签
	r2_code_t	label	= COD4::label ( );

	// 保存标签
	* RCD4::code	+= label;

	// 更新入口
	RCD4::function->entry			= label;

	// 设置定义行数
	RCD4::function->line_declare	= RCD4::line;
}


/* 退出函数 */
void r4_builder::function_leave (void) {
	if(RCD4::function == NULL) {
		O0::runtime ("退出函数定义失败，没有函数正在被定义。");
	}

	RCD4::function	= NULL;

	// 删除变量分配器
	delete RCD4::var;

	if(RCD4::cls == NULL) {
		// 将当前变量分配器映射为全局变量分配器
		RCD4::var	= RCD4::var_global;
	} else {
		RCD4::var	= NULL;

		// 当前代码指向启动代码
		RCD4::code	= RCD4::cls->code_boot;
	}
}


/* 调用函数 */
r2_function_t r4_builder::function_call (const STR1 *name, r2_code_directive_operand_t p) {
	r2_function_t	node	= r4_builder::function_fetch (name);

	// 判断是否为第一次调用
	if(node->line_call == 0) {
		node->line_call	= RCD4::line;
	}

	// 保存到调用表
	* node->caller	+= p;

	return node;
}


/* 获取函数 */
r2_function_t r4_builder::function_fetch (const STR1 *name) {
	r2_function_t	node	= (* RCD4::table_function) [name];

	// 判断函数是否不存在
	if(node == NULL) {
		node	= newz r2_function_o;

		node->name		= new STR1 (name);
		node->caller	= new LST1<r2_code_directive_operand_t>;

		// 保存到函数表
		RCD4::table_function->write (name, node);
	}

	return node;
}


/* 导出函数 */
void r4_builder::function_export (const STR1 *name) {
	r2_function_t	node	= r4_builder::function_fetch (name);

	if(node->visible == false) {
		node->visible		= true;
		node->line_export	= RCD4::line;
	}
}




/* 进入类 */
void r4_builder::class_enter (const STR1 *name) {
	if(RCD4::cls != NULL) {
		O0::runtime ("进入类定义失败，其它类正在被定义。");
	}

	// 判断类是否已被定义
	if(RCD4::table_class->exist (name) == true) {
		r2_class_t	last	= (* RCD4::table_class) [name];

		RCD4::error (true, "类 %s 重复定义，上一次定义位于第 %u 行。", name->pointer ( ), last->line);
	}

	// 创建类
	RCD4::cls	= r4_builder::class_fetch (name);

	// 初始化类成员特性
	RCD4::class_feature		= newz r2_class_feature_o;

	// 当前代码指向启动代码
	RCD4::code		= RCD4::cls->code_boot;

	// 没有变量分配器
	RCD4::var		= NULL;

	// 没有定义任何函数
	RCD4::function	= NULL;
}


/* 退出类 */
void r4_builder::class_leave (void) {
	if(RCD4::cls == NULL) {
		O0::runtime ("退出类定义失败，没有类正在被定义。");
	}

	// 删除类成员特性
	delete RCD4::class_feature;

	RCD4::class_feature	= NULL;

	// 当前代码映射为全局代码
	RCD4::code	= RCD4::code_global;

	// 当前变量分配器映射为全局变量分配器
	RCD4::var	= RCD4::var_global;

	// 终止类定义
	RCD4::cls	= NULL;

	// 终止函数定义
	RCD4::function	= NULL;
}


/* 类实现接口 */
void r4_builder::class_implement (const STR1 *name) {
	if(RCD4::cls == NULL) {
		O0::runtime ("更新类定义失败，没有类正在被定义。");
	}

	// 判断接口是否已被实现
	if(RCD4::cls->_implement->exist (name) == true) {
		RCD4::error (true, "类 %s 重复实现接口 %s。", RCD4::cls->name->pointer ( ), name->pointer ( ));
	}

	RCD4::cls->_implement->write (name, new STR1 (name));
}


/* 类常量定义 */
void r4_builder::class_declare_const (const STR1 *name, r2_code_directive_operand_t operand) {
	if(RCD4::cls == NULL) {
		O0::runtime ("更新类定义失败，没有类正在被定义。");
	}

	// 判断常量是否被定义
	if(RCD4::cls->_const->exist (name) == true) {
		r2_class_const_t	last	= (* RCD4::cls->_const) [name];

		RCD4::error (true, "类常量 %s::%s 重复定义，上一次定义位于第 %u 行。", RCD4::cls->name->pointer ( ), name->pointer ( ), last->line);
	}

	r2_class_const_t	node	= newz r2_class_const_o;

	node->name	= new STR1 (name);
	node->line	= RCD4::line;

	// 保存常量内容
	M0::copy (& node->value, operand, sizeof node->value);

	// 保存到类常量表
	RCD4::cls->_const->write (name, node);
}


/* 类属性定义 */
void r4_builder::class_declare_property (const STR1 *name) {
	if(RCD4::cls == NULL) {
		O0::runtime ("更新类定义失败，没有类正在被定义。");
	}

	// 判断类是否被定义
	if(RCD4::cls->_property->exist (name) == true) {
		r2_class_property_t		last	= (* RCD4::cls->_property) [name];

		RCD4::error (true, "类属性 %s::$%s 重复定义，上一次定义位于第 %u 行。", RCD4::cls->name->pointer ( ), name->pointer ( ), last->line);
	}

	r2_class_property_t		node	= newz r2_class_property_o;

	node->name	= new STR1 (name);
	node->line	= RCD4::line;

	// 保存类特性
	node->feature (RCD4::class_feature);

	// 保存到类属性表
	RCD4::cls->_property->write (name, node);
}


/* 获取类 */
r2_class_t r4_builder::class_fetch (const STR1 *name, LST1<r2_code_t> *code) {
	r2_class_t	node	= (* RCD4::table_class) [name];

	// 判断类是否不存在
	if(node == NULL) {
		node	= newz r2_class_o;

		node->name		= new STR1 (name);
		node->line		= RCD4::line;

		node->_implement	= new TBL1<STR1 *, r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive, r2_hash::handler_delete> ( );

		node->_const		= new TBL1<r2_class_const_t,	r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_sensitive,		r2_class::handler_delete_const>		( );
		node->_property		= new TBL1<r2_class_property_t,	r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_sensitive,		r2_class::handler_delete_property>	( );
		node->_method		= new TBL1<r2_class_method_t,	r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_insensitive,	r2_class::handler_delete_method>	( );

		// 启动代码
		node->code_boot		= new LST1<r2_code_t> ( );

		// 入口代码
		if(code == NULL) {
			node->code_entry	= new LST1<r2_code_t> ( );
		} else {
			node->code_entry	= code;
		}

		// 保存到类表
		RCD4::table_class->write (name, node);
	}

	return node;
}




/* 最后整理生成 */
void r4_builder::collect (void) {
	// 合并堆全局变量
	if(VAR4::heap->ready ( ) == true) {
		r2_variable_t	var;

		while(VAR4::heap->fetch (& var) == true) {
			// 判断是否为超全局变量
			if(var->super == true) {
				continue;
			}

			const char *	p	= var->name->pointer ( );

			// 判断是否为静态变量
			if(* p != '@') {
				continue;
			}

			// 实际变量名
			STR1	name	("%s", p + 1);

			// 从全局变量表中获取变量
			r2_variable_t	node	= r4_builder::variable_fetch (& name);

			node->line		= var->line;
			node->offset	= var->offset;
		}
	}

	// 遍历全局变量
	if(RCD4::table_variable->ready ( ) == true) {
		r2_variable_t	var;

		while(RCD4::table_variable->fetch (& var) == true) {
			// 判断是否导出且未定义
			if((var->visible == true) && (var->offset == 0)) {
				if(var->line_export == 0) {
					RCD4::warning (false, "使用 -Ev 参数尝试导出未定义的全局变量 $%s。", var->name->pointer ( ));
				} else {
					RCD4::warning (var->line_export, "使用编译杂注 #!export 尝试导出未定义的全局变量 $%s。", var->name->pointer ( ));
				}
			}
		}
	}

	// 遍历函数
	if(RCD4::table_function->ready ( ) == true) {
		r2_function_t	node;

		while(RCD4::table_function->fetch (& node) == true) {
			// 判断是否导出
			if(node->visible == true) {
				// 判断是否未定义
				if(node->entry == NULL) {
					if(node->line_export == 0) {
						RCD4::warning (false, "使用 -Ef 参数尝试导出未定义的函数 %s。", node->name->pointer ( ));
					} else {
						RCD4::warning (node->line_export, "使用编译杂注 #!export 尝试导出未定义的函数 %s。", node->name->pointer ( ));
					}
				}
			} else {
				// 判断是否未被使用
				if(node->caller->count == 0) {
					RCD4::warning (node->line_declare, "内联函数 %s 未被调用且外部不可见。", node->name->pointer ( ));
				}
			}

			// 整理函数
			r4_builder::collect_function (node);
		}
	}

	// 判断是否虚拟机封装类名冲突
	if(RCD4::table_class->exist (C3(vm_wrapper)) == true) {
		r2_class_t	node	= (* RCD4::table_class) [C3(vm_wrapper)];

		RCD4::error (node->line, "类 %s 名称冲突，与虚拟机封装类类名相同。", node->name->pointer ( ));
	}

	// 整理虚拟机
	r4_builder::collect_vm ( );

	// 遍历类
	if(RCD4::table_class->ready ( ) == true) {
		r2_class_t	node;

		while(RCD4::table_class->fetch (& node) == true) {
			if(node->_method->exist (C3(vm_entry)) == true) {
				r2_class_method_t	method	= (* node->_method) [C3(vm_entry)];

				RCD4::error (method->line_declare, "方法 %s::%s 名称冲突，与虚拟机调用入口方法名相同。", node->name->pointer ( ), method->name->pointer ( ));
			}

			// 整理类
			r4_builder::collect_class (node);
		}
	}
}


/* 整理虚拟机 */
void r4_builder::collect_vm (void) {
	// 创建类
	r2_class_t	node	= r4_builder::class_fetch (C3(vm_wrapper), RCD4::code_global);

	node->_final	= true;

	node->code_boot->ready ( );

	// 创建堆属性
	r2_class_property_t		heap	= newz r2_class_property_o;

	// 堆属性名称
	heap->name	= new STR1 (C3(vm_heap));

	// 堆属性类型
	heap->access	= R2_CLS_FTR_ACCESS_PUBLIC;
	heap->_final	= true;
	heap->_static	= true;

	// 保存到类属性表
	node->_property->write (C3(vm_heap), heap);

	// 创建构造方法
	r2_class_method_t	method	= newz r2_class_method_o;

	// 构造方法名称
	method->name	= new STR1 ("__construct");

	// 构造方法属性类型
	method->access	= R2_CLS_FTR_ACCESS_PRIVATE;

	// 保存到类方法表
	node->_method->write ("__construct", method);

	// 导出超全局变量
	if(VAR4::heap->ready ( ) == true) {
		r2_variable_t	var;

		while(VAR4::heap->fetch (& var) == true) {
			if(var->super == false) {
				continue;
			}

			STR1	name	("%s", var->name->pointer ( ) + 1);

			r2_code_t	code	= COD4::directive (R2_CD_OPC_REF, "AhD", var->offset, & name);

			* node->code_boot	+= code;
		}
	}
}


/* 整理函数 */
void r4_builder::collect_function (r2_function_t node) {
	r2_code_directive_operand_t	operand;

	node->caller->ready ( );

	// 判断是否定义
	if(node->entry == NULL) {
		while(node->caller->fetch (& operand) == true) {
			COD4::operand (operand, "D", node->name);
		}
	} else {
		while(node->caller->fetch (& operand) == true) {
			COD4::operand (operand, "L", node->entry);
		}
	}
}


/* 整理类 */
void r4_builder::collect_class	(r2_class_t node) {
	// 初始化返回指令
	r2_code_t	code	= COD4::directive (R2_CD_OPC_RETN, NULL);

	node->code_boot ->ready ( );
	node->code_entry->ready ( );

	// 创建标签
	node->label_code_boot	= COD4::label ( );
	node->label_code_entry	= COD4::label ( );

	// 插入标签
	node->code_boot ->insert (node->label_code_boot,	false);
	node->code_entry->insert (node->label_code_entry,	false);

	// 插入初始化返回指令
	node->code_entry->insert (code, false);

	// 创建完整代码
	node->code	= new LST1<r2_code_t, r2_class::handler_delete_code>;

	// 合并代码
	node->code->concat (node->code_boot);
	node->code->concat (node->code_entry);
}


