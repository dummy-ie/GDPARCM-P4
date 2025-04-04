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
		std::mutex* readMutex;

	private:
		virtual void draw() override;

		ModelClient* client0;
		ModelClient* client1;
		ModelClient* client2;
		ModelClient* client3;
		ModelClient* client4;
	};
}
