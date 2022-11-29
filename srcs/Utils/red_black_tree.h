#ifndef MYCONTAINERS_RED_BLACK_TREE_H
#define MYCONTAINERS_RED_BLACK_TREE_H

template<class T1, class T2>
struct node{
	enum node_type {
		red_node,
		nil_node,
		black_node,
	};

private:
	typedef std::pair<const T1, T2> value_type;
	node* right;
	node* left;
	value_type* data;
	node_type type;
	node* parent;
public:
	node(T1 key, T2 value, node *nil = NULL, node_type type = black_node)
			:   right(nil), left(nil), data(new value_type(key, value)), type(type), parent(nil) { }
	node(const node& other) { *this = other; }

	node& operator=(const node& other) {
		if (this == &other)
			return *this;
		type = other.type;
		parent = other.parent;
		left = other.left;
		right = other.right;
		data = new value_type(other.data->first, other.data->second);
		return *this;
	}

	~node() {
		if (data) {
			delete data;
			data = NULL;
		}
	}
};

template<class K, class T>
class rbt {
	std::pair<K, node<T> >	*root;
public:
	explicit rbt(node<T> *root) : root(root) {}

	explicit rbt() : root() {}

	std::pair<K, T> &search(K const &key) {
		std::pair<K, T> *current = root;
		while (current->getData()) {
			if (current->first == key)
				return current->second.get
			if (current->getLeft() <= )
		}
	}
	void push(T data) {
		if (!root) {
			root = new node<T>(&data, NULL);
			return;
		}
		node<T> *current = root;
		while (current->getLeft()->getRight()) {
			if (current->getData() >= current->getRight()->getData()) {}
		}
	}
	T &operator[](K key) {
		node<T> *current = root;

		while (current->getRight() || current->getLeft()) {
			if (current->getData() == key) {
				return current->getData();
			}
			if (current->getRight()->getData() >= current->getData()) {
				current = current->getRight();
			}
		}
		return *current->getData();
	};
};
#endif //MYCONTAINERS_RED_BLACK_TREE_H
