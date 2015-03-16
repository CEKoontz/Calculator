 // $Id: Array.cpp 1473 2014-01-20 15:48:07Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


//
// Array
//
template <typename T>
Array <T>::Array (void):
	data_ (0),
	cur_size_ (0),
	max_size_ (0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
	data_ (0),
	cur_size_ (0),
	max_size_ (0)
{
	if (length != 0) {
		data_ = new T [length + ARRAY_DEFAULT_SIZE];
		cur_size_ = length;
		max_size_ = length + ARRAY_DEFAULT_SIZE;
	}
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
	data_ (0),
	cur_size_ (0),
	max_size_ (0)
{
	if (length != 0) {
		data_ = new T [length + ARRAY_DEFAULT_SIZE];
		cur_size_ = length;
		max_size_ = length + ARRAY_DEFAULT_SIZE;
		this->fill(fill);
	}
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
	data_(0),
	cur_size_ (array.cur_size_),
	max_size_ (array.max_size_)
{
	if (array.data_ != 0 || cur_size_ != 0 || max_size_ != 0) {
		T * ar = new T [max_size_];

		for (size_t i = 0; i < cur_size_; ++i)
			ar[i] = array.data_[i];

		data_ = ar;
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	if (data_ != 0)
		delete [] data_;
}

//
// operator =
//
template <typename T>
const Array<T> & Array <T>::operator = (const Array & rhs)
{
	// Check for self reference
	if (*this != rhs) {

		// Only need to allocate new memory if rhs is larger than what
		// already is allocated
		if (max_size_ >= rhs.cur_size_) {
			for (size_t i = 0; i < rhs.cur_size_; ++i)
				data_[i] = rhs.data_[i];

			cur_size_ = rhs.cur_size_;
		}
		else {
			// Allocate new array, and copy rhs data into it
			T * ar = new T [rhs.max_size_];

			for (size_t i = 0; i < rhs.cur_size_; ++i)
				ar[i] = rhs.data_[i];

			// Update attributes
			cur_size_ = rhs.cur_size_;
			max_size_ = rhs.max_size_;

			T * temp = data_;
			data_ = ar;
			if (data_ != 0)
				delete[] temp;
		}
	}

	return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if (index >= cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	else if(data_ == 0) {
		throw std::out_of_range("Invalid access");
	}
	else
		return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if (index >= cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	else if(data_ == 0) {
		throw std::out_of_range("Invalid access");
	}
	else
		return data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if (index >= cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	else if(data_ == 0) {
		throw std::out_of_range("Invalid access");
	}
	else
		return data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if (index >= cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	else if(data_ == 0) {
		throw std::out_of_range("Invalid access");
	}
	else
		data_[index] = value;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size <= max_size_)
		cur_size_ = new_size;
	else{
		size_t oldSize = cur_size_;
		cur_size_ = new_size;
		max_size_ = new_size + ARRAY_DEFAULT_SIZE;

		T * ar = new T [max_size_];
		if (data_ != 0) {							// Don't copy/delete from null
			T * temp = data_;
			for (size_t i = 0; i < oldSize; ++i)
				ar[i] = data_[i];
			data_ = ar;
			delete[] temp;
		}
		else
			data_ = ar;
	}
}

//
// find (T)
//
template <typename T>
int Array <T>::find (T ch) const
{
	return find (ch, 0);
}

//
// find (T, size_t) 
//
template <typename T>
int Array <T>::find (T ch, size_t start) const
{
	if (start > cur_size_){
		throw std::out_of_range("Index is out of range");
	}
	else if (data_ == 0) {
		throw std::out_of_range("Invalid access");
	}
	else if (cur_size_ == 0) {
		throw std::out_of_range("Array size is zero");
	}
	else{
		for (start; start < cur_size_; ++start){
			if (data_[start] == ch)
				return start;
		}

		return -1;	// ch not found
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if (this->data_ == 0 && rhs.data_ == 0) {			// If both point to null, they're equal
		return true;
	}
	else if (this->data_ == 0 || rhs.data_ == 0) {		// If one points to null and not both, they're not equal
		return false;
	}
	else if (this->cur_size_ != rhs.cur_size_) {		// Check sizes
		return false;
	}
	else {												// Check characters for non-null, equal length arrays
		for(size_t i = 0; i < cur_size_; ++i) {
			if (this->get(i) != rhs.data_[i])
				return false;
		}
	}

	return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill (T ch)
{
	if (data_ != 0) {
		for (size_t i = 0; i < cur_size_; ++i)
			data_[i] = ch;
	}
}