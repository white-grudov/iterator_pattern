#pragma once

// NVI for the collections
template <typename T>
class Container
{
public:
	Container() {}
	virtual ~Container() = default;

	Container& add(const T& item) { return doAdd(item); }
	void remove() { return doRemove(); }
	int size() { return doSize(); }
	bool isEmpty() { return doIsEmpty(); }

private:
	virtual Container& doAdd(const T& item) = 0;
	virtual void doRemove() = 0;
	virtual int doSize() const = 0;
	virtual bool doIsEmpty() const = 0;

	Container(const Container&) = delete;
	Container& operator=(const Container&) = delete;
};
