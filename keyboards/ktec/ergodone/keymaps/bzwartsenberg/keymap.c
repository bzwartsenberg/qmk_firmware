#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOUSE 2 // media keys
#define NAV 4 // nav keys
#define NUM 3 // number keys
#define CVAT 5 // cvat

#define TAPPING_TOGGLE 2

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  PSCR_SEL_CP, // printscreen select, and copy to clipboard
  PSCR_SEL_SV, // printscreen select and save
  ALT_F4, // close current window
  RGB_SLD,
};

const uint16_t PROGMEM combo_quot[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_dquo[] = {KC_K, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_O, KC_P, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_quot, KC_QUOT),
    COMBO(combo_dquo, KC_DQUO),
    COMBO(combo_bsls, KC_BSLS),
};
/* const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END}; */
/* const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = { */
/*     COMBO(combo_quot, KC_QUOT), */
/*     COMBO(combo_dquo, KC_DQUO), */
/* }; */

// Some definitions:
#define KC_SFTF LSFT_T(KC_F)
#define KC_CTLD LCTL_T(KC_D)
#define KC_SFTZ LSFT_T(KC_Z)
#define KC_CTLX LCTL_T(KC_X)
#define KC_GUIC LGUI_T(KC_C)
#define KC_ALTV LALT_T(KC_V)


#define KC_SFTJ LSFT_T(KC_J)
#define KC_CTLK LCTL_T(KC_K)
#define KC_SFTSLSH LSFT_T(KC_SLSH)
#define KC_CTLDOT LCTL_T(KC_DOT)
#define KC_GUICOMM LGUI_T(KC_COMM)
#define KC_ALTM LALT_T(KC_M)

