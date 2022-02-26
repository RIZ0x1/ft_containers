
#ifndef PAIR_TPP
# define PAIR_TPP

#include "pair.hpp" // no need

# ifndef PAIR_HPP
#  error __FILE__ should only be included from pair.hpp
# endif

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

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename first_type, typename second_type>
TC_PAIR& TC_PAIR::operator = (const pair& other)
{
	this->t = other.t;
	this->u = other.u;
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator == (const pair& other)
{
	return (this->t == other.t && this->u == other.u);
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator != (const pair& other)
{
	return (this->t != other.t && this->u != other.u);
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator < (const pair& other)
{
	return (this->t >= other.t) ? false : (this->u < other.u);
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator <= (const pair& other)
{
	return (this->t > other.t ? false : (this->u <= other.u));
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator > (const pair& other)
{
	return (this->t <= other.t) ? false : (this->u > other.u);
}

template <typename first_type, typename second_type>
bool TC_PAIR::operator >= (const pair& other)
{
	return (this->t < other.t) ? false : (this->u >= other.u);
}

// ? ***************************************************************************
// ? *                              MAKE_PAIR                                  *
// ? ***************************************************************************

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 t, T2 u)
{
	return ( ft::pair<T1, T2>(t, u) );
}

#endif // PAIR_TPP
