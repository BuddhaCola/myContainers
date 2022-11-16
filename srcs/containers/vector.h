#ifndef CONTAINERS_VECTOR_H
#define CONTAINERS_VECTOR_H
namespace ft{
	template<class T, class Allocator = std::allocator<T> > class vector {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::pointer pointer;
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
		explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _pointer(0), _size(0), _capacity(0) {}
		explicit vector(T const &valueType, size_t size) : _pointer(valueType), _size(size) {}
		vector (const vector& x) : _size(x._size), _capacity(x._capacity) {
//			this = x;
		}

		//member functions

		T& at(size_t i) {
			if (i >= _size)
				throw std::out_of_range("");//TODO
			return _pointer[i];
		}

		void clear() {
			for (; _size > 0; _size--)
				_allocator.destroy(_pointer + _size - 1);

		};

		bool empty() const {
			return _size == 0;
		}

		void reserve(size_t n) {
			T* newarr = reinterpret_cast<T*>(new int8_t [n * sizeof(T)]);
			if (n == 0)
				n = 1;
			for (size_t i = 0; i < _size; ++i) {
				new(newarr + i) T(_pointer[i]);
			}
			for (size_t i = 0; i < _size; ++i) {
				(_pointer + i)->~T();
			}
			delete[] reinterpret_cast<int_fast8_t*>(_pointer);
			_pointer = newarr;
			_capacity = n;
		}

		void resize(size_t n, const T &value = T()) {
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

		void push_back(const T &value) {
			if (_size == _capacity)
				resize(_size + 1, value);
			else
				_allocator.construct(_pointer + _size++, value);
		}

		void shrink_to_fit() {
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
		T& operator[](size_t i) {
			return _pointer[i];
		}
	};
}
#endif //CONTAINERS_VECTOR_H
