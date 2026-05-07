#include QMK_KEYBOARD_H

// Relevant docs:
// - <https://docs.qmk.fm/features/key_overrides>
// - <https://docs.qmk.fm/mod_tap>
// - <https://docs.qmk.fm/tap_hold>
// - <https://docs.qmk.fm/one_shot_keys>
// - <https://docs.qmk.fm/feature_advanced_keycodes> for modifier keys
// - <https://docs.qmk.fm/features/tap_dance>
// - <https://docs.qmk.fm/custom_quantum_functions>

enum {
    L_QWERTY,
    L_SYM,
    L_FN,
    L_MEDIA,
    L_COMPAT,
};

enum {
    TD_LSFT,
    // TD_SYM,
};

enum custom_keycodes {
  CKC_ALTTAB = SAFE_RANGE,
  CKC_LCTL,
  CKC_LGUI,
  CKC_OSL_SYM,
  CKC_OSM_RSFT,
  CKC_LT_FN_STOP,
};

bool is_fn_pressed = false;
bool is_fn_used = false;
uint16_t fn_timer = 0;

bool is_sym_pressed = false;
bool is_lalt_pressed = false;
bool is_alttab_active = false;

// Tap dance //////////////////////////////////////////////////////////

// For information on how oneshot layers are processed, see:
// <https://github.com/qmk/qmk_firmware/blob/504533b3b49d0c7643c7ec5881348e400a86782f/quantum/action_util.c#L184>
// For the structure of tap_dance_state_t, see:
// <https://github.com/qmk/qmk_firmware/blob/master/quantum/process_keycode/process_tap_dance.h>

// void td_sym_finish(tap_dance_state_t *state, void *user_data) {
//     if(state->count != 2){
//         set_oneshot_layer(L_SYM, ONESHOT_START);
//     }
//     if(state->count >= 2){
//         register_mods(MOD_BIT(KC_RALT));
//
// }

// void td_sym_reset(tap_dance_state_t *state, void *user_data){
//     if (state->count != 2){
//         clear_oneshot_layer_state(ONESHOT_PRESSED);
//     }
//     if (get_mods() & MOD_BIT(MOD_LSFT)) {
//         unregister_mods(MOD_LSFT);
//     }
// }

void td_lsft_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
    }
}

void td_lsft_finish(tap_dance_state_t *state, void *user_data) {
    if (state->interrupting_keycode == CKC_OSM_RSFT
            || state->interrupting_keycode == CKC_OSL_SYM) {
        uint8_t tap = KC_NUBS;
        if (state->count >= 2) {
            tap = KC_CAPS;
        }
        unregister_code(KC_LSFT);
        tap_code(tap);
    }
}

void td_lsft_reset(tap_dance_state_t *state, void *user_data) {
    if (get_mods() & MOD_BIT(MOD_LSFT)) {
        unregister_mods(MOD_LSFT);
    }
    if(!state->interrupted) {
        uint8_t tap = KC_NUBS;
        if (state->count >= 2) {
            tap = KC_CAPS;
        }
        tap_code(tap);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(
            td_lsft_tap, td_lsft_finish, td_lsft_reset),
    // [TD_SYM]  = ACTION_TAP_DANCE_FN_ADVANCED(
    //         NULL,        td_sym_finish,  td_sym_reset),
};


// Overrides //////////////////////////////////////////////////////////


// We want the backslash to always emit a backslash, even with Shift.
const key_override_t backslash_override = ko_make_basic(
    MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);

const key_override_t lsft_override = ko_make_basic(
    MOD_BIT(KC_RSFT), TD(TD_LSFT), KC_NUBS);

const key_override_t *key_overrides[] = {
    &backslash_override,
    &lsft_override,
};

// Layers /////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_QWERTY] = LAYOUT_split_3x6_3(

KC_TAB,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
KC_ENT,
KC_BSPC,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
KC_QUOT,
TD(TD_LSFT),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
KC_BSLS,

KC_LALT,      CKC_LT_FN_STOP, KC_SPC,
CKC_OSM_RSFT, CKC_OSL_SYM,    KC_RCTL
    ),

[L_SYM] = LAYOUT_split_3x6_3(

S(KC_TAB),
    S(KC_1),    KC_LBRC,    S(KC_EQL), S(KC_3),    KC_RBRC,
    S(KC_6),    KC_7,       KC_8,      KC_9,       S(KC_5),
RALT(KC_ENT),
KC_BSPC,
    S(KC_8),    S(KC_9),    KC_MINS,   KC_EQL,     S(KC_0),
    S(KC_2),    KC_4,       KC_5,      KC_6,       KC_0,
KC_GRV,
KC_NUBS,
    S(KC_BSLS), S(KC_LBRC), S(KC_4),   S(KC_MINS), S(KC_RBRC),
    S(KC_7),    KC_1,       KC_2,      KC_3,       S(KC_GRV),
KC_BSLS,

_______, _______, _______,
_______, _______, _______
    ),

