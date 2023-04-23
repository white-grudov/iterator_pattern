#pragma once
#include <vector>
#include "Component.h"
#include "Iterator.h"
template <typename T>
class CompositeIterator;

template <typename T>
class NullIterator;

template <typename T>
class Composite : public Component<T> {
public:
    friend CompositeIterator<T>;

    explicit Composite(const T& value) : _value(value) {}
    // add child component
    void add(Component<T>* c) override {
        _children.push_back(c);
    }

    // remove component
    void remove(Component<T>* c) override {
        for (auto it = _children.begin(); it != _children.end(); ++it) {
            if (*it == c) {
                _children.erase(it);
                return;
            }
        }
    }
    bool isComposite() const override {
        return true;
    }
    // returns the value, which is the sum of all children values
    T getValue() const override {
        T value = _value;
        for (auto& child : _children) {
            value += child->getValue();
        }
        return value;
    }
    // fabric method for iterator
    Iterator<T>* createIterator() {
        return new CompositeIterator<T>(this);
    }
private:
    std::vector<Component<T>*> _children;
    T _value;
};
