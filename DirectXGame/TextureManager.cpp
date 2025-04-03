#include "TextureManager.h"
#include <filesystem>
#include "Texture.h"

namespace gdeng03
{
	TexturePtr TextureManager::createTextureFromFile(const wchar_t* filePath)
	{
		return std::static_pointer_cast<Texture>(createResourceFromFile(filePath));
	}

	void TextureManager::loadBlankTexture(TexturePtr& texture)
	{
		texture.reset();
		texture = createTextureFromFile(L"assets/images/default_square.png");
	}

	TexturePtr TextureManager::getBlankTexture()
	{
		return createTextureFromFile(L"assets/images/default_square.png");
	}

	Resource* TextureManager::createResourceFromFileConcrete(const wchar_t* filePath)
	{
		Texture* tex = nullptr;
		try
		{
			tex = new Texture(filePath);
		}
		catch (const std::exception& exc)
		{
			std::cerr << exc.what();
			throw std::exception("Failed to create texture!");
		}

		return tex;
	}
}