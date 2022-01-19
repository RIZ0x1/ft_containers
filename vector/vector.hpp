#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <limits>
#include "iterator.hpp"

namespace ft {
	class vector;
}

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
	T			*_array;
	Allocator	*_alloc;
	size_t		_capacity;

public:
	// ? ***********************************************************************
	// ?                              TYPEDEFS                                 *
	// ? ***********************************************************************

	typedef ft::iterator		iterator;
	typedef ft::const_iterator	const_iterator;

	// ? ***********************************************************************
	// ?                      CONSTRUCTORS & DESTRUCTOR                        *
	// ? ***********************************************************************

	vector();
	vector(const vector &other);
	explicit vector(const Allocator &alloc);
	explicit vector(size_t count, const T &value = T(), const Allocator &alloc = Allocator());
	template <class InputIt> vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());
	~vector();

	// ? ***********************************************************************
	// ?                            MEMBER FUNCTIONS                           *
	// ? ***********************************************************************

	void		assign(size_t count, const T& value);
	template <class InputIt> void	assign(InputIt first, InputIt last);
	Allocator	get_allocator() const; // TODO: returns the allocator associated with the container

	// ? ***********************************************************************
	// ?                             ELEMENT ACCESS                            *
	// ? ***********************************************************************

	T&			front(void);
	const T&	front(void) const;
	T&			back(void);
	const T&	back(void) const;
	T&			at(size_t pos); // TODO: returns _array[pos] with bounds checking
	const T&	at(size_t pos) const;
	T*			data(void); // TODO: returns a pointer to _array[0]
	const T*	data(void) const;

	// ? ***********************************************************************
	// ?                               ITERATORS                               *
	// ? ***********************************************************************

	iterator			begin();
	iterator 			end();
	const_iterator		end() const;

	// ? ***********************************************************************
	// ?                               CAPACITY                                *
	// ? ***********************************************************************

	bool	empty(void) const; // TODO: is empty
	size_t	size(void) const; // TODO: returns the nbr of elems in the cont (std::distance)
	size_t	max_size(void) const; // TODO: returns the max nbr of elems the cont is able to hold due system (std::distance)
	void	reserve(size_t new_cap); // TODO: https://en.cppreference.com/w/cpp/container/vector/reserve
	size_t	capacity(void) const; // TODO: returns the nbr of elems that the cont has currently allocated space for

	// ? ***********************************************************************
	// ?                               MODIFIERS                               *
	// ? ***********************************************************************

	void		clear(void); // TODO: Erases all elements from the container. After this call, size() returns zero
	// iterator<T>	erase(iterator<T> pos); // TODO: Removes the element at pos
	// iterator<T>	erase(iterator<T> first, iterator<T> last); // TODO: Removes the elements in the range [first, last)
	// void		push_back(const T& value); // TODO: The new element is initialized as a copy of value
	// void		pop_back(void); // TODO: Removes the last element of the container
	// void		resize(size_t count); // TODO: https://en.cppreference.com/w/cpp/container/vector/resize
	// void		resize(size_t count, T value = T()); // TODO: https://en.cppreference.com/w/cpp/container/vector/resize
	// void		swap(vector& other); // TODO: https://en.cppreference.com/w/cpp/container/vector/swap
	//void		insert(iterator<T> pos, size_t count, const T& value); // TODO: inserts value before pos
	// typename iterator<T>	insert(iterator<T> pos, const T& value); // TODO: inserts value before pos
	// template<class InputIt> void insert( iterator<T> pos, InputIt first, InputIt last ); // TODO: https://en.cppreference.com/w/cpp/container/vector/insert

	// ? ***********************************************************************
	// ?                               OPERATORS                               *
	// ? ***********************************************************************

	vector&	operator = (const vector &other);
	T&		operator [] (size_t pos) const;
};

#include "vector.tpp"

#endif // * FT_VECTOR_HPP
