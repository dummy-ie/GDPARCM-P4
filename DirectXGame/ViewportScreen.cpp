#include "ViewportScreen.h"

#include "imgui.h"

#include "AppWindow.h"
#include "SwapChain.h"
#include "CameraManager.h"
#include "GraphicsEngine.h"
#include "DeviceContext.h"
#include "EngineTime.h"
#include "ImGuiUtil.h"
#include "imgui_internal.h"
#include "InputSystem.h"
#include "ViewportManager.h"

namespace gdeng03
{
	ViewportScreen::ViewportScreen(int index) : UIScreen("Viewport " + std::to_string(index + 1)), index(index)
	{
		this->currentCamera = std::make_shared<SceneCamera>("Scene Camera " + std::to_string(index + 1), false, AppWindow::get()->getClientWindowRect());
		this->currentCamera->setLocalPosition({ 0, 0, -20 });
		this->currentCamera->setProjectionType(this->selectedProj);

		this->ownCamera = this->currentCamera;

		CameraManager::getInstance()->addSceneCamera(this->currentCamera);
		this->renderTexture = std::make_shared<RenderTexture>();

		this->camIndex = index;

		this->selectedCameraIndex = this->camIndex;

		LogUtils::log(this, "Initialized");
		LogUtils::log(name + " Current Cam : " + currentCamera->getUniqueName());
	}

	ViewportScreen::~ViewportScreen()
	{
		CameraManager::getInstance()->removeSceneCamera(this->ownCamera);
		GraphicsEngine::get()->getRenderSystem()->getImmediateDeviceContext()->setRenderTarget(AppWindow::get()->getSwapChain()->getRenderTexture());
	}

	void ViewportScreen::setIsSceneEmpty(bool isSceneEmpty)
	{
		this->isSceneEmpty = isSceneEmpty;
	}

	void ViewportScreen::draw()
	{
		const RenderSystem* renderSystem = GraphicsEngine::get()->getRenderSystem();

		renderSystem->getImmediateDeviceContext()->clearRenderTargetColor(this->renderTexture, 0.3, 0.3, 0.3, 1);

		// Push Style so Window has no padding
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollWithMouse;
		ImGui::Begin(this->name.c_str(), &isActive, windowFlags);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();

		renderSystem->getImmediateDeviceContext()->setViewportSize(viewportPanelSize.x, viewportPanelSize.y);

		this->currentCamera->setWidth(viewportPanelSize.x);
		this->currentCamera->setHeight(viewportPanelSize.y);

		this->handleInput();

		this->currentCamera->update(EngineTime::getDeltaTime());

		if (!ImGui::IsWindowCollapsed() && viewportPanelSize.x > 0 && viewportPanelSize.y > 0)
		{
			this->renderTexture->resizeResources(viewportPanelSize.x, viewportPanelSize.y);
			AppWindow::get()->draw(static_cast<int>(viewportPanelSize.x), static_cast<int>(viewportPanelSize.y), this->currentFillMode);
		}

		// Stores top left position
		const ImVec2 position = ImGui::GetCursorScreenPos();

		viewportPanelSize = ImGui::GetContentRegionAvail();
		ImGui::Image(reinterpret_cast<ImTextureID>(this->renderTexture->getShaderResourceView()), viewportPanelSize);

		// Pop Style so Selectables (Child Windows) don't get affected
		ImGui::PopStyleVar();

		this->drawViewportUI(position);

		if (isSceneEmpty) {
			const ImU32 col = ImGui::GetColorU32(ImGuiCol_ButtonHovered);
			ImGui::SetCursorScreenPos({ viewportPanelSize.x / 2, viewportPanelSize.y / 2});
			ImGui::Spinner("Spinner", 50.0f, 10, col);
		}

		ImGui::End();

		// Reset back to window size so other draw functions won't be broken
		auto [left, top, right, bottom] = AppWindow::get()->getClientWindowRect();
		const FLOAT width = right - left;
		const FLOAT height = bottom - top;

		renderSystem->getImmediateDeviceContext()->setViewportSize(width, height);
		renderSystem->getImmediateDeviceContext()->setRenderTarget(AppWindow::get()->getSwapChain()->getRenderTexture());

		if (!isActive)
			ViewportManager::get()->deleteViewport(this);
	}

