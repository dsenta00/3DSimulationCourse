#include "pch.h"
#include "ApplicationFactory.h"

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
    DebugPrint(std::wstring(L"main() called... \n"));

    // Create ApplicationFactory object
    auto factory = ref new ApplicationFactory();

    // Call metod CoreApplication::Run
    Windows::ApplicationModel::Core::CoreApplication::Run(factory);

    return 0;
}