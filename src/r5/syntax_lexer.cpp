/*
	$ [KiPHP] /r5/syntax_lexer.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../kiviuq.h"
#include "./syntax.h"
#include "./syntax_lexer.h"




#define self			r5_syntax_lexer

#define RETURN			do {										\
							self::token	= token->type;				\
							return;									\
						} while(0)




/* 返回值 */
r5_syntax_token_type_e	r5_syntax_lexer::token	= T_EOF;

/* 识别模式 */
r5_syntax_lexer_mode_e	r5_syntax_lexer::mode	= MODE_HTML;

/* 编码 */
bool	r5_syntax_lexer::encode		= false;

/* 缓冲区 */
STR1 *	r5_syntax_lexer::buffer		= NULL;




/* 计数器 */
void r5_syntax_lexer::count (const char *text, int length) {
	// 已处理字节
	RCD4::byte	+= (unsigned int) length;

	// 解析已处理行
	while((length --) > 0) {
		if(* (text ++) == '\n') {
			RCD4::line ++;
		}
	}
}




/* 附加数据到缓冲区 */
void r5_syntax_lexer::append (const char *p, int length) {
	if(self::buffer == NULL) {
		self::buffer	= new STR1 ( );
	}

	self::buffer->append (p, (unsigned int) length);
}




/* 创建单词 */

r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, char type) {
	token->type	= (r5_syntax_token_type_e) type;

	return token;
}


r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, r5_syntax_token_type_e type) {
	token->type	= type;

	return token;
}


r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, r5_syntax_token_type_e type, signed int value) {
	token->type			= type;
	token->v._integer	= value;

	return token;
}


r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, r5_syntax_token_type_e type, double value) {
	token->type			= type;
	token->v._float		= value;

	return token;
}


r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, r5_syntax_token_type_e type, const char *value) {
	token->type			= type;
	token->v._string	= STR4 (value);

	return token;
}


r5_syntax_token_t r5_syntax_lexer::build (r5_syntax_token_t token, r5_syntax_token_type_e type, STR1 *value) {
	token->type			= type;
	token->v._string	= STR4 (value);

	delete value;

	return token;
}




/* 判断编码 */
bool r5_syntax_lexer::check (bool status, const char *text) {
	if(C3(enable_encode) == true) {
		return status;
	} else {
		if(status == true) {
			if(text != NULL) {
				RCD4::warning (true, "%s", text);
			}
		}

		return false;
	}
}




DEF_CALL (eof) {
	switch(self::mode) {
		case MODE_PHP:
			break;

		case MODE_HTML:
			if(self::buffer != NULL) {
				self::build (token, T_HTML, self::buffer);

				self::mode		= MODE_PHP;
				self::buffer	= NULL;

				RETURN;
			}

			break;

		case MODE_STRING:
			RCD4::error (true, "在文件尾遇到未结束的字符串。");
	}

	self::build (token, T_EOF);

	RETURN;
}


DEF_CALL (undefined) {
	self::build (token, T_UNDEFINED);

	RETURN;
}




DEF_CALL (php_open) {
	if(self::buffer == NULL) {
		self::build (token, ';');
	} else {
		self::build (token, T_HTML, self::buffer);
	}

	self::mode		= MODE_PHP;
	self::buffer	= NULL;

	RETURN;
}


DEF_CALL (php_close) {
	self::mode		= MODE_HTML;
	self::buffer	= NULL;

	self::build (token, ';');

	RETURN;
}


DEF_CALL (php_echo) {
	self::build (token, T_ECHO);

	RETURN;
}




DEF_CALL (pragma) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("#!export")			self::build (token, T_PRAGMA_EXPORT);
		KI_LOOKSTR_CASE ("#!encode")			self::build (token, T_PRAGMA_ENCODE);
		KI_LOOKSTR_CASE ("#!inline")			self::build (token, T_PRAGMA_INLINE);
		KI_LOOKSTR_CASE ("#!vm-wrapper")		self::build (token, T_PRAGMA_VM_WRAPPER);
		KI_LOOKSTR_CASE ("#!vm-entry")			self::build (token, T_PRAGMA_VM_ENTRY);
		KI_LOOKSTR_CASE ("#!vm-heap")			self::build (token, T_PRAGMA_VM_HEAP);
		KI_LOOKSTR_CASE ("#!vm-stack")			self::build (token, T_PRAGMA_VM_STACK);
		KI_LOOKSTR_CASE ("#!vm-top")			self::build (token, T_PRAGMA_VM_TOP);
		KI_LOOKSTR_CASE ("#!vm-bottom")			self::build (token, T_PRAGMA_VM_BOTTOM);
		KI_LOOKSTR_CASE ("#!vm-exception")		self::build (token, T_PRAGMA_VM_EXCEPTION);
		KI_LOOKSTR_CASE ("#!vm-program")		self::build (token, T_PRAGMA_VM_PROGRAM);
		KI_LOOKSTR_CASE ("#!vm-return")			self::build (token, T_PRAGMA_VM_RETURN);
		KI_LOOKSTR_CASE ("#!vm-middle")			self::build (token, T_PRAGMA_VM_MIDDLE);

		KI_LOOKSTR_DEFAULT ( )					RCD4::error (true, "未知的或未实现的编译杂注。");
	}

	RETURN;
}




