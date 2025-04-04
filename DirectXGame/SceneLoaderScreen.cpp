#include "SceneLoaderScreen.h"

#include "GameObjectManager.h"
#include "MathUtil.h"
#include "ModelClient.h"

using namespace gdeng03;

SceneLoaderScreen::SceneLoaderScreen() : UIScreen("SceneLoaderScreen")
{
    this->coutMutex = new std::mutex();
	LogUtils::log(this, "Initialized");
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

    ImGui::End();
}