#ifndef RED_BLACK_TREE_TPP
# define RED_BLACK_TREE_TPP

# ifndef RED_BLACK_TREE_HPP
#  error __FILE__ should only be included from RedBlackTree.hpp
# endif

# define FT_RBT RedBlackTree<key_type, value_type>

using ft::RedBlackTree;

template <typename key_type, typename value_type>
FT_RBT::RedBlackTree() : _root(NULL) _alloc(allocator_type())
{
}

template <typename key_type, typename value_type>
FT_RBT::RedBlackTree(const RedBlackTree& other)
{
    // TODO
}

template <typename key_type, typename value_type>
void FT_RBT::_insert(const key_type& key, const value_type& value, RedBlackNode* root)
{

}

template <typename key_type, typename value_type>
void FT_RBT::insert(const key_type& key, const value_type& value)
{
    _insert(key, value, _root);
}

template <typename key_type, typename value_type>
void FT_RBT::delete(const key_type& key)
{

}

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::_find(const key_type& key, RedBlackNode* root)
{
    if (root == NULL)
        return (NULL);
    if (root.data.key < key)
        return ( _find(key, root.left) );
    if (root.data.key > key)
        return ( _find(key, root.right) );
    else
        return (root);
}

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::find(const key_type& key)
{
    return ( _find(key, _root) );
}

template <typename key_type, typename value_type>
template <typename OperationType>
void FT_RBT::traverse(OperationType* f)
{

}

// *****************************************************************************
// *                                 UTILS                                     *
// *****************************************************************************

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::_insert_case1(RedBlackNode *node)
{
    if (node != NULL)
    {
        if (node->parent == NULL)
            node->color = NodeColor::Black;
        else
            _insert_case2(node);
    }
}

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::_insert_case1(RedBlackNode *node)
{
    if (node != NULL)
    {
        if (node->parent->color == NodeColor::Black)
            
    }
}

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::_grandparent(const RedBlackNode* node)
{
    if (node != NULL && node->parent != NULL)
        return (node->parent->parent);
    else
        return (NULL);
}

template <typename key_type, typename value_type>
RedBlackNode* FT_RBT::_uncle(const RedBlackNode* node)
{
    RedBlackNode* grandparent = _grandparent(node);

    if (grandparent != NULL)
    {
        if (grandparent->left == node->left)
            return (grandparent->right);
        else
            return (grandparent->left);
    }
    return (NULL);
}

template <typename key_type, typename value_type>
void FT_RBT::_rotate_left(RedBlackNode* node)
{
    if (node->left != NULL)
    {
        RedBlackNode* replace_node = node->left;
        node->left = replace_node->right;
        replace_node->right = node;
        replace_node->parent = node->parent;
        node->parent = replace_node;

        if (replace_node->parent->left == node)
            replace_node->parent->left = replace_node;
        else
            replace_node->parent->right = replace_node;
    }
}

template <typename key_type, typename value_type>
void FT_RBT::_rotate_right(RedBlackNode* node)
{
    if (node->right != NULL)
    {
        RedBlackNode* replace_node = node->right;
        node->right = replace_node->left;
        replace_node->left = node;
        replace_node->parent = node->parent;
        node->parent = replace_node;

        if (replace_node->parent->left == node)
            replace_node->parent->left = replace_node;
        else
            replace_node->parent->right = replace_node;
    }
}

#endif // RED_BLACK_TREE_TPP