[L_FN] = LAYOUT_split_3x6_3(

CKC_ALTTAB,
    KC_ESC,    KC_HOME,   KC_UP,        KC_END,      KC_PGUP,
    LAG(KC_Y), LAG(KC_U), LAG(KC_I),    LAG(KC_O),   LAG(KC_P),
LAG(KC_ENT),
_______,
    CKC_LCTL,  KC_LEFT,   KC_DOWN,      KC_RGHT,     KC_PGDN,
    LAG(KC_H), LAG(KC_J), LAG(KC_K),    LAG(KC_L),   LAG(KC_SCLN),
LAG(KC_QUOT),
_______,
    CKC_LGUI,  KC_CUT,    KC_COPY,      KC_PSTE,     KC_DEL,
    LAG(KC_N), LAG(KC_M), LAG(KC_COMM), LAG(KC_DOT), LAG(KC_SLSH),
LAG(KC_BSLS),

_______, _______, KC_RGUI,
_______, _______, _______
    ),

[L_MEDIA] = LAYOUT_split_3x6_3(

_______,
    _______,   KC_MPRV,   KC_VOLU,    KC_MNXT,   KC_BRIU,
    KC_F12,    KC_F7,     KC_F8,      KC_F9,     KC_PAUS,
KC_INS,
_______,
    _______,   KC_MRWD,   KC_VOLD,    KC_MFFD,   KC_BRID,
    KC_F11,    KC_F6,     KC_F7,      KC_F8,     KC_PSCR,
KC_APP,
_______,
    _______,   KC_MSTP,   KC_KB_MUTE, KC_MPLY,   _______,
    KC_F10,    KC_F1,     KC_F2,      KC_F3,     _______,
KC_SCRL,

// Note:
// - uses stop/playpause instead of pause/play
// - No search key, no lock key, no close key

_______, _______, _______,
_______, _______, _______
    ),

[L_COMPAT] = LAYOUT_split_3x6_3(

_______,
    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,
_______,
_______,
    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,
_______,
_______,
    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______, _______,  _______,
_______,

_______, _______, _______,
_______, _______, _______
    ),

};

uint8_t oneshot_mods_previous;

void oneshot_mods_changed_user(uint8_t mods) {
    if ((mods ^ oneshot_mods_previous) & MOD_BIT(KC_LCTL)) {
        if (mods & MOD_BIT(KC_LCTL)) {
            layer_off(L_FN);
            layer_off(L_MEDIA);
        } else {
            if (is_fn_pressed) {
                layer_on(L_FN);
                if (is_sym_pressed) {
                    layer_on(L_MEDIA);
                }
            }
        }
    }
    oneshot_mods_previous = mods;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (layer_state_is(L_FN) && record->event.pressed) {
        is_fn_used = true;
    }

    switch (keycode) {

        case CKC_LCTL:
            if (record->event.pressed){
                register_mods(MOD_BIT(KC_LCTL));
                add_oneshot_mods(MOD_BIT(KC_LCTL));
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
            }
            return false;

        case CKC_LGUI:
            if (record->event.pressed){
                layer_off(L_FN);
                register_mods(MOD_BIT(KC_LGUI));
            } else {
                unregister_mods(MOD_BIT(KC_LGUI));
                if (is_fn_pressed) {
                    layer_on(L_FN);
                }
            }
            return false;

        case CKC_OSM_RSFT:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_RSFT));
                add_oneshot_mods(MOD_BIT(KC_RSFT));
            } else {
                unregister_mods(MOD_BIT(KC_RSFT));
            }
            return false;

        case CKC_OSL_SYM:
            is_sym_pressed = (record->event.pressed);
            if (is_sym_pressed) {
                set_oneshot_layer(L_SYM, ONESHOT_START);
                if (is_fn_pressed) {
                    layer_on(L_MEDIA);
                }
            } else {
                // TODO
                clear_oneshot_layer_state(ONESHOT_PRESSED);
                layer_off(L_MEDIA);
            }
            return false;

        // On keyup of the FN key, want to exit the AltTab mode
        case CKC_LT_FN_STOP:
            is_fn_pressed = (record->event.pressed);

            if (is_fn_pressed) {
                is_fn_used = false;
                fn_timer = timer_read();
                layer_on(L_FN);
                if (is_sym_pressed) {
                    layer_on(L_MEDIA);
                }
            } else {
                layer_off(L_FN);
                layer_off(L_MEDIA);
                if (timer_elapsed(fn_timer) < TAPPING_TERM && !is_fn_used) {
                    tap_code(KC_STOP);
                }

                if (is_alttab_active) {
                    is_alttab_active = false;
                    if(!is_lalt_pressed) {
                        unregister_mods(MOD_BIT(KC_LALT));
                    }
                }
            }
            return false;

        case CKC_ALTTAB:
            if (record->event.pressed) {
                if (!is_alttab_active) {
                    is_alttab_active = true;
                    register_mods(MOD_BIT(KC_LALT));
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        // We just want to remember when the 'real' LALT is pressed, and
        // prevent normal keyup in case we are still in AltTab mode
        case KC_LALT:
            is_lalt_pressed = (record->event.pressed);
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT));
            } else if (!is_alttab_active) {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            return false;

        // Other thumb keys should not have any influence...
        case OSM(KC_RSFT):
        case KC_RSFT:
        case KC_RALT:
        // case TD(TD_SYM):
        case KC_RCTL:
            return true;

        // ... but any other key should immediately exit the AltTab mode
        default:
            if (is_alttab_active && !is_lalt_pressed) {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            is_alttab_active = false;
            return true;
    }
}
