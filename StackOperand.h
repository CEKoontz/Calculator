#ifndef _STACKOPERAND_H_
#define _STACKOPERAND_H_

#include "Operand.h"
#include "Stack.h"

template <typename T>
class StackOperand : public Operand < T, Stack <T> > {
public:
	// Default Constructor
	StackOperand(void);

	// Value Constructor
	StackOperand(T val);

	// Default Destructor
	~StackOperand(void);

	// Execute
	bool execute(Stack <T> & s);
};

#include "StackOperand.cpp"

#endif // !_STACKOPERAND_H_