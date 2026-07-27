#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void bobik_start(void);

void oled_init(void);

void oled_fill(void);

void oled_write_cmd(uint8_t cmd);

#ifdef __cplusplus
}
#endif
