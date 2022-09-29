#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

#include "VectorIterator.hpp"

# ifndef VECTOR_ITERATOR_HPP
#  error __FILE__ should be included only from VectorIterator.hpp
# endif

# define FT_CONT_ITER VectorIterator<value_type>
# define FT_REV_CONT_ITER ReverseVectorIterator<value_type>

// ? ***************************************************************************
// ? ***************************************************************************
// ? *                          CONTIGUOUS ITERATOR                            *
// ? ***************************************************************************
// ? ***************************************************************************

using ft::VectorIterator;

template <typename value_type>
FT_CONT_ITER::VectorIterator() : _ptr(NULL)
{
}

template <typename value_type>
FT_CONT_ITER::VectorIterator(pointer ptr) : _ptr(ptr)
{
}

template <typename value_type>
FT_CONT_ITER::VectorIterator(const iterator& other) : _ptr(other._get_pointer())
{
}

template <typename value_type>
FT_CONT_ITER::~VectorIterator()
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

using ft::ReverseVectorIterator;

template <typename value_type>
FT_REV_CONT_ITER::ReverseVectorIterator() : VectorIterator<value_type>()
{
}

template <typename value_type>
FT_REV_CONT_ITER::ReverseVectorIterator(pointer ptr) : VectorIterator<value_type>(ptr)
{
}

template <typename value_type>
FT_REV_CONT_ITER::ReverseVectorIterator(const ReverseVectorIterator& other)
{
    this->_ptr = other._get_pointer();
}

template <typename value_type>
FT_REV_CONT_ITER::~ReverseVectorIterator()
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

#endif // VECTOR_ITERATOR_TPP
