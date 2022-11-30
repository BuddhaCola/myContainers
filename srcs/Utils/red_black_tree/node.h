#ifndef MYCONTAINERS_NODE_H
#define MYCONTAINERS_NODE_H
enum node_type {
	red_node,
	nil_node,
	black_node,
};

template <class T>
class node {
	T			*data;
	node		*parent;
	node		*left;
	node		*right;
	node_type	type;

public:
	node(T value, node* nil = NULL)
			: right(nil), left(nil), data(new T(value)), parent(nil), type(nil_node) { }

	node(const node& other) { *this = other; }

	node& operator=(const node& other) {
		if (this == &other)
			return *this;
		parent = other.parent;
		left = other.left;
		right = other.right;
		data = new T(other.value);
		type = other.type;
		return *this;
	}

	~node() {
		if (data) {
			delete data;
			data = NULL;
		}
	}

public:
	T *getData() const {
		return data;
	}

	void setData(T *data) {
		node::data = data;
	}

	node *getParent() const {
		return parent;
	}

	void setParent(node *parent) {
		node::parent = parent;
	}

	node *getLeft() const {
		return left;
	}

	void setLeft(node *left) {
		node::left = left;
	}

	node *getRight() const {
		return right;
	}

	void setRight(node *right) {
		node::right = right;
	}
};
#endif //MYCONTAINERS_NODE_H
