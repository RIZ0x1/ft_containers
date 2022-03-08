#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template<typename Iterator1, typename Iterator2>
	bool lexicographical_compare(Iterator1 start1, Iterator1 end1, Iterator2 start2, Iterator2 end2)
	{
		for (; start1 != end1 && start2 != end2; start1++, start2++)
		{
			if (*start1 < *start2) return (true);
			if (*start1 > *start2) return (false);
		}
		return ((start1 == end1) && (start2 != end2));
	}
}

#endif // LEXICOGRAPHICAL_COMPARE_HPP