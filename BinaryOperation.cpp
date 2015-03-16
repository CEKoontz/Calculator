// Default Constructor
template <typename T, typename V>
BinaryOperation<T, V>::BinaryOperation(void) {

}


// Default Destructor
template <typename T, typename V>
BinaryOperation<T, V>::~BinaryOperation(void) {

}


// Execute
template <typename T, typename V>
bool BinaryOperation<T, V>::execute(V & s) {
	// Retrieve operands
	T a = this->getFirstOperand(s);
	T b = this->getSecondOperand(s);

	// Perform operation
	T result = this->operate(a, b);

	// Handle result and return success value
	return this->finish(s, result);
}