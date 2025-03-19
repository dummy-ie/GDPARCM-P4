#include "LogUtils.h"

#include "UIManager.h"
#include "DebugScreen.h"

using namespace gdeng03;

void LogUtils::logToConsole(const std::string& message)
{
	UIManager* UIManager = UIManager::get();
	if (UIManager == nullptr) return;

	DebugScreen* debugScreen = dynamic_cast<DebugScreen*>(UIManager->getScreen("DebugScreen").get());
	if (debugScreen == nullptr) return;

	debugScreen->logToConsole(message);
}
