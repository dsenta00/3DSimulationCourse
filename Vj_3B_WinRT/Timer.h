#pragma once

#include "pch.h"
#include <Windows.h>

class Timer
{
private:
    // Period of the signal
    double _period;

    // Time between 2 ticks
    double _elapsed;

    // Number of ticks at the beginning
    __int64 _base;

    // Number of ticks when counting is stopped
    __int64 _stop;

    // Accumulated number of ticks in paused state
    __int64 _paused;

    // Current tick count
    __int64 _current;

    // Previous ticks count
    __int64 _last;

    // Pausing state denoter
    bool _pausing;

public:

    /*
     * Default constructor
     */
    Timer(void)
        : _elapsed{ -1.0   },
          _base{     0     },
          _stop{     0     },
          _paused{   0     },
          _current{  0     },
          _last{     0     },
          _pausing{  false }
    {
        __int64 frequency{ 0 };
        QueryPerformanceFrequency((LARGE_INTEGER*) &frequency);

        _period = 1.0 / (double) frequency;
    }

    /*
     * Start tick counting
     */
    void Reset(void)
    {
        __int64 now{ 0 };
        QueryPerformanceCounter((LARGE_INTEGER*) &now);

        _base = _last = now;
        _stop = 0;

        _pausing = false;
    }

    /*
     * Pause time ticking
     */
    void Pause(void)
    {
        if (!_pausing)
        {
            __int64 now{ 0 };
            QueryPerformanceCounter((LARGE_INTEGER*) &now);

            _stop = now;

            _pausing = true;
        }
    }
    
    /*
     * Resume (continue) tick counting
     */
    void Resume(void)
    {
        if (_pausing)
        {
            __int64 now{ 0 };
            QueryPerformanceCounter((LARGE_INTEGER*) &now);

            _current = now;
            _paused += _current - _stop;

            _pausing = false;
        }
    }

    /*
     * Count the time between 2 last ticks
     * (Current and last)
     */
    void Tick(void)
    {
        if (!_pausing)
        {
            __int64 now{ 0 };
            QueryPerformanceCounter((LARGE_INTEGER*) &now);
            
            _last = _current;
            _current = now;

            _elapsed = (double) (_current - _last);
        }
    }

    /*
     * Returns the time between the last 2 ticks
     */
    float GetElapsedTime(void)
    {
        return (float) (_elapsed * _period);
    }
    
    /*
     * Return the time passed since the beginning
     */
    float GetTotalTime(void)
    {
        __int64 count;

        if (_pausing)
            count = _stop;
        else
            count = _current;

        return (float) ((count - _base - _paused) * _period);
    }
};
