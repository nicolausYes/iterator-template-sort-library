#pragma once

#include <algorithm>    // std::swap
#include <vector>

namespace sortings
{
	class MergeSortBottomUp
	{
	public:
		template< class RandomAccessIterator >
		static void sort( RandomAccessIterator first, RandomAccessIterator last )
		{
			sort( first, last, std::less< std::iterator_traits<RandomAccessIterator>::value_type >() );
		}

		template< class RandomAccessIterator, class Compare >
		static void sort( RandomAccessIterator first, RandomAccessIterator last, Compare comp )
		{
			auto size = last - first;
			std::vector< std::iterator_traits<RandomAccessIterator>::value_type > data( size );

			for( auto sz = 1; sz < size; sz += sz )
				for( auto lo = 0; lo < size - sz; lo += sz+sz )
					merge( first, last, data.begin(), lo, lo+sz - 1, std::min(lo+sz+sz-1, size-1), comp );
		}

	private:

		template< class RandomAccessIterator, class Compare >
		static void merge( RandomAccessIterator first, RandomAccessIterator last,
			RandomAccessIterator firstCopy, long lo, long mid, long hi, Compare& comp)
		{
			// perform a copy
			std::copy( first + lo, first + hi, firstCopy + lo );

			// perform merge
			auto i = lo, j = mid + 1;
			for( auto k = lo; k != (hi + 1); k++ )
			{
				if		( i > mid )								first[k] = firstCopy[j++];
				else if	( j > hi )								first[k] = firstCopy[i++];
				else if ( comp( firstCopy[j], firstCopy[i] ) )	first[k] = firstCopy[j++];
				else											first[k] = firstCopy[i++];
			}
		}

	private:
		MergeSortBottomUp(void);
		~MergeSortBottomUp(void);
	};
}