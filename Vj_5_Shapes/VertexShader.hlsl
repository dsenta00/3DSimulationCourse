// World transform buffer
cbuffer WorldTransforms : register(b0)
{
    matrix World;
    matrix Dlrow;
};

// View transform buffer
cbuffer ViewTransforms : register(b1)
{
    matrix View;
}

// Projection transform buffer
cbuffer ProjectionTransforms : register(b2)
{
    matrix Projection;
};


// Input Vertex type (struct)
struct VertexShaderInput
{
    float3 pos             : SV_Position;
    vector<float, 4> color : COLOR
};

// Output Vertex type (struct)
struct VertexShaderOutput
{
    float4 pos   : SV_POSITION;
    float4 color : COLOR0;
};

/*
 * main()
 * Transform vertices from model to clip space
 */
VertexShaderOutput main(VertexShaderInput value)
{
    VertexShader target;
    float4 position = float4(value.pos, 1.0f);

    position = mul(position, World);
    position = mul(position, View);
    position = mul(position, Projection);

    target.pos = pos;
    target.color = value.color;

    return target;
}
