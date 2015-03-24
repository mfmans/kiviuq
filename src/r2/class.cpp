/*
	$ [KiPHP] /r2/class.cpp  (1406)    (C) 2005-2014  MF
*/


#define KI_RING			2

#include "../kiviuq.h"




void r2_class::handler_delete_const (r2_class_const_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;
	delete p;
}


void r2_class::handler_delete_property (r2_class_property_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;
	delete p;
}


void r2_class::handler_delete_method (r2_class_method_t p) {
	if(p == NULL) {
		return;
	}

	delete p->name;
	delete p->caller;

	delete p;
}


void r2_class::handler_delete_code (r2_code_t p) {
	if(p == NULL) {
		return;
	}

	if(p->type == R2_CD_LABEL) {
		delete p->v._label.operand;
	}

	delete p;
}




/* 更新属性特性 */
void r2_class_property::feature (r2_class_feature_t p) {
	this->access	= p->access;

	this->_final	= p->_final;
	this->_abstract	= p->_abstract;
	this->_static	= p->_static;
}


/* 更新方法特性 */
void r2_class_method::feature (r2_class_feature_t p) {
	this->access	= p->access;

	this->_final	= p->_final;
	this->_abstract	= p->_abstract;
	this->_static	= p->_static;
}


