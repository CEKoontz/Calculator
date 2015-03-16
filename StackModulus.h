#ifndef _STACKMODULUS_H_
#define _STACKMODULUS_H_

#include "Modulus.h"
#include "StackOperand.h"
#include "Stack.h"

template <typename T>
class StackModulus : public Modulus < T, Stack <T> > {
public:
	// Default Construcor
	StackModulus(void);

	// Default Destructor
	~StackModulus(void);

private:
	/** Template Method functions **/
	T getFirstOperand(Stack <T> & s);
	T getSecondOperand(Stack <T> & s);
	bool finish(Stack <T> & s, T & res);
	T second_;
};

#include "StackModulus.cpp"

#endif