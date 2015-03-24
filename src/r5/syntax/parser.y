%{

/*
	$ [KiPHP] /r5/syntax/parser.y  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#define KI_SYNTAX_DEFINITION


#include "../../kiviuq.h"
#include "../syntax.h"
#include "../syntax_parser.h"



%}



%token		T_EOF					0					"Œƒº˛Œ≤ EOF"
%token		T_UNDEFINED									"Œ¥∂®“Â◊÷∑˚ UND"

%left		','

%left		T_LOGICAL_OR
%token		T_LOGICAL_OR								"or"
%left		T_LOGICAL_XOR
%token		T_LOGICAL_XOR								"xor"
%left		T_LOGICAL_AND
%token		T_LOGICAL_AND								"and"

%right		'=' T_EQUAL_ADD T_EQUAL_SUB T_EQUAL_MUL T_EQUAL_DIV T_EQUAL_CAT T_EQUAL_MOD T_EQUAL_AND T_EQUAL_OR T_EQUAL_XOR T_EQUAL_SHL T_EQUAL_SHR T_EQUAL_ARROW
%token		T_EQUAL_ADD									"+="
%token		T_EQUAL_SUB									"-="
%token		T_EQUAL_MUL									"*="
%token		T_EQUAL_DIV									"/="
%token		T_EQUAL_CAT									".="
%token		T_EQUAL_MOD									"%="
%token		T_EQUAL_AND									"&="
%token		T_EQUAL_OR									"|="
%token		T_EQUAL_XOR									"^="
%token		T_EQUAL_SHL									"<<="
%token		T_EQUAL_SHR									">>="
%token		T_EQUAL_ARROW								"=>"

%left		'?' ':'

%left		T_BOOLEAN_OR
%token		T_BOOLEAN_OR								"||"
%left		T_BOOLEAN_AND
%token		T_BOOLEAN_AND								"&&"

%left		'|'
%left		'^'
%left		'&'

%nonassoc	T_IS_EQUAL T_IS_NOT_EQUAL T_IS_IDENTICAL T_IS_NOT_IDENTICAL T_IS_SMALLER_GREATER
%token		T_IS_EQUAL									"=="
%token		T_IS_NOT_EQUAL								"!="
%token		T_IS_IDENTICAL								"==="
%token		T_IS_NOT_IDENTICAL							"!=="
%token		T_IS_SMALLER_GREATER						"<>"

%nonassoc	'<' T_IS_SMALLER_EQUAL '>' T_IS_GREATER_EQUAL
%token		T_IS_SMALLER_EQUAL							"<="
%token		T_IS_GREATER_EQUAL							">="

%left		T_SHL T_SHR
%token		T_SHL										"<<"
%token		T_SHR										">>"

%left		'+' '-' '.'
%left		'*' '/' '%'

%right		'!'

%nonassoc	T_INSTANCEOF
%token		T_INSTANCEOF								"instanceof"

%right		T_INC T_DEC '~' T_CAST_INTEGER T_CAST_FLOAT T_CAST_STRING T_CAST_ARRAY T_CAST_OBJECT T_CAST_BOOLEAN '@'
%token		T_INC										"++"
%token		T_DEC										"--"
%token		T_CAST_INTEGER								"(int)"
%token		T_CAST_FLOAT								"(double)"
%token		T_CAST_STRING								"(string)"
%token		T_CAST_ARRAY								"(array)"
%token		T_CAST_OBJECT								"(object)"
%token		T_CAST_BOOLEAN								"(bool)"

%left		'['

%nonassoc	T_CLONE T_NEW
%token		T_CLONE										"clone"
%token		T_NEW										"new"

%token		T_CHILD										"->"
%token		T_COLON										"::"

%token		T_CLASS										"class"
%token		T_INTERFACE									"interface"
%token		T_EXTENDS									"extends"
%token		T_IMPLEMENTS								"implements"
%token		T_PUBLIC									"public"
%token		T_PROTECTED									"protected"
%token		T_PRIVATE									"private"
%token		T_FINAL										"final"
%token		T_ABSTRACT									"abstract"
%token		T_STATIC									"static"
%token		T_CONST										"const"

%token		T_FUNCTION									"function"
%token		T_GLOBAL									"global"
%token		T_RETURN									"return"

%token		T_IF										"if"
%left		T_ELSEIF
%token		T_ELSEIF									"elseif"
%token		T_ELSE										"else"

%token		T_WHILE										"while"
%token		T_DO										"do"
%token		T_FOR										"for"
%token		T_FOREACH									"foreach"
%token		T_AS										"as"

%token		T_SWITCH									"switch"
%token		T_CASE										"case"
%token		T_DEFAULT									"default"

%token		T_CONTINUE									"continue"
%token		T_BREAK										"break"

%token		T_TRY										"try"
%token		T_CATCH										"catch"
%token		T_FINALLY									"finally"
%token		T_THROW										"throw"

%token		T_INCLUDE									"include"
%token		T_INCLUDE_ONCE								"include_once"
%token		T_REQUIRE									"require"
%token		T_REQUIRE_ONCE								"require_once"

%token		T_ECHO										"echo"
%token		T_EXIT										"exit"
%token		T_EVAL										"eval"

%token		T_ISSET										"isset"
%token		T_UNSET										"unset"
%token		T_EMPTY										"empty"

%token		T_ARRAY										"array"

%token		T_LIST										"list"

%token		T_CONSTANT_TRUE								"true"
%token		T_CONSTANT_FALSE							"false"
%token		T_CONSTANT_NULL								"null"

%token		T_CONSTANT_FUNCTION							"__FUNCTION__"
%token		T_CONSTANT_CLASS							"__CLASS__"
%token		T_CONSTANT_METHOD							"__METHOD__"
%token		T_CONSTANT_DIR								"__DIR__"
%token		T_CONSTANT_FILE								"__FILE__"

%token		T_HTML										"ƒ⁄«∂ HTML"

%token		T_INTEGER									"’˚ ˝ INT"
%token		T_FLOAT										"∏°µ„ ˝ FLOAT"
%token		T_STRING									"◊÷∑˚¥Æ STRING"

%token		T_ENCODE_INTEGER							"±‡¬Î’˚ ˝ ENC INT"
%token		T_ENCODE_STRING								"±‡¬Î◊÷∑˚¥Æ ENC STRING"

%token		T_VARIABLE									"±‰¡ø VAR"

%token		T_IDENTIFIER								"±Í ∂∑˚ IDENTIFIER"

%token		T_PRAGMA_EXPORT								"±‡“Î‘”◊¢ '#!export'"
%token		T_PRAGMA_ENCODE								"±‡“Î‘”◊¢ '#!encode'"
%token		T_PRAGMA_INLINE								"±‡“Î‘”◊¢ '#!inline'"
%token		T_PRAGMA_VM_WRAPPER							"±‡“Î‘”◊¢ '#!vm-wrapper'"
%token		T_PRAGMA_VM_ENTRY							"±‡“Î‘”◊¢ '#!vm-entry'"
%token		T_PRAGMA_VM_HEAP							"±‡“Î‘”◊¢ '#!vm-heap'"
%token		T_PRAGMA_VM_STACK							"±‡“Î‘”◊¢ '#!vm-stack'"
%token		T_PRAGMA_VM_TOP								"±‡“Î‘”◊¢ '#!vm-top'"
%token		T_PRAGMA_VM_BOTTOM							"±‡“Î‘”◊¢ '#!vm-bottom'"
%token		T_PRAGMA_VM_EXCEPTION						"±‡“Î‘”◊¢ '#!vm-exception'"
%token		T_PRAGMA_VM_PROGRAM							"±‡“Î‘”◊¢ '#!vm-program'"
%token		T_PRAGMA_VM_RETURN							"±‡“Î‘”◊¢ '#!vm-return'"
%token		T_PRAGMA_VM_MIDDLE							"±‡“Î‘”◊¢ '#!vm-middle'"




%%



start:
		outer_statement_list
;




outer_statement_list:
		/* empty */
	|	outer_statement_list
		outer_statement
;


outer_statement:
		pragma

	|	define_function
	|	define_class

	|	inner_statement
;



pragma:
		T_PRAGMA_EXPORT		'(' T_IDENTIFIER	')'							{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_EXPORT		'(' T_VARIABLE		')'							{	CALL (pragma)	(& $1, & $3);	}

	|	T_PRAGMA_ENCODE		'(' T_CONSTANT_TRUE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_ENCODE		'(' T_CONSTANT_FALSE	')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_INLINE		'(' T_CONSTANT_TRUE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_INLINE		'(' T_CONSTANT_FALSE	')'						{	CALL (pragma)	(& $1, & $3);	}

	|	T_PRAGMA_VM_WRAPPER		'(' T_IDENTIFIER	')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_ENTRY		'(' T_IDENTIFIER	')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_HEAP		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_STACK		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_TOP			'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_BOTTOM		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_EXCEPTION	'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_PROGRAM		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_RETURN		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
	|	T_PRAGMA_VM_MIDDLE		'(' T_VARIABLE		')'						{	CALL (pragma)	(& $1, & $3);	}
;




define_function:
		define_function_header
		define_function_body
;


define_function_header:
		T_FUNCTION T_IDENTIFIER												{	CALL (define_function_begin)	(& $2);		}
		'(' define_function_parameter_list ')'
;


define_function_parameter_list:
		/* empty */
	|	define_function_parameter_required_list
	|	define_function_parameter_optional_list
	|	define_function_parameter_required_list ','
		define_function_parameter_optional_list
;


define_function_parameter_required_list:
		define_function_parameter_required_list ','
		define_function_parameter_required
	|	define_function_parameter_required
;


define_function_parameter_required:
		T_VARIABLE															{	CALL (define_function_parameter_required)	(& $1);		}
;


define_function_parameter_optional_list:
		define_function_parameter_optional_list ','
		define_function_parameter_optional
	|	define_function_parameter_optional
;


define_function_parameter_optional:
		T_VARIABLE '=' const_expression										{	CALL (define_function_parameter_optional)	(& $1);		}
;


define_function_body:
		'{' inner_statement_list '}'										{	CALL (define_function_end)		(& $1);		}
	|	';'																	{	CALL (define_function_end)		(NULL);		}
;




define_class:
		define_class_feature T_CLASS T_IDENTIFIER							{	CALL (define_class_begin)	(& $3, & $1);		}
		define_class_extends
		define_class_implements
		'{' define_class_member_list '}'									{	CALL (define_class_end)		( );				}
;


define_class_feature:
		/* empty */															{	ZR (& $$);	}
	|	T_FINAL																{	$$	= $1;	}
	|	T_ABSTRACT															{	$$	= $1;	}
;


define_class_extends:
		/* empty */
	|	T_EXTENDS T_IDENTIFIER												{	CALL (define_class_extend)	(& $2);		}
;


define_class_implements:
		/* empty */
	|	T_IMPLEMENTS define_class_implements_list
;


define_class_implements_list:
		define_class_implements_list ','
		T_IDENTIFIER														{	CALL (define_class_implement)	(& $3);		}
	|	T_IDENTIFIER														{	CALL (define_class_implement)	(& $1);		}
;


define_class_member_list:
		/* empty */
	|	define_class_member_list
		define_class_member
;


define_class_member:
		T_CONST define_class_const_list ';'
	|	define_class_member_feature_list define_class_property_list ';'		{	CALL (define_class_next)	( );		}
	|	define_class_member_feature_list define_function					{	CALL (define_class_next)	( );		}
;


define_class_member_feature_list:
		/* empty */
	|	define_class_member_feature_list
		define_class_member_feature
;


define_class_member_feature:
		T_PUBLIC															{	CALL (define_class_feature)	(& $1);		}
	|	T_PROTECTED															{	CALL (define_class_feature)	(& $1);		}
	|	T_PRIVATE															{	CALL (define_class_feature)	(& $1);		}
	|	T_STATIC															{	CALL (define_class_feature)	(& $1);		}
	|	T_FINAL																{	CALL (define_class_feature)	(& $1);		}
	|	T_ABSTRACT															{	CALL (define_class_feature)	(& $1);		}
;


define_class_const_list:
		define_class_const_list ','
		define_class_const
	|	define_class_const
;


define_class_const:
		T_IDENTIFIER '=' constant											{	CALL (define_class_const)	(& $1, & $3);	}
;


define_class_property_list:
		define_class_property_list ','
		define_class_property
	|	define_class_property
;


define_class_property:
		T_VARIABLE															{	CALL (define_class_property)	(& $1, NULL);	}
	|	T_VARIABLE '=' const_expression										{	CALL (define_class_property)	(& $1, & $2);	}
;




inner_statement_list:
		/* empty */
	|	inner_statement_list
		inner_statement
;


inner_statement:
		'{' inner_statement_list '}'

	|	expression_list_or_empty ';'										{	CALL (statement_expression)	( );	}

	|	T_HTML																{	CALL (statement_html)	(& $1);		}

	|	T_ECHO echo_list ';'
	|	T_EXIT exit_code ';'												{	CALL (statement_exit)	( );		}
	|	T_EVAL '(' expression ')' ';'										{	CALL (statement_eval)	( );		}

	|	T_RETURN ';'														{	CALL (statement_return)	(NULL);		}
	|	T_RETURN '(' ')' ';'												{	CALL (statement_return) (NULL);		}
	|	T_RETURN expression ';'												{	CALL (statement_return) (& $2);		}

	|	T_STATIC	static_define_list ';'
	|	T_GLOBAL	global_list ';'

	|	T_UNSET '(' unset_define_list ')' ';'
;




echo_list:
		echo_list ','
		expression															{	CALL (statement_echo)	( );		}
	|	expression															{	CALL (statement_echo)	( );		}
;


exit_code:
		/* empty */
	|	'(' ')'
	|	'(' expression ')'													{	CALL (statement_echo)	( );		}
;


static_define_list:
		static_define_list ','
		static_define
	|	static_define
;


static_define:
		T_VARIABLE															{	CALL (statement_static)	(& $1, NULL);		}
	|	T_VARIABLE '=' const_expression										{	CALL (statement_static) (& $1, & $2);		}
;


global_list:
		global_list ','
		T_VARIABLE															{	CALL (statement_global)	(& $1);		}
	|	T_VARIABLE															{	CALL (statement_global)	(& $1);		}
;


unset_define_list:
		unset_define_list ','
		unset_define
	|	unset_define
;


unset_define:
		T_VARIABLE															{	CALL (unset_variable)		(& $1);		}
	|	T_VARIABLE															{	CALL (unset_array_begin)	(& $1);		}
		unset_define_array '[' expression ']'								{	CALL (unset_array_end)		( );		}
;


unset_define_array:
		/* empty */
	|	unset_define_array
		'[' expression ']'													{	CALL (unset_array_shift)	( );		}
;




expression_list_or_empty:
		/* empty */															{	CALL (exprlist_empty)	( );	}
	|	expression_list
;


expression_list:
		expression_list ','													{	CALL (exprlist_next)	( );	}
		expression
	|	expression
;


expression:
		'(' expression_list ')'

	|	'@'																	{	CALL (expr_silent_on)	( );	}
		expression															{	CALL (expr_silent_off)	( );	}

	|	constant															{	CALL (const_expression)	(& $1);		}

	|	array

	|	call_expr
;




argument_list:
		/* empty */
	|	argument_list
		expression
;




call_expr:
		T_VARIABLE '(' argument_list ')'
	|	T_IDENTIFIER '(' argument_list ')'
	|	call_expr T_CHILD T_IDENTIFIER '(' argument_list ')'
	|	call_expr T_CHILD T_VARIABLE '(' argument_list ')'
;




const_expression:
		const_array
	|	constant															{	CALL (const_expression)	(& $1);		}
;




const_array:
		T_ARRAY '('															{	CALL (array_build)	( );	}
			const_array_define
		')'
;


const_array_define:
		/* empty */
	|	const_array_entry_list
	|	const_array_entry_list ','
;


const_array_entry_list:
		const_array_entry_list ','
		const_array_entry
	|	const_array_entry
;


const_array_entry:
		const_expression													{	CALL (array_extend)	( );		}
	|	const_array_entry_key T_EQUAL_ARROW const_expression				{	CALL (array_update)	(& $1);		}
;


const_array_entry_key:
		T_INTEGER															{	$$	= $1;	}
	|	T_STRING															{	$$	= $1;	}
;




array:
		T_ARRAY '('															{	CALL (array_build)	( );	}
			array_define
		')'
;


array_define:
		/* empty */
	|	array_entry_list
	|	array_entry_list ','
;


array_entry_list:
		array_entry_list ','
		array_entry
	|	array_entry
;


array_entry:
		expression															{	CALL (array_extend)	( );		}
	|	array_entry_key T_EQUAL_ARROW expression							{	CALL (array_update)	(& $1);		}
;


array_entry_key:
		T_INTEGER															{	$$	= $1;	}
	|	T_STRING															{	$$	= $1;	}
;




constant:
		T_INTEGER															{	$$	= $1;	}
	|	T_FLOAT																{	$$	= $1;	}
	|	T_STRING															{	$$	= $1;	}
	|	T_IDENTIFIER														{	$$	= $1;	}
	|	T_CONSTANT_TRUE														{	$$	= $1;	}
	|	T_CONSTANT_FALSE													{	$$	= $1;	}
	|	T_CONSTANT_NULL														{	$$	= $1;	}
	|	T_CONSTANT_FUNCTION													{	$$	= $1;	}
	|	T_CONSTANT_CLASS													{	$$	= $1;	}
	|	T_CONSTANT_METHOD													{	$$	= $1;	}
	|	T_CONSTANT_DIR														{	$$	= $1;	}
	|	T_CONSTANT_FILE														{	$$	= $1;	}
;

