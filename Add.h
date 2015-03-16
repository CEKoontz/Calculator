#ifndef _ADD_H_
#define _ADD_H_

#include "BinaryOperation.h"

template <typename T, typename V>
class Add : public BinaryOperation < T, V > {
public:

	// Default Constructor
	Add(void);

	// Default Destructor
	virtual ~Add(void);

	// Precedence
	int precedence(void);

protected:
	int rank_;

private:
	/** Template Method functions **/
	virtual T getFirstOperand(V & s) = 0;
	virtual T getSecondOperand(V & s) = 0;
	T operate(T & a, T & b);
	virtual bool finish(V & s, T & res) = 0;
};

#include "Add.cpp"

#endif