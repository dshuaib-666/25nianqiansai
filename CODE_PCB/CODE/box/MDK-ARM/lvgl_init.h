#ifndef __LVGL_INIT_H__
#define __LVGL_INIT_H__ 			   

#include "all.h"
void xinlv_update_display(lv_timer_t * timer) ;
void warmth_update_display(lv_timer_t * timer) ;
void humi_update_display(lv_timer_t * timer) ;
void Smoke_update_display(lv_timer_t * timer) ;
void phone_update_display(lv_timer_t * timer) ;
void create_button_with_zoom_effect(lv_obj_t * parent,lv_obj_t ** btn_ptr, lv_coord_t size_x, lv_coord_t size_y, 
                                  lv_coord_t loc_x, lv_coord_t loc_y, 
                                  lv_obj_t ** label_ptr, const char * string, 
                                  lv_event_cb_t event_cb);//按钮事件
lv_obj_t * use_init_screen(void);
lv_obj_t * use_btn1_screen(void);//按钮一界面
lv_obj_t * use_btn2_screen(void);//按钮二界面
lv_obj_t * use_btn3_screen(void);//按钮三界面
lv_obj_t * use_btn4_screen(void);//按钮四界面

																
void init_start_screen(void);
void update_aa_label(void) ;
#endif

