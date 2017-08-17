#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0      /* default layer (dvorak) */
#define QWERTY 1    /* QWERTY layer for the sake of it */
#define SYMB 2      /* Symbols and numbers: Coding layer */
#define MEDIA 3      /* Motion/media layer */


/* NOTE: The UK corresponding keys are '@ and #~, with the same keycodes corresponding to '" and \| in ANSI.
    The ANSI keys are desired therefore the software setting for the keyboard should be US layout
    TODO: What about dollar and pound signs?
*/
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Dvorak layer
TODO
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | left |           |right |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   '  |   ,  |   .  |   p  |   y  |      |           |      |   f  |   g  |   c  |   r  |   l  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   a  |   o  |   e  |   u  |   i  |------|           |------|   d  |   h  |   t  |   n  |   s  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT |   ;  |   q  |   j  |   k  |   x  |      |           |      |   b  |   m  |   w  |   v  |   z  | RSHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  L2  |                                       |  L2  |  LFT |  DWN |  UP  | RGHT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | SPC  | BSPC |------|       |------| TAB  | ENTR |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

  [BASE] = KEYMAP(
    /* LEFT HAND */
    KC_ESCAPE,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LEFT,
    KC_DELETE,  KC_QUOTE,   KC_COMMA,   KC_DOT,     KC_P,       KC_Y,       TG(3),
    KC_ESCAPE,  KC_A,       KC_O,       KC_E,       KC_U,       KC_I,
    KC_LSHIFT,  KC_SCOLON,  KC_Q,       KC_J,       KC_K,       KC_X,       TO(1),
    KC_LCTL,    KC_LGUI,    KC_LALT,    KC_TRNS,    MO(SYMB),

                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_SPACE,   KC_BSPACE,  KC_HOME,


    /* RIGHT HAND */
    KC_RIGHT,   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,
    KC_TRNS,    KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       /* KC_NONUS_BSLASH,*/ KC_BSLASH,
                KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_SLASH,
    KC_TRNS,    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_RSHIFT,

                            MO(SYMB),      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,

                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_END,     KC_TAB,     KC_ENTER),

/* 1: QWERTY layer
TODO
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [QWERTY] = KEYMAP(
    /* LEFT HAND */
    KC_ESCAPE,  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LEFT,
    KC_DELETE,  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       TG(3),
    KC_ESCAPE,  KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
    KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       TO(0),
    KC_LCTL,    KC_LGUI,    KC_LALT,    KC_TRNS,    MO(SYMB),

                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_SPACE,   KC_BSPACE,  KC_TRNS,

    /* RIGHT HAND */
    KC_RIGHT,   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
    KC_TRNS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
                KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_TRNS,
    KC_TRNS,    KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_TRNS,
    MO(SYMB),      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,

                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TAB,     KC_ENTER),

/* 2: Symbol layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [SYMB] = KEYMAP(
    /* LEFT HAND */
    KC_ESCAPE,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
    KC_TRNS,    KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_TRNS,
    KC_TRNS,    KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRAVE,
    KC_TRNS,    KC_PERC,    KC_CIRC,    KC_LBRACKET,KC_RBRACKET,KC_TILD,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_SPACE,   KC_BSPACE,  KC_TRNS,

    /* RIGHT HAND */
    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,
    KC_TRNS,    KC_UP,      KC_7,       KC_8,       KC_9,       KC_KP_ASTERISK,KC_TRNS,
                KC_DOWN,    KC_4,       KC_5,       KC_6,       KC_KP_PLUS, KC_MEDIA_PLAY_PAUSE,
    KC_TRNS,    KC_AMPR,    KC_1,       KC_2,       KC_3,       KC_BSLASH,  KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TAB,     KC_ENTER),

  [MEDIA] = KEYMAP(
    /* LEFT HAND */
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MS_UP,   KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                                                    KC_TRNS,    KC_TRNS,
                                                                KC_TRNS,
                                        KC_MS_BTN1, KC_MS_BTN2, KC_TRNS,

    /* RIGHT HAND */
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                KC_TRNS,    KC_TRNS,
                KC_TRNS,
                KC_TRNS,    KC_TRNS,    KC_TRNS),

};

const uint16_t PROGMEM fn_actions[] = {
  //[1] = ACTION_LAYER_TAP_TOGGLE(1)
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
