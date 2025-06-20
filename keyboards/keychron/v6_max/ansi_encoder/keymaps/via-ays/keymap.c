/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    FN_1,
    FN_2,
    // FN_MOUSE,
    BASE_CLEAN,
};

#define MS_FN1 LT(FN_1, KC_SPC)
#define MS_FN2 MO(FN_2)

enum custom_keycodes
{
    MS_KVM1 = SAFE_RANGE,
    MS_KVM2,
    MS_KVM3,
    MS_KVM4,

// Game Keyboard
    MS_GAME,

// vim start
    MS_B,
    MS_W,
// vim end

// layout sync start
    MS_ENG,
    MS_RUS,

    MS_BR,      // <br>
    MS_LBRC,    // [ {
    MS_RBRC,    // ] }
    MS_BSLS,    // \ |
    MS_SCLN,    // ; :
    MS_QUOT,    // ' "
    MS_COMM,    // , <
    MS_DOT,     // . >
    MS_SLSH,    // / ?
    MS_2,       // @
    MS_3,       // #
    MS_4,       // $
    MS_6,       // ^
    MS_7,       // &
    MS_LARR,    // <- <=
    MS_RARR,    // -> =>
// layout sync end

// special functions start
    MKS_OUT
// special functions end
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        MS_FN2,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               MS_FN1,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  _______,  _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        MS_FN2,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                MS_FN1,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [FN_1] = LAYOUT_ansi_109(
        _______,  MS_KVM1,  MS_KVM2,  MS_KVM3,  MS_KVM4,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_2,     MS_3,     MS_4,     _______,  MS_6,     MS_7,     _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  MS_W,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  MKS_OUT,  _______,  MS_LBRC,  MS_RBRC,    MS_BSLS,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, MS_SCLN,  MS_QUOT,              MS_BR,                                    _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  MS_B,     _______,  _______,  MS_COMM,  MS_DOT,   MS_SLSH,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    MS_LARR,  _______,  MS_RARR,  _______,            _______,  _______),
    [FN_2] = LAYOUT_ansi_109(
        _______,  MS_ENG,   MS_RUS,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  MS_GAME,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    KC_BTN1,  KC_BTN2,  KC_BTN3,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  KC_MPLY,  _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              KC_MS_U,              _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,            _______,  _______),
    [BASE_CLEAN] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  _______,  _______,  _______,  MS_GAME,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
};

    // [] = LAYOUT_ansi_109(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN_1]   = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [FN_2]   = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    // [FN_MOUSE]   = {ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [BASE_CLEAN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE


// special functions
static bool input_mode = false;
static bool use_dot = true;
static uint8_t input_length = 0;
static char input_buffer[4] = "";
static uint8_t out_n = UINT8_MAX;
static uint8_t out_m = UINT8_MAX;

// static bool fn1_held = false;
// static bool fn2_held = false;


void type_number(uint8_t number) {
    uint8_t digits[3];
    uint8_t length = 0;

    do {
        digits[length++] = number % 10;
        number /= 10;
    } while (number > 0);

    for (int8_t i = length - 1; i >= 0; i--) {
        if(digits[i] == 0)
        {
            tap_code(KC_0);
        }
        else
        {
            tap_code(KC_1 + digits[i] - 1);
        }
    }
}

void type_numbers_from_n_to_m(uint8_t n, uint8_t m)
{
    for(uint8_t i = n; i <= m; i++)
    {
        type_number(i);
        if(use_dot)
        {
            tap_code(KC_DOT);
        }
        tap_code(KC_SPACE);

        if(i != m)
        {
            tap_code(KC_ENTER);
        }
    }
    uint8_t diff = m - n;
    for(uint8_t i = 0; i < diff; i++)
    {
        tap_code(KC_UP);
    }
}

enum language_codes
{
    NONE,
    ENGLISH,
    RUSSIAN
};

enum language_codes current_language = ENGLISH;
enum language_codes previous_language = NONE;

void force_english_layout(void)
{
    previous_language = NONE;

    switch(current_language)
    {
        case NONE:
        case ENGLISH:
        {
            break;
        }

        case RUSSIAN:
        {
            // use special combination (should be set up everywhere)
            // SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_0))));
            // use default combination (works only if you have only 2 layout)
            SEND_STRING(SS_LSFT(SS_TAP(X_LCTL)));
            previous_language = current_language;
            current_language = ENGLISH;
            break;
        }
    }
}

