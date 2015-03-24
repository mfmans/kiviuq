/*
	$ [KiPHP] /r4/constring.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			4

#include "../kiviuq.h"




/* 常量表 */
SGL1<STR1 *, r2_hash::size_big, r2_hash::handler_build, r2_hash::handler_index_long, r2_hash::handler_compare_sensitive, r2_hash::handler_delete> *		r4_constring::table	= NULL;




KI_LOADER_BOOT (r4_constring) {
	r4_constring::table	= new SGL1<STR1 *, r2_hash::size_big, r2_hash::handler_build, r2_hash::handler_index_long, r2_hash::handler_compare_sensitive, r2_hash::handler_delete>;
}


KI_LOADER_SHUTDOWN (r4_constring) {
	delete r4_constring::table;
}




/* 获取字符串常量 */

STR1 * r4_constring::build (const char *p) {
	// 创建临时字符串
	STR1	data	("%s", p);

	return r4_constring::build (& data);
}


STR1 * r4_constring::build (const STR1 *p) {
	return r4_constring::table->fetch ((STR1 *) p);
}


