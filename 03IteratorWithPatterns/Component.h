#pragma once

// interface for the composite objects
template <typename T>
class Component {
public:
    virtual void add(Component<T>* c) = 0;
    virtual void remove(Component<T>* c) = 0;
    virtual bool isComposite() const {
        return false;
    }
    virtual T getValue() const = 0;

    virtual ~Component() {}
};