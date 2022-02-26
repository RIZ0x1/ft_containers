#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	class pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	t;
		second_type	u;

	public:
		pair();
		pair(const pair& other);
		pair(const T1& x, const T2& y);
		template <typename U1, typename U2>
			pair(const pair<U1, U2> &other);
		~pair();

		pair&	operator = (const pair& other);
	};

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 t, T2 u);

}

#include "pair.tpp"

#endif // PAIR_HPP