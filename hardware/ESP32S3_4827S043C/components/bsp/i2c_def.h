// I2C definitions for ESP32_4827S043C
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "i2c_bus.h"

// I2C definitions
#define I2C_PORT_NUMBER 0

// Configure I2C
const i2c_config_t i2c_cfg = {.mode = I2C_MODE_MASTER,
                              .scl_io_num = 20,  // GPIO 20
                              .sda_io_num = 19,  // GPIO 19
                              .scl_pullup_en = GPIO_PULLUP_ENABLE,
                              .sda_pullup_en = GPIO_PULLUP_ENABLE,
                              .master.clk_speed = 400 * 1000};

#ifdef __cplusplus
} /* extern "C" */
#endif
