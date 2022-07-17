#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "RedBlackNode.hpp"

namespace ft
{
    template <typename Key, typename T, typename Allocator = std::allocator<RedBlackNode> > >
    class RedBlackTree
    {
    public:
        typedef Key   key_type;
        typedef T     value_type;

    private:
        RedBlackNode<key_type, value_type>* _root;
        allocator_type                      _alloc;

    public:
        RedBlackTree();
        RedBlackTree(const RedBlackTree& other);

        void          insert(const key_type& key, const value_type& value);
        void          remove(const key_type& key);
        RedBlackNode* find(const key_type& key);
        template <typename OperationType> void traverse(OperationType* f);

    private:
        void            _insert(const key_type& key, const value_type& value, RedBlackNode* root);
        RedBlackNode*   _find(const key_type& key, RedBlackNode* root);

        RedBlackNode*   _grandparent(RedBlackNode* node);
        RedBlackNode*   _uncle(RedBlackNode* node);
        void            _rotate_left(RedBlackNode* node);
        void            _rotate_right(RedBlackNode* node);
    };
}

# inlcude "RedBlackTree.tpp"

#endif // RED_BLACK_TREE_HPP
