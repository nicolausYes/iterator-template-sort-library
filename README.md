This library contains the most popular sorting algorithms. Implementation based on templates and iterators.

Implemented algorithms
-----
- Bubble sort
- Selection sort
- Insertion sort
- Merge sort (recursive)
- Merge sort bottom-up (not recursive)
- (Quicksort will be implemented soon)

It also contains
-----
- Class to verify sorting algorithms on correctness
- Class to benchmark sort time

Structure
-----
Every sort-class contains two functions, that have the same structure as std::sort in STL
        template< class RandomAccessIterator >
        static void sort( RandomAccessIterator first, RandomAccessIterator last );
        
	    template< class RandomAccessIterator, class Compare >
	    static void sort( RandomAccessIterator first, RandomAccessIterator last, Compare comp );
        
Sorts the elements in the range [first,last) into ascending order.
The elements are compared using std::less for the first version, and comp for the second.




Credits
-------

Author: [Nikolay Yesypenko](https://github.com/nicolausYes)

The code in this project is licensed under the Apache Software License 2.0.
<br />
Copyright (c) 2013 nicolausYes
