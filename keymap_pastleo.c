#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Empty template
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
    KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
     */
    
    /* 0: qwerty for mac */
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          FN0,  \
        FN0 ,LALT,LGUI,          SPC,                     RGUI,RALT,ESC, FN1),
    /* 1: windows mode */
    KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,   \
        TRNS,LGUI,LALT,          TRNS,                    RGUI,RALT,TRNS,TRNS),
    /* 2: for non-geeks */
    KEYMAP_ANSI(
        ESC ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          RSFT,   \
        TRNS,LGUI,LALT,          TRNS,                    RALT,RGUI,RCTL,TRNS),
    /* 3: functions */
    KEYMAP_ANSI(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, \
        TRNS,TRNS,UP,  PSCR,SLCK,PAUS,WH_L,WH_D,MS_U,WH_U,RSFT,PGUP,INS, CAPS,\
        TRNS,LEFT,DOWN,RGHT,HOME,END ,WH_R,MS_L,MS_D,MS_R,RCTL,PGDN,     TRNS, \
        TRNS,BTN1,BTN2,BTN3,MUTE,VOLU,VOLD,MPRV,MPLY,MNXT,APP,           TRNS, \
        TRNS,TRNS,TRNS,          ACL0,                    TRNS,TRNS,TRNS,TRNS),
    /* 4: settings */
    KEYMAP_ANSI(
        FN2 ,FN3 ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  , \
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  , \
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,     NO  , \
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,          NO  , \
        NO  ,NO  ,NO  ,          NO  ,                    NO  ,NO  ,NO  ,TRNS),
};
const uint16_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(3),  // to Fn overlay
    [1] = ACTION_LAYER_MOMENTARY(4),  // to settings
    [2] = ACTION_LAYER_TOGGLE(1),     // mac or windows mode
    [3] = ACTION_LAYER_TOGGLE(2),     // toggle non-geek mode
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
