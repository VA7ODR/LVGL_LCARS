//
// Created by jim on 26/06/25.
//

#include "UI.hpp"
#include <SDL3/SDL.h>
#include <vector>

const int SDL_WINDOW_WIDTH = 1024;
const int SDL_WINDOW_HEIGHT = 576;
extern const lv_font_t antonio_22;
extern const lv_font_t antonio_24;
extern const lv_font_t antonio_28;
extern const lv_font_t antonio_32;
extern const lv_font_t antonio_36;
extern const lv_font_t antonio_48;
extern const lv_font_t antonio_96;
extern const lv_font_t antonio_bold_22;
extern const lv_font_t antonio_bold_24;
extern const lv_font_t antonio_bold_28;
extern const lv_font_t antonio_bold_32;
extern const lv_font_t antonio_bold_36;
extern const lv_font_t antonio_bold_48;
extern const lv_font_t antonio_bold_96;

const lv_color_t colour_black = lv_color_hex(0x000000);
const lv_color_t colour_white = lv_color_hex(0xffffff);
const lv_color_t colour_african_violet = lv_color_hex(0xcc99ff);
const lv_color_t colour_almond = lv_color_hex(0xffaa90);
const lv_color_t colour_almond_creme = lv_color_hex(0xffbbaa);
const lv_color_t colour_blue = lv_color_hex(0x5566ff);
const lv_color_t colour_bluey = lv_color_hex(0x8899ff);
const lv_color_t colour_butterscotch = lv_color_hex(0xff9966);
const lv_color_t colour_gold = lv_color_hex(0xffaa00);
const lv_color_t colour_gold_orange = lv_color_hex(0xff9900);
const lv_color_t colour_grey = lv_color_hex(0x666688);
const lv_color_t colour_green = lv_color_hex(0x999933);
const lv_color_t colour_ice = lv_color_hex(0x99ccff);
const lv_color_t colour_lilac = lv_color_hex(0xcc55ff);
const lv_color_t colour_lima_bean = lv_color_hex(0xcccc66);
const lv_color_t colour_magenta = lv_color_hex(0xcc5599);
const lv_color_t colour_mars = lv_color_hex(0xff2200);
const lv_color_t colour_moonlit_violet = lv_color_hex(0x9966ff);
const lv_color_t colour_orange = lv_color_hex(0xff8800);
const lv_color_t colour_peach = lv_color_hex(0xff8866);
const lv_color_t colour_red = lv_color_hex(0xcc4444);
const lv_color_t colour_sky = lv_color_hex(0xaaaaff);
const lv_color_t colour_space_white = lv_color_hex(0xf5f6fa);
const lv_color_t colour_sunflower = lv_color_hex(0xffcc99);
const lv_color_t colour_tomato = lv_color_hex(0xff5555);
const lv_color_t colour_violet_creme = lv_color_hex(0xddbbff);

const lv_color_t colour_left_frame_top = colour_bluey;
const lv_color_t colour_left_frame = colour_red;
const lv_color_t colour_corner_top = colour_left_frame_top;
const lv_color_t colour_corner_bottom = colour_left_frame;

const lv_color_t colour_panel_1 = colour_african_violet;
const lv_color_t colour_panel_4 = colour_red;
const lv_color_t colour_panel_5 = colour_orange;
const lv_color_t colour_panel_6 = colour_butterscotch;
const lv_color_t colour_panel_7 = colour_bluey;
const lv_color_t colour_panel_8 = colour_butterscotch;
const lv_color_t colour_panel_10 = colour_orange;
const lv_color_t colour_panel_top_button = colour_african_violet;

const int bar_height = 28;
const int bar_1_6_width = LV_PCT(40);
const int bar_2_7_width = LV_PCT(4);
const int bar_3_8_width = LV_PCT(17);
const int bar_5_10_width = LV_PCT(4);
const lv_color_t colour_bar_1 = colour_bluey;
const lv_color_t colour_bar_2 = colour_orange;
const lv_color_t colour_bar_3 = colour_african_violet;
const lv_color_t colour_bar_4 = colour_african_violet;
const lv_color_t colour_bar_5 = colour_red;
const lv_color_t colour_bar_6 = colour_red;
const lv_color_t colour_bar_7 = colour_butterscotch;
const lv_color_t colour_bar_8 = colour_red;
const lv_color_t colour_bar_9 = colour_african_violet;
const lv_color_t colour_bar_10 = colour_butterscotch;

