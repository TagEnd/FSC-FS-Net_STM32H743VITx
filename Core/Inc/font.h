#ifndef __FONT_H
#define __FONT_H
#include "main.h"
#include "stdint.h"
#include <string.h>

// #define FONT_6x8
// #define FONT_7x9
// #define FONT_11x18
// #define FONT_16x26
// #define FONT_16x28

typedef struct
{
    uint8_t FontWidth;    /*!< Font width in pixels */
    uint8_t FontHeight;   /*!< Font height in pixels */
    const uint16_t *data; /*!< Pointer to data font data array */
} FontDef_t;

typedef struct
{
    uint16_t Length; /*!< String length in units of pixels */
    uint16_t Height; /*!< String height in units of pixels */
} FONTS_SIZE_t;

// #ifdef FONT_6x8
// extern FontDef_t Font_6x8;
// #endif

// /**
//  * @brief  7 x 9 pixels font size structure
//  */
// #ifdef FONT_7x9
// extern FontDef_t Font_7x9;
// #endif

// /**
//  * @brief  11 x 18 pixels font size structure
//  */
// #ifdef FONT_11x18
// extern FontDef_t Font_11x18;
// #endif

// /**
//  * @brief  16 x 26 pixels font size structure
//  */
// #ifdef FONT_16x26
// extern FontDef_t Font_16x26;
// #endif

// /**
//  * @brief  16 x 28 pixels font size structure only numbers
//  */
// #ifdef FONT_16x28
// // Только цифры -- only numbers
// extern FontDef_t Font_16x28;
// #endif

char *FONTS_GetStringSize(char *str, FONTS_SIZE_t *SizeStruct, FontDef_t *Font);

#endif /*__FONT_H*/