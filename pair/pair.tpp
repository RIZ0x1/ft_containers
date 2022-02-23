#ifndef PAIR_TPP
# define PAIR_TPP

# ifndef PAIR_HPP
#  error __FILE__ should only be included from pair.hpp
# endif

#include "pair.hpp"

#define TC_PAIR pair<first_type, second_type> // Template Class 'pair'

using ft::pair;

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename first_type, typename second_type>
TC_PAIR::pair() : t(first_type()), u(second_type())
{
}

template <typename first_type, typename second_type>
TC_PAIR::pair(const pair& other) : t(other.t), u(other.u)
{
}

template <typename first_type, typename second_type>
TC_PAIR::pair(const first_type& x, const second_type& y) : t(x), u(y)
{

}

template <typename first_type, typename second_type>
template <typename U1, typename U2>
TC_PAIR::pair(const pair<U1, U2> &other)
{

}

template <typename first_type, typename second_type>
TC_PAIR::~pair()
{

}

template <typename first_type, typename second_type>
TC_PAIR& TC_PAIR::operator = (const pair& other)
{

}


#endif // PAIR_TPP