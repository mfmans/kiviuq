/*
	$ [KiPHP] /r2/code_directive_operand.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 2

#ifndef _R2_CODE_DIRECTIVE_OPERAND_H_
#define _R2_CODE_DIRECTIVE_OPERAND_H_




/* 操作数类型 */
typedef enum {
	R2_CD_OPND_NULL,							// 无操作数
	R2_CD_OPND_LABEL,							// 标签
	R2_CD_OPND_ADDRESS,							// 寻址
	R2_CD_OPND_CONSTANT,						// 常量
	R2_CD_OPND_IDENTIFIER,						// 标识符
	R2_CD_OPND_INTEGER,							// 整数
	R2_CD_OPND_FLOAT,							// 浮点数
	R2_CD_OPND_STRING,							// 字符串
	R2_CD_OPND_FUNCTION,						// 函数
} r2_code_directive_operand_e;




/* 寻址基址 */
typedef enum {
	R2_CD_OPND_ADDRESS_DIRECT,					// 直接寻址
	R2_CD_OPND_ADDRESS_HEAP,					// 堆基址
	R2_CD_OPND_ADDRESS_TOP,						// 栈顶寻址
	R2_CD_OPND_ADDRESS_BOTTOM,					// 栈底寻址
} r2_code_directive_operand_address_base_e;


/* 寻址 */
typedef struct {
	signed int		offset;
	r2_code_directive_operand_address_base_e	base;
} r2_code_directive_operand_address_o, * r2_code_directive_operand_address_t;




/* 常量 */
typedef enum {
	R2_CD_OPND_CONSTANT_NULL,
	R2_CD_OPND_CONSTANT_TRUE,
	R2_CD_OPND_CONSTANT_FALSE,
	R2_CD_OPND_CONSTANT_FUNCTION,
	R2_CD_OPND_CONSTANT_CLASS,
	R2_CD_OPND_CONSTANT_METHOD,
	R2_CD_OPND_CONSTANT_DIR,
	R2_CD_OPND_CONSTANT_FILE,
} r2_code_directive_operand_constant_e;




/* 操作数 */
typedef struct {
	r2_code_directive_operand_e		type;

	union {
		struct r2_code_label_o *				_label;
		r2_code_directive_operand_address_o		_address;
		r2_code_directive_operand_constant_e	_constant;
		STR1 *		_identifier;
		signed int	_integer;
		double		_float;
		STR1 *		_string;
		class r2_function *		_function;
	} v;
} r2_code_directive_operand_o, * r2_code_directive_operand_t;




#endif

#endif