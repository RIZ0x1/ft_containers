#ifndef VECTOR_TPP
# define VECTOR_TPP

#include "vector.hpp" // No need

# ifndef VECTOR_HPP
#  error __FILE__ should only be included from vector.hpp
# endif

# define TC_VECTOR vector<value_type, allocator_type>	// TEMPLATE CLASS VECTOR
# define EMPTY 0U										// EMPTY SIZE

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

using ft::vector;
using std::cerr;
using std::endl;

template <typename value_type, typename allocator_type>
TC_VECTOR::vector()
{
	_alloc = allocator_type();
	_array = NULL;
	_end = _array;
	_capacity = EMPTY;
}

template <typename value_type, typename allocator_type>
TC_VECTOR::vector(const vector &other) : _capacity(EMPTY), _array(NULL), _end(_array)
{
	operator=(other);
}

template <typename value_type, typename allocator_type>
TC_VECTOR::vector(const allocator_type &alloc)
{
	this->_alloc = alloc;
	_array = NULL;
	_end = _array;
	_capacity = EMPTY;
}

template <typename value_type, typename allocator_type>
TC_VECTOR::vector(size_type count, const value_type& value, const allocator_type& alloc)
{
    this->_alloc = alloc;
	_array = this->_alloc.allocate(count);
	_capacity = count;

	size_type i = 0;
	for (; i < count; i++)
		_array[i] = value;
	_end = &_array[i];
}

template <typename value_type, typename allocator_type> template <typename InputIt>
TC_VECTOR::vector(InputIt first, InputIt last, const allocator_type &alloc)
{
	this->_alloc = alloc;

	for (; first != last; first++)
		push_back(*first);
}

