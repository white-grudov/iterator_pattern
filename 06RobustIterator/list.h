#ifndef LIST_H_
#define LIST_H_

template <typename T>
class ListIterator;

template <typename T>
class Node;

template <typename T>
class List {
public:
    List() = default;

    ~List() {
        if (pRoot != nullptr) {
            auto tmp(pRoot);
            while (pRoot != nullptr) {
                tmp = pRoot->next;
                delete pRoot;
                pRoot = tmp;
            }
        }
    }

    void add(T* data) {
        auto tmp(new Node<T>(data));
        if (pRoot == nullptr) {
            pRoot = pTail = tmp;
        }
        else {
            tmp->prev = pTail;
            pTail->next = tmp;
            pTail = tmp;
        }
    }

    Node<T>* find(T* data) {
        auto tmp(pRoot);
        while (tmp != nullptr) {
            if (tmp->data == data)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }

    Node<T>* insert(T* key, T* data) {
        auto pKey(find(key));
        if (pKey) {
            auto pNode(new Node<T>(data));
            pNode->next = pKey->next;
            pKey->next = pNode;
            return pNode;
        }
        return nullptr;
    }

    T* get(int key) {
        auto tmp(pRoot);
        int i = 0;
        while (tmp != nullptr) {
            if (i == key)
                break;
            tmp = tmp->next;
            i++;
        }
        return (tmp != nullptr) ? tmp->data : nullptr;
    }

    T* get_prev(T* data) {
        std::unique_ptr<ListIterator<T>> iterator(new ListIterator<T>(this));
        T* prev = nullptr;
        while (!iterator->is_done()) {
            auto current = (T*)(iterator->next());
            if (current == data) {
                return prev;
            }
            prev = current;
        }
        return nullptr;
    }

    T* get_next(T* data) {
        std::unique_ptr<ListIterator<T>> iterator(new ListIterator<T>(this));
        if (data == nullptr) {
            return (iterator->is_done()) ? (T*)(iterator->next()) : nullptr;
        }
        while (iterator->is_done()) {
            auto current = (T*)(iterator->next());
            if (current == data) {
                return (iterator->is_done()) ? (T*)(iterator->next()) : nullptr;
            }
        }
        return nullptr;
    }

    int count() {
        auto tmp = pRoot;
        int count = 0;
        while (tmp != nullptr) {
            ++count;
            tmp = tmp->next;
        }
        return count;
    }

    bool remove(T* data) {
        auto pKey(find(data));
        if (pKey) {
            if (pKey == pRoot)
                pRoot = pKey->next;
            else {
                auto tmp = pRoot;
                while (tmp != nullptr) {
                    if (tmp->next == pKey) {
                        break;
                    }
                    tmp = tmp->next;
                }
                if (tmp) {
                    tmp->next = pKey->next;
                }
            }
            delete pKey;
            return true;
        }
        return false;
    }

private:
    Node<T>* pRoot = nullptr;
    Node<T>* pTail = nullptr;
};

#endif  // LIST_H_
