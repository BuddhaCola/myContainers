 //
// Created by Wedge Taylor on 10/18/21.
//

#ifndef MYCONTAINERS_VECTOR_HPP
#define MYCONTAINERS_VECTOR_HPP
# include <memory>

namespace ft {
	template <class T, class Allocator = std::allocator<T> > class Vector
	{
	private:

	public:
		typedef T					value_type;
		typedef std::allocator<T>	allocator_type;

	public:
		Vector() {
			std::cout << "Hi!" << std::endl;
		};
		Vector(Vector const &) {};
		Vector & operator=(Vector const &) {};
		~Vector() {};


		//Iterators:
		std::iterator<value_type, allocator_type> begin();
		//Return iterator to beginning (public member function )
		//
		//end
		//Return iterator to end (public member function )
		//
		//rbegin
		//Return reverse iterator to reverse beginning (public member function )
		//
		//rend
		//Return reverse iterator to reverse end (public member function )
		//
		//cbegin
		//Return const_iterator to beginning (public member function )
		//
		//cend
		//Return const_iterator to end (public member function )
		//
		//crbegin
		//Return const_reverse_iterator to reverse beginning (public member function )
		//
		//crend
		//Return const_reverse_iterator to reverse end (public member function )
	};
}
//Iterators:
//begin
//Return iterator to beginning (public member function )
//
//end
//Return iterator to end (public member function )
//
//rbegin
//Return reverse iterator to reverse beginning (public member function )
//
//rend
//Return reverse iterator to reverse end (public member function )
//
//cbegin
//Return const_iterator to beginning (public member function )
//
//cend
//Return const_iterator to end (public member function )
//
//crbegin
//Return const_reverse_iterator to reverse beginning (public member function )
//
//crend
//Return const_reverse_iterator to reverse end (public member function )
//
//
//Capacity:
//
//size
//Return size (public member function )
//
//max_size
//Return maximum size (public member function )
//
//resize
//Change size (public member function )
//
//capacity
//Return size of allocated storage capacity (public member function )
//
//empty
//Test whether vector is empty (public member function )
//
//reserve
//Request a change in capacity (public member function )
//
//shrink_to_fit
//Shrink to fit (public member function )
//
//
//Element access:
//
//operator[]
//Access element (public member function )
//
//at
//Access element (public member function )
//
//front
//Access first element (public member function )
//
//back
//Access last element (public member function )
//
//data
//Access data (public member function )
//
//
//Modifiers:
//
//assign
//Assign vector content (public member function )
//
//push_back
//Add element at the end (public member function )
//
//pop_back
//Delete last element (public member function )
//
//insert
//Insert elements (public member function )
//
//erase
//Erase elements (public member function )
//
//swap
//Swap content (public member function )
//
//clear
//Clear content (public member function )
//
//emplace
//Construct and insert element (public member function )
//
//emplace_back
//Construct and insert element at the end (public member function )
//
//
//Allocator:
//
//get_allocator
//Get allocator (public member function )
//
//
//Non-member function overloads
//
//relational operators
//Relational operators for vector (function template )
//
//swap
//Exchange contents of vectors (function template )

#endif //MYCONTAINERS_VECTOR_HPP
