#pragma once

#include <algorithm>    // std::swap

namespace sortings
{
	class InsertionSort
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
			for( auto i = first; i != last; i++ )
			{
				for( auto j = i; j != first; j-- )
				{
					if( comp( *j, *(j-1) ) )
						 std::swap( *j, *(j-1) );
					 else
						 break;
				}
			}
		}

	private:
		InsertionSort(void);
		~InsertionSort(void);
	};
}