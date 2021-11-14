#include <Chaos2D.h>

class Sandbox : public Chaos2D::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Chaos2D::Application* Chaos2D::CreateApplication() {
	return new Sandbox();
}
