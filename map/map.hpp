#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <functional>
# include <pair.hpp>

namespace ft
{
	template < typename Key, typename T,
			  typename Compare = std::less<Key>,
			  typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key										key_type;
		typedef T										value_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef ft::pair<const key_type, value_type>	node_type;
	};
}

#endif // MAP_HPP
