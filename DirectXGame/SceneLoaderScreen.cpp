#include "SceneLoaderScreen.h"

#include "GameObjectManager.h"
#include "MathUtil.h"
#include "ModelClient.h"
#include "ImGuiUtil.h"

using namespace gdeng03;

SceneLoaderScreen::SceneLoaderScreen() : UIScreen("SceneLoaderScreen")
{
    this->coutMutex = new std::mutex();
    this->readMutex = new std::mutex();


	LogUtils::log(this, "Initialized");

    ModelClient* client0 = new ModelClient("localhost:50051", "dragon", this->coutMutex, this->readMutex);
    ModelClient* client1 = new ModelClient("localhost:50051", "armadillo", this->coutMutex, this->readMutex);
    ModelClient* client2 = new ModelClient("localhost:50051", "lucy", this->coutMutex, this->readMutex);
    ModelClient* client3 = new ModelClient("localhost:50051", "teapot", this->coutMutex, this->readMutex);
    ModelClient* client4 = new ModelClient("localhost:50051", "bunny", this->coutMutex, this->readMutex);
}

SceneLoaderScreen::~SceneLoaderScreen()
{
}

void SceneLoaderScreen::draw()
{
    ImGui::Begin("Scenes", &isActive);
    
    if (ImGui::Button("Scene 1"))
    {
	    const std::vector<std::string> modelNames = { "armadillo", "lucy", "teapot", "bunny" };

        ModelClient* client0 = new ModelClient("localhost:50051", modelNames, this->coutMutex);
        client0->start();
        //
        // ModelClient* client1 = new ModelClient("localhost:50051", "armadillo", this->coutMutex);
        // client1->start();
        //
        // ModelClient* client2 = new ModelClient("localhost:50051", "lucy", this->coutMutex);
        // client2->start();
        //
        // ModelClient* client3 = new ModelClient("localhost:50051", "teapot", this->coutMutex);
        // client3->start();
        //
        // ModelClient* client4 = new ModelClient("localhost:50051", "bunny", this->coutMutex);
        // client4->start();

    }
    ImGui::SameLine();
    if (ImGui::Button("Scene 2"))
    {

    }
    ImGui::SameLine();
    if (ImGui::Button("Scene 3"))
    {

    }
    ImGui::SameLine();
    if (ImGui::Button("Scene 4"))
    {

    }
    ImGui::SameLine();
    if (ImGui::Button("Scene 5"))
    {

    }
    if (ImGui::Button("View All"))
    {
	    
    }
    const ImU32 col = ImGui::GetColorU32(ImGuiCol_ButtonHovered);
    const ImU32 bg = ImGui::GetColorU32(ImGuiCol_Button);

    this->readMutex->lock();
    float totalFileSize = client0->getFileSize() + client1->getFileSize() + client2->getFileSize() + client3->getFileSize() + client4->getFileSize();
    this->readMutex->unlock();
    //ImGui::BufferingBar("##buffer_bar1", (float)(client0->getTotalBytesReceived() + client1->getTotalBytesReceived() + client2->getTotalBytesReceived() + client3->getTotalBytesReceived() + client4->getTotalBytesReceived()) / totalFileSize, ImVec2(400, 6), bg, col);
    //std::cout << static_cast<float>(client0->getTotalBytesReceived() + client1->getTotalBytesReceived() + client2->getTotalBytesReceived() + client3->getTotalBytesReceived() + client4->getTotalBytesReceived()) / static_cast<float>(client0->getFileSize() + client1->getFileSize() + client2->getFileSize() + client3->getFileSize() + client4->getFileSize()) << "\n";
    std::cout << totalFileSize << "\n";
	ImGui::SameLine();
    ImGui::BufferingBar("##buffer_bar2", 0.7f, ImVec2(400, 6), bg, col);
    ImGui::SameLine();
    ImGui::BufferingBar("##buffer_bar3", 0.7f, ImVec2(400, 6), bg, col);
    ImGui::SameLine();
    ImGui::BufferingBar("##buffer_bar4", 0.7f, ImVec2(400, 6), bg, col);
    ImGui::SameLine();
    ImGui::BufferingBar("##buffer_bar5", 0.7f, ImVec2(400, 6), bg, col);

    ImGui::End();
}