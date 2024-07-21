#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <exception>

template <typename ANY, size_t max_size>
class Queue {
private:
	ANY data[max_size];
	size_t size;
public:
	Queue() : size(0){}
	void put(ANY value);
	ANY get();
	ANY look();
	bool isEmpty();
	bool isFull();
	void clear();
};

template<typename ANY, size_t max_size>
 void Queue<ANY, max_size>::put(ANY value) {
	 if (isFull())
		 throw std::exception("queue overflow");
	 data[size++] = value;
}
template<typename ANY, size_t max_size>
 ANY Queue<ANY, max_size>::get() {
	 if (isEmpty())
		 throw std::exception("queue is empty");
	 ANY tmp = data[0];
	 for (size_t i = 1; i < size; ++i)
		 data[i - 1] = data[i];
	 --size;
	 return tmp;
}

template<typename ANY, size_t max_size>
 ANY Queue<ANY, max_size>::look() {
	 if (isEmpty())
		 throw std::exception("queue is empty");
	 return data[0];
}

template<typename ANY, size_t max_size> bool Queue<ANY, max_size>::isEmpty(){
	return size == 0;
}

template<typename ANY, size_t max_size>
 bool Queue<ANY, max_size>::isFull(){
	return size == max_size;
}

template<typename ANY, size_t max_size>
 void Queue<ANY, max_size>::clear(){
	 size = 0;
}


#endif // _QUEUE_HPP_