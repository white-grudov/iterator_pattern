#pragma once

// NVI for the iterators
template<typename T>
class Iterator
{
public:
	Iterator() {}
	virtual ~Iterator() = default;
	Iterator<T>& clone() { return doClone(); }

	// start the iteration
	void begin() { return doBegin(); }
	// go to next element
	void next() { return doNext(); }
	// check if at the end
	bool end() const { return doEnd(); }
	// the same as next()
	const Iterator<T>& operator++() { return doAdd(); }
	// current element selector via iterator dereferencing
	const T& operator*() const { return doDereference(); }
	// current element modificator via iterator dereferencing
	T& operator*() { return doDereference(); }

private:
	virtual Iterator<T>& doClone() = 0;
	virtual void doBegin() = 0;
	virtual void doNext() = 0;
	virtual bool doEnd() const = 0;
	virtual const Iterator<T>& doAdd() = 0;
	virtual const T& doDereference() const = 0;
	virtual T& doDereference() = 0;

	Iterator(const Iterator&) = delete;
	Iterator& operator=(const Iterator&) = delete;
};