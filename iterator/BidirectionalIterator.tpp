#ifndef BIDIRECTIONAL_ITERATOR_TPP
# define BIDIRECTIONAL_ITERATOR_TPP

# ifndef BIDIRECTIONAL_ITERATOR_HPP
#  include "BidirectionalIterator.hpp"
#  error __FILE__ should only be included from BidirectionalIterator.hpp
# endif

# define TC_BIDIR_ITER	BidirectionalIterator<value_type>

using ft::BidirectionalIterator;

// ? ***************************************************************************
// ? ***************************************************************************
// ? *                        BIDIRECTIONAL ITERATOR                           *
// ? ***************************************************************************
// ? ***************************************************************************

template <typename value_type>
TC_BIDIR_ITER::BidirectionalIterator() : _p_node(NULL)
{
}

template <typename value_type>
TC_BIDIR_ITER::BidirectionalIterator(pointer p_node) : _p_node(p_node)
{
}

template <typename value_type>
TC_BIDIR_ITER::BidirectionalIterator(const BidirectionalIterator& other) : _p_node(other._p_node)
{
}

template <typename value_type>
TC_BIDIR_ITER::~BidirectionalIterator()
{
}

// ? ***************************************************************************
// ? *                           OPERATOR OVERLOADS                            *
// ? ***************************************************************************

template <typename value_type>
bool	TC_BIDIR_ITER::operator == (const iterator &other) const
{
	return ( this->_get_pointer() == other._get_pointer() );
}

template <typename value_type>
bool	TC_BIDIR_ITER::operator != (const iterator &other) const
{
	return ( this->_get_pointer() != other._get_pointer() );
}

template <typename value_type>
bool	TC_BIDIR_ITER::operator < (const iterator &other) const
{
	return ( this->_get_pointer() < other._get_pointer() );
}

template <typename value_type>
bool	TC_BIDIR_ITER::operator > (const iterator &other) const
{
	return ( this->_get_pointer() > other._get_pointer() );
}

template <typename value_type>
bool	TC_BIDIR_ITER::operator <= (const iterator &other) const
{
	return ( this->_get_pointer() <= other._get_pointer() );
}

template <typename value_type>
bool	TC_BIDIR_ITER::operator >= (const iterator &other) const
{
	return ( this->_get_pointer() >= other._get_pointer() );
}

template <typename value_type>
typename TC_BIDIR_ITER::reference	TC_BIDIR_ITER::operator * () const
{
	return ( *_get_pointer() );
}

template <typename value_type>
typename TC_BIDIR_ITER::reference	TC_BIDIR_ITER::operator [] (const size_type pos) const
{

}

template <typename value_type>
typename TC_BIDIR_ITER::pointer	TC_BIDIR_ITER::operator -> () const
{
	return ( &(operator*()) );
}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator + (const difference_type N) const
{

}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator - (const difference_type N) const
{

}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator ++ ()
{

}

template <typename value_type>
const typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator ++ (int)
{
}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator -- ()
{
}

template <typename value_type>
const typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator -- (int)
{

}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator += (const difference_type N)
{

}

template <typename value_type>
typename TC_BIDIR_ITER::iterator	TC_BIDIR_ITER::operator -= (const difference_type N)
{

}

// ? ***************************************************************************
// ? *                            PROTECTED METHODS                            *
// ? ***************************************************************************

template <typename value_type>
typename TC_BIDIR_ITER::pointer TC_BIDIR_ITER::_get_pointer() const
{
	return ( _p_node );
}

#endif // BIDIRECTIONAL_ITERATOR_TPP