const lv_color_t colour_section_2 = colour_almond_creme;
const lv_color_t colour_pill_1 = colour_red;
const lv_color_t colour_pill_2 = colour_butterscotch;
const lv_color_t colour_pill_3 = colour_bluey;
const lv_color_t colour_pill_4 = colour_almond_creme;
const lv_color_t colour_pill_5 = colour_orange;
const lv_color_t colour_pill_6 = colour_moonlit_violet;
const lv_color_t colour_pill_a1 = colour_moonlit_violet;
const lv_color_t colour_pill_a2 = colour_moonlit_violet;
const lv_color_t colour_pill_a3 = colour_black;
const lv_color_t colour_pill_a4 = colour_african_violet;
const lv_color_t colour_pill_a5 = colour_orange;
const lv_color_t colour_pill_a6 = colour_almond_creme;
const lv_color_t colour_panel_11 = colour_red;
const lv_color_t colour_panel_12 = colour_bluey;
const lv_color_t colour_panel_13 = colour_almond_creme;
const lv_color_t colour_panel_14 = colour_almond_creme;
const lv_color_t colour_panel_15 = colour_almond_creme;

const lv_color_t & pill_colour(size_t index)
{
	static const std::vector<const lv_color_t *>list =
			{
				&colour_pill_1,
				&colour_pill_2,
				&colour_pill_3,
				&colour_pill_4,
				&colour_pill_5,
				&colour_pill_6,
			};
	return *list[index % list.size()];
}

lv_obj_t * UI::create_pill(lv_obj_t * parent, const std::string & szLabel, const lv_color_t & colour)
{
	auto * button = lv_button_create(parent);
	auto * label = lv_label_create(button);

	lv_obj_add_style(button, &styleButton, 0);
	lv_label_set_text(label, "Hello world");
	lv_obj_set_style_bg_color(button, colour, 0);
	lv_obj_set_style_align(label, LV_ALIGN_BOTTOM_RIGHT, 0);
	return button;
}

