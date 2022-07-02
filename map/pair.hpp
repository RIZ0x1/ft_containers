#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
  template <typename T1, typename T2>
  class pair
  {
  public:
    typedef T1 key_type;
    typedef T2 value_type;

    key_type   key;
    value_type value;

  public:
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
