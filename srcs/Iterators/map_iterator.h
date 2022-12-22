#ifndef MYCONTAINERS_MAP_ITERATOR_H
#define MYCONTAINERS_MAP_ITERATOR_H

#include "iterator_traits.h"
#include "../Utils/red_black_tree/tree_node.h"

namespace ft {
	template <class T1, class T2, class Iter>
	class map_iterator_kv {
	public:
		typedef Iter iterator_type;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference reference;

	private:
		typedef tree_node_kv<T1, T2>* node_pointer;
		node_pointer _ptr;

	public:
		map_iterator_kv(node_pointer ptr = 0) : _ptr(ptr) { }

		template<class U>
		map_iterator_kv(const map_iterator_kv<T1, T2, U>& other) :_ptr(other.base()) { }

		map_iterator_kv& operator=(const map_iterator_kv& other) {
			if (this == &other)
				return *this;
			_ptr = other._ptr;
			return *this;
		}

		~map_iterator_kv() { }

		node_pointer base() const {
			return _ptr;
		}

		bool operator==(const map_iterator_kv& other) const {
			return _ptr == other.base();
		}

		bool operator!=(const map_iterator_kv& other) const {
			return _ptr != other.base();
		}

		reference operator*() const {
			return *(_ptr->data);
		}

		pointer operator->() const {
			return _ptr->data;
		}

		map_iterator_kv& operator++() {
			_ptr = next(_ptr);
			return *this;
		}

		map_iterator_kv operator++(int) {
			map_iterator_kv tmp(*this);
			_ptr = next(_ptr);
			return tmp;
		}

		map_iterator_kv& operator--() {
			_ptr = prev(_ptr);
			return *this;
		}

		map_iterator_kv operator--(int) {
			map_iterator_kv tmp(*this);
			_ptr = prev(_ptr);
			return tmp;
		}

	private:
		node_pointer maximum(node_pointer node) {
			while (node->right->type != nil_node) {
				node = node->right;
			}
			return node;
		}

		node_pointer minimum(node_pointer node) {
			while (node->left->type != nil_node) {
				node = node->left;
			}
			return node;
		}

		node_pointer next(node_pointer node) {
			if (node->type == nil_node)
				return node;

			if (node->right->type != nil_node)
				return minimum(node->right);

			node_pointer ptr = node->parent;
			while (ptr->type != nil_node && node == ptr->right) {
				node = ptr;
				ptr = ptr->parent;
			}
			return ptr;
		}

		node_pointer prev(node_pointer node) {
			if (node->type == nil_node)
				return node->parent;

			if (node->type != nil_node && node->left->type != nil_node)
				return maximum(node->left);

			node_pointer ptr = node->parent;
			while (ptr->type != nil_node && node == ptr->left) {
				node = ptr;
				ptr = ptr->parent;
			}
			return ptr->type != nil_node ? ptr : node;
		}
	};

	template <class T, class Iter>
	class map_iterator_v {
	public:
		typedef Iter iterator_type;
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference reference;

	private:
		typedef tree_node_v<T>* node_pointer;
		node_pointer _ptr;

	public:
		map_iterator_v(node_pointer ptr = 0) : _ptr(ptr) { }

		template<class U>
		map_iterator_v(const map_iterator_v<T, U>& other) :_ptr(other.base()) { }

		map_iterator_v& operator=(const map_iterator_v& other) {
			if (this == &other)
				return *this;
			_ptr = other._ptr;
			return *this;
		}

		~map_iterator_v() { }

		node_pointer base() const {
			return _ptr;
		}

		bool operator==(const map_iterator_v& other) const {
			return _ptr == other.base();
		}

		bool operator!=(const map_iterator_v& other) const {
			return _ptr != other.base();
		}

		reference operator*() const {
			return *(_ptr->data);
		}

		pointer operator->() const {
			return _ptr->data;
		}

		map_iterator_v& operator++() {
			_ptr = next(_ptr);
			return *this;
		}

		map_iterator_v operator++(int) {
			map_iterator_v tmp(*this);
			_ptr = next(_ptr);
			return tmp;
		}

		map_iterator_v& operator--() {
			_ptr = prev(_ptr);
			return *this;
		}

		map_iterator_v operator--(int) {
			map_iterator_v tmp(*this);
			_ptr = prev(_ptr);
			return tmp;
		}

	private:
		node_pointer maximum(node_pointer node) {
			while (node->right->type != nil_node) {
				node = node->right;
			}
			return node;
		}

		node_pointer minimum(node_pointer node) {
			while (node->left->type != nil_node) {
				node = node->left;
			}
			return node;
		}

		node_pointer next(node_pointer node) {
			if (node->type == nil_node)
				return node;

			if (node->right->type != nil_node)
				return minimum(node->right);

			node_pointer ptr = node->parent;
			while (ptr->type != nil_node && node == ptr->right) {
				node = ptr;
				ptr = ptr->parent;
			}
			return ptr;
		}

		node_pointer prev(node_pointer node) {
			if (node->type == nil_node)
				return node->parent;

			if (node->type != nil_node && node->left->type != nil_node)
				return maximum(node->left);

			node_pointer ptr = node->parent;
			while (ptr->type != nil_node && node == ptr->left) {
				node = ptr;
				ptr = ptr->parent;
			}
			return ptr->type != nil_node ? ptr : node;
		}
	};
}
#endif //MYCONTAINERS_MAP_ITERATOR_H
