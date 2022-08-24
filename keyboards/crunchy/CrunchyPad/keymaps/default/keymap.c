#include QMK_KEYBOARD_H

// Tapdance enum
enum {
    TD_RESET = 0
};

// Tapdance reset function
void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 5) {
    // Reset the keyboard if you tap the key more than five times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

// Tapdance call
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset)
};

// Main keymapping
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
    /* LAYER 0 (NUMPAD)
   *      ,-------------------.
   *      |Lyer| /  | *  | -  |
   * ,----|----|----|----|----|
   * |Mute| 7  | 8  | 9  |    |
   * '----|----|----|----| +  |
   *      | 4  | 5  | 6  |    |
   * ,----|----|----|----|----|
   * |Calc| 1  | 2  | 3  |    |
   * '----|----|----|----|Ent |
   *      | 0  | 00 | .  |    |
   *      `-------------------'
     */
    [0] = LAYOUT(
        TO(3),   KC_PSLS, KC_PAST, KC_PMNS,
        KC_MUTE, KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_CALC, KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    ),

    /* LAYER 1 (MACROS)
   *      ,-------------------.
   *      |Lyer|H(/)|H(*)|H(-)|
   * ,----|----|----|----|----|
   * |Rec1|H(7)|H(8)|H(9)|    |
   * '----|----|----|----|Ply1|
   *      |H(4)|H(5)|H(6)|    |
   * ,----|----|----|----|----|
   * |Rec2|H(1)|H(2)|H(3)|    |
   * '----|----|----|----|Ply2|
   *      |H(0)|H(S)|H(.)|    |
   *      `-------------------'
     */
    [1] = LAYOUT(
        TO(3),       HYPR(KC_PSLS), HYPR(KC_PAST), HYPR(KC_PMNS),
        DM_REC1,     HYPR(KC_P7),   HYPR(KC_P8),   HYPR(KC_P9),
        HYPR(KC_P4), HYPR(KC_P5),   HYPR(KC_P6),   DM_PLY1,
        DM_REC2,     HYPR(KC_P1),   HYPR(KC_P2),   HYPR(KC_P3),
        HYPR(KC_P0), HYPR(KC_SPC),  HYPR(KC_PDOT), DM_PLY2
    ),

    /* LAYER 2 (RGB CONTROL)
   *      ,-------------------.
   *      |Lyer|    |    |    |
   * ,----|----|----|----|----|
   * |    | M7 | M8 | M9 |    |
   * '----|----|----|----|SAI |
   *      | M4 | M5 | M6 |    |
   * ,----|----|----|----|----|
   * |Tog | M1 | M2 | M3 |    |
   * '----|----|----|----|SAD |
   *      | M0 |    |    |    |
   *      `-------------------'
     */
    [2] = LAYOUT(
        TO(3),   XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, RGB_M_T, RGB_M_TW, RGB_M_B,
        RGB_M_K, RGB_M_X, RGB_M_G,  RGB_SAI,
        RGB_TOG, RGB_M_R, RGB_M_SW, RGB_M_SN,
        RGB_M_P, XXXXXXX, XXXXXXX,  RGB_SAD
    ),

    /* LAYER 3 (LAYER SELECT)
   *      ,-------------------.
   *      |    | L0 | L1 | L2 |
   * ,----|----|----|----|----|
   * |    |    |    |    |    |
   * '----|----|----|----|    |
   *      |    |    |    |    |
   * ,----|----|----|----|----|
   * |RST |    |    |    |    |
   * '----|----|----|----|NUM |
   *      |    |    |    |    |
   *      `-------------------'
     */
    [3] = LAYOUT(
        XXXXXXX, TO(0),   TO(1),   TO(2),
        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,
        TD(TD_RESET), XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,      XXXXXXX, XXXXXXX, KC_NUM
    ),
};

// Encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [1] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),          ENCODER_CCW_CW(KC_UP, KC_DOWN)    },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [3] = { ENCODER_CCW_CW(KC_NO, KC_NO),               ENCODER_CCW_CW(KC_NO, KC_NO)      },
};
#endif