#define DEF_CALL_INTEGER(name, base, offset)												\
	DEF_CALL (integer_##name) {																\
		bool	encode;																		\
		if(* text == '@') {																	\
			text	= text + 1;																\
			encode	= true;																	\
		} else {																			\
			encode	= false;																\
		}																					\
		errno	= 0;																		\
		char *	end		= NULL;																\
		long	value	= strtol (text + offset, & end, base);								\
		if(errno == ERANGE) {																\
			RCD4::warning (true, "整数超出了表示范围的上限，实际表达的值将不准确。");				\
		}																					\
		if(self::check (encode, "编码支持已被禁用，整数将会以字面常量的形式出现。如需启用编码支持，请使用编译杂注 #!encode 或 -encode-on 参数。") == true) {		\
			self::build (token,	T_ENCODE_INTEGER,	(signed int) value);					\
		} else {																			\
			self::build (token,	T_INTEGER,			(signed int) value);					\
		}																					\
		RETURN;																				\
	}

DEF_CALL_INTEGER	(bin,	 2,		2)
DEF_CALL_INTEGER	(oct,	 8,		1)
DEF_CALL_INTEGER	(dec,	10,		0)
DEF_CALL_INTEGER	(hex,	16,		2)

#undef	DEF_CALL_INTEGER


DEF_CALL (double) {
	self::build (token, T_FLOAT, atof (text));

	RETURN;
}




DEF_CALL (operator_unary) {
	self::build (token, * text);

	RETURN;
}


