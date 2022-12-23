#ifndef MYCONTAINERS_RED_BLACK_TREE_SET_H
#define MYCONTAINERS_RED_BLACK_TREE_SET_H
#include "tree_node.h"
namespace ft {
	template<class T, class Compare, class Alloc>
	class red_black_tree_set {
	public:
		typedef T															mapped_type;
		typedef Compare														key_compare;
		typedef typename Alloc::template rebind< tree_node_v<T> >::other	allocator_type;
		typedef typename allocator_type::value_type							value_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef typename allocator_type::size_type							size_type;
		typedef typename allocator_type::difference_type					difference_type;

	private:
		allocator_type	_allocator;
		key_compare		_cmp;
		pointer			_root;
		pointer			_nil;
		size_type		_size;

	public:
		red_black_tree_set() : _allocator(), _cmp(key_compare()), _root(_allocator.allocate(1)), _nil(_root), _size(0) {
			_allocator.construct(_nil, value_type(mapped_type(), NULL, nil_node));
		}

		~red_black_tree_set() {
			_clear(_root);
			_free_node(_nil);
		}

		red_black_tree_set& operator =(const red_black_tree_set& other) {
			if (this == &other)
				return *this;
			clear();
			_cmp = other._cmp;
			for (pointer ptr = other.begin(); ptr != other.end(); ptr = _next(ptr)) {
				insert(*ptr->data);
			}
			return *this;
		}

		ft::pair<pointer, bool> insert(mapped_type value) {
			pointer current, parent, new_node;
			for (current = _root, parent = _nil; current != _nil;) {
				if (value == *current->data)
					return ft::pair<pointer, bool>(current, false);
				parent = current;
				current = _cmp(value, *current->data) ? current->left : current->right;
			}
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value_type(value, _nil, red_node));
			new_node->parent = parent;
			if (parent == _nil)
				_root = new_node;
			else {
				if (_cmp(value, *parent->data))
					parent->left = new_node;
				else
					parent->right = new_node;
			}
			_repair_tree_structure(new_node);
			_nil->parent = _maximum(_root);
			++_size;
			return ft::pair<pointer, bool>(new_node, true);
		}

		bool erase(value_type key) {
			pointer node = _find(_root, key);
			if (node == _nil)
				return false;
			_erase_node(node);
			--_size;
			return true;
		}

		size_type size() const {
			return _size;
		}
		size_type max_size() const {
			return _allocator.max_size();
		}

		pointer begin() {
			return _minimum(_root);
		}
		pointer begin() const {
			return _minimum(_root);
		}

		pointer end() {
			return _nil;
		}
		pointer end() const {
			return _nil;
		}

		void clear() { _clear(_root); }

		void swap(red_black_tree_set& other) {
			std::swap(_nil, other._nil);
			std::swap(_root, other._root);
			std::swap(_cmp, other._cmp);
			std::swap(_allocator, other._allocator);
			std::swap(_size, other._size);
		}

		pointer find(value_type value) const {
			return _find(_root, value);
		}

