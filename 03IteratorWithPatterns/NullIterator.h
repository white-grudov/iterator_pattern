#pragma once
#include "IteratorMemento.h"
#include "Iterator.h"

template <typename T>
class NullIterator : public Iterator<T> {
public:
    // returns nullptr since there are no children
    Component<T>* getNext() override {
        return nullptr;
    }
    // memento stores and restores nothing
    IteratorMemento<T> createMemento() const override {
        return IteratorMemento<T>(std::queue<Component<T>*>());
    }
    void restoreMemento(const IteratorMemento<T>& memento) override {}
    bool isDone() const override {
        return true;
    }
};