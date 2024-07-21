#ifndef _STACK_HPP
#define _STACK_HPP

#include <iostream>
#include <exception>
template <typename ANY>
class Stack {
private:
	ANY* first;
	ANY* last;
	size_t size;
	size_t elements;
public:
	Stack(size_t size);
	~Stack();
	void put(ANY value);
	ANY get();
	ANY look();
	bool isEmpty();
	bool isFull();
	void clear();
	void upgrade();
};

template <typename ANY> // Реализация класса.
Stack<ANY>::Stack(size_t size) {
	if (size == 0)
		throw std::exception("null size error");
	first = new ANY[size]{};
	last = nullptr;
	this->size = size;
	elements = 0;
}
template <typename ANY>
Stack<ANY>::~Stack() {
	delete[] first;
}

template <typename ANY>
void Stack<ANY>::put(ANY value) {
	if (isFull())
		throw std::exception("stack overflow");
	first[elements++] = value;
	//last = &(first[elements++] = value);
	// Два варианта как написать.
	last = &first[elements  - 1];
}

template <typename ANY>
ANY Stack<ANY>::get() {
	if (isEmpty())
		throw std::exception("stack is empty");

	--elements;
	return *(last--);
}

template <typename ANY>
ANY Stack<ANY>::look() {
	if (isEmpty())
		throw std::exception("stack is empty");
	return *last;
}

template <typename ANY>
bool Stack<ANY>::isEmpty() {
	return elements == 0;
}

template <typename ANY>
bool Stack<ANY>::isFull() {
	return elements == size;
}

template <typename ANY>
void Stack<ANY>::clear() {
	elements = 0;
}


#endif // _STACK_HPP_