#ifndef MYCONTAINERS_TEST_H
#define MYCONTAINERS_TEST_H

#include <array>
#include <vector>
#include <sys/time.h>
#include <stack>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../srcs/containers/vector.h"
#include "../srcs/containers/stack.h"

#define LIMIT 100

class Test {
protected:
	time_t timer() {
		struct timeval start = {};
		gettimeofday(&start, nullptr);
		time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
		return msecs_time;
	}

public:
	time_t start;
	time_t end;

	virtual void run_all_tests() {}

	void print_results(std::vector<int> &std_result, std::vector<int> &ft_result) {
		std::cout << "std:";
		for (int & it : std_result) {
			std::cout << it << '|';
		}
		std::cout << std::endl  << "ft :";
		for (int & it : ft_result) {
			std::cout << it << '|';
		}
		std::cout << std::endl;
	}

	void run_test(std::vector<int> test_ft(), std::vector<int> test_std(), std::string test_name) {
		std::cout << std::left << std::setw(20) << test_name << "|";
		set_start();
		std::vector<int> ft_result = test_ft();
		set_end();
		get_time_result();
		std::cout << "ft time " << std::setw(4) << end - start << '|';
		set_start();
		std::vector<int> std_result = test_std();
		set_end();
		get_time_result();
		std::cout << "std time " << std::setw(4) << end - start;
		std::cout << "|result comparisation: " << (ft_result == std_result ? "✅ " : "❌ ") << std::endl;
		print_results(std_result, ft_result);
	}
private:
	void set_start() {
		start = timer();
	}
	void set_end() {
		end = timer();
	}
	time_t get_time_result() const {
		return end - start;
	}
};
class Vector_Test : Test {
private:
	static std::vector<int> test_at_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> result;
		vector.assign(9900 * limit, 1);
		result.push_back(vector.at(354 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_at_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> result;
		vector.assign(9900 * limit, 1);
		result.push_back(vector.at(354 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_assign_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> result;
		std::vector<int> tmp, tmp2;
		vector.assign(3, 3);
		tmp.assign(4000 * limit, 1);
		tmp2.assign(4 * limit, 1);
		vector.assign(tmp.begin(), tmp.end());
		result.push_back(vector[1]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.assign(tmp2.begin(), tmp2.end());
		result.push_back(vector[444]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_assign_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> result;
		std::vector<int> tmp, tmp2;
		vector.assign(3, 3);
		tmp.assign(4000 * limit, 1);
		tmp2.assign(4 * limit, 1);
		vector.assign(tmp.begin(), tmp.end());
		result.push_back(vector[1]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.assign(tmp2.begin(), tmp2.end());
		result.push_back(vector[444]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_back_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> result;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.back());
		for (int i = limit; i < limit * 2; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.back());
		return result;
	}

	static std::vector<int> test_back_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> result;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.back());
		for (int i = limit; i < limit * 2; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.back());
		return result;
	}

	static std::vector<int> test_begin_std() {
		std::vector<int> vector;
		std::vector<int> result;
		vector.assign(1000, 1);
		result.push_back(*vector.begin());
		result.push_back(*++vector.begin());
		return result;
	}

	static std::vector<int> test_begin_ft() {
		ft::vector<int> vector;
		std::vector<int> result;
		vector.assign(1000, 1);
		result.push_back(*vector.begin());
		result.push_back(*++vector.begin());
		return result;
	}

	static std::vector<int> test_push_back_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		std::vector<int> result;
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		result.push_back(vector.back());
		return result;
	}

	static std::vector<int> test_push_back_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		std::vector<int> result;
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		result.push_back(vector.back());
		return result;
	}

	static std::vector<int> test_capacity_std() {
		std::vector<int> vector;
		std::vector<int> result;
		result.push_back(vector.capacity());
		vector.reserve(999);
		result.push_back(vector.capacity());
		vector.reserve(999);
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_capacity_ft() {
		ft::vector<int> vector;
		std::vector<int> result;
		result.push_back(vector.capacity());
		vector.reserve(999);
		result.push_back(vector.capacity());
		vector.reserve(999);
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_clear_std() {
		std::vector<int> result;
		std::vector<int> vector;
		int limit = LIMIT;
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.assign(limit, 42);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.clear();
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_clear_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		int limit = LIMIT;
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.assign(limit, 42);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		vector.clear();
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_constructor_std_iterators_std() {
		int limit = LIMIT;
		std::vector<int> result;
		std::vector<int> vector;
		vector.assign(3, 3);
		ft::vector<int> tmp(5, 42);
		ft::vector<int> tmp2(tmp.begin(), tmp.end());
		result.push_back(tmp2.size());
		result.push_back(tmp2.capacity());
		for (size_t i = 0; i < tmp.size(); ++i)
			result.push_back(tmp2[i]);
		return result;
	}

	static std::vector<int> test_constructor_std_iterators_ft() {
		int limit = LIMIT;
		std::vector<int> result;
		ft::vector<int> vector;
		vector.assign(3, 3);
		ft::vector<int> tmp(5, 42);
		ft::vector<int> tmp2(tmp.begin(), tmp.end());
		result.push_back(tmp2.size());
		result.push_back(tmp2.capacity());
		for (size_t i = 0; i < tmp.size(); ++i)
			result.push_back(tmp2[i]);
		return result;
	}

	static std::vector<int> test_constructor_std() {
		int limit = LIMIT;
		std::vector<int> result;
		std::vector<int> vector;
		std::vector<int> tmp0(vector);
		std::vector<int> tmp(1000 * limit, 4), tmp2(1000 * limit, 5);
		tmp = tmp2;
		std::vector<int> tmp3(tmp);
		std::vector<int> tmp4(tmp.begin(), tmp.end());
		result.push_back(tmp4.size());
		result.push_back(tmp4.capacity());
		result.push_back(tmp[2]);
		result.push_back(tmp3[2]);
		result.push_back(tmp4[2]);
		try { std::vector<int> tmp5(-1, -1); }
		catch (std::exception &e) { result.push_back(1); }
		return result;
	}

	static std::vector<int> test_constructor_ft() {
		int limit = LIMIT;
		std::vector<int> result;
		ft::vector<int> vector;
		ft::vector<int> tmp0(vector);
		ft::vector<int> tmp(1000 * limit, 4), tmp2(1000 * limit, 5);
		tmp = tmp2;
		ft::vector<int> tmp3(tmp);
		ft::vector<int> tmp4(tmp.begin(), tmp.end());
		result.push_back(tmp4.size());
		result.push_back(tmp4.capacity());
		result.push_back(tmp[2]);
		result.push_back(tmp3[2]);
		result.push_back(tmp4[2]);
		try { std::vector<int> tmp5(-1, -1); }
		catch (std::exception &e) { result.push_back(1); }
		return result;
	}

	static std::vector<int> test_data_std() {
		std::vector<int> result;
		std::vector<int> vector (42);
		int* p = vector.data();
		*p = 10;
		++p;
		*p = 20;
		p[2] = 100;
		for (unsigned i=0; i < vector.size(); ++i)
			result.push_back(vector[i]);
		return result;
	}

	static std::vector<int> test_data_ft() {
		std::vector<int> result;
		ft::vector<int> vector (42);
		int* p = vector.data();
		*p = 10;
		++p;
		*p = 20;
		p[2] = 100;
		for (unsigned i=0; i < vector.size(); ++i)
			result.push_back(vector[i]);
		return result;
	}

	static std::vector<int> test_empty_std() {
		std::vector<int> result;
		std::vector<int> vector;
		result.push_back(vector.empty());
		vector.assign(42, 42);
		result.push_back(vector.empty());
		return result;
	}

	static std::vector<int> test_empty_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		result.push_back(vector.empty());
		vector.assign(42, 42);
		result.push_back(vector.empty());
		return result;
	}

	static std::vector<int> test_end_std() {
		std::vector<int> result;
		std::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(*(vector.end() - 1));
		result.push_back(*(vector.end() - 2));
		return result;
	}

	static std::vector<int> test_end_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(*(vector.end() - 1));
		result.push_back(*(vector.end() - 2));
		return result;
	}

	static std::vector<int> test_erase_range_std() {
		int limit = LIMIT;
		std::vector<int> result;
		std::vector<int> vector;
		vector.assign(4242 * limit, 42);
		result.push_back(*(vector.erase(vector.begin() + 8 * limit, vector.end() - 42 * limit)));
		result.push_back(*(vector.begin() + 42 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		result.push_back(*(vector.erase(vector.begin() + 8 * limit)));
		result.push_back(*(vector.begin() + 42 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_erase_range_ft() {
		int limit = LIMIT;
		std::vector<int> result;
		ft::vector<int> vector;
		vector.assign(4242 * limit, 42);
		result.push_back(*(vector.erase(vector.begin() + 8 * limit, vector.end() - 42 * limit)));
		result.push_back(*(vector.begin() + 42 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		result.push_back(*(vector.erase(vector.begin() + 8 * limit)));
		result.push_back(*(vector.begin() + 42 * limit));
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_front_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> result;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.front());
		for (int i = limit; i < limit * 2; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.front());
		return result;
	}

	static std::vector<int> test_front_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> result;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.front());
		for (int i = limit; i < limit * 2; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.front());
		return result;
	}

	static std::vector<int> test_insert_std() {
		int limit = LIMIT;
		std::vector<int> result;
		std::vector<int> vector;
		vector.assign(1000, 1);
		vector.insert(vector.end() - 50, 4200 * limit , 2);
		result.push_back(vector[2121]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_insert_ft() {
		int limit = LIMIT;
		std::vector<int> result;
		ft::vector<int> vector;
		vector.assign(1000, 1);
		vector.insert(vector.end() - 50, 4200 * limit , 2);
		result.push_back(vector[2121]);
		result.push_back(vector.size());
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_max_size_std() {
		std::vector<int> result;
		std::vector<int> vector;
		vector.assign(1, 42);
		result.push_back(vector.max_size());
		return result;
	}

	static std::vector<int> test_max_size_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		vector.assign(1, 42);
		result.push_back(vector.max_size());
		return result;
	}

	static std::vector<int> test_pop_back_std() {
		std::vector<int> result;
		std::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[vector.back()]);
		vector.pop_back();
		result.push_back(vector[vector.back()]);
		return result;
	}

	static std::vector<int> test_pop_back_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[vector.back()]);
		vector.pop_back();
		result.push_back(vector[vector.back()]);
		return result;
	}

	static std::vector<int> test_rbegin_std() {
		std::vector<int> result;
		std::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[*vector.rbegin()]);
		vector.pop_back();
		result.push_back(vector[*vector.rbegin()]);
		return result;
	}

	static std::vector<int> test_rbegin_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[*vector.rbegin()]);
		vector.pop_back();
		result.push_back(vector[*vector.rbegin()]);
		return result;
	}

	static std::vector<int> test_rend_std() {
		std::vector<int> result;
		std::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[*vector.rend()]);
		return result;
	}

	static std::vector<int> test_rend_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		for (int i = 0; i < 10; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[*vector.rend()]);
		return result;
	}

	static std::vector<int> test_reserve_std() {
		std::vector<int> result;
		std::vector<int> vector;
		result.push_back(vector.capacity());
		vector.reserve(42);
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_reserve_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		result.push_back(vector.capacity());
		vector.reserve(42);
		result.push_back(vector.capacity());
		return result;
	}

	static std::vector<int> test_resize_std() {
		std::vector<int> result;
		std::vector<int> vector;
		vector.assign(42, 42);
		result.push_back(vector.size());
		vector.resize(1000);
		result.push_back(vector.size());
		vector.resize(42);
		result.push_back(vector.size());
		return result;
	}

	static std::vector<int> test_resize_ft() {
		std::vector<int> result;
		ft::vector<int> vector;
		vector.assign(42, 42);
		result.push_back(vector.size());
		vector.resize(1000);
		result.push_back(vector.size());
		vector.resize(42);
		result.push_back(vector.size());
		return result;
	}

	static std::vector<int> test_size_std() {
		std::vector<int> result;
		int limit = LIMIT;
		std::vector<int> vector;
		result.push_back(vector.size());
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.size());
		vector.clear();
		result.push_back(vector.size());
		return result;
	}

