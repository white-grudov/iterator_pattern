#pragma once

#include "AbstractListIterator.h"

template <typename T>
using ALI = AbstractListIterator<T>;

// concrete terminal iterator for list
template <typename T>
class ListIterator final : public AbstractListIterator<T>
{
public:
    // using the base class constructor
    ListIterator(const LinkedList<T>* list) : ALI<T>(list) {}
    ~ListIterator() {}

protected:
    // implementing the rest of interface methods
    ListIterator<T>& doClone() override;
    void doBegin() override;
    void doNext() override;
    const Iterator<T>& doAdd() override;
};
// here we use protected attributes and methods of base abstract class
template <typename T>
ListIterator<T>& ListIterator<T>::doClone() {
    return *(new ListIterator(ALI<T>::_list));
}
template <typename T>
void ListIterator<T>::doBegin() {
    ALI<T>::_current = ALI<T>::first();
}
template <typename T>
void ListIterator<T>::doNext() {
    if (ALI<T>::_current != nullptr) {
        ALI<T>::_current = ALI<T>::nextNode();
    }
}
template <typename T>
const Iterator<T>& ListIterator<T>::doAdd() {
    ALI<T>::_current = ALI<T>::nextNode();
    return *this;
}