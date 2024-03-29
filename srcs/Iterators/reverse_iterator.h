#ifndef MYCONTAINERS_REVERSE_ITERATOR_H
#define MYCONTAINERS_REVERSE_ITERATOR_H
#include "iterator_traits.h"
namespace ft {
	template<class IteratorType>
	class reverse_iterator {
	public:
		typedef IteratorType iterator_type;
		typedef typename ft::random_access_iterator_tag							iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
	private:
		iterator_type _base;
	public:
	public:
		reverse_iterator() { }

		reverse_iterator(const IteratorType& other) : _base(other.base()) { }

		reverse_iterator(const reverse_iterator& other) : _base(other.base()) { }

		template<typename I>
		reverse_iterator(const reverse_iterator<I>& other) : _base(other.base()) { }

		virtual ~reverse_iterator() { }

		iterator_type base() const {
		return _base;
		}

		reference operator*() const
		{
			iterator_type it(_base);
			--it;
			return *it;
		}

		pointer operator->() const {
		return &(operator*());
		}

		reverse_iterator operator+(difference_type n) const {
		return reverse_iterator(_base-n);
		}

		reverse_iterator operator-(difference_type n) const {
		return reverse_iterator(_base+n);
		}

		reverse_iterator& operator++() {
			_base--;
			return *this;
		}

		reverse_iterator& operator--() {
			_base++;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator temp(*this);
			_base--;
			return temp;
		}

		reverse_iterator operator--(int) {
			reverse_iterator temp(*this);
			_base++;
			return temp;
		}

		reverse_iterator& operator+=(difference_type n) {
			_base -= n;
			return *this;
		}

		reverse_iterator& operator-=(difference_type n) {
			_base += n;
			return *this;
		}

		reference operator[](difference_type n) const {
		return (this->base()[-n-1]);
		}

		template <class I>
		bool operator==(const reverse_iterator<I>& other) const {
			return _base == other.base();
		}

		template <class I>
		bool operator!=(const reverse_iterator<I>& other) const {
			return _base != other.base();
		}

		template <class I>
		bool operator<(const reverse_iterator<I>& other) const {
			return _base >  other.base();
		}

		template <class I>
		bool operator>(const reverse_iterator<I>& other) const {
			return _base <  other.base();
		}

		template <class I>
		bool operator<=(const reverse_iterator<I>& other) const {
			return _base >= other.base();
		}

		template <class I>
		bool operator>=(const reverse_iterator<I>& other) const {
			return _base <= other.base();
		}

		template <class I>
		difference_type operator-(const reverse_iterator<I>& other) {
			return other.base() - _base;
		}

		friend reverse_iterator operator+(difference_type n, const reverse_iterator& other) {
			return other + n;
		}
};
}
#endif //MYCONTAINERS_REVERSE_ITERATOR_H
