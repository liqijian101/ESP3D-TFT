/*
  esp3d_tft

  Copyright (c) 2022 Luc Lebosse. All rights reserved.

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This code is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <string>

#include "esp3d_hal.h"
#include "esp3d_log.h"
#include "esp3d_styles.h"
#include "esp3d_tft_ui.h"

/**********************
 *  STATIC PROTOTYPES
 **********************/

lv_obj_t *create_back_button(lv_obj_t *parent) {
  lv_obj_t *btn = lv_btn_create(parent);
  lv_obj_t *label = lv_label_create(btn);
  lv_label_set_text(label, " " LV_SYMBOL_NEW_LINE " ");
  lv_obj_center(label);
  apply_style(btn, ESP3DStyleType::button);
  lv_obj_align(btn, LV_ALIGN_BOTTOM_RIGHT, -CURRENT_BUTTON_PRESSED_OUTLINE,
               -CURRENT_BUTTON_PRESSED_OUTLINE);
  return btn;
}