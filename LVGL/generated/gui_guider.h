/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

	typedef enum
	{
		WIFI_PAGE,
		PASSWORD_PAGE,
		CONNECTED_PAGE,
	} LV_PAGE;

	typedef struct
	{

		lv_obj_t *screen;
		bool screen_del;
		lv_obj_t *screen_cont_1;
		lv_obj_t *screen_label_1;
		lv_obj_t *screen_line_1;
		lv_obj_t *screen_list_1;
		lv_obj_t *screen_list_1_item0;
		lv_obj_t *screen_list_1_item1;
		lv_obj_t *screen_list_1_item2;
		lv_obj_t *screen_list_1_item3;
		lv_obj_t *screen_list_1_item4;
		lv_obj_t *screen_list_1_item5;
		lv_obj_t *screen_list_1_item6;
		lv_obj_t *screen_list_1_item7;
		lv_obj_t *screen_list_1_item8;
		lv_obj_t *screen_list_1_item9;
		lv_obj_t *screen_btn_1;
		lv_obj_t *screen_btn_1_label;
		lv_obj_t *screen_1;
		bool screen_1_del;
		lv_obj_t *screen_1_cont_1;
		lv_obj_t *screen_1_ta_1;
		lv_obj_t *screen_1_label_1;
		lv_obj_t *screen_1_btn_1;
		lv_obj_t *screen_1_btn_1_label;
		lv_obj_t *screen_1_btnm_1;
		lv_obj_t *screen_2;
		bool screen_2_del;
		lv_obj_t *screen_2_cont_1;
		lv_obj_t *screen_2_label_1;
		lv_obj_t *screen_2_label_2;
		lv_obj_t *screen_2_btn_1;
		lv_obj_t *screen_2_btn_1_label;
		lv_obj_t *screen_2_label_3;
		lv_obj_t *screen_2_label_4;
		lv_obj_t *screen_2_label_5;
		char password_buf[30];
		uint8_t pwd_buf_len;
		char ssid_buf[33];
		char ip_buf[20];
		uint8_t ssid_buf_len;
		lv_group_t *group;
		LV_PAGE page;
		uint16_t btn_cnt;
		lv_style_t *btnm_style;
	} lv_ui;

	typedef void (*ui_setup_scr_t)(lv_ui *ui);

	void ui_init_style(lv_style_t *style);

	void ui_load_scr_animation(lv_ui *ui, lv_obj_t **new_scr, bool new_scr_del, bool *old_scr_del, ui_setup_scr_t setup_scr,
							   lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

	void ui_move_animation(void *var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
						   uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
						   lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void ui_scale_animation(void *var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
							uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
							lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void ui_img_zoom_animation(void *var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
							   uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
							   lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void ui_img_rotate_animation(void *var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
								 lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
								 uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void init_scr_del_flag(lv_ui *ui);

	void setup_ui(lv_ui *ui);

	void setup_ui_1(lv_ui *ui);

	void add_password_buf(lv_ui *ui, char element);

	void remove_password_buf(lv_ui *ui);

	void show_pwd_buf(lv_ui *ui);

	extern lv_ui guider_ui;

	void setup_scr_screen(lv_ui *ui);

	void setup_scr_screen_1(lv_ui *ui);

	void setup_scr_screen_2(lv_ui *ui);

	void add_item_focus(lv_ui *ui);

	void init_styles(void);

	void init_styles_1(lv_ui *ui);

	LV_IMG_DECLARE(_F5_20x20);

	LV_IMG_DECLARE(_back_240x320);

	LV_IMG_DECLARE(_back_20x20);

	LV_IMG_DECLARE(_off_240x320);

	LV_IMG_DECLARE(_off_20x20);

	LV_FONT_DECLARE(lv_font_montserratMedium_20)
	LV_FONT_DECLARE(lv_font_montserratMedium_16)
	LV_FONT_DECLARE(lv_font_montserratMedium_12)
	LV_FONT_DECLARE(lv_font_montserratMedium_14)

#ifdef __cplusplus
}
#endif
#endif
