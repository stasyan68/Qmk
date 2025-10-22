#include QMK_KEYBOARD_H
#include "quantum.h"
#include "print.h"
#include "pointing_device.h"
#define CLAMP(val, min, max) ((val) > (max) ? (max) : ((val) < (min) ? (min) : (val)))


void matrix_init_user(void) {
    setPinInputHigh(MOUSE_BTN1_PIN);  // Enable pull-up for Button 1
    setPinInputHigh(MOUSE_BTN2_PIN);  // Enable pull-up for Button 2
    setPinInputHigh(MOUSE_BTN3_PIN);  // Enable pull-up for Button 3
    debug_enable = true;
}

void matrix_scan_user(void) {
    static bool btn1_pressed = false;
    static bool btn2_pressed = false;
    static bool btn3_pressed = false;
    uint16_t x_value = analogReadPin(F0);
    uint16_t y_value = analogReadPin(F1);
    
    // Initialize the report structure

    report_mouse_t report = pointing_device_get_report();


    report.x = CLAMP(report.x, -7, 7);
    report.y = CLAMP(report.y, -7, 7);

    pointing_device_set_report(report);
    pointing_device_send();


    // Debugging Output - Raw Values & Mouse Report
    static uint32_t last_print = 0;
    uint32_t now = timer_read32();
    if (now - last_print > 500) {  // Adjust print frequency to 500 ms
        uprintf("Raw X: %d, Raw Y: %d\n",
                x_value, y_value);
                last_print = now;
    }
    // Button 1

    if (readPin(MOUSE_BTN1_PIN) == 0) {  // Button is pressed (active low)
        if (!btn1_pressed) {
            register_code(KC_MS_BTN1);  // Send mouse button press
            btn1_pressed = true;
        }
    } else if (btn1_pressed) {  // Button is released
        unregister_code(KC_MS_BTN1);  // Send mouse button release
        btn1_pressed = false;
    }

    // Button 2
    if (readPin(MOUSE_BTN2_PIN) == 0) {  // Button is pressed (active low)
        if (!btn2_pressed) {
            register_code(KC_MS_BTN2);  // Send mouse button press
            btn2_pressed = true;
        }
    } else if (btn2_pressed) {  // Button is released
        unregister_code(KC_MS_BTN2);  // Send mouse button release
        btn2_pressed = false;
    }

    // Button 3
    if (readPin(MOUSE_BTN3_PIN) == 0) {  // Button is pressed (active low)
        if (!btn3_pressed) {
            register_code(KC_MS_BTN3);  // Send mouse button press
            btn3_pressed = true;
        }
    } else if (btn3_pressed) {  // Button is released
        unregister_code(KC_MS_BTN3);  // Send mouse button release
        btn3_pressed = false;
    }
}

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESCAPE, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_SLASH, KC_MINUS, KC_EQUAL,
        KC_GRAVE,     KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BACKSPACE,
        KC_CAPS_LOCK, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BACKSLASH,
        KC_QUOTE,     KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_ENTER,
        KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_RIGHT_SHIFT,
        MO(1), KC_LEFT_CTRL, KC_LEFT_ALT, KC_SPACE, KC_RIGHT_ALT, KC_RIGHT_CTRL, MO(1)),
    
    [1] = LAYOUT(
        _______, _______, _______, _______, KC_F11, KC_F12,
        _______,     KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        KC_TAB, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),
};
