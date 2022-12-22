#ifndef MYCONTAINERS_SET_H
#define MYCONTAINERS_SET_H

#include "../Iterators/map_iterator.h"
#include "../Utils/red_black_tree/red_black_tree_set.h"
//#include "../Utils/pair.h"
#include "../Iterators/reverse_iterator.h"

namespace ft {
	template<
			class Key,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key>
	> class set {
	public:
		typedef Key											value_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef ft::map_iterator_v<Key, value_type*>		iterator;
		typedef ft::map_iterator_v<Key, const value_type*>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool> {
			friend class set;
		protected:
			key_compare _comp;
			value_compare(key_compare comp) : _comp(comp) { }

		public:
			bool operator()(const value_type& x, const value_type& y) const {
				return _comp(x, y);
			}
		};

	private:
		red_black_tree_set<Key, Compare, Allocator> _tree;
		key_compare _key_compare;
		allocator_type _allocator;

	public:
		explicit set(	const Compare& comp = key_compare(),
						const Allocator& alloc = allocator_type()
		): _tree(), _key_compare(comp), _allocator(alloc) { }

		template<class InputIterator>
		set(	InputIterator first,
				InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()
		) :_tree(), _key_compare(comp), _allocator(alloc) { insert(first, last); }

		set(const set& other) { *this = other; }

		~set() { }

		set& operator=(const set& other)
		{
			_allocator = other._allocator;
			_key_compare = other._key_compare;
			_tree = other._tree;
			return *this;
		}

		allocator_type get_allocator() const {
			return _allocator;
		}

		reverse_iterator rbegin() {
			return reverse_iterator(_tree.end());
		}
		const_reverse_iterator rbegin() const {
			return reverse_iterator(_tree.end());
		}

		reverse_iterator rend() {
			return reverse_iterator(_tree.begin());
		}
		const_reverse_iterator rend() const {
			return reverse_iterator(_tree.begin());
		}

		iterator begin() {
			return iterator(_tree.begin());
		}
		const_iterator begin() const {
			return const_iterator(_tree.begin());
		}

		iterator end() {
			return iterator(_tree.end());
		}
		const_iterator end() const {
			return const_iterator(_tree.end());
		}

		bool empty() const {
			return _tree.size() == 0;
		}

		size_type size() const {
			return _tree.size();
		}

		size_type max_size() const {
			return _tree.max_size();
		}

		void clear() {
			_tree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type& val) {
			return _tree.insert(val);
		}

		iterator insert(iterator hint, const value_type& val) {
			(void) hint;
			return _tree.insert(val);
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			for (; first!=last; ++first) {
				_tree.insert(value_type(*first));
			}
		}

		friend bool operator>(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return rhs<lhs;
		}

		friend bool operator<(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		friend bool operator==(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

		friend bool operator!=(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return !(lhs==rhs);
		}

		friend bool operator>=(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return !(lhs<rhs);
		}

		friend bool operator<=(
				const set<Key, Compare, Allocator>& lhs,
				const set<Key, Compare, Allocator>& rhs
		) {
			return !(rhs<lhs);
		}
	};
}
#endif //MYCONTAINERS_SET_H
