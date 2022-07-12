#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

namespace ft
{
    template <typename Key, typename Value>
    class BinarySearchTree
    {
    public:
        typedef Key        key_type;
        typedef Value      value_type;

    private:
        BinarySearchTree    *_parent_node;
        BinarySearchTree    *_left_node;
        BinarySearchTree    *_right_node;
        key_type            _key;
        value_type          _value;

    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& other);
        explicit BinarySearchTree(const key_type& key, const value_type& value);
        ~BinarySearchTree();

        BinarySearchTree*   left(void) const;
        BinarySearchTree*   right(void) const;
        void                set_key(const key_type& key);
        void                set_value(const value_type& value);
        const key_type      get_key(void) const;
        const value_type    get_value(void) const;



        BinarySearchTree&   operator = (const BinarySearchTree& other);
    };
}

# include "BinarySearchTree.tpp"

#endif // BINARY_SEARCH_TREE_HPP
