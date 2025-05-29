#ifndef _KEY_H
#define _KEY_H
#include "stdint.h"
// According to your need to modify the constants.
#define TICKS_INTERVAL 5 // ms
#define DEBOUNCE_TICKS 3 // MAX 7 (0 ~ 7)
#define SHORT_TICKS (300 / TICKS_INTERVAL)
#define LONG_TICKS (2500 / TICKS_INTERVAL)

enum Button_IDs
{
    btn1_id,
};

typedef struct KeyBoard_
{
    void (*key1_single)(void);
    // void (*key2_single)(void);
    // void (*key3_single)(void);
    void (*key1_double)(void);
    // void (*key2_double)(void);
    // void (*key3_double)(void);
    void (*key1_long)(void);
    // void (*key2_long)(void);
    // void (*key3_long)(void);
    uint8_t key_event_has;
} KeyBoard;

extern KeyBoard keyboard;

void key_init(void);
void key_run(void);
void reset_keyevent(void);
void key_manager_init(void);
void reload_wifi_page(void);
void update_key_event(void);
void password_right(void);
void password_wrong(void);

#endif /*_KEY_H*/
