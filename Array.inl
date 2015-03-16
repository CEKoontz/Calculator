// -*- C++ -*-
// $Id: Array.inl 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Array <T>::size (void) const
{
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array <T>::max_size (void) const
{
	return max_size_;
}
