#ifndef FORWARD_ITERATOR_TPP
# define FORWARD_ITERATOR_TPP

#include "iterators_core.hpp"

namespace ft
{
	// ? ***************************************************************
	// ? *                       VECTOR ITERATOR                       *
	// ? ***************************************************************

	template <typename T>
	class contiguous_iterator : public iterator_traits< iterator<random_access_iterator_tag, T> >
	{
	public:
		typedef typename iterator<forward_iterator_tag, T>::Category		iterator_category;
		typedef typename iterator<forward_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<forward_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<forward_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<forward_iterator_tag, T>::reference		reference;
		typedef contiguous_iterator<T>										iterator;

	protected:
		pointer _ptr;
	public:
		contiguous_iterator();
		contiguous_iterator(const iterator& other);
		~contiguous_iterator();

		bool						operator == (const iterator &other) const;
		bool						operator != (const iterator &other) const;
		bool						operator < (const iterator &other) const;
		bool						operator > (const iterator &other) const;
		bool						operator <= (const iterator &other) const;
		bool						operator >= (const iterator &other) const;
		value_type					operator *	(void) const;
		value_type					operator -> (void) const;
		virtual iterator			operator + (const difference_type N) const;
		virtual iterator			operator - (const difference_type N) const;
		virtual iterator			operator ++ (void);
		virtual const iterator		operator ++ (int);
		virtual iterator			operator -- (void);
		virtual const iterator		operator -- (int);
		virtual iterator			operator += (const difference_type N);
		virtual iterator			operator -= (const difference_type N);

	protected:
		inline pointer	get_pointer(void) const;
	};

	template <typename T>
	class const_contiguous_iterator : public contiguous_iterator<const T>
	{
	};

	template <typename T>
	class reverse_contiguous_iterator : public contiguous_iterator<T>
	{
	public:
		typedef typename iterator<forward_iterator_tag, T>::Category		iterator_category;
		typedef typename iterator<forward_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<forward_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<forward_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<forward_iterator_tag, T>::reference		reference;
		typedef reverse_contiguous_iterator								    iterator;

	public:
		reverse_contiguous_iterator();
		reverse_contiguous_iterator(const iterator& other);
		~reverse_contiguous_iterator();

		iterator			operator + (const difference_type N);
		iterator			operator - (const difference_type N);
		iterator			operator ++ (void);
		const iterator		operator ++ (int);
		iterator			operator -- (void);
		const iterator		operator -- (int);
		iterator			operator += (const difference_type N);
		iterator			operator -= (const difference_type N);
	};

	template <typename T>
	class const_reverse_contiguous_iterator : public reverse_contiguous_iterator<const T>
	{
	};
}

#include "contiguous_iterator.tpp"

#endif // FORWARD_ITERATOR_TPP
