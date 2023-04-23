#pragma once

#include "AbstractArrayIterator.h"

template <typename T>
using AAI = AbstractArrayIterator<T>;

// concrete terminal reverse iterator for array
template <typename T>
class ReverseArrayIterator final : public AbstractArrayIterator<T>
{
public:
    // using the base class constructor
    ReverseArrayIterator(const ArrayList<T>* array) : AAI<T>(array) {}
    ~ReverseArrayIterator() {}

protected:
    // implementing the rest of interface methods
    ReverseArrayIterator<T>& doClone() override;
    void doBegin() override;
    void doNext() override;
    const Iterator<T>& doAdd() override;
};

// here we use protected attributes and methods of base abstract class
template <typename T>
ReverseArrayIterator<T>& ReverseArrayIterator<T>::doClone() {
    return *(new ReverseArrayIterator(AAI<T>::_array));
}
template <typename T>
void ReverseArrayIterator<T>::doBegin() {
    AAI<T>::_index = AAI<T>::last();
}
template <typename T>
void ReverseArrayIterator<T>::doNext() {
    if (!AAI<T>::doEnd()) {
        AAI<T>::_index--;
    }
}
template <typename T>
const Iterator<T>& ReverseArrayIterator<T>::doAdd() {
    AAI<T>::_index--;
    return *this;
}
