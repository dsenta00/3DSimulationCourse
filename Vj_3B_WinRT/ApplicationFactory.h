#pragma once

#include "pch.h"
#include "App.h"


ref class ApplicationFactory : public Windows::ApplicationModel::Core::IFrameworkViewSource
{
internal:
    App ^_application;
    
    /*
    * Default constructor
    */
    ApplicationFactory(void)
    {
        DebugPrint(std::wstring(L"ApplicationFactory::ApplicationFactory() called... \n"));
    }

public:

    /*
     * Destructor
     */
    virtual ~ApplicationFactory(void)
    {
        DebugPrint(std::wstring(L"ApplicationFactory::~ApplicationFactory() called... \n"));
    }

    /*
     * Create a new view
     * (Allocate _application object)
     */
    virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView(void)
    {
        DebugPrint(std::wstring(L"ApplicationFactory::CreateView() called... \n"));

        _application = ref new App();

        return _application;
    }

};
