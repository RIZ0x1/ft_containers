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
    node->data.first = key;
    node->data.second = value;

    _insert(node, _root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::insert(const pair_type& pair)
{
    node_type *node = _alloc.allocate(1);
    node->data = ft::make_pair<key_type, value_type>(pair.first, pair.second);
    node->data.first = pair.first;
    node->data.second = pair.second;

    _insert(node, _root);
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::remove(const key_type& key)
{
    _remove(_find(key, _root), _root);
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
        if (node->data.first < cursor->data.first)
            cursor = cursor->left;
        else
            cursor = cursor->right;
    }
    
    if (node->data.first < cursor->data.first)
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
    if (node == NULL)
        throw std::runtime_error("(RedBlackTree::_insert_fixup): NULL as parameter");

    node_type *parent = node->parent;

    while (node != _root && parent->color == NodeColor::Red)
    {
        node_type *gparent = _grandparent(node);
        node_type *uncle = _uncle(node);

        if (uncle == gparent->right)
        {
            if (uncle != NULL && uncle->color == NodeColor::Red)
            {
                parent->color   = NodeColor::Black;
                uncle->color    = NodeColor::Black;
                gparent->color  = NodeColor::Red;
                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->right == node)
                {
                    _rotate_left(parent);
                    _swap(node, parent);
                }
                _rotate_right(gparent);
                gparent->color = NodeColor::Red;
                parent->color  = NodeColor::Black;
                break ;
            }
        }
        else
        {
            if (uncle != NULL && uncle->color == NodeColor::Red)
            {
                gparent->color  = NodeColor::Red;
                parent->color   = NodeColor::Black;
                uncle->color    = NodeColor::Black;
                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->left == node)
                {
                    _rotate_right(parent);
                    _swap(node, parent);
                }
                _rotate_left(gparent);
                gparent->color = NodeColor::Red;
                parent->color  = NodeColor::Black;
                break ;
            }
        }
    }
    root->color = NodeColor::Black;
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_remove(node_type* node, node_type* root)
{
    // todo
}

template <typename key_type, typename value_type, typename allocator_type>
void FT_RBT::_remove_fixup(node_type* node, node_type* root)
{
    // todo
}

template <typename key_type, typename value_type, typename allocator_type>
typename FT_RBT::node_type* FT_RBT::_find(const key_type& key, node_type* root) const
{
    if (root == NULL)
        return (NULL);
    if (root->data.first < key)
        return ( _find(key, root->left) );
    if (root->data.first > key)
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
        if (parent->data.first > node->data.first)
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
