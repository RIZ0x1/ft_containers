#include "contiguous_iterator.hpp"

// ? **************************************************************************
// ? *                          CONTIGUOUS ITERATOR                           *
// ? **************************************************************************

using ft::contiguous_iterator;

template <typename value_type>
bool	contiguous_iterator<value_type>::operator == (const iterator &other) const
{
	return ( this->get_pointer() == other.get_pointer() );
}

template <typename value_type>
bool	contiguous_iterator<value_type>::operator != (const iterator &other) const
{
	return ( this->get_pointer() != other.get_pointer() );
}

template <typename value_type>
bool	contiguous_iterator<value_type>::operator < (const iterator &other) const
{
	return ( this->get_pointer() < other.get_pointer() );
}

template <typename value_type>
bool	contiguous_iterator<value_type>::operator > (const iterator &other) const
{
	return ( this->get_pointer() > other.get_pointer() );
}

template <typename value_type>
bool	contiguous_iterator<value_type>::operator <= (const iterator &other) const
{
	return ( this->get_pointer() <= other.get_pointer() );
}

template <typename value_type>
bool	contiguous_iterator<value_type>::operator >= (const iterator &other) const
{
	return ( this->get_pointer() >= other.get_pointer() );
}

template <typename value_type>
typename contiguous_iterator<value_type>::value_type	contiguous_iterator<value_type>::operator * (void) const
{
	return ( *this->get_pointer() );
}

template <typename value_type>
typename contiguous_iterator<value_type>::value_type	contiguous_iterator<value_type>::operator -> (void) const
{
	return ( &(this->operator*) );
}

template <typename value_type>
typename contiguous_iterator<value_type>::iterator	contiguous_iterator<value_type>::operator + (const difference_type N) const
{
	return ( this->get_pointer() + N );
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator - (const difference_type N) const
{
	return ( this->get_pointer()- N );
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator ++ (void)
{
	iterator ret(*this);

	(this->_ptr)++;
	return (ret);
}

template <typename value_type>
virtual const iterator		contiguous_iterator<value_type>::operator ++ (int)
{
	(this->_ptr)++;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator -- (void)
{
	iterator ret(*this);

	(this->_ptr)--;
	return (ret);
}

template <typename value_type>
virtual const iterator		contiguous_iterator<value_type>::operator -- (int)
{
	(this->_ptr)--;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator += (const difference_type N)
{
	this->_ptr += N;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator -= (const difference_type N)
{
	this->_ptr -= N;
	return (*this);
}

// ? **************************************************************************
// ? *                         REVERSE CONTIGUOUS ITERATOR                    *
// ? **************************************************************************

template <typename value_type>
typename contiguous_iterator<value_type>::iterator	contiguous_iterator<value_type>::operator - (const difference_type N) const
{
	return ( this->get_pointer() + N );
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator + (const difference_type N) const
{
	return ( this->get_pointer()- N );
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator -- (void)
{
	iterator ret(*this);

	(this->_ptr)++;
	return (ret);
}

template <typename value_type>
virtual const iterator		contiguous_iterator<value_type>::operator -- (int)
{
	(this->_ptr)++;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator ++ (void)
{
	iterator ret(*this);

	(this->_ptr)--;
	return (ret);
}

template <typename value_type>
virtual const iterator		contiguous_iterator<value_type>::operator ++ (int)
{
	(this->_ptr)--;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator -= (const difference_type N)
{
	this->_ptr += N;
	return (*this);
}

template <typename value_type>
virtual iterator			contiguous_iterator<value_type>::operator += (const difference_type N)
{
	this->_ptr -= N;
	return (*this);
}
