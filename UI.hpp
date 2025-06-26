//
// Created by jim on 26/06/25.
//

#pragma once
#include "lvgl.h"
#include <string>

class UI
{
	public:
		UI();
		lv_obj_t * create_pill(lv_obj_t * parent, const std::string & szLabel, const lv_color_t & colour);

		static int Run();
	private:
		lv_display_t * sdlDisplay = nullptr;
		lv_indev_t * sdlMouse = nullptr;
		lv_indev_t * sdlMouseWheel = nullptr;
		lv_indev_t * sdlKayboard = nullptr;

		lv_style_t styleButton{};
		lv_style_t styleTopBack{};
		lv_style_t styleTopHolder{};
		lv_style_t styleTop{};
		lv_style_t styleTitle{};
		lv_style_t stylePillBox{};

		lv_obj_t * topHolder = nullptr;
		lv_obj_t * topBG = nullptr;
		lv_obj_t * topBlackout = nullptr;
		lv_obj_t * title = nullptr;
		lv_obj_t * pillBox = nullptr;
};
