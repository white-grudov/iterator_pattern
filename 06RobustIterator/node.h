#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node {
public:
    explicit Node(T* data_) : data(data_) {}
    ~Node() = default;

    T* data;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
};

#endif  // NODE_H_
