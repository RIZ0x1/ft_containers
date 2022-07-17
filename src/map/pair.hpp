#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
  template <typename T1, typename T2>
  struct pair
  {
    typedef T1 first_type;
    typedef T2 second_type;

    first_type  key;
    second_type value;

    pair();
    pair(const pair& other);
    pair(const T1& x, const T2& y);
    template <typename U1, typename U2> pair(const pair<U1, U2> &other);
    ~pair();

    pair&  operator = (const pair& other);
  };
}

#include "pair.tpp"

#endif // PAIR_HPP
