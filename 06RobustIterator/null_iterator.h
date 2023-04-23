#ifndef NULL_ITERATOR_H_
#define NULL_ITERATOR_H_

template <typename T>
class NullIterator : public RobustIterator<T> {
public:
    NullIterator() = default;
    virtual ~NullIterator() = default;

    Component<T>* next() override {
        return nullptr;
    }

    bool is_done() override {
        return true;
    }

    void notify_remove(Component<T>* item) override {}

    Component<T>* get_owner() override {
        return nullptr;
    }
};

#endif  // NULL_ITERATOR_H_
