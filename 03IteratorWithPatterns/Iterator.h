#pragma once
template <typename T>
class Component;
template <typename T>
class IteratorMemento;

// interface for the iterators
template <typename T>
class Iterator {
public:
    virtual Component<T>* getNext() = 0;

    // memento pattern
    virtual IteratorMemento<T> createMemento() const = 0;
    virtual void restoreMemento(const IteratorMemento<T>& memento) = 0;
    
    virtual bool isDone() const = 0;
    virtual ~Iterator() {}
};