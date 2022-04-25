#include "Gameplay/Components/SimpleObjectController.h"
#include <GLFW/glfw3.h>
#define  GLM_SWIZZLE
#include <GLM/gtc/quaternion.hpp>

#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"
#include "Application/Application.h"

SimpleObjectController::SimpleObjectController() :
	IComponent(),
	_moveSpeeds(glm::vec3(1.0f))
{}


SimpleObjectController::~SimpleObjectController() = default;

void SimpleObjectController::Update(float deltaTime)
{
	if (Application::Get().IsFocused) {

		glm::vec3 _moveVector = glm::vec3(0.0f);

	// up and down is Z axis
	// forward and backwards is y axis
	// left and right is x axis

		if (InputEngine::IsKeyDown(GLFW_KEY_W)) {
			_moveVector.y -= _moveSpeeds.x;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_S)) {
			_moveVector.y += _moveSpeeds.x;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_A)) {
			_moveVector.x -= _moveSpeeds.y;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_D)) {
			_moveVector.x += _moveSpeeds.y;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_LEFT_CONTROL)) {
			_moveVector.y -= _moveSpeeds.z;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_SPACE)) {
			_moveVector.y += _moveSpeeds.z; 
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			_moveVector += 3.0f;
		}

		_moveVector *= deltaTime;

		GetGameObject()->SetPostion(GetGameObject()->GetPosition() + _moveVector);
	}

}


void SimpleObjectController::RenderImGui()
{

}

nlohmann::json SimpleObjectController::ToJson() const {
	return nlohmann::json();
}

SimpleObjectController::Sptr SimpleObjectController::FromJson(const nlohmann::json& blob) {
	return SimpleObjectController::Sptr();
}

