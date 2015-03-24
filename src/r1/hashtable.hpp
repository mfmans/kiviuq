/*
	$ [KiPHP] /r1/hashtable.hpp  (1406)    (C) 2005-2014  MF
*/


#if KI_RING >= 1

#ifndef _R1_HASHTABLE_H_
#define _R1_HASHTABLE_H_



#define __TEMPLATE__	template <class T, unsigned int S, T D, unsigned int (* Ci)(const STR1 *), bool (* Cc)(const STR1 *, const STR1 *), void (* Cd)(T)>
#define __CLASS__		r1_hashtable<T, S, D, Ci, Cc, Cd>




__TEMPLATE__ __CLASS__::r1_hashtable (void) {
	// 初始化映射表
	M0::zero (& this->table, sizeof this->table);

	// 初始化节点指针
	this->head	= NULL;
	this->tail	= NULL;
	this->seek	= NULL;

	// 初始化节点数量
	this->count	= 0;
}


__TEMPLATE__ __CLASS__::~r1_hashtable (void) {
	if(this->count == 0) {
		return;
	}

	r1_node_duo<T> *	node	= this->head;

	// 遍历释放节点
	while(node != NULL) {
		r1_node_duo<T> *	next	= node->next2;

		// 垃圾清理
		if(Cd != NULL) {
			Cd (node->value);
		}

		// 销毁键
		delete node->key;

		// 销毁节点
		delete node;

		node	= next;
	}
}




/* 获取元素 */

__TEMPLATE__ T __CLASS__::operator [] (const STR1 &p) {
	return this->read (* p);
}


__TEMPLATE__ T __CLASS__::operator [] (const STR1 *p) {
	return this->read (p);
}


__TEMPLATE__ T __CLASS__::operator [] (const char *p) {
	return this->read (p);
}




/* 获取元素 */
__TEMPLATE__ T * __CLASS__::at (const STR1 *p, bool created = true) {
	// 计算索引
	unsigned int	index	= Ci (p);

	// 索引范围保护
	index	= index % S;

	// 节点指针
	r1_node_duo<T> *	node	= this->table [index];

	// 遍历查询
	while(node != NULL) {
		// 比较键
		if(Cc (p, node->key) == true) {
			break;
		}

		node	= node->next1;
	}

	// 判断是否找到节点
	if(node == NULL) {
		// 判断是否创建节点
		if(created == false) {
			return NULL;
		}

		// 创建节点
		node	= new r1_node_duo<T>;

		// 创建键
		node->key		= new STR1 (p);

		// 设置默认数据
		node->value		= D;

		// 设置指针
		node->next1		= this->table [index];
		node->next2		= NULL;

		// 保存到对应索引链表
		this->table [index]	= node;

		// 保存到公共链表
		if(this->head == NULL) {
			this->head	= node;
		} else {
			this->tail->next2	= node;
		}

		this->tail	= node;

		this->count ++;
	}

	return & node->value;
}




/* 读取元素 */

__TEMPLATE__ T __CLASS__::read (const STR1 &p) {
	return this->read (* p);
}


__TEMPLATE__ T __CLASS__::read (const STR1 *p) {
	return  * (this->at (p, true));
}


__TEMPLATE__ T __CLASS__::read (const char *p) {
	// 键
	STR1	key		("%s", p);

	return this->read (& key);
}




/* 写入数据 */

__TEMPLATE__ void __CLASS__::write (const STR1 &p, T data) {
	this->write (* p, data);
}


__TEMPLATE__ void __CLASS__::write (const STR1 *p, T data) {
	// 值指针
	T *		node	= this->at (p, true);

	// 垃圾清理
	if(Cd != NULL) {
		Cd (* node);
	}

	// 保存数据
	* (this->at (p, true))	= data;
}


__TEMPLATE__ void __CLASS__::write (const char *p, T data) {
	// 键
	STR1	key		("%s", p);

	this->write (& key, data);
}




/* 检测元素是否存在 */

__TEMPLATE__ bool __CLASS__::exist (const STR1 &p) {
	return this->exist (& p);
}


__TEMPLATE__ bool __CLASS__::exist (const STR1 *p) {
	if(this->at (p, false) == NULL) {
		return false;
	} else {
		return true;
	}
}


__TEMPLATE__ bool __CLASS__::exist (const char *p) {
	// 创建字符串
	STR1	key		("%s", p);

	return this->exist (& key);
}




/* 遍历预备 */
__TEMPLATE__ bool __CLASS__::ready (void) {
	if(this->count == 0) {
		return false;
	}

	this->seek	= this->head;

	return true;
}


/* 获取当前遍历元素 */
__TEMPLATE__ bool __CLASS__::fetch (T *p1, const STR1 **p2) {
	// 判断是否遍历结束
	if(this->seek == NULL) {
		return false;
	}

	// 返回值
	* p1	= this->seek->value;

	// 返回键
	if(p2 != NULL) {
		* p2	= this->seek->key;
	}

	// 更新遍历指针
	this->seek	= this->seek->next2;

	return true;
}




#undef __CLASS__
#undef __TEMPLATE__



#endif

#endif