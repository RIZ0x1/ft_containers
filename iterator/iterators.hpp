#ifndef FORWARD_ITERATOR_TPP
# define FORWARD_ITERATOR_TPP

#include "iterators_core.hpp"

namespace ft
{
	template <typename T>
	class forward_iterator : public iterator<forward_iterator_tag, T>
	{
	public:
		typedef typename iterator<forward_iterator_tag, T>::Category		iterator_category;
		typedef typename iterator<forward_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<forward_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<forward_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<forward_iterator_tag, T>::reference		reference;

	private:
		pointer	_ptr;

	public:
		bool			operator == (const forward_iterator<value_type> &other) const;
		value_type		operator *	(void) const;
		value_type		operator ++ (void);
		value_type		operator ++ (int);
	};

	template <typename T>
	class bidirectional_iterator : public forward_iterator<T>
	{
	public:
		typedef typename forward_iterator<T>::value_type value_type;
	public:
		value_type			operator -- (void);
		value_type			operator -- (int);
	};

	template <typename T>
    class random_access_iterator : public bidirectional_iterator<T>
	{
    public:
        typedef typename forward_iterator<T>::difference_type difference_type;

	public:
		bool		operator < (const random_access_iterator &other);
		bool		operator > (const random_access_iterator &other);
		bool		operator <= (const random_access_iterator &other);
		bool		operator >= (const random_access_iterator &other);

        random_access_iterator	operator += (const difference_type N);
        random_access_iterator	operator -= (const difference_type N);
        random_access_iterator	operator + (const difference_type N);
        random_access_iterator	operator - (const difference_type N);
	};

    template <typename T>
    class const_random_access_iterator : public random_access_iterator<const T>
    {
    };
}

#include "iterators.tpp"

#endif // FORWARD_ITERATOR_TPP
