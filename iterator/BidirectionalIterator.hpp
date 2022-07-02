#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterators_core.hpp"

namespace ft
{
    template <typename Node>
    class BidirectionalIterator : public iterator<bidirectional_iterator_tag, Node>
    {
    public:
        typedef typename ft::iterator<random_access_iterator_tag, Node>  traits;
        typedef typename iterator_traits<traits>::iterator_category      iterator_category;
        typedef typename iterator_traits<traits>::value_type             value_type;
        typedef typename iterator_traits<traits>::difference_type        difference_type;
        typedef typename iterator_traits<traits>::pointer                pointer;
        typedef typename iterator_traits<traits>::reference              reference;
        typedef BidirectionalIterator<Node>                              iterator;
        typedef unsigned long                                            size_type;

    protected:
        pointer _p_node;
    public:
        BidirectionalIterator();
        explicit BidirectionalIterator(pointer p_node);
        BidirectionalIterator(const iterator& other);
        ~BidirectionalIterator();

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

#endif // BIDIRECTIONAL_ITERATOR_HPP
