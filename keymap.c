#include QMK_KEYBOARD_H

#include "keymap_estonian.h"
#include "process_magic.h"

#define ___ KC_TRNS  // Transparent (no override)
#define XXX KC_NO    // No key / disabled
                     //
enum unicode_names {
    OTILDE_L,
    ADIAL_L,
    ODIAL_L,
    UDIAL_L,
    OTILDE_U,
    ADIAL_U,
    ODIAL_U,
    UDIAL_U
};

const uint32_t PROGMEM unicode_map[] = {
    [OTILDE_L]  = 0x00f5,
    [ADIAL_L]   = 0x00e4,
    [ODIAL_L]   = 0x00f6,
    [UDIAL_L]   = 0x00fc,
    [OTILDE_U]  = 0x00d5,
    [ADIAL_U]   = 0x00c4,
    [ODIAL_U]   = 0x00d6,
    [UDIAL_U]   = 0x00dc,
};

#define OTILDE UP(OTILDE_L, OTILDE_U)
#define ADIAL UP(ADIAL_L, ADIAL_U)
#define ODIAL UP(ODIAL_L, ODIAL_U)
#define UDIAL UP(UDIAL_L, UDIAL_U)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q,          KC_W,          KC_F,          KC_P,           KC_B,              KC_J,          KC_L,          KC_U,          KC_Y,          KC_SCLN,
        LSFT_T(KC_A),  LT(6,KC_R),    LT(2,KC_S),    LT(4,KC_T),     KC_G,              KC_M,          LT(5,KC_N),    LT(3,KC_E),    LT(7,KC_I),    LSFT_T(KC_O),
        KC_Z,          LCTL_T(KC_X),  LALT_T(KC_C),  KC_D,           KC_V,              KC_K,          KC_H,          LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
                                                     LT(3,KC_ESC),   KC_BSPC,           LT(8,KC_SPC),  LT(1,KC_ENTER)
    ),
    [1] = LAYOUT_split_3x5_2(
        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                KC_6,           KC_7,           KC_8,       KC_9,            KC_0,
        ___,           ___,           ___,           ___,           ___,                OTILDE,  ADIAL, ODIAL, UDIAL,   ___,
        ___,           ___,           ___,           ___,           ___,                ___,           ___,           ___,       ___,           ___,
                                                     KC_LSFT,           ___,                ___,           XXX
    ),
    [2] = LAYOUT_split_3x5_2(
        ___,           ___,           ___,           ___,            ___,               ___,           KC_WH_U,       KC_MS_U,       KC_WH_D,       ___,
        ___,           KC_BTN2,       XXX,           KC_BTN1,        ___,               ___,           KC_MS_L,       KC_MS_D,       KC_MS_R,       ___,
        ___,           ___,           ___,           ___,            ___,               ___,           KC_WH_L,       KC_WH_D,       KC_WH_R,       ___,
                                                     ___,            ___,               ___,           ___
    ),
    [3] = LAYOUT_split_3x5_2(
        ___,           ___,           ___,           ___,           ___,                ___,           ___,           KC_PGUP,       ___,            ___,
        ___,           KC_LGUI,       XXX,           LCTL(KC_LALT), LCA(KC_LSFT),       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,        ___,
        ___,           ___,           ___,           ___,           ___,                ___,           KC_HOME,       KC_PGDN,       KC_END,         ___,
                                                     ___,           ___,                ___,           ___
    ),
    [4] = LAYOUT_split_3x5_2(
        ___,           ___,           ___,           ___,            ___,               ___,           KC_UNDS,       KC_PIPE,       KC_QUOT,       ___,
        KC_CIRC,       KC_ASTR,       KC_AMPR,       XXX,            ___,               KC_HASH,       KC_TILD,       KC_SLSH,       KC_DQUO,       KC_DLR,
        ___,           ___,           ___,           ___,            ___,               ___,           KC_MINS,       KC_BSLS,       KC_GRV,        ___,
                                                     RM_PREV,       ___,                ___,           RM_NEXT
    ),
    [5] = LAYOUT_split_3x5_2(
        ___,           KC_MINS,       KC_LT,         KC_GT,          KC_SCLN,           ___,           ___,           ___,           ___,            ___,
        KC_LCBR,       KC_LPRN,       KC_RPRN,       KC_RCBR,        KC_AT,             ___,             XXX,            KC_EQL,         KC_PLUS,          KC_PERC,
        ___,           KC_EXLM,       KC_LBRC,       KC_RBRC,        ___,               ___,             ___,            ___,            ___,              ___,
                                                     KC_VOLD,        ___,               KC_SPC,          KC_VOLU
    ),
    [6] = LAYOUT_split_3x5_2(
        ___,           ___,           ___,           ___,            ___,               ___,           KC_F7,         KC_F8,         KC_F9,         KC_F10,
        ___,           XXX,           LCTL(KC_LALT), ___,            ___,               ___,           KC_F4,         KC_F5,         KC_F6,         KC_F11,
        ___,           ___,           ___,           ___,            ___,               ___,           KC_F1,         KC_F2,         KC_F3,         KC_F12,
                                                     ___,            ___,               ___,           ___
    ),
    [7] = LAYOUT_split_3x5_2(
        KC_PSLS,       KC_7,          KC_8,          KC_9,           KC_PPLS,           ___,           ___,           ___,           ___,           ___,
        KC_0,          KC_1,          KC_2,          KC_3,           KC_PMNS,           ___,           ___,           KC_LCTL,       XXX,           ___,
        KC_PAST,       KC_4,          KC_5,          KC_6,           KC_PEQL,           ___,           ___,           ___,           ___,           ___,
                                                     ___,          ___,                 ___,           ___
    ),
    [8] = LAYOUT_split_3x5_2(
        ___,         ___,           KC_COLN,       KC_ESC,         ___,                 ___,         ___,           ___,               ___,              KC_DEL,
        ___,         KC_PERC,       KC_SLSH,       KC_ENT,         ___,                 ___,         KC_LGUI,       ___,               ___,              ___,
        AG_LSWP,     AG_LNRM,       ___,           KC_EXLM,        ___,                 ___,         ___,           RALT_T(KC_COMM),   RCTL_T(KC_DOT),   QK_BOOT,
                                                   ___,            KC_TAB,              XXX,         ___
    )
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        set_unicode_input_mode(UNICODE_MODE_LINUX);
        return false;
    }

    keyrecord_t kr = {
        .event = {
            .pressed = true,
            .time = timer_read()
        }
    };

    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            process_magic(QK_MAGIC_SWAP_ALT_GUI, &kr);
            break;
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            process_magic(QK_MAGIC_UNSWAP_ALT_GUI, &kr);
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            process_magic(QK_MAGIC_UNSWAP_ALT_GUI, &kr);
            break;
        case OS_UNSURE:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
    }

    return true;
}
