C++ sorting library
=========================
This library contains the most popular sorting algorithms. Implementation based on templates and iterators.
	
Implemented algorithms
-----
- Bubble sort
- Selection sort
- Insertion sort
- Merge sort (recursive)
- Merge sort bottom-up (not recursive)
- Quicksort (recursive)

It also contains
-----
- Class to verify sorting algorithms on correctness
- Class to benchmark sort time

Both classes supports STL sorting algorithms.

Structure
-----
Every sort algorithm implemented as class with two static template functions, that have the same structure as std::sort in STL:

	template< class RandomAccessIterator >
	static void sort( RandomAccessIterator first, RandomAccessIterator last );
        
	template< class RandomAccessIterator, class Compare >
	static void sort( RandomAccessIterator first, RandomAccessIterator last, Compare comp );
        
Functions sort the elements in the range [first,last) into ascending order.
The elements are compared using std::less for the first version, and comp for the second.


Usage
-------
Just include one of the sort-class files:

	#include "BubbleSort.h"
	#include "SelectionSort.h"
	#include "InsertionSort.h"
	#include "ShellSort.h"
	#include "MergeSort.h"
	#include "MergeSortBottomUp.h"
	#include "QuickSort.h"

And call sort function:

	sortings::QuickSort::sort( data.begin(), data.end() );

You can use it with array:

	int array[] = {2, 4, 1, 5, 3};
	sortings::BubbleSort::sort( array, array + 5 );
	// array: 1 2 3 4 5

Or vector:

	std::vector<int> vec( 5 );
	std::generate( vec.begin(), vec.end(), std::rand ); // fill vector with random data
	sortings::ShellSort::sort( vec.begin(), vec.end() );

With any collection, that provides random access iterator.

You can also provide custom comparer for sort algorithm:

	int array[] = {2, 4, 1, 5, 3};
	sortings::BubbleSort::sort( array, array + 5, [](int& x, int& y){ return x > y; } );
	// array: 5 4 3 2 1

Some theory
-------
Big-O sorting algorithms complexities.

![C++sorting-library](https://dl.dropboxusercontent.com/u/20468014/sort_library/sorts.jpg "C++sorting-library")

Tests
-------
All sort algorithms were benchmarked in order to compare their efficiency with each other and STL sort algorithms.

Benchmark was made on:<br/>

Windows 7 x64<br/>
Intel Core i5 750, 2.67 GHz<br/>
RAM 8Gb, 1033<br/>

It is also need to be mentioned that on RAM 1333 or faster MergeSort performs much better (because of faster copy).

All tests were launched 50-1000 times for every algorithm. Test results (<b>clickable</b>) with avarage time in milliseconds ([link to html version of table](https://dl.dropboxusercontent.com/u/20468014/sort_library/sorts_comp.html)):

![C++sorting-library](https://dl.dropboxusercontent.com/u/20468014/sort_library/sorts_comp.jpg "C++sorting-library")

Battle of the most efficient algorithms on large amounts of data:
![C++sorting-library](https://dl.dropboxusercontent.com/u/20468014/sort_library/sorts_eff.jpg "C++sorting-library")

As you see, implemented algorithms performs better than STL analogs on large amounts of data.

You can build your own graphics based on data from benchmark ([Google docs spreadsheet](https://docs.google.com/spreadsheet/ccc?key=0Auj_SifTMGXodDJ2S0tiYW5qMTdKNXVLR2FQWExMSGc#gid=0)).

Credits
-------

Author: [Nikolay Yesypenko](https://github.com/nicolausYes)<br/>
You can feel free to contact me: nicolausYes@gmail.com

The code in this project is licensed under the CC Attribution — Share Alike.
<br />
Copyright (c) 2013 nicolausYes
