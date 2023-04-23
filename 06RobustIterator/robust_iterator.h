#ifndef ROBUST_ITERATOR_H_
#define ROBUST_ITERATOR_H_

template <typename T>
class RobustIterator : public Iterator<T> {
public:
    RobustIterator() = default;
    virtual ~RobustIterator() = default;

    virtual Component<T>* next() = 0;
    virtual bool is_done() = 0;
    virtual void notify_remove(Component<T>* item) = 0;

    void set_owner(Component<T>* owner_) {
        owner = owner_;
    }

    virtual Component<T>* get_owner() {
        return owner;
    }

    virtual void unsubscribe() {
        if (owner->is_composite()) {
            auto group = (Group<T>*)owner;
            group->unsubscribe(this);
        }
    }

private:
    Component<T>* owner = nullptr;
};

#endif  // ROBUST_ITERATOR_H_
