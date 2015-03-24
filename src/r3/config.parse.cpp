/*
	$ [KiPHP] /r3/config.parse.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			3

#include "../kiviuq.h"




/* 处理参数 */
void r3_config::parse (const char *command) {
	KI_LOOKSTR (command, strcmp) {
		// 查看帮助	-h
		KI_LOOKSTR_CASE ("-h")				r3_config::output (R3_CONFIG_OUTPUT_HELP);
		// 查看版本	-v
		KI_LOOKSTR_CASE ("-v")				r3_config::output (R3_CONFIG_OUTPUT_VERSION);
		// 查看分发	-distribution
		KI_LOOKSTR_CASE ("-distribution")	r3_config::output (R3_CONFIG_OUTPUT_DISTRIBUTION);


		// 流文件
#define	PARSE_FILE(cmd, mode, err)																\
		KI_LOOKSTR_CASE ("-" #cmd)																\
			const char *	file	= r3_config::fetch_string ( );								\
			if(file == NULL) {																	\
				O0::argument ("参数用法 : -" #cmd " {FILE}");										\
			}																					\
			FILE *	fp	= fopen (file, mode);													\
			if(fp == NULL) {																	\
				O0::argument ("无效的参数 : 无法打开指定的" err "流文件。");							\
			}																					\
			O0::stream_##cmd = fp;

		// 输入文件	-in {FILE}
		PARSE_FILE (in,		"rb",	"输入")
		// 输出文件	-out {FILE}
		PARSE_FILE (out,	"wb",	"输出")
		// 错误文件	-error {FILE}
		PARSE_FILE (error,	"wb",	"错误")
#undef	PARSE_FILE


		// 输出模式	-O[cis]
		KI_LOOKSTR_CASE ("-Oc")			C3(output)		= R3_CONFIG_OUTPUT_CODE;
		KI_LOOKSTR_CASE ("-Oi")			C3(output)		= R3_CONFIG_OUTPUT_INTERLANG;
		KI_LOOKSTR_CASE ("-Os")			C3(output)		= R3_CONFIG_OUTPUT_SYMBOL;

		// 警告模式	-W[012]
		KI_LOOKSTR_CASE ("-W0")			C3(warning)		= R3_CONFIG_WARNING_DISABLE;
		KI_LOOKSTR_CASE ("-W1")			C3(warning)		= R3_CONFIG_WARNING_NORMAL;
		KI_LOOKSTR_CASE ("-W2")			C3(warning)		= R3_CONFIG_WARNING_ERROR;


		// 噪音水平	-N {UINT}
		KI_LOOKSTR_CASE ("-N")
			// 获取级别
			if(r3_config::fetch_uint (& C3(noise)) == false) {
				O0::argument ("参数用法 : -N {UINT}");
			}

			// 判断级别是否合法
			if(C3(noise) > 100) {
				O0::argument ("无效的参数 : 噪音级别应为 0 (含) 到 100 (含) 之间的整数。");
			}


		// 输出运行记录	-log-(on|off)
		KI_LOOKSTR_CASE ("-log-on")			C3(log)		= true;
		KI_LOOKSTR_CASE ("-log-off")		C3(log)		= false;


		// 编码支持	-encode-(on|off)
		KI_LOOKSTR_CASE ("-encode-on")		C3(enable_encode)	= true;
		KI_LOOKSTR_CASE ("-encode-off")		C3(enable_encode)	= false;

		// 内联函数	-inline-(on|off)
		KI_LOOKSTR_CASE ("-inline-on")		C3(enable_inline)	= true;
		KI_LOOKSTR_CASE ("-inline-off")		C3(enable_inline)	= false;

		// 编译杂注	-pragma-(on|off)
		KI_LOOKSTR_CASE ("-pragma-on")		C3(enable_pragma)	= true;
		KI_LOOKSTR_CASE ("-pragma-off")		C3(enable_pragma)	= false;

		// 随机代码	-random-(on|off)
		KI_LOOKSTR_CASE ("-random-on")		C3(enable_random)	= true;
		KI_LOOKSTR_CASE ("-random-off")		C3(enable_random)	= false;


		// 虚拟机
#define	PARSE_VM(cmdl, cmdu, func, err)															\
		KI_LOOKSTR_CASE ("-vm-" #cmdl)															\
			const char *	name	= r3_config::func ( );										\
			if(name == NULL) {																	\
				O0::argument ("参数用法 : " err);													\
			}																					\
			r3_config::update_vm (R3_CONFIG_VM_##cmdu, name);

		// -vm-wrapper {CLS}
		PARSE_VM (wrapper,		WRAPPER,	fetch_identifier,		"-vm-wrapper {CLS}")
		// -vm-entry {FUNC}
		PARSE_VM (entry,		ENTRY,		fetch_identifier,		"-vm-entry {FUNC}")
		// -vm-heap {VAR}
		PARSE_VM (heap,			HEAP,		fetch_variable,			"-vm-heap {VAR}")
		// -vm-stack {VAR}
		PARSE_VM (stack,		STACK,		fetch_variable,			"-vm-stack {VAR}")
		// -vm-top {VAR}
		PARSE_VM (top,			TOP,		fetch_variable,			"-vm-top {VAR}")
		// -vm-bottom {VAR}
		PARSE_VM (bottom,		BOTTOM,		fetch_variable,			"-vm-bottom {VAR}")
		// -vm-exception {VAR}
		PARSE_VM (exception,	EXCEPTION,	fetch_variable,			"-vm-exception {VAR}")
		// -vm-program {VAR}
		PARSE_VM (program,		PROGRAM,	fetch_variable,			"-vm-program {VAR}")
		// -vm-return {VAR}
		PARSE_VM (return,		RETURN,		fetch_variable,			"-vm-return {VAR}")
		// -vm-middle {VAR}
		PARSE_VM (middle,		MIDDLE,		fetch_variable,			"-vm-middle {VAR}")
#undef	PARSE_VM


		// 导出全局变量	-Ev {VAR}
		KI_LOOKSTR_CASE ("-Ev")
			const char *	name	= r3_config::fetch_variable ( );

			if(name == NULL) {
				O0::argument ("参数用法 : -Ev {VAR}");
			}

			r3_config::update_export (C3(export_variable), name);

		// 导出函数	-Ef {FUNC}
		KI_LOOKSTR_CASE ("-Ef")
			const char *	name	= r3_config::fetch_identifier ( );

			if(name == NULL) {
				O0::argument ("参数用法 : -Ef {FUNC}");
			}

			r3_config::update_export (C3(export_function), name);


		// 无法解析
		KI_LOOKSTR_DEFAULT ( )
			O0::argument ("无法识别的参数 : %s", command);
	}
}


