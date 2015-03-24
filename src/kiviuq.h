/*
	$ [KiPHP] /kiviuq.h  (1406)    (C) 2005-2014  MF
*/


#ifndef _KIVIUQ_H_
#define _KIVIUQ_H_



/* 编译器 */
#ifdef _MSC_VER
	#pragma warning (disable: 4003)
	#pragma warning (disable: 4129)
	#pragma warning (disable: 4996)

	#define _KI_MSC_
#endif


/* 编译环境 */
#ifdef __cplusplus
	#define _KI_CPP_
#endif


/* 编译目标平台 */
#ifdef _KI_MSC_
	#ifdef _WIN64
		#define _KI_X64_
	#endif
#else
	#ifdef __SIZEOF_POINTER__
		#if __SIZEOF_POINTER__ > 4
			#define _KI_X64_
		#endif
	#endif
#endif




/* 编译必需 C++ 环境 */
#ifndef _KI_CPP_
	#error 不支持当前的编译环境 (ANSI C)
#endif


/* 编译必需 32 位平台 */
#ifdef _KI_X64_
	#error 不支持当前的编译目标平台 (x64)
#endif




/* UNICODE */

#ifdef UNICODE
	#undef UNICODE
#endif

#ifdef _UNICODE
	#undef _UNICODE
#endif




/* 检测文件是否设定所处在的权限环 */
#ifndef KI_RING
	#error 文件没有设定所处在的权限环
#endif




#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>


#include "rx/helper.h"
#include "rx/licence.h"

#include "rx/r0.h"						// R0 : 内核				core
#include "rx/r1.h"						// R1 : 通用数据结构		general data structure
#include "rx/r2.h"						// R2 : 内部数据结构		internal data structure
#include "rx/r3.h"						// R3 : 配置				configuration
#include "rx/r4.h"						// R4 : 组织				organization
#include "rx/r5.h"						// R5 : 生成器			generator
#include "rx/rx.h"						// Rx : 构造析构			con/destructor




#endif