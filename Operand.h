#ifndef _OPERAND_H_
#define _OPERAND_H_

#include "ExpressionElement.h"

template <typename T, typename V>
class Operand : public ExpressionElement < T, V > {
public:
	// Default Constructor
	Operand(void);

	// Value Constructor
	Operand(T v);

	// Default Destructor
	virtual ~Operand(void);

	// Execute
	virtual bool execute(V & s) = 0;

protected:
	T value_;
};

#include "Operand.cpp"

#endif