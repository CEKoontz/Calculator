// Default Constructor
template <typename T>
StackElementFactory <T>::StackElementFactory(void) {

}


// Default Destructor
template <typename T>
StackElementFactory <T>::~StackElementFactory(void) {

}


// Create Add
template <typename T>
StackAdd<T> * StackElementFactory <T>::createAdd(void) {
	return new StackAdd <T>();
}


// Create Subtract
template <typename T>
StackSubtract <T> * StackElementFactory <T>::createSubtract(void) {
	return new StackSubtract <T>();
}


// Create Multiply
template <typename T>
StackMultiply <T> * StackElementFactory <T>::createMultiply(void) {
	return new StackMultiply <T>();
}


// Create Divide
template <typename T>
StackDivide <T> * StackElementFactory <T>::createDivide(void) {
	return new StackDivide <T> ();
}


// Create Modulus
template <typename T>
StackModulus <T> * StackElementFactory <T>::createModulus(void) {
	return new StackModulus <T>();
}


// Create Operand
template <typename T>
StackOperand <T> * StackElementFactory <T>::createOperand(T val) {
	return new StackOperand <T>(val);
}