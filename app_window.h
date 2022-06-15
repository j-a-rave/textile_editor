#pragma once

#include "imgui_impl_glfw.h"
#include <string>

class app_window {
	GLFWwindow* window;

public:
	app_window();
	app_window(std::string title);
	~app_window();

	void update();
	bool should_close();
};