#ifndef FORWARD_ITERATOR_TPP
# define FORWARD_ITERATOR_TPP

#include "iterators_core.hpp"

namespace ft
{
	// ? ***************************************************************
	// ? *                       VECTOR ITERATOR                       *
	// ? ***************************************************************

	template <typename T>
	class ContiguousIterator : public iterator<random_access_iterator_tag, T>
	{
	public:
		typedef ContiguousIterator<T>									iterator;
		typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator>::value_type			value_type;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename iterator_traits<iterator>::pointer				pointer;
		typedef typename iterator_traits<iterator>::reference			reference;

	protected:
		pointer _ptr;
	public:
		ContiguousIterator();
		ContiguousIterator(const iterator& other);
		~ContiguousIterator();

		bool						operator == (const iterator &other) const;
		bool						operator != (const iterator &other) const;
		bool						operator < (const iterator &other) const;
		bool						operator > (const iterator &other) const;
		bool						operator <= (const iterator &other) const;
		bool						operator >= (const iterator &other) const;
		value_type					operator *	(void) const;
		value_type					operator -> (void) const;
		virtual iterator			operator + (const difference_type N) const;
		virtual iterator			operator - (const difference_type N) const;
		virtual iterator			operator ++ (void);
		virtual const iterator		operator ++ (int);
		virtual iterator			operator -- (void);
		virtual const iterator		operator -- (int);
		virtual iterator			operator += (const difference_type N);
		virtual iterator			operator -= (const difference_type N);

	protected:
		ContiguousIterator(pointer ptr);
		inline pointer	_get_pointer(void) const;
	};

	template <typename T>
	class const_ContiguousIterator : public ContiguousIterator<const T>
	{
	};

	template <typename T>
	class ReverseContiguousIterator : public ContiguousIterator<T>
	{
	public:
		typedef ReverseContiguousIterator								iterator;
		typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator>::value_type			value_type;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef typename iterator_traits<iterator>::pointer				pointer;
		typedef typename iterator_traits<iterator>::reference			reference;

	public:
		ReverseContiguousIterator();
		ReverseContiguousIterator(const iterator& other);
		~ReverseContiguousIterator();

		iterator			operator + (const difference_type N) const;
		iterator			operator - (const difference_type N) const;
		iterator			operator ++ (void);
		const iterator		operator ++ (int);
		iterator			operator -- (void);
		const iterator		operator -- (int);
		iterator			operator += (const difference_type N);
		iterator			operator -= (const difference_type N);
	};

	template <typename T>
	class const_ReverseContiguousIterator : public ReverseContiguousIterator<const T>
	{
	};
}

#include "ContiguousIterator.tpp"

#endif // FORWARD_ITERATOR_TPP
