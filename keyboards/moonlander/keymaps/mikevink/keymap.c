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
    DP_DLR,         DP_AMPR,                DP_LBRC,        DP_LCBR,                DP_RCBR,                DP_LPRN,        DP_EQL,             KC_PGUP,        KC_ASTR,    KC_RPRN,            KC_PLUS,        KC_RBRACKET,    KC_EXLM,        KC_HASH,
    KC_TAB,         KC_SCOLON,              KC_COMMA,       KC_DOT,                 KC_P,                   KC_Y,           KC_END,             KC_PGDOWN,      KC_F,       KC_G,               KC_C,           KC_R,           KC_L,           KC_AT,
    KC_CAPSLOCK,    KC_A,                   KC_O,           KC_E,                   KC_U,                   KC_I,           KC_AMPR,            KC_SLASH,       KC_D,       KC_H,               KC_T,           KC_N,           KC_S,           KC_BSLASH,
    KC_LSHIFT,      KC_QUOTE,               KC_Q,           KC_J,                   KC_K,                   KC_X,                                               KC_B,       KC_M,               KC_W,           KC_V,           KC_Z,           KC_MINUS,
    KC_LCTRL,       KC_TRNS,                KC_ESCAPE,      KC_RALT,                KC_LALT,                KC_BSPACE,                                          KC_LGUI,    KC_LEFT,            KC_UP,          KC_DOWN,        KC_RIGHT,       KC_ENTER,
                                                            KC_SPACE,               KC_INSERT,              TG(1),                                              TG(2),      KC_DELETE,          KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,                KC_TRNS,                KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,    KC_TRNS,            KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_TRNS,
    KC_TRNS,        KC_F1,                  KC_F2,          KC_F3,                  KC_F4,                  KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,    KC_KP_7,            KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_TRNS,
    KC_TRNS,        KC_F5,                  KC_F6,          KC_F7,                  KC_F8,                  KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,    KC_KP_4,            KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRNS,
    KC_TRNS,        KC_F9,                  KC_F10,         KC_F11,                 KC_F12,                 KC_TRNS,                                            KC_TRNS,    KC_KP_1,            KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRNS,
    KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,                KC_TRNS,                KC_TRNS,                                            KC_TRNS,    KC_KP_0,            KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_TRNS,
                                                            KC_TRNS,                KC_TRNS,                KC_TRNS,                                            KC_TRNS,    KC_TRNS,            KC_TRNS
  ),
  [2] = LAYOUT_moonlander(
    KC_TRNS,        KC_MEDIA_PREV_TRACK,    KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    KC_TRNS,        KC_AUDIO_MUTE,      WEBUSB_PAIR,    KC_TRNS,    RGB_HUI,            RGB_HUD,        KC_TRNS,        KC_TRNS,        RESET,
    KC_TRNS,        KC_TRNS,                KC_MS_UP,       KC_TRNS,                KC_MS_WH_UP,            KC_TRNS,        KC_AUDIO_VOL_UP,    KC_TRNS,        KC_TRNS,    RGB_MOD,            RGB_SLD,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_MS_LEFT,             KC_MS_DOWN,     KC_MS_RIGHT,            KC_MS_WH_DOWN,          KC_TRNS,        KC_AUDIO_VOL_DOWN,  KC_TRNS,        KC_TRNS,    TOGGLE_LAYER_COLOR, RGB_TOG,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,                KC_TRNS,                KC_TRNS,                                            KC_TRNS,    RGB_SPI,            RGB_SPD,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,                KC_TRNS,        RGB_VAD,                RGB_VAI,                KC_MS_BTN3,                                         KC_TRNS,    RGB_SAI,            RGB_SAD,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                            KC_MS_BTN1,             KC_MS_BTN2,             KC_TRNS,                                            KC_TRNS,    TO(3),              KC_TRNS
  ),
  [3] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,                   KC_2,           KC_3,                   KC_4,                   KC_5,           KC_RBRACKET,        KC_TRNS,        KC_6,       KC_7,               KC_8,           KC_9,           KC_0,           KC_TRNS,
    KC_TRNS,        KC_Q,                   KC_W,           KC_E,                   KC_R,                   KC_T,           KC_LBRACKET,        KC_TRNS,        KC_Y,       KC_U,               KC_I,           KC_O,           KC_P,           KC_TRNS,
    KC_TRNS,        KC_A,                   KC_S,           KC_D,                   KC_F,                   KC_G,           KC_F5,              KC_TRNS,        KC_H,       KC_J,               KC_K,           KC_L,           KC_SCOLON,      KC_TRNS,
    KC_TRNS,        KC_Z,                   KC_X,           KC_C,                   KC_V,                   KC_B,                                               KC_N,       KC_M,               KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRNS,
    KC_TRNS,        KC_TRNS,                KC_TRNS,        KC_TRNS,                KC_TRNS,                KC_TRNS,                                            KC_TRNS,    KC_TRNS,            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                            KC_TRNS,                KC_TRNS,                KC_ESCAPE,                                          TO(0),      KC_TRNS,            KC_TRNS
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {0,0,255},         {0,0,255},       {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {0,0,255},         {0,0,255},       {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},      {50,153,244},      {0,0,255},       {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
    {0,0,255},      {0,0,255},              {0,0,255},      {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {0,0,255},          {0,0,255},      {0,0,255},      {0,0,255},      {0,0,255},
                                                            {0,0,255},              {0,0,255},              {0,0,255},                                          {0,0,255},      {50,153,244},       {0,0,255}
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
