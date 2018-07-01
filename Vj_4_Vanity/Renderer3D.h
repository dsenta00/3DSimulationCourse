#pragma once

#include "..\Vanity\Vanity\Library\Engine\Core\Content\RendererBase3D.h"

/*
 * Vanity DirectX Engine namespace
 */
namespace vxe
{
    class Renderer3D : public RendererBase3D
    {
    public:
        Renderer3D(void);

        void CreateDeviceDependentResources(void);
        
        void CreateWindowSizeDependentResources(void);

        void ReleaseDeviceDependentResources(void);

        void Render(void);
    };
}
