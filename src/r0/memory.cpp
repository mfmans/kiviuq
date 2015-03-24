/*
	$ [KiPHP] /r0/memory.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			0

#include "../kiviuq.h"




/* 分配大小 */
unsigned int	r0_memory::size_total		= 0;				// 累积分配大小
unsigned int	r0_memory::size_peak		= 0;				// 分配峰值大小
unsigned int	r0_memory::size_current		= 0;				// 当前分配大小

/* 调用次数 */
unsigned int	r0_memory::call_allocate	= 0;				// 分配调用次数
unsigned int	r0_memory::call_reallocate	= 0;				// 重分配调用次数
unsigned int	r0_memory::call_release		= 0;				// 释放调用次数




/* 克隆内存块 */
void * r0_memory::clone (void *p) {
	// 目标地址
	void *	target	= NULL;

	if(p == NULL) {
		return target;
	}

	KI_EXCEPTION_BEGIN ( );

	// 内存大小
	size_t	size	= (size_t) *((unsigned int *) p - 1);

	// 分配内存
	target	= r0_memory::allocate ((size_t) size);

	// 执行内存拷贝
	r0_memory::copy (target, p, size);

	KI_EXCEPTION_END ("尝试对无效的内存块创建副本。");

	return target;
}




/* 分配内存 */
void * r0_memory::allocate (size_t size) {
	// 0 字节保护
	if(size == 0) {
		size	= 1;
	}

	// 实际分配大小
	unsigned int	byte	= (unsigned int) size + sizeof (unsigned int);

	// 分配内存
	unsigned int *	p		= (unsigned int *) malloc (byte);

	// 检测是否分配成功
	if(p == NULL) {
		O0::runtime ("申请分配内存失败。");
	}

	// 向内存块写入大小信息
	* p	= (unsigned int) size;

	// 更新分配大小
	r0_memory::size_total	+= byte;
	r0_memory::size_current	+= byte;

	// 更新分配峰值
	if(r0_memory::size_peak < r0_memory::size_current) {
		r0_memory::size_peak	= r0_memory::size_current;
	}

	// 更新调用次数
	r0_memory::call_allocate ++;

	return p + 1;
}


/* 重分配内存 */
void * r0_memory::reallocate (void *p, size_t size) {
	// 更新调用次数
	r0_memory::call_reallocate ++;

	// 空指针保护
	if(p == NULL) {
		return r0_memory::allocate (size);
	}

	KI_EXCEPTION_BEGIN ( );

	// 获取已分配大小
	unsigned int	size_real	= * (((unsigned int *) p) - 1);

	// 判断已分配大小是否大于请求大小
	if(size_real >= size) {
		return p;
	}

	// 分配新内存
	void *	p_new	= r0_memory::allocate (size);

	// 拷贝内存
	r0_memory::copy (p_new, p, size_real);

	// 释放老内存
	r0_memory::release (p);

	return p_new;

	KI_EXCEPTION_END ("尝试重新分配无效的内存块。");

	return NULL;
}


/* 释放内存 */
void r0_memory::release (void *p) {
	// 空指针保护
	if(p == NULL) {
		return;
	}

	// 实际分配大小
	unsigned int	size	= 0;

	// 实际地址
	p	= ((unsigned int *) p) - 1;

	KI_EXCEPTION_BEGIN ( );

	// 获取实际分配大小
	size	= *((unsigned int *) p) + sizeof (unsigned int);

	// 释放内存
	free (p);

	KI_EXCEPTION_END ("尝试释放无效的内存块。");

	// 更新分配大小
	r0_memory::size_current	-= size;

	// 更新调用次数
	r0_memory::call_release	++;
}




/* 复制内存 */
void * r0_memory::copy (void *target, const void *source, unsigned int size) {
	KI_EXCEPTION_BEGIN ( );

	memcpy (target, source, (size_t) size);

	KI_EXCEPTION_END ("尝试复制无效的内存块。");

	return target;
}




/* 内存填充 */

void * r0_memory::fill (void *p, int value) {
	KI_EXCEPTION_BEGIN ( );

	// 获取内存大小
	unsigned int	size	= *((unsigned int *) p - 1);

	// 清零
	memset (p, value, (size_t) size);

	KI_EXCEPTION_END ("尝试填充无效的内存块。");

	return p;
}


void * r0_memory::fill (void *p, unsigned int size, int value) {
	KI_EXCEPTION_BEGIN ( );

	// 清零
	memset (p, value, (size_t) size);

	KI_EXCEPTION_END ("尝试填充无效的内存块。");

	return p;
}




/* 内存清零 */

void * r0_memory::zero (void *p) {
	return r0_memory::fill (p, 0);
}


void * r0_memory::zero (void *p, unsigned int size) {
	return r0_memory::fill (p, size, 0);
}


