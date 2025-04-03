#include "ResourceManager.h"

#include <filesystem>

#if __cplusplus >= 201703L
#include <filesystem>
#endif

namespace gdeng03
{
	ResourcePtr ResourceManager::createResourceFromFile(const wchar_t* filePath)
	{

		if(defaultPath.empty()) defaultPath = std::filesystem::current_path();

		current_path(defaultPath);

#if (_MSC_VER >= 1900 && _MSC_VER <= 1916) || ( _MSC_VER >= 1920 && __cplusplus <= 201402L) 
		const std::wstring fullPath = std::filesystem::absolute(filePath);
#endif
		
#if _MSC_VER >= 1920 && __cplusplus > 201402L 
		std::wstring full_path = std::filesystem::absolute(file_path);
#endif

		if (const auto it = resourceMap.find(fullPath); it != resourceMap.end())
			return it->second;

		std::string str(fullPath.begin(), fullPath.end());
		std::cout << "path is " << str << "\n";
		if (Resource* raw = this->createResourceFromFileConcrete(fullPath.c_str()))
		{
			ResourcePtr res(raw);
			resourceMap[fullPath] = res;
			return res;
		}

		current_path(defaultPath);
		return nullptr;
	}
}
