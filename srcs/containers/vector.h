#ifndef CONTAINERS_VECTOR_H
#define CONTAINERS_VECTOR_H

#include "../Utils/Ultils.h"
#include "../Iterators/vector_iterator.h"

namespace ft{
	template<class T, class Allocator = std::allocator<T> > class vector {
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::reference			reference;
		typedef ft::vector_iterator<pointer>				iterator;
		typedef ft::vector_iterator<const_pointer>			const_iterator;
	private:
		allocator_type _allocator;
		pointer _pointer;
		size_t	_size;
		size_t	_capacity;
	public:
		//constructors
		//		✅default (1)
		//		explicit vector (const allocator_type& alloc = allocator_type());
		//		fill (2)
		//		explicit vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type());
		//		range (3)
		//		template <class InputIterator>         vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());
		//		✅copy (4)
		//		vector (const vector& x);
		explicit vector (const allocator_type& alloc = allocator_type()):
				_allocator(alloc), _pointer(NULL), _size(0), _capacity(0) {}

		explicit vector (size_type n,
						 const value_type& val = value_type(),
						 const allocator_type& alloc =allocator_type()):
				_allocator(alloc), _pointer(NULL), _size(0), _capacity(0) {
			assign(n, val);
		}

		template <class InputIterator>
		vector (InputIterator first,
				InputIterator last,
				const allocator_type& alloc = allocator_type()):
				_allocator(alloc), _pointer(NULL), _size(0), _capacity(0) {
			assign(first, last);
		}

		vector(const vector& other) : _allocator(other._allocator), _pointer(0), _size(0), _capacity(0) {
			assign(other.begin(), other.end());
		}

		~vector()
		{
			clear();
			if (_capacity > 0)
				_allocator.deallocate(_pointer, _capacity);
		}

		//member functions
		template <class InputIterator>
		void assign(
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
				InputIterator last) {
			clear();
			reserve(ft::distance(first, last));
			insert(begin(), first, last);
		};

		void assign(size_type n, const value_type& val) {
			clear();
			reserve(n);
			insert(begin(), n, val);
		};

		T& at(size_t i) {
			if (i >= _size)
				throw std::out_of_range("vector");//TODO
			return _pointer[i];
		}

		iterator begin() { return iterator(_pointer); };
		iterator end() { return iterator(_pointer + _size); };

		const_iterator begin() const { return const_iterator(_pointer); };
		const_iterator end() const { return const_iterator(_pointer + _size); };

		void clear() {
			for (; _size > 0; _size--)
				_allocator.destroy(_pointer + _size - 1);
		};

		void clear_when_exception(int i, pointer new_ptr, size_type cap) {
			while (i--) {
				_allocator.destroy(new_ptr + i);
			}
			_allocator.deallocate(new_ptr, cap);
		};

		pointer data() {
			return _pointer;
		}

		bool empty() const {
			return _size == 0;
		}

		void fill_new_elements(pointer new_ptr, size_type cap, size_type n, const value_type& val){
			size_type i = 0;
			try {
				for (; i < n; i++) {
					_allocator.construct(new_ptr + i, val);
				}
			}
			catch (...) {
				clear_when_exception(i, new_ptr, cap);
				throw ;
			}
		}

		template <class InputIterator>
		void fill_new_elements (pointer new_ptr,
								size_type cap,
								InputIterator first,
								InputIterator last){
			int i = 0;
			try {
				while (first != last) {
					_allocator.construct(new_ptr + i, *first);
					first++;
					i++;
				}
			}
			catch (...) {
				clear_when_exception(i, new_ptr, cap);
				throw ;
			}
		};

		iterator insert (iterator position, const value_type& val) {
			size_type pos = ft::distance(begin(), position);
			insert(position, 1, val);
			return iterator(_pointer + pos);
		};

		void insert (iterator position, size_type n, const value_type& val) {
			size_type pos = ft::distance(begin(), position);
			size_type new_cap;
			size_type new_size = _size + n;
			pointer new_pointer;

			if (_size + n > _capacity) {
				new_cap = !_capacity ? n : _capacity * 2 < n + _size ? _size + n : _capacity * 2;
				new_pointer = _allocator.allocate(new_cap);
				move(new_pointer, pos, n);
				fill_new_elements(new_pointer + pos, new_cap, n, val);

				clear();
				_allocator.deallocate(_pointer, _capacity);
				_capacity = new_cap;
				_pointer = new_pointer;
				_size = new_size;

			} else {
				move(_pointer, pos, n);
				fill_new_elements(_pointer + pos, _capacity, n, val);
				_size = new_size;
			}
		}

		template <class InputIterator>
		void insert (iterator position,
					 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
					 InputIterator last) {
			size_type n = ft::distance(first, last);
			size_type pos = ft::distance(begin(), position);
			size_type new_cap;
			size_type new_size = _size + n;
			pointer new_pointer;

			if (_size + n > _capacity) {
				new_cap = !_capacity ? n : _capacity * 2 < n + _size ? _size + n : _capacity * 2;

				new_pointer = _allocator.allocate(new_cap);

				move(new_pointer, pos, n);
				fill_new_elements(new_pointer + pos, new_cap, first, last);

				clear();
				_allocator.deallocate(_pointer, _capacity);
				_capacity = new_cap;
				_pointer = new_pointer;
				_size = new_size;
			} else {
				move(_pointer, pos, n);
				fill_new_elements(_pointer + pos, _capacity, first, last);
				_size = new_size;
			}
		}

		void move(pointer ptr, size_type start_pos, size_type new_elements_size){
			if (ptr) {
				move_head(ptr, start_pos);
				move_tail(ptr, start_pos, new_elements_size);
			}
		}

		void move_head(pointer ptr, size_type start_pos){
			for (size_type i = 0; i < start_pos; i++) {
				_allocator.construct(ptr+i, _pointer[i]);
			}
		}

		void move_tail(pointer ptr, size_type start_pos, size_type new_elements_size){
			for (size_type i = 0; i < _size-start_pos; i++) {
				_allocator.construct(ptr+_size+new_elements_size-1-i, _pointer[_size-1-i]);
			}
		}

		void reserve(size_t n) {
			if (n > _capacity) {
				pointer new_ptr = _allocator.allocate(n);
				if (_pointer)
				{
					int s = _size;
					while(s--){
						new_ptr[s] = _pointer[s - 1];
						_allocator.destroy(_pointer + s);
					}
					_allocator.deallocate(_pointer, _capacity);
				}
				_pointer = new_ptr;
				_capacity = n;
			}
//			if (n > capacity()) {
//				T *newarr = reinterpret_cast<T *>(new int8_t[n * sizeof(T)]);
//				if (n == 0)
//					n = 1;
//				for (size_t i = 0; i < _size; ++i) {
//					auto lol = _pointer[i]; //the fuck?!
//					new(newarr + i) T(lol);
//				}
//				for (size_t i = 0; i < _size; ++i) {
//					(_pointer + i)->~T();
//				}
//				delete[] reinterpret_cast<int_fast8_t *>(_pointer);
//				_pointer = newarr;
//				_capacity = n;
//			}
		}

		void push_back(const T &value) {
			if (_size == _capacity)
				resize(_size + 1, value);
			else
				_allocator.construct(_pointer + _size++, value);
		}

		void resize(size_type n, value_type value = value_type())
		{
			if (_size > n) {
				for (; _size > n; --_size)
					_allocator.destroy(_pointer + _size - 1);
			}
			else {
				if (!_capacity || n > 2 * _capacity)
					reserve(n);
				else if (n > _capacity)
					reserve(_capacity * 2);
				for (; _size < n; ++_size)
					_allocator.construct(_pointer + _size, value);
			}
		}

		void shrink_to_fit() {
			if (_size < _capacity)
			{

				pointer new_data = _pointer;
				_pointer = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; ++i)
					_allocator.construct(&_pointer[i], new_data[i]);
				size_type new_capacity = _size;
				if (_pointer)
					_allocator.deallocate(new_data, _capacity);
				_capacity = _size;
			}
		}

		size_t size() {
			return _size;
		}

		size_t capacity(){
			return _capacity;
		}

		size_t max_size(){
			return _allocator.max_size();
		}
		//operators
		reference operator[](difference_type n) { return _pointer[n]; }
		const_reference operator[](difference_type n) const { return _pointer[n]; }
		friend bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			if (lhs.size() == rhs.size()){
				return std::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			return false;
		};

		friend bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			return lhs != rhs;
		};

		friend bool operator<  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(),
											   rhs.begin(), rhs.end());
		};

		friend bool operator>  (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			return rhs<lhs;
		};

		friend bool operator<= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			return lhs <= rhs;
		};

		friend bool operator>= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
			return lhs >= rhs;
		};
	};
}
#endif //CONTAINERS_VECTOR_H
