#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef> // ? <ptrdiff_t>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Category, typename T, typename Distance = std::ptrdiff_t,
	typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef typename iterator<Category, T, Distance, Pointer, Reference>::Category	iterator_category;
		typedef typename iterator<Category, T, Distance, Pointer, Reference>::T			value_type;
		typedef typename iterator<Category, T, Distance, Pointer, Reference>::Distance	difference_type;
		typedef typename iterator<Category, T, Distance, Pointer, Reference>::Pointer	pointer;
		typedef typename iterator<Category, T, Distance, Pointer, Reference>::Reference	reference;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};
}

#endif // ITERATOR_HPP
