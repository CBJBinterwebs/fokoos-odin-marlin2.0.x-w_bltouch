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
//ADDED MENU OPTIONS FOR LEVELING, DISPLAY TEMPS FOR FOKOOS ODIN UI !!

#include "../../../../inc/MarlinConfigPre.h"

#if HAS_TFT_LVGL_UI

#include "../../../../MarlinCore.h"
#include "../../../../gcode/queue.h"
#include "../../../../module/temperature.h"

#include "lv_conf.h"
#include "draw_ui.h"

extern lv_group_t * g;
static lv_obj_t * scr;

static lv_obj_t *labelExt1;
static lv_obj_t *buttonExt1;

#if HAS_HEATED_BED
  static lv_obj_t *buttonBedstate;
  static lv_obj_t* labelBed;
#endif

enum {
  ID_GCODE = 1,
  #if HAS_USER_ITEM(1)
    ID_CUSTOM_1,
  #endif
  #if HAS_USER_ITEM(2)
    ID_CUSTOM_2,
  #endif
  #if HAS_USER_ITEM(3)
    ID_CUSTOM_3,
  #endif
  #if HAS_USER_ITEM(4)
    ID_CUSTOM_4,
  #endif
  #if HAS_USER_ITEM(5)
    ID_CUSTOM_5,
  #endif
  #if HAS_USER_ITEM(6)
    ID_CUSTOM_6,
  #endif
  ID_M_RETURN,
  ID_INFO_EXT,
  ID_INFO_BED
};

static void event_handler(lv_obj_t * obj, lv_event_t event) {
  if (event != LV_EVENT_RELEASED) return;
  switch (obj->mks_obj_id) {
    case ID_GCODE: lv_clear_more(); lv_draw_gcode(true); break;
    #if HAS_USER_ITEM(1)
      case ID_CUSTOM_1: lv_clear_more(); uiCfg.leveling_first_time = true; lv_draw_manualLevel();
      break;
    #endif
    #if HAS_USER_ITEM(2)
      case ID_CUSTOM_2: lv_clear_more(); uiCfg.leveling_first_time = false; lv_draw_manualLevel();
      break;
    #endif
    #if HAS_USER_ITEM(3)
      //case ID_CUSTOM_3: queue.inject_P(PSTR(USER_GCODE_3));
      break;
    #endif
    #if HAS_USER_ITEM(4)
      //case ID_CUSTOM_4: queue.inject_P(PSTR(USER_GCODE_4));
      break;
    #endif
    #if HAS_USER_ITEM(5)
      //case ID_CUSTOM_5: queue.inject_P(PSTR(USER_GCODE_5));
      break;
    #endif
    #if HAS_USER_ITEM(6)
      //case ID_CUSTOM_6: queue.inject_P(PSTR(USER_GCODE_6));
      break;
    #endif
    case ID_M_RETURN:
      lv_clear_cur_ui();
      lv_draw_return_ui();
      break;
    case ID_INFO_EXT:
      uiCfg.curTempType = 0;
      lv_draw_preHeat();
      break;
    case ID_INFO_BED:
      uiCfg.curTempType = 1;
      lv_draw_preHeat();
      break;
      //return;
  }
}

void lv_draw_more() {
  scr = lv_screen_create(MORE_UI);

  lv_big_button_create(scr, "F:/bmp_machine_para.bin", more_menu.gcode, INTERVAL_V, titleHeight, event_handler, ID_GCODE);
  
  #if HAS_USER_ITEM(1)
    lv_big_button_create(scr, "F:/bmp_leveling1.bin", more_menu.custom1, BTN_X_PIXEL + INTERVAL_V * 2, titleHeight, event_handler, ID_CUSTOM_1);
  #endif

  #if HAS_USER_ITEM(2)
    lv_big_button_create(scr, "F:/bmp_leveling1.bin", more_menu.custom2, BTN_X_PIXEL * 2 + INTERVAL_V * 3, titleHeight, event_handler, ID_CUSTOM_2);
  #endif

  /* #if HAS_USER_ITEM(3)
    lv_big_button_create(scr, "F:/bmp_custom3.bin", more_menu.custom3, BTN_X_PIXEL * 3 + INTERVAL_V * 4, titleHeight, event_handler, ID_CUSTOM_3);
  #endif

  #if HAS_USER_ITEM(4)
    lv_big_button_create(scr, "F:/bmp_custom4.bin", more_menu.custom4, INTERVAL_V, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_CUSTOM_4);
  #endif

  #if HAS_USER_ITEM(5)
    lv_big_button_create(scr, "F:/bmp_custom5.bin", more_menu.custom5, BTN_X_PIXEL + INTERVAL_V * 2, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_CUSTOM_5);
  #endif

  #if HAS_USER_ITEM(6)
    lv_big_button_create(scr, "F:/bmp_custom6.bin", more_menu.custom6, BTN_X_PIXEL * 2 + INTERVAL_V * 3, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_CUSTOM_6);
  #endif */

  lv_big_button_create(scr, "F:/bmp_return.bin", common_menu.text_back, BTN_X_PIXEL * 3 + INTERVAL_V * 4, BTN_Y_PIXEL + INTERVAL_H + titleHeight, event_handler, ID_M_RETURN);
  //create temp labels
  lv_big_button_create(scr, "F:/bmp_bed_state.bin", " ", 220, 1, event_handler, ID_INFO_BED);
  lv_big_button_create(scr, "F:/bmp_ext1_state.bin", " ", 300, 1, event_handler, ID_INFO_EXT);
  labelBed = lv_label_create(scr, 260, 1, nullptr);
  labelExt1 = lv_label_create(scr, 340, 1, nullptr);
  disp_ext_temp_more();
  disp_bed_temp_more();
}

void disp_ext_temp_more() {
  sprintf(public_buf_l, printing_menu.temp1, (int)thermalManager.degHotend(0), (int)thermalManager.degTargetHotend(0));
  lv_label_set_text(labelExt1, public_buf_l);

  #if HAS_MULTI_EXTRUDER && DISABLED(SINGLENOZZLE)
    sprintf(public_buf_l, printing_menu.temp1, (int)thermalManager.degHotend(1), (int)thermalManager.degTargetHotend(1));
    lv_label_set_text(labelExt2, public_buf_l);
  #endif
}

void disp_bed_temp_more() {
  #if HAS_HEATED_BED
    sprintf(public_buf_l, printing_menu.bed_temp, (int)thermalManager.temp_bed.celsius, (int)thermalManager.temp_bed.target);
    lv_label_set_text(labelBed, public_buf_l);
  #endif
}

void lv_clear_more() {
  #if HAS_ROTARY_ENCODER
    if (gCfgItems.encoder_enable) lv_group_remove_all_objs(g);
  #endif
  lv_obj_del(scr);
}

#endif // HAS_TFT_LVGL_UI
