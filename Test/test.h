#ifndef MYCONTAINERS_TEST_H
#define MYCONTAINERS_TEST_H

#include <array>
#include <vector>
#include <sys/time.h>
#include <stack>
#include <iostream>
#include <sstream>
#include "../srcs/containers/vector.h"

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
	void run_test(std::vector<int> test_ft(), std::vector<int> test_std(), std::string test_name) {
		std::cout << test_name << " |";
		set_start();
		std::vector<int> ft_result = test_ft();
		set_end();
		get_time_result();
		std::cout << "ft time " << end - start << '|';
		set_start();
		std::vector<int> std_result = test_std();
		set_end();
		get_time_result();
		std::cout << "std time " << end - start << '|';
		std::cout << "result comparisation: " << (ft_result == std_result ? "✅ " : "❌ ") << std::endl;
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
		std::vector<int> v;
		vector.assign(9900 * limit, 1);
		v.push_back(vector.at(354 * limit));
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_at_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> v;
		vector.assign(9900 * limit, 1);
		v.push_back(vector.at(354 * limit));
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_assign_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> v;
		std::vector<int> tmp, tmp2;
		vector.assign(3, 3);
		tmp.assign(4000 * limit, 1);
		tmp2.assign(4 * limit, 1);
		vector.assign(tmp.begin(), tmp.end());
		v.push_back(vector[1]);
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		vector.assign(tmp2.begin(), tmp2.end());
		v.push_back(vector[444]);
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_assign_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> v;
		std::vector<int> tmp, tmp2;
		vector.assign(3, 3);
		tmp.assign(4000 * limit, 1);
		tmp2.assign(4 * limit, 1);
		vector.assign(tmp.begin(), tmp.end());
		v.push_back(vector[1]);
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		vector.assign(tmp2.begin(), tmp2.end());
		v.push_back(vector[444]);
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_back_std() {
		int limit = LIMIT;
		std::vector<int> vector;
		std::vector<int> v;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		v.push_back(vector.back());
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_back_ft() {
		int limit = LIMIT;
		ft::vector<int> vector;
		std::vector<int> v;
		for (int i = 0; i < limit; ++i) {
			vector.push_back(i);
		}
		v.push_back(vector.back());
		v.push_back(vector.size());
		v.push_back(vector.capacity());
		return v;
	}

	static std::vector<int> test_begin_std() {
		std::vector<int> vector;
		std::vector<int> v;
		vector.assign(1000, 1);
		v.push_back(*vector.begin());
		v.push_back(*++vector.begin());
		return v;
	}

	static std::vector<int> test_begin_ft() {
		ft::vector<int> vector;
		std::vector<int> v;
		vector.assign(1000, 1);
		v.push_back(*vector.begin());
		v.push_back(*++vector.begin());
		return v;
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

	static std::vector<int> begin_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> begin_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> capacity_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> capacity_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> clear_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> clear_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> constructor_std_iterators_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> constructor_std_iterators_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> constructor_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> constructor_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> data_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> data_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> empty_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> empty_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> end_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> end_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> erase_range_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> erase_range_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> erase_value_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> erase_value_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> front_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> front_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_fill_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_fill_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_range_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_range_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_std_iterators_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_std_iterators_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_value_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> insert_value_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> iterators_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> iterators_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> max_size_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> max_size_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> operator_not_equal_test_std(){
		std::vector<int> v;
		return v;
	} // !=
	static std::vector<int> operator_not_equal_test_ft(){
		std::vector<int> v;
		return v;
	} // !=
	static std::vector<int> operator_less_test_std(){
		std::vector<int> v;
		return v;
	} // <
	static std::vector<int> operator_less_test_ft(){
		std::vector<int> v;
		return v;
	} // <
	static std::vector<int> operator_less_equal_test_std(){
		std::vector<int> v;
		return v;
	} // <=
	static std::vector<int> operator_less_equal_test_ft(){
		std::vector<int> v;
		return v;
	} // <=
	static std::vector<int> operator_equal_test_std(){
		std::vector<int> v;
		return v;
	} // ==
	static std::vector<int> operator_equal_test_ft(){
		std::vector<int> v;
		return v;
	} // ==
	static std::vector<int> operator_more_test_std(){
		std::vector<int> v;
		return v;
	} // >
	static std::vector<int> operator_more_test_ft(){
		std::vector<int> v;
		return v;
	} // >
	static std::vector<int> operator_more_equal_test_std(){
		std::vector<int> v;
		return v;
	} // >=
	static std::vector<int> operator_more_equal_test_ft(){
		std::vector<int> v;
		return v;
	} // >=
	static std::vector<int> operator_angle_braces_test_std(){
		std::vector<int> v;
		return v;
	} // []
	static std::vector<int> operator_angle_braces_test_ft(){
		std::vector<int> v;
		return v;
	} // []
	static std::vector<int> pop_back_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> pop_back_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> push_back_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> push_back_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> rbegin_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> rbegin_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> rend_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> rend_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> reserve_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> reserve_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> resize_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> resize_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> size_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> size_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> swap_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> swap_test_ft() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> using_allocator_test_std() {
		std::vector<int> v;
		return v;
	}
	static std::vector<int> using_allocator_test_ft() {
		std::vector<int> v;
		return v;
	}

public:
	void run_all_tests() {
		run_test(test_assign_ft, test_assign_std , "assign()");
		run_test(test_at_ft, test_at_std , "at()");
		run_test(test_back_ft, test_back_std , "back()");
		run_test(test_begin_ft, test_begin_std , "begin()");
		run_test(test_push_back_ft, test_push_back_std , "push_back()");
	}
};
#endif //MYCONTAINERS_TEST_H
