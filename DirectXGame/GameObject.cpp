#include "GameObject.h"

#include <iostream>
#include <utility>

#include "CameraManager.h"
#include "EditorAction.h"
#include "PhysicsComponent.h"

namespace gdeng03
{
	GameObject::GameObject(const std::string& name) : displayName(name), name(name)
	{
	}

	GameObject::~GameObject()
	{
		for (Component* component : componentList)
		{
			component->detachOwner();
		}

		componentList.clear();
	}

	void GameObject::setPosition(const Vector3D& position)
	{
		globalPosition = position;

		localPosition = (parent) ?
			globalPosition - parent->getGlobalPosition() :
			globalPosition;

		/*for(GameObjectPtr child : children)
		{
			child->setPosition(globalPosition + child->getLocalPosition());
		}*/

		updateLocalMatrix();
	}

	void GameObject::setLocalPosition(const Vector3D& position)
	{
		localPosition = position;

		globalPosition = (parent != nullptr) ?
			localPosition + parent->getGlobalPosition() :
			localPosition;

		/*for (GameObjectPtr child : children)
		{
			child->setPosition(globalPosition + child->getLocalPosition());
		}*/

		updateLocalMatrix();
	}

	void GameObject::translate(const Vector3D& translation)
	{
		localPosition += translation;
		setLocalPosition(localPosition);
		updateLocalMatrix();
	}

