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
struct tree_node_kv {
public:
	typedef ft::pair<const K, T> value_type;
	tree_node_kv *right;
	tree_node_kv *left;
	value_type *data;
	node_type type;
	tree_node_kv *parent;

public:
	tree_node_kv(K key, T value, tree_node_kv *nil = NULL, node_type type = black_node)
			: right(nil), left(nil), data(new value_type(key, value)), type(type), parent(nil) {}

	tree_node_kv(const tree_node_kv &other) { *this = other; }

	tree_node_kv &operator=(const tree_node_kv &other) {
		if (this == &other)
			return *this;
		parent = other.parent;
		left = other.left;
		right = other.right;
		data = new value_type(other.data->first, other.data->second);
		type = other.type;
		return *this;
	}

	~tree_node_kv() {
		if (data) {
			delete data;
			data = NULL;
		}
	}
};

template<class T>
struct tree_node_v {
public:
	typedef T value_type;
	tree_node_v *right;
	tree_node_v *left;
	value_type *data;
	node_type type;
	tree_node_v *parent;

public:
	tree_node_v(T value, tree_node_v *nil = NULL, node_type type = black_node)
			: right(nil), left(nil), data(new value_type(value)), type(type), parent(nil) {}

	tree_node_v(const tree_node_v &other) { *this = other; }

	tree_node_v &operator=(const tree_node_v &other) {
		if (this == &other)
			return *this;
		parent = other.parent;
		left = other.left;
		right = other.right;
		data = new value_type(*other.data);
		type = other.type;
		return *this;
	}

	~tree_node_v() {
		if (data) {
			delete data;
			data = NULL;
		}
	}
};

}
#endif //MYCONTAINERS_TREE_NODE_H
