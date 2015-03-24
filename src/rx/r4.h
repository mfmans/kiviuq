/*
	$ [KiPHP] /rx/r4.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 4

#ifndef _R4_H_
#define _R4_H_



#define VAR4			r4_variable
#define COD4			r4_code
#define BLD4			r4_builder
#define RCD4			r4_recorder

#define STR4(p)			r4_constring::build (p)





/* 字符串常量表 */
class r4_constring {
	KI_LOADER_DECLARE ( );


	private:
		/* 常量表 */
		static	SGL1<STR1 *, r2_hash::size_big, r2_hash::handler_build, r2_hash::handler_index_long, r2_hash::handler_compare_sensitive, r2_hash::handler_delete> *	table;


	public:
		/* 获取字符串常量 */
		static	STR1 *	build	(const char *p);
		static	STR1 *	build	(const STR1 *p);
};




/* 变量分配器 */
class r4_variable {
	KI_LOADER_DECLARE ( );


	public:
		static	unsigned int	handler_index		(const STR1 *p);
		static	bool			handler_compare		(const STR1 *p1, const STR1 *p2);
		static	void			handler_delete		(r2_variable_t p);


	private:
		/* 当前识别前缀 */
		STR1 *	prefix;

		/* 全局作用域 */
		bool	global;
		/* 栈底偏移量 */
		unsigned int	offset;

		
		/* 添加变量 */
		static	r2_variable_t	add_heap		(const STR1 *name);
				r2_variable_t	add_stack		(const STR1 *name);

		/* 获取变量 */
		static	r2_variable_t	fetch_heap		(const STR1 *name);
				r2_variable_t	fetch_stack		(const STR1 *name);


		/* 更新操作数 */
		static	void	update	(r2_variable_t var, r2_code_directive_operand_address_base_e base, r2_code_directive_operand_t operand);


	public:
		/* 超全局变量表 */
		static	TBL1<r2_variable_t, r2_hash::size_small, NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_sensitive,	NULL> *	super;
		/* 堆变量表 */
		static	TBL1<r2_variable_t, r2_hash::size_small, NULL,	r4_variable::handler_index,		r4_variable::handler_compare,		r4_variable::handler_delete> *	heap;

		/* 栈变量表 */
				TBL1<r2_variable_t, r2_hash::size_small, NULL,	r4_variable::handler_index,		r4_variable::handler_compare,		r4_variable::handler_delete> *	stack;


		r4_variable		(const STR1 *name_class, const STR1 *name_function, unsigned int offset = 0);

		~r4_variable	(void);


		/* 注册超全局变量 */
		static	void	register_super	(const char *p);
		static	void	register_super	(const STR1 *p);


		/* 注册静态变量 */
		bool	register_static	(const STR1 *p, r2_code_directive_operand_t operand_old, r2_code_directive_operand_t operand_new);
		/* 注册全局变量 */
		bool	register_global	(const STR1 *p, r2_code_directive_operand_t operand_old, r2_code_directive_operand_t operand_new);

		/* 使用变量 */
		void	use		(const STR1 *p, r2_code_directive_operand_t operand);
};




/* 代码生成器 */
class r4_code {
	private:
		/* 类型字符串比较 */
		static	int		compare		(const char *p1, const char *p2);


	public:
		/* 释放代码 */
		static	void		free		(r2_code_t p);

		/* 创建标签 */
		static	r2_code_t	label		(void);
		/* 创建指令 */
		static	r2_code_t	directive	(r2_code_directive_opcode_e opcode, const char *format, ...);

		/* 更新操作数 */
		static	unsigned int	operand		(r2_code_directive_operand_t operand, const char * format, ...);
		static	unsigned int	operand		(r2_code_directive_operand_t operand, va_list *ap, const char *format);
};




/* 生成器 */
class r4_builder {
	public:
		/* 获取全局变量 */
		static	r2_variable_t	variable_fetch	(const STR1 *name);

		/* 导出全局变量 */
		static	void	variable_export		(const STR1 *name);


		/* 进入函数 */
		static	void	function_enter	(const STR1 *name);
		/* 退出函数 */
		static	void	function_leave	(void);

		/* 调用函数 */
		static	r2_function_t	function_call	(const STR1 *name, r2_code_directive_operand_t p);

		/* 获取函数 */
		static	r2_function_t	function_fetch	(const STR1 *name);

		/* 导出函数 */
		static	void	function_export		(const STR1 *name);


		/* 进入类 */
		static	void	class_enter		(const STR1 *name);
		/* 退出类 */
		static	void	class_leave		(void);

		/* 类实现接口 */
		static	void	class_implement	(const STR1 *name);

		/* 类常量定义 */
		static	void	class_declare_const		(const STR1 *name, r2_code_directive_operand_t operand);
		/* 类属性定义 */
		static	void	class_declare_property	(const STR1 *name);

		/* 获取类 */
		static	r2_class_t	class_fetch		(const STR1 *name, LST1<r2_code_t> *code = NULL);


		/* 最后整理生成 */
		static	void	collect		(void);

		/* 整理虚拟机 */
		static	void	collect_vm			(void);
		/* 整理函数 */
		static	void	collect_function	(r2_function_t node);
		/* 整理类 */
		static	void	collect_class		(r2_class_t node);
};




/* 运行记录 */
class r4_recorder {
	KI_LOADER_DECLARE ( );


	public:
		static	void	handler_delete_variable	(r2_variable_t p);
		static	void	handler_delete_function	(r2_function_t p);
		static	void	handler_delete_class	(r2_class_t p);


		/* 已处理行 */
		static	unsigned int	line;
		/* 已处理字节 */
		static	unsigned int	byte;


		/* 全局变量表 */
		static	TBL1<r2_variable_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_sensitive,	r4_recorder::handler_delete_variable> *		table_variable;

		/* 函数表 */
		static	TBL1<r2_function_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_function> *		table_function;

		/* 类表 */
		static	TBL1<r2_class_t,	r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive,	r4_recorder::handler_delete_class> *		table_class;


		/* 当前代码 */
		static	LST1<r2_code_t> *	code;
		/* 全局代码 */
		static	LST1<r2_code_t> *	code_global;

		/* 当前函数 */
		static	r2_function_t	function;

		/* 当前类 */
		static	r2_class_t			cls;
		/* 当前类成员特性 */
		static	r2_class_feature_t	class_feature;


		/* 当前变量分配器 */
		static	VAR4 *		var;
		/* 全局变量分配器 */
		static	VAR4 *		var_global;

		
		/* 编译时警告 */
		static	void	warning		(bool line,			const char *format, ...);
		static	void	warning		(unsigned int line,	const char *format, ...);

		/* 编译时错误 */
		static	void	error		(bool line,			const char *format, ...);
		static	void	error		(unsigned int line,	const char *format, ...);
};




#endif

#endif