#pragma once

#include <algorithm>    // std::swap

namespace sortings
{
	class ShellSort
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
			auto h = 1;
			while( h < size / 3 ) h = 3 * h + 1;

			while( h >= 1 )
			{
				for( auto i = first + h; i != last; i++ )
				{
					for( auto j = i; (j - first) >= h && comp(*j, *(j-h)); j -= h )
						std::swap( *j, *(j-h) );
				}

				h /= 3;
			}
		}

	private:
		ShellSort(void);
		~ShellSort(void);
	};
}