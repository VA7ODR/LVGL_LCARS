#include <iostream>
#include <SDL3/SDL.h>
#include "UI.hpp"
#include <drivers/sdl/lv_sdl_window.h>

int main()
{
	UI ui;

	return ui.Run();

}