	static std::vector<int> test_size_ft() {
		std::vector<int> result;
		int limit = LIMIT;
		ft::vector<int> vector;
		result.push_back(vector.size());
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector.size());
		vector.clear();
		result.push_back(vector.size());
		return result;
	}

	static std::vector<int> test_swap_std() {
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		vector1.assign(100, 42);
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		vector2.swap(vector1);
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		return result;
	}

	static std::vector<int> test_swap_ft() {
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		vector1.assign(100, 42);
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		vector2.swap(vector1);
		result.push_back(vector1.size());
		result.push_back(vector1.capacity());
		result.push_back(vector2.size());
		result.push_back(vector2.capacity());
		return result;
	}

	static std::vector<int> test_iterator_std() {
		std::vector<int> result;
		std::vector<int>::iterator it;
		std::vector<int> vector;
		for (int i = 0; i < 42; ++i)
			vector.push_back(i);
		it = vector.begin();
		result.push_back(*(++it));
		result.push_back(*(--it));
		result.push_back(*(it + 1));
		it += 1;
		result.push_back(*(it - 1));
		it -= 1;
		result.push_back(*it);
		return result;
	}

	static std::vector<int> test_iterator_ft() {
		std::vector<int> result;
		ft::vector<int>::iterator it;
		ft::vector<int> vector;
		for (int i = 0; i < 42; ++i)
			vector.push_back(i);
		it = vector.begin();
		result.push_back(*(++it));
		result.push_back(*(--it));
		result.push_back(*(it + 1));
		it += 1;
		result.push_back(*(it - 1));
		it -= 1;
		result.push_back(*it);
		return result;
	}

	static std::vector<int> test_operator_not_equal_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 42; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector1 != vector2);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 != vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 != vector5);
		return result;
	}

	static std::vector<int> test_operator_not_equal_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 42; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector1 != vector2);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 != vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 != vector5);
		return result;
	}

	static std::vector<int> test_operator_less_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 < vector1);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 < vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 < vector5);
		return result;
	}


	static std::vector<int> test_operator_less_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 < vector1);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 < vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 < vector5);
		return result;
	}

	static std::vector<int> test_operator_less_equal_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 <= vector1);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 <= vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 <= vector5);
		return result;
	}

	static std::vector<int> test_operator_less_equal_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 <= vector1);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 <= vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 <= vector5);
		return result;
	}

	static std::vector<int> test_operator_equal_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 42; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector1 == vector2);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 == vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 == vector5);
		return result;
	}

	static std::vector<int> test_operator_equal_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 42; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector1 == vector2);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 == vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 == vector5);
		return result;
	}

	static std::vector<int> test_operator_more_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 > vector1);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 > vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 > vector5);
		return result;
	}

	static std::vector<int> test_operator_more_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 > vector1);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 > vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 > vector5);
		return result;
	}

	static std::vector<int> test_operator_more_equal_std(){
		std::vector<int> result;
		std::vector<int> vector1;
		std::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 >= vector1);
		std::vector<int> vector3(vector1);
		result.push_back(vector1 >= vector3);
		std::vector<int> vector4(vector1);
		std::vector<int> vector5(vector1);
		result.push_back(vector4 >= vector5);
		return result;
	}

	static std::vector<int> test_operator_more_equal_ft(){
		std::vector<int> result;
		ft::vector<int> vector1;
		ft::vector<int> vector2;
		for (int i = 0; i < 42; ++i) {
			vector1.push_back(i);
		}
		for (int i = 0; i < 24; ++i) {
			vector2.push_back(i * -1);
		}
		result.push_back(vector2 >= vector1);
		ft::vector<int> vector3(vector1);
		result.push_back(vector1 >= vector3);
		ft::vector<int> vector4(vector1);
		ft::vector<int> vector5(vector1);
		result.push_back(vector4 >= vector5);
		return result;
	}

	static std::vector<int> test_operator_angle_braces_std(){
		std::vector<int> result;
		std::vector<int> vector;
		for (int i = 0; i < 42; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[0]);
		result.push_back(vector[42 - 1]);
		result.push_back(vector[24]);
		return result;
	}

	static std::vector<int> test_operator_angle_braces_ft(){
		std::vector<int> result;
		ft::vector<int> vector;
		for (int i = 0; i < 42; ++i) {
			vector.push_back(i);
		}
		result.push_back(vector[0]);
		result.push_back(vector[42 - 1]);
		result.push_back(vector[24]);
		return result;
	}

