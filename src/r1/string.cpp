/*
	$ [KiPHP] /r1/string.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			1

#include "../kiviuq.h"



/* 缓冲区块大小 */
#define BLOCK			0x20				// 32 Byte




/* 创建空字符串 */
r1_string::r1_string (void) {
	// 分配缓冲区
	this->buffer	= new char [BLOCK];

	// 初始化使用记录
	this->size_used			= 0;
	this->size_available	= BLOCK;

	// 设置结尾的 \0
	this->buffer [0]	= '\0';
}


/* 克隆字符串 */
r1_string::r1_string (const r1_string *p) {
	// 创建缓冲区副本
	this->buffer	= (char *) M0::clone (p->buffer);

	// 复制使用记录
	this->size_used			= p->size_used;
	this->size_available	= p->size_available;
}


/* 格式化创建字符串 */
r1_string::r1_string (const char *format, ...) {
	// 创建空字符串
	recall r1_string ( );

	KI_VARG_BEGIN (format);

	// 执行连接
	this->concat (0, format, ap);

	KI_VARG_END ( );
}


/* 格式指针创建字符串 */
r1_string::r1_string (int dummy, const char *format, va_list ap) {
	// 创建空字符串
	recall r1_string ( );

	// 执行连接
	this->concat (dummy, format, ap);
}




r1_string::~r1_string (void) {
	delete [] this->buffer;
}




/* 比较字符串 */

bool r1_string::operator == (const r1_string &p) const {
	return r1_string::operator== (& p);
}


bool r1_string::operator == (const r1_string *p) const {
	if(p->size_used == this->size_used) {
		if(memcmp (p->buffer, this->buffer, this->size_used) == 0) {
			return true;
		}
	}

	return false;
}


bool r1_string::operator == (const char *p) const {
	unsigned int	length	= strlen (p);

	if(length == this->size_used) {
		if(memcmp (p, this->buffer, length) == 0) {
			return true;
		}
	}

	return false;
}




/* 连接字符串 */

void r1_string::operator += (const r1_string &p) {
	this->concat (& p);
}


void r1_string::operator += (const r1_string *p) {
	this->concat (p);
}


void r1_string::operator += (const char *p) {
	this->concat ("%s", p);
}




/* 字符串长度 */
unsigned int r1_string::length (void) const {
	return this->size_used;
}


/* 字符串缓冲区 */
const char * r1_string::pointer (void) const {
	return this->buffer;
}




/* 连接字符串 */

void r1_string::concat (const r1_string *p) {
	this->append (p->buffer, p->size_used);
}


void r1_string::concat (const char *format, ...) {
	KI_VARG_BEGIN (format);

	this->concat (0, format, ap);

	KI_VARG_END ( );
}


void r1_string::concat (int dummy, const char *format, va_list ap) {
	// 计算生成长度
	unsigned int	length	= vsnprintf (NULL, 0, format, ap);

	// 分配内存空间
	char *	buffer	= newz char [length + 4];

	// 生成字符串
	vsprintf (buffer, format, ap);

	// 执行连接操作
	this->append (buffer, length);

	// 释放临时内存空间
	delete [] buffer;
}




/* 合并缓冲区到字符串尾部 */
void r1_string::append (const void *buffer, unsigned int size) {
	// 判断是否需要重新分配空间 (保留 \0 结束)
	if(this->size_available <= size) {
		// 需要扩展的容量
		unsigned int	extend	= ((size / BLOCK) + 1) * BLOCK;

		// 重新分配内存
		this->buffer	= (char *) M0::reallocate (this->buffer, extend + this->size_used + this->size_available);

		// 更新可用容量
		this->size_available	+= extend;
	}

	// 合并内容
	M0::copy (this->buffer + this->size_used, buffer, size);

	// 更新统计信息
	this->size_used			+= size;
	this->size_available	-= size;

	// 设置结尾的 \0
	this->buffer [this->size_used]	= '\0';
}


