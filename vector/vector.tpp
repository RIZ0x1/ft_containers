#ifndef VECTOR_TPP
# define VECTOR_TPP

#include "vector.hpp"

#define EMPTY 0

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

using ft::vector;
using std::cerr;
using std::endl;

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>::vector()
{
	_alloc = new allocator_type();
	_array = NULL;
	_begin = _array;
	_end = _array;
	_capacity = EMPTY;
}

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>::vector(const vector &other)
{
	operator=(other);
}

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>::vector(const allocator_type &alloc)
{
	this->_alloc = alloc;
	_array = NULL;
	_begin = _array;
	_end = _array;
	_capacity = EMPTY;
}

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>::vector(size_type count, const value_type& value, const allocator_type& alloc)
{
    this->_alloc = new allocator_type(alloc);
	_array = this->_alloc->allocate(count);
	_begin = _array;

	size_type i = 0;
	for (i = 0; i < count; i++)
		_array[i] = value;
	_end = &_array[i];
	_capacity = i;
}

template <typename value_type, typename allocator_type> template <typename InputIt>
vector<value_type, allocator_type>::vector(InputIt first, InputIt last, const allocator_type &alloc)
{
	this->_alloc = alloc;

	for (; first != last; first++)
		push_back(*first);
}

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>::~vector()
{
	_alloc->destroy(_get_array());
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename value_type, typename allocator_type> template <typename InputIt>
void	vector<value_type, allocator_type>::assign(InputIt first, InputIt last)
{

}

template <typename value_type, typename allocator_type>
void		vector<value_type, allocator_type>::assign(size_type count, const value_type& value)
{

}

template <typename value_type, typename allocator_type>
allocator_type	vector<value_type, allocator_type>::get_allocator() const
{
	return (*_alloc);
}

// ? ***************************************************************************
// ? *                              ELEMENT ACCESS                             *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
value_type&	vector<value_type, allocator_type>::front(void)
{

}

template <typename value_type, typename allocator_type>
const value_type&	vector<value_type, allocator_type>::front(void) const
{

}

template <typename value_type, typename allocator_type>
value_type&	vector<value_type, allocator_type>::back(void)
{

}

template <typename value_type, typename allocator_type>
const value_type&	vector<value_type, allocator_type>::back(void) const
{

}

template <typename value_type, typename allocator_type>
value_type&	vector<value_type, allocator_type>::at(size_type pos)
{

}

template <typename value_type, typename allocator_type>
const value_type&	vector<value_type, allocator_type>::at(size_type pos) const
{

}

template <typename value_type, typename allocator_type>
value_type*	vector<value_type, allocator_type>::data(void)
{

}

template <typename value_type, typename allocator_type>
const value_type*	vector<value_type, allocator_type>::data(void) const
{

}

// ? ***************************************************************************
// ? *                                 CAPACITY                                *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
bool	vector<value_type, allocator_type>::empty(void) const
{

}

template <typename value_type, typename allocator_type>
typename ft::vector<value_type, allocator_type>::size_type	vector<value_type, allocator_type>::size(void) const
{
	return static_cast<size_t>(_end - _begin);
}

template <typename value_type, typename allocator_type>
typename ft::vector<value_type, allocator_type>::size_type	vector<value_type, allocator_type>::max_size(void) const
{
	return std::numeric_limits<std::ptrdiff_t>::max() / sizeof(value_type);
}

template <typename value_type, typename allocator_type>
void	vector<value_type, allocator_type>::reserve(size_type new_cap)
{
	if (new_cap > max_size())
		throw std::runtime_error("ERROR: New capacity value in invalid [ vector::reserve() ]");
	if (new_cap > capacity())
		_reallocate(new_cap);
}

template <typename value_type, typename allocator_type>
typename ft::vector<value_type, allocator_type>::size_type	vector<value_type, allocator_type>::capacity(void) const
{
	return (_capacity);
}

// ? ***************************************************************************
// ? *                                 MODIFIERS                               *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
void		vector<value_type, allocator_type>::clear(void)
{
	
}

template <typename value_type, typename allocator_type>
typename vector<value_type>::iterator	erase(typename vector<value_type>::iterator pos)
{

}

template <typename value_type, typename allocator_type>
typename vector<value_type>::iterator	erase(typename vector<value_type>::iterator first, typename vector<value_type>::iterator last)
{

}

template <typename value_type, typename allocator_type>
void		push_back(const value_type& value)
{

}

template <typename value_type, typename allocator_type>
void		pop_back(void)
{
}
template <typename value_type, typename allocator_type>
void		resize(size_t count)
{
}
template <typename value_type, typename allocator_type>
void		resize(size_t count, value_type value = value_type())
{
}
template <typename value_type, typename allocator_type>
void		vector<value_type, allocator_type>::swap(vector<value_type, allocator_type> &other)
{
}
template <typename value_type, typename allocator_type>
typename vector<value_type>::iterator	insert(typename vector<value_type>::iterator pos, const value_type& value)
{
}
template <typename value_type, typename allocator_type> template <typename InputIt>
void	vector<value_type, allocator_type>::insert(iterator pos, InputIt first, InputIt last)
{
}

template <typename value_type, typename allocator_type>
void		insert(typename vector<value_type>::iterator pos, size_t count, const value_type& value)
{
}

// ? ***************************************************************************
// ? *                               OPERATORS                                 *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
vector<value_type, allocator_type>&	vector<value_type, allocator_type>::operator = (const vector<value_type, allocator_type> &other)
{
	this->_copy_array(other._get_array(), other.size());
	this->_begin = this->_array;
	this->_end = this->_begin + (sizeof(value_type) * other.size());

	return (*this);
}

template <typename value_type, typename allocator_type>
value_type&	vector<value_type, allocator_type>::operator [] (size_type pos) const
{
	
}

// ? ***************************************************************************
// ? *                            PRIVATE METHODS                              *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
typename vector<value_type, allocator_type>::pointer	vector<value_type, allocator_type>::_get_array(void) const
{
	return (_array);
}

template <typename value_type, typename allocator_type>
void	vector<value_type, allocator_type>::_copy_array(pointer array, const size_type size)
{
	this->_alloc->destroy(this->_get_array());
	this->_array = this->_alloc->allocate(size);

	for (size_t i = 0; i < size; i++)
		this->_array[i] = array[i];
}

template <typename value_type, typename allocator_type>
bool	vector<value_type, allocator_type>::_reallocate(size_type new_capacity)
{
	bool	ret;

	ret = (new_capacity <= 0);

	if (ret)
	{
		const size_type	old_size = size();
		pointer			tmp = _alloc->allocate(new_capacity);

		try {
			for (size_type i = 0; i < size(); i++)
				_alloc->construct(&tmp[i], _array[i]);
		} catch (std::exception &e)
		{
			_alloc->deallocate(tmp, new_capacity);
			throw std::runtime_error("ERROR: Allocation failed [ vector::_reallocate() ]");
		}

		for (size_type i = 0; i < size(); i++)
			_alloc->destroy(&_array[i]);
		if (capacity() != 0)
			_alloc->deallocate(_array, capacity());

		this->_set_capacity(new_capacity);
		this->_set_size(old_size);
		this->_array = tmp;
	}
	return (ret);
}

#endif // VECTOR_TPP
