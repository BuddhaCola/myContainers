#ifndef STACK_HPP
#define STACK_HPP

#include "vector.h"
#include <memory>

namespace ft {
	template<class T, class Container = ft::vector<T, std::allocator<T> > >
	class stack {
	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;
	protected:
		container_type container;
	public:
		explicit stack<T>(container_type container) : container(container) {}
		stack()	: container() {}

		stack(stack &other) /*: container(other.container)*/{
			this->container = other.container;
		}
		~stack<T>(){}
		void push(const value_type& valueType) {
			container.push_back(valueType);
		}
		bool empty()	const {
			return container.empty();
		}
		size_type size() const {
			return container.size();
		}
		reference top() {
			return container.back();
		}
		const_reference top() const {
			return container.back();
		}
		void pop() {
			container.pop_back();
		}

		bool operator==(const stack &rhs) const {
			return container == rhs.container;
		}

		bool operator!=(const stack &rhs) const {
			return !(rhs == *this);
		}

		bool operator<(const stack &rhs) const {
			return container < rhs.container;
		}

		bool operator>(const stack &rhs) const {
			return rhs < *this;
		}

		bool operator<=(const stack &rhs) const {
			return !(rhs < *this);
		}

		bool operator>=(const stack &rhs) const {
			return !(*this < rhs);
		}
	};
}

#endif