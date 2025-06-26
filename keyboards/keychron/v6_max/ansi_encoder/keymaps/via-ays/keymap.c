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
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MPLY,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  MKS_F1,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  MS_W,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,              _______,                                  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,
        _______,            _______,  _______,  _______,  _______,  MS_B,     _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                QK_LEAD,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
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
    [FN_1]   = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
};
#endif // ENCODER_MAP_ENABLE


// special macros
#define SPECIAL_MACROS_MAX_INPUT_LENGTH 6
static uint16_t sm_command = 0;
static bool sm_input_mode = false;
static bool sm_f1_use_dot = true;
static uint8_t sm_input_length = 0;
static char sm_input_buffer[SPECIAL_MACROS_MAX_INPUT_LENGTH + 1] = "";
static uint8_t previous_rgb_mode = 0;


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

#define ABS(x) ((x) < 0 ? -(x) : (x))

void type_numbers_from_n_to_m(uint8_t n, uint8_t m)
{
    if (n <= m)
    {
        for (uint8_t i = n; i <= m; i++)
        {
            type_number(i);
            if (sm_f1_use_dot) tap_code(KC_DOT);
            tap_code(KC_SPACE);
            if (i != m) tap_code(KC_ENTER);
        }
    }
    else
    {
        for (uint8_t i = n; i >= m; i--)
        {
            type_number(i);
            if (sm_f1_use_dot) tap_code(KC_DOT);
            tap_code(KC_SPACE);
            if (i != m) tap_code(KC_ENTER);
            if (i == 0) break;
        }
    }

    uint8_t diff = (n > m) ? n - m : m - n;
    for(uint8_t i = 0; i < diff; i++)
    {
        tap_code(KC_UP);
    }
}

void init_special_macros(void)
{
    sm_input_mode = false;
    sm_input_buffer[0] = '\0';
    sm_input_length = 0;
    sm_command = 0;
    rgb_matrix_mode(previous_rgb_mode);
}

bool parse_range(const char *buffer, uint8_t *out_n, uint8_t *out_m) {
    const char *dots = strstr(buffer, "..");
    if (!dots) {
        return false; // не найдены две точки
    }

    char left[4] = {0};  // макс 3 цифры + \0
    char right[4] = {0};

    size_t left_len = dots - buffer;
    if (left_len >= sizeof(left)) return false;
    strncpy(left, buffer, left_len);
    strncpy(right, dots + 2, sizeof(right) - 1);

    int n = atoi(left);
    int m = atoi(right);

    if (n < 0 || n > 255 || m < 0 || m > 255) return false;

    *out_n = (uint8_t)n;
    *out_m = (uint8_t)m;
    return true;
}

bool process_user_input(uint16_t keycode, keyrecord_t *record)
{
    if(!sm_input_mode)
    {
        return true;
    }

    if(!record->event.pressed)
    {
        return true;
    }

    if (keycode == KC_ESC)
    {
        init_special_macros();
        return false;
    }

    if(keycode == KC_ENTER)
    {
        switch(sm_command)
        {
            case MKS_F1:
            {
                uint8_t a, b;
                if (parse_range(sm_input_buffer, &a, &b))
                {
                    type_numbers_from_n_to_m(a, b);
                }
                else{
                    SEND_STRING("bad values");
                }
            }
        }

        init_special_macros();
        return false;
    }

    if((keycode >= KC_1 && keycode <= KC_9) || keycode == KC_0 || keycode == KC_DOT)
    {
        if(sm_input_length < SPECIAL_MACROS_MAX_INPUT_LENGTH)
        {
            char digit = (keycode - KC_1 + '1');
            if (keycode == KC_0)
            {
                digit = '0';
            }
            if(keycode == KC_DOT)
            {
                digit = '.';
            }

            sm_input_buffer[sm_input_length] = digit;
            sm_input_length++;
            sm_input_buffer[sm_input_length] = '\0';
            return false;
        }
    }

    return false;
}

uint16_t custom_lt_timer;

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

        case MS_B:
        {
            if (record->event.pressed)
            {
                tap_code16(C(KC_LEFT));
            }
            break;
        }

        case MS_W:
        {
            if (record->event.pressed)
            {
                tap_code16(C(KC_RGHT));
            }
            break;
        }

        // print from N to M
        case MKS_F1:
        {
            if(record->event.pressed)
            {
                if(!sm_input_mode)
                {
                    previous_rgb_mode = rgb_matrix_get_mode();
                    init_special_macros();
                    sm_f1_use_dot = mods != (MOD_BIT(KC_LSFT));
                    sm_input_mode = true;
                    sm_command = MKS_F1;
                    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                    return false;
                }
            }
            break;
        }
    }

    return true;
}

void leader_end_user(void) {
    // git
    if (leader_sequence_one_key(KC_G))
    {
        SEND_STRING("git ");
    } else if (leader_sequence_two_keys(KC_G, KC_S))
    {
        SEND_STRING("git status\n");
    } else if (leader_sequence_two_keys(KC_G, KC_A))
    {
        SEND_STRING("git add ");
    } else if (leader_sequence_three_keys(KC_G, KC_A, KC_A))
    {
        SEND_STRING("git add .\n");
    } else if (leader_sequence_two_keys(KC_G, KC_C))
    {
        SEND_STRING("git commit\n");
    } else if (leader_sequence_two_keys(KC_G, KC_R))
    {
        SEND_STRING("git reset\n");
    }

    // user
    else if (leader_sequence_two_keys(KC_U, KC_P))
    {
        SEND_STRING("alexander.yu.shamin@gmail.com");
    }
    else if (leader_sequence_two_keys(KC_U, KC_W))
    {
        SEND_STRING("ashamin@tech-round.com");
    }
    else if (leader_sequence_two_keys(KC_U, KC_D))
    {
        // send_string_with_delay("alexander.yu.shamin.development@gmail.com", 20);
        SEND_STRING("alexander.yu.shamin.development@gmail.com");
    }
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
