#pragma once
#include <queue>
#include "Component.h"
#include "Iterator.h"
#include "IteratorMemento.h"

template <typename T>
class CompositeIterator : public Iterator<T> {
public:
    explicit CompositeIterator(Component<T>* root) {
        queue.push(root);
    }

    // gets the next component using breadth-first search
    Component<T>* getNext() override {
        if (queue.empty()) {
            return nullptr;
        }
        Component<T>* component = queue.front();
        queue.pop();
        if (Composite<T>* composite = dynamic_cast<Composite<T>*>(component)) {
            for (auto& child : composite->_children) {
                queue.push(child);
            }
        }
        return component;
    }

    // creates memento with the current state of the iterator
    IteratorMemento<T> createMemento() const override {
        return IteratorMemento<T>(queue);
    }
    // restores the state
    void restoreMemento(const IteratorMemento<T>& memento) override {
        queue = memento.getState();
    }
    // if traversal is done
    bool isDone() const override {
        return queue.empty();
    }
private:
    // components to be visited during iteration
    std::queue<Component<T>*> queue;
};