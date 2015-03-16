#ifndef _STACKSUBTRACT_H_
#define _STACKSUBTRACT_H_

#include "Subtract.h"
#include "StackOperand.h"
#include "Stack.h"

template <typename T>
class StackSubtract : public Subtract < T, Stack <T> > {
public:
	// Default Construcor
	StackSubtract(void);

	// Default Destructor
	~StackSubtract(void);

private:
	/** Template Method functions **/
	T getFirstOperand(Stack <T> & s);
	T getSecondOperand(Stack <T> & s);
	bool finish(Stack <T> & s, T & res);
	T second_;
};

#include "StackSubtract.cpp"

#endif