/*
	$ [KiPHP] /rx/r1.h  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 1

#ifndef _R1_H_
#define _R1_H_



#define STR1	r1_string
#define LST1	r1_linkedlist
#define STK1	r1_stack
#define TBL1	r1_hashtable
#define SGL1	r1_singleton





/* 字符串 */
class r1_string {
	private:
		/* 缓冲区 */
		char *	buffer;

		/* 长度 */
		unsigned int	size_used;
		/* 剩余容量 */
		unsigned int	size_available;


	public:
		/* 创建字符串 */
		r1_string	(void);												// 创建空字符串
		r1_string	(const r1_string *p);								// 克隆字符串
		r1_string	(const char *format, ...);							// 格式化创建字符串
		r1_string	(int dummy, const char *format, va_list ap);		// 格式指针创建字符串

		~r1_string	(void);


		/* 比较字符串 */
		bool	operator ==		(const r1_string &p)	const;
		bool	operator ==		(const r1_string *p)	const;
		bool	operator ==		(const char *p)			const;

		/* 连接字符串 */
		void	operator +=		(const r1_string &p);
		void	operator +=		(const r1_string *p);
		void	operator +=		(const char *p);


		/* 字符串长度 */
		unsigned int	length	(void)	const;

		/* 字符串缓冲区 */
		const char *	pointer	(void)	const;

		/* 连接字符串 */
		void	concat	(const r1_string *p);
		void	concat	(const char *format, ...);
		void	concat	(int dummy, const char *format, va_list ap);

		/* 合并缓冲区到字符串尾部 */
		void	append	(const void *buffer, unsigned int size);
};




/* 节点 */
template <typename T> struct r1_node {
	T	data;

	r1_node *		next;
	r1_node *		prev;
};


/* 双链表节点 */
template <typename T> struct r1_node_duo {
	/* 值 */
	T	value;
	/* 键 */
	r1_string *	key;

	r1_node_duo *	next1;
	r1_node_duo *	next2;
};




/* 链表 */
template <class T, void (* Cd)(T) = NULL>
class r1_linkedlist {
	private:
		/* 节点指针 */
		r1_node<T> *	head;						// 链头
		r1_node<T> *	tail;						// 链尾
		r1_node<T> *	seek;						// 遍历


	public:
		/* 节点数量 */
		unsigned int	count;


		/* 创建链表 */
		r1_linkedlist	(void);						// 创建空链表
		r1_linkedlist	(const void *p);			// 克隆链表

		~r1_linkedlist	(void);


		/* 向链尾插入元素 */
		void	operator +=		(T data);

		/* 获取元素 */
		T		operator []		(signed int offset)		const;

		/* 移动遍历指针 */
		void	operator ++		(int dummy);
		void	operator --		(int dummy);


		/* 获取元素 */
		T		at		(signed int offset)		const;

		/* 在当前元素前后插入元素 */
		void	insert	(T data, bool after = true);
		/* 向链尾插入元素 */
		void	append	(T data);

		/* 连接另一个链表 */
		void	concat	(const void *p);

		/* 遍历预备 */
		bool	ready	(void);
		/* 获取当前遍历元素 */
		bool	fetch	(T *p);
};




/* 栈 */
template <class T, void (* Cd)(T) = NULL>
class r1_stack {
	private:
		/* 栈顶指针 */
		r1_node<T> *	top;

		/* 元素数量 */
		unsigned int	count;


	public:
		r1_stack	(void);

		~r1_stack	(void);

		/* 压栈 */
		void	operator +=		(T data);
		/* 退栈 */
		void	operator --		(int dummy);

		/* 栈顶 */
		T		operator []		(unsigned int offset)	const;


		/* 压栈 */
		void	push	(T data);
		/* 退栈 */
		void	pop		(void);

		/* 栈顶 */
		T		peek	(unsigned int offset = 0)	const;

		/* 将元素冒泡到栈顶 */
		void	bubble	(unsigned int offset);

		/* 判断是否栈空 */
		bool	empty	(void)		const;
};




/* 哈希表 */
template
	<
		class			T,
		unsigned int	S,												// 哈希表大小
		T				D,												// 默认数据
		unsigned int	(* Ci)(const STR1 *),							// 哈希函数
		bool			(* Cc)(const STR1 *, const STR1 *),				// 键比较函数
		void			(* Cd)(T) = NULL								// 垃圾清理函数
	>
class r1_hashtable {
	private:
		/* 映射表 */
		r1_node_duo<T> *	table	[S + 1];

		/* 节点指针 */
		r1_node_duo<T> *	head;
		r1_node_duo<T> *	tail;
		r1_node_duo<T> *	seek;


		/* 获取元素 */
		T *		at		(const STR1 *p, bool created = true);


	public:
		/* 节点数量 */
		unsigned int	count;


		r1_hashtable	(void);

		~r1_hashtable	(void);


		/* 读取元素 */
		T		operator []		(const STR1 &p);
		T		operator []		(const STR1 *p);
		T		operator []		(const char *p);


		/* 读取元素 */
		T		read	(const STR1 &p);
		T		read	(const STR1 *p);
		T		read	(const char *p);

		/* 写入数据 */
		void	write	(const STR1 &p, T data);
		void	write	(const STR1 *p, T data);
		void	write	(const char *p, T data);


		/* 检测元素是否存在 */
		bool	exist	(const STR1 &p);
		bool	exist	(const STR1 *p);
		bool	exist	(const char *p);


		/* 遍历预备 */
		bool	ready	(void);
		/* 获取当前遍历元素 */
		bool	fetch	(T *p1, const STR1 **p2 = NULL);
};




/* 单例容器 */
template
	<
		class			T,
		unsigned int	S,												// 哈希表大小
		T				(* Cb)(T),										// 副本创建函数
		unsigned int	(* Ci)(T),										// 哈希函数
		bool			(* Cc)(T, T),									// 值比较函数
		void			(* Cd)(T) = NULL								// 垃圾清理函数
	>
class r1_singleton {
	private:
		/* 映射表 */
		r1_node<T> *	table	[S + 1];


	public:
		/* 节点数量 */
		unsigned int	count;


		r1_singleton	(void);

		~r1_singleton	(void);


		/* 获取元素 */
		T		fetch	(T data);
};





#include "../r1/linkedlist.hpp"
#include "../r1/stack.hpp"
#include "../r1/hashtable.hpp"
#include "../r1/singleton.hpp"




#endif

#endif