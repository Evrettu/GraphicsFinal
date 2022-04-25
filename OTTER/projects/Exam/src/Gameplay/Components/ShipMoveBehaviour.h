#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"

/// <summary>
/// A simple behaviour that applies an impulse along the Z axis to the 
/// rigidbody of the parent when the space key is pressed
/// </summary>
class ShipMoveBehaviour : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<ShipMoveBehaviour> Sptr;
	
	float _impulse;
	Gameplay::Physics::RigidBody::Sptr _body;

	ShipMoveBehaviour();
	virtual ~ShipMoveBehaviour();

	virtual void Update(float deltaTime) override;
	virtual void Awake() override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(ShipMoveBehaviour);
	virtual nlohmann::json ToJson() const override;
	static ShipMoveBehaviour::Sptr FromJson(const nlohmann::json& blob);

protected:
	bool	Swap = true;
	float time = 0;
};