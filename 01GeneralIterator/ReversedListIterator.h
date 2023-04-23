#pragma once

#include "AbstractListIterator.h"

template <typename T>
using ALI = AbstractListIterator<T>;

// concrete terminal reverse iterator for list
template <typename T>
class ReverseListIterator final : public AbstractListIterator<T>
{
public:
    // using the base class constructor
    ReverseListIterator(const LinkedList<T>* list) : ALI<T>(list) {}
    ~ReverseListIterator() {}

protected:
    // implementing the rest of interface methods
    ReverseListIterator<T>& doClone() override;
    void doBegin() override;
    void doNext() override;
    const Iterator<T>& doAdd() override;
};
// here we use protected attributes and methods of base abstract class
template <typename T>
ReverseListIterator<T>& ReverseListIterator<T>::doClone() {
    return *(new ReverseListIterator(ALI<T>::_list));
}
template <typename T>
void ReverseListIterator<T>::doBegin() {
    ALI<T>::_current = ALI<T>::last();
}
template <typename T>
void ReverseListIterator<T>::doNext() {
    if (ALI<T>::_current != nullptr) {
        ALI<T>::_current = ALI<T>::prevNode();
    }
}
template <typename T>
const Iterator<T>& ReverseListIterator<T>::doAdd() {
    ALI<T>::_current = ALI<T>::prevNode();
    return *this;
}