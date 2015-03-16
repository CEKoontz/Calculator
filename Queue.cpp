#define QUEUE_DEFAULT_SIZE 10

// Default Constructor
template <typename T>
Queue <T>::Queue(void)
	:array_(Array <T>(QUEUE_DEFAULT_SIZE)),
	head_(0),
	tail_(0),
	prevOp_(DQ)
{

}

// Copy Constructor
template <typename T>
Queue <T>::Queue(const Queue & q)
	:array_(q.array_),
	head_(q.head_),
	tail_(q.tail_),
	prevOp_(q.prevOp_)
{

}

// Destructor
template <typename T>
Queue <T>::~Queue(void) {

}

// Assignment Operator
template <typename T>
const Queue <T> & Queue <T>::operator=(const Queue & rhs) {
	this->array_ = rhs.array_;
	this->head_ = rhs.head_;
	this->tail_ = rhs.tail_;
	this->prevOp_ = rhs.prevOp_;

	return *this;
}

// Enqueue
template <typename T>
void Queue <T>::enqueue(T element) {
	// Add element to queue if the queue is not full
	if (this->size() < array_.size()) {
		array_.set(tail_, element);
		advance(tail_);
		prevOp_ = EQ;
	}

	// Otherwise, create a new, larger queue, copy data over,
	// then queue the element
	else {
		Array <T> newArray(array_.size() + QUEUE_DEFAULT_SIZE);
		size_t qSize = size();

		for (size_t i = 0; is_empty() == false; ++i)
			newArray.set(i, this->dequeue());
		
		array_ = newArray;
		head_ = 0;
		tail_ = qSize;

		enqueue(element);
	}
}

// Dequeue
template <typename T>
T Queue <T>::dequeue(void) {
	// Throw an exception if the queue is empty
	if (is_empty())
		throw empty_exception();
	else {
		T element = array_[head_];
		advance(head_);
		prevOp_ = DQ;
		return element;
	}
}

// Is Empty
template <typename T>
bool Queue <T>::is_empty(void) {
	if (size() == 0)
		return true;
	else
		return false;
}

// Size
template <typename T>
size_t Queue <T>::size(void) {
	// Tail is ahead of head: size is the difference
	if (tail_ > head_)
		return (tail_ - head_);

	// Head is ahead of tail: size is array size less empty space
	else if (tail_ < head_)
		return (array_.size() - (head_ - tail_));

	// Head and Tail are the same: could be empty or full, look at
	// previous operation to tell which
	else {
		if (prevOp_ == DQ)
			return 0;
		else
			return array_.size();
	}
}

// Clear
template <typename T>
void Queue <T>::clear(void) {
	head_ = 0;
	tail_ = 0;
	prevOp_ = DQ;
}

// Advance
template <typename T>
void Queue <T>::advance(size_t & index) {
	index = (index + 1) % array_.size();
}