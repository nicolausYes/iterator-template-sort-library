#pragma once

#include <vector>
#include <random>

class VerifySort
{
private:
	typedef int Type;
	typedef void (*sort_function)(std::vector<Type>::iterator, std::vector<Type>::iterator);

public:

	VerifySort(size_t dataSize)
	{
		_data.resize( dataSize );

		std::default_random_engine generator;
		std::generate( _data.begin(), _data.end(), generator );
		std::random_shuffle( _data.begin(), _data.end() );	
	}

	bool verify( sort_function sort )
	{
		std::vector< Type > tmpData( _data.size() );
		
		std::copy( _data.begin(), _data.end(), tmpData.begin() );
		sort( tmpData.begin(), tmpData.end() );
		return std::is_sorted( tmpData.begin(), tmpData.end() );
	}	

private:
	std::vector< int > _data;
};

