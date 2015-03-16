#ifndef _BINARYOPERATION_H_
#define _BINARYOPERATION_H_

#include "ExpressionElement.h"

template <typename T, typename V>
class BinaryOperation : public ExpressionElement < T, V > {
public:
	// Default Constructor
	BinaryOperation(void);

	// Default Destructor
	virtual ~BinaryOperation(void);

	// Execute
	bool execute(V & s);

	// Precedence
	virtual int precedence(void) = 0;

private:
	/** Template Method functions **/
	virtual T getFirstOperand(V & s) = 0;
	virtual T getSecondOperand(V & s) = 0;
	virtual T operate(T & a, T & b) = 0;
	virtual bool finish(V & s, T & res) = 0;
};

#include "BinaryOperation.cpp"

#endif