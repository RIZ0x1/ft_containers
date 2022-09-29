#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterators_core.hpp"

namespace ft
{
    template <typename Node>
    class MapIterator : public iterator<bidirectional_iterator_tag, Node>
    {
    public:
        typedef MapIterator<Node>                              iterator;
        typedef typename iterator_traits<iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<iterator>::value_type           value_type;
        typedef typename iterator_traits<iterator>::difference_type      difference_type;
        typedef typename iterator_traits<iterator>::pointer              pointer;
        typedef typename iterator_traits<iterator>::reference            reference;
        typedef unsigned long                                            size_type;

    protected:
        pointer _p_node;
    public:
        MapIterator();
        explicit MapIterator(pointer p_node);
        MapIterator(const iterator& other);
        ~MapIterator();

        bool                    operator == (const iterator &other) const;
        bool                    operator != (const iterator &other) const;
        bool                    operator < (const iterator &other) const;
        bool                    operator > (const iterator &other) const;
        bool                    operator <= (const iterator &other) const;
        bool                    operator >= (const iterator &other) const;
        reference               operator * (void) const;
        reference               operator [] (const size_type pos) const;
        pointer                 operator -> (void) const;
        virtual iterator        operator + (const difference_type N) const;
        virtual iterator        operator - (const difference_type N) const;
        virtual iterator        operator ++ (void);
        virtual const iterator  operator ++ (int);
        virtual iterator        operator -- (void);
        virtual const iterator  operator -- (int);
        virtual iterator        operator += (const difference_type N);
        virtual iterator        operator -= (const difference_type N);

    protected:
        inline pointer _get_pointer(void) const;
    };
}

#endif // MAP_ITERATOR_HPP
