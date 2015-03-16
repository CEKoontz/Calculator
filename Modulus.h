#ifndef _MODULUS_H_
#define _MODULUS_H_

#include "BinaryOperation.h"

template <typename T, typename V>
class Modulus : public BinaryOperation < T, V > {
public:

	// Default Constructor
	Modulus(void);

	// Default Destructor
	virtual ~Modulus(void);

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

#include "Modulus.cpp"

#endif