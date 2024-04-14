/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "keymap_us_international_linux.h"


// TODO : replace KC_TRNS with _______ in the keymap
// #define _______ KC_TRNSR

/*
Type       Press this key     Then press this key	 Resulting character
Acute      ‘(APOSTROPHE)	     c, e, y, u, i, o, a	 ç, é, ý, ú, í, ó, á
Umlaut     “(QUOTATION MARK)	e, y, u, i, o, a	 ë, ÿ, ü, ï, ö, ä
Grave      `(ACCENT GRAVE)	e, u, i, o, a	      è, ù, ì, ò, à
Tilde      ~(TILDE)	          o, n, a	           õ, ñ, ã
Circumflex ^(CARET)	          e, u, i, o, a	      ê, û, î, ô, â
*/

// custom keycodes used to create the dead key macros
enum custom_keycodes {
     // acute accents and the infamous c cedille
//   US_CCED = SAFE_RANGE,// ç ALLREADY exists as ALTGR(US_COMM),US_CCED
//   US_EACU,             // é ALLREADY exists as ALTGR(US_E),   US_EACU
  US_YACU = SAFE_RANGE,   // ý
//   US_UACU,             // ú ALLREADY exists as ALTGR(US_U),   US_UACU
//   US_IACU,             // í ALLREADY exists as ALTGR(US_I),   US_IACU
//   US_OACU,             // ó ALLREADY exists as ALTGR(US_O),   US_OACU
//   US_AACU,             // á ALLREADY exists as ALTGR(US_A),   US_AACU
  // ¨ umlaut accents
  US_EDIA,             // ë
  US_YDIA,             // ÿ
//   US_UDIA,             // ü ALLREADY exists as ALTGR(US_Y), US_UDIA
  US_IDIA,             // ï
//   US_ODIA,             // ö ALLREADY exists as ALTGR(US_P), US_ODIA
//   US_ADIA,             // ä ALLREADY exists as ALTGR(US_Q), US_ADIA
  // ` grv accents
  US_EGRV,             // è
  US_UGRV,             // ù
  US_IGRV,             // ì
  US_OGRV,             // ò
  US_AGRV,             // à
  // ^ circumflex accents
  US_ECFX,             // ê
  US_YCFX,             // ŷ
  US_UCFX,             // û
  US_ICFX,             // î
  US_OCFX,             // ô
  US_ACFX,             // â
};

// dead key conversion from us intl multi deadkey setup to lafayette single dead key.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case US_YACU:
        if (record->event.pressed) {
            SEND_STRING("'y"); // ý
        }
        break;
    case US_EDIA:
        if (record->event.pressed) {
            SEND_STRING("\"e"); // ë
        }
        break;
    case US_YDIA:
        if (record->event.pressed) {
            SEND_STRING("\"y"); // ÿ
        }
        break;
    case US_IDIA:
        if (record->event.pressed) {
            SEND_STRING("\"i"); // ï
        }
        break;
    case US_EGRV:
        if (record->event.pressed) {
            SEND_STRING("`e"); // è
        }
        break;
    case US_UGRV:
        if (record->event.pressed) {
            SEND_STRING("`u"); // ù
        }
        break;
    case US_IGRV:
        if (record->event.pressed) {
            SEND_STRING("`i"); // ì
        }
        break;
    case US_OGRV:
        if (record->event.pressed) {
            SEND_STRING("`o"); // ò
        }
        break;
    case US_AGRV:
        if (record->event.pressed) {
            SEND_STRING("`a"); // à
        }
        break;
    case US_ECFX:
        if (record->event.pressed) {
            SEND_STRING("^e"); // ê
        }
        break;
    case US_YCFX:
        if (record->event.pressed) {
            SEND_STRING("^y"); // ŷ
        }
        break;
    case US_UCFX:
        if (record->event.pressed) {
            SEND_STRING("^u"); // û
        }
        break;
    case US_ICFX:
        if (record->event.pressed) {
            SEND_STRING("^i"); // î
        }
        break;
    case US_OCFX:
        if (record->event.pressed) {
            SEND_STRING("^o"); // ô
        }
        break;
    case US_ACFX:
        if (record->event.pressed) {
            SEND_STRING("^a"); // â
        }
        break;
    }
    return true;  
};



// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2,
  ALT_GR,
  DK1,
  DK2
};


/* 
 * Key override for shifted keys in alt_gr layer to send different characters
 * The TODO are keys I did not find (yet ?) in the keymap
 */ 
 
// TODO : find ≤
// TODO : find ≥
const key_override_t US_BRKP_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, US_BRKP, 1<<ALT_GR);

/*
 * Key override for shifted keys in DK1 layers to send different characters
 * The TODO are keys I did not find (yet ?) in the keymap
 */
const key_override_t US_LSQU_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, US_LSQU, 1<<DK1);
const key_override_t US_RSQU_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, US_RSQU, 1<<DK1);
const key_override_t US_RSQU_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, US_RSQU, 1<<DK1);
/*
 * Key override for shifted keys in BASE layers to send different characters
 * The TODO are keys I did not find (yet ?) in the keymap
 */ 
