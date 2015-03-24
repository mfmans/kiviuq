%top{

/*
	$ [KiPHP] /r5/syntax/lexer.l  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#define KI_SYNTAX_DEFINITION


#include "../../kiviuq.h"
#include "../syntax.h"
#include "../syntax_lexer.h"



}



%option		bison-bridge
%option		case-insensitive
%option		8bit

%option		noyywrap
%option		nounistd
%option		noyyalloc
%option		noyyrealloc
%option		noyyfree


%x	PHP
%x	PHP_ECHO
%x	STRING_SIMPLE
%x	STRING_COMPLEX_TEXT
%x	STRING_COMPLEX_NAME
%x	STRING_COMPLEX_END
%x	STRING_COMPLEX_BLOCK
%x	COMMENT_SINGLE
%x	COMMENT_MULTI



%%



<<EOF>>															CALL (eof);											RETURN ( );



<INITIAL>{
	"<?="						BEGIN (PHP_ECHO);				CALL (php_open);					WAIVE ( );		RETURN ( );
	"<?php"						BEGIN (PHP);					CALL (php_open);					COUNT ( );		RETURN ( );
	"<?"						BEGIN (PHP);					CALL (php_open);					COUNT ( );		RETURN ( );

	"\n"|.														CONCAT (all);						COUNT ( );
}



<PHP>{
	"?>"						BEGIN (INITIAL);				CALL (php_close);					COUNT ( );		RETURN ( );

	"#!"[a-z_\-]+												CALL (pragma);						COUNT ( );		RETURN ( );

	"@"?"'"						BEGIN (STRING_SIMPLE);			CALL (string_start);				COUNT ( );
	"@"?"\""					BEGIN (STRING_COMPLEX_TEXT);	CALL (string_start);				COUNT ( );

	"#"							BEGIN (COMMENT_SINGLE);												COUNT ( );
	"//"						BEGIN (COMMENT_SINGLE);												COUNT ( );
	"/*"						BEGIN (COMMENT_MULTI);												COUNT ( );

	"@"?"0"														CALL (integer_dec);					COUNT ( );		RETURN ( );
	"@"?"0b"[01]+												CALL (integer_bin);					COUNT ( );		RETURN ( );
	"@"?"0"[0-7]+												CALL (integer_oct);					COUNT ( );		RETURN ( );
	"@"?"-"?[1-9][0-9]*											CALL (integer_dec);					COUNT ( );		RETURN ( );
	"@"?"0x"[0-9a-f]+											CALL (integer_hex);					COUNT ( );		RETURN ( );

	"-"?[0-9]+"."[0-9]*("e"[\+\-]?[0-9]+)?						CALL (double);						COUNT ( );		RETURN ( );
	"-"?[0-9]*"."[0-9]+("e"[\+\-]?[0-9]+)?						CALL (double);						COUNT ( );		RETURN ( );

	"("|")"|"["|"]"|"{"|"}"										CALL (operator_unary);				COUNT ( );		RETURN ( );
	"+"|"-"|"*"|"/"|"."|"%"|"&"|"|"|"!"|"^"|"~"					CALL (operator_unary);				COUNT ( );		RETURN ( );
	"<"|">"|"="|"@"|"?"|":"|","|";"								CALL (operator_unary);				COUNT ( );		RETURN ( );

	"++"|"--"|"<<"|">>"											CALL (operator_binary);				COUNT ( );		RETURN ( );
	"=="|"!="|"<="|">="|"<>"									CALL (operator_binary);				COUNT ( );		RETURN ( );
	"&&"|"||"|"->"|"::"|"=>"									CALL (operator_binary);				COUNT ( );		RETURN ( );
	"+="|"-="|"*="|"/="|".="|"%="|"&="|"|="|"^="				CALL (operator_binary);				COUNT ( );		RETURN ( );

	"==="|"!=="													CALL (operator_ternary);			COUNT ( );		RETURN ( );
	"<<="|">>="													CALL (operator_ternary);			COUNT ( );		RETURN ( );

	"(int)"|"(integer)"|"(float)"|"(double)"					CALL (operator_cast);				COUNT ( );		RETURN ( );
	"(bool)"|"(boolean)"|"(string)"|"(array)"|"(object)"		CALL (operator_cast);				COUNT ( );		RETURN ( );

	"and"|"or"|"xor"											CALL (operator_word);				COUNT ( );		RETURN ( );
	"clone"|"new"|"instanceof"									CALL (operator_word);				COUNT ( );		RETURN ( );

	"class"|"interface"|"extends"|"implements"					CALL (keyword_wrapper);				COUNT ( );		RETURN ( );
	"public"|"protected"|"private"								CALL (keyword_wrapper);				COUNT ( );		RETURN ( );
	"final"|"abstract"|"static"|"const"							CALL (keyword_wrapper);				COUNT ( );		RETURN ( );
	"function"|"global"|"return"								CALL (keyword_wrapper);				COUNT ( );		RETURN ( );

	"if"|"elseif"|"else"										CALL (keyword_control);				COUNT ( );		RETURN ( );
	"while"|"do"|"for"|"foreach"|"as"							CALL (keyword_control);				COUNT ( );		RETURN ( );
	"switch"|"case"|"default"									CALL (keyword_control);				COUNT ( );		RETURN ( );
	"continue"|"break"											CALL (keyword_control);				COUNT ( );		RETURN ( );
	"try"|"catch"|"finally"|"throw"								CALL (keyword_control);				COUNT ( );		RETURN ( );

	"include"|"include_once"|"require"|"require_once"			CALL (keyword_language);			COUNT ( );		RETURN ( );
	"echo"|"exit"|"die"|"eval"									CALL (keyword_language);			COUNT ( );		RETURN ( );
	"isset"|"unset"|"empty"										CALL (keyword_language);			COUNT ( );		RETURN ( );
	"array"|"list"												CALL (keyword_language);			COUNT ( );		RETURN ( );

	"true"|"false"|"null"										CALL (constant);					COUNT ( );		RETURN ( );
	"__FUNCTION__"|"__CLASS__"|"__METHOD__"						CALL (constant);					COUNT ( );		RETURN ( );
	"__DIR__"|"__FILE__"|"__LINE__"								CALL (constant);					COUNT ( );		RETURN ( );

	[a-z_][a-z0-9_]*											CALL (identifier);					COUNT ( );		RETURN ( );

	"$"[a-z_][a-z0-9_]*											CALL (variable);					COUNT ( );		RETURN ( );

	[ \t\r\n]																						COUNT ( );

	.															CALL (undefined);									RETURN ( );
}



<PHP_ECHO>{
	"<?="						BEGIN (PHP);					CALL (php_echo);					COUNT ( );		RETURN ( );
}



<STRING_SIMPLE>{
	"'"							BEGIN (PHP);					CALL (string_end);					COUNT ( );		RETURN ( );

	"\\'"														CONCAT (escape);					COUNT ( );
	"\\\\"														CONCAT (escape);					COUNT ( );

	"\n"|.														CONCAT (all);						COUNT ( );
}



<STRING_COMPLEX_TEXT>{
	"\""						BEGIN (PHP);					CALL (string_end);					COUNT ( );		RETURN ( );

	"\\"[\\\"$afnrt]											CONCAT (escape);					COUNT ( );

	"\\"[0-7]{1,3}												CONCAT (value);						COUNT ( );
	"\\x"[0-9a-f]{1,2}											CONCAT (value);						COUNT ( );

	"$"[a-z_][a-z0-9_]*			BEGIN (STRING_COMPLEX_NAME);	CALL (string_complex_next);			WAIVE ( );		RETURN ( );
	"{$"[a-z_][a-z0-9_]*"}"		BEGIN (STRING_COMPLEX_BLOCK);	CALL (string_complex_next);			WAIVE ( );		RETURN ( );

	"\n"|.														CONCAT (all);						COUNT ( );
}



<STRING_COMPLEX_NAME>{
	"$"															CALL (string_complex_concat);		COUNT ( );		RETURN ( );
	[a-z_][a-z0-9_]*			BEGIN (STRING_COMPLEX_END);		CALL (string_complex_name);			COUNT ( );		RETURN ( );
}



<STRING_COMPLEX_END>{
	"\n"|.						BEGIN (STRING_COMPLEX_TEXT);	CALL (string_complex_concat);		WAIVE ( );		RETURN ( );
}



<STRING_COMPLEX_BLOCK>{
	"{"															CALL (string_complex_concat);		COUNT ( );		RETURN ( );
	"}"							BEGIN (STRING_COMPLEX_TEXT);	CALL (string_complex_concat);		COUNT ( );		RETURN ( );

	"$"[a-z_][a-z0-9_]*											CALL (string_complex_name);			COUNT ( );		RETURN ( );
}



<COMMENT_SINGLE>{
	"\r"|"\n"|"\r\n"			BEGIN (PHP);														COUNT ( );

	.																								COUNT ( );
}



<COMMENT_MULTI>{
	"*/"						BEGIN (PHP);														COUNT ( );

	"\n"|.																							COUNT ( );
}



%%

