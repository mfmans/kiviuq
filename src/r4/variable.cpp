/*
	$ [KiPHP] /r4/variable.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			4

#include "../kiviuq.h"




/* 超全局变量表 */
TBL1<r2_variable_t, r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_sensitive, NULL> *	r4_variable::super	= NULL;

/* 堆变量表 */
TBL1<r2_variable_t, r2_hash::size_small, NULL, r4_variable::handler_index, r4_variable::handler_compare, r4_variable::handler_delete> *		r4_variable::heap	= NULL;




KI_LOADER_BOOT (r4_variable) {
	// 创建超全局变量表
	r4_variable::super	= new TBL1<r2_variable_t, r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_sensitive, NULL>;
	// 创建堆变量表
	r4_variable::heap	= new TBL1<r2_variable_t, r2_hash::size_small, NULL, r4_variable::handler_index, r4_variable::handler_compare, r4_variable::handler_delete>;

	// 注册超全局变量
	r4_variable::register_super ("GLOBALS");
	r4_variable::register_super ("_SERVER");
	r4_variable::register_super ("_GET");
	r4_variable::register_super ("_POST");
	r4_variable::register_super ("_FILES");
	r4_variable::register_super ("_COOKIE");
	r4_variable::register_super ("_REQUEST");
	r4_variable::register_super ("_SESSION");
	r4_variable::register_super ("_ENV");
}


KI_LOADER_SHUTDOWN (r4_variable) {
	// 销毁超全局变量表
	delete r4_variable::super;

	// 销毁堆变量表
	delete r4_variable::heap;
}




r4_variable::r4_variable (const STR1 *name_class, const STR1 *name_function, unsigned int offset) {
	// 判断全局作用域
	if(name_function == NULL) {
		this->global	= true;

		// 全局变量前缀
		this->prefix	= new STR1 ("@");
	} else {
		this->global	= false;

		this->prefix	= new STR1 ( );

		// 类名前缀
		if(name_class == NULL) {
			this->prefix->concat ("::");
		} else {
			this->prefix->concat ("%s::", name_class->pointer ( ));
		}

		// 函数名前缀
		this->prefix->concat ("%s@", name_function->pointer ( ));
	}

	// 保存栈底偏移量
	this->offset	= offset;

	// 创建栈变量表
	this->stack		= new TBL1<r2_variable_t, r2_hash::size_small, NULL, r4_variable::handler_index, r4_variable::handler_compare, r4_variable::handler_delete>;
}


r4_variable::~r4_variable (void) {
	// 销毁前缀
	delete this->prefix;

	// 销毁栈变量表
	delete this->stack;
}




unsigned int r4_variable::handler_index (const STR1 *p) {
	// 名称
	const char *	buffer	= p->pointer ( );
	// 名称长度
	unsigned int	length	= p->length ( );

	// 判断是否为超全局变量
	if(* buffer != '#') {
		// 不带前缀名称
		const char *	start	= strchr (buffer, '@');

		length	= length - (start - buffer);
		buffer	= start;
	}

	return r2_hash::handler_index (buffer, length, r2_hash::max_short);
}


bool r4_variable::handler_compare (const STR1 *p1, const STR1 *p2) {
	const char *	buffer_1	= p1->pointer ( );
	const char *	buffer_2	= p2->pointer ( );

	// 比较名称
	if(strcmp (buffer_1, buffer_2) == 0) {
		return true;
	} else {
		return false;
	}
}


void r4_variable::handler_delete (r2_variable_t p) {
	if(p == NULL) {
		return;
	}

	// 销毁变量名
	delete p->name;

	// 销毁变量
	delete p;
}




r2_variable_t r4_variable::add_heap (const STR1 *name) {
	r2_variable_t	var		= newz r2_variable_o;

	var->name		= new STR1 (name);
	var->line		= RCD4::line;
	var->offset		= r4_variable::heap->count;

	// 添加到堆变量表
	r4_variable::heap->write (name, var);

	return var;
}


r2_variable_t r4_variable::add_stack (const STR1 *name) {
	r2_variable_t	var		= newz r2_variable_o;

	var->name		= new STR1 (name);
	var->line		= RCD4::line;
	var->offset		= this->stack->count;

	// 添加到栈变量表
	this->stack->write (name, var);

	return var;
}




/* 获取变量 */

r2_variable_t r4_variable::fetch_heap (const STR1 *name) {
	r2_variable_t	var		= (* r4_variable::heap) [name];

	// 添加到堆变量表
	if(var == NULL) {
		var	= r4_variable::add_heap (name);

		// 修正新添加的堆变量偏移量
		var->offset --;
	}

	return var;
}


r2_variable_t r4_variable::fetch_stack (const STR1 *name) {
	r2_variable_t	var		= (* this->stack) [name];

	// 添加到栈变量表
	if(var == NULL) {
		var	= this->add_stack (name);

		// 修正新添加的栈变量偏移量
		var->offset	= this->offset + var->offset - 1;
	}

	return var;
}




