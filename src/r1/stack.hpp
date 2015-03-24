/*
	$ [KiPHP] /r1/stack.hpp  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 1

#ifndef _R1_STACK_H_
#define _R1_STACK_H_



#define __TEMPLATE__	template <class T, void (* Cd)(T)>
#define __CLASS__		r1_stack<T, Cd>




__TEMPLATE__ __CLASS__::r1_stack (void) {
	// 初始化元素
	this->top	= NULL;
	this->count	= 0;
}


__TEMPLATE__ __CLASS__::~r1_stack (void) {
	if(this->count == 0) {
		return;
	}

	// 遍历销毁所有节点
	while(this->top != NULL) {
		r1_node<T> *	prev	= this->top->prev;

		// 垃圾清理
		if(Cd != NULL) {
			Cd (this->top->data);
		}

		// 销毁节点
		delete this->top;

		this->top	= prev;
	}
}




/* 压栈 */
__TEMPLATE__ void __CLASS__::operator += (T data) {
	this->push (data);
}


/* 退栈 */
__TEMPLATE__ void __CLASS__::operator -- (int dummy) {
	this->pop ( );
}




/* 获取元素 */
__TEMPLATE__ T __CLASS__::operator [] (unsigned int offset) const {
	return this->peek (offset);
}




/* 压栈 */
__TEMPLATE__ void __CLASS__::push (T data) {
	r1_node<T> *	node	= new r1_node<T>;

	node->data	= data;
	node->prev	= this->top;
	node->next	= NULL;

	// 设置栈顶节点的后一个节点
	if(this->top != NULL) {
		this->top->next	= node;
	}

	// 更新栈顶节点
	this->top	= node;

	this->count	++;
}


/* 退栈 */
__TEMPLATE__ void __CLASS__::pop (void) {
	if(this->count == 0) {
		O0::runtime ("尝试对空栈执行退栈操作。");
	}

	// 栈顶节点的前一个节点
	r1_node<T> *	prev	= this->top->prev;

	// 垃圾清理
	if(Cd != NULL) {
		Cd (this->top->data);
	}

	// 销毁节点
	delete this->top;

	// 更新栈顶节点
	this->top	= prev;

	this->count	--;
}




/* 栈顶元素 */
__TEMPLATE__ T __CLASS__::peek (unsigned int offset = 0) const {
	if(this->count <= offset) {
		O0::runtime ("尝试访问超出栈范围的元素。");
	}

	// 栈顶节点
	r1_node<T> *	node	= this->top;

	// 查找指定节点
	for(unsigned int i = 0; i < offset; i ++) {
		node	= node->prev;
	}

	return node->data;
}




/* 将元素冒泡到栈顶 */
__TEMPLATE__ void __CLASS__::bubble (unsigned int offset) {
	if((offset == 0) || (this->count <= offset)) {
		O0::runtime ("尝试冒泡超出栈范围的元素。");
	}

	// 栈顶节点
	r1_node<T> *	node	= this->top;

	// 查找指定节点
	for(unsigned int i = 0; i < offset; i ++) {
		node	= node->prev;
	}

	// 设置指定节点的前一个节点 
	if(node->prev != NULL) {
		node->prev->next	= node->next;
	}

	// 设置指定节点的后一个节点
	node->next->prev	= node->prev;

	node->prev			= this->top;

	this->top->next		= node;

	this->top			= node;
}




/* 判断是否栈空 */
__TEMPLATE__ bool __CLASS__::empty (void) const {
	if(this->count == 0) {
		return true;
	} else {
		return false;
	}
}




#undef __CLASS__
#undef __TEMPLATE__



#endif

#endif