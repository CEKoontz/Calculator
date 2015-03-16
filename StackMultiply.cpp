// Default Constructor
template <typename T>
StackMultiply <T>::StackMultiply(void)
	:second_(0) {

}


// Default Destructor
template <typename T>
StackMultiply <T>::~StackMultiply(void) {

}


// getFirstOperand
template <typename T>
T StackMultiply <T>::getFirstOperand(Stack <T> & s) {
	/** When using the stack, the second element needs to be retrieved first,
	so we get, store it, then return the first element **/
	this->second_ = s.top();	s.pop();
	T a = s.top();				s.pop();

	return a;
}


// getSecondOperand
template <typename T>
T StackMultiply <T>::getSecondOperand(Stack <T> & s) {
	return this->second_;
}


// Finish
template <typename T>
bool StackMultiply <T>::finish(Stack <T> & s, T & res) {
	try {
		s.push(res);
	}
	catch (...) {
		return false;
	}
	return true;
}