const key_override_t US_DQUO_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOTE, US_DQUO, 1<<MAC_BASE | 1<<WIN_BASE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &US_BRKP_key_override,
    &US_DQUO_key_override,
    &US_LSQU_key_override,
    &US_RSQU_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {     
    /* Base layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐ 
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │RGB│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │HOM│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │Caps  │ A │ S │ D │ F │ G │ H │ J │ K │ L │DK1│ ' │    Ent │PGU│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Sft │   │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift │Up │PGD│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │Space                   │Cmd│Fn1│Fn2│Lft│Dwn│Rig│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
[MAC_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     OSL(DK1), US_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LOPT, KC_LCMD,                               KC_SPC,                     MO(ALT_GR),MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     OSL(DK1), US_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                       KC_SPC,                     MO(ALT_GR),MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

/*  ALT_GR layer (dev special chars) DONE
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐ 
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bkspc  │PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │Tab  │ @ │ < │ > │ $ │ % │ ^ │ & │ * │ ' │ ` │ [ │ ] │  \  │PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │Caps  │ { │ ( │ ) │ } │ = │ \ │ + │ - │ / │ " │ ' │    Ent │Ins│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Sft     │ ~ │ [ │ ] │ _ │ # │ | │ ! │ ; │ : │ ? │Shift │Up │Fn │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │Space                   │Alt│Fn1│Fn2│Lft│Dwn│Rig│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
[ALT_GR] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,   KC_AT,    KC_LT,    KC_GT,    KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_PAST,  KC_QUOT,  KC_GRV,   KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  KC_LCBR,  KC_LPRN,  KC_RPRN,  KC_RCBR,  KC_EQL,   KC_BSLS,  KC_PPLS,  KC_PMNS,  KC_SLSH,  KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_TILD,  KC_LBRC,  KC_RBRC,  KC_UNDS,  KC_HASH,  KC_PIPE,  KC_EXLM,  KC_SCLN,  KC_DOT,   KC_QUES,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

// [WIN_FN1] = LAYOUT_ansi_68(
//      KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
//      KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//      RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
//      KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//      KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[FN2] = LAYOUT_ansi_68(
     KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

/* Dead Key first layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐ 
     * │ ` │ 1 │ 2 │ 3 │ 4 │ £ │ 6 │ 7 │ 8 │ ¶ │ 0 │ - │ = │Bkspc  │PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │Tab  │ æ │ é │ è │ ë │ - │ ü │ ù │ ï │ œ │ P │ [ │ ] │  \  │PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │Caps  │ à │ ß │ ê │ - │ G │ ŷ │ û │ î │ ô │DK2│ ' │    Ent │Ins│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Sft │   │ â │ × │ ç │ _ │ B │ N │ M │ , │ . │ / │Shift │Up │Fn │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │ ’                      │Alt│Fn1│Fn2│Lft│Dwn│Rig│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
[DK1] = LAYOUT_ansi_68(
     KC_ESC,   KC_1,     US_LDQU,  US_RDQU,  US_CENT,  S_PND,    US_YEN,   US_CURR,  US_SECT,  US_PILC,   US_DEG,    KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
     KC_TAB,   US_AE,    US_EACU,  US_EGRV,  US_EDIA,  US_MINS,  US_UDIA,  US_UGRV,  US_IDIA,  US_OE,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     KC_CAPS,  US_AGRV,  US_SS,    US_ECFX,  US_MINS,  KC_G,     US_YCFX,  US_UCFX,  US_ICFX,  US_OCFX,  OSL(DK2),  US_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  US_ACFX,  US_MUL,   US_CCED,  US_UNDS,  KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LOPT, KC_LCMD,                                 US_RSQU,                     MO(ALT_GR),MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),
  /* DeadKey second layer
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐ 
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │Bkspc  │PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │Tab  │   │ ẅ │ ë │   │ ẗ │ ÿ │ ü │ ï │ ö │   │   │   │     │PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │Caps  │ ä │   │   │   │   │ ḧ │   │   │   │DK2│   │    Ent │Ins│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Sft │   │   │ ẍ │   │   │   │   │   │   │   │   │Shift │Up │Fn │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │Space                   │Alt│Fn1│Fn2│Lft│Dwn│Rig│
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
     */
[DK2] = LAYOUT_ansi_68(
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSPC,  RGB_MOD,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_ENT,   KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_RSFT,      KC_UP,    KC_PGDN,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_SPC,                       KC_RALT,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT),

// [DK2] = LAYOUT_ansi_68(
//      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, RGB_MOD,
//      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
//      KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     OSL(DD1), KC_QUOT,            KC_ENT,  KC_PGUP,
//      KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,         KC_RSFT,     KC_UP,   KC_PGDN,
//      KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                     MO(ALT_GR),MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

};
