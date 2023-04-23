#pragma once

#include "Iterator.h"

template <typename T>
class LinkedList;

// abstract non-terminal class for list iterators
template <typename T>
class AbstractListIterator : public Iterator<T>
{
public:
	AbstractListIterator(const LinkedList<T>* list) : _list(list), _current(nullptr) {}
	virtual ~AbstractListIterator() {}

protected:
	// we are already implementing some of the interface methods here
	bool doEnd() const override final;
	const T& doDereference() const override final;
	T& doDereference() override final;

	// and also declaring attributes for iteration control
	const LinkedList<T>* _list;
	typename LinkedList<T>::Node* _current;

	// and implement methods for derived classes in order to get access to arrray's private attributes
	virtual typename LinkedList<T>::Node* first() final;
	virtual typename LinkedList<T>::Node* last() final;
	virtual typename LinkedList<T>::Node* nextNode() final;
	virtual typename LinkedList<T>::Node* prevNode() final;
private:
	// interface methods which will be implemented in terminal classes
	virtual Iterator<T>& doClone() = 0;
	virtual void doBegin() = 0;
	virtual void doNext() = 0;
	virtual const Iterator<T>& doAdd() = 0;
};
template <typename T>
bool AbstractListIterator<T>::doEnd() const {
	return _current == nullptr;
}
template <typename T>
const T& AbstractListIterator<T>::doDereference() const {
	return _current->_value;
}
template <typename T>
T& AbstractListIterator<T>::doDereference() {
	return _current->_value;
}

template <typename T>
typename LinkedList<T>::Node* AbstractListIterator<T>::first() {
	return _list->_first;
}
template <typename T>
typename LinkedList<T>::Node* AbstractListIterator<T>::last() {
	return _list->_last;
}
template <typename T>
typename LinkedList<T>::Node* AbstractListIterator<T>::nextNode() {
	return _current->_next;
}
template <typename T>
typename LinkedList<T>::Node* AbstractListIterator<T>::prevNode() {
	return _current->_prev;
}