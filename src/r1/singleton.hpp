/*
	$ [KiPHP] /r1/singleton.hpp  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 1

#ifndef _R1_SINGLETON_H_
#define _R1_SINGLETON_H_



#define __TEMPLATE__	template <class T, unsigned int S, T (*Cb)(T), unsigned int (* Ci)(T), bool (* Cc)(T, T), void (* Cd)(T)>
#define __CLASS__		r1_singleton<T, S, Cb, Ci, Cc, Cd>




__TEMPLATE__ __CLASS__::r1_singleton (void) {
	// 初始化映射表
	M0::zero (& this->table, sizeof this->table);
}


__TEMPLATE__ __CLASS__::~r1_singleton (void) {
	// 遍历销毁映射表
	for(unsigned int i = 0; i <= S; i ++) {
		// 当前项指针
		r1_node<T> **	list	= r1_singleton::table + i;

		while(* list != NULL) {
			r1_node<T> *	node	= * list;

			// 下一个节点
			r1_node<T> *	next	= node->next;

			// 垃圾清理
			if(Cd != NULL) {
				Cd (node->data);
			}

			// 销毁节点
			delete node;

			* list	= next;
		}
	}
}




/* 获取元素 */
__TEMPLATE__ T __CLASS__::fetch (T data) {
	// 计算索引
	unsigned int	index	= Ci (data);

	// 索引范围保护
	index	= index % S;

	// 节点指针
	r1_node<T> *	node	= this->table [index];

	// 遍历查询
	while(node != NULL) {
		if(Cc (data, node->data) == true) {
			// 返回值
			return node->data;
		}

		node	= node->next;
	}

	// 创建节点
	node	= new r1_node<T>;

	node->data	= Cb (data);
	node->next	= this->table [index];

	// 保存到对应索引链表
	this->table [index]	= node;

	return node->data;
}




#undef __CLASS__
#undef __TEMPLATE__



#endif

#endif