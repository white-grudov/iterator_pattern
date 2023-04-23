#pragma once
#include "Component.h"
template <typename T>
class Leaf : public Component<T> {
public:
	explicit Leaf(const T& value) : value(value) {}
	void add(Component<T>* c) override {}
	void remove(Component<T>* c) override {}
	bool isComposite() const override {
		return false;
	}
	T getValue() const override {
		return value;
	}
	// since there are no values to iterate through in leaf,
	// the NullIterator is created
	Iterator<T>* createIterator() {
		return new NullIterator<T>();
	}
private:
	T value;
};