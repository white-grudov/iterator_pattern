#ifndef GROUP_H_
#define GROUP_H_

#include <vector>
#include <memory>
#include <algorithm>

template <typename T>
class CompositeIterator;

template <typename T>
class RobustIterator;

template <typename T>
class GroupIterator;

template <typename T>
class List;

template <typename T>
class Group : public Component<T> {
public:
    Group() = default;
    virtual ~Group() = default;

    void add(Component<T>* item) {
        components->add(item);
    }

    void remove(Component<T>* item) {
        for (auto iterator: iterators)
            iterator->notify_remove(item);
        components->remove(item);
    }

    List<Component<T>>* get() {
        return components;
    }

    Iterator<T>* create_iterator() {
        auto iterator(new GroupIterator<T>(this));
        iterators.push_back(iterator);

        auto composite_iterator(new CompositeIterator<T>(iterator));
        iterators.push_back(composite_iterator);

        return composite_iterator;
    }

    virtual bool is_composite() {
        return true;
    }

    virtual std::string to_string() {
        std::string str;
        std::unique_ptr<Iterator<T>> iterator(create_iterator());
        while (!iterator->is_done()) {
            std::unique_ptr<Component<int>> item(iterator->next());
            str += item->to_string();

            if (!iterator->is_done())
                str += " ";
        }
        return str;
    }

    void unsubscribe(RobustIterator<T>* iterator) {
        auto it = std::find(iterators.begin(), iterators.end(), iterator);
        if (it != iterators.end())
            iterators.erase(it);
    }

private:
    List<Component<T>>* components = new List<Component<T>>();
    std::vector<RobustIterator<T>*> iterators;
};

#endif  // GROUP_H_
