#ifndef GROUP_ITERATOR_H_
#define GROUP_ITERATOR_H_

template <typename T>
class GroupIterator : public RobustIterator<T> {
public:
    GroupIterator() = default;
    explicit GroupIterator(Group<T>* group) {
        list = group->get();
        RobustIterator<T>::set_owner(group);
    }
    virtual ~GroupIterator() = default;

    bool is_done() override {
        if (list->get_next(current) == nullptr) {
            RobustIterator<T>::unsubscribe();
            return true;
        }
        return false;
    }

    Component<T>* next() override {
        if (is_done()) {
            return nullptr;
        }
        Component<T>* next = list->get_next(current);
        current = next;
        return next;
    }

    void notify_remove(Component<T>* item) override {
        if (current != item) {
            return;
        }
        current = list->get_prev(current);
    }

private:
    List<Component<T>>* list;
    Component<T>* current = nullptr;
};

#endif  // GROUP_ITERATOR_H_
