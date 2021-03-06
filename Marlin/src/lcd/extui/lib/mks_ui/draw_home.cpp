/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
//ADDED TEMPERATURES TO UI FOR FOKOOS ODIN !!

#include "../../../../inc/MarlinConfigPre.h"

#if HAS_TFT_LVGL_UI

#include "draw_set.h"
#include "draw_ui.h"
#include <lv_conf.h>

#include "../../../../gcode/queue.h"
#include "../../../../inc/MarlinConfig.h"
#include "../../../../module/temperature.h"

extern lv_group_t *g;
static lv_obj_t *scr;

static lv_obj_t *labelExt1;
static lv_obj_t *buttonExt1;

#if HAS_HEATED_BED
  static lv_obj_t *buttonBedstate;
  static lv_obj_t* labelBed;
#endif

enum {
  ID_H_ALL = 1,
  ID_H_X,
  ID_H_Y,
  ID_H_Z,
  ID_H_RETURN,
  ID_H_OFF_ALL,
  ID_H_OFF_XY,
  ID_INFO_EXT,
  ID_INFO_BED
};

static void event_handler(lv_obj_t *obj, lv_event_t event) {
  if (event != LV_EVENT_RELEASED) return;
  switch (obj->mks_obj_id) {
    case ID_H_ALL:
      queue.inject_P(G28_STR);
      break;
    case ID_H_X:
      queue.inject_P(PSTR("G28X"));
      break;
    case ID_H_Y:
      queue.inject_P(PSTR("G28Y"));
      break;
    case ID_H_Z:
      queue.inject_P(PSTR("G28Z"));
      break;
    case ID_H_OFF_ALL:
      queue.inject_P(PSTR("M84"));
      break;
    case ID_H_OFF_XY:
      queue.inject_P(PSTR("M84XY"));
      break;
    case ID_H_RETURN:
      lv_clear_cur_ui();
      lv_draw_return_ui();
      break;
  }
}

void lv_draw_home(void) {
  //lv_clear_cur_ui();
  scr = lv_screen_create(ZERO_UI);
  lv_big_button_create(scr, "F:/bmp_zeroAll.bin", home_menu.home_all, INTERVAL_V, titleHeight, event_handler, ID_H_ALL);
  lv_big_button_create(scr, "F:/bmp_zeroX.bin", home_menu.home_x, BTN_X_PIXEL + INTERVAL_V * 2, titleHeight, event_handler, ID_H_X);
  lv_big_button_create(scr, "F:/bmp_zeroY.bin", home_menu.home_y, BTN_X_PIXEL * 2 + INTERVAL_V * 3, titleHeight, event_handler, ID_H_Y);
  lv_big_button_create(scr, "F:/bmp_zeroZ.bin", home_menu.home_z, BTN_X_PIXEL * 3 + INTERVAL_V * 4, titleHeight, event_handler, ID_H_Z);
  lv_big_button_create(scr, "F:/bmp_function1.bin", set_menu.motoroff, INTERVAL_V, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_H_OFF_ALL);
  lv_big_button_create(scr, "F:/bmp_function1.bin", set_menu.motoroffXY, BTN_X_PIXEL + INTERVAL_V * 2, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_H_OFF_XY);
  lv_big_button_create(scr, "F:/bmp_return.bin", common_menu.text_back, BTN_X_PIXEL * 3 + INTERVAL_V * 4, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_H_RETURN);
  //create temp labels
  lv_big_button_create(scr, "F:/bmp_bed_state.bin", " ", 220, 1, event_handler, ID_INFO_BED);
  lv_big_button_create(scr, "F:/bmp_ext1_state.bin", " ", 300, 1, event_handler, ID_INFO_EXT);
  labelBed = lv_label_create(scr, 260, 1, nullptr);
  labelExt1 = lv_label_create(scr, 340, 1, nullptr);
  disp_ext_temp_home();
  disp_bed_temp_home();
}

void disp_ext_temp_home() {
  sprintf(public_buf_l, printing_menu.temp1, (int)thermalManager.degHotend(0), (int)thermalManager.degTargetHotend(0));
  lv_label_set_text(labelExt1, public_buf_l);

  #if HAS_MULTI_EXTRUDER && DISABLED(SINGLENOZZLE)
    sprintf(public_buf_l, printing_menu.temp1, (int)thermalManager.degHotend(1), (int)thermalManager.degTargetHotend(1));
    lv_label_set_text(labelExt2, public_buf_l);
  #endif
}

void disp_bed_temp_home() {
  #if HAS_HEATED_BED
    sprintf(public_buf_l, printing_menu.bed_temp, (int)thermalManager.temp_bed.celsius, (int)thermalManager.temp_bed.target);
    lv_label_set_text(labelBed, public_buf_l);
  #endif
}

void lv_clear_home() {
  #if HAS_ROTARY_ENCODER
    if (gCfgItems.encoder_enable) lv_group_remove_all_objs(g);
  #endif
  lv_obj_del(scr);
}

#endif // HAS_TFT_LVGL_UI
