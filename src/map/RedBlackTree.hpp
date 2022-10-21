#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <exception>

# include "RedBlackNode.hpp"
# include "../iterator/MapIterator.hpp"
# include "pair.hpp"

namespace ft
{
    template < typename Key, typename T, typename Allocator = std::allocator<RedBlackNode<Key, T> > >
    class RedBlackTree
    {
    public:
        typedef Key                                                       key_type;
        typedef T                                                         value_type;
        typedef Allocator                                                 allocator_type;
        typedef MapIterator<RedBlackNode<key_type, value_type> >          iterator;
        typedef RedBlackNode<key_type, value_type>                        node_type;
        typedef typename ft::pair<key_type, value_type>                   pair_type;

    private:
        node_type*     _root;
        allocator_type _alloc;

    public:
        RedBlackTree();
        explicit RedBlackTree(const RedBlackTree& other);

        bool          is_empty() const;
        void          insert(const key_type& key, const value_type& value);
        void          insert(const pair_type& pair);
        void          remove(const key_type& key);
        node_type*    find(const key_type& key);
        template <typename OperationType> void traverse(OperationType* f);

    private:
        void         _insert(node_type* node, node_type* root);
        void         _insert_fixup(node_type* node, node_type* root);

        node_type*   _find(const key_type& key, node_type* root) const;

        void         _assign(node_type* node, node_type* parent) const throw(std::runtime_error);
        node_type*   _grandparent(const node_type* node) const;
        node_type*   _uncle(const node_type* node) const throw(std::runtime_error);
        void         _rotate_left(node_type* node) const throw(std::runtime_error);
        void         _rotate_right(node_type* node) const throw(std::runtime_error);
    };
}

# include "RedBlackTree.tpp"

#endif // RED_BLACK_TREE_HPP