template <typename value_type, typename allocator_type>
TC_VECTOR::~vector()
{
	if (_array)
		_alloc.destroy(_array);
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename value_type, typename allocator_type> template <typename InputIt>
void	TC_VECTOR::assign(InputIt first, InputIt last)
{
	clear();

	const size_type new_capacity = (last - first);
	_array = _alloc.allocate(new_capacity);
	_capacity = new_capacity;

	_copy_array(first, last, _array);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::assign(size_type count, const_reference value)
{
	clear();
	_array = this->_alloc.allocate(count);
	_capacity = count;

	size_type i = 0;
	for (; i < count; i++)
		_array[i] = value;
	_end = &_array[i];
}

template <typename value_type, typename allocator_type>
allocator_type	TC_VECTOR::get_allocator() const
{
	return (_alloc);
}

// ? ***************************************************************************
// ? *                              ELEMENT ACCESS                             *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
typename TC_VECTOR::reference	TC_VECTOR::front()
{
	return ( static_cast<const_reference>(*_array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reference	TC_VECTOR::front() const
{
	return ( static_cast<const_reference>(*_array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::reference	TC_VECTOR::back()
{
	return ( static_cast<const_reference>(*_end) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reference	TC_VECTOR::back() const
{
	return ( static_cast<const_reference>(*_end) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::reference	TC_VECTOR::at(const size_type pos)
{
	if (pos >= size())
		throw std::out_of_range("ERROR: Index is out of range");
	return (_array[pos]);
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reference	TC_VECTOR::at(size_type pos) const
{
	if (pos >= size())
		throw std::out_of_range("ERROR: Index is out of range");
	return (_array[pos]);
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::pointer	TC_VECTOR::data()
{
	return (_array);
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_pointer	TC_VECTOR::data() const
{
	return (static_cast<const_pointer>(_array));
}

// ? ***************************************************************************
// ? *                                ITERATORS                                *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::begin()
{
	return ( iterator(_array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_iterator	TC_VECTOR::begin() const
{
	return ( const_iterator(_array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::end()
{
	return ( iterator(_end) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_iterator	TC_VECTOR::end() const
{
	return ( const_iterator(_end) );
}

// ? ***************************************************************************
// ? *                                 CAPACITY                                *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
bool	TC_VECTOR::empty() const
{
	return ( size() == EMPTY );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::size_type	TC_VECTOR::size() const
{
	return ( static_cast<size_t>(_end - _array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::size_type	TC_VECTOR::max_size() const
{
	return ( _alloc.max_size() );
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::reserve(size_type new_cap)
{
	if (new_cap > max_size())
		throw std::length_error("ERROR: New capacity value is too high [ vector::reserve() ]");
	if (new_cap > capacity())
		_reallocate(new_cap);
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::size_type	TC_VECTOR::capacity() const
{
	return (_capacity);
}

// ? ***************************************************************************
// ? *                                 MODIFIERS                               *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
void		TC_VECTOR::clear()
{
	size_type	size_value = size();

	if (size_value > 0)
	{
		for (size_type i = 0; i < size_value; i++)
			_alloc.destroy(&_array[i]);
	}
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::erase(iterator pos)
{
	iterator ret = pos;

	for (; pos != end(); pos++)
	{
		_alloc.destroy(&(*pos));
		if ((pos + 1) != end())
			std::memcpy(&(*pos), &(*pos + 1), sizeof(value_type));
	}
	_end = &(*pos);

	return (ret);
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::erase(iterator first, iterator last)
{
	iterator	it = first;

	for (; last != end(); it++, last++)
	{
		_alloc.destroy(&(*it));
		*it = *last;
		std::memcpy(&(*it), &(*last), sizeof(value_type));
	}
	_end = &(*(it + 1));

	return (first);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::push_back(const value_type& value)
{
	if (size() < capacity())
	{
		*_end = value;
		(_end++);
	}
	else
	{
		const size_type new_capacity = (size() + 1);
		_reallocate(new_capacity);
		_end = (_array + new_capacity);
		*(_end - 1) = value;
	}
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::pop_back()
{
	_alloc.destroy(_end - 1);
	_end--;
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::resize(size_type count)
{
	if (count > capacity())
		reserve(count);

	const_iterator	new_end = ( begin() + count );

	if (count > size())
	{
		iterator		it = new_end;

		for (; it != end(); it++)
			_alloc.construct(&(*it), value_type());
		_end = &(*new_end);
	}
	else if (count < size())
	{
		erase(new_end, _end);
	}
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::resize(size_type count, value_type value)
{
	if (count > capacity())
		reserve(count);

	const_iterator	new_end = ( begin() + count );

	if (count > size())
	{
		iterator		it = new_end;

		for (; it != end(); it++)
			_alloc.construct(&(*it), value_type(value));
		_end = &(*new_end);
	}
	else if (count < size())
	{
		erase(new_end, _end);
	}
}

template <typename value_type, typename allocator_type>
void		TC_VECTOR::swap(TC_VECTOR &other)
{
	pointer	p_buf;

	p_buf = this->_array;
	this->_array = other._array;
	other._array = p_buf;

	p_buf = this->_end;
	this->_end = other._end;
	other._end = p_buf;

	size_type	s_buf;

	s_buf = this->_capacity;
	this->_capacity = other._capacity;
	other._capacity = s_buf;
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::insert(iterator pos, const_reference value)
{
	if (capacity() > size() && pos >= end())
	{
		*pos = value;
	}
	else
	{
		pointer 	array_second_part = _allocate_array(_end - pos);
		_copy_array(pos, _end, array_second_part);

		pointer 	new_array = _allocate_array(size() + 1);
		_copy_array(begin(), pos, new_array);

		size_type	n_pos = ( pos - begin() );

		_destroy_array(begin(), end());
		_array = new_array;

		pos = (_array + n_pos);
		_end = (pos + 1);
		push_back(value);
		_end = (new_array + size() + 1);
		_copy_array((pos + 1), _end, new_array);
		(_capacity++);
	}
	return (pos);
}

template <typename value_type, typename allocator_type> template <typename InputIt>
void	TC_VECTOR::insert(iterator pos, InputIt first, InputIt last)
{
	if (capacity() >= (size() + (last - first)) && pos >= end())
	{
		for (iterator it = pos; first != last; first++, it++)
			std::memcpy(&(*it), &(*first), sizeof(value_type));
	}
	else
	{
		pointer 	array_second_part = _allocate_array(_end - pos);
		_copy_array(pos, _end, array_second_part);

		pointer 	new_array = _allocate_array(size() + 1);
		_copy_array(begin(), pos, new_array);

		size_type	n_pos = ( pos - begin() );

		_destroy_array(begin(), end());
		_array = new_array;

		pos = (_array + n_pos);
		_end = (pos + 1);
		_copy_array(first, last, pos);
		_end = (new_array + size() + 1);
		_copy_array((pos + 1), _end, new_array);
		(_capacity++);
	}
	return (pos);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::insert(iterator pos, size_type count, const_reference value)
{
	if (capacity() >= ( size() + count ) && pos >= end())
	{
		for (iterator it = pos; count > 0; count--, it++)
			*it = value;
	}
	else
	{
		pointer 	array_second_part = _allocate_array(_end - pos);
		_copy_array(pos, _end, array_second_part);

		pointer 	new_array = _allocate_array(size() + 1);
		_copy_array(begin(), pos, new_array);

		size_type	n_pos = ( pos - begin() );

		_destroy_array(begin(), end());
		_array = new_array;

		pos = (_array + n_pos);
		_end = (pos + 1);

		for (iterator it = pos; count > 0; count--, it++)
			*it = value;

		_end = (new_array + size() + 1);
		_copy_array((pos + 1), _end, new_array);
		(_capacity++);
	}
	return (pos);
}

// ? ***************************************************************************
// ? *                               OPERATORS                                 *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
TC_VECTOR&	TC_VECTOR::operator = (const TC_VECTOR &other)
{
	if (this != &other)
	{
		this->_reallocate(other.size(), other._array, other._end);
	}
	return (*this);
}

template <typename value_type, typename allocator_type>
value_type&	TC_VECTOR::operator [] (size_type pos) const
{
	return ( _array[pos] );
}

// ? ***************************************************************************
// ? *                            PRIVATE METHODS                              *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
void	TC_VECTOR::_copy_array(const pointer start, const_pointer end, pointer result)
{
	if (start == result)
		return ;
	for (pointer p = start; p != end; p++)
		std::memcpy(result, p, sizeof(value_type));
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::pointer	TC_VECTOR::_allocate_array(size_type capacity)
{
	pointer	ret = NULL;

	try {
		ret = _alloc.allocate(capacity);
	} catch (const std::bad_alloc &e) {
		throw std::runtime_error("ERROR: Memory allocation failed [ vector::_allocate_array() ]");
	}
	return (ret);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::_destroy_array(iterator start, iterator end)
{
	for (; start != end; start++)
		_alloc.destroy(&(*start));
}

template <typename value_type, typename allocator_type>
bool	TC_VECTOR::_reallocate(size_type new_capacity)
{
	return ( _reallocate(new_capacity, _array, _end) );
}

template <typename value_type, typename allocator_type>
bool	TC_VECTOR::_reallocate(size_type new_capacity, pointer copy_start_point, pointer copy_end_point)
{
	bool	ret = (new_capacity != 0);

	if (ret)
	{
		clear();

		pointer	tmp = _allocate_array(new_capacity);
		_copy_array(copy_start_point, copy_end_point, tmp);
		this->_capacity = new_capacity;
		this->_array = tmp;
		this->_end = ( this->_array + (copy_end_point - copy_start_point) );
	}
	return (ret);
}

#endif // VECTOR_TPP
