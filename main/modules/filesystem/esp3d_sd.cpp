/*
  esp_sd.cpp - ESP3D SD support class

  Copyright (c) 2014 Luc Lebosse. All rights reserved.

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This code is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with This code; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "sd_def.h"
#include "esp3d_sd.h"
#include <stdio.h>
#include <string.h>
#include "esp_log.h"

#define LOG_TAG "SD_GLOBAL"

ESP_SD sd;

ESP_SD::ESP_SD()
{
    _mounted = false;
    _started = false;
    _spi_speed_divider = 1;
    _state = ESP3D_SDCARD_UNKNOWN;
}

esp3d_fs_types ESP_SD::getFSType(const char * path)
{
    (void)path;
    return FS_SD;
}

bool  ESP_SD::accessFS(esp3d_fs_types FS)
{
    (void)FS;
    //if card is busy do not let another task access SD and so prevent a release
    if (_state == ESP3D_SDCARD_BUSY) {
        ESP_LOGI(LOG_TAG, "SDCard Busy.");
        return false;
    }
    ESP_LOGI(LOG_TAG,"Access SD");
    return true;

}

void  ESP_SD::releaseFS(esp3d_fs_types FS)
{
    (void)FS;
    ESP_LOGI(LOG_TAG,"Release SD");
    setState(ESP3D_SDCARD_IDLE);
}

//helper to format size to readable string
const char* ESP_SD::formatBytes (uint64_t bytes)
{
    static char buffer[32];
    memset(buffer, 0, sizeof(buffer));
    int res = 0;
    if (bytes < 1024) {
        res = snprintf(buffer, sizeof(buffer), "%d B", (int)bytes);
    } else if (bytes < (1024 * 1024) ) {
        res =  snprintf(buffer, sizeof(buffer), "%.2f KB", ((float)(bytes / 1024.0)));
    } else if (bytes < (1024 * 1024 * 1024) ) {
        res =  snprintf(buffer, sizeof(buffer), "%.2f MB", ((float)(bytes / 1024.0 / 1024.0)));
    } else {
        res =  snprintf(buffer, sizeof(buffer), "%.2f GB", ((float)(bytes / 1024.0 / 1024.0 / 1024.0)));
    }
    if (res < 0) {
        strcpy(buffer, "? B");
    }
    return buffer;
}