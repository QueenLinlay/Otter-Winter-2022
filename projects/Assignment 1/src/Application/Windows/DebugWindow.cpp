#include "DebugWindow.h"
#include "Application/Application.h"
#include "Application/ApplicationLayer.h"
#include "Application/Layers/RenderLayer.h"

DebugWindow::DebugWindow() :
	IEditorWindow()
{
	Name = "Debug";
	SplitDirection = ImGuiDir_::ImGuiDir_None;
	SplitDepth = 0.5f;
	Requirements = EditorWindowRequirements::Menubar;
}

DebugWindow::~DebugWindow() = default;

void DebugWindow::RenderMenuBar() 
{
	Application& app = Application::Get();
	RenderLayer::Sptr renderLayer = app.GetLayer<RenderLayer>();

	BulletDebugMode physicsDrawMode = app.CurrentScene()->GetPhysicsDebugDrawMode();
	if (BulletDebugDraw::DrawModeGui("Physics Debug Mode:", physicsDrawMode)) {
		app.CurrentScene()->SetPhysicsDebugDrawMode(physicsDrawMode);
	}

	ImGui::Separator();

	RenderFlags flags = renderLayer->GetRenderFlags();
	bool changed = false;

	
	bool Ctemp = *(flags & RenderFlags::CoolColorCorrection);
	bool Wtemp = *(flags & RenderFlags::WarmColorCorrection);
	bool Customtemp = *(flags & RenderFlags::CustomColorCorrection);

	if (ImGui::Checkbox("Cool Color Correction", &Ctemp)) {
		changed = true;
		flags = (flags & ~*RenderFlags::CoolColorCorrection) | (Ctemp ? RenderFlags::CoolColorCorrection : RenderFlags::None);
	}

	if (ImGui::Checkbox("Warm Color Correction", &Wtemp)) {
		changed = true;
		flags = (flags & ~*RenderFlags::WarmColorCorrection) | (Wtemp ? RenderFlags::WarmColorCorrection : RenderFlags::None);
	}

	if (ImGui::Checkbox("Custom Color Correction", &Customtemp)) {
		changed = true;
		flags = (flags & ~*RenderFlags::CustomColorCorrection) | (Customtemp ? RenderFlags::CustomColorCorrection : RenderFlags::None);
	}


	if (changed) {
		renderLayer->SetRenderFlags(flags);
	}
}
