#ifndef VECTOR_TPP
# define VECTOR_TPP

#include "vector.hpp"

template <typename T, typename Allocator> template <typename InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator &alloc)
{

}

template <typename T, typename Allocator> template <class InputIt>
void	vector<T, Allocator>::assign(InputIt first, InputIt last)
{

}

#endif // VECTOR_TPP