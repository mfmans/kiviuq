/*
	$ [KiPHP] /r1/linkedlist.hpp  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 1

#ifndef _R1_LINKEDLIST_H_
#define _R1_LINKEDLIST_H_



#define __TEMPLATE__	template <class T, void (* Cd)(T)>
#define __CLASS__		r1_linkedlist<T, Cd>




/* 创建空链表 */
__TEMPLATE__ __CLASS__::r1_linkedlist (void) {
	// 初始化节点指针
	this->head	= NULL;
	this->tail	= NULL;
	this->seek	= NULL;

	// 初始化节点数量
	this->count	= 0;
}


/* 克隆链表 */
__TEMPLATE__ __CLASS__::r1_linkedlist (const void *p) {
	// 创建链表
	recall r1_linkedlist ( );

	// 连接链表
	this->concat (p);
}




__TEMPLATE__ __CLASS__::~r1_linkedlist (void) {
	r1_node<T> *	node	= this->head;

	// 遍历删除节点
	while(node != NULL) {
		r1_node<T> *	next	= node->next;

		// 垃圾清理
		if(Cd != NULL) {
			Cd (node->data);
		}

		// 销毁节点
		delete node;

		node	= next;
	}
}




/* 向链尾插入元素 */
__TEMPLATE__ void __CLASS__::operator += (T data) {
	this->append (data);
}


/* 获取元素 */
__TEMPLATE__ T __CLASS__::operator [] (signed int offset) const {
	return this->at (offset);
}




/* 移动遍历指针 */

__TEMPLATE__ void __CLASS__::operator ++ (int dummy) {
	if(this->seek != NULL) {
		this->seek	= this->seek->next;
	}
}


__TEMPLATE__ void __CLASS__::operator -- (int dummy) {
	// 判断是否从遍历结束向前移动
	if(this->seek == NULL) {
		this->seek	= this->tail;

		return;
	}

	// 判断是否移动到了链头
	if(this->seek == this->head) {
		return;
	}

	this->seek	= this->seek->prev;
}




/* 获取元素 */
__TEMPLATE__ T __CLASS__::at (signed int offset) const {
	// 查找的节点
	r1_node<T> *	node	= NULL;

	// 根据不同方向查找节点
	if(offset < 0) {
		// 从尾部开始查找
		node	= this->tail;

		// 倒序查找
		while((++ offset) < 0) {
			if(node == NULL) {
				break;
			}

			node	= node->prev;
		}
	} else {
		// 从头部开始查找
		node	= this->head;

		// 正序查找
		while((offset --) > 0) {
			if(node == NULL) {
				break;
			}

			node	= node->next;
		}
	}

	// 判断是否查找成功
	if(node == NULL) {
		O0::runtime ("尝试通过无效下标访问链表。");
	}

	return node->data;
}




/* 在当前元素前后插入元素 */
__TEMPLATE__ void __CLASS__::insert (T data, bool after = true) {
	// 判断链表是否为空
	if(this->head == NULL) {
		// 在尾部直接插入
		this->append (data);

		return;
	}

	r1_node<T> *	node	= new r1_node<T>;

	node->data	= data;

	// 插入目标
	r1_node<T> *	target	= this->seek;

	// 判断是否遍历结束
	if(this->seek == NULL) {
		target	= this->tail;
	}

	// 判断插入方向
	if(after == true) {
		// 判断插入目标是否为最后一个节点
		if(target->next == NULL) {
			// 更新尾节点
			this->tail	= node;
		} else {
			target->next->prev	= node;
		}

		node->prev	= target;
		node->next	= target->next;

		target->next	= node;
	} else {
		// 判断插入目标是否为第一个节点
		if(target->prev == NULL) {
			// 更新头结点
			this->head	= node;
		} else {
			target->prev->next	= node;
		}

		node->prev	= target->prev;
		node->next	= target;

		target->prev	= node;
	}

	// 更新遍历指针指向新插入的节点
	this->seek	= node;
}


/* 向链尾插入元素 */
__TEMPLATE__ void __CLASS__::append (T data) {
	r1_node<T> *	node	= new r1_node<T>;

	node->data	= data;
	node->prev	= this->tail;
	node->next	= NULL;

	if(this->tail != NULL) {
		this->tail->next	= node;
	}

	// 如果是第一个元素, 更新链头
	if(this->head == NULL) {
		this->head	= node;
	}

	// 更新链尾
	this->tail	= node;
	// 更新遍历指针
	this->seek	= node;

	this->count	++;
}




/* 连接另一个链表 */
__TEMPLATE__ void __CLASS__::concat (const void *p) {
	// 源链表
	r1_linkedlist<T, Cd> *	list	= (r1_linkedlist<T, Cd> *) p;

	// 源链表头结点
	r1_node<T> *	node	= list->head;

	// 遍历拷贝节点
	while(node != NULL) {
		this->append (node->data);

		node	= node->next;
	}
}




/* 遍历预备 */
__TEMPLATE__ bool __CLASS__::ready (void) {
	// 判断是否有元素
	if(this->count == 0) {
		return false;
	}

	// 更新寻址指针
	this->seek	= this->head;

	return true;
}


/* 获取当前遍历元素 */
__TEMPLATE__ bool __CLASS__::fetch (T *p) {
	// 判断是否遍历结束
	if(this->seek == NULL) {
		return false;
	}

	// 返回数据
	* p	= this->seek->data;

	// 更新遍历指针
	this->seek	= this->seek->next;

	return true;
}




#undef __CLASS__
#undef __TEMPLATE__



#endif

#endif