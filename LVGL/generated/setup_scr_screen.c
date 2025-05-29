/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

static lv_style_t style_focused;
extern char wifi_info[10][33];

void init_styles(void)
{
	lv_style_init(&style_focused);
	lv_style_set_bg_color(&style_focused, lv_palette_main(LV_PALETTE_BLUE));
	lv_style_set_border_color(&style_focused, lv_palette_main(LV_PALETTE_BLUE));
	lv_style_set_border_width(&style_focused, 2);
}

void setup_scr_screen(lv_ui *ui)
{
	// Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_cont_1
	ui->screen_cont_1 = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_cont_1, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_1);
	lv_label_set_text(ui->screen_label_1, "WLAN");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 12, 12);
	lv_obj_set_size(ui->screen_label_1, 83, 23);

	// Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_line_1
	ui->screen_line_1 = lv_line_create(ui->screen_cont_1);
	static lv_point_t screen_line_1[] = {
		{0, 0},
		{210, 0},
	};
	lv_line_set_points(ui->screen_line_1, screen_line_1, 2);
	lv_obj_set_pos(ui->screen_line_1, 10, 44);
	lv_obj_set_size(ui->screen_line_1, 215, 3);

	// Write style for screen_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->screen_line_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->screen_line_1, lv_color_hex(0x757575), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->screen_line_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->screen_line_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_list_1
	ui->screen_list_1 = lv_list_create(ui->screen_cont_1);
	ui->screen_list_1_item0 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[0]);
	ui->screen_list_1_item1 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[1]);
	ui->screen_list_1_item2 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[2]);
	ui->screen_list_1_item3 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[3]);
	ui->screen_list_1_item4 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[4]);
	ui->screen_list_1_item5 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[5]);
	ui->screen_list_1_item6 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[6]);
	ui->screen_list_1_item7 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[7]);
	ui->screen_list_1_item8 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[8]);
	ui->screen_list_1_item9 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_WIFI, wifi_info[9]);
	lv_obj_set_pos(ui->screen_list_1, 8, 44);
	lv_obj_set_size(ui->screen_list_1, 212, 266);
	lv_obj_set_scrollbar_mode(ui->screen_list_1, LV_SCROLLBAR_MODE_AUTO);
	if (wifi_info[0][0] == '\0')
	{
		for (uint8_t i = 0; i < 10; i++)
		{
			lv_obj_t *list_btn = lv_obj_get_child(ui->screen_list_1, i);
			lv_obj_add_flag(list_btn, LV_OBJ_FLAG_HIDDEN);
		}
	}

	// Write style state: LV_STATE_DEFAULT for &style_screen_list_1_main_main_default
	static lv_style_t style_screen_list_1_main_main_default;
	ui_init_style(&style_screen_list_1_main_main_default);

	lv_style_set_pad_top(&style_screen_list_1_main_main_default, 5);
	lv_style_set_pad_left(&style_screen_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_screen_list_1_main_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_list_1_main_main_default, 5);
	lv_style_set_bg_opa(&style_screen_list_1_main_main_default, 255);
	lv_style_set_bg_color(&style_screen_list_1_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_list_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_screen_list_1_main_main_default, 1);
	lv_style_set_border_opa(&style_screen_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_screen_list_1_main_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_list_1_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_list_1_main_main_default, 3);
	lv_style_set_shadow_width(&style_screen_list_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_list_1, &style_screen_list_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for &style_screen_list_1_main_scrollbar_default
	static lv_style_t style_screen_list_1_main_scrollbar_default;
	ui_init_style(&style_screen_list_1_main_scrollbar_default);

	lv_style_set_radius(&style_screen_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_list_1, &style_screen_list_1_main_scrollbar_default, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for &style_screen_list_1_extra_btns_main_default
	static lv_style_t style_screen_list_1_extra_btns_main_default;
	ui_init_style(&style_screen_list_1_extra_btns_main_default);

	lv_style_set_pad_top(&style_screen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_screen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_screen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_screen_list_1_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_screen_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_list_1_extra_btns_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_opa(&style_screen_list_1_extra_btns_main_default, 255);
	lv_style_set_radius(&style_screen_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_screen_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_list_1_item9, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item8, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item7, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item6, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item5, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item4, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item3, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item2, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item1, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item0, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for &style_screen_list_1_extra_texts_main_default
	static lv_style_t style_screen_list_1_extra_texts_main_default;
	ui_init_style(&style_screen_list_1_extra_texts_main_default);

	lv_style_set_pad_top(&style_screen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_screen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_screen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_screen_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_screen_list_1_extra_texts_main_default, lv_color_hex(0x2F92DA));
	lv_style_set_text_font(&style_screen_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_list_1_extra_texts_main_default, 255);
	lv_style_set_radius(&style_screen_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_screen_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_screen_list_1_extra_texts_main_default, lv_color_hex(0x2FDAAE));
	lv_style_set_bg_grad_dir(&style_screen_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

	// Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen_cont_1);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
	lv_label_set_text(ui->screen_btn_1_label, "");
	lv_label_set_long_mode(ui->screen_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_btn_1, 187, 12);
	lv_obj_set_size(ui->screen_btn_1, 20, 20);

	// Write style for screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->screen_btn_1, &_F5_20x20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->screen_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

	// The custom code of screen.
	static uint8_t wifi_page_cnt = 0;
	init_styles();
	ui->page = WIFI_PAGE;
	if (wifi_page_cnt == 0)
	{
		ui->group = lv_group_create();
		wifi_page_cnt++;
	}
	memset(ui->ssid_buf, 0, sizeof(ui->ssid_buf));
	ui->ssid_buf_len = 0;
	lv_group_set_default(ui->group);
	lv_obj_add_style(ui->screen_list_1_item0, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item1, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item2, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item3, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item4, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item5, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item6, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item7, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item8, &style_focused, LV_STATE_FOCUSED);
	lv_obj_add_style(ui->screen_list_1_item9, &style_focused, LV_STATE_FOCUSED);

	lv_group_add_obj(ui->group, ui->screen_list_1_item0);
	lv_group_add_obj(ui->group, ui->screen_list_1_item1);
	lv_group_add_obj(ui->group, ui->screen_list_1_item2);
	lv_group_add_obj(ui->group, ui->screen_list_1_item3);
	lv_group_add_obj(ui->group, ui->screen_list_1_item4);
	lv_group_add_obj(ui->group, ui->screen_list_1_item5);
	lv_group_add_obj(ui->group, ui->screen_list_1_item6);
	lv_group_add_obj(ui->group, ui->screen_list_1_item7);
	lv_group_add_obj(ui->group, ui->screen_list_1_item8);
	lv_group_add_obj(ui->group, ui->screen_list_1_item9);
	lv_group_focus_obj(ui->screen_list_1_item0);
	// Update current screen layout.
	lv_obj_update_layout(ui->screen);

	// Init events for screen.
	events_init_screen(ui);
}

void add_item_focus(lv_ui *ui)
{
	lv_group_focus_next(ui->group);
}
