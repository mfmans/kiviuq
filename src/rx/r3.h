/*
	$ [KiPHP] /rx/r3.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 3

#ifndef _R3_H_
#define _R3_H_



#define CFG3		r3_config

#define C3(v)		r3_config_container::##v





/* 输出模式 */
typedef enum {
	R3_CONFIG_OUTPUT_HELP,					//			-h
	R3_CONFIG_OUTPUT_VERSION,				//			-v
	R3_CONFIG_OUTPUT_DISTRIBUTION,			//			-distribution
	R3_CONFIG_OUTPUT_CODE,					// 目标代码	-Oc
	R3_CONFIG_OUTPUT_INTERLANG,				// 中间语言	-Oi
	R3_CONFIG_OUTPUT_SYMBOL,				// 符号信息	-Os
} r3_config_output_e;


/* 警告模式 */
typedef enum {
	R3_CONFIG_WARNING_DISABLE,				// 禁用警告	-W0
	R3_CONFIG_WARNING_NORMAL,				// 标准警告	-W1
	R3_CONFIG_WARNING_ERROR,				// 警告错误	-W2
} r3_config_warning_e;


/* 虚拟机设置 */
typedef enum {
	R3_CONFIG_VM_WRAPPER,
	R3_CONFIG_VM_ENTRY,
	R3_CONFIG_VM_HEAP,
	R3_CONFIG_VM_STACK,
	R3_CONFIG_VM_TOP,
	R3_CONFIG_VM_BOTTOM,
	R3_CONFIG_VM_EXCEPTION,
	R3_CONFIG_VM_PROGRAM,
	R3_CONFIG_VM_RETURN,
	R3_CONFIG_VM_MIDDLE,
} r3_config_vm_e;




/* 配置管理 */
class r3_config {
	KI_LOADER_DECLARE ( );


	private:
		/* 启动参数 */
		static	int			argc;
		static	char **		argv;


		/* 解析参数 */
		static	bool			fetch_uint			(unsigned int *p);
		static	const char *	fetch_string		(void);
		static	const char *	fetch_variable		(void);
		static	const char *	fetch_identifier	(void);

		/* 处理参数 */
		static	void	parse	(const char *command);

		/* 输出模式 */
		static	void	output	(r3_config_output_e mode);


	public:
		static	void	handler_delete	(STR1 *data);


		/* 更新导出表 */
		static	void	update_export	(LST1<STR1 *, r3_config::handler_delete> *table, const char *p);
		/* 配置虚拟机 */
		static	void	update_vm		(r3_config_vm_e entry, const char *p);
};




/* 配置容器 */
class r3_config_container {
	public:
		/* 导出表 */
		static	LST1<STR1 *, r3_config::handler_delete> *		export_variable;		// 全局变量导出表
		static	LST1<STR1 *, r3_config::handler_delete> *		export_function;		// 函数导出表


		/* 输出模式 */
		static	r3_config_output_e		output;

		/* 警告模式 */
		static	r3_config_warning_e		warning;

		/* 噪音水平 */
		static	unsigned int	noise;

		/* 输出运行记录 */
		static	bool		log;

		/* 启用编码支持 */
		static	bool		enable_encode;
		/* 启用内联函数 */
		static	bool		enable_inline;
		/* 启用编译杂注 */
		static	bool		enable_pragma;
		/* 启用随机代码 */
		static	bool		enable_random;

		/* 虚拟机信息 */
		static	STR1 *		vm_wrapper;					// 封装类类名
		static	STR1 *		vm_entry;					// 调用入口方法名
		static	STR1 *		vm_heap;					// 堆属性名
		static	STR1 *		vm_stack;					// 栈变量名
		static	STR1 *		vm_top;						// 栈顶指针变量名
		static	STR1 *		vm_bottom;					// 栈底指针变量名
		static	STR1 *		vm_exception;				// 异常指针变量名
		static	STR1 *		vm_program;					// 程序计数器指针变量名
		static	STR1 *		vm_return;					// 返回值暂存器变量名
		static	STR1 *		vm_middle;					// 中间值暂存器变量名
};




#endif

#endif