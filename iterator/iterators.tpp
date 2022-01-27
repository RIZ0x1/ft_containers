#include "iterators.hpp"

// ? **************************************************************************
// ? *                           VECTOR ITERATOR                              *
// ? **************************************************************************

template <typename value_type>
ft::contiguous_iterator<value_type>::contiguous_iterator()
{

}

template <typename value_type>
ft::contiguous_iterator<value_type>::contiguous_iterator(const iterator &other)
{
}

template <typename value_type>
ft::contiguous_iterator<value_type>::~contiguous_iterator()
{

}


template <typename value_type>
value_type ft::contiguous_iterator<value_type>::operator * () const {}