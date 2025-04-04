#include "SceneLoaderScreen.h"

#include "GameObjectManager.h"
#include "MathUtil.h"
#include "ModelClient.h"
#include "ImGuiUtil.h"
#include "Texture.h"

using namespace gdeng03;

SceneLoaderScreen::SceneLoaderScreen() : UIScreen("SceneLoaderScreen")
{
    this->coutMutex = new std::mutex();

	LogUtils::log(this, "Initialized");

    const std::vector<std::string> modelNames = { "armadillo", "lucy", "teapot", "bunny" };

    this->client0 = new ModelClient("localhost:50051", modelNames, this->coutMutex);
    this->client1 = new ModelClient("localhost:50051", modelNames, this->coutMutex);
    this->client2 = new ModelClient("localhost:50051", modelNames, this->coutMutex);
    this->client3 = new ModelClient("localhost:50051", modelNames, this->coutMutex);
    this->client4 = new ModelClient("localhost:50051", modelNames, this->coutMutex);

    this->scene1Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/default_square.png");
    this->scene2Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/default_square.png");
    this->scene3Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/default_square.png");
    this->scene4Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/default_square.png");
    this->scene5Tex = GraphicsEngine::get()->getTextureManager()->createTextureFromFile(L"assets/images/default_square.png");

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
    if (ImGui::ImageButton("Scene 3", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene1Tex->getShaderResourceView())), imageSize))
    {
        this->client2->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 4", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene1Tex->getShaderResourceView())), imageSize))
    {
        this->client3->start();
    }
    ImGui::SameLine();
    if (ImGui::ImageButton("Scene 5", static_cast<ImTextureID>(reinterpret_cast<intptr_t>(this->scene1Tex->getShaderResourceView())), imageSize))
    {
        this->client4->start();
    }
    
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