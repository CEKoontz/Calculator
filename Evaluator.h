#ifndef _EVALUATOR_H_
#define _EVALUATOR_H_

#include "Queue.h"
#include "Stack.h"
#include "ExpressionElement.h"
#include <string>
#include <memory>


/**
	Parse

	input:	string representation of the expression
	exp:	output, queue of expression operations; post-fix representation of the expression
	retval:	true on success
**/
bool parse(std::string & input, Queue <std::shared_ptr <ExpressionElement <int, Stack <int> > > > & exp);


/**
	Evaluate

	exp:	queue of expression operations; post-fix representation of the expression
	result:	result of the computation
	reval: true on success

**/
bool evaluate(Queue <std::shared_ptr <ExpressionElement <int, Stack <int> > > > & exp, int & result);

#endif