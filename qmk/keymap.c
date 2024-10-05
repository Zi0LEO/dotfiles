#include QMK_KEYBOARD_H

void accent_e(tap_dance_state_t *state, void *user_data);

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NUM_LAYER,
  FUNC_LAYER
};

enum my_tap_dances {
  TD_Q_1,
  TD_W_2,
  TD_F_3,
  TD_P_4,
  TD_B_5,
  TD_J_6,
  TD_L_7,
  TD_U_8,
  TD_Y_9,
  TD_BSPC_0,
  TD_Z_CAPS,
  TD_X_CTLX,
  TD_C_CTLC,
  TD_V_CTLV,
  TD_H_CTLH,
  TD_K_CTLK,
  TD_LBRC_GLB,
  TD_RBRC_GRB,
  TD_E_ACCENT,
  TD_A_TAB
};

enum my_keycodes {
    M_DSKN = SAFE_RANGE,
    M_DSKP
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_split_3x5_2(
    TD(TD_Q_1), TD(TD_W_2), TD(TD_F_3), TD(TD_P_4), TD(TD_B_5), TD(TD_J_6), TD(TD_L_7), TD(TD_U_8), TD(TD_Y_9), TD(TD_BSPC_0),
    TD(TD_A_TAB), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G, KC_M, RGUI_T(KC_N), TD(TD_E_ACCENT), RCTL_T(KC_I), KC_O,
    TD(TD_Z_CAPS), TD(TD_X_CTLX), TD(TD_C_CTLC), KC_D, TD(TD_V_CTLV), TD(TD_K_CTLK), TD(TD_H_CTLH), KC_COMM, KC_DOT, KC_SLSH,
    OSM(MOD_LSFT), KC_SPC, KC_ENT, OSL(SYM_LAYER)
  ),
  [SYM_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM, KC_DQUO, LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PLUS,
    KC_ESC, KC_PIPE, TD(TD_LBRC_GLB), KC_LCBR, KC_LPRN, KC_COLN, KC_AT, KC_TILD, KC_MINS, KC_EQL,
    TO(FUNC_LAYER), KC_NUBS, TD(TD_RBRC_GRB), KC_RCBR, KC_RPRN, KC_SCLN, KC_QUOT, KC_HASH, KC_QUES, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(NUM_LAYER)
  ),
  [NUM_LAYER] = LAYOUT_split_3x5_2(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TAB, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_DEL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    TO(FUNC_LAYER), KC_LGUI, M_DSKP, M_DSKN, LSFT(KC_V), KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    TO(BASE_LAYER), KC_SPC, KC_ENT, KC_NO
  ),
  [FUNC_LAYER] = LAYOUT_split_3x5_2(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_MNXT, KC_VOLU, KC_BRIU, KC_ASTR, KC_NO, KC_PLUS,
    KC_F5, KC_F6, KC_F7, KC_F8, KC_MPLY, KC_VOLD, KC_BRID, KC_NO, KC_MINS, KC_EQL,
    KC_F9, KC_F10, KC_F11, KC_F12, KC_MPRV, KC_MUTE, KC_NO, KC_COMM, KC_DOT, KC_SLSH,
    TO(BASE_LAYER), KC_SPC, KC_ENT, TO(SYM_LAYER)
  )
};
 
// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
  // Numbers
  [TD_Q_1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_1),
  [TD_W_2] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_2),
  [TD_F_3] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_3),
  [TD_P_4] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_4),
  [TD_B_5] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_5),
  [TD_J_6] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_6),
  [TD_L_7] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_7),
  [TD_U_8] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_8),
  [TD_Y_9] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_9),
  [TD_BSPC_0] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_0),
  // Cut, copy and paste
  [TD_X_CTLX] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL(KC_X)),
  [TD_C_CTLC] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
  [TD_V_CTLV] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
  // Caps lock
  [TD_Z_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_CAPS),
  [TD_E_ACCENT] = ACTION_TAP_DANCE_DOUBLE(KC_E, 0x00E8),
  // Grave on Q key
  [TD_Q_1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_1),
  // Vim navigation keys with ctrl key pressed on double tap
  [TD_H_CTLH] = ACTION_TAP_DANCE_DOUBLE(KC_H, LCTL(KC_H)),
  [TD_K_CTLK] = ACTION_TAP_DANCE_DOUBLE(KC_K, LCTL(KC_K)),
  // Tap once for [, twice for Search-[ (ChromeOS prev desk)
  [TD_LBRC_GLB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
  // Tap once for ], twice for Search-] (ChromeOS next desk)
  [TD_RBRC_GRB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB)
};

void accent_e(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    tap_code16(UC(0x00E8));
    } else {
    tap_code(KC_E);
  }
    reset_tap_dance(state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Return to the base later after fn keys, space or enter have been pressed
  case KC_F1 ... KC_F12:
  case KC_SPC:
  case KC_ENT:
    if (record->event.pressed) {
      layer_move(BASE_LAYER);
    }
    break;
  // Return to num layer if symbol keys in the func layer have been pressed
  case KC_ASTR:
  case KC_PLUS:
  case KC_MINS:
  case KC_EQL:
  case KC_DOT:
  case KC_SLSH:
    if (record->event.pressed) {
      if (IS_LAYER_ON(FUNC_LAYER)) {
        layer_move(NUM_LAYER);
      }
    }
    break;
  // Respond to next desktop macro
  case M_DSKN:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_RIGHT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
    }
    break;
  // Respond to previous desktop macro
  case M_DSKP:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_LEFT));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
    }
    break;
  }
  return true;
}

void leader_start_user(void) {
  // Do something when the leader key is pressed
}

void leader_end_user(void) {
  // Vim regexp and substitution
  if (leader_sequence_one_key(KC_R)) {
      SEND_STRING(SS_TAP(X_ESC)":/");
  } else if (leader_sequence_one_key(KC_S)) {
      SEND_STRING(SS_TAP(X_ESC)":s/");
  // AutoHotkey shortcuts to minimise, maximise and close windows
  } else if (leader_sequence_one_key(KC_Z)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_Z));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_X)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_X));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_A)) {
      SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
      SEND_STRING(SS_TAP(X_A));
      SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  // AutoHotkey shortcuts to open applications or bring them to the front
  } else if (leader_sequence_one_key(KC_Q)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_1));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_W)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_2));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_F)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_3));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_P)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_4));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_B)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_5));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_J)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_6));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_L)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_7));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_U)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_8));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  } else if (leader_sequence_one_key(KC_Y)) {
    SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
    SEND_STRING(SS_TAP(X_9));
    SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT)SS_UP(X_LCTL)SS_UP(X_LSFT));
  }
}
