#pragma once
template <typename T>
class Iterator
{
public:
	Iterator() {}
	virtual ~Iterator() = default;

	// for comparing current iterator with end operator
	bool operator!=(const Iterator& other) const { return doNotEqual(other); }
	// get the current item by dereferencing
	T& operator*() const { return doDereference(); }
	// advance to the next value
	Iterator& operator++() { return doIncrement(); }

private:
	virtual bool doNotEqual(const Iterator& other) const = 0;
	virtual T& doDereference() const = 0;
	virtual Iterator& doIncrement() = 0;

	Iterator(const Iterator&) = delete;
	Iterator& operator=(const Iterator&) = delete;
};