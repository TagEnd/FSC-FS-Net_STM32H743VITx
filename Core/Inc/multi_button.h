#ifndef _MULTI_BUTTON_H_
#define _MULTI_BUTTON_H_
 
#include <stdint.h>
#include <string.h>
 
typedef struct ButtonPara {
  uint8_t ticks_interval;
  uint8_t debounce_ticks;
  uint16_t short_ticks;
  uint16_t long_ticks;
}ButtonPara;
 
typedef void (*BtnCallback)(void*);
 
typedef enum {
  PRESS_DOWN = 0,
  PRESS_UP,
  PRESS_REPEAT,
  SINGLE_CLICK,
  DOUBLE_CLICK,
  LONG_PRESS_START,
  LONG_PRESS_HOLD,
  number_of_event,
  NONE_PRESS
}PressEvent;
 
typedef struct Button {
  uint16_t ticks;
  uint8_t  repeat : 4;
  uint8_t  event : 4;
  uint8_t  state : 3;
  uint8_t  debounce_cnt : 3;
  uint8_t  active_level : 1;
  uint8_t  button_level : 1;
  uint8_t  button_id;
  uint8_t  (*hal_button_Level)(uint8_t button_id_);
  BtnCallback  cb[number_of_event];
  struct Button* next;
}Button;
 
#ifdef __cplusplus
extern "C" {
#endif
void button_para_init(struct ButtonPara para);
void button_init(struct Button* handle, uint8_t(*pin_level)(uint8_t), uint8_t active_level, uint8_t button_id);
void button_attach(struct Button* handle, PressEvent event, BtnCallback cb);
PressEvent get_button_event(struct Button* handle);
int  button_start(struct Button* handle);
void button_stop(struct Button* handle);
void button_ticks(void);
 
#ifdef __cplusplus
}
#endif
 
#endif