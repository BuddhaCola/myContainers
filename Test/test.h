#ifndef MYCONTAINERS_TEST_H
#define MYCONTAINERS_TEST_H

#include <array>
#include <vector>
#include <sys/time.h>
#include <stack>
#include <iostream>
#include <sstream>
#include "../srcs/containers/vector.h"

#define LIMIT 10000

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
		std::cout << "result comparisation: " << (ft_result == std_result ? "✅" : "❌") << std::endl;
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
public:
	void run_all_tests() {
		run_test(test_push_back_ft, test_push_back_std , "push_back()");
//		run_test(test_assign_ft, test_assign_std , "assign()");
	}
};
#endif //MYCONTAINERS_TEST_H