void return_language_layout(void)
{
    switch (previous_language)
    {
        case ENGLISH:
        {
            current_language = ENGLISH;
            // SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_0))));
            // SEND_STRING(SS_LSFT(SS_TAP(X_LCTL)));
            break;
        }
        case RUSSIAN:
        {
            current_language = RUSSIAN;
            SEND_STRING(SS_LSFT(SS_TAP(X_LCTL)));
            break;
        }
        case NONE:
        {
            break;
        }
    }
    previous_language = NONE;
}

bool register_unregister_macros(keyrecord_t *record, uint8_t code, uint16_t shift_code)
{
    const uint8_t mods = get_mods();
    // const uint8_t oneshot_mods = get_oneshot_mods();

    if (record->event.pressed)
    {
        force_english_layout();
        if(mods & MOD_MASK_SHIFT)
        {
            del_mods(MOD_MASK_SHIFT);
            register_code16(shift_code);
            set_mods(mods);
        }
        else
        {
            register_code(code);
        }
    }
    else
    {
        if(mods & MOD_MASK_SHIFT)
        {
            unregister_code16(shift_code);
        }
        else
        {
            unregister_code(code);
        }

        return_language_layout();
    }

    return false;
}


bool send_string_macros(keyrecord_t *record, char *str, char *shift_str)
{
    const uint8_t mods = get_mods();
    // const uint8_t oneshot_mods = get_oneshot_mods();

    if (record->event.pressed)
    {
        force_english_layout();
        if(mods & MOD_MASK_SHIFT)
        {
            del_mods(MOD_MASK_SHIFT);
            send_string_P(shift_str);
            set_mods(mods);
        }
        else
        {
            send_string_P(str);
        }
    }
    else
    {
        return_language_layout();
    }

    return false;
}


#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_1:
            return 250;
        default:
            return TAPPING_TERM;
    }
}


// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    // if (keycode == FN_1) {
    //     fn1_held = record->event.pressed;
    // }
    // else if (keycode == FN_2) {
    //     fn2_held = record->event.pressed;
    // }

    // if (fn1_held && fn2_held) {
    //     layer_on(FN_MOUSE);
    // }
    // else {
    //     layer_off(FN_MOUSE);
    // }

    if(record->event.pressed)
    {
        if(input_mode)
        {
            if((keycode >= KC_1 && keycode <= KC_9) || keycode == KC_0)
            {
                if(input_length < 3)
                {
                    char digit = (keycode - KC_1 + '1');
                    if (keycode == KC_0)
                    {
                        digit = '0';
                    }
                    input_buffer[input_length] = digit;
                    input_length++;
                    input_buffer[input_length] = '\0';
                    return false;
                }
            }

            if (keycode == KC_ENTER)
            {
                int value = atoi(input_buffer);
                if(value >= 1 && value <= 100)
                {
                    if(out_n == UINT8_MAX)
                    {
                        out_n = value;
                        input_length = 0;
                        input_buffer[0] = '\0';
                        out_m = UINT8_MAX;
                        return false;
                    }
                    else
                    {
                        out_m = value;
                        input_mode = false;
                        type_numbers_from_n_to_m(out_n, out_m);
                        input_length = 0;
                        input_buffer[0] = '\0';
                        out_n = UINT8_MAX;
                        out_m = UINT8_MAX;
                        return false;
                    }
                }
                else
                {
                    SEND_STRING("bad values");
                    input_mode = false;
                    input_length = 0;
                    input_buffer[0] = '\0';
                    out_n = UINT8_MAX;
                    out_m = UINT8_MAX;
                    return false;
                }
            }

            if (keycode == KC_ESC)
            {
                input_mode = false;
                input_buffer[0] = '\0';
                out_n = UINT8_MAX;
                out_m = UINT8_MAX;
                return false;
            }

            return true;
        }
    }

    const uint8_t mods = get_mods();
    switch (keycode)
    {
        case MS_BR:
        {
            if(record->event.pressed)
            {
                force_english_layout();
                SEND_STRING("<br>");
                return_language_layout();
                return false;
            }
            break;
        }

        // fast switch
        case MS_KVM1:
        case MS_KVM2:
        case MS_KVM3:
        case MS_KVM4:
        {
            if(record->event.pressed)
            {
                tap_code(KC_LCTL);
                tap_code(KC_LCTL);
                switch (keycode)
                {
                    case MS_KVM1:
                    {
                        tap_code(KC_1);
                        break;
                    }
                    case MS_KVM2:
                    {
                        tap_code(KC_2);
                        break;
                    }
                    case MS_KVM3:
                    {
                        tap_code(KC_3);
                        break;
                    }
                    case MS_KVM4:
                    {
                        tap_code(KC_4);
                        break;
                    }
                }
                return false;
            }
            break;
        }

        case MS_GAME:
        {
            if (record->event.pressed) {
                if(layer_state_is(BASE_CLEAN)){
                    layer_move(WIN_BASE);
                }else{
                    layer_move(BASE_CLEAN);
                }
                return false;
            }
            break;
        }

        // Shift + Backspace for Delete
        case KC_BSPC:
        {
            static bool delkey_registered;
            if (record->event.pressed)
            {
                if (mods & MOD_MASK_SHIFT)
                {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mods);
                    return false;
                }
            }
            else
            {
                if (delkey_registered)
                {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }

        // lang
        case MS_ENG:
        {
            if (record->event.pressed)
            {
                current_language = ENGLISH;
                return false;
            }
            break;
        }

        case MS_RUS:
        {
            if (record->event.pressed)
            {
                current_language = RUSSIAN;
                return false;
            }
            break;
        }

        case FN_2:
        {
            if(record->event.pressed)
            {
                switch (current_language)
                {
                    case ENGLISH:
                    {
                        current_language = RUSSIAN;
                        break;
                    }
                    case RUSSIAN:
                    {
                        current_language = ENGLISH;
                        break;
                    }
                    case NONE:
                    {
                        break;
                    }
                }
            }
            break;
        }

        // [ {
        case MS_LBRC:
        {
            return register_unregister_macros(record, KC_LBRC, S(KC_LBRC));
        }

        // ] }
        case MS_RBRC:
        {
            return register_unregister_macros(record, KC_RBRC, S(KC_RBRC));
        }

        // \ |
        case MS_BSLS:
        {
            return register_unregister_macros(record, KC_BSLS, S(KC_BSLS));
        }

        // ; :
        case MS_SCLN:
        {
            return register_unregister_macros(record, KC_SCLN, S(KC_SCLN));
        }

        // ' "
        case MS_QUOT:
        {
            return register_unregister_macros(record, KC_QUOT, S(KC_QUOT));
        }

        // , <
        case MS_COMM:
        {
            return register_unregister_macros(record, KC_COMM, S(KC_COMM));
        }

        // . >
        case MS_DOT:
        {
            return register_unregister_macros(record, KC_DOT, S(KC_DOT));
        }

        // / ?
        case MS_SLSH:
        {
            return register_unregister_macros(record, KC_SLSH, S(KC_SLSH));
        }

        // @
        case MS_2:
        {
            return register_unregister_macros(record, KC_2, S(KC_2));
        }

        // #
        case MS_3:
        {
            return register_unregister_macros(record, KC_3, S(KC_3));
        }

        // $
        case MS_4:
        {
            return register_unregister_macros(record, KC_4, S(KC_4));
        }

        // ^
        case MS_6:
        {
            return register_unregister_macros(record, KC_6, S(KC_6));
        }

        // &
        case MS_7:
        {
            return register_unregister_macros(record, KC_7, S(KC_7));
        }

        // <- <=
        case MS_LARR:
        {
            if (record->event.pressed)
            {
                force_english_layout();
                if(mods & MOD_MASK_SHIFT)
                {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("<=");
                    set_mods(mods);
                }
                else
                {
                    SEND_STRING("<-");
                }
            }
            else
            {
                return_language_layout();
            }
            return false;
        }

        // -> =>
        case MS_RARR:
        {
            if (record->event.pressed)
            {
                force_english_layout();
                if(mods & MOD_MASK_SHIFT)
                {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("=>");
                    set_mods(mods);
                }
                else
                {
                    SEND_STRING("->");
                }
            }
            else
            {
                return_language_layout();
            }
            return false;
        }

        // vim b
        case MS_B:
        {
            if (record->event.pressed)
            {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
        }

        // vim w
        case MS_W:
        {
            if (record->event.pressed)
            {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)));
            }
            break;
        }

        // print from N to M
        case MKS_OUT:
        {
            if(mods & MOD_MASK_SHIFT)
            {
                use_dot = mods == (MOD_BIT(KC_LSFT));
                if(!input_mode)
                {
                    input_mode = true;
                    input_buffer[0] = '\0';
                    input_length = 0;
                    out_n = UINT8_MAX;
                    out_m = UINT8_MAX;
                    return false;
                }
            }
            break;
        }
    }

    return true;
}

#ifdef RGB_MATRIX_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case WIN_BASE:
        case MAC_BASE:
        case MAC_FN:
        case WIN_FN:
            //rgb_matrix_set_color_all(255, 255, 255);
            break;
        case BASE_CLEAN:
            rgb_matrix_set_color_all(0, 255, 255);
            break;
        case FN_2:
            SEND_STRING(SS_LSFT(SS_TAP(X_LCTL)));
            break;
    }
    return state;
}
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > WIN_FN) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_WHITE);
                }
            }
        }
    }
    return false;
}


