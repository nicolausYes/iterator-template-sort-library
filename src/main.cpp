#include <iostream>

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "MergeSortBottomUp.h"
#include "QuickSort.h"

#include "VerifySort.h"
#include "Benchmark.h"

int main()
{
	// Test sortings on correctness
	const long dataSize = 10000;
	VerifySort sortVerifier( dataSize );
	
	std::cout << "Testing sortings on correctness" << std::endl << std::endl;
	std::cout << "BubbleSort... " << ( sortVerifier.verify( sortings::BubbleSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "SelectionSort... " << ( sortVerifier.verify( sortings::SelectionSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "InsertionSort... " << ( sortVerifier.verify( sortings::InsertionSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "ShellSort... " << ( sortVerifier.verify( sortings::ShellSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "MergeSort... " << ( sortVerifier.verify( sortings::MergeSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "MergeSortBottomUp... " << ( sortVerifier.verify( sortings::MergeSortBottomUp::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << "QuickSort... " << ( sortVerifier.verify( sortings::QuickSort::sort ) ? "OK" : "FAILED" ) << std::endl;
	std::cout << std::endl << std::endl;
	
	// Test sort time
	const long sortsCount = 10;

	std::cout << "Benchmark sort time. Data size = " << dataSize << ". Sorts count = " << sortsCount << ". Average time in milliseconds:" << std::endl << std::endl;
	std::cout << "BubbleSort = " << Benchmark::benchmark( sortings::BubbleSort::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "SelectionSort = " << Benchmark::benchmark( sortings::SelectionSort::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "InsertionSort = " << Benchmark::benchmark( sortings::InsertionSort::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "ShellSort = " << Benchmark::benchmark( sortings::ShellSort::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "MergeSort = " << Benchmark::benchmark( sortings::MergeSort::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "MergeSortBottomUp = " << Benchmark::benchmark( sortings::MergeSortBottomUp::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "QuickSort = " << Benchmark::benchmark( sortings::QuickSort::sort, dataSize, sortsCount ) << "ms" << std::endl;

	std::cout << "std::sort = " << Benchmark::benchmark( std::sort, dataSize, sortsCount ) << "ms" << std::endl;
	std::cout << "std::stable_sort = " << Benchmark::benchmark( std::stable_sort, dataSize, sortsCount ) << "ms" << std::endl;

	return 0;
}