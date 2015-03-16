#ifndef _STACKMULTIPLY_H_
#define _STACKMULTIPLY_H_

#include "Multiply.h"
#include "StackOperand.h"
#include "Stack.h"

template <typename T>
class StackMultiply : public Multiply < T, Stack <T> > {
public:
	// Default Construcor
	StackMultiply(void);

	// Default Destructor
	~StackMultiply(void);

private:
	/** Template Method functions **/
	T getFirstOperand(Stack <T> & s);
	T getSecondOperand(Stack <T> & s);
	bool finish(Stack <T> & s, T & res);
	T second_;
};

#include "StackMultiply.cpp"

#endif