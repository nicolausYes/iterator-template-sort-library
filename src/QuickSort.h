#pragma once

#include <algorithm>    // std::swap
#include <iterator>
#include <typeinfo>  

namespace sortings
{
	class QuickSort
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
			//std::random_shuffle( first, last ); // perfectly have to be shuffled before sorting
			sort( first, last, 0, last - first - 1, comp );
		}

	private:

		template< class RandomAccessIterator, class Compare >
		static void sort( RandomAccessIterator first, RandomAccessIterator last, long lo, long hi, Compare& comp )
		{
			if( hi <= lo )
				return;

			auto j = partition(first, lo, hi, comp);
			sort( first, last, lo, j-1, comp );
			sort( first, last, j+1, hi, comp );
		}

		template< class RandomAccessIterator, class Compare >
		static long partition( RandomAccessIterator first, long lo, long hi, Compare& comp )
		{
			
			auto i = lo, j = hi + 1;
			while( true )
			{
				while( comp( first[++i], first[lo] ) )
				{
					if( i == hi )	break;
				}

				while( comp( first[lo], first[--j] ) )
				{
					if( j == lo )	break;
				}

				if( i >= j )
					break;

				std::swap( first[i], first[j] );
			}

			std::swap( first[lo], first[j] );
			return j;
		}

	private:
		QuickSort(void);
		~QuickSort(void);
	};
}