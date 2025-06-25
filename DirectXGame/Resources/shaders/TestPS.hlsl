#include "Test.hlsli"

Texture2D<float32_t> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    
    float32_t2 uv = input.texcoord;
    float32_t2 textureColor = gTexture.Sample(gSampler, uv);
    
   // float32_t4 uv = input.texcoord; // ← 修正！

    output.color = float4(uv.x, uv.y, 0.0f, 1.0f);
    
    return output;
}