#include "Timer.hpp"
#include <iostream>
#include <string>

Timer::Timer(void) {}

Timer::Timer(const Timer& other)
{
    _tp = other._tp;
    _start = other._start;
    _stop = other._stop;
}

Timer::~Timer(void) {}

Timer&    Timer::operator=(const Timer& other)
{
    _tp = other._tp;
    _start = other._start;
    _stop = other._stop;

    return (*this);
}

void     Timer::start(void)
{
	gettimeofday(&_tp, NULL);
	_start = _tp.tv_sec * 1000000 + _tp.tv_usec;

    std::cout << "Timer started" << std::endl;
}

void     Timer::stop(void)
{
	gettimeofday(&_tp, NULL);
	_stop = _tp.tv_sec * 1000000 + _tp.tv_usec - _start;

	std::cout << "Timer stopped\n" << _stop << " ms - execution time" << std::endl;
}