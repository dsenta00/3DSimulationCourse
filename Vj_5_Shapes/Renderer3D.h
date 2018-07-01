#pragma once

#include "..\Vanity\Vanity\Library\Engine\Core\Content\RendererBase3D.h"

#include "..\Vanity\Vanity\Library\Engine\Third Party\DirectX Tool Kit\VertexTypes.h"
#include "..\Vanity\Vanity\Library\Engine\Pipeline Stages\Shaders\Vertex Shader.h"
#include "..\Vanity\Vanity\Library\Engine\Pipeline Stages\Shaders\Pixel Shader.h"

#include "..\Vanity\Vanity\Library\Engine\Models\Mesh Base.h"

#include "..\Vanity\Vanity\Library\Engine\Scene\Transforms\World Transforms.h"
#include "..\Vanity\Vanity\Library\Engine\Scene\Transforms\View Transform.h"
#include "..\Vanity\Vanity\Library\Engine\Scene\Transforms\Projection Transform.h"

/*
 * Vanity DirectX Engine namespace
 */
namespace vxe
{
    class Renderer3D : public RendererBase3D
    {
    private:
        // Shared pointers to vertex shader and pixel shader
        std::shared_ptr<VertexShader<DirectX::VertexPositionColor>> _vertexShader;
        std::shared_ptr<PixelShader>                                _pixelShader;

        // Shared pointer to model to be rendered
        std::shared_ptr<MeshBase<DirectX::VertexPositionColor, unsigned short>> _model;

        // Shared pointers to world, view and projection transforms
        std::shared_ptr<WorldTransforms>     _world;
        std::shared_ptr<ViewTransform>       _view;
        std::shared_ptr<ProjectionTransform> _projection;

    public:
        Renderer3D(void);

        void CreateDeviceDependentResources(void);
        
        void CreateWindowSizeDependentResources(void);

        void ReleaseDeviceDependentResources(void);

        void Render(void);

        void Rotate(float);

        void SetCamera(void);

        template <typename T, typename U>
        void Draw(std::shared_ptr<MeshBase<T, U>>&,
                  std::shared_ptr<WorldTransforms>&,
                  bool = true);

        void Reset(void);
    };
}
