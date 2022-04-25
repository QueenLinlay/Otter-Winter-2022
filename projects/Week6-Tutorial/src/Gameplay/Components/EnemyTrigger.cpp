#include "Gameplay/Components/EnemyTrigger.h"
#include "Gameplay/Components/ComponentManager.h"
#include "Gameplay/GameObject.h"


EnemyTrigger::EnemyTrigger() :
	IComponent()
{ }
EnemyTrigger::~EnemyTrigger() = default;

void EnemyTrigger::OnTriggerVolumeEntered(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger)
{
		std::cout << "You Lost!!" << std::endl;
		std::cout << "Game have Reset!!" << std::endl;
		trigger->GetGameObject()->SetPostion(glm::vec3(4.0f, 0.0f, 3.0f));
}

void EnemyTrigger::OnTriggerVolumeLeaving(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger) 
{
	
}

void EnemyTrigger::RenderImGui() { }

nlohmann::json EnemyTrigger::ToJson() const {
	return { };
}

EnemyTrigger::Sptr EnemyTrigger::FromJson(const nlohmann::json & blob) {
	EnemyTrigger::Sptr result = std::make_shared<EnemyTrigger>();
	return result;
}