#define KC_LT4GRV LT(4, KC_GRV)
// combo keys? leds? where does ' and " go?
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  | BSPC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    Tab |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |    '   |
 * |--------+------+------+------+------+------| `    |           |   '  |------+------+------+------+------+--------|
 * | LShift |Z     |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |  CMD |Alt   | L3   | L1   |                                       |  L2  | L4   |   Alt| CMD  |  CTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | left |right|       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Enter|Tab   |------|       |------|  BSPC  |SPC   |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox( //layer 0 : default
        // left hand
        KC_GRV     , KC_1    , KC_2    , KC_3      , KC_4     , KC_5      , KC_DEL   ,
        KC_TAB     , KC_Q    , KC_W    , KC_E      , KC_R     , KC_T      , TO(CVAT)  ,
        KC_ESC     , KC_A    , KC_S    , KC_CTLD   , KC_SFTF  , KC_G      ,
        KC_LSFT    , KC_SFTZ , KC_CTLX , KC_GUIC   , KC_ALTV  , KC_B      , KC_NO,
        KC_LCTL    , KC_LGUI , KC_LALT , MO(3)     , MO(1)    ,
        KC_LEFT    , KC_RGHT ,
        KC_HOME    ,
        KC_ENT     , KC_TAB  , KC_END  ,


        // right hand
        PSCR_SEL_CP, KC_6    , KC_7    , KC_8      , KC_9     , KC_0      , KC_BSPC  ,
        KC_RBRC    , KC_Y    , KC_U    , KC_I      , KC_O     , KC_P      , KC_BSLS  ,
        KC_H       , KC_SFTJ , KC_CTLK , KC_L      , KC_SCLN  , KC_QUOT   ,
        KC_QUOT    , KC_N    , KC_ALTM , KC_GUICOMM, KC_CTLDOT, KC_SFTSLSH, KC_RSFT  ,
        KC_LT4GRV  , TT(2)   , KC_LALT , KC_LGUI   , KC_LCTL  ,
        KC_UP      , KC_DOWN ,
        KC_PGUP    ,
        KC_PGDN    , KC_BSPC , KC_SPC) ,

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   $  |   +  |   (  |   )  |   @  |------|           |------|   *  |   -  |   =  |   _  |   ^  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   !  |   #  |   {  |   }  |   ~  |      |           |      |   &  |   [  |   ]  |   %  |   |  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
        KC_NO      , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , ALT_F4 ,
        KC_NO      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_NO  ,
        KC_NO      , KC_DLR  , KC_PLUS , KC_LPRN , KC_RPRN , KC_AT   ,
        KC_LSFT    , KC_EXLM , KC_HASH , KC_LCBR , KC_RCBR , KC_TILD , KC_NO  ,
        KC_LCTL    , KC_LGUI , KC_LALT , KC_NO   , KC_NO   ,
        KC_NO      , KC_NO   ,
        KC_NO      ,
        KC_NO      , KC_NO   , KC_NO   ,

       // right hand
        PSCR_SEL_SV, KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
        KC_NO      , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12 ,
        KC_ASTR    , KC_MINS , KC_EQL  , KC_UNDS , KC_CIRC , KC_NO   ,
        KC_NO      , KC_AMPR , KC_LBRC , KC_RBRC , KC_PERC , KC_PIPE , KC_LSFT  ,
        KC_NO      , KC_NO   , KC_LALT , KC_LGUI , KC_LCTL ,
        KC_NO      , KC_NO   ,
        KC_NO      ,
        KC_NO      , KC_NO   , KC_NO)  ,
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |WHL_U |      |M_Ac2 |      |      |           |      |      |      | PSCR |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WHL_L |WHL_D |WHL_R |M_Ac1 |      |------|           |------| MsLe | MsDn | MsUp | MsRi |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |M_Ac0 |      |      |           |TO(0) |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |BT_1  |BT_3  |      |       |      | BT_4 |BT_2  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |BT_5  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUSE] = LAYOUT_ergodox(
      KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO, KC_NO,
      KC_NO  , KC_NO  , KC_WH_U , KC_NO  , KC_ACL2, KC_NO, KC_NO,
      KC_NO  , KC_WH_L, KC_WH_D , KC_WH_R, KC_ACL1, KC_NO,
      KC_LSFT  , KC_NO  , KC_NO   , KC_NO  , KC_ACL0, KC_NO, KC_NO,
      KC_LCTL    , KC_LGUI , KC_LALT , KC_NO   , KC_NO   ,
      KC_NO  , KC_NO  ,
      KC_NO  ,
      KC_BTN1, KC_BTN3, KC_NO   ,

      KC_NO  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO, KC_NO,
      KC_NO  , KC_NO  , KC_PSCR , KC_NO  , KC_NO  , KC_NO, KC_NO,
      KC_MS_L, KC_MS_D, KC_MS_U , KC_MS_R, KC_NO  , KC_NO,
      TO(0)  , KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO, KC_LSFT,
      KC_NO      , TO(0)  , KC_LALT , KC_LGUI , KC_LCTL ,
      KC_NO  , KC_NO  ,
      KC_NO  ,
      KC_BTN5, KC_BTN4, KC_BTN2),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | BrDn | BrUp | MPrev| Mplay|Mnext |      |           |      |      | Mute |VolD  |VolU  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |      |      |      |           |      |Home  |pgdn  |Pgup  |End   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Left | Down |Right |      |      |------|           |------|Left  | Down | Up   |Right |      |        |
 * |--------+------+------+------+------+------|      |           | TO(0)|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//NAV and MEDIA
[NAV] = LAYOUT_ergodox(
      KC_NO  , KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,
      KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_NO  , KC_NO  , KC_NO,
      KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO  ,
      KC_LSFT  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,
        KC_LCTL    , KC_LGUI , KC_LALT , KC_NO   , KC_NO   ,
      KC_NO  , KC_NO  ,
      KC_NO  ,
      KC_NO  , KC_NO  , KC_NO  ,

      KC_NO  , KC_NO  , KC_MUTE, KC_VOLD, KC_VOLU, KC_NO  , KC_NO,
      KC_NO  , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_NO  , KC_NO,
      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_NO  ,
      TO(0)  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LSFT,
      KC_NO      , KC_NO   , KC_LALT , KC_LGUI , KC_LCTL ,
      KC_NO  , KC_NO  ,
      KC_NO  ,
      KC_NO  , KC_NO  , KC_NO) ,



/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  1   |  2   |   3  |   4  |   5  |------|           |------|  6   |   7  |  8   |  9   |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
//NUM
[NUM] = LAYOUT_ergodox(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_1 , KC_2 , KC_3 , KC_4 , KC_5 ,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO,

      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_NO, KC_NO),

[CVAT] = LAYOUT_ergodox(
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO    ,
      KC_NO , KC_NO , KC_NO  , KC_M  , KC_N  , KC_NO , KC_NO    ,
      KC_NO , KC_NO , KC_NO  , KC_D  , KC_F  , KC_NO ,
      KC_NO , KC_NO , KC_DEL , KC_C  , KC_V  , KC_NO , TO(BASE) ,
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO ,
      KC_NO , KC_NO ,
      KC_NO ,
      KC_NO , KC_NO , KC_NO  ,

      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO    ,
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO    ,
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO ,
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO    ,
      KC_NO , KC_NO , KC_NO  , KC_NO , KC_NO ,
      KC_NO , KC_NO ,
      KC_NO ,
      KC_NO , KC_NO , KC_NO)

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
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;

    case PSCR_SEL_CP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_PSCR))));
      }
      return false;
      break;

    case PSCR_SEL_SV:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_PSCR)));
      }
      return false;
      break;

    case ALT_F4:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MOUSE:
            ergodox_right_led_2_on();
            break;
        case NAV:
            ergodox_right_led_3_on();
            break;
        case NUM:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case CVAT:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
