#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <limits>
#include <iostream>
#include "contiguous_iterator.hpp"

namespace ft {
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;

        typedef typename ft::contiguous_iterator<value_type>				iterator;
		typedef typename ft::const_contiguous_iterator<value_type>			const_iterator;
		typedef typename ft::reverse_contiguous_iterator<value_type>		reverse_iterator;
		typedef typename ft::const_reverse_contiguous_iterator<value_type>	const_reverse_iterator;

	private:
		pointer				_array;
		value_type*			_begin;
		value_type*			_end;
		allocator_type*		_alloc;
		size_type			_capacity;

		// ? ***********************************************************************
		// ?                      CONSTRUCTORS & DESTRUCTOR                        *
		// ? ***********************************************************************
	public:
		vector();
		vector(const vector &other);
		explicit vector(const allocator_type &alloc);
		explicit vector(size_type count, const value_type &value = value_type(), const allocator_type &alloc = allocator_type());
		template <class InputIt> vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type());
		~vector();

		// ? ***********************************************************************
		// ?                            MEMBER FUNCTIONS                           *
		// ? ***********************************************************************

		void		assign(size_type count, const value_type& value);
		template <class InputIt> void	assign(InputIt first, InputIt last);
		Allocator	get_allocator() const; // TODO: returns the allocator associated with the container

		// ? ***********************************************************************
		// ?                             ELEMENT ACCESS                            *
		// ? ***********************************************************************

		value_type&			front(void);
		const value_type&	front(void) const;
		value_type&			back(void);
		const value_type&	back(void) const;
		value_type&			at(size_type pos); // TODO: returns _array[pos] with bounds checking
		const value_type&	at(size_type pos) const;
		value_type*			data(void); // TODO: returns a pointer to _array[0]
		const value_type*	data(void) const;

		// ? ***********************************************************************
		// ?                               ITERATORS                               *
		// ? ***********************************************************************

		iterator			begin(void);
		iterator 			end(void);
		const_iterator		end(void) const;

		// ? ***********************************************************************
		// ?                               CAPACITY                                *
		// ? ***********************************************************************

		bool		empty(void) const; // TODO: is empty
		size_type	size(void) const; // TODO: returns the nbr of elems in the cont (std::distance)
		size_type	max_size(void) const; // TODO: returns the max nbr of elems the cont is able to hold due system (std::distance)
		void		reserve(size_type new_cap); // TODO: https://en.cppreference.com/w/cpp/container/vector/reserve
		size_type	capacity(void) const; // TODO: returns the nbr of elems that the cont has currently allocated space for

		// ? ***********************************************************************
		// ?                               MODIFIERS                               *
		// ? ***********************************************************************

		void		clear(void); // TODO: Erases all elements from the container. After this call, size() returns zero
		iterator	erase(iterator pos); // TODO: Removes the element at pos
		iterator	erase(iterator first, iterator last); // TODO: Removes the elements in the range [first, last)
		void		push_back(const T& value); // TODO: The new element is initialized as a copy of value
		void		pop_back(void); // TODO: Removes the last element of the container
		void		resize(size_type count); // TODO: https://en.cppreference.com/w/cpp/container/vector/resize
		void		resize(size_type count, T value = T()); // TODO: https://en.cppreference.com/w/cpp/container/vector/resize
		void		swap(vector& other); // TODO: https://en.cppreference.com/w/cpp/container/vector/swap
		void		insert(iterator pos, size_type count, const T& value); // TODO: inserts value before pos
		iterator	insert(iterator pos, const value_type& value); // TODO: inserts value before pos
		template<class InputIt> void insert( iterator pos, InputIt first, InputIt last ); // TODO: https://en.cppreference.com/w/cpp/container/vector/insert

		// ? ***********************************************************************
		// ?                               OPERATORS                               *
		// ? ***********************************************************************

		vector&		operator = (const vector &other);
		value_type&	operator [] (size_type pos) const;

	private:
		value_type*		_get_array(void) const;
		value_type*		_copy_array(pointer data, const size_type size);
		void			_set_capacity(size_type new_capacity);
		void			_set_size(size_type new_size);
		bool			_reallocate(size_type new_capacity);
	};
}

#include "vector.tpp"

#endif // * FT_VECTOR_HPP
