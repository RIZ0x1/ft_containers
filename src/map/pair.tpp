
#ifndef PAIR_TPP
# define PAIR_TPP

# ifndef PAIR_HPP
#  error __FILE__ should only be included from pair.hpp
# endif

#define FT_PAIR pair<first_type, second_type>

using ft::pair;

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename first_type, typename second_type>
FT_PAIR::pair() : key(first_type()), value(second_type())
{
}

template <typename first_type, typename second_type>
FT_PAIR::pair(const pair<first_type, second_type>& other) : key(other.t), value(other.u)
{
}

template <typename first_type, typename second_type>
FT_PAIR::pair(const first_type& x, const second_type& y) : key(x), value(y)
{
}

template <typename first_type, typename second_type>
template <typename U1, typename U2>
FT_PAIR::pair(const pair<U1, U2> &other,
              typename ft::enable_if<std::is_convertible<const U1&, first_type>::value>::type*,
              typename ft::enable_if<std::is_convertible<const U2&, second_type>::value>::type*)
              : key(other.first), value(other.second)
{
}

template <typename first_type, typename second_type>
FT_PAIR::~pair()
{
}

// ? ***************************************************************************
// ? *                         OPERATOR OVERLOADS                              *
// ? ***************************************************************************

template <typename first_type, typename second_type>
FT_PAIR& FT_PAIR::operator = (const pair<first_type, second_type>& other)
{
    this->t = other.t;
    this->u = other.u;
}

// ? ***************************************************************************
// ? *                             NON-MEMBER                                  *
// ? ***************************************************************************

template <typename first_type, typename second_type>
bool operator == (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t == right.t && left->u == right.u);
}

template <typename first_type, typename second_type>
bool operator != (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t != right.t && left->u != right.u);
}

template <typename first_type, typename second_type>
bool operator < (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t >= right.t) ? false : (left->u < right.u);
}

template <typename first_type, typename second_type>
bool operator <= (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t > right.t ? false : (left->u <= right.u));
}

template <typename first_type, typename second_type>
bool operator > (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t <= right.t) ? false : (left->u > right.u);
}

template <typename first_type, typename second_type>
bool operator >= (const FT_PAIR& left, const FT_PAIR& right)
{
    return (left->t < right.t) ? false : (left->u >= right.u);
}

namespace ft
{
    template <typename T1, typename T2>
    pair<T1, T2> make_pair(T1 t, T2 u)
    {
        return ( ft::pair<T1, T2>(t, u) );
    }
}

#endif // PAIR_TPP
