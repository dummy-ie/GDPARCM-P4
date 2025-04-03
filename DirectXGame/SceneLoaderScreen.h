#pragma once
#include <mutex>

#include "UIScreen.h"

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
	};
}