public:
	void run_all_tests() {
		run_test(test_assign_ft, test_assign_std , "assign()");
		run_test(test_at_ft, test_at_std , "at()");
		run_test(test_back_ft, test_back_std , "back()");
		run_test(test_begin_ft, test_begin_std , "begin()");
		run_test(test_push_back_ft, test_push_back_std , "push_back()");
		run_test(test_capacity_ft, test_capacity_std , "capacity()");
		run_test(test_clear_ft, test_clear_std , "clear()");
		run_test(test_constructor_std_iterators_ft, test_constructor_std_iterators_std , "constructor(std_it)");
		run_test(test_constructor_ft, test_constructor_std , "constructor");
		run_test(test_data_ft, test_data_std , "data()");
		run_test(test_empty_ft, test_empty_std , "empty()");
		run_test(test_end_ft, test_end_std , "end()");
		run_test(test_erase_range_ft, test_erase_range_std , "erase() (range)");
		run_test(test_front_ft, test_front_std , "front()");
		run_test(test_insert_ft, test_insert_std , "insert()");
		run_test(test_max_size_ft, test_max_size_std , "max_size()");
		run_test(test_pop_back_ft, test_pop_back_std , "pop_back()");
		run_test(test_rbegin_ft, test_rbegin_std , "rbegin()");
		run_test(test_rend_ft, test_rend_std , "rend()");
		run_test(test_reserve_ft, test_reserve_std , "reserve()");
		run_test(test_resize_ft, test_resize_std , "resize()");
		run_test(test_size_ft, test_size_std , "size()");
		run_test(test_swap_ft, test_swap_std , "swap()");
		run_test(test_iterator_ft, test_iterator_std , "iterator");
		run_test(test_operator_not_equal_ft, test_operator_not_equal_std , "operator !=");
		run_test(test_operator_less_ft, test_operator_less_std , "operator <");
		run_test(test_operator_less_equal_ft, test_operator_less_equal_std , "operator <=");
		run_test(test_operator_equal_ft, test_operator_equal_std , "operator ==");
		run_test(test_operator_more_ft, test_operator_more_std , "operator >");
		run_test(test_operator_more_equal_ft, test_operator_more_equal_std , "operator >=");
		run_test(test_operator_angle_braces_ft, test_operator_angle_braces_std , "operator []");
	}
};