	void ViewportScreen::handleInput()
	{
		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();

		if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootWindow))
		{
			if (ImGui::IsMouseClicked(ImGuiMouseButton_Right))
			{
				InputSystem::get()->addListener(this->currentCamera.get());
				this->currentCamera->setPossessed(true);
				if (!ImGui::IsMouseHoveringRect(ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x + viewportPanelSize.x, ImGui::GetWindowPos().y + viewportPanelSize.y)))
				{
					InputSystem::get()->removeListener(this->currentCamera.get());
					this->currentCamera->setPossessed(false);
					ImGui::FocusWindow(nullptr);

					// Floating Close button with a margin
					if (ImGui::Button("Close", ImVec2(100, 0)))
					{
						isActive = false;
					}
				}
			}
			if (ImGui::IsMouseReleased(ImGuiMouseButton_Right))
			{
				InputSystem::get()->removeListener(this->currentCamera.get());
				this->currentCamera->setPossessed(false);
			}
		}
	}

	void ViewportScreen::drawViewportUI(ImVec2 position)
	{
		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();

		float buttonWidth = viewportPanelSize.x / 8.0f;

		const char* perspectiveOptions[] = { "Perspective", "Orthographic" };

		const char* currentPersLabel = perspectiveOptions[selectedProj];

		position.x += 10.0f;
		position.y += 8.0f;

		// Sets to draw on position
		ImGui::SetCursorScreenPos(position);
		ImGui::SetNextItemWidth(buttonWidth);
		if (ImGui::BeginCombo("##Perspective", currentPersLabel))
		{
			for (int n = 0; n < IM_ARRAYSIZE(perspectiveOptions); n++)
			{
				bool isSelected = (selectedProj == n);
				if (ImGui::Selectable(perspectiveOptions[n], isSelected))
				{
					selectedProj = n;
					this->currentCamera->setProjectionType(n);
					this->currentCamera->setLocalPosition({ 0, 0, -3 });
					this->currentCamera->setLocalRotation({ 0, 0, 0 });

					if (n == 2)
					{
						this->currentCamera->setLocalPosition({ 0, 10, 0 });
						this->currentCamera->setLocalRotation({ 1.57f, 0, 0 });
					}
				}
				if (isSelected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}

		// const char* stateOptions[] = { "Solid", "Wireframe", "Solid Wireframe" };
		//
		// const char* currentStatesLabel = stateOptions[selectedState];
		//
		// ImGui::SameLine();
		// ImGui::SetNextItemWidth(buttonWidth);
		// if (ImGui::BeginCombo("##State", currentStatesLabel))
		// {
		// 	for (int n = 0; n < IM_ARRAYSIZE(perspectiveOptions); n++)
		// 	{
		// 		bool isSelected = (selectedState == n);
		// 		if (ImGui::Selectable(stateOptions[n], isSelected))
		// 		{
		// 			selectedState = n;
		// 			this->currentFillMode = static_cast<EFillMode>(n);
		// 		}
		// 		if (isSelected)
		// 		{
		// 			ImGui::SetItemDefaultFocus();
		// 		}
		// 	}
		// 	ImGui::EndCombo();
		// }

		ImGui::SameLine();
		const auto& cameras = CameraManager::getInstance()->getSceneCameras();

		ImGui::SetNextItemWidth(buttonWidth);

		if (cameras.empty())
		{
			selectedCameraIndex = 0;
		}

		if (selectedCameraIndex >= cameras.size())
		{
			selectedCameraIndex = cameras.size() - 1;
		}

		std::string displayName = "Cam " + std::to_string(selectedCameraIndex + 1);
		if (ImGui::BeginCombo("##SelectCamera", displayName.c_str()))
		{
			for (size_t i = 0; i < cameras.size(); i++)
			{
				bool isSelected = (selectedCameraIndex == static_cast<int>(i));
				displayName = "Cam " + std::to_string(i + 1);
				if (ImGui::Selectable(displayName.c_str(), isSelected))
				{
					selectedCameraIndex = static_cast<int>(i);
					this->currentCamera->setPossessed(false);
					this->currentCamera = cameras[selectedCameraIndex];
				}
				if (isSelected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
	}
}
