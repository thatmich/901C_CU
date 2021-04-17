#include "main.h"
#include "lvgl_functions.h"
#include "../configure/config.h"

lv_obj_t * scr = lv_obj_create(NULL,NULL);
lv_obj_t * main_label =  lv_label_create(scr, NULL);

lv_obj_t * debug_x_label =  lv_label_create(scr, NULL);
lv_obj_t * debug_y_label =  lv_label_create(scr, NULL);
lv_obj_t * debug_a_label =  lv_label_create(scr, NULL);

int autonNo = 1;

void setup(){
  lv_scr_load(scr);
  lv_label_set_recolor(main_label, true);
  lv_label_set_text(main_label, "#ff0000 asfadsf Left Home Row# #ffffff Auton#");
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

/*
bool add: adds or subtracts a number from autonNo
*/
void switch_auton(bool add){
  if(add){
     autonNo++;
  }
  else{
    autonNo--;
  }
  switch (autonNo){
    case 1:
      lv_label_set_text(main_label, "#ff0000 k;jkl Left Home Row# #ffffff Auton#");
      break;
    case 2:
      lv_label_set_text(main_label, "#ff0000 Red Right Home Row# #ffffff Auton#");
      break;
    case 3:
      lv_label_set_text(main_label, "#ff0000 Red Middle# #ffffff Auton#");
      break;
    case 4:
      lv_label_set_text(main_label, "#0000ff Blue Left Home Row# #ffffff Auton#");
      break;
    case 5:
      lv_label_set_text(main_label, "#0000ff Blue Right Home Row# #ffffff Auton#");
      break;
    case 6:
      lv_label_set_text(main_label, "#0000ff Blue Middle# #ffffff Auton#");
      break;
    case 7:
      lv_label_set_text(main_label, "#ff0000 Red# #ffffff Auton#");
      autonNo = 1;
      break;

  }
}

void limit_detection_task(void *param){
  while(true){
    if(auton_limit_plus.get_new_press() == 1){
      switch_auton(true);
    }
    else if(auton_limit_minus.get_new_press() == 1){
      switch_auton(false);
    }
    pros::delay(50);
  }
}
