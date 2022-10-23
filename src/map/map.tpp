#ifndef MAP_TPP
# define MAP_TPP

# ifndef MAP_HPP
#  error __FILE__ should only be included from map.hpp
# endif

# define FT_MAP map<key_type, mapped_type, key_compare, allocator_type>

using ft::map;

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
FT_MAP::map()
{
	_rbtree = new RedBlackTree<key_type, value_type, allocator_type>();
}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
FT_MAP::map(const map& other)
{
	_rbtree = new RedBlackTree<key_type, value_type, allocator_type>(other._rbtree);
}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
FT_MAP::map(const key_compare& comp, const allocator_type& alloc)
{
}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
FT_MAP::~map()
{
	delete _rbtree;
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
bool FT_MAP::empty()
{
	return ( _rbtree->is_empty() );
}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
size_type FT_MAP::size()
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
size_type FT_MAP::max_size()
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
void FT_MAP::clear()
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
ft::pair<iterator, bool> FT_MAP::insert(const value_type& value)
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
iterator FT_MAP::erase(iterator first, iterator last)
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
size_type FT_MAP::erase(const key_type& key)
{

}

template <typename key_type, typename mapped_type, typename key_compare, typename allocator_type>
void FT_MAP::swap(const map& other)
{

}

// ? ***************************************************************************
// ? *                              NON-MEMBER FUNCTIONS                       *
// ? ***************************************************************************

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator == (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}
template <typename Key, typename T, typename Compare, typename Allocator>
bool operator != (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}
template <typename Key, typename T, typename Compare, typename Allocator>
bool operator <  (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}
template <typename Key, typename T, typename Compare, typename Allocator>
bool operator <= (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}
template <typename Key, typename T, typename Compare, typename Allocator>
bool operator >  (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}
template <typename Key, typename T, typename Compare, typename Allocator>
bool operator >= (const ft::map<Key, T, Compare, Allocator>& lhs,
                  const ft::map<Key, T, Compare, Allocator>& rhs) {}

#endif // MAP_TPP
