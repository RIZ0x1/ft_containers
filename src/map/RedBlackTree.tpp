#ifndef RED_BLACK_TREE_TPP
# define RED_BLACK_TREE_TPP

# ifndef RED_BLACK_TREE_HPP
#  error __FILE__ should only be included from RedBlackTree.hpp
# endif

# define FT_RBT RedBlackTree<key_type, value_type, allocator_type>

using ft::RedBlackTree;

// ? ***************************************************************************
// ? *                       CONSTRUCTORS & DESTRUCTOR                         *
// ? ***************************************************************************

template <typename key_type, typename value_type, typename allocator_type>
FT_RBT::RedBlackTree() : _root(NULL), _alloc(allocator_type())
{
}

template <typename key_type, typename value_type, typename allocator_type>
FT_RBT::RedBlackTree(const FT_RBT& other)
{
    // TODO
}

// ? ***************************************************************************
// ? *                             MEMBER FUNCTIONS                            *
// ? ***************************************************************************

template <typename key_type, typename value_type, typename allocator_type>
bool FT_RBT::is_empty() const
{
    return (_root == NULL);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::insert(const key_type& key, const value_type& value)
{
    typename FT_RBT::node_type *node = _alloc.allocate(1);
    node->data = ft::make_pair<key_type, value_type>(key, value);
    node->data.key = key;
    node->data.value = value;

    _insert(node, _root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::insert(const pair_type& pair)
{
    node_type *node = _alloc.allocate(1);
    node->data = ft::make_pair<key_type, value_type>(pair.key, pair.value);
    node->data.key = pair.key;
    node->data.value = pair.value;

    _insert(node, _root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::remove(const key_type& key)
{

}

template <typename key_type, typename value_type, typename allocator_type>
typename FT_RBT::node_type* FT_RBT::find(const key_type& key)
{
    return ( _find(key, _root) );
}

template <typename key_type, typename value_type, typename allocator_type>
template <typename OperationType>
void FT_RBT::traverse(OperationType* f)
{

}

// *****************************************************************************
// *                                 UTILS                                     *
// *****************************************************************************

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_insert(node_type* node, node_type* root)
{
    node_type *cursor = root;

    if (cursor == NULL || node == NULL)
        throw std::runtime_error("(RedBlackTree::_insert): NULL as parameter");

    while (cursor->left != NULL || cursor->right != NULL)
    {
        if (node->data.key < cursor->data.key)
            cursor = cursor->left;
        else
            cursor = cursor->right;
    }
    
    if (node->data.key < cursor->data.key)
        cursor->left = node;
    else
        cursor->right = node;
    node->parent = cursor;
    node->color  = NodeColor::Red;
    _insert_fixup(node, root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_insert_fixup(node_type* node, node_type* root)
{

}

template <typename key_type, typename value_type, typename allocator_type>
typename FT_RBT::node_type* FT_RBT::_find(const key_type& key, node_type* root) const
{
    if (root == NULL)
        return (NULL);
    if (root->data.key < key)
        return ( _find(key, root->left) );
    if (root->data.key > key)
        return ( _find(key, root->right) );
    else
        return (root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_assign(node_type* node, node_type* parent) const throw(std::runtime_error)
{
    if (node == NULL)
        throw std::runtime_error("(RedBlackTree::_assign): NULL as parameter");

    if (parent != NULL)
    {
        node->parent = parent;
        if (parent->data.key > node->data.key)
            parent->left = node;
        else
            parent->right = node;
    }
}

template <typename key_type, typename value_type, typename allocator_type>
typename FT_RBT::node_type* FT_RBT::_grandparent(const node_type* node) const
{
    if (node != NULL && node->parent != NULL)
        return (node->parent->parent);
    else
        return (NULL);
}

template <typename key_type, typename value_type, typename allocator_type>
typename FT_RBT::node_type* FT_RBT::_uncle(const node_type* node) const throw(std::runtime_error)
{
    if (node != NULL)
        throw std::runtime_error("(RedBlackTree::_uncle): NULL as parameter");

    node_type* grandparent = _grandparent(node);

    if (grandparent != NULL)
    {
        if (grandparent->left == node->parent)
            return (grandparent->right);
        else
            return (grandparent->left);
    }
    return (NULL);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_rotate_left(node_type* node) const throw(std::runtime_error)
{
    if (node != NULL)
        throw std::runtime_error("(RedBlackTree::_rotate_left): NULL as parameter");

    if (node->left != NULL)
    {
        node_type* replace_node = node->left;
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

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_rotate_right(node_type* node) const throw(std::runtime_error)
{
    if (node != NULL)
        throw std::runtime_error("(RedBlackTree::_rotate_right): NULL as parameter");

    if (node->right != NULL)
    {
        node_type* replace_node = node->right;
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
