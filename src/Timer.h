#pragma once

#include <ctime>

class Timer
{
public:
	void	start();
	double	stop();			// return time in ms
	double	elapsedTime();

private:
	clock_t	_start;
	clock_t	_end;
};

inline void Timer::start()
{
	_start = clock();
}

inline double Timer::stop()
{
	_end = clock();
	return elapsedTime();
}

inline double Timer::elapsedTime()
{
	return difftime( _end, _start );
}
