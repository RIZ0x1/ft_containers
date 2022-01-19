#ifndef VECTOR_TPP
# define VECTOR_TPP

#include "vector.hpp"

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename T, typename Allocator>
vector<T, Allocator>::vector()
{
	_capacity = 0;
	_alloc = new Allocator();
	_array = _alloc->allocate(0);
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector &other)
{
	operator=(other);
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator &alloc)
{
	_capacity = 0;
	_alloc = alloc;
	_array = _alloc->allocate(0);
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_t count, const T& value, const Allocator& alloc)
{
	_capacity = count;
	this->_alloc = new Allocator(alloc);
	_array = this->_alloc->allocate(count);

	for (size_t i = 0; i < count; i++)
		_array[i] = value;
}

template <typename T, typename Allocator> template <typename InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator &alloc)
{

}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{
	// todo: Allocator
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename T, typename Allocator> template <typename InputIt>
void	vector<T, Allocator>::assign(InputIt first, InputIt last)
{

}

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
	return (std::numeric_limits<T>::max());
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

template <typename T, typename Allocator>
void		vector<T, Allocator>::clear(void)
{

}

// template <typename T, typename Allocator>
// iterator<T>	erase(iterator<T> pos)
// {

// }

// template <typename T, typename Allocator>
// iterator<T>	erase(iterator<T> first, iterator<T> last)
// {

// }

// template <typename T, typename Allocator>
// void		push_back(const T& value)
// {

// }

// template <typename T, typename Allocator>
// void		pop_back(void)
// {

// }

// template <typename T, typename Allocator>
// void		resize(size_t count)
// {

// }

// template <typename T, typename Allocator>
// void		resize(size_t count, T value = T())
// {

// }

// template <typename T, typename Allocator>
// void		vector<T, Allocator>::swap(vector<T, Allocator> &other)
// {

// }

// template <typename T, typename Allocator>
// iterator<T>	insert(iterator<T> pos, const T& value)
// {

// }

// template <typename T, typename Allocator> template <typename InputIt>
// void	vector<T, Allocator>::insert(iterator<T> pos, InputIt first, InputIt last)
// {

// }

// template <typename T, typename Allocator>
// void		insert(iterator<T> pos, size_t count, const T& value)
// {

// }

// ? ***************************************************************************
// ? *                                 OPERATORS                               *
// ? ***************************************************************************

template <typename T, typename Allocator>
vector<T, Allocator>&	vector<T, Allocator>::operator = (const vector<T, Allocator> &other)
{
	return (*this);
}

template <typename T, typename Allocator>
T&	vector<T, Allocator>::operator [] (size_t pos) const
{

}


#endif // VECTOR_TPP