DEF_CALL (operator_binary) {
	KI_LOOKSTR (text, strcmp) {
		KI_LOOKSTR_CASE ("++")				self::build (token, T_INC);
		KI_LOOKSTR_CASE ("--")				self::build (token, T_DEC);
		KI_LOOKSTR_CASE ("<<")				self::build (token, T_SHL);
		KI_LOOKSTR_CASE (">>")				self::build (token, T_SHR);
		KI_LOOKSTR_CASE ("==")				self::build (token, T_IS_EQUAL);
		KI_LOOKSTR_CASE ("!=")				self::build (token, T_IS_NOT_EQUAL);
		KI_LOOKSTR_CASE ("<=")				self::build (token, T_IS_SMALLER_EQUAL);
		KI_LOOKSTR_CASE (">=")				self::build (token, T_IS_GREATER_EQUAL);
		KI_LOOKSTR_CASE ("<>")				self::build (token, T_IS_SMALLER_GREATER);
		KI_LOOKSTR_CASE ("&&")				self::build (token, T_BOOLEAN_AND);
		KI_LOOKSTR_CASE ("||")				self::build (token, T_BOOLEAN_OR);
		KI_LOOKSTR_CASE ("->")				self::build (token, T_CHILD);
		KI_LOOKSTR_CASE ("::")				self::build (token, T_COLON);
		KI_LOOKSTR_CASE ("=>")				self::build (token, T_EQUAL_ARROW);
		KI_LOOKSTR_CASE ("+=")				self::build (token, T_EQUAL_ADD);
		KI_LOOKSTR_CASE ("-=")				self::build (token, T_EQUAL_SUB);
		KI_LOOKSTR_CASE ("*=")				self::build (token, T_EQUAL_MUL);
		KI_LOOKSTR_CASE ("/=")				self::build (token, T_EQUAL_DIV);
		KI_LOOKSTR_CASE (".=")				self::build (token, T_EQUAL_CAT);
		KI_LOOKSTR_CASE ("%=")				self::build (token, T_EQUAL_MOD);
		KI_LOOKSTR_CASE ("&=")				self::build (token, T_EQUAL_AND);
		KI_LOOKSTR_CASE ("|=")				self::build (token, T_EQUAL_OR);
		KI_LOOKSTR_CASE ("^=")				self::build (token, T_EQUAL_XOR);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (operator_ternary) {
	KI_LOOKSTR (text, strcmp) {
		KI_LOOKSTR_CASE ("===")				self::build (token, T_IS_IDENTICAL);
		KI_LOOKSTR_CASE ("!==")				self::build (token, T_IS_NOT_IDENTICAL);
		KI_LOOKSTR_CASE ("<<=")				self::build (token, T_EQUAL_SHL);
		KI_LOOKSTR_CASE (">>=")				self::build (token, T_EQUAL_SHR);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (operator_cast) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("(int)")			self::build (token, T_CAST_INTEGER);
		KI_LOOKSTR_CASE ("(integer)")		self::build (token, T_CAST_INTEGER);
		KI_LOOKSTR_CASE ("(float)")			self::build (token, T_CAST_FLOAT);
		KI_LOOKSTR_CASE ("(double)")		self::build (token, T_CAST_FLOAT);
		KI_LOOKSTR_CASE ("(bool)")			self::build (token, T_CAST_BOOLEAN);
		KI_LOOKSTR_CASE ("(boolean)")		self::build (token, T_CAST_BOOLEAN);
		KI_LOOKSTR_CASE ("(string)")		self::build (token, T_CAST_STRING);
		KI_LOOKSTR_CASE ("(array)")			self::build (token, T_CAST_ARRAY);
		KI_LOOKSTR_CASE ("(object)")		self::build (token, T_CAST_OBJECT);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (operator_word) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("and")				self::build (token, T_LOGICAL_AND);
		KI_LOOKSTR_CASE ("or")				self::build (token, T_LOGICAL_OR);
		KI_LOOKSTR_CASE ("xor")				self::build (token, T_LOGICAL_XOR);
		KI_LOOKSTR_CASE ("clone")			self::build (token, T_CLONE);
		KI_LOOKSTR_CASE ("new")				self::build (token, T_NEW);
		KI_LOOKSTR_CASE ("instanceof")		self::build (token, T_INSTANCEOF);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}




DEF_CALL (keyword_wrapper) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("class")			self::build (token, T_CLASS);
		KI_LOOKSTR_CASE ("interface")		self::build (token, T_INTERFACE);
		KI_LOOKSTR_CASE ("extends")			self::build (token, T_EXTENDS);
		KI_LOOKSTR_CASE ("implements")		self::build (token, T_IMPLEMENTS);
		KI_LOOKSTR_CASE ("public")			self::build (token, T_PUBLIC);
		KI_LOOKSTR_CASE ("protected")		self::build (token, T_PROTECTED);
		KI_LOOKSTR_CASE ("private")			self::build (token, T_PRIVATE);
		KI_LOOKSTR_CASE ("final")			self::build (token, T_FINAL);
		KI_LOOKSTR_CASE ("abstract")		self::build (token, T_ABSTRACT);
		KI_LOOKSTR_CASE ("static")			self::build (token, T_STATIC);
		KI_LOOKSTR_CASE ("const")			self::build (token, T_CONST);
		KI_LOOKSTR_CASE ("function")		self::build (token, T_FUNCTION);
		KI_LOOKSTR_CASE ("global")			self::build (token, T_GLOBAL);
		KI_LOOKSTR_CASE ("return")			self::build (token, T_RETURN);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (keyword_control) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("if")				self::build (token, T_IF);
		KI_LOOKSTR_CASE ("elseif")			self::build (token, T_ELSEIF);
		KI_LOOKSTR_CASE ("else")			self::build (token, T_ELSE);
		KI_LOOKSTR_CASE ("while")			self::build (token, T_WHILE);
		KI_LOOKSTR_CASE ("do")				self::build (token, T_DO);
		KI_LOOKSTR_CASE ("for")				self::build (token, T_FOR);
		KI_LOOKSTR_CASE ("foreach")			self::build (token, T_FOREACH);
		KI_LOOKSTR_CASE ("as")				self::build (token, T_AS);
		KI_LOOKSTR_CASE ("switch")			self::build (token, T_SWITCH);
		KI_LOOKSTR_CASE ("case")			self::build (token, T_CASE);
		KI_LOOKSTR_CASE ("default")			self::build (token, T_DEFAULT);
		KI_LOOKSTR_CASE ("continue")		self::build (token, T_CONTINUE);
		KI_LOOKSTR_CASE ("break")			self::build (token, T_BREAK);
		KI_LOOKSTR_CASE ("try")				self::build (token, T_TRY);
		KI_LOOKSTR_CASE ("catch")			self::build (token, T_CATCH);
		KI_LOOKSTR_CASE ("finally")			self::build (token, T_FINALLY);
		KI_LOOKSTR_CASE ("throw")			self::build (token, T_THROW);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (keyword_language) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("include")			self::build (token, T_INCLUDE);
		KI_LOOKSTR_CASE ("include_once")	self::build (token, T_INCLUDE_ONCE);
		KI_LOOKSTR_CASE ("require")			self::build (token, T_REQUIRE);
		KI_LOOKSTR_CASE ("require_once")	self::build (token, T_REQUIRE_ONCE);
		KI_LOOKSTR_CASE ("echo")			self::build (token, T_ECHO);
		KI_LOOKSTR_CASE ("exit")			self::build (token, T_EXIT);
		KI_LOOKSTR_CASE ("die")				self::build (token, T_EXIT);
		KI_LOOKSTR_CASE ("eval")			self::build (token, T_EVAL);
		KI_LOOKSTR_CASE ("isset")			self::build (token, T_ISSET);
		KI_LOOKSTR_CASE ("unset")			self::build (token, T_UNSET);
		KI_LOOKSTR_CASE ("empty")			self::build (token, T_EMPTY);
		KI_LOOKSTR_CASE ("array")			self::build (token, T_ARRAY);
		KI_LOOKSTR_CASE ("list")			self::build (token, T_LIST);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}




DEF_CALL (constant) {
	KI_LOOKSTR (text, stricmp) {
		KI_LOOKSTR_CASE ("true")			self::build (token, T_CONSTANT_TRUE);
		KI_LOOKSTR_CASE ("false")			self::build (token, T_CONSTANT_FALSE);
		KI_LOOKSTR_CASE ("null")			self::build (token, T_CONSTANT_NULL);
		KI_LOOKSTR_CASE ("__FUNCTION__")	self::build (token, T_CONSTANT_FUNCTION);
		KI_LOOKSTR_CASE ("__CLASS__")		self::build (token, T_CONSTANT_CLASS);
		KI_LOOKSTR_CASE ("__METHOD__")		self::build (token, T_CONSTANT_METHOD);
		KI_LOOKSTR_CASE ("__DIR__")			self::build (token, T_CONSTANT_DIR);
		KI_LOOKSTR_CASE ("__FILE__")		self::build (token, T_CONSTANT_FILE);
		KI_LOOKSTR_CASE ("__LINE__")		self::build (token, T_INTEGER, (signed int) RCD4::line);

		KI_LOOKSTR_DEFAULT ( )				self::build (token, T_UNDEFINED);
	}

	RETURN;
}


DEF_CALL (identifier) {
	self::build (token, T_IDENTIFIER, text);

	RETURN;
}


DEF_CALL (variable) {
	self::build (token, T_VARIABLE, text + 1);

	RETURN;
}




DEF_CALL (string_start) {
	self::mode		= MODE_STRING;
	self::buffer	= new STR1 ( );
	self::encode	= false;

	if(* text == '@') {
		if(C3(enable_encode) == true) {
			self::encode	= true;
		} else {
			RCD4::warning (true, "编码支持已被禁用，字符串将会以字面常量的形式出现。如需启用编码支持，请使用编译杂注 #!encode 或 -encode-on 参数。");
		}
	}
}


DEF_CALL (string_end) {
	if(self::check (self::encode) == true) {
		self::build (token, T_ENCODE_STRING,	self::buffer);
	} else {
		self::build (token, T_STRING,			self::buffer);
	}

	self::mode		= MODE_PHP;
	self::buffer	= NULL;
	self::encode	= false;

	RETURN;
}


DEF_CALL (string_complex_next) {
	if(self::check (self::encode) == true) {
		self::build (token, T_ENCODE_STRING,	self::buffer);
	} else {
		self::build (token, T_STRING,			self::buffer);
	}

	self::buffer	= new STR1 ( );

	RETURN;
}


DEF_CALL (string_complex_concat) {
	self::build (token, '.');

	RETURN;
}


DEF_CALL (string_complex_name) {
	if(* text == '$') {
		self::build (token, T_VARIABLE, text + 1);
	} else {
		self::build (token, T_VARIABLE, text);
	}

	RETURN;
}




DEF_CONCAT (all) {
	self::append (text, length);
}


DEF_CONCAT (escape) {
	const char *	byte;

	switch(* (text + 1)) {
		case '\\':	byte	= "\\";			break;
		case '\'':	byte	= "'";			break;
		case '"':	byte	= "\"";			break;
		case '$':	byte	= "$";			break;

		case 'a':	byte	= "\a";			break;
		case 'f':	byte	= "\f";			break;
		case 'n':	byte	= "\n";			break;
		case 'r':	byte	= "\r";			break;
		case 't':	byte	= "\t";			break;

		default:	return;
	}

	self::append (byte, 1);
}


DEF_CONCAT (value) {
	signed int		value;
	unsigned char	buffer	[4]	= {0};

	if(* (text + 1) == 'x') {
		value	= (signed int) strtol (text + 2, NULL, 16);
	} else {
		value	= (signed int) strtol (text + 1, NULL,  8);
	}

	if(value > 255) {
		RCD4::warning (true, "字符串内使用转义方式指定的字符超出了表示范围的上限，实际表达的值将不准确。");

		value	= 255;
	}

	buffer [0]	= (unsigned char) value;

	self::append ((char *) buffer, 1);
}


