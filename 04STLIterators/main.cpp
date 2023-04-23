#include <vector>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>

int main() {
	// Implicit and explicit individual iterators, reverse iterator
	{
		std::vector<int> vec({ 1, 2, 3, 4, 5 });
		std::cout << "std::vector can be traversed either with implicit iterator:" << std::endl;
		for (const auto& el : vec) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << "or with individual iterator:" << std::endl;
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "Reverse iterator:" << std::endl;
		for (std::vector<int>::reverse_iterator rIt = vec.rbegin(); rIt != vec.rend(); ++rIt) {
			std::cout << *rIt << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	// Move iterator
	{
		std::list<std::string> li{ "one", "two", "three" };
		std::cout << "List values: " << std::endl;
		for (const auto& el : li) {
			std::cout << el << " ";
		}
		std::cout << std::endl;

		std::vector<std::string> vec(std::make_move_iterator(li.begin()), std::make_move_iterator(li.end()));
		std::cout << "Moved elements from list to vector.\nVector values:" << std::endl;
		for (const auto& el : vec) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << "List values: " << std::endl;
		for (const auto& el : li) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	// Insert iterator
	{
		std::vector<int> vec{ 1,2,3,4,5 };
		std::cout << "Vector values: " << std::endl;
		for (const auto& el : vec) {
			std::cout << el << " ";
		}
		std::cout << std::endl;

		std::list<int> li{ -1,-2,-3 };
		std::cout << "List values: " << std::endl;
		for (const auto& el : li) {
			std::cout << el << " ";
		}
		std::cout << std::endl;

		std::copy(vec.begin(), vec.end(), std::insert_iterator<std::list<int>>(li, ++li.begin()));
		std::cout << "Inserted vector values into list.\nNew list values: " << std::endl;
		for (const auto& el : li) {
			std::cout << el << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	// Stream iterators (input/output)
	{
		std::ifstream input_file("input.txt");

		std::istream_iterator<int> input_begin(input_file);
		std::istream_iterator<int> input_end;

		int sum = std::accumulate(input_begin, input_end, 0);

		std::ostream_iterator<int> output_iterator(std::cout, " ");
		std::cout << "Sum of numbers inside input.txt:" << std::endl;
		*output_iterator++ = sum;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	// Invalidated iterator
	{
		std::vector<int> vec = { 1, 2, 3, 4 };
		auto it = vec.begin();

		// this operation will cause iterator invalidation
		vec.push_back(0);

		// error!
		std::cout << *it << std::endl;
	}

	return 0;
}