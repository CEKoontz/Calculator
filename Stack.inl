// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return top_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (this->is_empty())
		throw empty_exception();
	else
		return array_.get(top_ - 1);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (top_ == 0);
}

//
// advanceTop
//
template <typename T>
inline
void Stack <T>::advanceTop (void)
{
	top_++;
	if (array_.max_size() <= top_)
		array_.resize(array_.max_size() + STACK_DEFAULT_SIZE);
}
