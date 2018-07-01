#include "pch.h"
#include "Renderer3D.h"

#include <string>

#define EXIT_SUCCESS 0

[Platform::MTAThread]
int main(Platform::Array<Platform::String ^>^)
{
    vxe::DebugPrint(std::string("main() started... \n"));

    std::shared_ptr<vxe::RendererBase3D> renderer3D = std::make_shared<vxe::Renderer3D>();

    auto factory = ref new vxe::ApplicationFactory(renderer3D);
    Windows::ApplicationModel::Core::CoreApplication::Run(factory);

    return EXIT_SUCCESS;
}