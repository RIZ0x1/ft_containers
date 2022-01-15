#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>

namespace ft
{ class vector; }

template <typename T, typename Alloc = std::allocator<T>>
class vector
{

public:
	vector();
	vector(const vector &other);
};

#endif // * FT_VECTOR_HPP