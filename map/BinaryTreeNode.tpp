#ifndef BINARY_TREE_NODE_TPP
# define BINARY_TREE_NODE_TPP

# ifndef BINARY_TREE_NODE_HPP
#  include "BinaryTreeNode.hpp"
#  error __FILE__ should only be included from BinaryTreeNode.hpp
# endif

# define TC_BIN_TREE_NODE BinaryTreeNode<key_type, value_type>

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

using ft::BinaryTreeNode;

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE::BinaryTreeNode()
		:	_key(key_type()), _value(value_type()),
			_left_node(NULL), _right_node(NULL)
{
}

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE::BinaryTreeNode(const BinaryTreeNode& other)
		:	_key(other._key), _value(other._value),
			_left_node(other._left_node), _right_node(other._right_node)
{
}

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE::BinaryTreeNode(const key_type& key, const value_type& value)
		:	_key(key), _value(value),
			_left_node(NULL), _right_node(NULL)
{
}

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE::~BinaryTreeNode()
{
}

// ? ***************************************************************************
// ? *                              PUBLIC METHODS                             *
// ? ***************************************************************************

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE*	TC_BIN_TREE_NODE::left() const
{
	return (_left_node);
}

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE*	TC_BIN_TREE_NODE::right() const
{
	return (_right_node);
}

template <typename key_type, typename value_type>
const key_type	TC_BIN_TREE_NODE::get_key() const
{
	return (_key);
}

template <typename key_type, typename value_type>
const value_type	TC_BIN_TREE_NODE::get_value() const
{
	return (_value);
}

template <typename key_type, typename value_type>
void	TC_BIN_TREE_NODE::set_key(const key_type& key)
{
	this->_key = key;
}

template <typename key_type, typename value_type>
void	TC_BIN_TREE_NODE::set_value(const value_type& value)
{
	this->_value = value;
}

// ? ***************************************************************************
// ? *                          OPERATOR OVERLOADS                             *
// ? ***************************************************************************

template <typename key_type, typename value_type>
TC_BIN_TREE_NODE&	TC_BIN_TREE_NODE::operator = (const TC_BIN_TREE_NODE& other)
{
	this->_value = other._value;
	return (*this);
}

#endif // BINARY_TREE_NODE_TPP