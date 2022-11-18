#ifndef MYCONTAINERS_VECTOR_ITERATOR_H
#define MYCONTAINERS_VECTOR_ITERATOR_H
#include "iterator_traits.h"

namespace ft {
template<class IteratorType>
class vector_iterator {
public:
	typedef IteratorType iterator_type;
	typedef typename ft::random_access_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference reference;
protected:
	pointer _pointer;
public:

	vector_iterator(pointer ptr = 0) : _pointer(ptr) {};

	template<class I>
	vector_iterator(const vector_iterator<I> &it) : _pointer(it.base()) {};

	virtual ~vector_iterator() {}

	pointer base() const { return _pointer; }

	vector_iterator &operator=(const vector_iterator &other) {
		if (this == &other)
			return *this;
		_pointer = other._pointer;
		return *this;
	}

	vector_iterator &operator++() {
		_pointer++;
		return *this;
	}

	vector_iterator operator++(int) {
		vector_iterator prev(*this);
		operator++();
		return prev;
	}

	template<class I>
	bool operator==(const vector_iterator<I> &it) const { return _pointer == it.base(); }

	template<class I>
	bool operator!=(const vector_iterator<I> &it) const { return _pointer != it.base(); }

	vector_iterator &operator--() {
		_pointer--;
		return *this;
	}

	vector_iterator operator--(int) {
		vector_iterator prev(*this);
		operator--();
		return prev;
	}

	vector_iterator operator+(difference_type n) const {
		return _pointer + n;
	}

	vector_iterator operator-(difference_type n) const { return _pointer - n; }

	template<typename T>
	ptrdiff_t operator-(const vector_iterator<T> &it) { return this->base() - it.base(); }

	pointer operator->() { return _pointer; }

	template<class I>
	bool operator>(const vector_iterator<I> &it) const { return _pointer > it.base(); }

	template<class I>
	bool operator<(const vector_iterator<I> &it) const { return _pointer < it.base(); }

	template<class I>
	bool operator>=(const vector_iterator<I> &it) const { return _pointer >= it.base(); }

	template<class I>
	bool operator<=(const vector_iterator<I> &it) const { return _pointer <= it.base(); }

	vector_iterator operator+=(difference_type n) {
		_pointer += n;
		return *this;
	}

	vector_iterator operator-=(difference_type n) {
		_pointer -= n;
		return *this;
	}

	reference operator*() { return *_pointer; }

	reference operator[](difference_type n) const { return _pointer[n]; }
};
}
#endif //MYCONTAINERS_VECTOR_ITERATOR_H
