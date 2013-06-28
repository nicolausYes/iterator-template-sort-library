#pragma once

#include <algorithm>    // std::swap
#include <vector>

namespace sortings
{
	class MergeSort
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
			std::vector< std::iterator_traits<RandomAccessIterator>::value_type > data( last - first );
			sort(first, last, data.begin(), 0, last - first - 1, comp);
		}

	private:

		template< class RandomAccessIterator, class Compare >
		static void sort( RandomAccessIterator first, RandomAccessIterator last, 
			RandomAccessIterator firstCopy, long lo, long hi, Compare& comp )
		{
			if( hi <= lo ) return;
			long mid = lo + ( hi - lo ) / 2;
			sort( first, last, firstCopy, lo, mid, comp );
			sort( first, last, firstCopy, mid + 1, hi, comp );
			merge( first, last, firstCopy, lo, mid, hi, comp );
		}

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
		MergeSort(void);
		~MergeSort(void);
	};
}