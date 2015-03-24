/*
	$ [KiPHP] /r3/config.output.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			3

#include "../kiviuq.h"




/* 输出模式 */
void r3_config::output (r3_config_output_e mode) {
	switch(mode) {
		case R3_CONFIG_OUTPUT_HELP:
			O0::printf (
				"用法 : kiviuq [...]\n\n"

				"%s  (%s)\n\n\n"

				"输出 (启动):\n"
				"      -h                         输出本屏帮助，退出程序\n"
				"      -v                         输出版本信息，退出程序\n\n"

				"输出 (模式):\n"
				"  [1] -Oc                        输出目标代码\n"
				"  (1) -Oi                        输出中间语言\n"
				"  (1) -Os                        输出符号信息\n\n"

				"流文件:\n"
				"      -in {FILE}                 指定输入流文件，取代 STDIN\n"
				"      -out {FILE}                指定输出流文件，取代 STDOUT\n"
				"      -error {FILE}              指定错误流文件，取代 STDERR\n\n"

				"警告模式:\n"
				"  (2) -W0                        禁用警告\n"
				"  [2] -W1                        输出警告\n"
				"  (2) -W2                        输出警告并终止编译\n\n"

				"噪音水平:\n"
				"      -N {UINT}                  指定噪音代码水平，范围为 0（含） 到 100（含）\n\n"

				"运行记录:\n"
				"  (3) -log-on                    启用运行记录输出\n"
				"  [3] -log-off                   禁用运行记录输出\n\n"

				"特性支持:\n"
				"  [4] -encode-on                 启用编码支持\n"
				"  (4) -encode-off                禁用编码支持\n"
				"  (5) -inline-on                 启用内联函数\n"
				"  [5] -inline-off                禁用内联函数\n"
				"  [6] -pragma-on                 启用编译杂注\n"
				"  (6) -pragma-off                禁用编译杂注\n"
				"  (7) -random-on                 启用随机代码\n"
				"  [7] -random-off                禁用随机代码\n\n"

				"虚拟机设置:\n"
				"      -vm-wrapper {CLS}          指定封装类类名，取代 __kiviuq_wrapper\n"
				"      -vm-entry {FUNC}           指定调用入口方法名，取代 __kiviuq__\n"
				"      -vm-heap {VAR}             指定堆属性名，取代 $HEAP\n"
				"      -vm-stack {VAR}            指定栈变量名，取代 $STACK\n"
				"      -vm-top {VAR}              指定栈顶指针变量名，取代 $T\n"
				"      -vm-bottom {VAR}           指定栈底指针变量名，取代 $B\n"
				"      -vm-exception {VAR}        指定异常指针变量名，取代 $E\n"
				"      -vm-pointer {VAR}          指定程序计数器指针变量名，取代 $P\n"
				"      -vm-return {VAR}           指定返回值暂存器变量名，取代 $R\n"
				"      -vm-middle {VAR}           指定中间值暂存器变量名，取代 $M\n\n"

				"导出:\n"
				"      -Ev {VAR}                  导出全局变量\n"
				"      -Ef {FUNC}                 导出函数\n\n"

				"部分设置使用 [n] 和 (n) 进行组织，相同数字代表为互斥设置\n"
				"其中，[n] 为默认设置，(n) 为候选设置"

				, KI_LIC_NAME
				, KI_LIC_VERSION
			);

			break;


		case R3_CONFIG_OUTPUT_VERSION:
			O0::printf (
				"%s  (%s)\n"
				"%s\n\n"

				"这不是一个免费软件，使用前必须获得授权。\n\n"

				"主页 : %s"

				, KI_LIC_NAME
				, KI_LIC_VERSION
				, KI_LIC_COPYRIGHT
				, KI_LIC_HOMEPAGE
			);

			break;


		case R3_CONFIG_OUTPUT_DISTRIBUTION:
			{
				O0::printf ("D = %s\n",		__DATE__);
				O0::printf ("T = %s\n",		__TIME__);

				const char *	p	= KI_LIC_DISTRIBUTION;

				for(int i = 0; i < (sizeof (KI_LIC_DISTRIBUTION) - 1); i ++) {
					if((i % 8) == 0) {
						O0::printf ("\n");
					}

					O0::printf ("%02X ", (unsigned int) * (p ++));
				}
			}

			break;


		default:
			return;
	}

	// 退出程序
	LDR0::die ( );
}


