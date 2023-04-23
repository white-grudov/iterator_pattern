#pragma once

#include "Iterator.h"

template <typename T>
class ArrayList;

// abstract non-terminal class for array iterators
template <typename T>
class AbstractArrayIterator : public Iterator<T>
{
public:
    AbstractArrayIterator(const ArrayList<T>* array) : _array(array), _index(-1) {}
    virtual ~AbstractArrayIterator() {}

protected:
    // we are already implementing some of the interface methods here
    bool doEnd() const override final;
    const T& doDereference() const override final;
    T& doDereference() override final;

    // and also declaring attributes for iteration control
    const ArrayList<T>* _array;
    int _index;

    // and implement methods for derived classes in order to get access to arrray's private attributes
    virtual int last() final;

private:
    // interface methods which will be implemented in terminal classes
    virtual Iterator<T>& doClone() = 0;
    virtual void doBegin() = 0;
    virtual void doNext() = 0;
    virtual const Iterator<T>& doAdd() = 0;
};

template <typename T>
bool AbstractArrayIterator<T>::doEnd() const {
    return _index < 0 || _index >= _array->doSize();
}
template <typename T>
const T& AbstractArrayIterator<T>::doDereference() const {
    return _array->_array[_index];
}
template <typename T>
T& AbstractArrayIterator<T>::doDereference() {
    return _array->_array[_index];
}

template <typename T>
int AbstractArrayIterator<T>::last() {
    return _array->doSize() - 1;
}
