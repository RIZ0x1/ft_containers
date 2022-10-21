#ifndef VECTOR_HPP
# define VECTOR_HPP

# ifdef __unix
#  include <cstring>
# endif

# include <memory>
# include <limits>
# include <iostream>
# include <stdexcept>
# include "../iterator/VectorIterator.hpp"
# include "../ft_utils/enable_if.hpp"
# include "../ft_utils/is_integral.hpp"
# include "../ft_utils/lexicographical_compare.hpp"

namespace ft {
    template < typename T, typename Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T                                                   value_type;
        typedef const value_type                                    const_value_type;
        typedef value_type&                                         reference;
        typedef const value_type&                                   const_reference;
        typedef Allocator                                           allocator_type;
        typedef typename allocator_type::pointer                    pointer;
        typedef const typename allocator_type::pointer              const_pointer;
        typedef std::ptrdiff_t                                      difference_type;
        typedef unsigned long int                                   size_type;

        typedef typename ft::VectorIterator<value_type>             iterator;
        typedef typename ft::ConstVectorIterator<value_type>        const_iterator;
        typedef typename ft::ReverseVectorIterator<value_type>      reverse_iterator;
        typedef typename ft::ConstReverseVectorIterator<value_type> const_reverse_iterator;

    private:
        value_type*      _array;
        value_type*      _end;
        allocator_type   _alloc;
        size_type        _capacity;

    public:
        vector();
        vector(const vector &other);
        explicit vector(const allocator_type &alloc);
        explicit vector(size_type count, const_reference value = value_type(), const allocator_type& alloc = allocator_type());
        template <class InputIt>
            vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
        ~vector();

        allocator_type get_allocator() const;
        void assign(size_type count, const_reference value);
        template <class InputIt>
            void assign(InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type* = NULL);

        reference           front(void);
        const_reference     front(void) const;
        reference           back(void);
        const_reference     back(void) const;
        reference           at(size_type pos);
        const_reference     at(size_type pos) const;
        value_type*         data(void);
        const_value_type*   data(void) const;

        iterator               begin(void);
        const_iterator         begin(void) const;
        reverse_iterator       rbegin(void);
        const_reverse_iterator rbegin(void) const;
        iterator               end(void);
        const_iterator         end(void) const;
        reverse_iterator       rend(void);
        const_reverse_iterator rend(void) const;

        bool      empty(void) const;
        size_type size(void) const;
        size_type max_size(void) const;
        void      reserve(size_type new_cap);
        size_type capacity(void) const;

        void      clear(void);
        iterator  erase(iterator pos);
        iterator  erase(iterator first, iterator last);
        void      push_back(const_reference value);
        void      pop_back(void);
        void      resize(size_type count, value_type value = value_type());
        void      swap(vector& other);
        void      insert(iterator pos, size_type count, const_reference value);
        iterator  insert(iterator pos, const_reference value);
        template<class InputIt>
            void insert( iterator pos, InputIt first, InputIt last,
                    typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);

        vector&       operator = (const vector& other);
        value_type&   operator [] (size_type pos) const;

    private:
        void        _copy_array(const_value_type* start, const_value_type* end, value_type* result);
        value_type* _allocate_array(size_type capacity);
        void        _destroy_array(iterator start, iterator end);
        void        _reallocate(size_type new_capacity);
        void        _reallocate(size_type new_capacity, value_type* copy_start_point, value_type* copy_end_point);
    };

    template <typename T, class Alloc>
    bool    operator == (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
    template <typename T, class Alloc>
    bool    operator != (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
    template <typename T, class Alloc>
    bool    operator < (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
    template <typename T, class Alloc>
    bool    operator <= (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
    template <typename T, class Alloc>
    bool    operator > (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
    template <typename T, class Alloc>
    bool    operator >= (const vector<T, Alloc> lhs, const vector<T, Alloc> rhs);
}

# include "vector.tpp"

#endif // VECTOR_HPP
