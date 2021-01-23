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

// todo: caps lock indicator maybe?

// colours to use in the keymap
//                  H    S    V
#define V_COL_DED {  0,   0,   0}
#define V_COL_SMB {  0,   0, 255}
#define V_COL_SPC {127, 255, 255}
#define V_COL_MOD { 21, 255, 255}
#define V_COL_NAV {148, 255, 255}
#define V_COL_MED { 85, 255, 255}
#define V_COL_RGB { 35, 255, 255}
#define V_COL_FN  {  0, 183, 238}
#define V_COL_KP  {134, 255, 213}
#define V_COL_RST {  0, 255, 255}
#define V_COL_ORX { 64, 255, 255}
#define V_COL_GUI V_COL_ORX
const HSV V_COL_LYR[] = {
    [0] =         {  0,   0, 255},
    [1] =         {169, 255, 255},
    [2] =         { 85, 255, 255},
    [3] =         {  0, 255, 255},
};

// helpers for key definition
typedef struct PACKED {
    uint16_t key;
    HSV hsv; // color.h, uint8_t {h, s, v}
} V_KEY_DEF;
#define V_DED       {    KC_NO,        V_COL_DED}
#define V_SMB(key)  {      key,        V_COL_SMB}
#define V_SPC(key)  {      key,        V_COL_SPC}
#define V_MOD(key)  {      key,        V_COL_MOD}
#define V_NAV(key)  {      key,        V_COL_NAV}
#define V_MED(key)  {      key,        V_COL_MED}
#define V_RGB(key)  {      key,        V_COL_RGB}
#define V_FN(key)   {      key,         V_COL_FN}
#define V_KP(key)   {      key,         V_COL_KP}
#define V_RST(key)  {      key,        V_COL_RST}
#define V_ORX(key)  {      key,        V_COL_ORX}
#define V_GUI(key)  {      key,        V_COL_GUI}
#define V_TO(layer) {TO(layer), V_COL_LYR[layer]}

