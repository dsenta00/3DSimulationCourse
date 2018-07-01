#include "pch.h"
#include "App.h"

/*
 * Default constructor
 */
App::App(void)
{
    DebugPrint(std::wstring(L"App::App() called... \n"));
}

/*
 * Register handlers for lifecycle events
 * (Activated, Suspending, Resuming)
 */
void App::Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^applicationView)
{
    DebugPrint(std::wstring(L"App::Initialize() called... \n"));

    applicationView->Activated += ref new Windows::Foundation::TypedEventHandler
        <Windows::ApplicationModel::Core::CoreApplicationView^,
        Windows::ApplicationModel::Activation::IActivatedEventArgs^>
        (this, &App::OnActivated);

    Windows::ApplicationModel::Core::CoreApplication::Suspending +=
        ref new Windows::Foundation::EventHandler
        <Windows::ApplicationModel::SuspendingEventArgs^>
        (this, &App::OnSuspending);

    Windows::ApplicationModel::Core::CoreApplication::Resuming +=
        ref new Windows::Foundation::EventHandler
        <Platform::Object^>
        (this, &App::OnResuming);
}

/*
 * Set application window and registers display-related data
 */
void App::SetWindow(Windows::UI::Core::CoreWindow ^window)
{
    DebugPrint(std::wstring(L"App::SetWindow() called... \n"));

    _window = window;
}

/*
 * Load application data
 */
void App::Load(Platform::String ^entryPoint)
{
    DebugPrint(std::wstring(L"App::Load() called... \n"));
}

/*
 * Run main event loop and process
 * events from queue of associated window
 */
void App::Run(void)
{
    DebugPrint(std::wstring(L"App::Run() called... \n"));

    auto dispatcher = Windows::UI::Core
                    ::CoreWindow::GetForCurrentThread()->Dispatcher;

    while (!_windowClosed)
    {
        if (_windowVisible)
        {
            dispatcher->ProcessEvents(Windows::UI::Core
                                      ::CoreProcessEventsOption
                                      ::ProcessAllIfPresent);
        }
        else
        {
            dispatcher->ProcessEvents(Windows::UI::Core
                                      ::CoreProcessEventsOption
                                      ::ProcessOneAndAllPending);
        }
    }
}

/*
 * Uninitialize application data
 */
void App::Uninitialize(void)
{
    DebugPrint(std::wstring(L"App::Uninitialize() called... \n"));
}

/*
 * Activate the window
 * Present the window on the screen
 * Called when the user opens the app
 */
void App::OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^,
                      Windows::ApplicationModel::Activation::IActivatedEventArgs^)
{
    DebugPrint(std::wstring(L"App::OnActivated() called... \n"));

    Windows::UI::Core::CoreWindow::GetForCurrentThread()->Activate();
}

/*
 * Suspend the application
 * Keep the application in memory, but pause the execution
 * Called when the user switches away from the app
 */
void App::OnSuspending(Platform::Object^,
                       Windows::ApplicationModel::SuspendingEventArgs^)
{
    DebugPrint(std::wstring(L"App::OnSuspending() called... \n"));
}

/*
 * Resume the execution of the application
 * Called when the user switches back to the app 
 */
void App::OnResuming(Platform::Object^, 
                     Platform::Object^)
{
    DebugPrint(std::wstring(L"App::OnResuming() called... \n"));
}
