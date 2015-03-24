/*
	$ [KiPHP] /r4/recorder.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			4

#include "../kiviuq.h"




/* 已处理行 */
unsigned int	r4_recorder::line	= 0;
/* 已处理字节 */
unsigned int	r4_recorder::byte	= 0;


/* 全局变量表 */
TBL1<r2_variable_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_sensitive,	r4_recorder::handler_delete_variable> *		r4_recorder::table_variable	= NULL;

/* 函数表 */
TBL1<r2_function_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_function> *		r4_recorder::table_function	= NULL;

/* 类表 */
TBL1<r2_class_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_class> *		r4_recorder::table_class	= NULL;


/* 当前代码 */
LST1<r2_code_t> *	r4_recorder::code			= NULL;
/* 全局代码 */
LST1<r2_code_t> *	r4_recorder::code_global	= NULL;

/* 当前函数 */
r2_function_t		r4_recorder::function		= NULL;

/* 当前类 */
r2_class_t			r4_recorder::cls			= NULL;
/* 当前类特性 */
r2_class_feature_t	r4_recorder::class_feature	= NULL;


/* 当前变量分配器 */
VAR4 *		r4_recorder::var			= NULL;
/* 全局变量分配器 */
VAR4 *		r4_recorder::var_global		= NULL;




KI_LOADER_BOOT (r4_recorder) {
	// 创建符号表
	r4_recorder::table_variable		= new TBL1<r2_variable_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_sensitive,	r4_recorder::handler_delete_variable>;
	r4_recorder::table_function		= new TBL1<r2_function_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_function>;
	r4_recorder::table_class		= new TBL1<r2_class_t,		r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_class>;

	// 创建全局代码表
	r4_recorder::code_global	= new LST1<r2_code_t>;

	// 创建全局变量分配器
	r4_recorder::var_global		= new VAR4 (NULL, NULL);

	// 当前代码映射为全局代码
	r4_recorder::code		= r4_recorder::code_global;

	// 将当前变量分配器映射为全局变量分配器
	r4_recorder::var		= r4_recorder::var_global;

	// 遍历导出全局变量
	if(C3(export_variable)->ready ( ) == true) {
		STR1 *	name;

		while(C3(export_variable)->fetch (& name) == true) {
			BLD4::variable_export (name);
		}
	}

	// 遍历导出函数
	if(C3(export_function)->ready ( ) == true) {
		STR1 *	name;

		while(C3(export_function)->fetch (& name) == true) {
			BLD4::function_export (name);
		}
	}
}


KI_LOADER_SHUTDOWN (r4_recorder) {
	// 删除符号表
	delete r4_recorder::table_variable;
	delete r4_recorder::table_function;
	delete r4_recorder::table_class;

	// 删除全局变量分配器
	delete r4_recorder::var_global;
}




void r4_recorder::handler_delete_variable (r2_variable_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;

	delete p;
}


void r4_recorder::handler_delete_function (r2_function_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;
	delete p->caller;

	delete p;
}


void r4_recorder::handler_delete_class (r2_class_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;

	delete p->_extend;
	delete p->_implement;
	delete p->_const;
	delete p->_property;
	delete p->_method;

	delete p->code;
	delete p->code_boot;
	delete p->code_entry;

	delete p;
}




/* 编译时警告 */

void r4_recorder::warning (bool line, const char *format, ...) {
	KI_VARG_BEGIN (format);

	// 创建错误信息
	STR1	message		(0, format, ap);

	switch(C3(warning)) {
		case R3_CONFIG_WARNING_DISABLE:
			break;

		case R3_CONFIG_WARNING_NORMAL:
			if(line == true) {
				O0::syntax (message.pointer ( ),	r4_recorder::line,	false);
			} else {
				O0::syntax (message.pointer ( ),	0,					false);
			}
			break;

		case R3_CONFIG_WARNING_ERROR:
			if(line == true) {
				O0::syntax (message.pointer ( ),	r4_recorder::line,	true);
			} else {
				O0::syntax (message.pointer ( ),	0,					true);
			}
			break;
	}

	KI_VARG_END ( );
}


void r4_recorder::warning (unsigned int line, const char *format, ...) {
	KI_VARG_BEGIN (format);

	// 创建错误信息
	STR1	message		(0, format, ap);

	switch(C3(warning)) {
		case R3_CONFIG_WARNING_DISABLE:
			break;

		case R3_CONFIG_WARNING_NORMAL:
			O0::syntax (message.pointer ( ), line, false);
			break;

		case R3_CONFIG_WARNING_ERROR:
			O0::syntax (message.pointer ( ), line, true);
			break;
	}

	KI_VARG_END ( );
}




/* 编译时错误 */

void r4_recorder::error (bool line, const char *format, ...) {
	KI_VARG_BEGIN (format);

	// 创建错误信息
	STR1	message		(0, format, ap);

	if(line == true) {
		O0::syntax (message.pointer ( ),	r4_recorder::line,	true);
	} else {
		O0::syntax (message.pointer ( ),	0,					true);
	}

	KI_VARG_END ( );
}


void r4_recorder::error (unsigned int line, const char *format, ...) {
	KI_VARG_BEGIN (format);

	// 创建错误信息
	STR1	message		(0, format, ap);

	O0::syntax (message.pointer ( ), line, true);

	KI_VARG_END ( );
}