// keymaps go here, arranged in the RGB setup
// that means first 36 entries are the left side of the keyboard, top to bottom, left to right
//        the last 36 entries are the right side of the keyboard, top to bottom, right to left
const V_KEY_DEF PROGMEM v_keymaps[][DRIVER_LED_TOTAL] = {
    [0] = {
        // left half, top to bottom, left to right
        V_SMB(DP_DLR),          V_SPC(KC_TAB),              V_MOD(KC_CAPSLOCK),         V_MOD(KC_LSHIFT),   V_DED,
        V_SMB(DP_AMPR),         V_SMB(DP_SCLN),             V_SMB(DP_A),                V_SMB(DP_QUOT),     V_MOD(KC_LCTRL),
        V_SMB(DP_LBRC),         V_SMB(DP_COMM),             V_SMB(DP_O),                V_SMB(DP_Q),        V_GUI(KC_ESC),
        V_SMB(DP_LCBR),         V_SMB(DP_DOT),              V_SMB(DP_E),                V_SMB(DP_J),        V_MOD(KC_RALT),
        V_SMB(DP_RCBR),         V_SMB(DP_P),                V_SMB(DP_U),                V_SMB(DP_K),        V_MOD(KC_LALT),
        V_SMB(DP_LPRN),         V_SMB(DP_Y),                V_SMB(DP_I),                V_SMB(DP_X),
        V_SMB(DP_EQL),          V_NAV(KC_HOME),             V_NAV(KC_END),
        // left flap
        V_SPC(KC_SPACE),        V_SPC(KC_INSERT),           V_TO(1),
        V_SPC(KC_BSPACE),
        // right half, top to bottom, right to left
        V_SMB(DP_HASH),         V_SMB(DP_AT),               V_SMB(DP_MINS),             V_SMB(DP_BSLS),     V_SPC(KC_ENTER),
        V_SMB(DP_EXLM),         V_SMB(DP_L),                V_SMB(DP_S),                V_SMB(DP_Z),        V_NAV(KC_RIGHT),
        V_SMB(DP_RBRC),         V_SMB(DP_R),                V_SMB(DP_N),                V_SMB(DP_V),        V_NAV(KC_DOWN),
        V_SMB(DP_PLUS),         V_SMB(DP_C),                V_SMB(DP_T),                V_SMB(DP_W),        V_NAV(KC_UP),
        V_SMB(DP_RPRN),         V_SMB(DP_G),                V_SMB(DP_H),                V_SMB(DP_M),        V_NAV(KC_LEFT),
        V_SMB(DP_ASTR),         V_SMB(DP_F),                V_SMB(DP_D),                V_SMB(DP_B),
        V_NAV(KC_PGUP),         V_NAV(KC_PGDOWN),           V_SMB(DP_SLSH),
        // right flap
        V_TO(2),                V_SPC(KC_DELETE),           V_SPC(KC_ENTER),
        V_GUI(KC_LGUI),
    },
    [1] = {
        // left half, top to bottom, left to right
        V_DED,                  V_DED,                      V_DED,                      V_MOD(KC_LSHIFT),   V_DED,
        V_DED,                  V_FN(KC_F1),                V_FN(KC_F5),                V_FN(KC_F9),        V_MOD(KC_LCTRL),
        V_DED,                  V_FN(KC_F2),                V_FN(KC_F6),                V_FN(KC_F10),       V_DED,
        V_DED,                  V_FN(KC_F3),                V_FN(KC_F7),                V_FN(KC_F11),       V_DED,
        V_DED,                  V_FN(KC_F4),                V_FN(KC_F8),                V_FN(KC_F12),       V_MOD(KC_LALT),
        V_DED,                  V_DED,                      V_DED,                      V_DED,
        V_DED,                  V_DED,                      V_DED,
        // left flap
        V_DED,                  V_DED,                      V_TO(0),
        V_DED,
        // right half, top to bottom, right to left
        V_DED,                  V_DED,                      V_DED,                      V_DED,              V_DED,
        V_KP(KC_KP_MINUS),      V_KP(KC_KP_PLUS),           V_KP(KC_KP_PLUS),           V_KP(KC_KP_ENTER),  V_KP(KC_KP_ENTER),
        V_KP(KC_KP_ASTERISK),   V_KP(KC_KP_9),              V_KP(KC_KP_6),              V_KP(KC_KP_3),      V_KP(KC_KP_DOT),
        V_KP(KC_KP_SLASH),      V_KP(KC_KP_8),              V_KP(KC_KP_5),              V_KP(KC_KP_2),      V_KP(KC_KP_0),
        V_DED,                  V_KP(KC_KP_7),              V_KP(KC_KP_4),              V_KP(KC_KP_1),      V_KP(KC_KP_0),
        V_DED,                  V_DED,                      V_DED,                      V_DED,
        V_DED,                  V_DED,                      V_DED,
        // right flap
        V_DED,                  V_DED,                      V_DED,
        V_DED,
    },
    [2] = {
        // left half, top to bottom, left to right
        V_DED,                      V_DED,                  V_DED,                      V_MOD(KC_LSHIFT),   V_DED,
        V_MED(KC_MEDIA_PREV_TRACK), V_DED,                  V_NAV(KC_MS_LEFT),          V_DED,              V_MOD(KC_LCTRL),
        V_MED(KC_MEDIA_STOP),       V_NAV(KC_MS_UP),        V_NAV(KC_MS_DOWN),          V_DED,              V_DED,
        V_MED(KC_MEDIA_PLAY_PAUSE), V_DED,                  V_NAV(KC_MS_RIGHT),         V_DED,              V_DED,
        V_MED(KC_MEDIA_NEXT_TRACK), V_NAV(KC_MS_WH_UP),     V_NAV(KC_MS_WH_DOWN),       V_DED,              V_MOD(KC_LALT),
        V_DED,                      V_DED,                  V_DED,                      V_DED,
        V_MED(KC_AUDIO_MUTE),       V_MED(KC_AUDIO_VOL_UP), V_MED(KC_AUDIO_VOL_DOWN),
        // left flap
        V_NAV(KC_MS_BTN1),          V_NAV(KC_MS_BTN2),      V_DED,
        V_NAV(KC_MS_BTN3),
        // right half, top to bottom, right to left
        V_RST(RESET),               V_DED,                  V_DED,                      V_RGB(RGB_VAI),     V_RGB(RGB_VAD),
        V_DED,                      V_DED,                  V_DED,                      V_DED,              V_DED,
        V_DED,                      V_DED,                  V_DED,                      V_DED,              V_DED,
        V_RGB(RGB_HUD),             V_RGB(RGB_SLD),         V_RGB(RGB_TOG),             V_RGB(RGB_SPD),     V_RGB(RGB_SAD),
        V_RGB(RGB_HUI),             V_RGB(RGB_MOD),         V_RGB(TOGGLE_LAYER_COLOR),  V_RGB(RGB_SPI),     V_RGB(RGB_SAI),
        V_DED,                      V_DED,                  V_DED,                      V_DED,
        V_ORX(WEBUSB_PAIR),         V_DED,                  V_DED,
        // right flap
        V_TO(0),                    V_TO(3),                V_DED,
        V_DED,
    },
    [3] = {
        // left half, top to bottom, left to right
        V_GUI(KC_GESC),             V_DED,                  V_DED,                      V_DED,              V_DED,
        V_SMB(DP_1),                V_SMB(DP_Q),            V_SMB(DP_A),                V_SMB(DP_Z),        V_MOD(KC_LCTRL),
        V_SMB(DP_2),                V_SMB(DP_W),            V_SMB(DP_S),                V_SMB(DP_X),        V_DED,
        V_SMB(DP_3),                V_SMB(DP_E),            V_SMB(DP_D),                V_SMB(DP_C),        V_DED,
        V_SMB(DP_4),                V_SMB(DP_R),            V_SMB(DP_F),                V_SMB(DP_V),        V_MOD(KC_LALT),
        V_SMB(DP_5),                V_SMB(DP_T),            V_SMB(DP_G),                V_SMB(DP_B),
        V_SMB(DP_LBRC),             V_SMB(DP_RBRC),         V_FN(KC_F5),
        // left flap
        V_SPC(KC_SPACE),            V_SPC(KC_INSERT),       V_GUI(KC_ESC),
        V_SPC(KC_BSPACE),
        // right half, top to bottom, right to left
        V_DED,                      V_DED,                  V_DED,                      V_DED,              V_SPC(KC_ENTER),
        V_SMB(DP_0),                V_SMB(DP_P),            V_SMB(DP_SCLN),             V_SMB(DP_SLSH),     V_NAV(KC_RIGHT),
        V_SMB(DP_9),                V_SMB(DP_O),            V_SMB(DP_L),                V_SMB(DP_DOT),      V_NAV(KC_DOWN),
        V_SMB(DP_8),                V_SMB(DP_I),            V_SMB(DP_K),                V_SMB(DP_COMM),     V_NAV(KC_UP),
        V_SMB(DP_7),                V_SMB(DP_U),            V_SMB(DP_J),                V_SMB(DP_M),        V_NAV(KC_LEFT),
        V_SMB(DP_6),                V_SMB(DP_Y),            V_SMB(DP_H),                V_SMB(DP_N),
        V_DED,                      V_DED,                  V_DED,
        // right flap
        V_TO(0),                    V_SPC(KC_DELETE),       V_SPC(KC_ENTER),
        V_GUI(KC_LGUI),
    },
};



// left to right, top to bottom
// big red buttons are in line with the first to last row
// last 6 keys are ltr as well
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
                                                            KC_MS_BTN1,             KC_MS_BTN2,             KC_NO,                                              TO(0),      TO(3),              KC_NO
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

// top to bottom, left to right
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
    // left half, top to bottom, left to right
    {0,0,255},    {32,255,234},    {32,255,234},    {32,255,234},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},    {0,0,0},    {0,0,0},
    // left flap
    {0,0,0},    {0,0,0},    {169, 255,255},
    {0,255,255},
    // right half, top to bottom, right to left
    {0,255,255},    {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,255},      {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},        {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},        {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},        {0,0,0},    {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},        {0,0,0},    {0,0,0},    {0,0,0},
    {0,0,0},        {0,0,0},    {0,0,0},
    // right flap
    {0,0,0},        {0,0,0},    {0,0,0},
    {0,0,0}
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
