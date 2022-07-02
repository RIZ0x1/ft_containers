
#ifndef PAIR_TPP
# define PAIR_TPP

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
TC_PAIR::pair(const pair<U1, U2> &other,
              typename ft::enable_if<std::is_convertible<const U1&, first_type>::value>::type*,
              typename ft::enable_if<std::is_convertible<const U2&, second_type>::value>::type*)
              : key(other.key), value(other.value)
{
}

template <typename first_type, typename second_type>
TC_PAIR::~pair()
{
}

// ? ***************************************************************************
// ? *                         OPERATOR OVERLOADS                              *
// ? ***************************************************************************

template <typename first_type, typename second_type>
TC_PAIR& TC_PAIR::operator = (const pair& other)
{
    this->t = other.t;
    this->u = other.u;
}

// ? ***************************************************************************
// ? *                    NON-MEMBER OPERATOR OVERLOADS                        *
// ? ***************************************************************************

template <typename first_type, typename second_type>
bool operator == (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t == right.t && left->u == right.u);
}

template <typename first_type, typename second_type>
bool operator != (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t != right.t && left->u != right.u);
}

template <typename first_type, typename second_type>
bool operator < (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t >= right.t) ? false : (left->u < right.u);
}

template <typename first_type, typename second_type>
bool operator <= (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t > right.t ? false : (left->u <= right.u));
}

template <typename first_type, typename second_type>
bool operator > (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t <= right.t) ? false : (left->u > right.u);
}

template <typename first_type, typename second_type>
bool operator >= (const TC_PAIR& left, const TC_PAIR& right)
{
    return (left->t < right.t) ? false : (left->u >= right.u);
}

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 t, T2 u)
{
    return ( ft::pair<T1, T2>(t, u) );
}

#endif // PAIR_TPP
