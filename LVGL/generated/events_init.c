/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_list_1_item0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_list_1_item1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_list_1_item2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_list_1_item3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_list_1_item4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void screen_list_1_item5_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_list_1_item0, screen_list_1_item0_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_list_1_item1, screen_list_1_item1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_list_1_item2, screen_list_1_item2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_list_1_item3, screen_list_1_item3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_list_1_item4, screen_list_1_item4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_list_1_item5, screen_list_1_item5_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_1_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_1_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
		break;
	}
	default:
		break;
	}
}
static void screen_1_btnm_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		uint32_t id = lv_btnmatrix_get_selected_btn(obj);
		switch(id) {
		case 0:
		{
			
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_1_btn_1, screen_1_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_1_btnm_1, screen_1_btnm_1_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
