#ifndef RED_BLACK_NODE_HPP
# define RED_BLACK_NODE_HPP

# include <memory>
# include "pair.hpp"

namespace ft
{
    template <typename Key, typename Value>
    class RedBlackNode
    {
    public:
        typedef Key    key_type;
        typedef Value  value_type;
        enum NodeColor { Red, Black };

    public:
        RedBlackNode() : parent(NULL),
                         left(NULL),
                         right(NULL),
                         data(NULL),
                         color(NodeColor::Red);
        ~RedBlackNode() {
                         delete parent;
                         delete left;
                         delete right;
                         delete data;
        }

        RedBlackNode*                   parent;
        RedBlackNode*                   left;
        RedBlackNode*                   right;
        NodeColor                       color;
        ft::pair<key_type, value_type>* data;
    };
}

#endif // RED_BLACK_NODE_HPP
