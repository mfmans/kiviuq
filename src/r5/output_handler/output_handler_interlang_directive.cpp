/*
	$ [KiPHP] /r5/output/output.interlang_directive.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../../kiviuq.h"




const char * r5_output_handler_interlang::fetch (r2_code_directive_opcode_e opcode) {
	switch(opcode) {
		case R2_CD_OPC_SLTON:		return "slton";
		case R2_CD_OPC_SLTOFF:		return "sltoff";

		case R2_CD_OPC_MOV:			return "mov";
		case R2_CD_OPC_MOVH:		return "movh";
		case R2_CD_OPC_MOVA:		return "mova";

		case R2_CD_OPC_THIS:		return "this";

		case R2_CD_OPC_PUSH:		return "push";
		case R2_CD_OPC_PUSHR:		return "pushr";

		case R2_CD_OPC_POP:			return "pop";
		case R2_CD_OPC_POPR:		return "popr";
		case R2_CD_OPC_POPA:		return "popa";

		case R2_CD_OPC_REF:			return "ref";
												
		case R2_CD_OPC_VAL:			return "val";
		case R2_CD_OPC_ASG:			return "asg";
		case R2_CD_OPC_ASGE:		return "asge";
		case R2_CD_OPC_SHK:			return "shk";
		case R2_CD_OPC_SHP:			return "shp";
	
		case R2_CD_OPC_ADD:			return "add";
		case R2_CD_OPC_SUB:			return "sub";
		case R2_CD_OPC_MUL:			return "mul";
		case R2_CD_OPC_DIV:			return "div";
		case R2_CD_OPC_MOD:			return "mod";
		case R2_CD_OPC_CAT:			return "cat";
		case R2_CD_OPC_AND:			return "and";
		case R2_CD_OPC_OR:			return "or";
		case R2_CD_OPC_XOR:			return "xor";
		case R2_CD_OPC_SHL:			return "shl";
		case R2_CD_OPC_SHR:			return "shr";

		case R2_CD_OPC_NOT:			return "not";
		case R2_CD_OPC_NEG:			return "neg";
		case R2_CD_OPC_OPP:			return "opp";
	
		case R2_CD_OPC_CMPE:		return "cmpe";
		case R2_CD_OPC_CMPNE:		return "cmpne";
		case R2_CD_OPC_CMPI:		return "cmpi";
		case R2_CD_OPC_CMPNI:		return "cmpni";
		case R2_CD_OPC_CMPG:		return "cmpg";
		case R2_CD_OPC_CMPGE:		return "cmpge";
		case R2_CD_OPC_CMPS:		return "cmps";
		case R2_CD_OPC_CMPSE:		return "cmpse";
		case R2_CD_OPC_INSTOF:		return "instof";

		case R2_CD_OPC_JMP:			return "jmp";
		case R2_CD_OPC_JMPT:		return "jmpt";
		case R2_CD_OPC_JMPF:		return "jmpf";

		case R2_CD_OPC_CALL:		return "call";
		case R2_CD_OPC_RET:			return "ret";
		case R2_CD_OPC_RETN:		return "retn";
	
		case R2_CD_OPC_ARRAY:		return "array";

		case R2_CD_OPC_NEW:			return "new";

		case R2_CD_OPC_ISSET:		return "isset";
		case R2_CD_OPC_UNSET:		return "unset";
		case R2_CD_OPC_UNSETK:		return "unsetk";

		case R2_CD_OPC_EVAL:		return "eval";
		case R2_CD_OPC_ECHO:		return "echo";
		case R2_CD_OPC_EXIT:		return "exit";

		case R2_CD_OPC_INCL:		return "incl";
		case R2_CD_OPC_INCLO:		return "inclo";
		case R2_CD_OPC_REQU:		return "requ";
		case R2_CD_OPC_REQUO:		return "requo";
	}

	O0::runtime ("输出时遇到未知的指令。");

	return NULL;
}


