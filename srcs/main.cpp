#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"
#include <vector>
#include <sys/time.h>
#include <sstream>

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
	ft::swap(vector, tmp2);
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

int main() {
//	ft::stack<int> lol;
//	int count = 1000;
//	for (int i = 0; i < count; ++i) {
//		lol.push(i * -100);
////		std::cout << lol.top() << std::endl;
//	}
//	ft::stack<int> wow(lol);
//	for (int i = 0; i < lol.size(); ++i) {
//		std::cout << wow.top() << std::endl;

	std::vector<int> res = swap_test();
	std::vector<int> res_std = swap_test_std();
	bool o = res == res_std;
	std::string lol;
	std::string wow;
	for (size_t i = 0; i < res.size(); ++i) {
		lol += std::to_string(res[i]) += ' ';
	}
	for (size_t i = 0; i < res_std.size(); ++i) {
		wow += std::to_string(res_std[i]) += ' ';
	}
	std::cout << lol << std::endl;
	std::cout << wow << std::endl;
	bool wtf = lol == wow;
	std::cout << wtf << std::endl;
//	std::cout << o << std::endl;
//	std::cout << res << std::endl;
}