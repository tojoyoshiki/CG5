struct VertexShaderOutPut
{
    float32_t4 positiion : SV_POSITION;
};

struct VertexShaderInput
{
    float32_t4 position : POSITION0;
};

VertexShaderOutPut main(VertexShaderInput input)
{
    VertexShaderOutPut output;
    output.positiion = input.position;
    return output;
}