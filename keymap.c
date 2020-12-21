#include QMK_KEYBOARD_H

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _FUN 3
#define _ADJUST 4

enum custom_keycodes {
  LOWER,
  RAISE,
};

enum unicode_names {
    EACU,
		EGRV,
		AGRV,
		UGRV,
		IGRV,
		OGRV,
  	LTEQ,
 	 	GTEQ,
  	NOTEQ,
  	PLMIN,
		LMU
};

const uint32_t PROGMEM unicode_map[] = {
  [EACU] = 0x00E9,
	[EGRV] = 0x00E8,
	[AGRV] = 0x00E0,
	[UGRV] = 0x00F9,
	[IGRV] = 0x00EC,
	[OGRV] = 0x00F2,

  // math
  [LTEQ] = 0x2264, // less than or equal
  [GTEQ] = 0x2265, // greater than or equal
  [NOTEQ] = 0x2260, // not equal
  [PLMIN] = 0xB1, // plus minus

	// misc symbols
	[LMU] = 0x03BC

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
	KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, 
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
	LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), 
	KC_LCTL, MO(_FUN), KC_LGUI, KC_LALT, RAISE, KC_SPC, KC_BSPC, KC_ENT, KC_SPC, LOWER, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
	),

	[_LOWER] = LAYOUT(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(NOTEQ),
	KC_TRNS, KC_TRNS, KC_TRNS, X(EGRV), KC_TRNS, KC_TRNS, KC_TRNS, X(UGRV), X(IGRV), X(OGRV), KC_TRNS, X(PLMIN),
	KC_TRNS, X(AGRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(LMU), X(LTEQ), X(GTEQ), KC_TRNS, KC_BSLS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_RAISE] = LAYOUT(
	KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, 
	KC_TRNS, KC_NO, KC_NO, X(EACU), KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_UNDS, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_COLN, KC_DQUO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_LT, KC_GT, KC_QUES, KC_PIPE, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
	),

	[_FUN] = LAYOUT(
	KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
	),

	[_ADJUST] = LAYOUT(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, RESET, EEP_RST, DEBUG, KC_NO, KC_NO, AG_SWAP, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UC_M_LN, KC_NO, KC_NO, 
	KC_NO, KC_NO, KC_NO, UC_M_WC, KC_NO, KC_NO, KC_NO, UC_M_MA, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}else{
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}else{
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break; 
	}
	return true;
}
