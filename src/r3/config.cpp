/*
	$ [KiPHP] /r3/config.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			3

#include "../kiviuq.h"




/* 启动参数 */
int			r3_config::argc		= 0;
char **		r3_config::argv		= NULL;




KI_LOADER_BOOT (r3_config) {
	// 设置启动参数
	r3_config::argc		= argc - 1;
	r3_config::argv		= argv + 1;

	// 初始化导出表
	C3(export_variable)		= new LST1<STR1 *, r3_config::handler_delete> ( );
	C3(export_function)		= new LST1<STR1 *, r3_config::handler_delete> ( );

	// 初始化虚拟机信息
	C3(vm_wrapper)		= new STR1 ("%s",	"__kiviuq_wrapper");
	C3(vm_entry)		= new STR1 ("%s",	"__kiviuq__");
	C3(vm_heap)			= new STR1 ("%s",	"HEAP");
	C3(vm_stack)		= new STR1 ("%s",	"STACK");
	C3(vm_top)			= new STR1 ("%s",	"T");
	C3(vm_bottom)		= new STR1 ("%s",	"B");
	C3(vm_exception)	= new STR1 ("%s",	"E");
	C3(vm_program)		= new STR1 ("%s",	"P");
	C3(vm_return)		= new STR1 ("%s",	"R");
	C3(vm_middle)		= new STR1 ("%s",	"M");

	// 正在解析的参数
	const char *	command;

	// 依次解析参数
	while(command = r3_config::fetch_string ( )) {
		r3_config::parse (command);
	}
}


KI_LOADER_SHUTDOWN (r3_config) {
	// 销毁导出表
	delete C3(export_variable);
	delete C3(export_function);

	// 销毁虚拟机信息
	delete C3(vm_wrapper);
	delete C3(vm_entry);
	delete C3(vm_heap);
	delete C3(vm_stack);
	delete C3(vm_top);
	delete C3(vm_bottom);
	delete C3(vm_exception);
	delete C3(vm_program);
	delete C3(vm_return);
	delete C3(vm_middle);
}




/* 解析参数 */

bool r3_config::fetch_uint (unsigned int *p) {
	const char *	start	= r3_config::fetch_string ( );
	char *			end		= NULL;

	if(start == NULL) {
		return false;
	}

	// 解析无符号整数
	unsigned long	value	= strtoul (start, & end, 0);

	// 判断是否完全解析整个字符串
	if(* end != '\0') {
		return false;
	}

	* p	= (unsigned int) value;

	return true;
}


const char * r3_config::fetch_string (void) {
	if((r3_config::argc --) <= 0) {
		return NULL;
	}

	return * (r3_config::argv ++);
}


const char * r3_config::fetch_variable (void) {
	const char *	name	= r3_config::fetch_string ( );

	if(name == NULL) {
		return NULL;
	}

	if(* name == '$') {
		const char *	p	= name + 1;

		if((* p != '_') && (isalpha (* p) == 0)) {
			return NULL;
		}

		while(* (++ p) != '\0') {
			if((* p != '_') && (isalnum (* p) == 0)) {
				return NULL;
			}
		}

		return name + 1;
	}

	return NULL;
}


const char * r3_config::fetch_identifier (void) {
	const char *	name	= r3_config::fetch_string ( );
	const char *	p		= name;

	if(name == NULL) {
		return NULL;
	}

	if((* p != '_') && (isalpha (* p) == 0)) {
		return NULL;
	}

	while(* (++ p) != '\0') {
		if((* p != '_') && (isalnum (* p) == 0)) {
			return NULL;
		}
	}

	return name;
}




void r3_config::handler_delete (STR1 *data) {
	delete data;
}




/* 更新导出表 */
void r3_config::update_export (LST1<STR1 *, r3_config::handler_delete> *table, const char *p) {
	// 判断导出项是否已经存在
	if(table->ready ( ) == true) {
		STR1 *	name;

		// 遍历查找
		while(table->fetch (& name) == true) {
			if(* name == p) {
				return;
			}
		}
	}

	// 保存到导出表
	* table		+= new STR1 ("%s", p);
}


/* 配置虚拟机 */
void r3_config::update_vm (r3_config_vm_e entry, const char *p) {
	STR1 **	object	= NULL;

	switch(entry) {
		case R3_CONFIG_VM_WRAPPER:		object	= & C3(vm_wrapper);		break;
		case R3_CONFIG_VM_ENTRY:		object	= & C3(vm_entry);		break;
		case R3_CONFIG_VM_HEAP:			object	= & C3(vm_heap);		break;
		case R3_CONFIG_VM_STACK:		object	= & C3(vm_stack);		break;
		case R3_CONFIG_VM_TOP:			object	= & C3(vm_top);			break;
		case R3_CONFIG_VM_BOTTOM:		object	= & C3(vm_bottom);		break;
		case R3_CONFIG_VM_EXCEPTION:	object	= & C3(vm_exception);	break;
		case R3_CONFIG_VM_PROGRAM:		object	= & C3(vm_program);		break;
		case R3_CONFIG_VM_RETURN:		object	= & C3(vm_return);		break;
		case R3_CONFIG_VM_MIDDLE:		object	= & C3(vm_middle);		break;

		default:
			return;
	}

	// 销毁原有的设置
	delete * object;

	// 保存设置
	* object	= new STR1 ("%s", p);
}


