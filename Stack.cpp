// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//#define STACK_DEFAULT_SIZE 10

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
	:array_(Array <T> (STACK_DEFAULT_SIZE)),
	top_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
	:array_(Array <T>(stack.array_)),
	top_(stack.top_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// Push if there's enough space
	if (top_ < array_.size()) {
		array_.set(top_, element);
		advanceTop();
	}

	// Or: resize the array, then push
	else {
		array_.resize(size() + STACK_DEFAULT_SIZE);
		array_.set(top_, element);
		advanceTop();
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (!is_empty())
		--top_;
	else
		throw empty_exception();
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	// Check for self reference
	if (this != &rhs) {
		this->top_ = rhs.top_;
		this->array_ = rhs.array_;
	}

	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	top_ = 0;
}
