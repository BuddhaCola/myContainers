#include <array>
#include <iostream>
#include "containers/stack.h"
#include "containers/vector.h"

int main() {
	std::vector<int> orig;
	FT::vector<int> mine;
	for (int i = 0; i < 6; ++i) {
		int *juj = new int(2);
		orig.push_back(*juj);
		mine.push_back(*juj);
		std::cout << "Orig.size() = " << orig.size() << " orig.capacity() = " << orig.capacity() << " orig[" << i << "] = " << orig[i] << std::endl;
		std::cout << "Mine.size() = " << mine.size() << " mine.capacity() = " << mine.capacity() << " mine[" << i << "] = " << mine[i] << std::endl;
	}
}