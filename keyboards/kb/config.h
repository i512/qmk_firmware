#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    qmkbuilder
#define PRODUCT         keyboard
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 10 // doubled up
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

#define MATRIX_ROW_PINS_RIGHT { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS_RIGHT { F6, F7, B1, B3, B2, B6 }

#define UNUSED_PINS

#define SPLIT_HAND_PIN F4
#define SOFT_SERIAL_PIN D0

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#ifdef PS2_USE_INT
    #define PS2_CLOCK_PORT  PORTD
    #define PS2_CLOCK_PIN   PIND
    #define PS2_CLOCK_DDR   DDRD
    #define PS2_CLOCK_BIT   2
    #define PS2_DATA_PORT   PORTD
    #define PS2_DATA_PIN    PIND
    #define PS2_DATA_DDR    DDRD
    #define PS2_DATA_BIT    3

    #define PS2_INT_INIT()  do {    \
        EICRA |= ((1<<ISC21) |      \
                (0<<ISC20));      \
    } while (0)
    #define PS2_INT_ON()  do {      \
        EIMSK |= (1<<INT2);         \
    } while (0)
    #define PS2_INT_OFF() do {      \
        EIMSK &= ~(1<<INT2);        \
    } while (0)
    #define PS2_INT_VECT   INT2_vect
#endif

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif
