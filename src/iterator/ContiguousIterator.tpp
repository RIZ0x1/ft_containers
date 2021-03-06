#ifndef CONTIGUOUS_ITERATOR_TPP
# define CONTIGUOUS_ITERATOR_TPP

#include "ContiguousIterator.hpp"

# ifndef CONTIGUOUS_ITERATOR_HPP
#  error __FILE__ should be included only from ContiguousIterator.hpp
# endif

# define FT_CONT_ITER ContiguousIterator<value_type>
# define FT_REV_CONT_ITER ReverseContiguousIterator<value_type>

// ? ***************************************************************************
// ? ***************************************************************************
// ? *                          CONTIGUOUS ITERATOR                            *
// ? ***************************************************************************
// ? ***************************************************************************

using ft::ContiguousIterator;

template <typename value_type>
FT_CONT_ITER::ContiguousIterator() : _ptr(NULL)
{
}

template <typename value_type>
FT_CONT_ITER::ContiguousIterator(pointer ptr) : _ptr(ptr)
{
}

template <typename value_type>
FT_CONT_ITER::ContiguousIterator(const iterator& other) : _ptr(other._get_pointer())
{
}

template <typename value_type>
FT_CONT_ITER::~ContiguousIterator()
{
}

// ? ***************************************************************************
// ? *                           OPERATOR OVERLOADS                            *
// ? ***************************************************************************

template <typename value_type>
bool FT_CONT_ITER::operator == (const iterator &other) const
{
    return ( this->_get_pointer() == other._get_pointer() );
}

template <typename value_type>
bool FT_CONT_ITER::operator != (const iterator &other) const
{
    return ( this->_get_pointer() != other._get_pointer() );
}

template <typename value_type>
bool FT_CONT_ITER::operator < (const iterator &other) const
{
    return ( this->_get_pointer() < other._get_pointer() );
}

template <typename value_type>
bool FT_CONT_ITER::operator > (const iterator &other) const
{
    return ( this->_get_pointer() > other._get_pointer() );
}

template <typename value_type>
bool FT_CONT_ITER::operator <= (const iterator &other) const
{
    return ( this->_get_pointer() <= other._get_pointer() );
}

template <typename value_type>
bool FT_CONT_ITER::operator >= (const iterator &other) const
{
    return ( this->_get_pointer() >= other._get_pointer() );
}

template <typename value_type>
typename FT_CONT_ITER::reference FT_CONT_ITER::operator * () const
{
    return ( *_get_pointer() );
}

template <typename value_type>
typename FT_CONT_ITER::reference FT_CONT_ITER::operator [] (const size_type pos) const
{
    return ( *(_get_pointer() + pos) );
}

template <typename value_type>
typename FT_CONT_ITER::pointer FT_CONT_ITER::operator -> () const
{
    return ( &(operator*()) );
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator + (const difference_type N) const
{
    return ( iterator(_get_pointer() + N) );
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator - (const difference_type N) const
{
    return ( iterator(_get_pointer() - N) );
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator ++ ()
{
    (this->_ptr)++;
    return (*this);
}

template <typename value_type>
const typename FT_CONT_ITER::iterator FT_CONT_ITER::operator ++ (int)
{
    iterator ret(*this);

    (this->_ptr)++;
    return (ret);
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator -- ()
{
    (this->_ptr)--;
    return (*this);
}

template <typename value_type>
const typename FT_CONT_ITER::iterator FT_CONT_ITER::operator -- (int)
{
    iterator ret(*this);

    (this->_ptr)--;
    return (ret);
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator += (const difference_type N)
{
    this->_ptr += N;
    return (*this);
}

template <typename value_type>
typename FT_CONT_ITER::iterator FT_CONT_ITER::operator -= (const difference_type N)
{
    this->_ptr -= N;
    return (*this);
}

// ? ***************************************************************************
// ? *                            PROTECTED METHODS                            *
// ? ***************************************************************************

template <typename value_type>
typename FT_CONT_ITER::pointer FT_CONT_ITER::_get_pointer() const
{
    return (_ptr);
}

// ? ***************************************************************************
// ? ***************************************************************************
// ? *                      REVERSE CONTIGUOUS ITERATOR                        *
// ? ***************************************************************************
// ? ***************************************************************************

using ft::ReverseContiguousIterator;

template <typename value_type>
FT_REV_CONT_ITER::ReverseContiguousIterator() : ContiguousIterator<value_type>()
{
}

template <typename value_type>
FT_REV_CONT_ITER::ReverseContiguousIterator(pointer ptr) : ContiguousIterator<value_type>(ptr)
{
}

template <typename value_type>
FT_REV_CONT_ITER::ReverseContiguousIterator(const ReverseContiguousIterator& other)
{
    this->_ptr = other._get_pointer();
}

template <typename value_type>
FT_REV_CONT_ITER::~ReverseContiguousIterator()
{
}

// ? ***************************************************************************
// ? *                           OPERATOR OVERLOADS                            *
// ? ***************************************************************************

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator - (const difference_type N) const
{
    return ( iterator(this->_get_pointer() + N) );
}

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator + (const difference_type N) const
{
    return ( iterator(this->_get_pointer() - N) );
}

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator -- ()
{
    (this->_ptr)++;
    return (*this);
}

template <typename value_type>
const typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator -- (int)
{
    iterator ret(*this);

    (this->_ptr)++;
    return (ret);
}

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator ++ ()
{
    (this->_ptr)--;
    return (*this);
}

template <typename value_type>
const typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator ++ (int)
{
    iterator ret(*this);

    (this->_ptr)--;
    return (ret);
}

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator -= (const difference_type N)
{
    this->_ptr += N;
    return (*this);
}

template <typename value_type>
typename FT_REV_CONT_ITER::iterator    FT_REV_CONT_ITER::operator += (const difference_type N)
{
    this->_ptr -= N;
    return (*this);
}

#endif // CONTIGUOUS_ITERATOR_TPP
