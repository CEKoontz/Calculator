#ifndef _EXPRESSIONELEMENT_H_
#define _EXPRESSIONELEMENT_H_

template <typename T, typename V>
class ExpressionElement{
public:
	// Default Constructor
	ExpressionElement(void) {}

	// Default Destructor
	virtual ~ExpressionElement(void) {}

	// Execute
	virtual bool execute(V & s) = 0;
};

#endif