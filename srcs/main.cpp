#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"
//#include "/Users/wtaylor/Projects/ft_containers_Dinar/vector.hpp"
#include <sstream>

void print_comparisation(std::vector<int>& orig, ft::vector<int>& mine, int i);

int main() {
	std::vector<int> orig;
	ft::vector<int> mine;
	int limit = 10;
	print_comparisation(orig, mine, -1);
	for (int i = 0; i < limit; ++i) {
		orig.push_back(i);
		mine.push_back(i);
		print_comparisation(orig, mine, i);
	}
	orig.clear();
	mine.clear();
	std::cout << "after clear()" << std::endl << "-------" << std::endl;
	print_comparisation(orig, mine, -1);
	for (int i = 0; i < limit; ++i) {
		orig.push_back(i);
		mine.push_back(i);
		print_comparisation(orig, mine, i);
	}
}

template <class T>std::string result(std::vector<T> v, int i) {
	std::stringstream  stream;
	size_t size = v.size();
	stream << "size() = " << size;
//	size_t capacity = v.capacity();
//	stream << " capacity() = " << capacity;
	size_t max_size = v.max_size();
	stream << " max_size()" << max_size;
	if (i >= 0) {
		T q = v[i];
		stream << " [" << i << "] = " << q;
	}
	stream << std::endl;
	return stream.str();
}

template <class T>std::string result(ft::vector<T> &v, int i) {
	std::stringstream  stream;
	size_t size = v.size();
	stream << "size() = " << size;
//	size_t capacity = v.capacity();
//	stream << " capacity() = " << capacity;
	size_t max_size = v.max_size();
	stream << " max_size()" << max_size;
	if (i >= 0) {
		T q = v[i];
		stream << " [" << i << "] = " << q;
	}
	stream << std::endl;
	return stream.str();
}

void print_comparisation(std::vector<int>& orig, ft::vector<int>& mine, int i) {
	std::string std_result = result(orig, i);
	std::string ft_result = result(mine, i);
	if (std_result != ft_result)
		std::cout << "std " << std_result << "ft " << ft_result;
}
