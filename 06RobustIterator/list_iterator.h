#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

template <typename T>
class ListIterator : public Iterator<T> {
public:
    explicit ListIterator(List<T>* list_) : list(list_) {}
    virtual ~ListIterator() = default;

    Component<T>* next() override {
        ++current;
        return (Component<T>*)list->get(current - 1);
    }

    bool is_done() override {
        return current != list->count();
    }

private:
    List<T>* list;
    int current = 0;
};

#endif  // LIST_ITERATOR_H_
