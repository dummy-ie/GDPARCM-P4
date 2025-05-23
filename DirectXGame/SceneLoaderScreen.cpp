#include "SceneLoaderScreen.h"

#include "GameObjectManager.h"
#include "MathUtil.h"
#include "ModelClient.h"
#include "ImGuiUtil.h"
#include "Texture.h"
#include "ViewportManager.h"

using namespace gdeng03;

SceneLoaderScreen::SceneLoaderScreen() : UIScreen("SceneLoaderScreen")
{
	this->coutMutex = new std::mutex();

	LogUtils::log(this, "Initialized");

	const std::vector<std::string> modelNames0 = { "armadillo", "lucy", "teapot", "bunny", "dragon" };
	const std::vector<std::string> modelNames1 = { "airplane", "skull", "notebook", "skyscraper", "slot_machine" };
	const std::vector<std::string> modelNames2 = { "sportsCar", "alfa147", "whiteOak", "diamond", "violin_case" };
	const std::vector<std::string> modelNames3 = { "gourd", "humanoid_quad", "icosahedron", "lamp", "magnolia" };
	const std::vector<std::string> modelNames4 = { "mercedes", "pine", "power_lines", "sandal", "shuttle" };

	this->client0 = new ModelClient("localhost:50051", modelNames0, this->coutMutex);
	this->client1 = new ModelClient("localhost:50051", modelNames1, this->coutMutex);
	this->client2 = new ModelClient("localhost:50051", modelNames2, this->coutMutex);
	this->client3 = new ModelClient("localhost:50051", modelNames3, this->coutMutex);
	this->client4 = new ModelClient("localhost:50051", modelNames4, this->coutMutex);

	this->scene1Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/scene 0.png");
	this->scene2Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/scene 1.png");
	this->scene3Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/scene 2.png");
	this->scene4Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/scene 3.png");
	this->scene5Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/scene 4.png");

	LogUtils::log(this, "Initialized");
}

SceneLoaderScreen::~SceneLoaderScreen()
{
}

void SceneLoaderScreen::draw()
{
	ImGui::Begin("Scenes");

	constexpr ImVec2 imageSize = { 100, 100 };
	if (ImGui::Button("Close##Scene 1 Close", ImVec2(108, 0)))
	{
		this->client0->deleteModels();
	}
	ImGui::SameLine();
	if (ImGui::Button("Close##Scene 2 Close", ImVec2(108, 0)))
	{
		this->client1->deleteModels();
	}
	ImGui::SameLine();
	if (ImGui::Button("Close##Scene 3 Close", ImVec2(108, 0)))
	{
		this->client2->deleteModels();
	}
	ImGui::SameLine();
	if (ImGui::Button("Close##Scene 4 Close", ImVec2(108, 0)))
	{
		this->client3->deleteModels();
	}
	ImGui::SameLine();
	if (ImGui::Button("Close##Scene 5 Close", ImVec2(108, 0)))
	{
		this->client4->deleteModels();
	}

    if (ImGui::ImageButton("Scene 1", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene1Tex->getShaderResourceView())), imageSize))
    {
        this->client0->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 2", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene2Tex->getShaderResourceView())), imageSize))
    {
        this->client1->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 3", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene3Tex->getShaderResourceView())), imageSize))
    {
        this->client2->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 4", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene4Tex->getShaderResourceView())), imageSize))
    {
        this->client3->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 5", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene5Tex->getShaderResourceView())), imageSize))
    {
        this->client4->start();
    }

    bool isSceneEmpty = !(this->client0->isFinished() || this->client1->isFinished() ||
						 this->client2->isFinished() || this->client3->isFinished() || this->client4->isFinished());

	bool isLoading = this->client0->isLoading() || this->client1->isLoading() ||
					 this->client2->isLoading() || this->client3->isLoading() || this->client4->isLoading();

    ViewportManager::get()->getViewports()[0]->setIsSceneEmpty(isSceneEmpty && isLoading);

    const ImU32 col = ImGui::GetColorU32(ImGuiCol_ButtonHovered);
    const ImU32 bg = ImGui::GetColorU32(ImGuiCol_Button);

	ImGui::BufferingBar("##buffer_bar1", static_cast<float>(this->client0->getTotalBytesReceived()) / static_cast<float>(this->client0->getFileSize()), ImVec2(116, 6), bg, col);
	ImGui::SameLine();
	ImGui::BufferingBar("##buffer_bar2", static_cast<float>(this->client1->getTotalBytesReceived()) / static_cast<float>(this->client1->getFileSize()), ImVec2(116, 6), bg, col);
	ImGui::SameLine();
	ImGui::BufferingBar("##buffer_bar3", static_cast<float>(this->client2->getTotalBytesReceived()) / static_cast<float>(this->client2->getFileSize()), ImVec2(116, 6), bg, col);
	ImGui::SameLine();
	ImGui::BufferingBar("##buffer_bar4", static_cast<float>(this->client3->getTotalBytesReceived()) / static_cast<float>(this->client3->getFileSize()), ImVec2(116, 6), bg, col);
	ImGui::SameLine();
	ImGui::BufferingBar("##buffer_bar5", static_cast<float>(this->client4->getTotalBytesReceived()) / static_cast<float>(this->client4->getFileSize()), ImVec2(116, 6), bg, col);

	if (ImGui::Button("View All"))
	{
		this->client0->start();
		this->client1->start();
		this->client2->start();
		this->client3->start();
		this->client4->start();
	}

	ImGui::End();
}