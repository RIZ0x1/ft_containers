#ifndef MAP_ITERATOR_TPP
# define MAP_ITERATOR_TPP

# ifndef MAP_ITERATOR_HPP
#  error __FILE__ should only be included from MapIterator.hpp
# endif

# define FT_BIDIR_ITER MapIterator<value_type>

using ft::MapIterator;

// ? ***************************************************************************
// ? ***************************************************************************
// ? *                        BIDIRECTIONAL ITERATOR                           *
// ? ***************************************************************************
// ? ***************************************************************************

template <typename value_type>
FT_BIDIR_ITER::MapIterator() : _p_node(NULL)
{
}

template <typename value_type>
FT_BIDIR_ITER::MapIterator(pointer p_node) : _p_node(p_node)
{
}

template <typename value_type>
FT_BIDIR_ITER::MapIterator(const MapIterator& other) : _p_node(other._p_node)
{
}

template <typename value_type>
FT_BIDIR_ITER::~MapIterator()
{
}

// ? ***************************************************************************
// ? *                           OPERATOR OVERLOADS                            *
// ? ***************************************************************************

template <typename value_type>
bool FT_BIDIR_ITER::operator == (const iterator &other) const
{
    return ( this->_get_pointer() == other._get_pointer() );
}

template <typename value_type>
bool FT_BIDIR_ITER::operator != (const iterator &other) const
{
    return ( this->_get_pointer() != other._get_pointer() );
}

template <typename value_type>
bool FT_BIDIR_ITER::operator < (const iterator &other) const
{
    return ( this->_get_pointer() < other._get_pointer() );
}

template <typename value_type>
bool FT_BIDIR_ITER::operator > (const iterator &other) const
{
    return ( this->_get_pointer() > other._get_pointer() );
}

template <typename value_type>
bool FT_BIDIR_ITER::operator <= (const iterator &other) const
{
    return ( this->_get_pointer() <= other._get_pointer() );
}

template <typename value_type>
bool FT_BIDIR_ITER::operator >= (const iterator &other) const
{
    return ( this->_get_pointer() >= other._get_pointer() );
}

template <typename value_type>
typename FT_BIDIR_ITER::reference FT_BIDIR_ITER::operator * () const
{
    return ( *_get_pointer() );
}

template <typename value_type>
typename FT_BIDIR_ITER::reference FT_BIDIR_ITER::operator [] (const size_type pos) const
{

}

template <typename value_type>
typename FT_BIDIR_ITER::pointer FT_BIDIR_ITER::operator -> () const
{
    return ( &(operator*()) );
}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator + (const difference_type N) const
{

}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator - (const difference_type N) const
{

}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator ++ ()
{

}

template <typename value_type>
const typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator ++ (int)
{
}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator -- ()
{
}

template <typename value_type>
const typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator -- (int)
{

}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator += (const difference_type N)
{

}

template <typename value_type>
typename FT_BIDIR_ITER::iterator FT_BIDIR_ITER::operator -= (const difference_type N)
{

}

// ? ***************************************************************************
// ? *                            PROTECTED METHODS                            *
// ? ***************************************************************************

template <typename value_type>
typename FT_BIDIR_ITER::pointer FT_BIDIR_ITER::_get_pointer() const
{
    return ( _p_node );
}

#endif // MAP_ITERATOR_TPP
