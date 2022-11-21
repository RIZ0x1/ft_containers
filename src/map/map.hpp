#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <functional>
# include "../iterator/MapIterator.hpp"
# include "RedBlackTree.hpp"
# include "pair.hpp"

namespace ft
{
    template < typename Key, typename T,
               typename Compare = std::less<Key>,
               typename Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef unsigned long int                                        size_type;
        typedef Compare                                                  key_compare;
        typedef Allocator                                                allocator_type;
        typedef Key                                                      key_type;
        typedef T                                                        mapped_type;
        typedef ft::pair<const key_type, mapped_type>                    value_type;
        typedef MapIterator< RedBlackNode<key_type, mapped_type> >       iterator;
        typedef const MapIterator< RedBlackNode<key_type, mapped_type> > const_iterator;

    private:
        RedBlackTree<key_type, mapped_type>*    _rbtree;
        allocator_type                          _alloc;
        key_compare                             _key_comp;

    public:
        map();
        map(const map& other);
        explicit map(const key_compare& comp, const allocator_type& alloc = allocator_type());
        ~map();

        /* Capacity */
        bool        empty() const;
        size_type   size() const;
        size_type   max_size() const;

        /* Modifiers */
        void                        clear();
        ft::pair<iterator, bool>    insert(const value_type& value);
        iterator                    erase(iterator first, iterator last);
        size_type                   erase(const key_type& key);
        void                        swap(const map& other);
        template <typename InputIt>
            void                    insert(InputIt first, InputIt last);

        /* Lookup */
        size_type                                count(const key_type& key) const;
        iterator                                 find(const key_type& key);
        const_iterator                           find(const key_type& key) const;
        ft::pair<iterator, iterator>             equal_range(const Key& key);
        ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const;
        iterator                                 lower_bound(const Key& key);
        const_iterator                           lower_bound(const Key& key) const;
        iterator                                 upper_bound(const Key& key);
        const_iterator                           upper_bound(const Key& key) const;

        /* Observers */
        key_compare   key_comp() const;
        value_compare value_comp() const;

        /* Operator */
        mapped_type& operator [] (const key_type& key);
    };

    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator == (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);
    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator != (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);
    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator <  (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);
    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator <= (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);
    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator >  (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);
    template <typename Key, typename T, typename Compare, typename Allocator>
    bool operator >= (const ft::map<Key, T, Compare, Allocator>& lhs,
                      const ft::map<Key, T, Compare, Allocator>& rhs);

    template <typename Key, typename T, typename Compare, typename Allocator>
    void swap(ft::map<Key, T, Compare, Allocator>& lhs,
              ft::map<Key, T, Compare, Allocator>& rhs);
}

# include "map.tpp"

#endif // MAP_HPP
