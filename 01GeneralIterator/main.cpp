#include <iostream>
#include <functional>
#include <vector>

#include "Iterator.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "ListIterator.h"
#include "ReversedListIterator.h"

template<typename T>
using Itor = std::unique_ptr<Iterator<T>>;

template<typename T>
void testIterator(Iterator<T>& it, std::function<void(T&)> func) {
	it.begin();
	while (!it.end()) {
		func(*it);
		++it;
	}
}

int main() {
	LinkedList<int> list;
	list.add(1).add(2).add(3).add(4).add(5);
	Itor<int> listItor = list.createIterator();

	std::cout << "Iterate through list with iterator:" << std::endl;
	testIterator<int>(*listItor, [](int x) { std::cout << x << " "; });
	std::cout << std::endl;

	std::cout << "Increase the values by 1:" << std::endl;
	testIterator<int>(*listItor, [](int& x) { std::cout << ++x << " "; });
	std::cout << std::endl;

	Itor<int> reverseItor = std::make_unique<ReverseListIterator<int>>(&list);
	std::cout << "Iterate in inverse order:" << std::endl;
	testIterator<int>(*reverseItor, [](int x) { std::cout << x << " "; });
	std::cout << std::endl;

	ArrayList<char> array;
	array.add('a').add('b').add('c').add('d').add('e');
	Itor<char> arrayItor = array.createIterator();
	std::cout << "Same interface for iterating through array:" << std::endl;
	testIterator<char>(*arrayItor, [](char x) { std::cout << x << " "; });
	std::cout << std::endl;

	Itor<char> newArrayItor = std::unique_ptr<Iterator<char>>(&(arrayItor->clone()));
	std::cout << "Cloned iterator will have the same values:" << std::endl;
	testIterator<char>(*newArrayItor, [](char x) { std::cout << x << " "; });
	std::cout << std::endl;

	array.remove();
	std::cout << "If structure has changed, the iterator changes too:" << std::endl;
	testIterator<char>(*newArrayItor, [](char x) { std::cout << x << " "; });
	std::cout << std::endl;
}