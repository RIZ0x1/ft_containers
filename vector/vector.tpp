#ifndef VECTOR_TPP
# define VECTOR_TPP

# ifndef VECTOR_HPP
#  error __FILE__ should only be included from vector.hpp
# endif

#include "vector.hpp" // No need

# define TC_VECTOR	vector<value_type, allocator_type>	// Template Class 'vector'

using ft::vector;

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
TC_VECTOR::vector()
{
	_alloc = allocator_type();
	_array = NULL;
	_end = _array;
	_capacity = 0;
}

template <typename value_type, typename allocator_type>
TC_VECTOR::vector(const vector &other) : _capacity(0), _array(NULL), _end(_array)
{
	operator=(other);
}

template <typename value_type, typename allocator_type>
TC_VECTOR::vector(const allocator_type &alloc)
{
	this->_alloc = alloc;
	_array = NULL;
	_end = _array;
	_capacity = 0;
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
TC_VECTOR::vector(InputIt first, InputIt last, const allocator_type &alloc, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	this->_alloc = alloc;

	for (; first != last; first++) // this is bad
		push_back(*first);
}

template <typename value_type, typename allocator_type>
TC_VECTOR::~vector()
{
	clear();
	delete _array;
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
void	TC_VECTOR::assign(size_type count, const value_type& value)
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
template <typename InputIt>
void	TC_VECTOR::assign(InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type*)
{
	clear();
	const size_type new_capacity = (&(*last) - &(*first));

	//_copy_array(&(*first), &(*last), _array);
	_reallocate(new_capacity, &(*first), &(*last));
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
	return ( _array[pos] );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reference	TC_VECTOR::at(size_type pos) const
{
	if (pos >= size())
		throw std::out_of_range("ERROR: Index is out of range");
	return ( _array[pos] );
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
typename TC_VECTOR::reverse_iterator	TC_VECTOR::rbegin()
{
	return ( reverse_iterator(_end) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reverse_iterator	TC_VECTOR::rbegin() const
{
	return ( const_reverse_iterator(_end) );
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

template <typename value_type, typename allocator_type>
typename TC_VECTOR::reverse_iterator	TC_VECTOR::rend()
{
	return ( reverse_iterator(_array) );
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::const_reverse_iterator	TC_VECTOR::rend() const
{
	return ( const_reverse_iterator(_array) );
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
void	TC_VECTOR::reserve(size_type new_capacity)
{
	if (new_capacity > max_size())
		throw std::length_error("ERROR: New capacity value is too high [ vector::reserve() ]");
	if (new_capacity > capacity())
		_reallocate(new_capacity);
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
			_alloc.construct(&(*pos), *(pos + 1));
	}
	(_end--);

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
		_alloc.construct(&(*it), value_type(*it));
	}
	_end = &(*(it));
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
	if (_end != _array)
	{
		_alloc.destroy(_end - 1);
		(_end--);
	}
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::resize(size_type count, value_type value)
{
	try
	{
		if (size() > count)
		{
			_reallocate(size());
		}
		else
		{
			if (capacity() != count)
				_reallocate(count);
			for (size_type i = size(); i < count; i++)
				push_back(value);
		}
	}
	catch (std::length_error &e) { }
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
	size_type	new_size = ( size() + 1 );

	if ( capacity() > size() && pos >= end() )
	{
		*pos = value;
	}
	else
	{
		pointer new_array = _alloc.allocate(new_size);
		pointer p_pos_a = &(*pos);

		_copy_array(_array, p_pos_a, new_array);

		pointer	p_pos_b = ( new_array + (p_pos_a - _array) );

		*p_pos_b = value;
		_copy_array(p_pos_a, _end, p_pos_b + 1);

		clear();
		delete _array;
		_array = new_array;
		_capacity = new_size;
		_end = (_array + _capacity);
	}
	return (pos);
}

template <typename value_type, typename allocator_type> template <typename InputIt>
void	TC_VECTOR::insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	const size_type	new_size = (size() + ( &(*last) - &(*first) ));

	if ( capacity() >= new_size && pos >= end() )
	{
		for (; first != last; first++)
			push_back(*first);
	}
	else
	{
		const pointer	second_part_size = _end - &(*pos);
		pointer			array_second_part = _allocate_array(second_part_size);
		_copy_array(pos, _end, array_second_part);

		pointer	new_array = _allocate_array(new_size);
		_copy_array(begin(), pos, new_array);

		size_type n_pos = ( &(*pos) - &(*begin()) );
		for (; first != last; first++, n_pos++)
			*(new_array + n_pos) = *first;

		_copy_array( array_second_part, (array_second_part + second_part_size), (new_array + n_pos) );

		clear();
		delete _array;
		_array = new_array;
		_capacity = new_size;
		_end = (_array + new_size);
	}
	return (pos);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::insert(iterator pos, size_type count, const_reference value)
{
	const size_type	new_size = ( size() + count );

	if ( capacity() >= new_size && pos >= end() )
	{
		for (size_type i = 0; i < count; i++, pos++)
			push_back(*pos);
	}
	else
	{
		const pointer	second_part_size = _end - &(*pos);
		pointer			array_second_part = _allocate_array(second_part_size);
		_copy_array(pos, _end, array_second_part);

		pointer	new_array = _allocate_array(new_size);
		_copy_array(begin(), pos, new_array);

		size_type n_pos = ( &(*pos) - &(*begin()) );
		for (size_type i = 0; i < count; i++)
			*(new_array + n_pos) = value;
		_copy_array( array_second_part, (array_second_part + second_part_size), (new_array + n_pos) );

		clear();
		delete _array;
		_array = new_array;
		_capacity = new_size;
		_end = (_array + new_size);
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
	for (pointer p = start; p != end; p++, result++)
		_alloc.construct(result, value_type(*p));
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
void	TC_VECTOR::_reallocate(size_type new_capacity)
{
	_reallocate(new_capacity, _array, _end);
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::_reallocate(size_type new_capacity, pointer copy_start_point, pointer copy_end_point)
{
	if (new_capacity != 0)
	{
		clear();

		pointer	tmp = _allocate_array(new_capacity);
		_copy_array(copy_start_point, copy_end_point, tmp);
		this->_capacity = new_capacity;
		this->_array = tmp;
		this->_end = ( this->_array + (copy_end_point - copy_start_point) );
	}
}

#endif // VECTOR_TPP
