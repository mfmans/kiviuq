/*
	$ [KiPHP] /r5/syntax_lexer.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 5

#ifndef _R5_SYNTAX_LEXER_H_
#define _R5_SYNTAX_LEXER_H_


#ifdef _KI_MSC_
	#include <io.h>
#endif




/* for lexer.l */
#ifdef KI_SYNTAX_DEFINITION
	// 调用处理
	#define CALL(n)					r5_syntax_lexer::handler_call_##n	(yylval, yytext, yyleng)
	#define CONCAT(n)				r5_syntax_lexer::handler_concat_##n	(yytext, yyleng)

	// 放弃处理
	#define WAIVE()					yyless (0)
	// 计数
	#define COUNT()					r5_syntax_lexer::count (yytext, yyleng)
	// 返回值
	#define RETURN()				return r5_syntax_lexer::token;


	#define yyalloc					r5_syntax_alloc
	#define yyrealloc				r5_syntax_realloc
	#define yyfree					r5_syntax_free


	#ifdef _KI_MSC_
		#define isatty				_isatty
	#endif
#endif




/* 处理器声明 */
#define DECL_CALL(n)				static	void	handler_call_##n	(r5_syntax_token_t token, const char *text, int length)
#define DECL_CONCAT(n)				static	void	handler_concat_##n	(const char *text, int length)

/* 处理器定义 */
#define DEF_CALL(n)					void	r5_syntax_lexer::handler_call_##n	(r5_syntax_token_t token, const char *text, int length)
#define DEF_CONCAT(n)				void	r5_syntax_lexer::handler_concat_##n	(const char *text, int length)




/* 识别模式 */
typedef enum {
	MODE_PHP,
	MODE_HTML,
	MODE_STRING,
} r5_syntax_lexer_mode_e;




/* 词法解析器 */
class r5_syntax_lexer {
	public:
		/* 返回值 */
		static	r5_syntax_token_type_e	token;

		/* 识别模式 */
		static	r5_syntax_lexer_mode_e	mode;

		/* 编码 */
		static	bool	encode;

		/* 缓冲区 */
		static	STR1 *	buffer;


		/* 计数器 */
		static	void	count	(const char *text, int length);


		/* 附加数据到缓冲区 */
		static	void	append	(const char *p, int length);


		/* 创建单词 */
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, char type);
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, r5_syntax_token_type_e type);
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, r5_syntax_token_type_e type, signed int value);
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, r5_syntax_token_type_e type, double value);
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, r5_syntax_token_type_e type, const char *value);
		static	r5_syntax_token_t	build	(r5_syntax_token_t token, r5_syntax_token_type_e type, STR1 *value);

		/* 判断编码支持 */
		static	bool	check	(bool status, const char *text = NULL);


		DECL_CALL	(eof);
		DECL_CALL	(undefined);
		
		DECL_CALL	(php_open);
		DECL_CALL	(php_close);
		DECL_CALL	(php_echo);

		DECL_CALL	(pragma);
		
		DECL_CALL	(string_start);
		DECL_CALL	(string_end);
		DECL_CALL	(string_complex_next);
		DECL_CALL	(string_complex_concat);
		DECL_CALL	(string_complex_name);
		
		DECL_CALL	(integer_bin);
		DECL_CALL	(integer_oct);
		DECL_CALL	(integer_dec);
		DECL_CALL	(integer_hex);
		DECL_CALL	(double);
		
		DECL_CALL	(operator_unary);
		DECL_CALL	(operator_binary);
		DECL_CALL	(operator_ternary);
		DECL_CALL	(operator_cast);
		DECL_CALL	(operator_word);
		
		DECL_CALL	(keyword_wrapper);
		DECL_CALL	(keyword_control);
		DECL_CALL	(keyword_language);
		
		DECL_CALL	(constant);

		DECL_CALL	(identifier);

		DECL_CALL	(variable);

		
		DECL_CONCAT	(all);
		DECL_CONCAT	(escape);
		DECL_CONCAT	(value);
};




#endif

#endif