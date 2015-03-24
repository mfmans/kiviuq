/*
	$ [KiPHP] /r5/output/output.interlang.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../../kiviuq.h"




void r5_output_handler_interlang::operand (r2_code_directive_operand_t operand, const char *prefix) {
	if(operand->type == R2_CD_OPND_NULL) {
		return;
	}

	if(prefix != NULL) {
		O0::printf ("%s", prefix);
	}

	switch(operand->type) {
		case R2_CD_OPND_CONSTANT:
		case R2_CD_OPND_IDENTIFIER:
		case R2_CD_OPND_INTEGER:
		case R2_CD_OPND_FLOAT:
		case R2_CD_OPND_STRING:
			this->print_operand (operand);
			break;

		case R2_CD_OPND_LABEL:
			O0::printf (":label_%u", operand->v._label->id);
			break;

		case R2_CD_OPND_ADDRESS:
			{
				r2_code_directive_operand_address_t	address	= & operand->v._address;

				char	buffer	[16]	= {0};

				if(address->offset < 0) {
					sprintf (buffer, " - %d", - address->offset);
				} else if(address->offset > 0) {
					sprintf (buffer, " + %d",   address->offset);
				}

				switch(address->base) {
					case R2_CD_OPND_ADDRESS_DIRECT:		O0::printf ("! [%d]",			address->offset);		break;
					case R2_CD_OPND_ADDRESS_HEAP:		O0::printf ("!HEAP [%d]",		address->offset);		break;
					case R2_CD_OPND_ADDRESS_TOP:		O0::printf ("!STACK [T%s]",		buffer);				break;
					case R2_CD_OPND_ADDRESS_BOTTOM:		O0::printf ("!STACK [B%s]",		buffer);				break;
				}
			}
			break;
	}
}




void r5_output_handler_interlang::callback_begin (void) {
	O0::print ("/* {{{\n");

	this->indent ++;
}


void r5_output_handler_interlang::callback_end (void) {
	O0::print ("}}} */\n");

	this->indent --;
}


void r5_output_handler_interlang::callback_code (r2_code_t p) {
	switch(p->type) {
		case R2_CD_LABEL:
			this->indent --;

			this->print_space ( );

			O0::printf ("label_%u:\n", p->v._label.id);

			this->indent ++;

			break;

		case R2_CD_DIRECTIVE:
			{
				const char *	name	= this->fetch (p->v._directive.opcode);
				unsigned int	length	= strlen (name);

				this->print_space ( );

				O0::printf ("%s", name);

				// 输出空格对齐
				for(; length <= 8; length ++) {
					O0::print (" ");
				}

				// 输出操作数
				this->operand (& p->v._directive.operand_1,		NULL);
				this->operand (& p->v._directive.operand_2,		", ");
				this->operand (& p->v._directive.operand_3,		", ");

				O0::print ("\n");
			}

			break;
	}
}


void r5_output_handler_interlang::callback_function (r2_class_t cls, r2_code_t label) {
	O0::printf ("/* {{{ CALL : ");

	O0::printf ("%s::label_%u", cls->name->pointer ( ), label->v._label.id);

	O0::printf (" }}} */");
}


