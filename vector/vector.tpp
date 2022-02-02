#ifndef VECTOR_TPP
# define VECTOR_TPP

# ifndef VECTOR_HPP
#  error __FILE__ should only be included from vector.hpp
# endif

# define TC_VECTOR vector<value_type, allocator_type>
# define EMPTY 0

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
TC_VECTOR::vector(const vector &other)
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

}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::assign(size_type count, const_reference value)
{

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
	return ( std::numeric_limits<size_type>::max() / sizeof(value_type) );
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
	_alloc.deallocate(_array, capacity());
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::erase(iterator pos)
{
	// выделение пямяти (size() - 1)
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::erase(iterator first, iterator last)
{

}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::push_back(const_reference value)
{

}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::pop_back()
{
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::resize(size_type count)
{
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::resize(size_type count, value_type value)
{
}

template <typename value_type, typename allocator_type>
void		TC_VECTOR::swap(TC_VECTOR &other)
{
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::iterator	TC_VECTOR::insert(iterator pos, const_reference value)
{
}

template <typename value_type, typename allocator_type> template <typename InputIt>
void	TC_VECTOR::insert(iterator pos, InputIt first, InputIt last)
{
}

template <typename value_type, typename allocator_type>
void	TC_VECTOR::insert(iterator pos, size_type count, const_reference value)
{
}

// ? ***************************************************************************
// ? *                               OPERATORS                                 *
// ? ***************************************************************************

template <typename value_type, typename allocator_type>
TC_VECTOR&	TC_VECTOR::operator = (const TC_VECTOR &other)
{
	if (this->capacity() < other.size())
		this->_reallocate(other.size());

	this->_copy_array(other._array, other._end, _array);
	this->_end = ( this->_array + other.size() );

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
	for (pointer i = start; i != end; i++)
		*(result++) = *i;
}

template <typename value_type, typename allocator_type>
typename TC_VECTOR::pointer	TC_VECTOR::_allocate_array(size_type capacity)
{
	pointer	ret;

	try {
		ret = _alloc.allocate(capacity);
	} catch (const std::bad_alloc &e) {
		throw std::runtime_error("ERROR: Memory allocation failed [ vector::_allocate_array() ]");
	}
	return (ret);
}

template <typename value_type, typename allocator_type>
bool	TC_VECTOR::_reallocate(size_type new_capacity)
{
	bool	ret;

	ret = (new_capacity == 0);

	if (ret)
	{
		const size_type	old_size = size();
		pointer			tmp = _allocate_array(new_capacity);

		try {
			for (size_type i = 0; i < size(); i++)
				_alloc.construct(&tmp[i], _array[i]);
		} catch (std::exception &e) {
			_alloc.deallocate(tmp, new_capacity);
			throw std::runtime_error("ERROR: Memory initialization failed [ vector::_reallocate() ]");
		}

		for (size_type i = 0; i < size(); i++)
			_alloc.destroy(&_array[i]);
		if (capacity() != 0)
			clear();

		this->_array = tmp;
	}
	return (ret);
}

#endif // VECTOR_TPP
