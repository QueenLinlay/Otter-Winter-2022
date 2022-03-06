#pragma once
#include "IComponent.h"

struct GLFWwindow;

/// <summary>
/// A simple behaviour that allows movement of a gameobject with WASD, mouse,
/// and ctrl + space
/// </summary>
class SimpleObjectController : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<SimpleObjectController> Sptr;

	SimpleObjectController();
	virtual ~SimpleObjectController();

	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(SimpleObjectController);
	virtual nlohmann::json ToJson() const override;
	static SimpleObjectController::Sptr FromJson(const nlohmann::json& blob);

protected:
	glm::vec3 _moveSpeeds;
};