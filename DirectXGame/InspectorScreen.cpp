#include "InspectorScreen.h"

#include "ActionHistory.h"
#include "AppWindow.h"
#include "EngineBackend.h"
#include "imgui.h"
#include "libraries/imgui/misc/cpp/imgui_stdlib.h"
#include "UIManager.h"
#include "GameObjectManager.h"
#include "PhysicsComponent.h"
#include "Renderer3D.h"

using namespace gdeng03;

namespace gdeng03
{
	InspectorScreen::InspectorScreen() : UIScreen("InspectorScreen")
	{
		LogUtils::log(this, "Initialized");
	}

	void InspectorScreen::draw()
	{
		ImGui::SetNextWindowSize(ImVec2(AppWindow::get()->getWindowWidth() / 6, AppWindow::get()->getWindowHeight()), ImGuiCond_Once);
		ImGui::Begin("Inspector", &isActive);

		selectedObject = GameObjectManager::get()->getSelectedObject();
		if (selectedObject != nullptr)
		{
			this->drawInspector();
		}

		ImGui::End();
	}

	void InspectorScreen::drawInspector()
	{
		std::string name = selectedObject->getDisplayName();
		bool isEnabled = selectedObject->getEnabled();

		if (ImGui::Checkbox("##Active", &isEnabled))
		{
			selectedObject->setEnabled(isEnabled);
		}
		ImGui::SameLine();
		ImGui::SetNextItemWidth(-1);
		if (ImGui::InputText("##Name", &name))
		{
			if (ImGui::IsItemDeactivatedAfterEdit())
				selectedObject->setDisplayName(name);
		}

		this->drawTransformTable(selectedObject);
		this->drawComponentList(selectedObject);

		if (ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x - 15, 40)))
		{
			ImGui::SetNextWindowPos(ImGui::GetCursorScreenPos());
			ImGui::OpenPopup("SelectComponent");
		}
		ImVec2 buttonSize = ImGui::GetItemRectSize();
		buttonSize.x -= 17;
		buttonSize.y = 0;
		if (ImGui::BeginPopup("SelectComponent"))
		{
			// if (ImGui::Selectable("Rigidbody", false, 0, buttonSize))
			// {
			// 	// ADD RIGIDBODY TO OBJECT
			// 	GameObject::ComponentList rendererComponentList = selectedObject->getComponentsOfType(ComponentType::RENDERER);
			// 	for (Component* component : rendererComponentList)
			// 	{
			// 		if (component->getName().find("RendererComponent") != std::string::npos)
			// 		{
			// 			Renderer3D* rendererComponent = dynamic_cast<Renderer3D*>(component);
			// 			selectedObject->attachComponent(new PhysicsComponent(selectedObject, rendererComponent->getMesh()->getType()));
			// 		}
			// 	}
			// 	;
			// }
			if (ImGui::Selectable("Material", false, 0, buttonSize))
			{
				// add material to renderer
				GameObject::ComponentList rendererComponentList = selectedObject->getComponentsOfType(ComponentType::RENDERER);
				for (Component* component : rendererComponentList)
				{
					if (component->getName().find("RendererComponent") != std::string::npos)
					{
						Renderer3D* rendererComponent = dynamic_cast<Renderer3D*>(component);
						rendererComponent->createMaterial();
					}
				}
			}
			ImGui::EndPopup();
		}

		if (ImGui::Button("Delete", ImVec2(ImGui::GetWindowSize().x - 15, 40)))
		{
			GameObjectManager::get()->setSelectedObject(nullptr);
			GameObjectManager::get()->deleteObjectByName(selectedObject->getUniqueName());
		}
	}

	void InspectorScreen::drawTransformTable(GameObject* gameObject)
	{
		int rows = 3;

		std::string labels[] = { "Position", "Rotation", "Scale" };

		Vector3D vectorValues[3];
		vectorValues[0] = gameObject->getLocalPosition();
		vectorValues[1] = gameObject->getLocalRotation();
		vectorValues[2] = gameObject->getLocalScale();

		if (ImGui::BeginTable("Transform", 2, ImGuiTableFlags_SizingFixedFit))
		{
			ImGui::TableSetupColumn("Label", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Values", ImGuiTableColumnFlags_WidthStretch);

			for (int i = 0; i < rows; i++)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text(labels[i].c_str());
				ImGui::TableNextColumn();
				ImGui::SetNextItemWidth(-1);
				float values[3] = { vectorValues[i].x, vectorValues[i].y, vectorValues[i].z };
				std::string dragLabel = "##" + labels[i];

				if (ImGui::DragFloat3(dragLabel.c_str(), values, 0.01f))
				{
					if (!hasChanged)
					{
						ActionHistory::get()->recordAction(gameObject);
					}

					hasChanged = true;

					switch (i)
					{
					case 0:
						gameObject->setLocalPosition(Vector3D(values[0], values[1], values[2]));
						break;
					case 1:
						gameObject->setLocalRotation({ values[0] * static_cast<float>((M_PI / 180.f)), values[1] * static_cast<float>((M_PI / 180.f)), values[2] * static_cast<float>((M_PI / 180.f)) });
						break;
					case 2:
						gameObject->setLocalScale(Vector3D(values[0], values[1], values[2]));
						break;
					}
				}

				if (ImGui::IsMouseDown(ImGuiMouseButton_Left))
				{
					isLeftDown = true;
				}
				else
				{
					isLeftDown = false;
				}

				if (hasChanged && !isLeftDown)
				{
					hasChanged = false;
				}
			}

			ImGui::EndTable();
		}
	}

	void InspectorScreen::drawComponentList(GameObject* gameObject)
	{
		// GameObject::ComponentList physicsComponentList = gameObject->getComponentsOfType(ComponentType::PHYSICS);
		// for (Component* component : physicsComponentList)
		// {
		// 	if (component->getName().find("PhysicsComponent") != std::string::npos)
		// 	{
		// 		PhysicsComponent* physicsComponent = dynamic_cast<PhysicsComponent*>(component);
		//
		// 		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0);
		// 		if (ImGui::CollapsingHeader("Rigidbody", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_DefaultOpen))
		// 		{
		// 			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.800000190734863f);
		//
		// 			float mass = physicsComponent->getMass();
		// 			float linearDrag = physicsComponent->getLinearDrag();
		// 			float angularDrag = physicsComponent->getAngularDrag();
		// 			bool gravity = physicsComponent->getUseGravity();
		//
		// 			ImGui::DragFloat("Mass", &mass);
		// 			ImGui::DragFloat("Linear Drag", &linearDrag);
		// 			ImGui::DragFloat("Angular Drag", &angularDrag);
		// 			ImGui::Checkbox("Gravity", &gravity);
		//
		// 			BodyType bodyType = physicsComponent->getBodyType();
		// 			const char* items[] = { "Static", "Kinematic", "Dynamic" };
		// 			int iteselected_idx = static_cast<int>(bodyType); // Here we store our selection data as an index.
		// 			// Pass in the preview value visible before opening the combo (it could technically be different contents or not pulled from items[])
		// 			const char* combo_preview_value = items[iteselected_idx];
		//
		// 			if (ImGui::BeginCombo("Body Type", combo_preview_value))
		// 			{
		// 				for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		// 				{
		// 					const bool is_selected = (iteselected_idx == n);
		// 					if (ImGui::Selectable(items[n], is_selected))
		// 						iteselected_idx = n;
		//
		// 					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
		// 					if (is_selected)
		// 						ImGui::SetItemDefaultFocus();
		// 				}
		// 				ImGui::EndCombo();
		// 			}
		//
		// 			if (ImGui::TreeNode("Constraints"))
		// 			{
		// 				bool freezePosX = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezePositionX);
		// 				bool freezePosY = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezePositionY);
		// 				bool freezePosZ = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezePositionZ);
		// 				bool freezeRotX = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezeRotationX);
		// 				bool freezeRotY = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezeRotationY);
		// 				bool freezeRotZ = physicsComponent->getConstraint(PhysicsComponent::EConstraints::FreezeRotationZ);
		//
		// 				if (ImGui::BeginTable("ConstraintsTable", 4, ImGuiTableFlags_SizingFixedFit))
		// 				{
		// 					ImGui::TableSetupColumn("Label", ImGuiTableColumnFlags_WidthStretch);
		// 					ImGui::TableSetupColumn("X", ImGuiTableColumnFlags_WidthFixed);
		// 					ImGui::TableSetupColumn("Y", ImGuiTableColumnFlags_WidthFixed);
		// 					ImGui::TableSetupColumn("Z", ImGuiTableColumnFlags_WidthFixed);
		//
		// 					ImGui::TableNextRow();
		// 					ImGui::TableNextColumn();
		// 					ImGui::Text("Freeze Position");
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("X##Pos", &freezePosX);
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("Y##Pos", &freezePosY);
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("Z##Pos", &freezePosZ);
		//
		// 					ImGui::TableNextColumn();
		// 					ImGui::Text("Freeze Rotation");
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("X##Rot", &freezeRotX);
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("Y##Rot", &freezeRotY);
		// 					ImGui::TableNextColumn();
		// 					ImGui::Checkbox("Z##Rot", &freezeRotZ);
		//
		// 					ImGui::EndTable();
		// 				}
		// 				ImGui::TreePop();
		//
		// 				physicsComponent->setConstraints(
		// 					static_cast<PhysicsComponent::EConstraints>(
		// 						freezePosX << 0
		// 						| freezePosY << 1
		// 						| freezePosZ << 2
		// 						| freezeRotX << 3
		// 						| freezeRotY << 4
		// 						| freezeRotZ << 5));
		// 			}
		//
		// 			physicsComponent->setMass(mass);
		// 			physicsComponent->setLinearDrag(linearDrag);
		// 			physicsComponent->setAngularDrag(angularDrag);
		// 			physicsComponent->setUseGravity(gravity);
		// 			physicsComponent->setType(static_cast<BodyType>(iteselected_idx));
		//
		// 			std::string buttonName = "Delete##" + component->getName();
		// 			if (ImGui::Button(buttonName.c_str(), ImVec2(ImGui::GetWindowSize().x - 15, 40)))
		// 			{
		// 				gameObject->detachComponent(component);
		// 				//gameObject->setPhysics(false);
		// 			}
		// 			ImGui::PopStyleVar();
		// 		}
		// 		ImGui::PopStyleVar();
		// 		ImGui::Separator();
		// 	}
		// }

		GameObject::ComponentList rendererComponentList = gameObject->getComponentsOfType(ComponentType::RENDERER);
		for (Component* component : rendererComponentList)
		{
			if (component->getName().find("RendererComponent") != std::string::npos)
			{
				MaterialEditor* matEditorScreen = dynamic_cast<MaterialEditor*>(UIManager::get()->getScreen("MaterialEditor").get());
				Renderer3D* rendererComponent = dynamic_cast<Renderer3D*>(component);

				if (!rendererComponent->getMaterial())
					continue;

				ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0);
				if (ImGui::CollapsingHeader("Material", ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_DefaultOpen))
				{
					ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 7.800000190734863f);

					if (matEditorScreen && matEditorScreen->canSelectMaterial())
					{
						matEditorScreen->setSelectedMaterial(rendererComponent->getMaterial());
					}

					std::string buttonName = "Delete##" + component->getName();
					if (ImGui::Button(buttonName.c_str(), ImVec2(ImGui::GetWindowSize().x - 15, 40)))
					{
						if (matEditorScreen)
							matEditorScreen->unselectMaterial();

						rendererComponent->resetMaterial();
						//gameObject->setPhysics(false);
					}
					ImGui::PopStyleVar();
				}
				ImGui::PopStyleVar();
				ImGui::Separator();
			}

		}
	}
}
