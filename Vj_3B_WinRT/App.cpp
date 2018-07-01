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
void App::Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView)
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
 * Set application window and register display-related data
 * Also, register Key and Pointer press events
 */
void App::SetWindow(Windows::UI::Core::CoreWindow^ window)
{
    DebugPrint(std::wstring(L"App::SetWindow() called... \n"));

    

    // Register OnKeyDown event handler
    window->KeyDown += ref new Windows::Foundation::TypedEventHandler
        <Windows::UI::Core::CoreWindow^, 
         Windows::UI::Core::KeyEventArgs^>
        (this, &App::OnKeyDown);

    // Register OnPointerPressed event handler
    window->PointerPressed += ref new Windows::Foundation::TypedEventHandler
        <Windows::UI::Core::CoreWindow^,
        Windows::UI::Core::PointerEventArgs^>
        (this, &App::OnPointerPressed);

    _window = window;
}

/*
 * Load application data
 */
void App::Load(Platform::String^ entryPoint)
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

    Timer timer;
    Renderer render;

    timer.Reset();
    timer.Pause();

    while (!_windowClosed)
    {
        if (_windowVisible)
        {
            dispatcher->ProcessEvents(Windows::UI::Core
                                      ::CoreProcessEventsOption
                                      ::ProcessAllIfPresent);

            timer.Resume();
            render.Render();
            timer.Tick();
            timer.Pause();
            render.CalculateStatistics(timer);
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

    _windowVisible = true;
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

    _windowVisible = false;
}

/*
 * Resume the execution of the application
 * Called when the user switches back to the app 
 */
void App::OnResuming(Platform::Object^, Platform::Object^)
{
    DebugPrint(std::wstring(L"App::OnResuming() called... \n"));

    _windowVisible = true;
}

/*
 * Function that handles key (down) press events
 */
void App::OnKeyDown(Windows::UI::Core::CoreWindow^ sender,
                    Windows::UI::Core::KeyEventArgs^ args)
{
    Platform::String^ text{ args->VirtualKey.ToString() };

    Windows::UI::Popups::MessageDialog dialog(text, "Key Pressed!");
    dialog.ShowAsync();
}

/*
 * Function that handles pointer (mouse) press events
 */
void App::OnPointerPressed(Windows::UI::Core::CoreWindow^ sender,
                           Windows::UI::Core::PointerEventArgs^ args)
{
    float x{ args->CurrentPoint->Position.X };
    float y{ args->CurrentPoint->Position.Y };

    Platform::String^ text{ x + " x " + y };

    Windows::UI::Popups::MessageDialog dialog(text, "Pointer Pressed!");
    dialog.ShowAsync();
}
