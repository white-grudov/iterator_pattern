#include <iostream>

#include "ListIterator.h"
#include "Container.h"

template <typename T>
class AbstractListIterator;

template <typename T>
class LinkedList : public Container<T> {
public:
    // we are declaring base abstract iterator class as friend to get access to private fields
    friend class AbstractListIterator<T>;

    LinkedList() : _first(nullptr), _last(nullptr), _size(0) {}
    ~LinkedList();
private:
    struct Node;

    Node* _first;
    Node* _last;

    int _size;

    LinkedList& doAdd(const T& value);
    void doRemove();
    int doSize() const;
    bool doIsEmpty() const;
    std::unique_ptr<Iterator<T>> doCreateIterator() const;
};

// implementations details of collection classes are not necessary
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

// factory method for creating the iterator
template<typename T>
std::unique_ptr<Iterator<T>> LinkedList<T>::doCreateIterator() const
{
    return std::make_unique<ListIterator<T>>(this);
}