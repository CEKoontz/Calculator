#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "BinaryOperation.h"

template <typename T, typename V>
class Divide : public BinaryOperation < T, V > {
public:

	// Default Constructor
	Divide(void);

	// Default Destructor
	virtual ~Divide(void);

	// Precedence
	int precedence(void);

	// Divide by Zero exception -- copied from empty_exception by Dr. Hill
	class divide_by_zero : public std::exception {
	public:
		// Default constructor.
		divide_by_zero (void)
			: std::exception() {}
	};

protected:
	int rank_;

private:
	/** Template Method functions **/
	virtual T getFirstOperand(V & s) = 0;
	virtual T getSecondOperand(V & s) = 0;
	T operate(T & a, T & b);
	virtual bool finish(V & s, T & res) = 0;
};

#include "Divide.cpp"

#endif