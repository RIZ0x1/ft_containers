#ifndef BINARY_SEARCH_TREE_TPP
# define BINARY_SEARCH_TREE_TPP

# ifndef BINARY_SEARCH_TREE_HPP
#  error __FILE__ should only be included from BinarySearchTree.hpp
# endif

# define FT_BST BinarySearchTree<key_type, value_type>

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

using ft::BinarySearchTree;

template <typename key_type, typename value_type>
FT_BTS::BinarySearchTree()
    : _key(key_type()), _value(value_type()), _left_node(NULL), _right_node(NULL)
{
}

template <typename key_type, typename value_type>
FT_BTS::BinarySearchTree(const BinarySearchTree& other)
    : _key(other._key), _value(other._value), _left_node(other._left_node), _right_node(other._right_node)
{
}

template <typename key_type, typename value_type>
FT_BTS::BinarySearchTree(const key_type& key, const value_type& value)
    : _key(key), _value(value), _left_node(NULL), _right_node(NULL)
{
}

template <typename key_type, typename value_type>
FT_BTS::~BinarySearchTree()
{
}

// ? ***************************************************************************
// ? *                              PUBLIC METHODS                             *
// ? ***************************************************************************

template <typename key_type, typename value_type>
FT_BTS*  FT_BTS::left() const
{
    return (_left_node);
}

template <typename key_type, typename value_type>
FT_BTS*  FT_BTS::right() const
{
    return (_right_node);
}

template <typename key_type, typename value_type>
const key_type  FT_BTS::get_key() const
{
    return (_key);
}

template <typename key_type, typename value_type>
const value_type FT_BTS::get_value() const
{
    return (_value);
}

template <typename key_type, typename value_type>
void FT_BTS::set_key(const key_type& key)
{
    this->_key = key;
}

template <typename key_type, typename value_type>
void FT_BTS::set_value(const value_type& value)
{
    this->_value = value;
}

// ? ***************************************************************************
// ? *                          OPERATOR OVERLOADS                             *
// ? ***************************************************************************

template <typename key_type, typename value_type>
FT_BTS& FT_BTS::operator = (const FT_BTS& other)
    this->_value = other._value;
    return (*this);
}

#endif // BINARY_SEARCH_TREE_TPP
