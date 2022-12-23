#ifndef MYCONTAINERS_SET_TEST_H
#define MYCONTAINERS_SET_TEST_H

#include <set>
#include "test.h"
#include "../srcs/containers/set.h"
class Set_Test : Test {
private:
	static std::vector<int> test_count_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		result.push_back(set.count(42));
		for (int i = 0; i < limit; ++i)
			set.insert(i % 2 ? 42 : i);
		result.push_back(set.count(42));
		return result;
	}

	static std::vector<int> test_count_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		result.push_back(set.count(42));
		for (int i = 0; i < limit; ++i)
			set.insert(i % 2 ? 42 : i);
		result.push_back(set.count(42));
		return result;
	}
	static std::vector<int>test_insert_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		ft::set<int>::iterator it = set.begin();
		result.push_back(*it);
		result.push_back(set.size());
		ft::set<int> set2;
		set2.insert(set.find(42), set.end());
		result.push_back(*set2.begin());
		result.push_back(set2.size());
		return result;
	}

	static std::vector<int>test_insert_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		std::set<int>::iterator it = set.begin();
		result.push_back(*it);
		result.push_back(set.size());
		std::set<int> set2;
		set2.insert(set.find(42), set.end());
		result.push_back(*set2.begin());
		result.push_back(set2.size());
		return result;
	}

	static std::vector<int>test_size_ft() {
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		result.push_back(set.size());
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(set.size());
		ft::set<int> set2(set);
		result.push_back(set2.size());
		set.clear();
		result.push_back(set.size());
		return result;
	}

	static std::vector<int>test_size_std() {
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		result.push_back(set.size());
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(set.size());
		std::set<int> set2(set);
		result.push_back(set2.size());
		set.clear();
		result.push_back(set.size());
		return result;
	}

	static std::vector<int>test_erase_ft(){
		std::vector<int> result;
		int limit = LIMIT;
		ft::set<int> set;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		set.erase(set.begin()++);
		result.push_back(set.size());
		ft::set<int>::iterator it1 = set.begin();
		ft::set<int>::iterator it2 = set.find(10);
		set.erase(it1, it2);
		result.push_back(set.size());
		result.push_back(*set.begin());
		set.erase((set.begin()));
		result.push_back(set.size());
		result.push_back(*set.begin());
		set.erase(set.begin(), set.end()--);
		result.push_back(set.size());
		return result;
	}

	static std::vector<int>test_erase_std(){
		std::vector<int> result;
		int limit = LIMIT;
		std::set<int> set;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		set.erase(set.begin()++);
		result.push_back(set.size());
		std::set<int>::iterator it1 = set.begin();
		std::set<int>::iterator it2 = set.find(10);
		set.erase(it1, it2);
		result.push_back(set.size());
		result.push_back(*set.begin());
		set.erase((set.begin()));
		result.push_back(set.size());
		result.push_back(*set.begin());
		set.erase(set.begin(), set.end()--);
		result.push_back(set.size());
		return result;
	}

	static std::vector<int>test_swap_ft() {
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		ft::set<int> set2;
		set2.insert(42);
		result.push_back(set.size());
		result.push_back(*set.begin());
		result.push_back(set2.size());
		result.push_back(*set2.begin());
		set.swap(set2);
		result.push_back(set.size());
		result.push_back(*set.begin());
		result.push_back(set2.size());
		result.push_back(*set2.begin());
		return result;
	}

	static std::vector<int>test_swap_std() {
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		std::set<int> set2;
		set2.insert(42);
		result.push_back(set.size());
		result.push_back(*set.begin());
		result.push_back(set2.size());
		result.push_back(*set2.begin());
		set.swap(set2);
		result.push_back(set.size());
		result.push_back(*set.begin());
		result.push_back(set2.size());
		result.push_back(*set2.begin());
		return result;
	}

	static std::vector<int>test_find_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(*set.find(42));
		result.push_back(*set.find(0));
		return result;
	}

	static std::vector<int>test_find_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(*set.find(42));
		result.push_back(*set.find(0));
		return result;
	}

	static std::vector<int>test_lower_bound_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		ft::set<int>::iterator lower = set.lower_bound(limit / 4);
		result.push_back(*lower);
		return result;
	}

	static std::vector<int>test_lower_bound_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		std::set<int>::iterator lower = set.lower_bound(limit / 4);
		result.push_back(*lower);
		return result;
	}

	static std::vector<int>test_upper_bound_ft() {
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		ft::set<int>::iterator upper = set.upper_bound(limit / 4);
		result.push_back(*upper);
		return result;
	}

	static std::vector<int>test_upper_bound_std() {
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		std::set<int>::iterator upper = set.upper_bound(limit / 4);
		result.push_back(*upper);
		return result;
	}

	static std::vector<int>test_equal_range_std(){
		std::vector<int> result;
		std::set<int> set;
		set.insert(10);
		set.insert(20);
		set.insert(30);
		set.insert(40);
		set.insert(50);
		set.insert(60);
		const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& range1 = set.equal_range(10);
		const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& range2 = set.equal_range(11);
		const std::pair<std::set<int>::const_iterator , std::set<int>::const_iterator>& range3 = set.equal_range(1);
		result.push_back(*range1.first);
		result.push_back(*range1.second);
		result.push_back(*range2.first);
		result.push_back(*range2.second);
		result.push_back(*range3.first);
		result.push_back(*range3.second);
		return result;
	}

	static std::vector<int>test_equal_range_ft(){
		std::vector<int> result;
		ft::set<int> set;
		set.insert(10);
		set.insert(20);
		set.insert(30);
		set.insert(40);
		set.insert(50);
		set.insert(60);
		const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& range1 = set.equal_range(10);
		const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& range2 = set.equal_range(11);
		const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator>& range3 = set.equal_range(1);
		result.push_back(*range1.first);
		result.push_back(*range1.second);
		result.push_back(*range2.first);
		result.push_back(*range2.second);
		result.push_back(*range3.first);
		result.push_back(*range3.second);
		return result;
	}

	static std::vector<int>test_key_comp_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		ft::set<int>::key_compare comp = set.key_comp();
		int needle = *set.find(limit / 3);
		ft::set<int>::iterator it = set.begin();
		result.push_back(comp(*it, needle));
		while (comp(*it++, needle))
			;
		result.push_back(comp(*it, needle));
		result.push_back(*it);
		return result;
	}

	static std::vector<int>test_key_comp_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		std::set<int>::key_compare comp = set.key_comp();
		int needle = *set.find(limit / 3);
		std::set<int>::iterator it = set.begin();
		result.push_back(comp(*it, needle));
		while (comp(*it++, needle))
			;
		result.push_back(comp(*it, needle));
		result.push_back(*it);
		return result;
	}

	static std::vector<int> test_constructor_ft(){
		std::vector<int> result;
		ft::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(set.size());
		ft::set<int> set2(set);
		result.push_back(set2.size());
		return result;
	}

	static std::vector<int> test_constructor_std(){
		std::vector<int> result;
		std::set<int> set;
		int limit = LIMIT;
		for (int i = 0; i < limit; ++i) {
			set.insert(i);
		}
		result.push_back(set.size());
		std::set<int> set2(set);
		result.push_back(set2.size());
		return result;
	}

	static std::vector<int> test_iterators_ft(){
		std::vector<int> result;
		ft::set<int> set;
		for (int i = 0; i < 100; ++i) {
			set.insert(i);
		}
		ft::set<int>::iterator it1 = set.begin();
		result.push_back(*it1);
		it1++;
		it1++;
		it1++;
		result.push_back(*it1);
		it1--;
		result.push_back(*it1);
		it1++;
		it1++;
		it1++;
		result.push_back(*it1);
		it1--;
		result.push_back(*it1);
		ft::set<int>::iterator it2 = --set.end();
		result.push_back(*it2);
		it2--;
		it2--;
		it2--;
		result.push_back(*it2);
		it2--;
		it2--;
		it2--;
		it2++;
		result.push_back(*it2);
		ft::set<int>::reverse_iterator it3 = ++set.rbegin();
		result.push_back(*it3);
		it3++;
		it3++;
		it3++;
		it3--;
		result.push_back(*it3);
		ft::set<int>::reverse_iterator it4 = --set.rend();
		result.push_back(*it4);
		it4--;
		it4--;
		it4--;
		it4++;
		result.push_back(*it4);
		return result;
	}

	static std::vector<int> test_iterators_std(){
		std::vector<int> result;
		std::set<int> set;
		for (int i = 0; i < 100; ++i) {
			set.insert(i);
		}
		std::set<int>::iterator it1 = set.begin();
		result.push_back(*it1);
		it1++;
		it1++;
		it1++;
		result.push_back(*it1);
		it1--;
		result.push_back(*it1);
		it1++;
		it1++;
		it1++;
		result.push_back(*it1);
		it1--;
		result.push_back(*it1);
		std::set<int>::iterator it2 = --set.end();
		result.push_back(*it2);
		it2--;
		it2--;
		it2--;
		result.push_back(*it2);
		it2--;
		it2--;
		it2--;
		it2++;
		result.push_back(*it2);
		std::set<int>::reverse_iterator it3 = ++set.rbegin();
		result.push_back(*it3);
		it3++;
		it3++;
		it3++;
		it3--;
		result.push_back(*it3);
		std::set<int>::reverse_iterator it4 = --set.rend();
		result.push_back(*it4);
		it4--;
		it4--;
		it4--;
		it4++;
		result.push_back(*it4);
		return result;
	}

	static std::vector<int> test_operator_not_equal_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 != set2);
		result.push_back(set1 != set3);
		return result;
	}

	static std::vector<int> test_operator_not_equal_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 != set2);
		result.push_back(set1 != set3);
		return result;
	}

	static std::vector<int> test_operator_less_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 < set2);
		result.push_back(set1 < set3);
		return result;
	}

	static std::vector<int> test_operator_less_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 < set2);
		result.push_back(set1 < set3);
		return result;
	}

	static std::vector<int> test_operator_less_equal_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 <= set2);
		result.push_back(set1 <= set3);
		return result;
	}

	static std::vector<int> test_operator_less_equal_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 <= set2);
		result.push_back(set1 <= set3);
		return result;
	}

	static std::vector<int> test_operator_equal_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 == set2);
		result.push_back(set1 == set3);
		return result;
	}

	static std::vector<int> test_operator_equal_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 == set2);
		result.push_back(set1 == set3);
		return result;
	}

	static std::vector<int> test_operator_more_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		ft::set<int>::iterator it = set1.end();
		for (int i = 0; i < 50 * LIMIT; ++i) {
			set1.insert(it, i);
		}
		result.push_back(set1 > set2);
		result.push_back(set1 > set3);
		return result;
	}

	static std::vector<int> test_operator_more_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		std::set<int>::iterator it = set1.end();
		for (int i = 0; i < 50 * LIMIT; ++i) {
			set1.insert(it, i);
		}
		result.push_back(set1 > set2);
		result.push_back(set1 > set3);
		return result;
	}

	static std::vector<int> test_operator_more_equal_ft() {
		std::vector<int> result;
		ft::set<int> set1;
		ft::set<int> set2;
		ft::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 >= set2);
		result.push_back(set1 >= set3);
		return result;
	}

	static std::vector<int> test_operator_more_equal_std() {
		std::vector<int> result;
		std::set<int> set1;
		std::set<int> set2;
		std::set<int> set3;
		int bigger = LIMIT;
		int lesser = bigger / 2;
		for (int i = 0; i < bigger; ++i) {
			set1.insert(i);
		}
		for (int i = 0; i < lesser; ++i) {
			set2.insert(i);
		}
		for (int i = 0; i < bigger; ++i) {
			set3.insert(i);
		}
		result.push_back(set1 >= set2);
		result.push_back(set1 >= set3);
		return result;
	}

public:
	void run_all_tests() {
		run_test(test_count_ft, test_count_std , "count()");
		run_test(test_insert_ft, test_insert_std , "insert()");
		run_test(test_size_ft, test_size_std , "size()");
		run_test(test_erase_ft, test_erase_std , "erase()");
		run_test(test_swap_ft, test_swap_std , "swap()");
		run_test(test_find_ft, test_find_std , "find()");
		run_test(test_lower_bound_ft, test_lower_bound_std , "lower_bound()");
		run_test(test_upper_bound_ft, test_upper_bound_std , "upper_bound()");
		run_test(test_equal_range_ft, test_equal_range_std , "equal_range()");
		run_test(test_key_comp_ft, test_key_comp_std , "key_comp()");

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