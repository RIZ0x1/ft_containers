#ifndef FORWARD_ITERATOR_TPP
# define FORWARD_ITERATOR_TPP

#include "iterators_core.hpp"

namespace ft
{
	// ? ***************************************************************
	// ? *                          FORWARD                            *
	// ? ***************************************************************

	template <typename T>
	class forward_iterator : public iterator<forward_iterator_tag, T>
	{
	public:
		typedef typename iterator<forward_iterator_tag, T>::Category		iterator_category;
		typedef typename iterator<forward_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<forward_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<forward_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<forward_iterator_tag, T>::reference		reference;
		typedef forward_iterator<T>								iterator;

	private:
		pointer	_ptr;

	public:
		bool					operator == (const forward_iterator<value_type> &other) const;
		value_type				operator *	(void) const;
		virtual iterator		operator ++ (void);
		virtual iterator		operator ++ (int);
	};

	// ? ***************************************************************
	// ? *                       BIDIRECTIONAL                         *
	// ? ***************************************************************

	template <typename T>
	class bidirectional_iterator : public forward_iterator<T>
	{
	public:
		typedef typename forward_iterator<T>::value_type	value_type;
		typedef bidirectional_iterator<T>					iterator;
	public:
		virtual iterator	    operator -- (void);
		virtual const iterator	operator -- (int);
	};

    template <typename T>
    class const_bidirectional_iterator : public bidirectional_iterator<const T>
    {
    };

    template <typename T>
	class reverse_bidirectional_iterator : public bidirectional_iterator<T>
	{
	public:
		typedef typename forward_iterator<T>::value_type	value_type;
		typedef reverse_bidirectional_iterator<T>			iterator;
	public:
		virtual iterator	operator ++ (void);
		virtual iterator	operator ++ (int);
		virtual iterator	operator -- (void);
		virtual iterator	operator -- (int);
	};

	// ? ***************************************************************
	// ? *                       RANDOM ACCESS                         *
	// ? ***************************************************************

	template <typename T>
    class random_access_iterator : public bidirectional_iterator<T>
	{
    public:
		typedef typename forward_iterator<T>::difference_type	difference_type;
		typedef random_access_iterator<T>						iterator;
	public:
		bool				operator < (const random_access_iterator &other);
		bool				operator > (const random_access_iterator &other);
		bool				operator <= (const random_access_iterator &other);
		bool				operator >= (const random_access_iterator &other);
		virtual iterator	operator += (const difference_type N);
		virtual iterator	operator -= (const difference_type N);
		virtual iterator	operator + (const difference_type N);
		virtual iterator	operator - (const difference_type N);
	};

	template <typename T>
	class reverse_random_access_iterator : public reverse_bidirectional_iterator<T>
	{
	public:
		typedef typename forward_iterator<T>::difference_type	difference_type;
		typedef reverse_random_access_iterator					iterator;
	public:

	};

    template <typename T>
    class const_random_access_iterator : public random_access_iterator<const T>
    {
    };
}

#include "iterators.tpp"

#endif // FORWARD_ITERATOR_TPP
