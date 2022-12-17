#include "test.h"
#ifndef MYCONTAINERS_STACK_TEST_H
#define MYCONTAINERS_STACK_TEST_H
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
#endif //MYCONTAINERS_STACK_TEST_H
