#include "iterators.hpp"

// ? ***************************************************************************
// ? *                            FORWARD ITERATOR                             *
// ? ***************************************************************************

using ft::forward_iterator;

template <typename value_type>
bool	forward_iterator<value_type>::operator == (const forward_iterator<value_type> &other) const
{
	return (this->ptr == other.ptr);
}

template <typename value_type>
forward_iterator<value_type>::value_type	forward_iterator<value_type>::operator * (void) const
{
	return (*ptr);
}

template <typename value_type>
forward_iterator<value_type>::value_type	forward_iterator<value_type>::operator ++ (void)
{
	pointer	tmp;

	tmp = _ptr;
	(_ptr++);
	return (*tmp);
}

template <typename value_type>
forward_iterator<value_type>::value_type	forward_iterator<value_type>::operator ++ (int)
{
	(_ptr++);
	return (*_ptr);
}

// ? ***************************************************************************
// ? *                         BIDIRECTIONAL ITERATOR                          *
// ? ***************************************************************************

using ft::bidirectional_iterator;

template <typename value_type>
bidirectional_iterator<value_type>::value_type bidirectional_iterator<value_type>::operator -- (void)
{

}

template <typename value_type>
bidirectional_iterator<value_type>::value_type bidirectional_iterator<value_type>::operator -- (int)
{
	
}
