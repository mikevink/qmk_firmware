/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 600000

#define FIRMWARE_VERSION u8"0qBOP/v5rqQ"
#define RGB_MATRIX_STARTUP_SPD 60

#define MOUSEKEY_DELAY 100
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 5
