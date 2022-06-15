#include "app_window.h"

int main()
{
	app_window app;
	while (!app.should_close()) {
		app.update();
	}
}