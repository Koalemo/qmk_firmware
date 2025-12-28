#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#ifndef COLORS
#define COLORS
// colors
#define PURP {131,255,255}
#define YELLOW {41,255,255}
#define BLUE {219,255,255}
#define BRIGHTORANGE {82,255,255}
#define PINK {90,255,255}
#define RED {95,255,255}
#define ORANGE {70,255,206}
#define BRIGHTBLUE {240,255,255}


// color mappings
#define COL_TAB YELLOW
#define COL_SPACE YELLOW
#define COL_ESC PURP
#define COL_MO_1 BLUE
#define COL_BSPC PINK
#define COL_CTL RED
#define COL_ENTER BRIGHTORANGE
#define COL_GUI ORANGE
#define COL_SHIFT BRIGHTBLUE

#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_245_245,
  HSV_74_255_206,
  HSV_152_255_255,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       KC_BSPC,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,                                           TG(1),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
        MT(MOD_LCTL, KC_TAB), KC_A,     KC_S,           KC_D,           KC_F,           KC_G,           KC_HYPR,                                        KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           LT(2, KC_SCLN), KC_QUOTE,
        MT(MOD_LSFT, KC_GRAVE),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH), OSM(MOD_RSFT),
        OSM(MOD_LCTL) ,          CW_TOGG,        KC_LEFT,        KC_RIGHT,       MT(MOD_LGUI, KC_SPACE),       MT(MOD_LALT, KC_APPLICATION),                                   MT(MOD_LCTL, KC_ESCAPE),        MT(MOD_LSFT, KC_SPACE),       KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,
        KC_LEFT_GUI,    KC_SPACE,       KC_LEFT_GUI,                    KC_LEFT_ALT,    KC_SPACE,       KC_ENTER
      ),
      [1] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
        KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT,
        KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     KC_TRANSPARENT,
        KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_TRANSPARENT,
        KC_TRANSPARENT, KC_COMMA,       HSV_0_245_245,  HSV_74_255_206, HSV_152_255_255,RGB_MODE_FORWARD,                                                                                                RGB_TOG,        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
        RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
      ),
      [2] = LAYOUT_moonlander(
        AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
        MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        MU_NEXT,        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
      ),
    };





    extern rgb_config_t rgb_matrix_config;

    RGB hsv_to_rgb_with_value(HSV hsv) {
      RGB rgb = hsv_to_rgb( hsv );
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
    }

    void keyboard_post_init_user(void) {
      rgb_matrix_enable();
    }

    const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
        [0] = { COL_ESC,      COL_TAB,       COL_CTL,       COL_SHIFT,      COL_CTL,     // Escape   Tab Ctrl Shift  LT(1, backtick)
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // 1 q a z CW_TOGGLE
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // 2 w s x KC_LEFT
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // 3 e d c KC_RIGHT
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      COL_SPACE,     // 4 r f v KC_SPACE
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},                     // 5 t g b
                 {0,0,0},     {0,0,0},       {0,0,0},                                    // 6 y KC_HYPR
                 COL_GUI, COL_SPACE, COL_GUI,  {0,0,0},                                  // KC_SPACE, KC_SPACE, LEFT_GUI, BIGREDLEFT
                 COL_BSPC,    {0,0,0},       {0,0,0},       COL_SHIFT,    COL_MO_1,      // KC_BSPC KC_BSLS KC_QUOTE KC_RSFT]
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // - p ; / [
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // = o l . KC_DOWN
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},       // 0 i k , KC_UP
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},      COL_SPACE,     // 9 u j m KC_SPACE
                 {0,0,0},     {0,0,0},       {0,0,0},       {0,0,0},                     // 8 y h n
                 {0,0,0},     COL_MO_1,      {0,0,0},                                    // 7 TG(1) KC_MEH
                 COL_ENTER,   COL_SPACE, {0,0,0}, {0,0,0} },                             // ctrl KC_SPACE KC_LEFT_ALT BIGREDRIGHT
    };

    void set_layer_color(int layer) {
      for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
          .h = pgm_read_byte(&ledmap[layer][i][0]),
          .s = pgm_read_byte(&ledmap[layer][i][1]),
          .v = pgm_read_byte(&ledmap[layer][i][2]),
        }; if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb_with_value(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
      }
    }

    bool rgb_matrix_indicators_user(void) {
      if (rawhid_state.rgb_control) {
          return false;
      }
      if (!keyboard_config.disable_layer_led) {
        switch (biton32(layer_state)) {
          case 0:
            set_layer_color(0);
            break;
         default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
              rgb_matrix_set_color_all(0, 0, 0);
            }
        }
      } else {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
      }

      return true;
    }




    // Initialize variable holding the binary
    // representation of active modifiers.
    uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
    // allow to handle multiple macro...
  case QK_MODS ... QK_MODS_MAX:
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    // Shift+Backspace -> Del
    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_245_245:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,245,245);
        }
        return false;
    case HSV_74_255_206:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(74,255,206);
        }
        return false;
    case HSV_152_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(152,255,255);
        }
        return false;
  }
  return true;
}

