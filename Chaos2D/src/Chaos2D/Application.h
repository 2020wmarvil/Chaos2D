#pragma once

#include "Core.h"

namespace Chaos2D {
	class CHAOS2D_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
