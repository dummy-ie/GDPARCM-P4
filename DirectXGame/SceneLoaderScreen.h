#pragma once
#include <mutex>

#include "Prerequisites.h"
#include "UIScreen.h"

class ModelClient;

namespace gdeng03
{
	class SceneLoaderScreen : public UIScreen
	{
	public:
		SceneLoaderScreen();
		~SceneLoaderScreen();

	private:
		friend class UIManager;
		std::mutex* coutMutex;

	private:
		virtual void draw() override;

		ModelClient* client0 = nullptr;
		ModelClient* client1 = nullptr;
		ModelClient* client2 = nullptr;
		ModelClient* client3 = nullptr;
		ModelClient* client4 = nullptr;

		TexturePtr scene1Tex;
		TexturePtr scene2Tex;
		TexturePtr scene3Tex;
		TexturePtr scene4Tex;
		TexturePtr scene5Tex;
	};
}
