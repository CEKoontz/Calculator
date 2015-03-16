#ifndef _STACKADD_H_
#define _STACKADD_H_

#include "Add.h"
#include "StackOperand.h"
#include "Stack.h"

template <typename T>
class StackAdd : public Add < T, Stack <T> > {
public:
	// Default Construcor
	StackAdd(void);

	// Default Destructor
	~StackAdd(void);

private:
	/** Template Method functions **/
	T getFirstOperand(Stack <T> & s);
	T getSecondOperand(Stack <T> & s);
	bool finish(Stack <T> & s, T & res);
	T second_;
};

#include "StackAdd.cpp"

#endif