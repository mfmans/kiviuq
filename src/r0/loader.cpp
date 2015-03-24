/*
	$ [KiPHP] /r0/loader.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			0

#include "../kiviuq.h"




/* 函数表 */
void	(* r0_loader::handler_boot		[r0_loader::size])	(int, char **)	= {NULL};
void	(* r0_loader::handler_shutdown	[r0_loader::size])	(void)			= {NULL};


/* 注册函数数量 */
unsigned int	r0_loader::count	= 0;




/* 挂载新的函数 */
void r0_loader::mount (void (* boot)(int, char **), void (* shutdown)(void)) {
	// 判断挂载数量
	if(r0_loader::count >= r0_loader::size) {
		return;
	}
	
	// 挂载
	r0_loader::handler_boot		[r0_loader::count]	= boot;
	r0_loader::handler_shutdown	[r0_loader::count]	= shutdown;

	r0_loader::count ++;
}




/* 启动 */
void r0_loader::boot (int argc, char *argv[]) {
	// 正序执行启动函数
	for(unsigned int i = 0; i < r0_loader::count; i ++) {
		r0_loader::handler_boot [i] (argc, argv);
	}
}


/* 结束 */
void r0_loader::shutdown (void) {
	// 倒序执行结束函数
	for(unsigned int i = r0_loader::count; i > 0; i --) {
		r0_loader::handler_shutdown [i - 1] ( );
	}
}




/* 终止进程 */
void r0_loader::die (int code) {
	r0_loader::shutdown ( );

	exit (code);
}