UI::UI()
{
	lv_init();

	sdlDisplay = lv_sdl_window_create(SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT);

	sdlMouse = lv_sdl_mouse_create();
	sdlMouseWheel = lv_sdl_mousewheel_create();
	sdlKayboard = lv_sdl_keyboard_create();

	auto * scr1 = lv_screen_active();
	lv_obj_set_style_bg_color(scr1, lv_color_hex(0), LV_PART_MAIN);
	lv_obj_set_scrollbar_mode(scr1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_remove_flag(scr1, LV_OBJ_FLAG_SCROLLABLE);

	lv_style_init(&styleButton);
	lv_style_set_bg_opa(&styleButton, LV_OPA_COVER);
	lv_style_set_border_width(&styleButton, 0);
	lv_style_set_radius(&styleButton, LV_RADIUS_CIRCLE);
	lv_style_set_shadow_width(&styleButton, 0);
	lv_style_set_width(&styleButton, 224);
	lv_style_set_height(&styleButton, 80);
	lv_style_set_text_font(&styleButton, &antonio_bold_22);
	lv_style_set_text_color(&styleButton, colour_black);
	lv_style_set_align(&styleButton, LV_ALIGN_TOP_RIGHT);
	lv_style_set_text_align(&styleButton, LV_TEXT_ALIGN_RIGHT);

	lv_style_init(&styleTopBack);
	lv_style_set_bg_color(&styleTopBack, colour_sky);
	lv_style_set_width(&styleTopBack, LV_PCT(100) + 260);
	lv_style_set_height(&styleTopBack, 2160);
	lv_style_set_align(&styleTopBack, LV_ALIGN_BOTTOM_LEFT);
	lv_style_set_bg_opa(&styleTopBack, LV_OPA_COVER);
	lv_style_set_border_width(&styleTopBack, 0);
	lv_style_set_shadow_width(&styleTopBack, 0);
	lv_style_set_radius(&styleTopBack, 130);
	lv_style_set_margin_all(&styleTopBack, 0);

	topBG = lv_obj_create(scr1);
	lv_obj_add_style(topBG, &styleTopBack, 0);

	lv_style_init(&styleTop);
	lv_style_set_bg_color(&styleTop, colour_black);
	lv_style_set_width(&styleTop, LV_PCT(100));
	lv_style_set_height(&styleTop, 2160);
	lv_style_set_align(&styleTop, LV_ALIGN_BOTTOM_LEFT);
	lv_style_set_bg_opa(&styleTop, LV_OPA_COVER);
	lv_style_set_border_width(&styleTop, 0);
	lv_style_set_shadow_width(&styleTop, 0);
	lv_style_set_radius(&styleTop, 80);
	lv_style_set_margin_all(&styleTop, 0);

	topBlackout = lv_obj_create(scr1);
	lv_obj_add_style(topBlackout, &styleTop, 0);

	lv_style_init(&styleTopHolder);
	lv_style_set_align(&styleTopHolder, LV_ALIGN_TOP_LEFT);
	lv_style_set_bg_opa(&styleTopHolder, LV_OPA_TRANSP);
	lv_style_set_height(&styleTopHolder, LV_SIZE_CONTENT);
	lv_style_set_width(&styleTopHolder, LV_PCT(100));
	lv_style_set_border_width(&styleTopHolder, 2);
	lv_style_set_radius(&styleTopHolder, 0);
	lv_style_set_pad_all(&styleTopHolder, 0);

	topHolder = lv_obj_create(scr1);
	lv_obj_add_style(topHolder, &styleTopHolder, 0);
//	lv_obj_set_scrollbar_mode(topHolder, LV_SCROLLBAR_MODE_OFF);
//	lv_obj_remove_flag(topHolder, LV_OBJ_FLAG_SCROLLABLE);

	lv_style_init(&styleTitle);
	lv_style_set_bg_opa(&styleTitle, LV_OPA_TRANSP);
	lv_style_set_text_color(&styleTitle, colour_orange);
	lv_style_set_text_font(&styleTitle, &antonio_96);
	lv_style_set_text_align(&styleTitle, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_align(&styleTitle, LV_ALIGN_TOP_RIGHT);
	lv_style_set_pad_right(&styleTitle, 24);
	lv_style_set_margin_bottom(&styleTitle, 24);

	title = lv_label_create(topHolder);
	lv_label_set_text(title, "LCARS • 123456");
	lv_obj_add_style(title, &styleTitle, 0);
	lv_obj_set_align(title, LV_ALIGN_TOP_RIGHT);

	lv_style_init(&stylePillBox);
	lv_style_set_align(&stylePillBox, LV_ALIGN_TOP_RIGHT);
	lv_style_set_bg_opa(&stylePillBox, LV_OPA_TRANSP);
	lv_style_set_pad_all(&stylePillBox, 0);
	lv_style_set_height(&stylePillBox, LV_SIZE_CONTENT);
	lv_style_set_width(&stylePillBox, 224 * 2 + 44);
	lv_style_set_translate_y(&stylePillBox, 120);
	lv_style_set_flex_flow(&stylePillBox, LV_FLEX_FLOW_ROW_WRAP);
	lv_style_set_flex_main_place(&stylePillBox, LV_FLEX_ALIGN_END);
	lv_style_set_layout(&stylePillBox, LV_LAYOUT_FLEX);
	lv_style_set_margin_bottom(&stylePillBox, 44);
	lv_style_set_pad_right(&stylePillBox, 24);
	lv_style_set_border_width(&stylePillBox, 0);

	pillBox = lv_obj_create(topHolder);
	lv_obj_add_style(pillBox, &stylePillBox, 0);

	size_t buttonIndex = 0;
	auto * button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));
	button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));
	button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));
	button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));
	button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));
	button = create_pill(pillBox, "Hello world", pill_colour(buttonIndex++));

	lv_obj_align_to(topBG, topHolder, LV_ALIGN_BOTTOM_LEFT, 0, 0);
	lv_obj_align_to(topBlackout, topHolder, LV_ALIGN_BOTTOM_LEFT, 224, -20);

}

int UI::Run()
{
	Uint32 lastTick = SDL_GetTicks();
	while(true) {
		SDL_Delay(5);
		Uint32 current = SDL_GetTicks();
		lv_tick_inc(current - lastTick); // Update the tick timer. Tick is new for LVGL 9
		lastTick = current;
		lv_timer_handler(); // Update the UI-
	}
}
