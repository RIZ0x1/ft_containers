#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <functional>
# include <pair.hpp>
# include "BidirectionalIterator.hpp"
# include "BinaryTreeNode.hpp"

namespace ft
{
	template < typename Key, typename T,
			  typename Compare = std::less<Key>,
			  typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef unsigned long int										size_type;
		typedef typename iterator_traits<iterator>::reference			reference;
		typedef typename iterator_traits<iterator>::pointer				pointer;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename iterator_traits<iterator>::reference			const_reference;
		typedef typename iterator_traits<iterator>::pointer				const_pointer;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef ft::pair<const key_type, value_type>	node_type;

	public:
		map();
		map(const map& other);
		explicit map(const key_compare& comp, const allocator_type& alloc = allocator_type());
		~map();



	};
}

#endif // MAP_HPP