/* 更新操作数 */
void r4_variable::update (r2_variable_t var, r2_code_directive_operand_address_base_e base, r2_code_directive_operand_t operand) {
	// 更新引用次数
	var->reference ++;

	// 更新操作数
	operand->type				= R2_CD_OPND_ADDRESS;
	operand->v._address.base	= base;
	operand->v._address.offset	= (signed int) var->offset;
}




/* 注册超全局变量 */

void r4_variable::register_super (const char *p) {
	STR1	name	("%s", p);

	r4_variable::register_super (& name);
}


void r4_variable::register_super (const STR1 *p) {
	// 超全局变量名
	STR1	name	("#%s", p->pointer ( ));

	// 判断变量是否存在
	if(r4_variable::super->exist (name) == true) {
		return;
	}

	// 添加到堆变量表
	r2_variable_t	var		= r4_variable::add_heap (& name);

	// 设置超全局变量标记
	var->super	= true;

	// 添加到超全局变量表
	r4_variable::super->write (p, var);
}




/* 注册静态变量 */
bool r4_variable::register_static (const STR1 *p, r2_code_directive_operand_t operand_old, r2_code_directive_operand_t operand_new) {
	// 判断是否为超全局变量
	if(r4_variable::super->exist (p) == true) {
		RCD4::warning (true, "对超全局变量 $%s 使用 static 关键词无效。", p->pointer ( ));

		return false;
	}

	// 判断全局作用域
	if(this->global == true) {
		RCD4::warning (true, "对全局变量 $%s 使用 static 关键词无效。", p->pointer ( ));

		return false;
	}

	STR1	name;

	// 内部变量名
	name	+= this->prefix;
	name	+= p;

	// 在栈中查找变量
	r2_variable_t	var_stack	= this->fetch_stack (& name);

	// 在堆中查找变量
	r2_variable_t	var_heap	= r4_variable::fetch_heap (& name);

	// 栈变量地址
	r4_variable::update (var_stack,	R2_CD_OPND_ADDRESS_BOTTOM,	operand_old);

	// 堆变量地址
	r4_variable::update (var_heap,	R2_CD_OPND_ADDRESS_HEAP,	operand_new);

	return true;
}


/* 注册全局变量 */
bool r4_variable::register_global (const STR1 *p, r2_code_directive_operand_t operand_old, r2_code_directive_operand_t operand_new) {
	// 判断是否为超全局变量
	if(r4_variable::super->exist (p) == true) {
		RCD4::warning (true, "对超全局变量 $%s 使用 global 关键词无效。", p->pointer ( ));

		return false;
	}

	// 判断是否为全局作用域
	if(this->global == true) {
		STR1	name;

		// 内部变量名
		name	+= this->prefix;
		name	+= p;

		// 作为全局变量查找
		r2_variable_t	var		= r4_variable::fetch_heap (& name);

		// 设置可见性
		var->visible	= true;

		// 输出警告
		RCD4::warning (true, "在全局作用域中，对全局变量 $%s 使用 global 关键词，行为与标准 PHP 不一致，此处将会把变量导出。不推荐使用这种用法，如需导出变量，请使用编译杂注 #!export 或 -Ev 参数。", p->pointer ( ));

		return false;
	}

	STR1	name_stack;
	STR1	name_heap;

	// 栈变量名
	name_stack	+= this->prefix;
	name_stack	+= p;

	// 堆变量名
	name_heap	+= "@";
	name_heap	+= p;

	// 在栈中查找变量
	r2_variable_t	var_stack	= this->fetch_stack (& name_stack);

	// 在堆中查找变量
	r2_variable_t	var_heap	= r4_variable::fetch_heap (& name_heap);

	// 栈变量地址
	r4_variable::update (var_stack,	R2_CD_OPND_ADDRESS_BOTTOM,	operand_old);

	// 堆变量地址
	r4_variable::update (var_heap,	R2_CD_OPND_ADDRESS_HEAP,	operand_new);

	return true;
}




/* 使用变量 */
void r4_variable::use (const STR1 *p, r2_code_directive_operand_t operand) {
	// 判断是否为超全局变量
	if(r4_variable::super->exist (p) == true) {
		// 获取堆中的超全局变量信息
		r2_variable_t	var		= (* r4_variable::super) [p];

		r4_variable::update (var, R2_CD_OPND_ADDRESS_HEAP, operand);

		return;
	}

	STR1	name;

	// 内部变量名
	name	+= this->prefix;
	name	+= p;

	// 判断是否在全局作用域
	if(this->global == true) {
		// 在堆中查找
		r2_variable_t	var		= r4_variable::fetch_heap (& name);

		r4_variable::update (var, R2_CD_OPND_ADDRESS_HEAP, operand);
	} else {
		// 在堆中查找
		r2_variable_t	var		= this->fetch_stack (& name);

		r4_variable::update (var, R2_CD_OPND_ADDRESS_BOTTOM, operand);
	}
}


