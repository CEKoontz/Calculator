#ifndef _STACKDIVIDE_H_
#define _STACKDIVIDE_H_

#include "Divide.h"
#include "StackOperand.h"
#include "Stack.h"

template <typename T>
class StackDivide : public Divide < T, Stack <T> > {
public:
	// Default Construcor
	StackDivide(void);

	// Default Destructor
	~StackDivide(void);

private:
	/** Template Method functions **/
	T getFirstOperand(Stack <T> & s);
	T getSecondOperand(Stack <T> & s);
	bool finish(Stack <T> & s, T & res);
	T second_;
};

#include "StackDivide.cpp"

#endif