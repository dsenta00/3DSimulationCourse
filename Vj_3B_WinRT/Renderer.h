#pragma once

#include "pch.h"
#include "Timer.h"

#include <chrono>
#include <random>
#include <thread>

class Renderer
{
private:
    // Random generator and distribution
    std::default_random_engine _generator;
    std::uniform_int_distribution<int> _distribution{ 50, 150 };

    // Rendering (sleeping) time
    int _renderingTime;

    int _frameCount;
    float _elapsedTime;

public:
    /*
     * Default constructor
     * Sets _renderingTime to a random number in the
     * scope 50-150
     */
    Renderer(void)
        : _renderingTime{ 0 }, _frameCount{ 0 },
          _elapsedTime{ 0 }
    {
        _renderingTime = _distribution(_generator);
    }

    /*
     * Render simulating function
     * Sleeps for _renderingTime milliseconds
     */
    void Render(void)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(_renderingTime));
    }

    /*
     * Calculate FPS (Frames Per Second), average duration
     * of a frame and total running time, and display that
     * data in the debug output window
     */
    void CalculateStatistics(Timer& timer)
    {
        _elapsedTime += timer.GetElapsedTime();
        _frameCount++;

        if (_elapsedTime > 1.0f)
        {
            float fps{ (float)_frameCount / _elapsedTime };
            float msPerFrame{ 1000.0f / fps };
            float totalTime{ timer.GetTotalTime() };

            _frameCount = 0;
            _elapsedTime = 0.0f;

            DebugPrint(std::wstring(L"CalculateStatistics() called...\n"));
            DebugPrint(std::wstring(L"Frames per second: " + std::to_wstring(fps) + L"\n"));
            DebugPrint(std::wstring(L"Average frame time: " + std::to_wstring(msPerFrame) + L"\n"));
            DebugPrint(std::wstring(L"Total time: " + std::to_wstring(totalTime) + L"\n"));
        }
    }
};
