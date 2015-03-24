/*
	$ [KiPHP] /rx/r2.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 2

#ifndef _R2_H_
#define _R2_H_




/* 哈希 */
class r2_hash {
	public:
		/* 表大小 */
		static	const	unsigned int	size_small	= 47;			// 小表
		static	const	unsigned int	size_big	= 151;			// 大表


		/* 哈希长度 */
		static	const	unsigned int	max_short	= 5;			// 短哈希
		static	const	unsigned int	max_long	= 14;			// 长哈希


		/* 哈希算法 */
		static	unsigned int	handler_index	(const char *buffer, unsigned int length, unsigned int max);


		/* 哈希函数 */
		static	unsigned int	handler_index_short		(STR1 *p);								// 短哈希
		static	unsigned int	handler_index_long		(STR1 *p);								// 长哈希

		/* 哈希函数 (const) */
		static	unsigned int	handler_index_short		(const STR1 *p);						// 短哈希
		static	unsigned int	handler_index_long		(const STR1 *p);						// 长哈希


		/* 键比较函数 */
		static	bool	handler_compare_sensitive		(STR1 *p1, STR1 *p2);					// 区分大小写
		static	bool	handler_compare_insensitive		(STR1 *p1, STR1 *p2);					// 忽略大小写 (二进制不安全)

		/* 键比较函数 */
		static	bool	handler_compare_sensitive		(const STR1 *p1, const STR1 *p2);		// 区分大小写
		static	bool	handler_compare_insensitive		(const STR1 *p1, const STR1 *p2);		// 忽略大小写 (二进制不安全)


		/* 哈希创建 */
		static	STR1 *	handler_build		(STR1 *p);


		/* 哈希清理 */
		static	void	handler_delete		(STR1 *p);
};




struct	r2_code_label_o;
struct	r2_code_directive_o;

class	r2_function;




/* 操作数 */
#include "../r2/code_directive_operand.h"
/* 操作码 */
#include "../r2/code_directive_opcode.h"


/* 代码类型 */
typedef enum {
	R2_CD_LABEL,
	R2_CD_DIRECTIVE,
} r2_code_e;


/* 标签 */
typedef struct r2_code_label_o {
	unsigned int	id;									// 标签序号
	LST1<r2_code_directive_operand_t> *	operand;		// 引用表
} r2_code_label_o, * r2_code_label_t;


/* 指令 */
typedef struct r2_code_directive_o {
	r2_code_directive_opcode_e		opcode;				// 操作码
	r2_code_directive_operand_o		operand_1;			// 操作数 #1
	r2_code_directive_operand_o		operand_2;			// 操作数 #2
	r2_code_directive_operand_o		operand_3;			// 操作数 #3
} r2_code_directive_o, * r2_code_directive_t;


/* 代码 */
typedef struct {
	r2_code_e		type;								// 代码类型

	union {
		r2_code_label_o			_label;					// 标签
		r2_code_directive_o		_directive;				// 指令
	} v;
} r2_code_o, * r2_code_t;




/* 变量 */
typedef struct {
	STR1 *		name;									// 变量名

	bool		visible;								// 可见性 (是否导出)
	bool		super;									// 超全局变量

	unsigned int	line;								// 首次出现所在行
	unsigned int	line_export;						// 导出所在行

	unsigned int	reference;							// 引用次数

	unsigned int	offset;								// 偏移量
} r2_variable_o, * r2_variable_t;




/* 函数 */
typedef class r2_function {
	public:
		STR1 *	name;									// 函数名

		bool	visible;								// 可见性 (是否导出)

		unsigned int	line_call;						// 首次调用所在行
		unsigned int	line_declare;					// 定义所在行
		unsigned int	line_export;					// 导出所在行

		unsigned int	parameter_total;				// 参数个数
		unsigned int	parameter_optional;				// 可选参数个数

		r2_code_t		entry;							// 函数入口

		LST1<r2_code_directive_operand_t> *	caller;		// 调用者
} r2_function_o, * r2_function_t;




/* 类相关 */
#include "../r2/class.h"


/* 类 */
typedef class r2_class : public r2_class_feature {
	public:
		static	void	handler_delete_const		(r2_class_const_t p);
		static	void	handler_delete_property		(r2_class_property_t p);
		static	void	handler_delete_method		(r2_class_method_t p);
		static	void	handler_delete_code			(r2_code_t p);


		STR1 *	name;									// 类名

		unsigned int	line;							// 定义所在行

		STR1 *	_extend;								// 父类

		// 实现接口
		TBL1<STR1 *, r2_hash::size_small, NULL, r2_hash::handler_index_short, r2_hash::handler_compare_insensitive, r2_hash::handler_delete> *	_implement;

		// 常量
		TBL1<r2_class_const_t,		r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_sensitive,		r2_class::handler_delete_const> *		_const;
		// 属性
		TBL1<r2_class_property_t,	r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_sensitive,		r2_class::handler_delete_property> *	_property;
		// 方法
		TBL1<r2_class_method_t,		r2_hash::size_small,	NULL,	r2_hash::handler_index_short,	r2_hash::handler_compare_insensitive,	r2_class::handler_delete_method> *		_method;

		LST1<r2_code_t> *	code_boot;					// 启动代码
		LST1<r2_code_t> *	code_entry;					// 入口代码

		// 代码
		LST1<r2_code_t, r2_class::handler_delete_code> *	code;

		// 代码标签
		r2_code_t		label_code_boot;
		r2_code_t		label_code_entry;
} r2_class_o, * r2_class_t;




#endif

#endif