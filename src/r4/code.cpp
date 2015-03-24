/*
	$ [KiPHP] /r4/code.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			4

#include "../kiviuq.h"




/* 类型字符串比较 */
int r4_code::compare (const char *p1, const char *p2) {
	unsigned int	length	= strlen (p2);

	return strncmp (p1, p2, length);
}




/* 释放代码 */
void r4_code::free (r2_code_t p) {
	// 释放内部信息
	switch(p->type) {
		// 标签
		case R2_CD_LABEL:
			// 删除标签引用表
			delete p->v._label.operand;

			break;
	}

	delete p;
}




/* 创建标签 */
r2_code_t r4_code::label (void) {
	r2_code_t	code	= newz r2_code_o;

	code->type		= R2_CD_LABEL;

	// 创建标签引用表
	code->v._label.operand	= new LST1<r2_code_directive_operand_t>;

	return code;
}


/* 创建指令 */
r2_code_t r4_code::directive (r2_code_directive_opcode_e opcode, const char *format, ...) {
	r2_code_t	code	= newz r2_code_o;

	code->type					= R2_CD_DIRECTIVE;
	code->v._directive.opcode	= opcode;
	
	code->v._directive.operand_1.type	= R2_CD_OPND_NULL;
	code->v._directive.operand_2.type	= R2_CD_OPND_NULL;
	code->v._directive.operand_3.type	= R2_CD_OPND_NULL;

	// 判断是否需要格式化指令
	if(format != NULL) {
		// 操作数集合
		r2_code_directive_operand_t	operands	[ ]	= {
			& code->v._directive.operand_1,
			& code->v._directive.operand_2,
			& code->v._directive.operand_3,
			NULL,
		};

		// 当前操作数
		r2_code_directive_operand_t *	operand	= operands;

		// 格式长度
		unsigned int	length	= strlen (format);

		KI_VARG_BEGIN (format);

		while(length > 0) {
			// 判断是否操作数用尽
			if(* operand == NULL) {
				O0::runtime ("无效的操作数格式化串，缺少操作数。");
			}

			unsigned int	read	= r4_code::operand (* operand, & ap, format);

			// 判断解析的数量
			if(read > length) {
				O0::runtime ("无效的操作数格式化串，长度溢出。");
			} else if(read == 0) {
				O0::runtime ("无效的操作数格式化串，解析失败。");
			}

			format	+= read;
			length	-= read;

			operand	++;
		}

		KI_VARG_END ( );

		// 判断是否处理完毕
		if(* format != '\0') {
			O0::runtime ("无效的操作数格式化串，处理剩余。");
		}
	}

	return code;
}




/* 更新操作数 */

unsigned int r4_code::operand (r2_code_directive_operand_t operand, const char * format, ...) {
	KI_VARG_BEGIN (format);

	unsigned int	size	= r4_code::operand (operand, & ap, format);

	KI_VARG_END ( );

	return size;
}


unsigned int r4_code::operand (r2_code_directive_operand_t operand, va_list *ap, const char *format) {
	// 读取的长度
	unsigned int	length	= 1;

	// 解析格式化串
	switch(* format) {
		// 保留
		case '@':
			break;

		// 标签
		case 'L':
			{
				operand->type		= R2_CD_OPND_LABEL;

				r2_code_t	label	= va_arg (* ap, r2_code_t);

				if(label != NULL) {
					operand->v._label	= & label->v._label;

					* label->v._label.operand	+= operand;
				}
			}

			break;

		// 寻址
		case 'A':
			operand->type				= R2_CD_OPND_ADDRESS;
			operand->v._address.offset	= va_arg (* ap, signed int);

			switch(* (format + 1)) {
				case 'd':		operand->v._address.base	= R2_CD_OPND_ADDRESS_DIRECT;		break;
				case 'h':		operand->v._address.base	= R2_CD_OPND_ADDRESS_HEAP;			break;
				case 't':		operand->v._address.base	= R2_CD_OPND_ADDRESS_TOP;			break;
				case 'b':		operand->v._address.base	= R2_CD_OPND_ADDRESS_BOTTOM;		break;

				default:
					O0::runtime ("无效的操作数格式化串，未知的寻址基址。");
			}

			length ++;

			break;

		// 常量
		case 'C':
			{
				operand->type	= R2_CD_OPND_CONSTANT;

				KI_LOOKSTR (format + 1, r4_code::compare) {
					KI_LOOKSTR_CASE ("null")		operand->v._constant	= R2_CD_OPND_CONSTANT_NULL;			length	= sizeof ("null");
					KI_LOOKSTR_CASE ("true")		operand->v._constant	= R2_CD_OPND_CONSTANT_TRUE;			length	= sizeof ("true");
					KI_LOOKSTR_CASE ("false")		operand->v._constant	= R2_CD_OPND_CONSTANT_FALSE;		length	= sizeof ("false");
					KI_LOOKSTR_CASE ("function")	operand->v._constant	= R2_CD_OPND_CONSTANT_FUNCTION;		length	= sizeof ("function");
					KI_LOOKSTR_CASE ("class")		operand->v._constant	= R2_CD_OPND_CONSTANT_CLASS;		length	= sizeof ("class");
					KI_LOOKSTR_CASE ("method")		operand->v._constant	= R2_CD_OPND_CONSTANT_METHOD;		length	= sizeof ("method");
					KI_LOOKSTR_CASE ("dir")			operand->v._constant	= R2_CD_OPND_CONSTANT_DIR;			length	= sizeof ("dir");
					KI_LOOKSTR_CASE ("file")		operand->v._constant	= R2_CD_OPND_CONSTANT_FILE;			length	= sizeof ("file");

					KI_LOOKSTR_DEFAULT ( )
						O0::runtime ("无效的操作数格式化串，未知的常量类型。");
				}
			}

			break;

		// 标识符
		case 'D':
			operand->type			= R2_CD_OPND_IDENTIFIER;
			operand->v._identifier	= STR4 (va_arg (* ap, const STR1 *));

			break;

		// 整数
		case 'I':
			operand->type		= R2_CD_OPND_INTEGER;
			operand->v._integer	= va_arg (* ap, signed int);

			break;

		// 浮点数
		case 'F':
			operand->type		= R2_CD_OPND_FLOAT;
			operand->v._float	= va_arg (* ap, double);

			break;

		// 字符串
		case 'S':
			operand->type		= R2_CD_OPND_STRING;
			operand->v._string	= STR4 (va_arg (* ap, const STR1 *));

			break;

		// 函数
		case 'N':
			operand->type			= R2_CD_OPND_FUNCTION;
			operand->v._function	= BLD4::function_call (va_arg (* ap, const STR1 *), operand);

			break;

		default:
			O0::runtime ("无效的操作数格式化串，未知类型。");
	}

	return length;
}


