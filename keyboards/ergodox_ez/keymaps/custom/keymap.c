#include QMK_KEYBOARD_H
#include "version.h"

#define L0 0 // default layer
#define L1 1 // symbols
#define L2 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------.       ,--------------------------------------------.
 * | L-GUI  |  1  |  2  |  3  |  4  |  5  |  6  |       |  7  |  8  |  9  |  0  | - _ | = + |  Home  |
 * |--------+-----+-----+-----+-----+-----------|       |-----+-----+-----+-----+-----+-----+--------|
 * | Tab    |  Q  |  W  |  E  |  R  |  T  | { [ |       | ] } |  Y  |  U  |  I  |  O  |  P  |  PgUp  |
 * |--------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+--------|
 * | Esc    |  A  |  S  |  D  |  F  |  G  |-----|       |-----|  H  |  J  |  K  |  L  |  ;  |  PgDn  |
 * |--------+-----+-----+-----+-----+-----| ' " |       | \ | |-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  |     |       |     |  N  |  M  |  ,  |  .  |  /  |   End  |
 * `--------+-----+-----+-----+-----+-----------'       `-----------+-----+-----+-----+-----+--------'
 *    |L-Ctl| ` ~ |     | \ | |L-Alt|                               |R-Alt| Left| Down|  Up |Right|
 *    `-----------------------------'                               `-----------------------------'
 *                                  ,-----------.       ------,------
 *                                  | ~L1 | ~L2 |       | ~L2 | ~L1 |
 *                            ,-----|-----|-----|       |-----|-----|-----.
 *                            |     |     | +L1 |       | +L2 |     |     |
 *                            |BkSpc| Del |-----|       |-----| Ent | Spc |
 *                            |     |     |R-Alt|       |L-Alt|     |     |
 *                            `-----------------'       `-----------------'
 */
[L0] = LAYOUT_ergodox(
  // left hand
  KC_LGUI,  KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,
  KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_LBRC,
  KC_ESC,   KC_A,    KC_S,     KC_D,     KC_F,    KC_G,
  KC_LSFT,  KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    KC_QUOT,
  KC_LCTL,  KC_GRV,  KC_TRNS,  KC_NUBS,  KC_LALT,
                                                   MO(L1), MO(L2),
                                                           TO(L1),
                                         KC_BSPC, KC_DEL, KC_RALT,
  // right hand
  KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_HOME,
  KC_RBRC,  KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_PGUP,
            KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_PGDN,
  KC_BSLS,  KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_END,
                     KC_RALT,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,
  MO(L2),  MO(L1),
  TG(L2),
  KC_LALT, KC_ENT, KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------.       ,--------------------------------------------.
 * | RESET  | F1  | F2  | F3  | F4  | F5  | F6  |       |  F7 |  F8 |  F9 | F10 | F11 | F12 |  VRSN  |
 * |--------+-----+-----+-----+-----+-----+-----|       |-----+-----+-----+-----+-----+-----+--------|
 * |  Next  |     |     |     |     |     |     |       |     |     |     |     |     |     |  VolUp |
 * |--------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+--------|
 * |  Play  |     |     |     |     |     |-----|       |-----|     |     |     |     |     |  Mute  |
 * |--------+-----+-----+-----+-----+-----|     |       |     |-----+-----+-----+-----+-----+--------|
 * |  Prev  |     |     |     |     |     |     |       |     |     |     |     |     |     |  VolDn |
 * `--------+-----+-----+-----+-----+-----------'       `-----------+-----+-----+-----+-----+--------'
 *    |     |     |     |     |     |                               |     |     |     |     |      |
 *    `-----------------------------'                               `------------------------------'
 *                                  ,-----------.       ,-----------.
 *                                  |     |     |       |     |     |
 *                            ,-----|-----|-----|       |-----+-----+------.
 *                            |     |     | -L1 |       |     |     |      |
 *                            |     |     |-----|       |-----|     |      |
 *                            |     |     |     |       |     |     |      |
 *                            `-----------------'       `------------------'
 */
[L1] = LAYOUT_ergodox(
  // left hand
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        TO(L0),
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  VRSN,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L2] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
      case 1:
        ergodox_right_led_1_on();
        ergodox_right_led_2_off();
        ergodox_right_led_3_off();
        break;
      case 2:
        ergodox_right_led_1_off();
        ergodox_right_led_2_on();
        ergodox_right_led_3_off();
        break;
      case 3:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_off();
        break;
      case 4:
        ergodox_right_led_1_off();
        ergodox_right_led_2_off();
        ergodox_right_led_3_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_2_off();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_1_off();
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

  return state;
};