class Stack_Test : Test {
private:
	static std::vector<int> test_constructor_ft() {
		std::vector<int>	result;
		int limit = LIMIT;
		ft::vector<int>		vector;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		ft::vector<int>		vector2;
		for (int i = 0; i < limit; ++i) {
			vector2.push_back(i);
		}
		ft::stack<int>		stack1(vector);
		ft::stack<int>		stack2(stack1);
		result.push_back(stack1.size());
		result.push_back(stack1.top());
		stack1.pop();
		result.push_back(stack1.top());
		result.push_back(stack2.size());
		result.push_back(stack2.top());
		stack2.pop();
		result.push_back(stack2.top());
		return result;
	}

	static std::vector<int> test_constructor_std() {
		std::vector<int>	result;
		int limit = LIMIT;
		std::deque<int>		deque;
		for (int i = 0; i < limit; ++i) {
			deque.push_back(i);
		}
		std::vector<int>		vector2;
		for (int i = 0; i < limit; ++i) {
			vector2.push_back(i);
		}
		std::stack<int>		stack1(deque);
		std::stack<int>		stack2(stack1);
		result.push_back(stack1.size());
		result.push_back(stack1.top());
		stack1.pop();
		result.push_back(stack1.top());
		result.push_back(stack2.size());
		result.push_back(stack2.top());
		stack2.pop();
		result.push_back(stack2.top());
		return result;
	}

