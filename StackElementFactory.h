#ifndef _STACKELEMENTFACTORY_H_
#define _STACKELEMENTFACTORY_H_

#include "ExpressionElementFactory.h"
#include "Stack.h"
#include "StackAdd.h"
#include "StackSubtract.h"
#include "StackMultiply.h"
#include "StackDivide.h"
#include "StackModulus.h"
#include "StackOperand.h"

template <typename T>
class StackElementFactory : public ExpressionElementFactory < T, Stack <T> > {
public:
	// Default Constructor
	StackElementFactory(void);

	// Default Destructor
	~StackElementFactory(void);

	// Creators
	StackAdd <T> * createAdd(void);
	StackSubtract <T> * createSubtract(void);
	StackMultiply <T> * createMultiply(void);
	StackDivide <T> * createDivide(void);
	StackModulus <T> * createModulus(void);
	StackOperand <T> * createOperand(T val);
};

#include "StackElementFactory.cpp"

#endif // !_STACKELEMENTFACTORY_H_