#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> list;
	list.add(1).add(2).add(3).add(4).add(5);

	cout << "Implicit iterator allows for the foreach loop:" << endl;
	for (auto& el : list) {
		cout << el << " ";
	}
	cout << endl;

	cout << "But we can still use the explicit iteration and get the same result:" << endl;
	for (auto it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;
}