	static std::vector<int> test_empty_ft() {
		std::vector<int>	result;
		ft::stack<int>		stack;
		result.push_back(stack.empty());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.empty());
		result.push_back(stack.top());
		while (!stack.empty()) {
			stack.pop();
		}
		result.push_back(stack.empty());
		return result;
	}

	static std::vector<int> test_empty_std() {
		std::vector<int>	result;
		std::stack<int>		stack;
		result.push_back(stack.empty());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.empty());
		result.push_back(stack.top());
		while (!stack.empty()) {
			stack.pop();
		}
		result.push_back(stack.empty());
		return result;
	}

	static std::vector<int> test_pop_ft() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		ft::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < limit; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		for (int i = 0; i < limit / 2; ++i) {
			stack.pop();
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		while (!stack.empty()) {
			stack.pop();
		}
		result.push_back(stack.size());
		return result;
	}

	static std::vector<int> test_pop_std() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		std::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < limit; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		for (int i = 0; i < limit / 2; ++i) {
			stack.pop();
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		while (!stack.empty()) {
			stack.pop();
		}
		result.push_back(stack.size());
		return result;
	}

	static std::vector<int> test_push_ft() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		ft::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < limit; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		return result;
	}

	static std::vector<int> test_push_std() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		std::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < limit; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		result.push_back(stack.top());
		return result;
	}

	static std::vector<int> test_size_ft() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		ft::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		return result;
	}

	static std::vector<int> test_size_std() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		std::stack<int>		stack;
		result.push_back(stack.size());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.size());
		return result;
	}

	static std::vector<int> test_top_ft() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		ft::stack<int>		stack;
		stack.push(stack.size());
		result.push_back(stack.top());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.top());
		for (int i = 0; i < 42; ++i) {
			stack.push(i * -1);
		}
		result.push_back(stack.top());
		return result;
	}

	static std::vector<int> test_top_std() {
		std::vector<int>	result;
		int 				limit = LIMIT;
		std::stack<int>		stack;
		stack.push(stack.size());
		result.push_back(stack.top());
		for (int i = 0; i < 42; ++i) {
			stack.push(i);
		}
		result.push_back(stack.top());
		for (int i = 0; i < 42; ++i) {
			stack.push(i * -1);
		}
		result.push_back(stack.top());
		return result;
	}
		static std::vector<int> test_operator_less_ft() {
			std::vector<int>	result;
			ft::stack<int>		stack1;
			ft::stack<int>		stack2;
			result.push_back(stack1 < stack2);
			stack2.push(42);
			result.push_back(stack1 < stack2);
			stack1.push(42);
			result.push_back(stack1 < stack2);
			return result;
	}
		static std::vector<int> test_operator_less_std() {
			std::vector<int>	result;
			std::stack<int>		stack1;
			std::stack<int>		stack2;
			result.push_back(stack1 < stack2);
			stack2.push(42);
			result.push_back(stack1 < stack2);
			stack1.push(42);
			result.push_back(stack1 < stack2);
			return result;
	}
		static std::vector<int> test_operator_less_equal_ft() {
			std::vector<int>	result;
			ft::stack<int>		stack1;
			ft::stack<int>		stack2;
			result.push_back(stack1 <= stack2);
			stack2.push(42);
			result.push_back(stack1 <= stack2);
			stack1.push(42);
			result.push_back(stack1 <= stack2);
			return result;
	}
		static std::vector<int> test_operator_less_equal_std() {
			std::vector<int>	result;
			std::stack<int>		stack1;
			std::stack<int>		stack2;
			result.push_back(stack1 <= stack2);
			stack2.push(42);
			result.push_back(stack1 <= stack2);
			stack1.push(42);
			result.push_back(stack1 <= stack2);
			return result;
	}
		static std::vector<int> test_operator_equal_ft() {
			std::vector<int>	result;
			ft::stack<int>		stack1;
			ft::stack<int>		stack2;
			result.push_back(stack1 == stack2);
			stack2.push(42);
			result.push_back(stack1 == stack2);
			stack1.push(42);
			result.push_back(stack1 == stack2);
			return result;
	}
		static std::vector<int> test_operator_equal_std() {
			std::vector<int>	result;
			std::stack<int>		stack1;
			std::stack<int>		stack2;
			result.push_back(stack1 == stack2);
			stack2.push(42);
			result.push_back(stack1 == stack2);
			stack1.push(42);
			result.push_back(stack1 == stack2);
			return result;
	}
		static std::vector<int> test_operator_more_ft() {
			std::vector<int>	result;
			ft::stack<int>		stack1;
			ft::stack<int>		stack2;
			result.push_back(stack1 > stack2);
			stack2.push(42);
			result.push_back(stack1 > stack2);
			stack1.push(42);
			result.push_back(stack1 > stack2);
			return result;
	}
		static std::vector<int> test_operator_more_std() {
			std::vector<int>	result;
			std::stack<int>		stack1;
			std::stack<int>		stack2;
			result.push_back(stack1 > stack2);
			stack2.push(42);
			result.push_back(stack1 > stack2);
			stack1.push(42);
			result.push_back(stack1 > stack2);
			return result;
	}
		static std::vector<int> test_operator_more_equal_ft() {
			std::vector<int>	result;
			ft::stack<int>		stack1;
			ft::stack<int>		stack2;
			result.push_back(stack1 >= stack2);
			stack2.push(42);
			result.push_back(stack1 >= stack2);
			stack1.push(42);
			result.push_back(stack1 >= stack2);
			return result;
	}
		static std::vector<int> test_operator_more_equal_std() {
			std::vector<int>	result;
			std::stack<int>		stack1;
			std::stack<int>		stack2;
			result.push_back(stack1 >= stack2);
			stack2.push(42);
			result.push_back(stack1 >= stack2);
			stack1.push(42);
			result.push_back(stack1 >= stack2);
			return result;
	}
public:
	void run_all_tests() {
		run_test(test_constructor_ft, test_constructor_std , "constructor()");
		run_test(test_empty_ft, test_empty_std , "empty()");
		run_test(test_pop_ft, test_pop_std , "pop()");
		run_test(test_push_ft, test_push_std , "push()");
		run_test(test_size_ft, test_size_std , "size()");
		run_test(test_top_ft, test_top_std , "top()");
		run_test(test_operator_less_ft, test_operator_less_std , "operator <");
		run_test(test_operator_less_equal_ft, test_operator_less_equal_std , "operator <=");
		run_test(test_operator_equal_ft, test_operator_equal_std , "operator ==");
		run_test(test_operator_more_ft, test_operator_more_std , "operator >");
		run_test(test_operator_more_equal_ft, test_operator_more_equal_std , "operator >=");
}
};
#endif //MYCONTAINERS_TEST_H
