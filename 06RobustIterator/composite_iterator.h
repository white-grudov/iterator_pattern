#ifndef COMPOSITE_ITERATOR_H_
#define COMPOSITE_ITERATOR_H_

#include <stack>
#include <map>

template<typename Key, typename Value, typename Arg>
inline bool map_contains(const std::map< Key, Value >& m, const Arg& value) {
    return m.find(value) != m.end();
}

template <typename T>
class CompositeIterator : public RobustIterator<T> {
public:
    explicit CompositeIterator(RobustIterator<T>* iterator) {
        push(iterator->get_owner(), iterator);
        RobustIterator<T>::set_owner(iterator->get_owner());
    }
    virtual ~CompositeIterator() = default;

    bool is_done() override {
        if (st.size() <= 0) {
            RobustIterator<T>::unsubscribe();
            return true;
        }

        auto iterator = top();

        if (iterator->is_done()) {
            pop();
            return is_done();
        }
        return false;
    }

    Component<T>* next() override {
        if (is_done()) {
            return nullptr;
        }

        auto iterator = top();
        auto component = iterator->next();
        if (component->is_composite()) {
            push(component, component->create_iterator());
            return next();
        }
        return component;
    }

    void notify_remove(Component<T>* item) override {
        while (map_contains(m, item)) {  // replace with m.contains(item) (C++20) when
            pop();                       // will available in official clang/gcc
        }
    }

private:
    std::stack<Component<T>*> st;
    std::map<Component<T>*, Iterator<T>*> m;

    void push(Component<T>* owner, Iterator<T>* iterator) {
        st.push(owner);
        m.insert(std::make_pair(owner, iterator));
    }

    Iterator<T>* top() {
        auto top_owner(st.top());
        auto it = m.find(top_owner);
        return (it != m.end()) ? it->second : nullptr;
    }

    Iterator<T>* pop() {
        auto pop_owner(st.top());
        st.pop();
        auto iterator = m.at(pop_owner);
        auto it = m.find(pop_owner);
        if (it != m.end()) {
            m.erase(it);
        }
        return iterator;
    }
};

#endif  // COMPOSITE_ITERATOR_H_
