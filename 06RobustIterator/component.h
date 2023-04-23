#ifndef COMPONENT_H_
#define COMPONENT_H_

template <typename T>
class Iterator;

template <typename T>
class Component {
public:
    Component() = default;
    virtual ~Component() = default;

    virtual Iterator<T>* create_iterator() = 0;
    virtual bool is_composite() = 0;
    virtual std::string to_string() = 0;
};

#endif  // COMPONENT_H_
