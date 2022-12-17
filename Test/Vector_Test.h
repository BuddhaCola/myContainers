#ifndef MYCONTAINERS_VECTOR_TEST_H
#define MYCONTAINERS_VECTOR_TEST_H

#include "test.h"
#include "../srcs/containers/vector.h"

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
#endif //MYCONTAINERS_VECTOR_TEST_H
