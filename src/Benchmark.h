#pragma once

#include <vector>
#include <random>
#include "Timer.h"

class Benchmark
{
	typedef int Type;
	typedef void (*sort_function)(std::vector<Type>::iterator, std::vector<Type>::iterator);

public:
	static double benchmark( sort_function sort, size_t dataSize, size_t testsCount )
	{
		Timer timer;
		double totalTime = 0;	// total time 
		for( size_t i = 0; i < testsCount; i++ )
		{
			std::default_random_engine generator;
			std::vector< Type > data( dataSize );
			std::generate( data.begin(), data.end(), generator );
			std::random_shuffle( data.begin(), data.end() );	

			timer.start();
			sort( data.begin(), data.end() );
			totalTime += timer.stop();
		}

		return testsCount == 0 ? 0 : totalTime / testsCount;
	}

private:
	Benchmark();
	~Benchmark();
};