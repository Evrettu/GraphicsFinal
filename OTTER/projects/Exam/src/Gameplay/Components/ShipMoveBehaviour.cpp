#include "ShipMoveBehaviour.h"

#include "Gameplay/GameObject.h"

#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"
#include "GLM/gtc/quaternion.hpp"

void ShipMoveBehaviour::Awake()
{
	_body = GetComponent<Gameplay::Physics::RigidBody>();
	if (_body == nullptr) {
		IsEnabled = false;
	}
}

ShipMoveBehaviour::ShipMoveBehaviour() :
	IComponent(),
	_impulse(10.0f)
{ }

ShipMoveBehaviour::~ShipMoveBehaviour() = default;

void ShipMoveBehaviour::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat, "Impulse", &_impulse, 1.0f);
}

nlohmann::json ShipMoveBehaviour::ToJson() const {
	return {
		{ "impulse", _impulse }
	};
}

ShipMoveBehaviour::Sptr ShipMoveBehaviour::FromJson(const nlohmann::json & blob) {
	ShipMoveBehaviour::Sptr result = std::make_shared<ShipMoveBehaviour>();
	result->_impulse = blob["impulse"];
	return result;
}

void ShipMoveBehaviour::Update(float deltaTime) 
{
	if (Swap == true)
	{
		_body->SetLinearVelocity(glm::vec3(_impulse * -1.0f, 0.0f, 0.0f));

		if (deltaTime >= time)
		{
			Swap = false;
			time = (deltaTime + 2.0f);

			_body->SetLinearVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
		}
	}

	if (Swap == false)
	{
		_body->SetLinearVelocity(glm::vec3(_impulse, 0.0f, 0.0f));

		if (deltaTime >= time)
		{
			Swap = true;
			time = (deltaTime + 2.0f);

			_body->SetLinearVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
		}
	}
}