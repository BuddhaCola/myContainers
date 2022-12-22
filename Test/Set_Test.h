#ifndef MYCONTAINERS_SET_TEST_H
#define MYCONTAINERS_SET_TEST_H

#include <set>
#include "test.h"
#include "../srcs/containers/set.h"
class Set_Test : Test {
private:
	static std::vector<int>test_constructor_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		int limit = LIMIT;
		for (int i = 0, j = -limit; i < limit; ++i, --j) {
			map.insert(ft::make_pair(i, j));
		}
		result.push_back(map.size());
		ft::map<int, int> map2(map);
		result.push_back(map2.size());
		return result;
	}

	static std::vector<int>test_constructor_std(){
		std::vector<int> result;
		std::map<int, int> map;
		int limit = LIMIT;
		for (int i = 0, j = -limit; i < limit; ++i, --j) {
			map.insert(std::make_pair(i, j));
		}
		result.push_back(map.size());
		std::map<int, int> map2(map);
		result.push_back(map2.size());
		return result;
	}

	static std::vector<int>test_iterators_ft(){
		std::vector<int> result;
		ft::map<int, int> map;
		for (int i = 0, j = -100; i < 100; ++i, --j) {
			map.insert(ft::make_pair(i, j));
		}
		ft::map<int, int>::iterator it1 = map.begin();
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1++;
		it1++;
		it1++;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1--;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1++;
		it1++;
		it1++;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1--;
		result.push_back(it1->first);
		result.push_back(it1->second);
		ft::map<int, int>::iterator it2 = --map.end();
		result.push_back(it2->first);
		result.push_back(it2->second);
		it2--;
		it2--;
		it2--;
		result.push_back(it2->first);
		result.push_back(it2->second);
		it2--;
		it2--;
		it2--;
		it2++;
		result.push_back(it2->first);
		result.push_back(it2->second);
		ft::map<int, int>::reverse_iterator it3 = ++map.rbegin();
		result.push_back(it3->first);
		result.push_back(it3->second);
		it3++;
		it3++;
		it3++;
		it3--;
		result.push_back(it3->first);
		result.push_back(it3->second);
		ft::map<int, int>::reverse_iterator it4 = --map.rend();
		result.push_back(it4->first);
		result.push_back(it4->second);
		it4--;
		it4--;
		it4--;
		it4++;
		result.push_back(it4->first);
		result.push_back(it4->second);
		return result;
	}

	static std::vector<int>test_iterators_std(){
		std::vector<int> result;
		std::map<int, int> map;
		for (int i = 0, j = -100; i < 100; ++i, --j) {
			map.insert(std::make_pair(i, j));
		}
		std::map<int, int>::iterator it1 = map.begin();
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1++;
		it1++;
		it1++;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1--;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1++;
		it1++;
		it1++;
		result.push_back(it1->first);
		result.push_back(it1->second);
		it1--;
		result.push_back(it1->first);
		result.push_back(it1->second);
		std::map<int, int>::iterator it2 = --map.end();
		result.push_back(it2->first);
		result.push_back(it2->second);
		it2--;
		it2--;
		it2--;
		result.push_back(it2->first);
		result.push_back(it2->second);
		it2--;
		it2--;
		it2--;
		it2++;
		result.push_back(it2->first);
		result.push_back(it2->second);
		std::map<int, int>::reverse_iterator it3 = ++map.rbegin();
		result.push_back(it3->first);
		result.push_back(it3->second);
		it3++;
		it3++;
		it3++;
		it3--;
		result.push_back(it3->first);
		result.push_back(it3->second);
		std::map<int, int>::reverse_iterator it4 = --map.rend();
		result.push_back(it4->first);
		result.push_back(it4->second);
		it4--;
		it4--;
		it4--;
		it4++;
		result.push_back(it4->first);
		result.push_back(it4->second);
		return result;
	}

	static std::vector<int> test_operator_not_equal_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 != map2);
		result.push_back(map1 != map3);
		return result;
	}

	static std::vector<int> test_operator_not_equal_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 != map2);
		result.push_back(map1 != map3);
		return result;
	}

	static std::vector<int> test_operator_less_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 < map2);
		result.push_back(map1 < map3);
		return result;
	}

	static std::vector<int> test_operator_less_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 < map2);
		result.push_back(map1 < map3);
		return result;
	}

	static std::vector<int> test_operator_less_equal_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 <= map2);
		result.push_back(map1 <= map3);
		return result;
	}

	static std::vector<int> test_operator_less_equal_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 <= map2);
		result.push_back(map1 <= map3);
		return result;
	}

	static std::vector<int> test_operator_equal_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 == map2);
		result.push_back(map1 == map3);
		return result;
	}

	static std::vector<int> test_operator_equal_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 == map2);
		result.push_back(map1 == map3);
		return result;
	}

	static std::vector<int> test_operator_more_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 > map2);
		result.push_back(map1 > map3);
		return result;
	}

	static std::vector<int> test_operator_more_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 > map2);
		result.push_back(map1 > map3);
		return result;
	}

	static std::vector<int> test_operator_more_equal_ft() {
		std::vector<int> result;
		ft::map<int, int> map1;
		ft::map<int, int> map2;
		ft::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(ft::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(ft::make_pair(i, j));
		}
		result.push_back(map1 >= map2);
		result.push_back(map1 >= map3);
		return result;
	}

	static std::vector<int> test_operator_more_equal_std() {
		std::vector<int> result;
		std::map<int, int> map1;
		std::map<int, int> map2;
		std::map<int, int> map3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map1.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -42; i < lesser; ++i, --j) {
			map2.insert(std::make_pair(i, j));
		}
		for (int i = 0, j = -100; i < bigger; ++i, --j) {
			map3.insert(std::make_pair(i, j));
		}
		result.push_back(map1 >= map2);
		result.push_back(map1 >= map3);
		return result;
	}

public:
	void run_all_tests() {
		run_test(test_constructor_ft, test_constructor_std , "constructor");
		run_test(test_iterators_ft, test_iterators_std , "iterators");
		run_test(test_operator_not_equal_ft, test_operator_not_equal_std , "operator !=");
		run_test(test_operator_less_ft, test_operator_less_std , "operator <");
		run_test(test_operator_less_equal_ft, test_operator_less_equal_std , "operator <=");
		run_test(test_operator_equal_ft, test_operator_equal_std , "operator ==");
		run_test(test_operator_more_ft, test_operator_more_std , "operator >");
		run_test(test_operator_more_equal_ft, test_operator_more_equal_std , "operator >=");
	}
};
#endif //MYCONTAINERS_SET_TEST_H
