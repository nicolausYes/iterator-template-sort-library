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
		std::default_random_engine generator;
		_data.resize( dataSize );
		std::generate( _data.begin(), _data.end(), generator );
		std::random_shuffle( _data.begin(), _data.end() );	
	}

	bool verify( sort_function sort )
	{
		std::vector< Type > tmpData( _data.size() );
		auto copyToTmpContainer = [&] () { std::copy( _data.begin(), _data.end(), tmpData.begin() ); };

		copyToTmpContainer();
		sort( tmpData.begin(), tmpData.end() );
		if( !std::is_sorted( tmpData.begin(), tmpData.end() ) )
			return false;

		return true;
	}	

private:
	std::vector< int > _data;
};

