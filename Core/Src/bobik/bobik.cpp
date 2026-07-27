#include "bobik/bobik.h"
#include "bobik/log.h"
#include "stm32h5xx.h"
#include <stdio.h>
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

#define OLED_ADDR 0x78

void bobik_start()
{
    log_init();
    printf("Searching for OLED...\n");

    if (HAL_I2C_IsDeviceReady(&hi2c1, 0x78, 3, 100) == HAL_OK) {
        printf("BINGO! OLED found at 0x78\n");
    }
    else if (HAL_I2C_IsDeviceReady(&hi2c1, 0x7A, 3, 100) == HAL_OK) {
        printf("BINGO! OLED found at 0x7A (Change OLED_ADDR in code!)\n");
    }
    else {
        printf("OLED IS DEAD OR DISCONNECTED. Check wires!\n");
    }
}

void oled_write_cmd(uint8_t cmd) {
    uint8_t data[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDR, data, 2, HAL_MAX_DELAY);
}

void oled_init(void) {
    HAL_Delay(100);

    oled_write_cmd(0xAE);
    oled_write_cmd(0x20);
    oled_write_cmd(0x00);
    oled_write_cmd(0xC8);
    oled_write_cmd(0x00);
    oled_write_cmd(0x10);
    oled_write_cmd(0x40);
    oled_write_cmd(0x81);
    oled_write_cmd(0xFF);
    oled_write_cmd(0xA1);
    oled_write_cmd(0xA6);
    oled_write_cmd(0xA8);
    oled_write_cmd(0x3F);
    oled_write_cmd(0xA4);
    oled_write_cmd(0xD3);
    oled_write_cmd(0x00);
    oled_write_cmd(0xD5);
    oled_write_cmd(0xF0);
    oled_write_cmd(0xD9);
    oled_write_cmd(0x22);
    oled_write_cmd(0xDA);
    oled_write_cmd(0x12);
    oled_write_cmd(0xDB);
    oled_write_cmd(0x20);

    oled_write_cmd(0x8D);
    oled_write_cmd(0x14);
    oled_write_cmd(0xAF);
}

void oled_fill(void) {
    for (int page = 0; page < 8; page++) {
        oled_write_cmd(0xB0 + page);
        oled_write_cmd(0x00);
        oled_write_cmd(0x10);

        for (int i = 0; i < 128; i++) {
            uint8_t data[2] = {0x40, 0xFF};
            HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDR, data, 2, HAL_MAX_DELAY);
        }
    }
}
