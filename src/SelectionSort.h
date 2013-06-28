#pragma once

#include <algorithm>    // std::swap

namespace sortings
{
	class SelectionSort
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
				auto min = i;
				for( auto j = i + 1; j != last; j++ )
					if( comp( *j, *min ) )
						min = j;
				std::swap( *min, *i );
			}
		}

	private:
		SelectionSort(void);
		~SelectionSort(void);
	};
}