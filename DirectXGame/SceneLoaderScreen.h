#pragma once
#include <mutex>

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
	};
}
