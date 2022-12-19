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

	static std::vector<int>test_empty_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		result.push_back(map.empty());
		map.insert(ft::make_pair(42, 42));
		result.push_back(map.empty());
		map.clear();
		result.push_back(map.empty());
		return result;
	}

	static std::vector<int>test_empty_std(){
		std::vector<int> result;
		std::map<int, int> map;
		result.push_back(map.empty());
		map.insert(std::make_pair(42, 42));
		result.push_back(map.empty());
		map.clear();
		result.push_back(map.empty());
		return result;
	}

	static std::vector<int>test_equal_range_std(){
		std::vector<int> result;
		std::map<int, int> map;
		map.insert(std::make_pair(10, 10));
		map.insert(std::make_pair(20, 20));
		map.insert(std::make_pair(30, 30));
		map.insert(std::make_pair(40, 40));
		map.insert(std::make_pair(50, 50));
		map.insert(std::make_pair(60, 60));
		const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& range1 = map.equal_range(10);
		const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& range2 = map.equal_range(11);
		const std::pair<std::map<int, int>::const_iterator , std::map<int, int>::const_iterator>& range3 = map.equal_range(1);
		result.push_back(range1.first->first);
		result.push_back(range1.first->second);
		result.push_back(range1.second->first);
		result.push_back(range1.second->second);
		result.push_back(range2.first->first);
		result.push_back(range2.first->second);
		result.push_back(range2.second->first);
		result.push_back(range2.second->second);
		result.push_back(range3.first->first);
		result.push_back(range3.first->second);
		result.push_back(range3.second->first);
		result.push_back(range3.second->second);
		return result;
	}
	static std::vector<int>test_equal_range_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		map.insert(ft::make_pair(10, 10));
		map.insert(ft::make_pair(20, 20));
		map.insert(ft::make_pair(30, 30));
		map.insert(ft::make_pair(40, 40));
		map.insert(ft::make_pair(50, 50));
		map.insert(ft::make_pair(60, 60));
		const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& range1 = map.equal_range(10);
		const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& range2 = map.equal_range(11);
		const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& range3 = map.equal_range(1);
		result.push_back(range1.first->first);
		result.push_back(range1.first->second);
		result.push_back(range1.second->first);
		result.push_back(range1.second->second);
		result.push_back(range2.first->first);
		result.push_back(range2.first->second);
		result.push_back(range2.second->first);
		result.push_back(range2.second->second);
		result.push_back(range3.first->first);
		result.push_back(range3.first->second);
		result.push_back(range3.second->first);
		result.push_back(range3.second->second);
		return result;
	}

	static std::vector<int>test_erase_ft(){
		std::vector<int> result;
		int limit = LIMIT;
		ft::map<int, int> map;
		for (int i = 0, j = -limit; i < limit; ++i, --j) {
			map.insert(ft::make_pair(i, j));
		}
		map.erase(map.begin()++->first);
		result.push_back(map.size());
		ft::map<int, int>::iterator it1 = map.begin();
		ft::map<int, int>::iterator it2 = map.find(10);
		map.erase(it1, it2);
		result.push_back(map.size());
		result.push_back(map.begin()->second);
		map.erase((map.begin())->first);
		result.push_back(map.size());
		result.push_back(map.begin()->second);
		map.erase(map.begin(), map.end()--);
		result.push_back(map.size());
		return result;
	}
	static std::vector<int>test_erase_std(){
		std::vector<int> result;
		int limit = LIMIT;
		std::map<int, int> map;
		for (int i = 0, j = -limit; i < limit; ++i, --j) {
			map.insert(std::make_pair(i, j));
		}
		map.erase(map.begin()++->first);
		result.push_back(map.size());
		std::map<int, int>::iterator it1 = map.begin();
		std::map<int, int>::iterator it2 = map.find(10);
		map.erase(it1, it2);
		result.push_back(map.size());
		result.push_back(map.begin()->second);
		map.erase((map.begin())->first);
		result.push_back(map.size());
		result.push_back(map.begin()->second);
		map.erase(map.begin(), map.end()--);
		result.push_back(map.size());
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
		run_test(test_empty_ft, test_empty_std , "empty()");
		run_test(test_equal_range_ft, test_equal_range_std , "equal_range()");
		run_test(test_erase_ft, test_erase_std , "erase()");


		run_test(test_constructor_ft, test_constructor_std , "constructor()"); //not implemented
	}
};
#endif //MYCONTAINERS_MAP_TEST_H
