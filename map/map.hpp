#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <functional>

namespace ft
{
	template < typename Key, typename T,
			  typename Compare = std::less<Key>,
			  typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{

	};
}

#endif // MAP_HPP
