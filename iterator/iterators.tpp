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
typename forward_iterator<value_type>::value_type	forward_iterator<value_type>::operator * () const
{
    return (*_ptr);
}

template <typename value_type>
typename forward_iterator<value_type>::iterator	forward_iterator<value_type>::operator ++ ()
{
	pointer	tmp;

	tmp = _ptr;
	(_ptr++);
	return (*tmp);
}

template <typename value_type>
const typename forward_iterator<value_type>::iterator	forward_iterator<value_type>::operator ++ (int)
{
	(_ptr++);
	return (*_ptr);
}

// ? ***************************************************************************
// ? *                         BIDIRECTIONAL ITERATOR                          *
// ? ***************************************************************************

using ft::bidirectional_iterator;
using ft::reverse_bidirectional_iterator;

template <typename value_type>
typename bidirectional_iterator<value_type>::iterator    bidirectional_iterator<value_type>::operator -- ()
{
	(this->_ptr--);
	return (*(this->_ptr));
}

template <typename value_type>
const typename bidirectional_iterator<value_type>::iterator	bidirectional_iterator<value_type>::operator -- (int)
{
	pointer	tmp;

	tmp = this->_ptr;
	(this->_ptr--);
	return (*tmp);
}

// * ********************* REVERSE BIDIRECTIONAL ITERATOR **********************

template <typename value_type>
typename reverse_bidirectional_iterator<value_type>::iterator    reverse_bidirectional_iterator<value_type>::operator ++ ()
{
	(this->_ptr--);
	return (*(this->_ptr));
}

template <typename value_type>
const typename reverse_bidirectional_iterator<value_type>::iterator	reverse_bidirectional_iterator<value_type>::operator ++ (int)
{
	pointer	tmp;

	tmp = this->_ptr;
	(this->_ptr--);
	return (*tmp);
}

template <typename value_type>
typename reverse_bidirectional_iterator<value_type>::iterator    reverse_bidirectional_iterator<value_type>::operator -- ()
{
	pointer	tmp;

	this->_ptr;

	tmp = this->_ptr;
	(this->_ptr++);
	return (*tmp);
}

template <typename value_type>
const typename reverse_bidirectional_iterator<value_type>::iterator	reverse_bidirectional_iterator<value_type>::operator -- (int)
{
	this->_ptr++;
	return *(this->_ptr);
}

// ? ***************************************************************************
// ? *                          RANDOM ACESS ITERATOR                          *
// ? ***************************************************************************




