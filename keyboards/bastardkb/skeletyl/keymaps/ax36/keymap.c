#include QMK_KEYBOARD_H
#include "definitions.h"
#include "layers.h"
#include "os_specific/os_specific.h"
#include "oneshot/oneshot.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)


qk_tap_dance_action_t tap_dance_actions[] = {};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, BASE_LAYER),
  [NAV] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, NAV_LAYER),
  [MOUSE] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, MOUSE_LAYER),
  [NUM] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, NUM_LAYER),
  [SYM] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, SYM_LAYER),
  [FUN] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, FUN_LAYER),
  [MEDIA] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, MEDIA_LAYER),
  [CODE] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3, CODE_LAYER)
};




bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case TO(BASE):
    case LT(NAV, KC_SPC):
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case TO(BASE):
    case LT(NAV, KC_ESC):
    case TO(NUM):
    case LT(CODE, KC_BSPC):
    case TO(SYM):
    case LT(MEDIA, KC_COMM):
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}


oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AX36_COPY:
      if (record->event.pressed) { os_specific_copy(); }
      return false; // Skip all further processing of this key

    case AX36_PASTE:
      if (record->event.pressed) { os_specific_paste(); }
      return false;

    case AX36_LOCK:
      if (record->event.pressed) { os_specific_lock(); }
      return false;

    case AX36_SCRNSHT:
      if (record->event.pressed) { os_specific_screenshot(); }
      return false;

    case AX36_SCRNSHT_TO_CLIP:
      if (record->event.pressed) { os_specific_screenshot_to_clipboard(); }
      return false;

    case AX36_SCREEN_RECORD:
      if (record->event.pressed) { os_specific_record(); }
      return false;

    case AX36_INDICATE_OS:
      if (record->event.pressed) { os_specific_indicate_os(); }
      return false;

    default:
      update_oneshot(
          &os_shft_state, KC_LSFT, OS_SHFT,
          keycode, record
      );
      update_oneshot(
          &os_ctrl_state, KC_LCTL, OS_CTRL,
          keycode, record
      );
      update_oneshot(
          &os_alt_state, KC_LALT, OS_ALT,
          keycode, record
      );
      update_oneshot(
          &os_cmd_state, KC_LCMD, OS_CMD,
          keycode, record
      );
      return true; // Process all other keycodes normally
  }
}
