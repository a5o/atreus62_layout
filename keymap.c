#include QMK_KEYBOARD_H

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _FUN 3
#define _ADJUST 4

enum custom_keycodes {
  BASE,
  LOWER,
  RAISE,
	TD_E,
	UGRV,
	IGRV,
	OGRV,
	AGRV
};

void accent_e (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
		send_string("'e");
  } else {
    send_string("`e");
  }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_E] = ACTION_TAP_DANCE_FN(accent_e),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
	KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, 
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, 
	LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), 
	KC_LCTL, MO(_FUN), KC_LGUI, KC_LALT, RAISE, KC_BSPC, KC_SPC, KC_ENT, KC_BSLS, LOWER, RALT_T(KC_LEFT), RGUI_T(KC_DOWN), KC_UP, RCTL_T(KC_RGHT)),

	[_LOWER] = LAYOUT(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, TD(TD_E), KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, UGRV, IGRV, OGRV, KC_TRNS, KC_TRNS,
	KC_TRNS, AGRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_RAISE] = LAYOUT(
	KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, 
	KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, 
	KC_TRNS, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_PIPE, KC_LBRC, KC_RBRC, KC_NO, KC_COLN, KC_DQUO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_TRNS, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_FUN] = LAYOUT(
	KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PSCR, KC_INS, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, 
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_ADJUST] = LAYOUT(
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, RESET, EEP_RST, DEBUG, KC_NO, KC_NO, AG_SWAP, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO, 
	BASE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case BASE:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_BASE);
			}
			return false;
			break;
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
		case AGRV:
			if (record->event.pressed) {
				send_string("`a");
			}
			return false;
			break;
		case IGRV:
			if (record->event.pressed) {
				send_unicode_string("`i");
			}
			return false;
			break;
		case OGRV:
			if (record->event.pressed) {
				send_unicode_string("`o");
			}
			return false;
			break;
		case UGRV:
			if (record->event.pressed) {
				send_unicode_string("`u");
			}
			return false;
			break;
	}
	return true;
}
