// #include "PhysicsComponent.h"
//
// #include "BaseComponentSystem.h"
// #include "CameraManager.h"
// #include "PhysicsSystem.h"
// #include "GameObject.h"
// #include "ShaderLibrary.h"
// #include "Vector3D.h"
//
//
// namespace gdeng03
// {
// 	using namespace reactphysics3d;
// 	using reactphysics3d::Quaternion;
//
// 	PhysicsComponent::PhysicsComponent(GameObject* owner, PrimitiveType colliderType) : Component("PhysicsComponent " + owner->getUniqueName(), ComponentType::PHYSICS, owner)
// 	{
// 		BaseComponentSystem::get()->getPhysicsSystem()->registerComponent(this);
// 		PhysicsCommon* physicsCommon = BaseComponentSystem::get()->getPhysicsSystem()->getPhysicsCommon();
// 		PhysicsWorld* physicsWorld = BaseComponentSystem::get()->getPhysicsSystem()->getPhysicsWorld();
// 		// Create a rigid body in the world
// 		const Vector3D scale = this->getOwner()->getLocalScale();
// 		Transform transform;
// 		Vector3 position;
// 		position.x = this->getOwner()->getLocalPosition().x;
// 		position.y = this->getOwner()->getLocalPosition().y;
// 		position.z = this->getOwner()->getLocalPosition().z;
//
// 		//transform.setPosition((2.f * position) / 3.f);
// 		//transform.setPosition({ 0, 0, 0 });
// 		//transform.setPosition(position);
// 		transform.setPosition(position / 2.f);
//
// 		transform.setOrientation(Quaternion::fromEulerAngles(this->getOwner()->getLocalRotationInRadians().x, this->getOwner()->getLocalRotationInRadians().y, this->getOwner()->getLocalRotationInRadians().z));
// 		//transform.setFromOpenGL(this->getOwner()->getPhysicsLocalMatrix());
//
// 		this->rigidBody = physicsWorld->createRigidBody(transform);
//
//
// 		switch (colliderType)
// 		{
// 		case PrimitiveType::NOT_PRIMITIVE:
// 		case PrimitiveType::CUBE:
// 		{
// 			BoxShape* boxShape = physicsCommon->createBoxShape(Vector3(scale.x / 2.9f, scale.y / 2.9f, scale.z / 2.9f));
// 			this->rigidBody->addCollider(boxShape, transform);
// 			break;
// 		}
// 		case PrimitiveType::PLANE:
// 		{
// 			BoxShape* boxShape = physicsCommon->createBoxShape(Vector3(scale.x * 2.5f, scale.y * 0.1f, scale.z * 2.5f));
// 			this->rigidBody->addCollider(boxShape, transform);
// 			break;
// 		}
// 		case PrimitiveType::SPHERE:
// 		{
// 			SphereShape* sphereShape = physicsCommon->createSphereShape(scale.x);
// 			this->rigidBody->addCollider(sphereShape, transform);
// 			break;
// 		}
// 		case PrimitiveType::CAPSULE:
// 		{
// 			CapsuleShape* capsuleShape = physicsCommon->createCapsuleShape(scale.x, scale.y);
// 			this->rigidBody->addCollider(capsuleShape, transform);
// 			break;
// 		}
// 		}
//
// 		this->rigidBody->updateMassPropertiesFromColliders();
// 		this->rigidBody->setMass(this->mass);
// 		this->rigidBody->setType(BodyType::DYNAMIC);
// 		//this->rigidBody->setIsDebugEnabled(true);
//
// 		Transform origin;
// 		origin.setPosition({ 0,0,0 });
// 		origin.setOrientation(Quaternion::fromEulerAngles(0, 0, 0));
// 		this->rigidBody->setTransform(origin);
//
// 		transform = this->rigidBody->getTransform();
// 		float matrix[16];
// 		transform.getOpenGLMatrix(matrix);
// 		
// 		this->getOwner()->recomputeMatrix(matrix);
//
// 		 //updateRigidbodyTransform();
// 		// temp
//
// 		// vertexShader = ShaderLibrary::get()->getVertexShader(L"DebugRendererVertexShader.hlsl");
// 		//
// 		//
// 		//
// 		// Constant constants;
// 		//
// 		// constantBuffer = GraphicsEngine::get()->getRenderSystem()->createConstantBuffer(&constants, sizeof(Constant));
// 	}
//
// 	PhysicsComponent::~PhysicsComponent()
// 	{
// 		BaseComponentSystem::get()->getPhysicsSystem()->unregisterComponent(this);
// 		Component::~Component();
//
// 		// for (int i = 0; i < rigidBody->getNbColliders(); ++i)
// 		// {
// 		// 	this->rigidBody->removeCollider(rigidBody->getCollider(i));
// 		// }
//
//
// 		PhysicsWorld* physicsWorld = BaseComponentSystem::get()->getPhysicsSystem()->getPhysicsWorld();
// 		physicsWorld->destroyRigidBody(this->rigidBody);
// 	}
//
// 	void PhysicsComponent::update()
// 	{
// 		const Transform transform = this->rigidBody->getTransform();
// 		float matrix[16];
// 		transform.getOpenGLMatrix(matrix);
//
// 		// this->getOwner()->setLocalPosition(transform.getPosition());
// 		// this->getOwner()->setLocalRotation(transform.getOrientation().getVectorV());
//
// 		this->getOwner()->recomputeMatrix(matrix);
//
// 		// temp
// 		// const DeviceContextPtr deviceContext = GraphicsEngine::get()->getRenderSystem()->getImmediateDeviceContext();
// 		// Constant constants;
// 		// GameObject* owner = getOwner();
// 		// PhysicsWorld* physicsWorld = BaseComponentSystem::get()->getPhysicsSystem()->getPhysicsWorld();
// 		// DebugRenderer& debugRenderer = physicsWorld->getDebugRenderer();
// 		//
// 		// std::vector<Vertex> listVertices;
// 		//
// 		// // for (int i = 0; i < debugRenderer.getNbTriangles(); ++i)
// 		// // {
// 		// // 	DebugRenderer::DebugTriangle dt = debugRenderer.getTriangles()[i];
// 		// // 	listVertices.push_back(Vertex(dt.point1, dt.color1));
// 		// // 	listVertices.push_back(Vertex(dt.point2, dt.color2));
// 		// // 	listVertices.push_back(Vertex(dt.point3, dt.color3));
// 		// // }
// 		//
// 		// for (int i = 0; i < debugRenderer.getNbLines(); ++i)
// 		// {
// 		// 	DebugRenderer::DebugLine dl = debugRenderer.getLines()[i];
// 		// 	listVertices.push_back(Vertex(dl.point1, dl.color1));
// 		// 	listVertices.push_back(Vertex(dl.point2, dl.color2));
// 		// }
// 		//
// 		// if (listVertices.empty())
// 		// 	return;
// 		//
// 		//
// 		// constants.world = owner->getLocalMatrix();
// 		// //constants.world = scaleMatrix * transMatrix * newMatrix;
// 		//
// 		// constants.view = CameraManager::getInstance()->getActiveSceneCameraView();
// 		// constants.proj = CameraManager::getInstance()->getActiveSceneCameraProjection();
// 		//
// 		// constants.time = 0;
// 		//
// 		// constants.color = Vector3D(1);
// 		//
// 		// constantBuffer->update(deviceContext, &constants);
// 		//
// 		// deviceContext->setConstantBuffer(constantBuffer);
// 		//
// 		// //this->vertexBuffer = mesh->getVertexBuffer();
// 		// //this->indexBuffer = mesh->getIndexBuffer();
// 		//
// 		// void* shaderByteCode = nullptr;
// 		// size_t sizeShader = 0;
// 		// GraphicsEngine::get()->getVertexMeshLayoutShaderByteCodeAndSize(&shaderByteCode, &sizeShader);
// 		// vertexBuffer = GraphicsEngine::get()->getRenderSystem()->createVertexBuffer(listVertices.data(), sizeof(Vertex),
// 		// 	static_cast<UINT>(listVertices.size()), shaderByteCode, static_cast<UINT>(sizeShader));
// 		// //indexBuffer = GraphicsEngine::get()->getRenderSystem()->createIndexBuffer(listIndices.data(), static_cast<UINT>(listIndices.size()));
// 		//
// 		// deviceContext->setVertexBuffer(vertexBuffer);
// 		// //deviceContext->setIndexBuffer(indexBuffer);
// 		//
// 		// deviceContext->setVertexShader(vertexShader);
// 		// //deviceContext->setGeometryShader(geometryShader);
// 		// deviceContext->setPixelShader(ShaderLibrary::get()->getPixelShader(L"DebugRendererPixelShader.hlsl"));
// 		//
// 		// //deviceContext->drawTriangleList(vertexBuffer->getSizeVertexList(), 0);
// 		// deviceContext->drawLineStrip(vertexBuffer->getSizeVertexList(), 0);
// 		//
// 		// //deviceContext->setTexture(*material);
// 	}
//
// 	RigidBody* PhysicsComponent::getRigidBody() const
// 	{
// 		return this->rigidBody;
// 	}
//
// 	float PhysicsComponent::getMass() const
// 	{
// 		return mass;
// 	}
//
// 	bool PhysicsComponent::getUseGravity() const
// 	{
// 		return this->rigidBody->isGravityEnabled();
// 	}
//
// 	BodyType PhysicsComponent::getBodyType() const
// 	{
// 		return this->rigidBody->getType();
// 	}
//
// 	float PhysicsComponent::getLinearDrag() const
// 	{
// 		return this->rigidBody->getLinearDamping();
// 	}
//
// 	float PhysicsComponent::getAngularDrag() const
// 	{
// 		return this->rigidBody->getAngularDamping();
// 	}
//
// 	bool PhysicsComponent::getConstraint(EConstraints constraint) const
// 	{
// 		return (constraints & static_cast<uint8_t>(constraint)) == static_cast<uint8_t>(constraint);
// 	}
//
// 	void PhysicsComponent::updateRigidbodyTransform() const
// 	{
// 		Vector3 position;
// 		position.x = this->getOwner()->getLocalPosition().x;
// 		position.y = this->getOwner()->getLocalPosition().y;
// 		position.z = this->getOwner()->getLocalPosition().z;
//
// 		Transform transform = this->rigidBody->getTransform();
// 		//transform.setPosition((2.f * position) / 3.f);
// 		//transform.setPosition(position);
// 		transform.setPosition(position / 2.f);
// 		//transform.setPosition({ 0, 0, 0 });
// 		transform.setOrientation(Quaternion::fromEulerAngles(this->getOwner()->getLocalRotationInRadians().x, this->getOwner()->getLocalRotationInRadians().y, this->getOwner()->getLocalRotationInRadians().z));
// 		this->rigidBody->setTransform(transform);
// 		//this->rigidBody->getCollider(0)->setLocalToBodyTransform(transform);
// 	}
//
// 	void PhysicsComponent::setTransformFromOpenGL(float* matrix) const
// 	{
// 		Transform transform;
// 		transform.setFromOpenGL(matrix);
// 		this->rigidBody->setIsActive(false);
// 		this->rigidBody->setTransform(transform);
// 		this->rigidBody->setIsActive(true);
// 		this->rigidBody->setIsSleeping(false);
// 	}
//
// 	void PhysicsComponent::setMass(float mass)
// 	{
// 		this->mass = mass;
// 		this->rigidBody->setMass(mass);
// 	}
//
// 	void PhysicsComponent::setUseGravity(const bool isUsingGravity) const
// 	{
// 		this->rigidBody->enableGravity(isUsingGravity);
// 	}
//
// 	void PhysicsComponent::setType(const BodyType type) const
// 	{
// 		this->rigidBody->setType(type);
// 	}
//
// 	void PhysicsComponent::setLinearDrag(float linearDrag) const
// 	{
// 		if (linearDrag < 0)
// 			linearDrag = 0;
//
// 		this->rigidBody->setLinearDamping(linearDrag);
// 	}
//
// 	void PhysicsComponent::setAngularDrag(float angularDrag) const
// 	{
// 		if (angularDrag < 0)
// 			angularDrag = 0;
//
// 		this->rigidBody->setAngularDamping(angularDrag);
// 	}
//
// 	void PhysicsComponent::setConstraints(EConstraints constraints)
// 	{
// 		this->constraints = static_cast<uint8_t>(constraints);
//
// 		// getConstraint returns 1 if true. AxisFactor of ReactPhysics3D is 0 to freeze.
// 		const Vector3 freezePosition = Vector3(
// 			!getConstraint(EConstraints::FreezePositionX),
// 			!getConstraint(EConstraints::FreezePositionY),
// 			!getConstraint(EConstraints::FreezePositionZ));
//
// 		const Vector3 freezeRotation = Vector3(
// 			!getConstraint(EConstraints::FreezeRotationX),
// 			!getConstraint(EConstraints::FreezeRotationY),
// 			!getConstraint(EConstraints::FreezeRotationZ));
//
// 		this->rigidBody->setLinearLockAxisFactor(freezePosition);
// 		this->rigidBody->setAngularLockAxisFactor(freezeRotation);
// 	}
// }