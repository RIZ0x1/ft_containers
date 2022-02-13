#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <limits>
# include <iostream>
# include <stdexcept>
# include "ContiguousIterator.hpp"

# ifdef __unix
#  include <cstring>
# endif

namespace ft {
	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T															value_type;
		typedef Allocator													allocator_type;

		typedef typename ft::ContiguousIterator<value_type>					iterator;
		typedef typename ft::ConstContiguousIterator<value_type>			const_iterator;
		typedef typename ft::ReverseContiguousIterator<value_type>			reverse_iterator;
		typedef typename ft::ConstReverseContiguousIterator<value_type>		const_reverse_iterator;

		typedef unsigned long int											size_type;
		typedef typename iterator_traits<iterator>::reference				reference;
		typedef typename iterator_traits<iterator>::pointer					pointer;
		typedef typename iterator_traits<iterator>::difference_type			difference_type;
		typedef typename iterator_traits<iterator>::reference				const_reference;
		typedef typename iterator_traits<iterator>::pointer					const_pointer;

	private:
		pointer				_array;
		pointer				_end;
		allocator_type		_alloc;
		size_type			_capacity;

	public:
		vector();
		vector(const vector &other);
		explicit vector(const allocator_type &alloc);
		explicit vector(size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIt> vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
		~vector();

		void				assign(size_type count, const value_type& value);
		allocator_type		get_allocator() const;
		template <class InputIt> void assign(InputIt first, InputIt last);

		reference			front(void);
		const_reference 	front(void) const;
		reference			back(void);
		const_reference		back(void) const;
		reference			at(size_type pos);
		const_reference 	at(size_type pos) const;
		pointer				data(void);
		const_pointer 		data(void) const;

		iterator			begin(void);
		const_iterator		begin(void) const;
		iterator 			end(void);
		const_iterator		end(void) const;

		bool				empty(void) const;
		size_type			size(void) const;
		size_type			max_size(void) const;
		void				reserve(size_type new_cap);
		size_type			capacity(void) const;

		void				clear(void);
		iterator			erase(iterator pos);
		iterator			erase(iterator first, iterator last);
		void				push_back(const value_type& value);
		void				pop_back(void);
		void				resize(size_type count);
		void				resize(size_type count, value_type value = value_type());
		void				swap(vector& other);
		void				insert(iterator pos, size_type count, const_reference value);
		iterator			insert(iterator pos, const_reference value);
		template<class InputIt> void insert( iterator pos, InputIt first, InputIt last );

		vector&				operator = (const vector &other);
		value_type&			operator [] (size_type pos) const;

	private:
		void		_copy_array(const pointer start, const_pointer end, pointer result);
		pointer		_allocate_array(size_type capacity);
		void		_destroy_array(iterator start, iterator end);
		void		_reallocate(size_type new_capacity);
		void		_reallocate(size_type new_capacity, pointer copy_start_point, pointer copy_end_point);
	};
}

# include "vector.tpp"

#endif // * VECTOR_HPP
