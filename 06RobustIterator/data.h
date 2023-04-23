#ifndef DATA_H_
#define DATA_H_

#include <sstream>

template <typename T>
class NullIterator;

template <typename T>
class Data : public Component<T> {
public:
    Data() : data() {};
    explicit Data(T data_) : data(data_) {};
    virtual ~Data() = default;

    Iterator<T>* create_iterator() override {
        return new NullIterator<T>();
    }

    bool is_composite() override {
        return false;
    }

    std::string to_string() override {
        return std::to_string(data);
    }

private:
    T data;
};

#endif  // DATA_H_
