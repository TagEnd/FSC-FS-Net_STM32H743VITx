/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include "main.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

void init_styles_1(lv_ui *ui)
{
	lv_style_init(ui->btnm_style);
	lv_style_set_bg_color(ui->btnm_style, lv_palette_main(LV_PALETTE_GREY));
	lv_style_set_bg_grad_color(ui->btnm_style, lv_palette_darken(LV_PALETTE_GREY, 3));
	lv_style_set_bg_grad_dir(ui->btnm_style, LV_GRAD_DIR_VER);
	lv_style_set_border_color(ui->btnm_style, lv_palette_main(LV_PALETTE_GREY));
	lv_style_set_border_width(ui->btnm_style, 2);
}

void setup_scr_screen_1(lv_ui *ui)
{
	// Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_1, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->screen_1, &_back_240x320, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->screen_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_1_cont_1
	ui->screen_1_cont_1 = lv_obj_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_1_cont_1, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_1_cont_1, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen_1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_1_ta_1
	ui->screen_1_ta_1 = lv_textarea_create(ui->screen_1_cont_1);
	lv_textarea_set_text(ui->screen_1_ta_1, "");
	lv_textarea_set_placeholder_text(ui->screen_1_ta_1, "");
	lv_textarea_set_password_bullet(ui->screen_1_ta_1, "*");
	lv_textarea_set_password_mode(ui->screen_1_ta_1, false);
	lv_textarea_set_one_line(ui->screen_1_ta_1, "false");
	lv_textarea_set_accepted_chars(ui->screen_1_ta_1, "");
	lv_textarea_set_max_length(ui->screen_1_ta_1, 32);
	lv_obj_set_pos(ui->screen_1_ta_1, 18, 55);
	lv_obj_set_size(ui->screen_1_ta_1, 200, 28);

	// Write style for screen_1_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_1_ta_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_ta_1, &lv_font_montserratMedium_14, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_ta_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_ta_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_ta_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_ta_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_ta_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_ta_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ta_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for screen_1_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1_ta_1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_ta_1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	// Write codes screen_1_label_1
	ui->screen_1_label_1 = lv_label_create(ui->screen_1_cont_1);
	lv_label_set_text(ui->screen_1_label_1, "Password");
	lv_label_set_long_mode(ui->screen_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_1_label_1, 62, 33);
	lv_obj_set_size(ui->screen_1_label_1, 100, 32);

	// Write style for screen_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_label_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_1_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_1_btn_1
	ui->screen_1_btn_1 = lv_btn_create(ui->screen_1_cont_1);
	ui->screen_1_btn_1_label = lv_label_create(ui->screen_1_btn_1);
	lv_label_set_text(ui->screen_1_btn_1_label, "");
	lv_label_set_long_mode(ui->screen_1_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_1_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_1_btn_1, 10, 10);
	lv_obj_set_size(ui->screen_1_btn_1, 20, 20);

	// Write style for screen_1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_1_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_1_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_btn_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->screen_1_btn_1, &_back_20x20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->screen_1_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_1_btnm_1
	ui->screen_1_btnm_1 = lv_btnmatrix_create(ui->screen_1_cont_1);
	static const char *screen_1_btnm_1_text_map[] = {
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"\n",
		"7",
		"8",
		"9",
		"0",
		"a",
		"b",
		"\n",
		"c",
		"d",
		"e",
		"f",
		"g",
		"h",
		"\n",
		"i",
		"j",
		"k",
		"l",
		"m",
		"n",
		"\n",
		"o",
		"p",
		"q",
		"r",
		"s",
		"t",
		"\n",
		"u",
		"v",
		"w",
		"x",
		"y",
		"z",
		"\n",
		"←",
		"√",
		"",
	};
	lv_btnmatrix_set_map(ui->screen_1_btnm_1, screen_1_btnm_1_text_map);
	lv_obj_set_pos(ui->screen_1_btnm_1, 0, 92);
	lv_obj_set_size(ui->screen_1_btnm_1, 236, 215);

	// Write style for screen_1_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_btnm_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_1_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_1_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_1_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_1_btnm_1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_row(ui->screen_1_btnm_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_column(ui->screen_1_btnm_1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_btnm_1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_btnm_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_btnm_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_btnm_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for screen_1_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_1_btnm_1, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_1_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_1_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_1_btnm_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_1_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_1_btnm_1, &lv_font_montserratMedium_16, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_1_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_1_btnm_1, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_1_btnm_1, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_1_btnm_1, lv_color_hex(0x2195f6), LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_1_btnm_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_1_btnm_1, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);

	// The custom code of screen_1.
	init_styles_1(ui);
	ui->page = PASSWORD_PAGE;
	ui->btn_cnt = 0;
	memset(ui->password_buf, 0, sizeof(ui->password_buf));
	ui->pwd_buf_len = 0;
	memset(ui->password_buf, 1 + '0', 8);
	ui->pwd_buf_len = 8;
	// show_pwd_buf(ui);
	lv_obj_add_style(ui->screen_1_btnm_1, ui->btnm_style, LV_PART_ITEMS | LV_STATE_CHECKED);
	lv_btnmatrix_set_btn_ctrl_all(ui->screen_1_btnm_1, LV_BTNMATRIX_CTRL_CHECKABLE);
	lv_btnmatrix_set_btn_ctrl(ui->screen_1_btnm_1, ui->btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
	// Update current screen layout.
	lv_obj_update_layout(ui->screen_1);

	// Init events for screen.
	events_init_screen_1(ui);
}
