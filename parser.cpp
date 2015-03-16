#include "Evaluator.h"
#include "StackElementFactory.h"
#include <iostream>

using std::string;
using std::shared_ptr;

string getNextSubstring(string & str, size_t pos, char delimiter = ' ') {
	size_t edge = str.find(delimiter, pos);
	return str.substr(pos, edge - pos);
}

shared_ptr <BinaryOperation <int, Stack <int> > > convert(string & str, StackElementFactory <int> & factory) {
	if (str == "+")
		return shared_ptr <StackAdd <int> >(factory.createAdd());
	else if (str == "-")
		return shared_ptr <StackSubtract <int> >(factory.createSubtract());
	else if (str == "*")
		return shared_ptr <StackMultiply <int> > (factory.createMultiply());
	else if (str == "/")
		return shared_ptr <StackDivide <int> >(factory.createDivide());
	else if (str == "%")
		return shared_ptr <StackModulus <int> >(factory.createModulus());
}

bool findSubExpression(string str, size_t start, string & subExp) {
	Stack <char> stk;

	for (size_t i = start; i < str.length(); ++i) {
		// Push open brackets
		if (str[i] == '(')
			stk.push(str[i]);
		else if (str[i] == ')') {
			// Error if the stack is empty and looking at a closed bracket
			if (stk.is_empty())
				return false;
			// Pop corresponding bracket
			else
				stk.pop();
		}

		// Check exit condition
		// An empty stack indicates a balanced set of brackets has been found
		if (stk.is_empty()) {
			subExp = str.substr(start + 1, i - start);
			return true;
		}
	}

	// Unbalanced brackets, return error
	return false;
}

bool parse(string & input, Queue <shared_ptr <ExpressionElement <int, Stack <int> > > > & exp) {
	StackElementFactory <int> factory;
	Stack <shared_ptr <BinaryOperation <int, Stack <int> > > > opStack;
	string token;
	int value;

	size_t i = 0;
	while (i < input.length()) {
		if (input[i] != ' ' && input[i] != ')') {
			// Token is an element of the expression in string form
			token = getNextSubstring(input, i);

			/** Attempt to convert token to a number, and enqueue is so **/
			try {
				value = stoi(token, nullptr, 0);
				exp.enqueue(shared_ptr <StackOperand<int> >(factory.createOperand(value)));
			}
			/** Token is not a number, must be an operator **/
			catch (std::invalid_argument) {
				// Handle bracketed sub-expressions
				if (token == "(") {
					// Find sub-expression
					if (findSubExpression(input, i, token) == false)
						return false;

					// Parse sub-expression
					if (parse(token, exp) == false)
						return false;
				}
				else {
					// Convert the string to an operator
					shared_ptr <BinaryOperation <int, Stack <int> > > op = convert(token, factory);

					// If the stack is empty push
					if (opStack.is_empty() == true) {
						opStack.push(op);
					}

					// Pop the stack while the top is of greater or equal precedence, then push
					else {
						while (opStack.is_empty() == false && opStack.top()->precedence() >= op->precedence()) {
							exp.enqueue(opStack.top());
							opStack.pop();
						}
						opStack.push(op);
					}

				} // end else
			}
			/** Something unexpected occurred, exit **/
			catch (...) {
				return false;
			}

			i += token.length();
		} // end if(input[i] != ' ' )
		else
			++i;

	} // end while

	/** Pop any remaining operators on the stack **/
	while (opStack.is_empty() == false) {
		exp.enqueue(opStack.top());
		opStack.pop();
	}

	return true;
}