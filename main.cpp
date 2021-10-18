#include <vector>
#include <iostream>
#include "Vector.hpp"

int main () {
	std::vector<int> sampleVector;
	for (std::vector<int>::iterator it = sampleVector.begin(); it != sampleVector.end(); it++) {
		std::cout << *(it) << std::endl;
	}
	ft::Vector<int> test;
	return (0);
}