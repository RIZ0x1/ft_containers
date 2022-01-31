#include "ContiguousIterator.hpp"

// ? **************************************************************************
// ? *                          CONTIGUOUS ITERATOR                           *
// ? **************************************************************************

using ft::ContiguousIterator;

template <typename value_type>
ContiguousIterator<value_type>::ContiguousIterator() : _ptr(NULL)
{
}

template <typename value_type>
ContiguousIterator<value_type>::ContiguousIterator(const iterator& other) : _ptr(other._get_pointer())
{
}

template <typename value_type>
ContiguousIterator<value_type>::~ContiguousIterator()
{
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator == (const iterator &other) const
{
	return ( this->_get_pointer() == other.get_pointer() );
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator != (const iterator &other) const
{
	return ( this->_get_pointer() != other.get_pointer() );
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator < (const iterator &other) const
{
	return ( this->_get_pointer() < other.get_pointer() );
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator > (const iterator &other) const
{
	return ( this->_get_pointer() > other.get_pointer() );
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator <= (const iterator &other) const
{
	return ( this->_get_pointer() <= other.get_pointer() );
}

template <typename value_type>
bool	ContiguousIterator<value_type>::operator >= (const iterator &other) const
{
	return ( this->_get_pointer() >= other.get_pointer() );
}

template <typename value_type>
typename ContiguousIterator<value_type>::value_type	ContiguousIterator<value_type>::operator * () const
{
	return ( *_get_pointer() );
}

template <typename value_type>
typename ContiguousIterator<value_type>::value_type	ContiguousIterator<value_type>::operator -> () const
{
	return ( &(this->operator*) );
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator + (const difference_type N) const
{
	return ( _get_pointer() + N );
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator - (const difference_type N) const
{
	return ( _get_pointer() - N );
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator ++ ()
{
	iterator ret(*this);

	(this->_ptr)++;
	return (ret);
}

template <typename value_type>
const typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator ++ (int)
{
	(this->_ptr)++;
	return (*this);
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator -- ()
{
	iterator ret(*this);

	(this->_ptr)--;
	return (ret);
}

template <typename value_type>
const typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator -- (int)
{
	(this->_ptr)--;
	return (*this);
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator += (const difference_type N)
{
	this->_ptr += N;
	return (*this);
}

template <typename value_type>
typename ContiguousIterator<value_type>::iterator	ContiguousIterator<value_type>::operator -= (const difference_type N)
{
	this->_ptr -= N;
	return (*this);
}

//

template <typename value_type>
typename ContiguousIterator<value_type>::pointer ContiguousIterator<value_type>::_get_pointer() const
{
	return (_ptr);
}

// ? **************************************************************************
// ? *                         REVERSE CONTIGUOUS ITERATOR                    *
// ? **************************************************************************

using ft::ReverseContiguousIterator;

template <typename value_type>
ReverseContiguousIterator<value_type>::ReverseContiguousIterator() : ReverseContiguousIterator()
{
}

template <typename value_type>
ReverseContiguousIterator<value_type>::ReverseContiguousIterator(const ReverseContiguousIterator& other)
{
	this->_ptr = other._get_pointer();
}

template <typename value_type>
ReverseContiguousIterator<value_type>::~ReverseContiguousIterator()
{
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator - (const difference_type N) const
{
	return ( this->_get_pointer() + N );
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator + (const difference_type N) const
{
	return ( this->_get_pointer() - N );
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator -- ()
{
	iterator ret(*this);

	(this->_ptr)++;
	return (ret);
}

template <typename value_type>
const typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator -- (int)
{
	(this->_ptr)++;
	return (*this);
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator ++ ()
{
	iterator ret(*this);

	(this->_ptr)--;
	return (ret);
}

template <typename value_type>
const typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator ++ (int)
{
	(this->_ptr)--;
	return (*this);
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator -= (const difference_type N)
{
	this->_ptr += N;
	return (*this);
}

template <typename value_type>
typename ReverseContiguousIterator<value_type>::iterator	ReverseContiguousIterator<value_type>::operator += (const difference_type N)
{
	this->_ptr -= N;
	return (*this);
}
