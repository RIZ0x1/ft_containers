#ifndef BINARY_TREE_NODE_HPP
# define BINARY_TREE_NODE_HPP

namespace ft
{
	template <typename Key, typename Value>
	class BinaryTreeNode
	{
	public:
		typedef Key		key_type;
		typedef Value	value_type;

	private:
		BinaryTreeNode	*_left_node;
		BinaryTreeNode	*_right_node;
		key_type		_key;
		value_type		_value;

	public:
		BinaryTreeNode();
		BinaryTreeNode(const BinaryTreeNode& other);
		explicit BinaryTreeNode(const key_type& key, const value_type& value);
		~BinaryTreeNode();

		BinaryTreeNode*		left(void) const;
		BinaryTreeNode*		right(void) const;
		void				set_key(const key_type& key);
		void				set_value(const value_type& value);
		const key_type		get_key(void) const;
		const value_type	get_value(void) const;

		BinaryTreeNode&		operator = (const BinaryTreeNode& other);
	};
}

# include "BinaryTreeNode.tpp"

#endif // BINARY_TREE_NODE_HPP