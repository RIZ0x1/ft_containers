#ifndef ENABLE_IF_TPP
# define ENABLE_IF_TPP

namespace ft {

	template <bool, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

}

#endif // ENABLE_IF_TPP
