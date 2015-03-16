#ifndef _EXPRESSIONELEMENTFACTORY_H_
#define _EXPRESSIONELEMENTFACTORY_H_

#include "ExpressionElement.h"

template <typename T, typename V>
class ExpressionElementFactory{
public:
	// Default Constructor
	ExpressionElementFactory(void) {}

	// Default Destructor
	virtual ~ExpressionElementFactory(void) {}

	// Creators
	virtual ExpressionElement <T, V> * createAdd(void) = 0;
	virtual ExpressionElement <T, V> * createSubtract(void) = 0;
	virtual ExpressionElement <T, V> * createMultiply(void) = 0;
	virtual ExpressionElement <T, V> * createDivide(void) = 0;
	virtual ExpressionElement <T, V> * createModulus(void) = 0;
	virtual ExpressionElement <T, V> * createOperand(T val) = 0;
};


#endif // !_EXPRESSIONELEMENTFACTORY_H_