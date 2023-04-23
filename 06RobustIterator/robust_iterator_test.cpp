#include <iostream>
#include <memory>
#include <cassert>

#include "iterator.h"

int main() {
    // Create some data components
    auto data1 = new Data<int>(1);
    auto data2 = new Data<int>(2);
    auto data3 = new Data<int>(3);
    auto data4 = new Data<int>(4);

    // Create a group and add the data components to it
    auto group1 = new Group<int>();
    group1->add(data1);
    group1->add(data2);

    // Create another group and add data components to it
    auto group2 = new Group<int>();
    group2->add(data3);
    group2->add(data4);

    // Add the groups to the first group
    group1->add(group2);

    // Create an iterator for the first group
    auto iterator = group1->create_iterator();

    // Iterate over the components in the first group
    while (!iterator->is_done()) {
        auto component = iterator->next();
        std::cout << component->to_string() << std::endl;
    }

    // Remove a data component from the second group
    group2->remove(data3);

    // Iterate over the components in the first group again
    std::cout << std::endl << "After removing data3:" << std::endl;
    iterator = group1->create_iterator();
    while (!iterator->is_done()) {
        auto component = iterator->next();
        std::cout << component->to_string() << std::endl;
    }

    return 0;
}
