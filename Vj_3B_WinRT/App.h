#pragma once

#include "pch.h"
#include "Renderer.h"
#include "Timer.h"

#include <string>

ref class App : Windows::ApplicationModel::Core::IFrameworkView
{
private:
    Platform::Agile<Windows::UI::Core::CoreWindow> _window;

    bool _windowClosed;
    bool _windowVisible;

internal:
    App(void);

public:
    /* Inherited methods */
    virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView ^applicationView);

    virtual void SetWindow(Windows::UI::Core::CoreWindow ^window);

    virtual void Load(Platform::String ^entryPoint);

    virtual void Run(void);

    virtual void Uninitialize(void);

    /* Application lifecycle methods */
    void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^,
                     Windows::ApplicationModel::Activation::IActivatedEventArgs^);

    void OnSuspending(Platform::Object^, Windows::ApplicationModel::SuspendingEventArgs^);

    void OnResuming(Platform::Object^, Platform::Object^);

    /* Event Handlers */
    void OnKeyDown(Windows::UI::Core::CoreWindow^, Windows::UI::Core::KeyEventArgs^);

    void OnPointerPressed(Windows::UI::Core::CoreWindow^, Windows::UI::Core::PointerEventArgs^);
};