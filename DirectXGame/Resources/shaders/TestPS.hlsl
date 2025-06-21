#include "Test.hlsli"

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    float32_t4 uv = input.texcoord; // ← 修正！

    output.color = float4(uv.x, uv.y, 0.0f, 1.0f);
    
    return output;
}