#pragma once

#include "Prerequisites.h"
#include "Resource.h"
#include "ResourceManager.h"

namespace gdeng03
{
	class TextureManager final : public ResourceManager
	{
	public:
		TexturePtr createTextureFromFile(const wchar_t* filePath);
		void loadBlankTexture(TexturePtr& texture);
		TexturePtr getBlankTexture();

	protected:
		Resource* createResourceFromFileConcrete(const wchar_t* filePath) override;
	};
}
