#include "pydactyl.h"
#define BASE 0
#define SYMB 1
#define NAV 2

const uint16_t PROGMEM combo_quot[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_bsls[] = {KC_L, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_scrl[] = {KC_I, KC_SCLN, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_quot, KC_QUOT),
    COMBO(combo_bsls, KC_BSLS),
    COMBO(combo_scrl, KC_SCRL),
};

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define SFT_TAB  SFT_T(KC_TAB)
#define ALT_V  ALT_T(KC_V)
#define ALT_M  ALT_T(KC_M)
#define SFT_F  SFT_T(KC_F)
#define SFT_J  SFT_T(KC_J)
#define CTL_D CTL_T(KC_D)
#define CTL_K CTL_T(KC_K)
#define GUI_C GUI_T(KC_C)

#define GUI_COMM GUI_T(KC_COMM)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define SYMB_ESC LT(SYMB, KC_ESC)
#define NAV_GRV LT(NAV, KC_GRV)
/* #define RAISE MO(_RAISE) */
/* #define LOWER MO(_LOWER) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             | SPACE|ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | HOME | | END  | DEL  |
     *                                    '------+------' '------+------'
     *                                    | Raise|  ~   | | GUI  | Lower|
     *                                    '------+------' '------+------'
     */
    [BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    CTL_D,    SFT_F,    KC_G,                                         KC_H,    SFT_J,    CTL_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    GUI_C,    ALT_V,    KC_B,                                         KC_N,    ALT_M,    GUI_COMM, KC_DOT,  KC_SLSH,
                          KC_LBRC, KC_RBRC,                                                        KC_MINS, KC_EQL,
                                                 SYMB_ESC, KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC, NAV_GRV,
                                                          KC_LSFT,  KC_LGUI,  KC_LCTL,  KC_LALT
    ),

    [SYMB] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,                                      KC_6, KC_7, KC_8,   KC_9, KC_0,
        KC_DLR  , KC_PLUS , KC_LPRN , KC_RPRN , KC_AT,                                     KC_ASTR, KC_MINS , KC_EQL  , KC_UNDS , KC_CIRC,
        KC_EXLM , KC_HASH , KC_LCBR , KC_RCBR , KC_TILD ,                                      KC_AMPR , KC_LBRC , KC_RBRC , KC_PERC , KC_PIPE,
                 QK_BOOT, _______,                                                                          KC_MB1,  KC_MB2,
                                                 KC_ESC, KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC, NAV_GRV,
                                                          KC_LSFT,  KC_LGUI,  KC_LCTL,  KC_LALT
    ),

    [NAV] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_NO,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 KC_F11,  KC_F12,                                                                           _______, QK_BOOT,
                                                 SYMB_ESC, KC_ENT,  KC_TAB,  KC_BSPC, KC_SPC, KC_GRV,
                                                          KC_LSFT,  KC_LGUI,  KC_LCTL,  KC_LALT
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_WH_U, 10);
        } else {
            tap_code_delay(KC_WH_D, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
}
