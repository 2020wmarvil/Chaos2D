#include "ch2pch.h"

#include "Application.h"

#include "Log.h"

#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Events/ApplicationEvent.h"

namespace Chaos2D {
	Application::Application() { }
	Application::~Application() { }

	void Application::Run() {
		WindowResizeEvent resize(100, 200);
		CH2_TRACE(resize);
		WindowMovedEvent moved(300, 400);
		CH2_TRACE(moved);

		KeyPressedEvent pressed(0, 5);
		CH2_TRACE(pressed);
		KeyReleasedEvent released(1);
		CH2_TRACE(released);

		MouseButtonPressedEvent mPress(10);
		CH2_TRACE(mPress);
		MouseButtonReleasedEvent mRelease(12);
		CH2_TRACE(mRelease);

		MouseMovedEvent mMove(50, 60);
		CH2_TRACE(mMove);
		MouseScrolledEvent mScroll(70, 80);
		CH2_TRACE(mScroll);

		while (true);
	}
}