	Vector3D GameObject::getGlobalPosition()
	{
		Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);
		return globalPosition;
	}

	Vector3D GameObject::getLocalPosition()
	{
		return localPosition;
	}

	void GameObject::setLocalScale(const Vector3D& scale)
	{
		localScale = scale;
		//LogUtils::log(this->name + " setting local scale to: " + localScale.toString());
		updateGlobalScaleWithChildren();
		//LogUtils::log(this->name + " global scale: " + globalScale.toString());
	}

	void GameObject::scale(const Vector3D& scale)
	{
		localScale += scale;
		updateGlobalScaleWithChildren();
	}

	Vector3D GameObject::getGlobalScale()
	{
		Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);
		return globalScale;
	}

	Vector3D GameObject::getLocalScale()
	{
		return localScale;
	}

	void GameObject::updateGlobalScaleWithChildren()
	{
		globalScale = (parent) ?
			localScale.multiply(parent->getGlobalScale()) :
			localScale;

		/*for (GameObjectPtr child : children)
		{
			child->updateGlobalScaleWithChildren();
		}*/

		updateLocalMatrix();
	}

	void GameObject::setRotation(const Vector3D& rotation)
	{
		globalRotation = rotation;

		localRotation = (parent) ?
			globalRotation - parent->getGlobalRotation() :
			globalRotation;

		/*for (GameObjectPtr child : children)
		{
			child->setRotation(globalRotation + child->getLocalRotation());
		}*/


		updateLocalMatrix();
	}

	void GameObject::setLocalRotation(const Vector3D& rotation)
	{
		localRotation = rotation;

		globalRotation = (parent) ?
			localRotation + parent->getGlobalRotation() :
			localRotation;

		/*for (GameObjectPtr child : children)
		{
			child->setRotation(globalRotation + child->getLocalRotation());
		}*/

		updateLocalMatrix();
	}

	void GameObject::rotate(const Vector3D& rotation)
	{
		localRotation += rotation;
		setLocalRotation(localRotation);
	}

	Vector3D GameObject::getGlobalRotation()
	{
		Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);
		return globalRotation;
	}

	// Gets local rotation IN DEGREES!
	Vector3D GameObject::getLocalRotation() const
	{
		return localRotation * (180 / M_PI);
	}

	Vector3D GameObject::getLocalRotationInRadians() const
	{
		return localRotation;
	}

	void GameObject::setOrientation(const Vector4D& orientation)
	{
		this->orientation = orientation;
		updateLocalMatrix();
	}

	Vector4D GameObject::getOrientation()
	{
		return orientation;
	}

	void GameObject::setEnabled(const bool enabled)
	{
		isEnabled = enabled;

		for (GameObjectPtr child : children)
		{
			child->setEnabled(enabled);
		}
	}

	bool GameObject::getEnabled() const
	{
		return isEnabled;
	}

	// can be non-unique.
	void GameObject::setDisplayName(const std::string& displayName)
	{
		this->displayName = std::move(displayName);
	}

	std::string GameObject::getUniqueName()
	{
		return name;
	}

	std::string GameObject::getDisplayName()
	{
		return displayName;
	}

	void GameObject::updateLocalMatrix()
	{
		//setup transformation matrix for drawing.
		Matrix4x4 allMatrix; allMatrix.setIdentity();
		Matrix4x4 translationMatrix; translationMatrix.setIdentity();  translationMatrix.setTranslation(getLocalPosition());
		Matrix4x4 scaleMatrix; scaleMatrix.setScale(getLocalScale());
		Vector3D rotation = localRotation;
		Matrix4x4 xMatrix; xMatrix.setRotationX(rotation.x);
		Matrix4x4 yMatrix; yMatrix.setRotationY(rotation.y);
		Matrix4x4 zMatrix; zMatrix.setRotationZ(rotation.z);

		//Scale --> Rotate --> Transform as recommended order.
		Matrix4x4 rotMatrix; rotMatrix.setIdentity();
		rotMatrix = rotMatrix.multiplyTo(xMatrix.multiplyTo(yMatrix.multiplyTo(zMatrix)));

		allMatrix = allMatrix.multiplyTo(scaleMatrix.multiplyTo(rotMatrix));
		allMatrix = allMatrix.multiplyTo(translationMatrix);
		this->localMatrix = allMatrix;

		localMatrix = (parent) ?
			localMatrix.multiplyTo(parent->localMatrix) :
			localMatrix;

		//Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);

		for (GameObjectPtr child : children)
		{
			child->updateLocalMatrix();
		}

		// ComponentList result = getComponentsOfType(ComponentType::PHYSICS);
		// if (result.size() == 0) return;
		// PhysicsComponent* physicsComponent = reinterpret_cast<PhysicsComponent*>(result.front());
		// if (physicsComponent != nullptr)
		// {
		// 	physicsComponent->updateRigidbodyTransform();
		// 	//physicsComponent->setTransformFromOpenGL(getPhysicsLocalMatrix());
		// }
	}

	//void GameObject::updateGlobalMatrix()
	//{
	//	//setup transformation matrix for drawing.
	//	Matrix4x4 allMatrix; allMatrix.setIdentity();
	//	Matrix4x4 translationMatrix; translationMatrix.setIdentity();  translationMatrix.setTranslation(getGlobalPosition());
	//	Matrix4x4 scaleMatrix; scaleMatrix.setScale(getGlobalScale());
	//	Vector3D rotation = getGlobalRotation();
	//	Matrix4x4 xMatrix; xMatrix.setRotationX(rotation.x);
	//	Matrix4x4 yMatrix; yMatrix.setRotationY(rotation.y);
	//	Matrix4x4 zMatrix; zMatrix.setRotationZ(rotation.z);

	//	//Scale --> Rotate --> Transform as recommended order.
	//	Matrix4x4 rotMatrix; rotMatrix.setIdentity();
	//	//reactphysics3d::Quaternion q = reactphysics3d::Quaternion(orientation.x, orientation.y, orientation.z, orientation.w).getMatrix();
	//	rotMatrix = rotMatrix.multiplyTo(xMatrix.multiplyTo(yMatrix.multiplyTo(zMatrix)));

	//	allMatrix = allMatrix.multiplyTo(scaleMatrix.multiplyTo(rotMatrix));
	//	allMatrix = allMatrix.multiplyTo(translationMatrix);
	//	this->localMatrix = allMatrix;

	//	localMatrix = (parent) ?
	//		localMatrix.multiplyTo(parent->localMatrix) :
	//		localMatrix;

	//	//Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);

	//	for (GameObjectPtr child : children)
	//	{
	//		child->updateGlobalMatrix();
	//	}

	//	ComponentList result = getComponentsOfType(ComponentType::PHYSICS);
	//	if (result.size() == 0) return;
	//	PhysicsComponent* physicsComponent = reinterpret_cast<PhysicsComponent*>(result.front());
	//	if (physicsComponent != nullptr)
	//	{
	//		physicsComponent->setTransformFromOpenGL(getPhysicsLocalMatrix());
	//	}
	//}

	Matrix4x4 GameObject::getLocalMatrix() const
	{
		return localMatrix;
	}

	void GameObject::setLocalMatrix(const Matrix4x4& matrix)
	{
		Matrix4x4 allMatrix; allMatrix.setIdentity();
		Matrix4x4 translationMatrix; translationMatrix.setIdentity(); translationMatrix.setTranslation(this->getLocalPosition());
		Matrix4x4 scaleMatrix; scaleMatrix.setIdentity(); scaleMatrix.setScale(this->getLocalScale());
		Vector3D rotation = this->getLocalRotation();
		Matrix4x4 zMatrix; zMatrix.setIdentity(); zMatrix.setRotationZ(rotation.z);
		Matrix4x4 xMatrix; xMatrix.setIdentity(); xMatrix.setRotationX(rotation.x);
		Matrix4x4 yMatrix; yMatrix.setIdentity(); yMatrix.setRotationY(rotation.y);

		allMatrix *= scaleMatrix;
		allMatrix *= zMatrix;
		allMatrix *= yMatrix;
		allMatrix *= xMatrix;
		allMatrix *= translationMatrix;

		this->localMatrix = matrix;
		this->localMatrix *= allMatrix;

		// float matrix4x4[4][4];
		// matrix4x4[0][0] = matrix[0];
		// matrix4x4[0][1] = matrix[1];
		// matrix4x4[0][2] = matrix[2];
		// matrix4x4[0][3] = matrix[3];
		//
		// matrix4x4[1][0] = matrix[4];
		// matrix4x4[1][1] = matrix[5];
		// matrix4x4[1][2] = matrix[6];
		// matrix4x4[1][3] = matrix[7];
		//
		// matrix4x4[2][0] = matrix[8];
		// matrix4x4[2][1] = matrix[9];
		// matrix4x4[2][2] = matrix[10];
		// matrix4x4[2][3] = matrix[11];
		//
		// matrix4x4[3][0] = matrix[12];
		// matrix4x4[3][1] = matrix[13];
		// matrix4x4[3][2] = matrix[14];
		// matrix4x4[3][3] = matrix[15];
		//
		// Matrix4x4 newMatrix; newMatrix.setMatrix(matrix4x4);
		//
		// Matrix4x4
		// 	translateMatrix,
		// 	scaleMatrix;
		//
		// translateMatrix.setTranslation(getLocalPosition());
		// scaleMatrix.setScale(getLocalScale());
		//
		// localMatrix = scaleMatrix * translateMatrix * newMatrix;
	}

	void GameObject::recomputeMatrix(float matrix[16])
	{

		Matrix4x4 physMat;
		physMat.setIdentity();

		int index = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				physMat.mat[i][j] = matrix[index];
				index++;
			}
		}
		//physMat.setTranslation(physMat.getTranslation() * 2.f);
		//physMat.setTranslationWithoutReset(physMat.getTranslation() + physMat.getTranslation() / 2.f);
		physMat.setTranslationWithoutReset(physMat.getTranslation() * 2.f);
		Matrix4x4 newMatrix;
		newMatrix.setMatrix(physMat);

		Matrix4x4 scaleMatrix;
		scaleMatrix.setIdentity();
		scaleMatrix.setScale(this->localScale);

		Matrix4x4 transMatrix;
		transMatrix.setIdentity();
		//transMatrix.setTranslation(localPosition / 2.f);
		transMatrix.setTranslation(localPosition);

		transMatrix *= newMatrix;
		//transMatrix.setTranslationWithoutReset(transMatrix.getTranslation() + transMatrix.getTranslation() / 2.f);
		//LogUtils::log(this->getUniqueName() + " recomputing translation: " + transMatrix.getTranslation().toString());
		scaleMatrix *= transMatrix;
		this->localMatrix = scaleMatrix;
	}

	float* GameObject::getPhysicsLocalMatrix()
	{
		// Matrix4x4 allMatrix; allMatrix.setIdentity();
		// Matrix4x4 translationMatrix; translationMatrix.setIdentity();
		// translationMatrix.setTranslation(getLocalPosition());
		// Matrix4x4 scaleMatrix; scaleMatrix.setLocalScale(1); //physics 3D only accepts uniform scale for rigidbody
		// Vector3D rotation = getLocalRotation();
		// Matrix4x4 xMatrix; xMatrix.setRotationX(rotation.x);
		// Matrix4x4 yMatrix; yMatrix.setRotationY(rotation.y);
		// Matrix4x4 zMatrix; zMatrix.setRotationZ(rotation.z);
		//
		// //Scale --> Rotate --> Transform as recommended order.
		// Matrix4x4 rotMatrix; rotMatrix.setIdentity();
		// rotMatrix = rotMatrix * xMatrix * yMatrix * zMatrix;
		//
		// allMatrix = allMatrix * scaleMatrix * rotMatrix;
		// allMatrix = allMatrix * translationMatrix;
		//
		// return allMatrix.getLocalMatrix();

		Matrix4x4 allMatrix, originalScale;
		Matrix4x4 temp;

		allMatrix.setIdentity();
		allMatrix.setScale(Vector3D(1, 1, 1));

		// originalScale.setIdentity();
		// originalScale.setScale(this->localScale);

		temp.setIdentity();
		temp.setRotationZ(this->localRotation.z);
		allMatrix *= temp;

		temp.setIdentity();
		temp.setRotationY(this->localRotation.y);
		allMatrix *= temp;

		temp.setIdentity();
		temp.setRotationX(this->localRotation.x);
		allMatrix *= temp;

		temp.setIdentity();
		temp.setTranslation(this->localPosition);
		allMatrix *= temp;


		//this->localMatrix = allMatrix;
		return allMatrix.getMatrix();

		// Matrix4x4
		// 	translateMatrix,
		// 	scaleMatrix,
		// 	xMatrix,
		// 	yMatrix,
		// 	zMatrix;
		//
		// translateMatrix.setTranslation(getLocalPosition());
		// scaleMatrix.setScale(getLocalScale());
		//
		// zMatrix.setRotationZ(getLocalRotation().z);
		// yMatrix.setRotationY(getLocalRotation().y);
		// xMatrix.setRotationX(getLocalRotation().x);
		//
		// const Matrix4x4 rotateMatrix = xMatrix * yMatrix * zMatrix;
		// return (scaleMatrix * rotateMatrix * translateMatrix).getMatrix();
	}

	void GameObject::recalculateChildTransformWithParent(GameObjectPtr parent)
	{
		if (!parent) return;

		Matrix4x4 parentGlobalMatrix = parent->getLocalMatrix();
		parentGlobalMatrix.inverse();

		Matrix4x4 newLocalMatrix = parentGlobalMatrix.multiplyTo(this->getLocalMatrix());

		Matrix4x4::decomposeMatrix(newLocalMatrix, localPosition, localRotation, localScale);

		setLocalPosition(localPosition);
		setLocalRotation(localRotation);
		setLocalScale(localScale);
	}

	void GameObject::recalculateChildTransformWithParent(GameObject* parent)
	{
		if (!parent) return;

		Matrix4x4 parentGlobalMatrix = parent->getLocalMatrix();
		parentGlobalMatrix.inverse();

		Matrix4x4 newLocalMatrix = parentGlobalMatrix.multiplyTo(this->getLocalMatrix());

		Matrix4x4::decomposeMatrix(newLocalMatrix, localPosition, localRotation, localScale);

		setLocalPosition(localPosition);
		setLocalRotation(localRotation);
		setLocalScale(localScale);
	}

	void GameObject::recalculateChildTransformWithoutParent()
	{
		Matrix4x4::decomposeMatrix(localMatrix, globalPosition, globalRotation, globalScale);

		setPosition(globalPosition);
		setRotation(globalRotation);
		setLocalScale(globalScale);
	}

	void GameObject::attachComponent(Component* component)
	{
		componentList.push_back(component);
		component->attachOwner(this);
	}

	void GameObject::detachComponent(const Component* component)
	{
		const auto it = std::find(componentList.begin(), componentList.end(), component);
		componentList.erase(it);
	}

	void GameObject::setParent(GameObject* parent)
	{
		this->parent = parent;
	}

	void GameObject::detachParent()
	{
		parent = nullptr;
	}

	GameObject* GameObject::getParent()
	{
		return parent;
	}

	void GameObject::attachChild(GameObjectPtr child)
	{
		if (child == nullptr || child.get() == this || child.get() == parent) return;

		if (child->parent != nullptr)
		{
			child->parent->detachChild(child);
		}

		children.push_back(child);
		child->setParent(this);
		child->level = level + 1;
		child->setEnabled(isEnabled);
		child->recalculateChildTransformWithParent(this);
	}

	void GameObject::detachChild(GameObjectPtr child)
	{
		if (child.get() == this || child == nullptr) return;

		const GameObjectList::iterator it = std::find(children.begin(), children.end(), child);

		if (it != children.end())
		{
			children.erase(it);
		}

		child->level = 0;
		child->setParent(nullptr);
		child->recalculateChildTransformWithoutParent();
	}

	GameObject::GameObjectList GameObject::getChildren()
	{
		return this->children;
	}

	int GameObject::getLevel()
	{
		return level;
	}

	Component* GameObject::findComponentByName(const std::string& name)
	{
		const auto it = std::find_if(componentList.begin(), componentList.end(),
			[name](Component* component)
			{
				return component->getName() == name;
			});

		if (it != componentList.end())
			return *it;

		return nullptr;
	}

	Component* GameObject::findComponentOfType(ComponentType type, const std::string& name)
	{
		const auto it = std::find_if(componentList.begin(), componentList.end(),
			[type, name](Component* component)
			{
				return component->getType() == type && component->getName() == name;
			});

		if (it != componentList.end())
			return *it;

		return nullptr;
	}

	GameObject::ComponentList GameObject::getComponentsOfType(const ComponentType type) const
	{
		ComponentList result;
		result.reserve(componentList.size());

		for (auto component : componentList)
		{
			if (component->getType() == type)
				result.push_back(component);
		}

		return result;
	}

	// TODO: search child GameObjects recursively.
	GameObject::ComponentList GameObject::getComponentsOfTypeRecursive(const ComponentType type) const
	{
		ComponentList result;
		result.reserve(componentList.size());

		for (auto component : componentList)
		{
			if (component->getType() == type)
				result.push_back(component);
		}

		return result;
	}

	void GameObject::saveEditState()
	{
		lastEditState = new EditorAction(this);
	}

	void GameObject::restoreEditState()
	{
		if (lastEditState)
		{
			displayName = lastEditState->getOwnerName();
			localPosition = lastEditState->getStoredPosition();
			localScale = lastEditState->getStoredScale();
			orientation = lastEditState->getStoredOrientation();
			localMatrix = lastEditState->getStoredMatrix();

			// for (const ComponentList physicsList = getComponentsOfType(ComponentType::PHYSICS);
			// 	Component * component : physicsList)
			// {
			// 	PhysicsComponent* physicsComponent = dynamic_cast<PhysicsComponent*>(component);
			// 	//physicsComponent->setTransformFromOpenGL(localMatrix.getMatrix());
			// 	physicsComponent->updateRigidbodyTransform();
			// 	physicsComponent->getRigidBody()->setAngularVelocity(Vector3(0, 0, 0));
			// 	physicsComponent->getRigidBody()->setLinearVelocity(Vector3(0, 0, 0));
			// }

			//LogUtils::log(this->getUniqueName() + "restored scale: " + lastEditState->getStoredScale().toString());

			lastEditState = nullptr;
		}
	}

	void GameObject::setUniqueName(const std::string& uniqueName)
	{
		this->name = uniqueName;
	}
}
