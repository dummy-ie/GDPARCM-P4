struct GS_INPUT
{
    float4 pos : SV_POSITION;
    float2 texcoord : TEXCOORD;
    float3 color : COLOR;
    //float3 color1 : COLOR1;
    // float fogFactor : FOG;
};

struct GS_OUTPUT
{
    float4 pos : SV_POSITION;
    float2 texcoord : TEXCOORD;
    float3 color : COLOR;
    //float3 color1 : COLOR1;
    // float fogFactor : FOG;
};

cbuffer constant : register(b0)
{
    row_major float4x4 world;
    row_major float4x4 view;
    row_major float4x4 proj;
    float3 cameraPos;
    float time;
};

[maxvertexcount(16)]
void main(triangle GS_INPUT input[3], inout TriangleStream<GS_OUTPUT> outputStream)
{
    for (int i = 0; i < 3; ++i)
    {
        GS_OUTPUT output;
        // output.fogFactor = input[i].fogFactor;
        output.pos = input[i].pos;
        output.texcoord = input[i].texcoord;
        output.color = input[i].color;
        //output.color1 = input[i].color1;

        outputStream.Append(output);
    }

    outputStream.RestartStrip();

    // const float4 positions[4] =
    // {
    //     float4(-0.10f, 0.10f, 0.0f, 0.0f),
    //     float4(0.10f, 0.10f, 0.0f, 0.0f),
    //     float4(-0.10f, -0.10f, 0.0f, 0.0f),
    //     float4(0.10f, -0.10f, 0.0f, 0.0f),
    // };
    //
    // for (int i = 0; i < 3; i++)
    // {
    //     // int next = (i + 1) % 3;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         GS_OUTPUT output;
    //         output.pos = input[i].pos + positions[j];
    //         output.color = input[i].color;
    //         output.color1 = input[i].color1;
    //
    //         outputStream.Append(output);
    //     }
    //
    //     outputStream.RestartStrip();
    // }
    
}