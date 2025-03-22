// #pragma once
//
// #include "Component.h"
// #include <reactphysics3d/reactphysics3d.h>
//
// #include "GameObject.h"
// #include "PrimitiveType.h"
//
// namespace gdeng03
// {
// 	using namespace reactphysics3d;
// 	class PhysicsComponent : public Component
// 	{
// 	public:
// 		enum class EConstraints : uint8_t
// 		{
// 			None = 0,
// 			FreezePositionX = 1 << 0,
// 			FreezePositionY = 1 << 1,
// 			FreezePositionZ = 1 << 2,
// 			FreezeRotationX = 1 << 3,
// 			FreezeRotationY = 1 << 4,
// 			FreezeRotationZ = 1 << 5,
// 			FreezePosition = FreezePositionX | FreezePositionY | FreezePositionZ,
// 			FreezeRotation = FreezeRotationX | FreezeRotationY | FreezeRotationZ,
// 			FreezeAll = FreezePosition | FreezeRotation
// 		};
//
// 	private:
// 		RigidBody* rigidBody;
// 		float mass = 10.0f;
// 		uint8_t constraints = 0;
//
// 	public:
// 		PhysicsComponent(GameObject* owner, PrimitiveType colliderType = PrimitiveType::NOT_PRIMITIVE);
// 		~PhysicsComponent() override;
//
// 	public:
// 		void update() override;
// 		RigidBody* getRigidBody() const;
//
// 		float getMass() const;
// 		bool getUseGravity() const;
// 		BodyType getBodyType() const;
// 		float getLinearDrag() const;
// 		float getAngularDrag() const;
// 		bool getConstraint(EConstraints constraint) const;
//
// 		void updateRigidbodyTransform() const;
// 		void setTransformFromOpenGL(float* matrix) const;
// 		void setMass(float mass);
// 		void setUseGravity(bool isUsingGravity) const;
// 		void setType(BodyType type) const;
// 		void setLinearDrag(float linearDrag) const;
// 		void setAngularDrag(float angularDrag) const;
// 		void setConstraints(EConstraints constraints);
//
// 	//private: // temp
// 		// VertexShaderPtr vertexShader = nullptr;
// 		// GeometryShaderPtr geometryShader = nullptr;
// 		// //MaterialPtr material = nullptr;
// 		//
// 		// VertexBufferPtr vertexBuffer = nullptr;
// 		// IndexBufferPtr indexBuffer = nullptr;
// 		// ConstantBufferPtr constantBuffer = nullptr;
// 	};
// }
