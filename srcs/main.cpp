#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"
//#include "/Users/wtaylor/Projects/ft_containers_Dinar/vector.hpp"
#include <sstream>

void print_comparisation(std::vector<int>& orig, ft::vector<int>& mine, int i);

template <typename T>
std::vector<int> reserve_test(ft::vector<T> vector) {
	std::vector<int> v;
//	g_start1 = timer();
	vector.reserve(9900 * 10000);
//	g_end1 = timer();
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

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
	for (int i = 0; i < limit; ++i) {
		std::cout << "orig.at(" << i << ") = " << orig.at(i) << ' ';
	}
	std::cout << std::endl;
	for (int i = 0; i < limit; ++i) {
		std::cout << "mine.at(" << i << ") = " << mine.at(i) << ' ';
	}
	std::cout << std::endl;
	try {
		std::cout << "orig.at(" << limit + 1 << ")" << orig.at(limit + 1) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "mine.at(" << limit + 1 << ")" << mine.at(limit + 1) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "orig.data() = " << *orig.data() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "mine.data() = " << *mine.data() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "orig.data() + " << limit / 2 << " = " << *orig.data() + limit / 2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "mine.data() + " << limit / 2 << " = " << *mine.data() + limit / 2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "reserve(9900 * 10000)" << std::endl << "-------" << std::endl;
	orig.reserve(9900 * 10000);
	mine.reserve(9900 * 10000);
	print_comparisation(orig, mine, -1);
	std::cout << "shrink_to_fit()" << std::endl << "-------" << std::endl;
	orig.shrink_to_fit();
	mine.shrink_to_fit();
	print_comparisation(orig, mine, -1);
	std::cout << "clear()" << std::endl << "-------" << std::endl;
	orig.clear();
	mine.clear();
	print_comparisation(orig, mine, -1);
	for (int i = 0; i < limit; ++i) {
		orig.push_back(i);
		mine.push_back(i);
		print_comparisation(orig, mine, i);
	}
	std::cout << "resize(1000)" << std::endl << "-------" << std::endl;
	orig.resize(limit / 2);
	mine.resize(limit / 2);
	print_comparisation(orig, mine, -1);
	std::cout << "reserve(1100)" << std::endl << "-------" << std::endl;
	orig.reserve(1100);
	mine.reserve(1100);
	print_comparisation(orig, mine, -1);
}

template <class T>std::string result(std::vector<T> v, int i) {
	std::stringstream  stream;
	size_t size = v.size();
	stream << "size() = " << size;
	size_t capacity = v.capacity();
	stream << " capacity() = " << capacity;
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
	size_t capacity = v.capacity();
	stream << " capacity() = " << capacity;
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
//	if (std_result != ft_result)
		std::cout << "std " << std_result << "ft " << ft_result;
}

//Just copy that shit 🤘
//https://cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare
// template <class InputIterator1, class InputIterator2>
//  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
//                                InputIterator2 first2, InputIterator2 last2)
//{
//  while (first1!=last1)
//  {
//    if (first2==last2 || *first2<*first1) return false;
//    else if (*first1<*first2) return true;
//    ++first1; ++first2;
//  }
//  return (first2!=last2);
//}
