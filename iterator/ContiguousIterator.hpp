#ifndef CONTIGUOUS_ITERATOR_HPP
# define CONTIGUOUS_ITERATOR_HPP

#include "iterators_core.hpp"

namespace ft
{
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
		ContiguousIterator(pointer ptr);
		ContiguousIterator(const iterator& other);
		~ContiguousIterator();

		bool						operator == (const iterator &other) const;
		bool						operator != (const iterator &other) const;
		bool						operator < (const iterator &other) const;
		bool						operator > (const iterator &other) const;
		bool						operator <= (const iterator &other) const;
		bool						operator >= (const iterator &other) const;
		reference					operator *	(void) const;
		pointer						operator -> (void) const;
		virtual iterator			operator + (const difference_type N) const;
		virtual iterator			operator - (const difference_type N) const;
		virtual iterator			operator ++ (void);
		virtual const iterator		operator ++ (int);
		virtual iterator			operator -- (void);
		virtual const iterator		operator -- (int);
		virtual iterator			operator += (const difference_type N);
		virtual iterator			operator -= (const difference_type N);

	protected:
		inline pointer	_get_pointer(void) const;
	};

	template <typename T>
	class ConstContiguousIterator : public ContiguousIterator<const T>
	{
	public:
		typedef ConstContiguousIterator<T>						iterator;
		typedef typename iterator_traits<iterator>::pointer		pointer;
	public:
		ConstContiguousIterator() : ContiguousIterator<const T>() {};
		ConstContiguousIterator(pointer ptr) : ContiguousIterator<const T>(ptr) {};
		ConstContiguousIterator(const ConstContiguousIterator& other) : ContiguousIterator<const T>::_ptr(other._get_pointer()) {};
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
		ReverseContiguousIterator(pointer ptr);
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
	class ConstReverseContiguousIterator : public ReverseContiguousIterator<const T>
	{
	public:
		typedef ConstContiguousIterator<T>						iterator;
		typedef typename iterator_traits<iterator>::pointer		pointer;
	public:
		ConstReverseContiguousIterator() : ReverseContiguousIterator<const T>() {};
		ConstReverseContiguousIterator(pointer ptr) : ReverseContiguousIterator<const T>(ptr) {};
		ConstReverseContiguousIterator(const ConstReverseContiguousIterator& other) : ReverseContiguousIterator<const T>::_ptr(other._get_pointer()) {};
	};
}

#include "ContiguousIterator.tpp"

#endif // CONTIGUOUS_ITERATOR_HPP
