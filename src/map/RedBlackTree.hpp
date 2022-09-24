#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <exception>

# include "RedBlackNode.hpp"

namespace ft
{
    template <typename Key, typename T, typename Allocator = std::allocator<RedBlackNode<Key, T> > >
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
        void            _insert_case1(RedBlackNode* node);

        RedBlackNode*   _find(const key_type& key, RedBlackNode* root);

        void            _assign(RedBlackNode* node, RedBlackNode* parent) throw(std::runtime_error);
        RedBlackNode*   _grandparent(RedBlackNode* node);
        RedBlackNode*   _uncle(RedBlackNode* node) throw(std::runtime_error);
        void            _rotate_left(RedBlackNode* node) throw(std::runtime_error);
        void            _rotate_right(RedBlackNode* node) throw(std::runtime_error);
    };
}

# include "RedBlackTree.tpp"

#endif // RED_BLACK_TREE_HPP
