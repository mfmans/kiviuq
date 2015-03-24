/*
	$ [KiPHP] /r5/syntax_parser.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 5

#ifndef _R5_SYNTAX_PARSER_H_
#define _R5_SYNTAX_PARSER_H_




/* for parser.y */
#ifdef KI_SYNTAX_DEFINITION
	#define ZR(p)					M0::zero (p, sizeof (r5_syntax_token_o))


	#define YYLEX_PARAM				& yylval
	#define YYERROR_VERBOSE			1

	#define YYMALLOC				r5_syntax_alloc
	#define YYFREE					r5_syntax_free

	#define yyerror(m)				RCD4::error (true, "%s。", m)
#endif




/* 处理器名称 */
#define FUNC(name)					handler_##name

/* 处理器调用 */
#define CALL(name)					r5_syntax_parser::FUNC(name)


/* 处理器声明 */
#define DECL_T0(name)				static	void	FUNC(name)	(void)
#define DECL_T1(name)				static	void	FUNC(name)	(r5_syntax_token_t)
#define DECL_T2(name)				static	void	FUNC(name)	(r5_syntax_token_t, r5_syntax_token_t)
#define DECL_T3(name)				static	void	FUNC(name)	(r5_syntax_token_t, r5_syntax_token_t, r5_syntax_token_t)

/* 处理器定义 */
#define DEF_T0(name)				void	r5_syntax_parser::FUNC(name)	(void)
#define DEF_T1(name)				void	r5_syntax_parser::FUNC(name)	(r5_syntax_token_t t1)
#define DEF_T2(name)				void	r5_syntax_parser::FUNC(name)	(r5_syntax_token_t t1, r5_syntax_token_t t2)
#define DEF_T3(name)				void	r5_syntax_parser::FUNC(name)	(r5_syntax_token_t t1, r5_syntax_token_t t2, r5_syntax_token_t t3)




/* 语法分析器 */
class r5_syntax_parser {
	private:
		static	void	token_to_operand	(r5_syntax_token_t token, r2_code_directive_operand_t operand);


	public:
		DECL_T2 (pragma);

		DECL_T1 (define_function_begin);
		DECL_T1 (define_function_end);
		DECL_T1 (define_function_parameter_required);
		DECL_T1 (define_function_parameter_optional);
		
		DECL_T2 (define_class_begin);
		DECL_T0 (define_class_end);
		DECL_T1 (define_class_extend);
		DECL_T1 (define_class_implement);
		DECL_T1 (define_class_feature);
		DECL_T0 (define_class_next);
		DECL_T2 (define_class_const);
		DECL_T2 (define_class_property);

		DECL_T0 (statement_expression);
		DECL_T1 (statement_html);
		DECL_T0 (statement_echo);
		DECL_T0 (statement_exit);
		DECL_T0 (statement_eval);
		DECL_T1 (statement_return);
		DECL_T2 (statement_static);
		DECL_T1 (statement_global);
		
		DECL_T1 (unset_variable);
		DECL_T1 (unset_array_begin);
		DECL_T0 (unset_array_end);
		DECL_T0 (unset_array_shift);
		
		DECL_T0 (exprlist_next);
		DECL_T0 (exprlist_empty);

		DECL_T0 (expr_silent_on);
		DECL_T0 (expr_silent_off);

		DECL_T1 (const_expression);

		DECL_T0 (array_build);
		DECL_T0 (array_extend);
		DECL_T1 (array_update);
};




#endif

#endif