/*
	$ [KiPHP] /rx/r0.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 0

#ifndef _R0_H_
#define _R0_H_



#define LDR0	r0_loader
#define O0		r0_io
#define M0		r0_memory





/* 加载器 */
class r0_loader {
	private:
		/* 函数表大小 */
		static	const	unsigned int	size	= 32;

		/* 函数表 */
		static	void	(* handler_boot		[r0_loader::size])	(int, char **);
		static	void	(* handler_shutdown	[r0_loader::size])	(void);

		/* 注册函数数量 */
		static	unsigned int	count;


	public:
		/* 挂载新的函数 */
		static	void	mount		(void (* boot)(int, char **), void (* shutdown)(void));


		/* 启动 */
		static	void	boot		(int argc, char *argv[]);
		/* 结束 */
		static	void	shutdown	(void);


		/* 终止进程 */
		static	void	die			(int code = 0);
};




/* 输出 */
class r0_io {
	KI_LOADER_DECLARE ( );


	public:
		/* 流文件 */
		static	FILE *	stream_in;								// 输入流
		static	FILE *	stream_out;								// 输出流
		static	FILE *	stream_error;							// 错误流


		/* 向输出流输出字符 */
		static	void	putchar		(const int data);
		/* 向输出流输出字符串 */
		static	void	print		(const char *data);
		static	void	printf		(const char *format, ...);

		/* 向错误流输出语法警告/错误 */
		static	void	syntax		(const char *message, unsigned int line = 0, bool fatal = false);
		/* 向错误流输出运行时错误并终止程序 */
		static	void	runtime		(const char *message);
		/* 向错误流输出参数错误并终止程序 */
		static	void	argument	(const char *format, ...);

		/* 向错误流输出记录信息 */
		static	void	log			(const char *entry, const char *format, ...);
};




/* 内存 */
class r0_memory {
	public:
		/* 分配大小 */
		static	unsigned int	size_total;						// 累积分配大小
		static	unsigned int	size_peak;						// 分配峰值大小
		static	unsigned int	size_current;					// 当前分配大小

		/* 调用次数 */
		static	unsigned int	call_allocate;					// 分配调用次数
		static	unsigned int	call_reallocate;				// 重分配调用次数
		static	unsigned int	call_release;					// 释放调用次数


		/* 克隆内存块 */
		static	void *	clone		(void *p);

		/* 分配内存 */
		static	void *	allocate	(size_t size);
		/* 重分配内存 */
		static	void *	reallocate	(void *p, size_t size);
		/* 释放内存 */
		static	void	release		(void *p);

		/* 复制内存 */
		static	void *	copy	(void *target, const void *source, unsigned int size);

		/* 内存填充 */
		static	void *	fill	(void *p, int value);
		static	void *	fill	(void *p, unsigned int size, int value);

		/* 内存清零 */
		static	void *	zero	(void *p);
		static	void *	zero	(void *p, unsigned int size);
};





/* 重载 new */
inline	void *	operator new	(size_t size)				{	return				M0::allocate (size);									}
inline	void *	operator new	(size_t size, bool dummy)	{	return	M0::fill (	M0::allocate (size),	(unsigned int) size,	0);		}

/* 重载 delete */
inline	void	operator delete	(void *p)					{	M0::release (p);	}
inline	void	operator delete	(void *p, bool dummy)		{	M0::release (p);	}


/* placement new */
inline	void *	operator new	(size_t size, void *p)		{	return p;	}
inline	void	operator delete	(void *p1, void *p2)		{				}




/* 带内存清空的 new 运算符 */
#define newz	new (true)

/* placement new */
#define recall	new (this)




#endif

#endif