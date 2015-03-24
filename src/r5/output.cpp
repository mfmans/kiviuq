/*
	$ [KiPHP] /r5/output.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			5

#include "../kiviuq.h"




/* 运行记录 */
void r5_output::log (void) {
	O0::log ("code.line",				"%u",	RCD4::line			);
	O0::log ("code.byte",				"%u",	RCD4::byte			);

	O0::log ("memory.call.allocate",	"%u",	M0::call_allocate	);
	O0::log ("memory.call.reallocate",	"%u",	M0::call_reallocate	);
	O0::log ("memory.call.release",		"%u",	M0::call_release	);
	O0::log ("memory.size.total",		"%u",	M0::size_total		);
	O0::log ("memory.size.peak",		"%u",	M0::size_peak		);
	O0::log ("memory.size.current",		"%u",	M0::size_current	);

	// 输出全局变量导出表
	if(C3(export_variable)->ready ( ) == true) {
		STR1 *	name;

		while(C3(export_variable)->fetch (& name) == true) {
			O0::log ("config.export.variable", "%s", name->pointer ( ));
		}
	}

	// 输出函数导出表
	if(C3(export_function)->ready ( ) == true) {
		STR1 *	name;

		while(C3(export_function)->fetch (& name) == true) {
			O0::log ("config.export.function", "%s", name->pointer ( ));
		}
	}

	O0::log ("config.output",		"%d",			C3(output)			);
	O0::log ("config.warning",		"%d",			C3(warning)			);
	O0::log ("config.noise",		"%u",			C3(noise)			);
	O0::log ("config.log",			"%d",	(int)	C3(log)				);
	O0::log ("config.encode",		"%d",	(int)	C3(enable_encode)	);
	O0::log ("config.inline",		"%d",	(int)	C3(enable_inline)	);
	O0::log ("config.pragma",		"%d",	(int)	C3(enable_pragma)	);
	O0::log ("config.random",		"%d",	(int)	C3(enable_random)	);
	
	O0::log ("config.vm.wrapper",	"%s",			C3(vm_wrapper)		->pointer ( )	);
	O0::log ("config.vm.entry",		"%s",			C3(vm_entry)		->pointer ( )	);
	O0::log ("config.vm.heap",		"%s",			C3(vm_heap)			->pointer ( )	);
	O0::log ("config.vm.stack",		"%s",			C3(vm_stack)		->pointer ( )	);
	O0::log ("config.vm.top",		"%s",			C3(vm_top)			->pointer ( )	);
	O0::log ("config.vm.bottom",	"%s",			C3(vm_bottom)		->pointer ( )	);
	O0::log ("config.vm.exception",	"%s",			C3(vm_exception)	->pointer ( )	);
	O0::log ("config.vm.program",	"%s",			C3(vm_program)		->pointer ( )	);
	O0::log ("config.vm.return",	"%s",			C3(vm_return)		->pointer ( )	);
	O0::log ("config.vm.middle",	"%s",			C3(vm_middle)		->pointer ( )	);
}




/* 执行输出 */
void r5_output::execute (void) {
	r5_output_handler *	handler;

	// 创建输出
	switch(C3(output)) {
		case R3_CONFIG_OUTPUT_CODE:			handler	= new r5_output_handler_code		( );	break;
		case R3_CONFIG_OUTPUT_INTERLANG:	handler	= new r5_output_handler_interlang	( );	break;
		case R3_CONFIG_OUTPUT_SYMBOL:		handler	= new r5_output_handler_symbol		( );	break;

		default:
			return;
	}

	// 执行输出
	handler->execute ( );

	// 输出运行记录
	if(C3(log) == true) {
		r5_output::log ( );
	}

	delete handler;
}




/* 序列化代码 */
void r5_output::serialize (LST1<r2_code_t, r2_class::handler_delete_code> *p) {
	if(p->ready ( ) == true) {
		r2_code_t		code;

		unsigned int	id		= 0;

		while(p->fetch (& code) == true) {
			if(code->type == R2_CD_LABEL) {
				code->v._label.id	= id ++;
			}
		}
	}
}


