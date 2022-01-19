#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>

namespace ft {
	class iterator;
	typedef const iterator const_iterator;
}

template <typename T>
class iterator : public std::iterator<std::input_iterator_tag, T>
{

public:

};

#endif // ITERATOR_HPP