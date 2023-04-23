#pragma once
#include <queue>

template <typename T>
class Component;

template <typename T>
class IteratorMemento {
public:
    explicit IteratorMemento(const std::queue<Component<T>*>& state) : _state(state) {}
    
    // state getter
    const std::queue<Component<T>*>& getState() const {
        return _state;
    }
private:
    // the state
    std::queue<Component<T>*> _state;
};