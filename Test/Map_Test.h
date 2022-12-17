#ifndef MYCONTAINERS_MAP_TEST_H
#define MYCONTAINERS_MAP_TEST_H

#include <map>
#include "test.h"
#include "../srcs/containers/map.h"
class Map_Test : Test {
private:
	static std::vector<int>test_at_ft(){
		std::vector<int> result;
		int limit = LIMIT;
		ft::map<int, int> map;
		for (int i = 0, j = -42; i < 70 * limit; ++i, --j)
			map.insert(ft::make_pair(i, j));
		try {
			result.push_back(map.at(40 * limit));
			result.push_back(map.at(40 * limit + 1));
		} catch (std::exception &e) {
			result.push_back(-42);
		}
		return result;
	}

	static std::vector<int>test_at_std(){
		std::vector<int> result;
		int limit = LIMIT;
		std::map<int, int> map;
		for (int i = 0, j = -42; i < 70 * limit; ++i, --j)
			map.insert(std::make_pair(i, j));
		try {
			result.push_back(map.at(40 * limit));
			result.push_back(map.at(40 * limit + 1));
		} catch (std::exception &e) {
			result.push_back(-42);
		}
		return result;
	}

	static std::vector<int>test_clear_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		int limit = LIMIT;
		for (int i = 0, j = -42; i < 70 * limit; ++i, --j)
			map.insert(ft::make_pair(i, j));
		result.push_back(map.size());
		map.clear();
		result.push_back(map.size());
		return result;
	}

	static std::vector<int>test_clear_std(){
		std::vector<int> result;
		std::map<int, int> map;
		int limit = LIMIT;
		for (int i = 0, j = -42; i < 70 * limit; ++i, --j)
			map.insert(std::make_pair(i, j));
		result.push_back(map.size());
		map.clear();
		result.push_back(map.size());
		return result;
	}

	static std::vector<int>test_count_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		int limit = LIMIT;
		result.push_back(map.count(42));
		for (int i = 0; i < 70 * limit; ++i)
			map.insert(ft::make_pair(i, i % 2 ? 42 : i));
		result.push_back(map.count(42));
		return result;
	}

	static std::vector<int>test_count_std(){
		std::vector<int> result;
		std::map<int, int> map;
		int limit = LIMIT;
		result.push_back(map.count(42));
		for (int i = 0; i < 70 * limit; ++i)
			map.insert(std::make_pair(i, i % 2 ? 42 : i));
		result.push_back(map.count(42));
		return result;
	}

	static std::vector<int>test_constructor_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		result.push_back(map.size());
		return result;
	}

	static std::vector<int>test_constructor_std(){
		std::vector<int> result;
		std::map<int, int> map;
		result.push_back(map.size());
		return result;
	}
public:
	void run_all_tests() {
		run_test(test_at_ft, test_at_std , "at()");
		run_test(test_clear_ft, test_clear_std , "clear()");
		run_test(test_count_ft, test_count_std , "count()");


		run_test(test_constructor_ft, test_constructor_std , "constructor()"); //not implemented
	}
};
#endif //MYCONTAINERS_MAP_TEST_H
