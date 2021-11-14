#pragma once

#ifdef CH2_PLATFORM_WINDOWS

extern Chaos2D::Application* Chaos2D::CreateApplication();

int main(int argc, char** argv) {
	Chaos2D::Log::Init();
	CH2_CORE_WARN("Logging initialized");
	CH2_INFO("hi");

	auto app = Chaos2D::CreateApplication();
	app->Run();
	delete app;
}

#endif
