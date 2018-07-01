#pragma once

#include <wrl.h>
#include <wrl/client.h>
#include <dxgi1_4.h>
#include <d3d11_3.h>
#include <d2d1_3.h>
#include <d2d1effects_2.h>
#include <dwrite_3.h>
#include <wincodec.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <concrt.h>

#include <string>
#include <wrl.h>

#if defined (_DEBUG)

/*
 * Output strings to the debug window
 * (when running in debugging mode)
 * 
 * Useful for following method calls during
 * app lifecycle
 */
inline void DebugPrint(void)
{
}

template<typename T, typename... Tail>
inline void DebugPrint(T& text, Tail... tail)
{
    OutputDebugStringW(text.c_str());

    DebugPrint(tail...);
}
#else
#define DebugPrint(x);
#endif