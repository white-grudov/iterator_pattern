#pragma once

#include "ArrayIterator.h"
#include "Container.h"

template <typename T>
class AbstractArrayIterator;

template <typename T>
class ArrayList : public Container<T> {
public:
    // we are declaring base abstract iterator class as friend to get access to private fields
    friend class AbstractArrayIterator<T>;

    ArrayList(size_t size = 64) : _array(new T[size]()), _size(size), _count(0) {}
    ~ArrayList() {
        delete[] _array;
    }

private:
    T* _array;
    size_t _size;
    size_t _count;

    ArrayList& doAdd(const T& value);
    void doRemove();
    int doSize() const;
    bool doIsEmpty() const;
    std::unique_ptr<Iterator<T>> doCreateIterator() const;
};

// implementations details of collection classes are not necessary
template<typename T>
ArrayList<T>& ArrayList<T>::doAdd(const T& value) {
    _array[_count++] = value;
    return *this;
}
template<typename T>
void ArrayList<T>::doRemove() {
    if (_count == 0) {
        throw std::out_of_range("ArrayList is empty");
    }
    _array[--_count] = 0;
}
template<typename T>
int ArrayList<T>::doSize() const {
    return _count;
}
template<typename T>
bool ArrayList<T>::doIsEmpty() const {
    return _count == 0;
}

// factory method for creating the iterator
template<typename T>
std::unique_ptr<Iterator<T>> ArrayList<T>::doCreateIterator() const {
    return std::make_unique<ArrayIterator<T>>(this);
}
