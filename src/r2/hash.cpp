/*
	$ [KiPHP] /r2/hash.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			2

#include "../kiviuq.h"




/* 哈希算法 */
unsigned int r2_hash::handler_index (const char *buffer, unsigned int length, unsigned int max) {
	// 最大哈希字节
	if(length < max) {
		max	= length;
	}

	// 哈希值
	int	value	= 0;

	for(unsigned int i = 0; i < max; i ++) {
		if(buffer [i] != '\0') {
			value	+= tolower ((int) buffer [i]);
		}
	}

	return (unsigned int) value;
}




/* 哈希函数 */

unsigned int r2_hash::handler_index_short (STR1 *p) {
	return r2_hash::handler_index_short ((const STR1 *) p);
}


unsigned int r2_hash::handler_index_long (STR1 *p) {
	return r2_hash::handler_index_long ((const STR1 *) p);
}




/* 哈希函数 (const) */

unsigned int r2_hash::handler_index_short (const STR1 *p) {
	return r2_hash::handler_index (p->pointer ( ), p->length ( ), r2_hash::max_short);
}


unsigned int r2_hash::handler_index_long (const STR1 *p) {
	return r2_hash::handler_index (p->pointer ( ), p->length ( ), r2_hash::max_long);
}




/* 键比较函数 */

bool r2_hash::handler_compare_sensitive (STR1 *p1, STR1 *p2) {
	return r2_hash::handler_compare_sensitive ((const STR1 *) p1, (const STR1 *) p2);
}


bool r2_hash::handler_compare_insensitive (STR1 *p1, STR1 *p2) {
	return r2_hash::handler_compare_insensitive ((const STR1 *) p1, (const STR1 *) p2);
}




/* 键比较函数 (const) */

bool r2_hash::handler_compare_sensitive (const STR1 *p1, const STR1 *p2) {
	return (* p1) == p2;
}


bool r2_hash::handler_compare_insensitive (const STR1 *p1, const STR1 *p2) {
	if(stricmp (p1->pointer ( ), p2->pointer ( )) == 0) {
		return true;
	} else {
		return false;
	}
}




/* 哈希创建 */
STR1 * r2_hash::handler_build (STR1 *p) {
	return new STR1 (p);
}




/* 哈希清理 */
void r2_hash::handler_delete (STR1 *p) {
	delete p;
}


