#ifndef MYCONTAINERS_TREE_NODE_H
#define MYCONTAINERS_TREE_NODE_H

#include "../pair.h"

namespace ft {
enum node_type {
	red_node,
	nil_node,
	black_node,
};

template<class K, class T>
struct tree_node {
public:
	typedef ft::pair<const K, T> value_type;
	tree_node *right;
	tree_node *left;
	value_type *data;
	node_type type;
	tree_node *parent;

public:
	tree_node(K key, T value, tree_node *nil = NULL, node_type type = black_node)
			: right(nil), left(nil), data(new value_type(key, value)), type(type), parent(nil) {}

	tree_node(const tree_node &other) { *this = other; }

	tree_node &operator=(const tree_node &other) {
		if (this == &other)
			return *this;
		parent = other.parent;
		left = other.left;
		right = other.right;
		data = new value_type(other.data->first, other.data->second);
		type = other.type;
		return *this;
	}

	~tree_node() {
		if (data) {
			delete data;
			data = NULL;
		}
	}
};

}
#endif //MYCONTAINERS_TREE_NODE_H
