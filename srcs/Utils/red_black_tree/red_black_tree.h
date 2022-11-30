#ifndef MYCONTAINERS_RED_BLACK_TREE_H
#define MYCONTAINERS_RED_BLACK_TREE_H
#include "node.h"

#include <utility>
template <class K, class T>
class tree {
	typedef std::pair<node<K>, T> *pointer;
private:
	pointer _root;
	pointer _nil;
	size_t _size;
public:
	tree() : _root(NULL), _nil(_root) {}

	~tree() {}

	void	insert(std::pair<K, node<T> > pair) {
		node<T> *current, parent, new_node;

		for (current = _root, parent = _nil; current != _nil;) {
			if (pair.first == current->data->first)
				return std::pair<pointer, bool>(current, false);
			parent = current;
			current = _cmp(pair.first, current->data->first) ? current->left : current->right;
		}
		new_node = new node<T>(pair.second);
		new_node->parent = parent;

		if (parent == _nil)
			_root = new_node;
		else {
			if (_cmp(pair.first, parent->data->first))
				parent->left = new_node;
			else
				parent->right = new_node;
		}
		_repair_tree_structure(new_node);
		_nil->parent = _maximum(_root);
		++_size;
		return std::pair<pointer, bool>(new_node, true);
	}

	pointer _find(pointer node, K key) const
	{
		if (node != _nil) {
			if (node->data->first == key)
				return node;
			else if (_cmp(key, node->data->first))
				return _find(node->left, key);
			else
				return _find(node->right, key);
		}
		return _nil;
	}

	pointer _next(pointer node)
	{
		if (node->type == nil_node)
			return node;

		if (node->right->type != nil_node)
			return _minimum(node->right);

		pointer tmp = node->parent;
		for (; tmp->type != nil_node && node == tmp->right; node = tmp, tmp = tmp->parent) { }
		return tmp;
	}

	pointer _prev(pointer node)
	{
		if (node->type == nil_node)
			return node->parent;

		if (node->type != nil_node && node->left->type != nil_node)
			return _maximum(node->left);

		pointer tmp = node->parent;
		for (; tmp->type != nil_node && node == tmp->left; node = tmp, tmp = tmp->parent) { }
		return tmp->type != nil_node ? tmp : node;
	}

	void _clear(pointer& node)
	{
		if (node == NULL || node == _nil)
			return;

		_clear(node->left);
		_clear(node->right);
		if (node == _root) {
			_free_node(_root);
			_root = _nil;
			_nil->parent = NULL;
			_size = 0;
		}
		else
			_free_node(node);
	}
};
#endif //MYCONTAINERS_RED_BLACK_TREE_H
