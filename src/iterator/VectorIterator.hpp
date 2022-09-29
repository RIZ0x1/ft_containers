#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterators_core.hpp"

namespace ft
{
    template <typename T>
    class VectorIterator : public iterator<random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator<random_access_iterator_tag, T>   traits;
        typedef typename iterator_traits<traits>::iterator_category    iterator_category;
        typedef typename iterator_traits<traits>::value_type           value_type;
        typedef typename iterator_traits<traits>::difference_type      difference_type;
        typedef typename iterator_traits<traits>::pointer              pointer;
        typedef typename iterator_traits<traits>::reference            reference;
        typedef VectorIterator<T>                                      iterator;
        typedef unsigned long                                          size_type;

    protected:
        pointer _ptr;
    public:
        VectorIterator();
        explicit VectorIterator(pointer ptr);
        VectorIterator(const iterator& other);
        ~VectorIterator();

        bool           operator == (const iterator &other) const;
        bool           operator != (const iterator &other) const;
        bool           operator < (const iterator &other) const;
        bool           operator > (const iterator &other) const;
        bool           operator <= (const iterator &other) const;
        bool           operator >= (const iterator &other) const;
        reference      operator * (void) const;
        reference      operator [] (const size_type pos) const;
        pointer        operator -> (void) const;
        iterator       operator + (const difference_type N) const;
        iterator       operator - (const difference_type N) const;
        iterator       operator ++ (void);
        const iterator operator ++ (int);
        iterator       operator -- (void);
        const iterator operator -- (int);
        iterator       operator += (const difference_type N);
        iterator       operator -= (const difference_type N);

    protected:
        inline pointer _get_pointer(void) const;
    };

    template <typename T>
    class ConstVectorIterator : public VectorIterator<const T>
    {
    public:
        typedef ConstVectorIterator<T>                  iterator;
        typedef typename iterator_traits<iterator>::pointer pointer;
    public:
        ConstVectorIterator() : VectorIterator<const T>() {};
        explicit ConstVectorIterator(pointer ptr) : VectorIterator<const T>(ptr) {};
        ConstVectorIterator(const ConstVectorIterator& other) : VectorIterator<const T>::_ptr(other._get_pointer()) {};
    };

    template <typename T>
    class ReverseVectorIterator : public VectorIterator<T>
    {
    public:
        typedef ReverseVectorIterator<T>                             iterator;
        typedef typename iterator_traits<iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<iterator>::value_type           value_type;
        typedef typename iterator_traits<iterator>::difference_type      difference_type;
        typedef typename iterator_traits<iterator>::pointer              pointer;
        typedef typename iterator_traits<iterator>::reference            reference;

    public:
        ReverseVectorIterator();
        explicit ReverseVectorIterator(pointer ptr);
        ReverseVectorIterator(const iterator& other);
        ~ReverseVectorIterator();

        iterator            operator + (const difference_type N) const;
        iterator            operator - (const difference_type N) const;
        iterator            operator ++ (void);
        const iterator      operator ++ (int);
        iterator            operator -- (void);
        const iterator      operator -- (int);
        iterator            operator += (const difference_type N);
        iterator            operator -= (const difference_type N);
    };

    template <typename T>
    class ConstReverseVectorIterator : public ReverseVectorIterator<const T>
    {
    public:
        typedef ConstVectorIterator<T>                  iterator;
        typedef typename iterator_traits<iterator>::pointer pointer;
    public:
        ConstReverseVectorIterator() : ReverseVectorIterator<const T>() {};
        explicit ConstReverseVectorIterator(pointer ptr) : ReverseVectorIterator<const T>(ptr) {};
        ConstReverseVectorIterator(const ConstReverseVectorIterator& other) : ReverseVectorIterator<const T>::_ptr(other._get_pointer()) {};
    };
}

#include "VectorIterator.tpp"

#endif // VECTOR_ITERATOR_HPP
