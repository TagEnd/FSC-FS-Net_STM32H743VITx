#include "key.h"
#include "multi_button.h"
#include "main.h"
#include "stdbool.h"

Button button;
// Button button2;
// Button button3;
static Button *_ = NULL;
KeyBoard keyboard = {NULL, NULL, NULL};
uint8_t read_button_GPIO(uint8_t button_id)
{
    // switch (button_id)
    // {
    // case btn1_id:
    //     return HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin);
    // case btn2_id:
    //     return HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
    // case btn3_id:
    //     return HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin);
    // default:
    //     return 0;
    // }
    if (button_id == btn1_id)
    {
        return HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin);
    }
    else
        return 0;
}

struct ButtonPara btnpara = {TICKS_INTERVAL, DEBOUNCE_TICKS, SHORT_TICKS, LONG_TICKS};

/**
 * @brief 5ms
 * @describe
 * @author 小白菜
 * @param
 * @return
 */
void key_run(void)
{
    button_ticks();
}

void BTN_SINGLE_CLICK_Handler(void *btn)
{
    _ = btn;
    if (_->button_id == btn1_id)
    {
        if (keyboard.key1_single)
        {
            keyboard.key1_single();
        }
        keyboard.key_event_has = true;
    }
}
void BTN_LONG_PRESS_START_Handler(void *btn)
{
    _ = btn;
    if (_->button_id == btn1_id)
    {
        if (keyboard.key1_long)
        {
            keyboard.key1_long();
        }
    }
    keyboard.key_event_has = true;
}
void BTN_DOUBLE_CLICK_Handler(void *btn)
{
    _ = btn;
    if (_->button_id == btn1_id)
    {
        if (keyboard.key1_double)
        {
            keyboard.key1_double();
        }
    }
    keyboard.key_event_has = true;
}

/**
 * @brief 按键初始化
 * @describe
 * @author 小白菜
 * @param
 * @return
 */
void key_init(void)
{
    button_para_init(btnpara);
    button_init(&button, read_button_GPIO, 0, btn1_id);

    button_attach(&button, SINGLE_CLICK, BTN_SINGLE_CLICK_Handler);
    button_attach(&button, LONG_PRESS_START, BTN_LONG_PRESS_START_Handler);
    button_attach(&button, DOUBLE_CLICK, BTN_DOUBLE_CLICK_Handler);

    // button_attach(&button2, SINGLE_CLICK, BTN_SINGLE_CLICK_Handler);
    // button_attach(&button2, LONG_PRESS_START, BTN_LONG_PRESS_START_Handler);
    // button_attach(&button2, DOUBLE_CLICK, BTN_DOUBLE_CLICK_Handler);

    // button_attach(&button3, SINGLE_CLICK, BTN_SINGLE_CLICK_Handler);
    // button_attach(&button3, LONG_PRESS_START, BTN_LONG_PRESS_START_Handler);
    // button_attach(&button3, DOUBLE_CLICK, BTN_DOUBLE_CLICK_Handler);

    button_start(&button);
    // button_start(&button2);
    // button_start(&button3);
}

void reset_keyevent(void)
{
    keyboard.key1_single = NULL;
    keyboard.key1_double = NULL;
    keyboard.key1_long = NULL;
    // keyboard.key2_single = NULL;
    // keyboard.key2_double = NULL;
    // keyboard.key2_long = NULL;
    // keyboard.key3_single = NULL;
    // keyboard.key3_double = NULL;
    // keyboard.key3_long = NULL;
}
