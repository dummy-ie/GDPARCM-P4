﻿#pragma once
#include <d3d11.h>

#include "Prerequisites.h"
#include "GraphicsResource.h"

namespace gdeng03
{
	class ConstantBuffer final : public GraphicsResource
	{
	public:
		ConstantBuffer(const void* buffer, UINT sizeBuffer, RenderSystem* system);
		~ConstantBuffer() override;
		ConstantBuffer(const ConstantBuffer& obj) = default;
		ConstantBuffer(ConstantBuffer&& other) noexcept = default;
		ConstantBuffer& operator=(const ConstantBuffer& other) = default;
		ConstantBuffer& operator=(ConstantBuffer&& other) noexcept = default;

		void update(const DeviceContextPtr& context, const void* buffer) const;

	private:
		ID3D11Buffer* constantBuffer;

		friend class DeviceContext;
	};
}

