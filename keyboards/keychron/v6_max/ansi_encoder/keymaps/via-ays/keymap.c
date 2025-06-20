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
};

enum custom_keycodes
{
    MS_FN1 = SAFE_RANGE,

    // KVM
    MS_KVM1,
    MS_KVM2,
    MS_KVM3,
    MS_KVM4,

    // vim
    MS_B,
    MS_W,

    // special functions start
    MKS_F1
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        MS_FN1,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,  MS_KVM1,  MS_KVM2,  MS_KVM3,  MS_KVM4,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        MS_FN1,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [FN_1] = LAYOUT_ansi_109(
        _______,  MKS_F1,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,              _______,                                  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
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
};
#endif // ENCODER_MAP_ENABLE


// special functions
static bool input_mode = false;
static bool use_dot = true;
static uint8_t input_length = 0;
static char input_buffer[4] = "";
static uint8_t out_n = UINT8_MAX;
static uint8_t out_m = UINT8_MAX;


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

bool process_user_input(uint16_t keycode, keyrecord_t *record)
{
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
        }
    }
    return true;
}

uint16_t custom_lt_timer;
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!process_record_keychron_common(keycode, record))
    {
        return false;
    }

    if(!process_user_input(keycode, record))
    {
        return false;
    }

    const uint8_t mods = get_mods();
    switch (keycode)
    {
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

        case MS_FN1:
        {
            if(record->event.pressed)
            {
                custom_lt_timer = timer_read();
                layer_on(FN_1);
            }
            else
            {
                layer_off(FN_1);
                if(timer_elapsed(custom_lt_timer) < 200)
                {
                    register_code(KC_LSFT);
                    register_code(KC_LCTL);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LSFT);
                }
            }

            return false;
        }

        // print from N to M
        case MKS_F1:
        {
            use_dot = mods != (MOD_BIT(KC_LSFT));
            if(!input_mode)
            {
                input_mode = true;
                input_buffer[0] = '\0';
                input_length = 0;
                out_n = UINT8_MAX;
                out_m = UINT8_MAX;
                return false;
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
