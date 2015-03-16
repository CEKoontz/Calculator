/**
	Queue
	
	An ADT that contains a list of elements such that the list has first-in,
	first-out (FIFO) semantics, i.e., elements are inserted into the of the list 
	and removed from the front of the list
**/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"

#define DQ true
#define EQ !DQ

template <typename T>
class Queue{
public:
	typedef T type;

	/**
	* @class empty_exception
	*
	* Exception thrown to indicate the stack is empty.
	*/
	class empty_exception : public std::exception
	{
		public:
			/// Default constructor.
			empty_exception(void) : std::exception() {}
	};

	// Default Constructor
	Queue(void);

	// Copy Constructor
	Queue(const Queue & q);

	// Destructor
	~Queue(void);

	/* 
		Assignment Operator

		rhs		right hand side of operator
		return	reference to self
	*/
	const Queue & operator = (const Queue & rhs);

	/*
		enqueue

		element		item to be added to the end of the queue
	*/
	void enqueue(T element);
	
	/*
		dequeue
		
		return		item at the front of the queue
		throws exception when queue is empty
	*/
	T dequeue(void);

	/*
		is_empty

		return		true if the queue is empty
	*/
	bool is_empty(void);

	/*
		size

		return		number of items in the queue
	*/
	size_t size(void);

	// clear - remove all items from the queue
	void clear(void);

private:
	Array<T> array_;
	size_t head_;		// Index in array_ pointing to front of the 'line'
	size_t tail_;		// Index in array_ pointing to one past the back of the 'line'
	bool prevOp_;

	// Helper Functions
	void advance(size_t & index);
};

#include "Queue.cpp"

#endif