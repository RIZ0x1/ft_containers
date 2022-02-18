#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

	template <typename T, T v>
	struct integral_constant
	{
		static const T	value = v;
		typedef T		value_type;
		typedef struct	integral_constant type;
	};

	struct true_type : public integral_constant<bool, true> {};
	struct false_type : public integral_constant<bool, false> {};

	template <typename T> struct is_integral;
	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<short> : public true_type {};
	template<> struct is_integral<unsigned short> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<long> : public true_type {};
	template<> struct is_integral<unsigned long> : public true_type {};

}

#endif // IS_INTEGRAL_HPP
