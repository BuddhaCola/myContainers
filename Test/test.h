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
//		print_results(std_result, ft_result);
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

#endif //MYCONTAINERS_TEST_H