		pointer lower_bound(const mapped_type value) const {
			if (_root != _nil)
			{
				pointer node;
				pointer tmp;
				for (node = _root, tmp = _root; node != _nil;) {
					if (value == *node->data)
						return node;
					if (_cmp(value, *node->data)) {
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return _cmp(value, *tmp->data) ? tmp : _nil;
			}
			return _nil;
		}

		pointer upper_bound(const mapped_type value) const {
			if (_root != _nil)
			{
				pointer	node;
				pointer	tmp;
				for (node = _root, tmp = _root; node != _nil;) {
					if (_cmp(value, *node->data)) {
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return _cmp(value, *tmp->data) ? tmp : _nil;
			}
			return _nil;
		}

	private:
		void _rotate_right(pointer x) {
			pointer y = x->left;
			x->left = y->right;
			if (y->right != _nil)
				y->right->parent = x;

			if (y != _nil)
				y->parent = x->parent;
			if (x->parent == _nil)
				_root = y;
			else {
				if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
			}

			y->right = x;
			if (x != _nil)
				x->parent = y;
		}

		void _rotate_left(pointer x) {
			pointer y = x->right;
			x->right = y->left;
			if (y->left != _nil)
				y->left->parent = x;

			if (y != _nil)
				y->parent = x->parent;
			if (x->parent == _nil)
				_root = y;
			else {
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
			}

			y->left = x;
			if (x != _nil)
				x->parent = y;
		}


		pointer _find(pointer node, value_type value) const {
			if (node != _nil) {
				if (*node->data == *value.data)
					return node;
				else if (_cmp(*value.data, *node->data))
					return _find(node->left, value);
				else
					return _find(node->right, value);
			}
			return _nil;
		}

		pointer _maximum(pointer node) const {
			while (node->type != nil_node && node->right->type != nil_node) {
				node = node->right;
			}
			return node;
		}

		pointer _minimum(pointer node) const {
			while (node->type != nil_node && node->left->type != nil_node) {
				node = node->left;
			}
			return node;
		}

		pointer _next(pointer node) {
			if (node->type == nil_node)
				return node;

			if (node->right->type != nil_node)
				return _minimum(node->right);

			pointer tmp = node->parent;
			for (; tmp->type != nil_node && node == tmp->right; node = tmp, tmp = tmp->parent) { }
			return tmp;
		}

		pointer _prev(pointer node) {
			if (node->type == nil_node)
				return node->parent;

			if (node->type != nil_node && node->left->type != nil_node)
				return _maximum(node->left);

			pointer tmp = node->parent;
			for (; tmp->type != nil_node && node == tmp->left; node = tmp, tmp = tmp->parent) { }
			return tmp->type != nil_node ? tmp : node;
		}

		void _free_node(const pointer& node) {
			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
		}

		void _erase_node(pointer node_to_erase) {
			pointer x, y;

			if (node_to_erase != _nil) {
				if (node_to_erase->left == _nil || node_to_erase->right == _nil)
					y = node_to_erase;
				else {
					y = node_to_erase->right;
					for (; y->left != _nil; y = y->left) { }
				}

				if (y->left != _nil)
					x = y->left;
				else
					x = y->right;

				if (x != _nil)
					x->parent = y->parent;
				if (y->parent == _nil)
					_root = x;

				else {
					if (y == y->parent->left)
						y->parent->left = x;
					else
						y->parent->right = x;
				}

				if (y != node_to_erase) {
					delete node_to_erase->data;
					node_to_erase->data = new mapped_type (*y->data);
				}

				if (y->type == black_node)
					_repair_tree_structure_erase(x);

				_allocator.destroy(y);
				_allocator.deallocate(y, 1);
				_nil->parent = _maximum(_root);
			}
		}

		void _repair_tree_structure(pointer x) {
			while (x != _root && x->parent->type == red_node) {
				if (x->parent == x->parent->parent->left) {
					pointer y = x->parent->parent->right;
					if (y->type == red_node) {
						x->parent->type = black_node;
						y->type = black_node;
						x->parent->parent->type = red_node;
						x = x->parent->parent;
					} else {
						if (x == x->parent->right) {
							x = x->parent;
							_rotate_left(x);
						}
						x->parent->type = black_node;
						x->parent->parent->type = red_node;
						_rotate_right(x->parent->parent);
					}
				} else {
					pointer y = x->parent->parent->left;
					if (y->type == red_node) {
						x->parent->type = black_node;
						y->type = black_node;
						x->parent->parent->type = red_node;
						x = x->parent->parent;
					} else {
						if (x == x->parent->left) {
							x = x->parent;
							_rotate_right(x);
						}
						x->parent->type = black_node;
						x->parent->parent->type = red_node;
						_rotate_left(x->parent->parent);
					}
				}
			}
			_root->type = black_node;
		}

		void _repair_tree_structure_erase(pointer x) {
			for (; x != _root && x->type == black_node;) {
				if (x == x->parent->left) {
					pointer w = x->parent->right;
					if (w->type == red_node) {
						w->type = black_node;
						x->parent->type = red_node;
						_rotate_left(x->parent);
						w = x->parent->right;
					}
					if (w->left->type == black_node && w->right->type == black_node) {
						w->type = red_node;
						x = x->parent;
					} else {
						if (w->right->type == black_node) {
							w->left->type = black_node;
							w->type = red_node;
							_rotate_right(w);
							w = x->parent->right;
						}
						w->type = x->parent->type;
						x->parent->type = black_node;
						w->right->type = black_node;
						_rotate_left(x->parent);
						x = _root;
					}
				} else {
					pointer w = x->parent->left;
					if (w->type == red_node) {
						w->type = black_node;
						x->parent->type = red_node;
						_rotate_right(x->parent);
						w = x->parent->left;
					}
					if (w->right->type == black_node && w->left->type == black_node) {
						w->type = red_node;
						x = x->parent;
					} else {
						if (w->left->type == black_node) {
							w->right->type = black_node;
							w->type = red_node;
							_rotate_left(w);
							w = x->parent->left;
						}
						w->type = x->parent->type;
						x->parent->type = black_node;
						w->left->type = black_node;
						_rotate_right(x->parent);
						x = _root;
					}
				}
			}
			if (x->type != nil_node)
				x->type = black_node;
		}

		void _clear(pointer& node) {
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
}
#endif //MYCONTAINERS_RED_BLACK_TREE_SET_H
