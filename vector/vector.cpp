#include "vector.hpp"

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename T, typename Allocator>
vector<T, Allocator>::vector()
{

}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector &other)
{

}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator &alloc)
{

}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_t count, const T& value = T(), const Allocator& alloc = Allocator())
{

}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{

}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename T, typename Allocator>
void		vector<T, Allocator>::assign(size_t count, const T& value)
{

}

template <typename T, typename Allocator>
Allocator		vector<T, Allocator>::get_allocator() const
{
	
}

// ? ***************************************************************************
// ? *                              ELEMENT ACCESS                             *
// ? ***************************************************************************

template <typename T, typename Allocator>
T&	vector<T, Allocator>::front(void)
{

}

template <typename T, typename Allocator>
const T&	vector<T, Allocator>::front(void) const
{

}

template <typename T, typename Allocator>
T&	vector<T, Allocator>::back(void)
{

}

template <typename T, typename Allocator>
const T&	vector<T, Allocator>::back(void) const
{

}

template <typename T, typename Allocator>
T&	vector<T, Allocator>::at(size_t pos)
{

}

template <typename T, typename Allocator>
const T&	vector<T, Allocator>::at(size_t pos) const
{

}

template <typename T, typename Allocator>
T*	vector<T, Allocator>::data(void)
{

}

template <typename T, typename Allocator>
const T*	vector<T, Allocator>::data(void) const
{

}

// ? ***************************************************************************
// ? *                                 CAPACITY                                *
// ? ***************************************************************************

template <typename T, typename Allocator>
bool	vector<T, Allocator>::empty(void) const
{

}

template <typename T, typename Allocator>
size_t	vector<T, Allocator>::size(void) const
{

}

template <typename T, typename Allocator>
size_t	vector<T, Allocator>::max_size(void) const
{

}

template <typename T, typename Allocator>
void	vector<T, Allocator>::reserve(size_t new_cap)
{

}

template <typename T, typename Allocator>
size_t	vector<T, Allocator>::capacity(void) const
{

}

// ? ***************************************************************************
// ? *                                 MODIFIERS                               *
// ? ***************************************************************************



// ? ***************************************************************************
// ? *                                 OPERATORS                               *
// ? ***************************************************************************

template <typename T, typename Allocator>
vector<T, Allocator>&	vector<T, Allocator>::operator = (const vector<T, Allocator> &other)
{

}

template <typename T, typename Allocator>
T&	vector<T, Allocator>::operator [] (size_t pos) const
{

}
