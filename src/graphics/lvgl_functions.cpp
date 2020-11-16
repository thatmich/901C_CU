#include "main.h"
#include "lvgl_functions.h"
#include "../configure/config.h"

lv_obj_t * scr = lv_obj_create(NULL,NULL);
lv_obj_t * main_label =  lv_label_create(scr, NULL);
lv_obj_t * debug_x_label =  lv_label_create(scr, NULL);
lv_obj_t * debug_y_label =  lv_label_create(scr, NULL);
lv_obj_t * debug_a_label =  lv_label_create(scr, NULL);

void setup(){
  lv_scr_load(scr);
  lv_label_set_recolor(main_label, true);
  lv_label_set_text(main_label, "#ffffff yo#");
  lv_obj_align(main_label, NULL, LV_ALIGN_CENTER, 0, 0);
}

void odom_debug(float x, float y, float a){
  char coords_x[20];
  char coords_y[20];
  char coords_a[20];
  std::sprintf(coords_x, "x: %G", x);
  std::sprintf(coords_y, "y: %G", y);
  std::sprintf(coords_a, "a: %G", a);
  lv_label_set_text(debug_a_label, coords_a);
  lv_label_set_text(debug_x_label, coords_x);
  lv_label_set_text(debug_y_label, coords_y);
  lv_obj_align(debug_a_label, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 20);
  lv_obj_align(debug_x_label, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 70);
  lv_obj_align(debug_y_label, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 130);
}

void debug_text(std::string text){
  int n = text.length();
  char text_array[n+1];
  strcpy(text_array, text.c_str());
  lv_label_set_text(main_label, text_array);
}
