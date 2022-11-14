#ifndef CONTAINERS_VECTOR_H
#define CONTAINERS_VECTOR_H
namespace FT{
	template<class T, class Allocator = std::allocator<T> > class vector {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::pointer pointer;
	private:
		allocator_type _alloc;
		pointer _pointer;
		size_t	_size;
		size_t	_capacity;
	public:
		vector(T const &valueType, size_t size) : _pointer(valueType), _size(size) {}
		T& operator[](size_t i) {
			return _pointer[i];
		}

		explicit vector(const allocator_type& alloc = allocator_type()) :_alloc(alloc), _pointer(0), _size(0), _capacity(0) { }

		T& at(size_t i) {
			if (i >= _size)
				throw std::out_of_range("");//TODO
			return _pointer[i];
		}

		void resize(size_t n, const T &value = T());

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

		void push_back(const T &value) {
			if (_size == _capacity) {
				reserve(_capacity * 2);
			}
			new(_pointer + _size) T(value);
			++_size;
		}


		void shrink_to_fit() {

		}

		size_t size() {
			return _size;
		}

		size_t capacity(){
			return _capacity;
		}
	};
}
#endif //CONTAINERS_VECTOR_H
