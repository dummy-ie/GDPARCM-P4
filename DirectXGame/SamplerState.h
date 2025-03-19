#pragma once
#include <d3d11.h>
#include <Windows.h>
#include "Prerequisites.h"

namespace gdeng03
{
	class SamplerState
	{
	public:
		SamplerState(RenderSystem* system);
		~SamplerState();
	private:
		UINT m_size_vertex;
		UINT m_size_list;
	private:
		ID3D11SamplerState* samplerState;
		RenderSystem* m_system = nullptr;
	private:
		friend class DeviceContext;
	};
}