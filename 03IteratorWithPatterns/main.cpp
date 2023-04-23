#include <iostream>
#include "Composite.h"
#include "Leaf.h"
#include "CompositeIterator.h"

int main() {
    Composite<int> root(5);
    Composite<int> branch1(6);
    Composite<int> branch2(7);
    Leaf<int> leaf1(1);
    Leaf<int> leaf2(2);
    Leaf<int> leaf3(3);
    Leaf<int> leaf4(4);
    branch1.add(&leaf1);
    branch1.add(&leaf2);
    branch2.add(&leaf3);
    branch2.add(&leaf4);
    root.add(&branch1);
    root.add(&branch2);

    std::cout << "Iterate through values of node and its children:" << std::endl;
    Iterator<int>* iter = root.createIterator();
    for (auto c = iter->getNext(); c != nullptr; c = iter->getNext()) {
        std::cout << c->getValue() << std::endl;
    }

	return 0;
}