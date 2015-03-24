/*
	$ [KiPHP] /r5/output_handler/output_handler_symbol.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../../kiviuq.h"




void	r5_output_handler_symbol::callback_begin	(void)						{ }
void	r5_output_handler_symbol::callback_end		(void)						{ }
void	r5_output_handler_symbol::callback_code		(r2_code_t)					{ }
void	r5_output_handler_symbol::callback_function	(r2_class_t, r2_code_t)		{ }




void r5_output_handler_symbol::execute (void) {
	// 输出变量
	if(RCD4::table_variable->ready ( ) == true) {
		r2_variable_t	var;

		while(RCD4::table_variable->fetch (& var) == true) {
			O0::printf ("V# %s : line=%u, offset=%u", var->name->pointer ( ), var->line, var->offset);

			if(var->visible == true) {
				O0::printf (", export=1");
			} else {
				O0::printf (", export=0");
			}

			O0::print ("\n");
		}
	}

	// 输出函数
	if(RCD4::table_function->ready ( ) == true) {
		r2_function_t	func;

		while(RCD4::table_function->fetch (& func) == true) {
			O0::printf ("F# %s : line_call=%u, line_declare=%u, parameter_total=%u, parameter_optional=%u, caller=%u", func->name->pointer ( ), func->line_call, func->line_declare, func->parameter_total, func->parameter_optional, func->caller->count);

			if(func->entry == NULL) {
				O0::printf (", declare=0");
			} else {
				O0::printf (", declare=1");
			}

			if(func->visible == true) {
				O0::printf (", export=1");
			} else {
				O0::printf (", export=0");
			}

			O0::print ("\n");
		}
	}
}


