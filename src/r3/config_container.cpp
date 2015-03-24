/*
	$ [KiPHP] /r3/config_container.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			3

#include "../kiviuq.h"




/* 导出表 */
LST1<STR1 *, r3_config::handler_delete> *	r3_config_container::export_variable	= NULL;
LST1<STR1 *, r3_config::handler_delete> *	r3_config_container::export_function	= NULL;


/* 输出模式 */
r3_config_output_e		r3_config_container::output		= R3_CONFIG_OUTPUT_CODE;


/* 警告模式 */
r3_config_warning_e		r3_config_container::warning	= R3_CONFIG_WARNING_NORMAL;


/* 噪音水平 */
unsigned int	r3_config_container::noise		= 0;


/* 输出运行记录 */
bool		r3_config_container::log			= false;


/* 启用编码支持 */
bool		r3_config_container::enable_encode	= true;
/* 启用内联函数 */
bool		r3_config_container::enable_inline	= false;
/* 启用编译杂注 */
bool		r3_config_container::enable_pragma	= true;
/* 启用随机代码 */
bool		r3_config_container::enable_random	= false;


/* 虚拟机信息 */
STR1 *		r3_config_container::vm_wrapper		= NULL;
STR1 *		r3_config_container::vm_entry		= NULL;
STR1 *		r3_config_container::vm_heap		= NULL;
STR1 *		r3_config_container::vm_stack		= NULL;
STR1 *		r3_config_container::vm_top			= NULL;
STR1 *		r3_config_container::vm_bottom		= NULL;
STR1 *		r3_config_container::vm_exception	= NULL;
STR1 *		r3_config_container::vm_program		= NULL;
STR1 *		r3_config_container::vm_return		= NULL;
STR1 *		r3_config_container::vm_middle		= NULL;


