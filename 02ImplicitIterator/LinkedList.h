#include <iostream>

#include "Container.h"
#include "Iterator.h"

template <typename T>
class LinkedList : public Container<T> {
public:
    LinkedList() : _first(nullptr), _last(nullptr), _size(0) {}
    ~LinkedList();

    // in this implementation, the iterator class is the member class of the collection
    // (STL collections are implemented the same way)
    class ListIterator;

    // begin and end methods define the implicit iterator
    ListIterator begin();
    ListIterator end();
private:
    struct Node;

    Node* _first;
    Node* _last;

    int _size;

    LinkedList& doAdd(const T& value);
    void doRemove();
    int doSize() const;
    bool doIsEmpty() const;
};

template <typename T>
class LinkedList<T>::ListIterator final : public Iterator<T>{
public:
    ListIterator(LinkedList<T>::Node * node) : _node(node) {}
    // copy constructor for comparing the iterators
    ListIterator(const ListIterator & other) : Iterator<T>(other), _node(other._node) {}

private:
    LinkedList<T>::Node * _node;

    // compares current node with the node passed by other (other is explicitly converted to ListIterator)
    bool doNotEqual(const Iterator<T>& other) const {
        const ListIterator* otherIterator = static_cast<const ListIterator*>(&other);
        return _node != otherIterator->_node;
    }
    // returns the value of the node
    T& doDereference() const {
        return _node->_value;
    }
    // proceeds to the next node
    ListIterator& doIncrement() {
        _node = _node->_next;
        return *this;
    }
};
// returns begin iterator
template <typename T>
typename LinkedList<T>::ListIterator LinkedList<T>::begin() {
    return ListIterator(_first);
}
// returns end iterator
template <typename T>
typename LinkedList<T>::ListIterator  LinkedList<T>::end() {
    return ListIterator(nullptr);
}

// we don't need to know the internal implementation of the linked list in detail
template <typename T>
struct LinkedList<T>::Node
{
    Node(const T& value) : _value(value), _prev(nullptr), _next(nullptr) {}
    Node* _prev;
    Node* _next;
    T _value;
};
template<typename T>
LinkedList<T>::~LinkedList()
{
    while (_first) {
        Node* next = _first->_next;
        delete _first;
        _first = next;
    }
}
template<typename T>
LinkedList<T>& LinkedList<T>::doAdd(const T& value)
{
    Node* node = new Node(value);
    if (!_first) {
        _first = node;
        _last = node;
    }
    else {
        _last->_next = node;
        node->_prev = _last;
        _last = node;
    }
    ++_size;
    return *this;
}
template<typename T>
void LinkedList<T>::doRemove()
{
    if (!_first) {
        throw std::out_of_range("LinkedList is empty");
    }
    Node* node = _last;
    if (_first == _last) {
        _first = nullptr;
        _last = nullptr;
    }
    else {
        _last = _last->_prev;
        _last->_next = nullptr;
    }
    --_size;
    delete node;
}
template<typename T>
int LinkedList<T>::doSize() const
{
    return _size;
}
template<typename T>
bool LinkedList<T>::doIsEmpty() const
{
    return _size == 0;
}