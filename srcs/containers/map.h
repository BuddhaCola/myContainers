#ifndef MYCONTAINERS_MAP_H
#define MYCONTAINERS_MAP_H
//#include <memory>
#include "../Utils/red_black_tree/red_black_tree.h"
template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
> class map {
public:
	map() {
		tree<Key, T> data;
	}
};
#endif //MYCONTAINERS_MAP_H
