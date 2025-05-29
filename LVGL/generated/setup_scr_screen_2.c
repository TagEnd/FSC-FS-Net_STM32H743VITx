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

void setup_scr_screen_2(lv_ui *ui)
{
	// Write codes screen_2
	ui->screen_2 = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_2, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_2, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->screen_2, &_off_240x320, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->screen_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_cont_1
	ui->screen_2_cont_1 = lv_obj_create(ui->screen_2);
	lv_obj_set_pos(ui->screen_2_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_2_cont_1, 240, 320);
	lv_obj_set_scrollbar_mode(ui->screen_2_cont_1, LV_SCROLLBAR_MODE_OFF);

	// Write style for screen_2_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_cont_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_2_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_2_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_2_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_cont_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_2_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_2_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_cont_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_label_1
	ui->screen_2_label_1 = lv_label_create(ui->screen_2_cont_1);
	lv_label_set_text(ui->screen_2_label_1, "");
	lv_label_set_long_mode(ui->screen_2_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_1, 6, 50);
	lv_obj_set_size(ui->screen_2_label_1, 68, 20);

	// Write style for screen_2_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_label_2
	ui->screen_2_label_2 = lv_label_create(ui->screen_2_cont_1);
	lv_label_set_text(ui->screen_2_label_2, "");
	lv_label_set_long_mode(ui->screen_2_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_2, 44, 50);
	lv_obj_set_size(ui->screen_2_label_2, 178, 20);

	// Write style for screen_2_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_btn_1
	ui->screen_2_btn_1 = lv_btn_create(ui->screen_2_cont_1);
	ui->screen_2_btn_1_label = lv_label_create(ui->screen_2_btn_1);
	lv_label_set_text(ui->screen_2_btn_1_label, "");
	lv_label_set_long_mode(ui->screen_2_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_2_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_2_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_2_btn_1, 18, 14);
	lv_obj_set_size(ui->screen_2_btn_1, 20, 20);

	// Write style for screen_2_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_2_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_2_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_2_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_2_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_btn_1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->screen_2_btn_1, &_off_20x20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->screen_2_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_label_3
	ui->screen_2_label_3 = lv_label_create(ui->screen_2_cont_1);
	lv_label_set_text(ui->screen_2_label_3, "");
	lv_label_set_long_mode(ui->screen_2_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_3, 6, 96);
	lv_obj_set_size(ui->screen_2_label_3, 78, 20);

	// Write style for screen_2_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_label_4
	ui->screen_2_label_4 = lv_label_create(ui->screen_2_cont_1);
	lv_label_set_text(ui->screen_2_label_4, "");
	lv_label_set_long_mode(ui->screen_2_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_4, 112, 96);
	lv_obj_set_size(ui->screen_2_label_4, 90, 20);

	// Write style for screen_2_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes screen_2_label_5
	ui->screen_2_label_5 = lv_label_create(ui->screen_2_cont_1);
	lv_label_set_text(ui->screen_2_label_5, "");
	lv_label_set_long_mode(ui->screen_2_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_2_label_5, 15, 125);
	lv_obj_set_size(ui->screen_2_label_5, 206, 32);

	// Write style for screen_2_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_2_label_5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_2_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_2_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_2_label_5, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_2_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// The custom code of screen_2.

	// Update current screen layout.
	lv_obj_update_layout(ui->screen_2);
}
