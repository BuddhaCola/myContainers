#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"
//#include "/Users/wtaylor/Projects/ft_containers_Dinar/vector.hpp"
#include <sstream>

void print_comparisation(std::vector<int>& orig, ft::vector<int>& mine, int i);

//int main() {
//	std::vector<int> orig;
//	ft::vector<int> mine;
//	int limit = 10;
//	print_comparisation(orig, mine, -1);
//	for (int i = 0; i < limit; ++i) {
//		orig.push_back(i);
//		mine.push_back(i);
//		print_comparisation(orig, mine, i);
//	}
//	for (int i = 0; i < limit; ++i) {
//		std::cout << "orig.at(" << i << ") = " << orig.at(i) << ' ';
//	}
//	std::cout << std::endl;
//	for (int i = 0; i < limit; ++i) {
//		std::cout << "mine.at(" << i << ") = " << mine.at(i) << ' ';
//	}
//	std::cout << std::endl;
//	try {
//		std::cout << "orig.at(" << limit + 1 << ")" << orig.at(limit + 1) << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << "mine.at(" << limit + 1 << ")" << mine.at(limit + 1) << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << "orig.data() = " << *orig.data() << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << "mine.data() = " << *mine.data() << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << "orig.data() + " << limit / 2 << " = " << *orig.data() + limit / 2 << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	try {
//		std::cout << "mine.data() + " << limit / 2 << " = " << *mine.data() + limit / 2 << std::endl;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//	std::cout << "reserve(9900 * 10000)" << std::endl << "-------" << std::endl;
//	orig.reserve(9900 * 10000);
//	mine.reserve(9900 * 10000);
//	print_comparisation(orig, mine, -1);
//	std::cout << "shrink_to_fit()" << std::endl << "-------" << std::endl;
//	orig.shrink_to_fit();
//	mine.shrink_to_fit();
//	print_comparisation(orig, mine, -1);
//	std::cout << "clear()" << std::endl << "-------" << std::endl;
//	orig.clear();
//	mine.clear();
//	print_comparisation(orig, mine, -1);
//	for (int i = 0; i < limit; ++i) {
//		orig.push_back(i);
//		mine.push_back(i);
//		print_comparisation(orig, mine, i);
//	}
//	std::cout << "resize(1000)" << std::endl << "-------" << std::endl;
//	orig.resize(limit / 2);
//	mine.resize(limit / 2);
//	print_comparisation(orig, mine, -1);
//	std::cout << "reserve(1100)" << std::endl << "-------" << std::endl;
//	orig.reserve(1100);
//	mine.reserve(1100);
//	print_comparisation(orig, mine, -1);
//}

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

#include "/Users/wtaylor/Projects/ft_containers-unit-test/sources/system/system_methods.ipp"
#include "/Users/wtaylor/Projects/ft_containers-unit-test/sources/vector_tests/__service.ipp"
#include "/Users/wtaylor/Projects/ft_containers-unit-test/config.hpp"
template <typename T>
std::vector<int> constructor_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp0(vector);
	std::vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
	tmp = tmp2;
	std::vector<int> tmp3(tmp);
	g_start1 = timer();
	std::vector<int> tmp4(tmp.begin(), tmp.end());
	g_end1 = timer();
	v.push_back(tmp4.size());
	v.push_back(tmp4.capacity());
	v.push_back(tmp[2]);
	v.push_back(tmp3[2]);
	v.push_back(tmp4[2]);
	try { std::vector<int> tmp5(-1, -1); }
	catch (std::exception &e) { v.push_back(1); }
	return v;
}

template <typename T>
std::vector<int> constructor_test(_vector<T> vector) {
	std::vector<int> v;
	_vector<int> tmp0(vector);
	_vector<int> tmp(1000 * _ratio, 4), tmp2(1000 * _ratio, 5);
	tmp = tmp2;
	_vector<int> tmp3(tmp);
	g_start2 = timer();
	_vector<int> tmp4(tmp.begin(), tmp.end());
	g_end2 = timer();
	v.push_back(tmp4.size());
	v.push_back(tmp4.capacity());
	v.push_back(tmp[2]);
	v.push_back(tmp3[2]);
	v.push_back(tmp4[2]);
	try { _vector<int> tmp5(-1, -1); }
	catch (std::exception &e) { v.push_back(1); }
	return v;
}

int main() {

	exit(run_vector_unit_test<int>("constructor", constructor_test, constructor_test));
}