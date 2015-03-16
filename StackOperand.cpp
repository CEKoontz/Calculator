// Default Constructor
template <typename T>
StackOperand <T>::StackOperand(void)
	:Operand <T, Stack <T> >()
{

}


// Value Constructor
template <typename T>
StackOperand <T>::StackOperand(T val)
	:Operand <T, Stack <T> >(val)
{

}


// Default Destructor
template <typename T>
StackOperand <T>::~StackOperand(void) {

}


// Execute
template <typename T>
bool StackOperand <T>::execute(Stack <T> & s) {
	try {
		s.push(Operand <T, Stack <T> >::value_);
	}
	catch (...) {
		return false;
	}
	
	return true;
}