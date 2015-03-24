/*
	$ [KiPHP] /r5/syntax.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../kiviuq.h"
#include "./syntax.h"




void *	r5_syntax_alloc		(size_t size)			{	return	M0::allocate	(size);			}
void *	r5_syntax_realloc	(void *p, size_t size)	{	return	M0::reallocate	(p, size);		}
void 	r5_syntax_free		(void *p)				{			M0::release		(p);			}




STK1<r2_code_t> *	r5_syntax::stack	= NULL;




void r5_syntax::begin (void) {
	// 初始化栈
	r5_syntax::stack	= new STK1<r2_code_t>;

	// 重定向流
	yyin	= O0::stream_in;
	yyout	= NULL;

	// 初始化行号
	RCD4::line	= 1;
}


void r5_syntax::end (void) {
	// 释放栈
	delete r5_syntax::stack;

	yylex_destroy ( );
}


void r5_syntax::call (void) {
	if(yyparse ( ) != 0) {
		LDR0::die ( );
	}
}




void r5_syntax::execute (void) {
	// 执行处理
	r5_syntax::begin	( );
	r5_syntax::call		( );
	r5_syntax::end		( );

	// 对生成的代码进行整理
	BLD4::collect ( );
}


