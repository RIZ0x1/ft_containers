#ifndef PAIR_HPP
# define PAIR_HPP

#include "../ft_utils/enable_if.hpp"

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
        pair(const pair<first_type, second_type>& other);
        pair(const first_type& x, const second_type& y);
        template <typename U1, typename U2>
            pair(const pair<U1, U2>& other, typename ft::enable_if<std::is_convertible<const U1&, first_type>::value>::type*,
                                            typename ft::enable_if<std::is_convertible<const U2&, second_type>::value>::type*);
        ~pair();

        pair<first_type, second_type>&  operator = (const pair<first_type, second_type>& other);
    };
}

#include "pair.tpp"

#endif // PAIR_HPP
