#include "Evaluator.h"

using std::shared_ptr;

bool evaluate(Queue <shared_ptr <ExpressionElement <int, Stack <int> > > > & exp, int & result) {
	Stack <int> stk;
	shared_ptr <ExpressionElement <int, Stack <int> > > element;

	// Calculate
	while (exp.is_empty() == false) {
		element = exp.dequeue();

		// Execute
		try {
			if (element->execute(stk) == false) {
				// Error, return false
				return false;
			}
		}
		catch (...) {
			return false;
		}
	}


	// Get result
	if (stk.is_empty())
		return false;
	else
		result = stk.top();


	return true;
}