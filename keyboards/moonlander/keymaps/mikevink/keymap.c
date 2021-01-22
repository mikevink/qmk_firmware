#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_dvp.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    DP_DLR,         DP_AMPR,            DP_LBRC,            DP_LCBR,                DP_RCBR,                DP_LPRN,            DP_EQL,         KC_PGUP,        DP_ASTR,    DP_RPRN,            DP_PLUS,        DP_RBRC,        DP_EXLM,        DP_HASH,
    KC_TAB,         DP_SCLN,            DP_COMM,            DP_DOT,                 DP_P,                   DP_Y,               KC_HOME,        KC_PGDOWN,      DP_F,       DP_G,               DP_C,           DP_R,           DP_L,           DP_AT,
    KC_CAPSLOCK,    DP_A,               DP_O,               DP_E,                   DP_U,                   DP_I,               KC_END,         DP_SLSH,        DP_D,       DP_H,               DP_T,           DP_N,           DP_S,           DP_MINS,
    KC_LSHIFT,      DP_QUOT,            DP_Q,               DP_J,                   DP_K,                   DP_X,                                               DP_B,       DP_M,               DP_W,           DP_V,           DP_Z,           DP_BSLS,
    KC_NO,          KC_LCTRL,           KC_ESC,             KC_RALT,                KC_LALT,                KC_BSPACE,                                          KC_LGUI,    KC_LEFT,            KC_UP,          KC_DOWN,        KC_RIGHT,       KC_ENTER,
                                                            KC_SPACE,               KC_INSERT,              TO(1),                                              TO(2),      KC_DELETE,          KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,                KC_NO,            KC_NO,                  KC_NO,                  KC_NO,          KC_NO,            KC_NO,            KC_NO,      KC_NO,              KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_NO,
    KC_NO,          KC_F1,                KC_F2,            KC_F3,                  KC_F4,                  KC_NO,          KC_NO,            KC_NO,            KC_NO,      KC_KP_7,            KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_NO,
    KC_NO,          KC_F5,                KC_F6,            KC_F7,                  KC_F8,                  KC_NO,          KC_NO,            KC_NO,            KC_NO,      KC_KP_4,            KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_NO,
    KC_LSHIFT,      KC_F9,                KC_F10,           KC_F11,                 KC_F12,                 KC_NO,                                              KC_NO,      KC_KP_1,            KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_NO,
    KC_NO,          KC_LCTRL,             KC_NO,            KC_NO,                  KC_LALT,                KC_NO,                                              KC_NO,      KC_KP_0,            KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_NO,
                                                            KC_NO,                  KC_NO,                  TO(0),                                              KC_NO,      KC_NO,              KC_NO
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_MEDIA_PREV_TRACK,    KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_NO,          KC_AUDIO_MUTE,      WEBUSB_PAIR,    KC_NO,      RGB_HUI,            RGB_HUD,        KC_NO,          KC_NO,          RESET,
    KC_NO,          KC_NO,                  KC_MS_UP,       KC_NO,                  KC_MS_WH_UP,            KC_NO,          KC_AUDIO_VOL_UP,    KC_NO,          KC_NO,      RGB_MOD,            RGB_SLD,        KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_MS_LEFT,             KC_MS_DOWN,     KC_MS_RIGHT,            KC_MS_WH_DOWN,          KC_NO,          KC_AUDIO_VOL_DOWN,  KC_NO,          KC_NO,      TOGGLE_LAYER_COLOR, RGB_TOG,        KC_NO,          KC_NO,          KC_NO,
    KC_LSHIFT,      KC_NO,                  KC_NO,          KC_NO,                  KC_NO,                  KC_NO,                                              KC_NO,      RGB_SPI,            RGB_SPD,        KC_NO,          KC_NO,          RGB_VAI,
    KC_NO,          KC_LCTRL,               KC_NO,          KC_NO,                  KC_LALT,                KC_MS_BTN3,                                         KC_NO,      RGB_SAI,            RGB_SAD,        KC_NO,          KC_NO,          RGB_VAD,
                                                            KC_MS_BTN1,             KC_MS_BTN2,             KC_NO,                                              KC_NO,      TO(3),              KC_NO
  ),
  [3] = LAYOUT_moonlander(
    KC_GESC,        DP_1,                   DP_2,           DP_3,                   DP_4,                   DP_5,         DP_LBRC,            KC_NO,            DP_6,       DP_7,               DP_8,           DP_9,           DP_0,           KC_NO,
    KC_NO,          DP_Q,                   DP_W,           DP_E,                   DP_R,                   DP_T,         DP_RBRC,            KC_NO,            DP_Y,       DP_U,               DP_I,           DP_O,           DP_P,           KC_NO,
    KC_NO,          DP_A,                   DP_S,           DP_D,                   DP_F,                   DP_G,         KC_F5,              KC_NO,            DP_H,       DP_J,               DP_K,           DP_L,           DP_SCLN,        KC_NO,
    KC_NO,          DP_Z,                   DP_X,           DP_C,                   DP_V,                   DP_B,                                               DP_N,       DP_M,               DP_COMM,        DP_DOT,         DP_SLSH,        KC_NO,
    KC_NO,          KC_LCTRL,               KC_NO,          KC_NO,                  KC_LALT,                KC_BSPACE,                                          KC_LGUI,    KC_LEFT,            KC_UP,          KC_DOWN,        KC_RIGHT,       KC_ENTER,
                                                            KC_SPACE,               KC_INSERT,              KC_ESC,                                             TO(0),      KC_DELETE,          KC_ENTER
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {240,90,90},        {0,0,255},      {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
                                                            {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {240,90,90},        {0,0,255}
  },
  [1] = {
    {0,0,0},        {0,0,0},                {0,0,0},        {0,0,0},                {0,0,0},                {0,0,0},        {0,183,238},        {0,183,238},    {0,183,238},    {0,0,0},            {0,0,0},        {0,183,238},    {0,183,238},    {0,183,238},
    {0,0,0},        {0,0,0},                {0,183,238},    {0,183,238},            {0,183,238},            {0,0,0},        {0,0,0},            {0,183,238},    {0,183,238},    {0,183,238},        {0,0,0},        {0,0,0},        {0,0,0},        {0,0,0},
    {0,0,0},        {0,0,0},                {0,0,0},        {0,0,0},                {0,0,0},                {0,0,0},        {50,153,244},       {0,0,0},        {0,0,0},        {0,0,0},            {0,0,0},        {0,0,0},        {0,0,0},        {134,255,213},
    {134,255,213},  {134,255,213},          {134,255,213},  {134,255,213},          {134,255,213},          {134,255,213},                                      {134,255,213},  {134,255,213},      {134,255,213},  {134,255,213},  {134,255,213},  {134,255,213},
    {134,255,213},  {134,255,213},          {0,0,0},        {134,255,213},          {134,255,213},          {134,255,213},                                      {134,255,213},  {0,0,0},            {0,0,0},        {0,0,0},        {0,0,0},        {0,0,0},
                                                            {0,0,0},                {0,0,0},                {0,0,0},                                            {0,0,0},        {0,0,0},            {0,0,0}
  },
  [2] = {
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {134,255,213}, {0,0,0}, {35,255,255}, {85,203,158}, {134,255,213}, {134,255,213}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {11,242,248}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {50,153,244}, {0,0,0}
  },
  [3] = {
    {169,120,255}, {32,255,234}, {32,255,234}, {154,255,255}, {154,255,255}, {169,120,255}, {169,120,255}, {154,255,255}, {169,120,255}, {0,0,0}, {169,120,255}, {154,255,255}, {154,255,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {154,255,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {154,255,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {32,255,234}, {154,255,255}, {32,255,234}, {32,255,234}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {32,255,234}, {0,0,0}, {154,255,255}
  },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
