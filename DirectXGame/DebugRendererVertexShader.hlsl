struct VS_INPUT
{
    float4 pos : POSITION;
    float3 color : COLOR;
    //float3 color1 : COLOR1;
};

struct VS_OUTPUT
{
    float4 pos : SV_POSITION;
    float3 color : COLOR;
    // float3 directionToCamera : TEXCOORD1;
    // float fogFactor : FOG;
};

cbuffer constant : register(b0)
{
    row_major float4x4 world;
    // row_major float4x4 view;
    // row_major float4x4 proj;
    float3 cameraPos;
    float time;

    float3 color;         // albedo color
    float metallic;       // metallic strength
    float smoothness;     // specular strength
    float flatness;       // normal flatness
    float2 tiling;        // texture tiling
    float2 offset;        // texture offset

    float hasAlbedoMap;
    float hasNormalMap;
    float hasMetallicMap;
    float hasSmoothnessMap;
};

cbuffer camera : register(b1)
{
    row_major float4x4 view;
    row_major float4x4 proj;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output = (VS_OUTPUT) 0;
    // input.pos.w = 1.0f;

    //output.pos = lerp(input.pos, input.pos1, (sin(m_angle) + 1.0f) / 2.0f);

    // World Space
    output.pos = mul(input.pos, world);
    // Calculate linear fog    
    // output.fogFactor = getFogFactor(distance(cameraPos, output.pos));
    // output.directionToCamera = normalize(cameraPos - output.pos);
 
	// View Space
    output.pos = mul(output.pos, view);
 
    // Screen Space
    output.pos = mul(output.pos, proj);

    // output.pos = input.pos;

    output.color = input.color;
    //output.color1 = input.color1;

    return output;
}

/* This is the required means to set shader resources. Conduct this WITHIN the rendering code.
deviceContext->PSSetShaderResources(0, 1, &albedoTexture);
deviceContext->PSSetShaderResources(1, 1, &normalTexture);
deviceContext->PSSetShaderResources(2, 1, &metallicTexture);
deviceContext->PSSetShaderResources(3, 1, &smoothnessTexture);
deviceContext->PSSetSamplers(0, 1, &samplerState);
*/