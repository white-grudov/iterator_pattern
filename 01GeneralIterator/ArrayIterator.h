#pragma once

#include "AbstractArrayIterator.h"

template <typename T>
using AAI = AbstractArrayIterator<T>;

// concrete terminal iterator for array
template <typename T>
class ArrayIterator final : public AbstractArrayIterator<T>
{
public:
    // using the base class constructor
    ArrayIterator(const ArrayList<T>* array) : AAI<T>(array) {}
    ~ArrayIterator() {}

protected:
    // implementing the rest of interface methods
    ArrayIterator<T>& doClone() override;
    void doBegin() override;
    void doNext() override;
    const Iterator<T>& doAdd() override;
};

// here we use protected attributes and methods of base abstract class
template <typename T>
ArrayIterator<T>& ArrayIterator<T>::doClone() {
    return *(new ArrayIterator(AAI<T>::_array));
}
template <typename T>
void ArrayIterator<T>::doBegin() {
    AAI<T>::_index = 0;
}
template <typename T>
void ArrayIterator<T>::doNext() {
    if (!AAI<T>::doEnd()) {
        AAI<T>::_index++;
    }
}
template <typename T>
const Iterator<T>& ArrayIterator<T>::doAdd() {
    AAI<T>::_index++;
    return *this;
}
