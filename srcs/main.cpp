#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"
//#include "/Users/wtaylor/Projects/ft_containers_Dinar/vector.hpp"
#include <vector>
#include <sys/time.h>
#include <sstream>
#include <stack>


int main() {
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	int count = 1000;
	for (int i = 0; i < count; ++i) {
		ft_stack.push(i * 3);
		std_stack.push(i * 3);
	}
//	for (int i = 0; i < count; ++i) {
//		std::cout << "ft [" << i << "] = " << ft_stack.top()  << std::endl;
//		ft_stack.pop();
//		std::cout << "std[" << i << "] = " << std_stack.top()  << std::endl;
//		std_stack.pop();
//	}
	ft::stack<int> lol(ft_stack);
	std::stack<int> laol;
	std::stack<int> lao1l;
	bool iw = laol != lao1l;
	if (!laol.empty())
	try { std::cout << "laol ["  "] = " << laol.top() << std::endl; }
	catch (std::exception &e) {
		e.what();
	}
	if (!lol.empty())
	try { std::cout << "lol ["  "] = " << lol.top() << std::endl; }
	catch (std::exception &e) {
		e.what();
	}
	std::cout << "ft_stack ["  "] = " << ft_stack.top()  << std::endl;
	ft::stack<int> wq;
	bool wow = lol != lol;
	bool woww = lol != ft_stack;
	bool wowww = lol != wq;
}

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

std::vector<int> swap_test_std() {
	std::vector<int> vector;
	int _ratio = 10000;
	time_t g_start1;
	time_t g_end1;
	std::vector<int> v;
	vector.assign(1100 * _ratio, 11);
	std::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
	g_start1 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	long *adr1 = reinterpret_cast<long *>(&vector);
	long *adr2 = reinterpret_cast<long *>(&tmp);
	vector.swap(tmp);
	if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		v.push_back(1);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp3);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp2);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp4);
	g_end1 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

std::vector<int> swap_test() {
	ft::vector<int> vector;
	std::vector<int> v;
	int _ratio = 10000;
	time_t gstart2;
	time_t gend2;
	vector.assign(1100 * _ratio, 11);
	ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
	gstart2 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	long *adr1 = reinterpret_cast<long *>(&vector);
	long *adr2 = reinterpret_cast<long *>(&tmp);
	vector.swap(tmp);
	if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		v.push_back(1);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.swap(tmp3);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp2);
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::swap(vector, tmp4);
	gend2 = timer();
	v.push_back(vector[2]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	std::cout << gend2 - gstart2 << std::endl;
	return v;
}
