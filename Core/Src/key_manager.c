#include "key.h"
#include "spi.h"
#include "gui_guider.h"
#include "tasks.h"
#include <string.h>

void key_manager_init(void)
{
    update_key_event();
}

void Add_item_focus(void)
{
    add_item_focus(&guider_ui);
}

char *get_focused_item_text(void)
{
    lv_obj_t *focused_btn = lv_group_get_focused(guider_ui.group);
    char *text = lv_list_get_btn_text(guider_ui.screen_list_1, focused_btn);
    return text;
}

void Navigation_to_pwd(void)
{
    char *text = get_focused_item_text();
    for (uint8_t i = 0; i < strlen(text); i++)
    {
        guider_ui.ssid_buf[guider_ui.ssid_buf_len] = text[i];
        guider_ui.ssid_buf_len++;
    }
    reset_keyevent();
    guider_ui.page = PASSWORD_PAGE;
    // change_screen_1(guider_ui);
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    update_key_event();
    show_pwd_buf(&guider_ui);
}

void reload_wifi_page(void)
{
    reset_keyevent();
    guider_ui.page = WIFI_PAGE;
    // change_screen(guider_ui);
    ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_1_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    update_key_event();
}

void Navigation_to_wifi(void)
{
    // reload_wifi_page();
    // reload_wifi_page();
    request_wifi_scan_task(&hspi1);
    // reset_keyevent();
    // guider_ui.page = WIFI_PAGE;
    // // change_screen(guider_ui);
    // ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.screen_1_del, setup_scr_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    // update_key_event();
}

void Change_btn_selected(void)
{
    if (guider_ui.btn_cnt <= 37)
    {
        lv_btnmatrix_clear_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
        guider_ui.btn_cnt += 1;
    }
    else
    {
        guider_ui.btn_cnt = 0;
    }
    // lv_obj_add_style(guider_ui.screen_1_btnm_1, guider_ui.btnm_style, LV_STATE_CHECKED);
    lv_btnmatrix_set_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
    // lv_btnmatrix_set_btn_width(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt,1);
}

void Select_btn_event(void)
{
    if (guider_ui.btn_cnt <= 35)
    {
        volatile char *element = lv_btnmatrix_get_btn_text(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt);
        add_password_buf(&guider_ui, *element);
        show_pwd_buf(&guider_ui);
        lv_btnmatrix_clear_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
        guider_ui.btn_cnt = 0;
        // lv_obj_add_style(guider_ui.screen_1_btnm_1, guider_ui.btnm_style, LV_STATE_CHECKED);
        lv_btnmatrix_set_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
    }
    else if (guider_ui.btn_cnt == 36)
    {
        remove_password_buf(&guider_ui);
        show_pwd_buf(&guider_ui);
        lv_btnmatrix_clear_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
        guider_ui.btn_cnt = 0;
        // lv_obj_add_style(guider_ui.screen_1_btnm_1, guider_ui.btnm_style, LV_STATE_CHECKED);
        lv_btnmatrix_set_btn_ctrl(guider_ui.screen_1_btnm_1, guider_ui.btn_cnt, LV_BTNMATRIX_CTRL_CHECKED);
    }
    else if (guider_ui.btn_cnt == 37)
    {
        connect_wifi(&hspi1, wifinode);
        // ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
        // lv_label_set_text(guider_ui.screen_2_label_1, "IP");
        // lv_label_set_text(guider_ui.screen_2_label_2, "192.168.1.10");
        // lv_label_set_text(guider_ui.screen_2_label_3, "Voltage");
        // lv_label_set_text(guider_ui.screen_2_label_4, "10V");
        // lv_label_set_text(guider_ui.screen_2_label_5, "Password Error!");
    }
}

void _test(void)
{
    connect_wifi(&hspi1, wifinode);
}

void password_right(void)
{
    reset_keyevent();
    guider_ui.page = CONNECTED_PAGE;
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    lv_label_set_text(guider_ui.screen_2_label_1, "IP");
    lv_label_set_text(guider_ui.screen_2_label_2, guider_ui.ip_buf);
    lv_label_set_text(guider_ui.screen_2_label_3, "Voltage");
    lv_label_set_text(guider_ui.screen_2_label_4, "10V");
    update_key_event();
}

void password_wrong(void)
{
    reset_keyevent();
    guider_ui.page = CONNECTED_PAGE;
    ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 0, 0, true, true);
    lv_label_set_text(guider_ui.screen_2_label_5, "Password Error!");
    update_key_event();
}

void connect_wifi(SPI_HandleTypeDef *hspi, WifiNode WifiInfo)
{
    memcpy(&WifiInfo.SSID, &guider_ui.ssid_buf, sizeof(guider_ui.ssid_buf));
    memcpy(&WifiInfo.PWD, &guider_ui.password_buf, sizeof(guider_ui.password_buf));
    WifiInfo.SSIDLen = guider_ui.ssid_buf_len;
    WifiInfo.PWDLen = guider_ui.pwd_buf_len;
    connect_wifi_task(hspi, WifiInfo);
}

// zxh 原本的

void update_key_event(void)
{
    switch ((guider_ui.page))
    {
    case WIFI_PAGE:
        keyboard.key1_single = Add_item_focus;
        keyboard.key1_long = Navigation_to_pwd;
        keyboard.key1_double = Navigation_to_wifi;
        break;
    case PASSWORD_PAGE:
        keyboard.key1_single = Change_btn_selected;
        keyboard.key1_long = Navigation_to_wifi;
        // keyboard.key1_double = Select_btn_event;
        keyboard.key1_double = _test;
        break;
    case CONNECTED_PAGE:
        keyboard.key1_single = NULL;
        keyboard.key1_long = NULL;
        keyboard.key1_double = Navigation_to_wifi;
        break;
    default:
        break;
    }
}

// void update_key_event()
// {
//     keyboard.key1_single = Add_item_focus;
//     keyboard.key1_long = Navigation_to_pwd;
//     keyboard.key1_double = Navigation_to_wifi;
// }
