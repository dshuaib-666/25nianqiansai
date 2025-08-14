#include "lvgl_init.h"
#include "pic.h"
#include "all.h"

//选择需要使用的界面
typedef struct{
lv_obj_t *init_screen;
lv_obj_t *btn1_screen;
lv_obj_t *btn2_screen;
lv_obj_t *btn3_screen;
lv_obj_t *btn4_screen;
lv_obj_t *btn5_screen;
lv_obj_t *button1_screen;	
}screen_mode;
screen_mode fact_screen;

// 创建五个界面
lv_obj_t * main_screen=NULL;
lv_obj_t * btn1_screen2=NULL;
lv_obj_t * btn2_screen2=NULL;
lv_obj_t * btn3_screen2=NULL;
lv_obj_t * btn4_screen2=NULL;
lv_obj_t * btn5_screen2=NULL;
lv_obj_t * button1_screen2=NULL;

//在图标声明前添加 LVGL 的 Flash 属性宏
LV_IMG_DECLARE(medicine);
LV_IMG_DECLARE(warmth);
LV_IMG_DECLARE(xinlv);
LV_IMG_DECLARE(control);
LV_IMG_DECLARE(fanhui); 
LV_IMG_DECLARE(jiuyuan); 

//显示文字
LV_FONT_DECLARE(wendu_font);
LV_FONT_DECLARE(shidu_font);
LV_FONT_DECLARE(xinlv_font);
LV_FONT_DECLARE(ziwaixian_font);
LV_FONT_DECLARE(yaowushibie);
LV_FONT_DECLARE(wenshidu);
LV_FONT_DECLARE(load_xinlv);
LV_FONT_DECLARE(recognize_font);
LV_FONT_DECLARE(none_recognize_font);
LV_FONT_DECLARE(xueyang);
LV_FONT_DECLARE(pilaodu);
LV_FONT_DECLARE(yanwu);
LV_FONT_DECLARE(zaixian);
LV_FONT_DECLARE(putong);
LV_FONT_DECLARE(jinji);
LV_FONT_DECLARE(lv_font_montserrat_14);
LV_FONT_DECLARE(lv_font_montserrat_32);

//按钮回调
static void btn1_event_cb(lv_event_t * e)
{		
	
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件一的按钮
    
    if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn1_screen);
		medicine_state=0;
    }

}


static void btn2_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件二的按钮
    if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn2_screen);
    }
}


static void btn3_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件三的按钮
    if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn3_screen);
    }
}


static void btn4_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件四的按钮
		if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn4_screen);
    }
}


static void btn5_event_cb(lv_event_t * e)
{
	
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件五的按钮
		if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn5_screen);
    }
		
}

static void button1_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);  // 获取触发事件四的按钮
		if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.btn4_screen);
		
    }
}


static void imgbtn_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);  // 获取返回事件的按钮
		if(e->code == LV_EVENT_PRESSED) {
		
		lv_scr_load(fact_screen.init_screen);
    }
}
lv_obj_t *sw1,*sw2,*sw3,*sw4;
int32_t load_state=0;//上传数据按钮
int32_t shine_state=0;//紫外线
int32_t load_medicin_state=0;//药物数据上传
static void control_event_cb(lv_event_t * e)
{
    lv_obj_t * sw = lv_event_get_target(e);  // 获取控制事件的按钮
		    
				
		if(e->code == LV_EVENT_VALUE_CHANGED) {
		bool is_on = lv_obj_has_state(sw, LV_STATE_CHECKED);  // 获取当前状态
		if(is_on) // 开关打开时的逻辑
			{ 
       if(sw==sw1)
				{
				shine_state=1;
		    }
		    else if(sw==sw2)
		    {
		    load_medicin_state=1;
		    }
		    else if(sw==sw3)
		    {
		    load_state=1;
		    }
       } 
			else// 开关关闭时的逻辑
			{
				if(sw==sw1)
				{
				shine_state=0;
		    }
		    else if(sw==sw2)
		    {
		    load_medicin_state=0;
		    }
		    else if(sw==sw3)
		    {
		    load_state=0;
		    }
            
       }	
		
		
    }
}


static void medicine_control_event_cb(lv_event_t * e)
{
    lv_obj_t * sw = lv_event_get_target(e);  // 获取控制事件的按钮
		    
				
		if(e->code == LV_EVENT_VALUE_CHANGED) {
		bool is_on = lv_obj_has_state(sw, LV_STATE_CHECKED);  // 获取当前状态
		if(is_on) // 开关打开时的逻辑
			{ 
       if(sw==sw4)//开始识别
				{
				lv_scr_load(fact_screen.button1_screen);
				medicine_reconfig_state=1;
		    }
		   
       } 
			else// 开关关闭时的逻辑
			{	
            
       }	
		
		
    }
}

//药盒按键回调
lv_obj_t * btn1_medicine_btn0,* btn1_medicine_btn1,* btn1_medicine_btn2,* btn1_medicine_btn3,* btn1_medicine_btn4,* btn1_medicine_btn5;
lv_obj_t * medicine_btn0,* medicine_btn1,* medicine_btn2,* medicine_btn3,* medicine_btn4,* medicine_btn5;
static void medicine_btn_event_cb(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);
		
    // 根据按钮指针判断是哪个按钮被点击
	if(e->code == LV_EVENT_PRESSED) {
    if(btn == medicine_btn0||btn == btn1_medicine_btn0) {
        medicine_state = 0;
    } 
    else if(btn == medicine_btn1||btn == btn1_medicine_btn1) {
        medicine_state = 1;
    }
    else if(btn == medicine_btn2||btn == btn1_medicine_btn2) {
        medicine_state = 2;
    }
    else if(btn == medicine_btn3||btn == btn1_medicine_btn3) {
        medicine_state = 3;
    }
    else if(btn == medicine_btn4||btn == btn1_medicine_btn4) {
        medicine_state = 4;
    }
    else if(btn == medicine_btn5||btn == btn1_medicine_btn5) {
        medicine_state = 5;
    }
}
								   
}

/**
 * @brief 创建按键
 * @param btn: 输入按键
 * @param size_x, size_y: 图片的大小
 * @param loc_x，loc_y: 图片的中心坐标
 * @param label: 输入标签
 * @param string:标签名称
 */
void create_button_with_zoom_effect(lv_obj_t * parent,lv_obj_t ** btn_ptr, lv_coord_t size_x, lv_coord_t size_y, 
                                  lv_coord_t loc_x, lv_coord_t loc_y, 
                                  lv_obj_t ** label_ptr, const char * string, 
                                  lv_event_cb_t event_cb)
{		
    // 创建按钮
    lv_obj_t * btn = lv_btn_create(parent);
    lv_obj_set_size(btn, size_x, size_y);            
    lv_obj_align(btn, LV_ALIGN_CENTER, loc_x, loc_y);
    
    // 设置按钮颜色
    lv_obj_set_style_bg_color(btn, lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_ANY);
    
    // 添加事件回调
    if(event_cb) {
        lv_obj_add_event_cb(btn, event_cb, LV_EVENT_ALL, NULL);
    }
    
    // 返回创建的对象
    if(btn_ptr) *btn_ptr = btn;
}

void create_imgbtn_button(lv_obj_t *parent,lv_obj_t **imgbtn_ptr,lv_coord_t size_x, lv_coord_t size_y, lv_coord_t loc_x, lv_coord_t loc_y)//, lv_event_cb_t event_cb
{
		lv_obj_t *imgbtn = lv_imgbtn_create(parent);
		lv_imgbtn_set_src(imgbtn, LV_IMGBTN_STATE_RELEASED, NULL, &fanhui, NULL);
		lv_obj_set_size(imgbtn,size_x,size_y);
		lv_obj_align(imgbtn, LV_ALIGN_CENTER, loc_x, loc_y);
		lv_obj_add_event_cb(imgbtn, button1_event_cb, LV_EVENT_ALL, NULL);
		if(imgbtn_ptr) *imgbtn_ptr = imgbtn;
}






/**
 * @brief 创建返回图片按钮
 * @param loc_x, loc_y: 图片的中心坐标
 * @param size: 图片的大小
 * @param src: 图片
 */
void create_imgbtn(lv_obj_t *parent,lv_obj_t **imgbtn_ptr,lv_coord_t size_x, lv_coord_t size_y, lv_coord_t loc_x, lv_coord_t loc_y)//, lv_event_cb_t event_cb
{
		lv_obj_t *imgbtn = lv_imgbtn_create(parent);
		lv_imgbtn_set_src(imgbtn, LV_IMGBTN_STATE_RELEASED, NULL, &fanhui, NULL);
		lv_obj_set_size(imgbtn,size_x,size_y);
		lv_obj_align(imgbtn, LV_ALIGN_CENTER, loc_x, loc_y);
		lv_obj_add_event_cb(imgbtn, imgbtn_event_cb, LV_EVENT_ALL, NULL);
		if(imgbtn_ptr) *imgbtn_ptr = imgbtn;
}

/**
 * @brief 显示图片
 * @param loc_x, loc_y: 图片的中心坐标
 * @param size: 图片的大小
 * @param src: 图片
 */
void create_button_init_screen(lv_obj_t *parent,lv_obj_t * img,lv_coord_t loc_x,lv_coord_t loc_y,float size,const void * src)
{	
    img = lv_img_create(parent);   //使用默认的显示器（返回值就是lv_obj_t *）
    lv_obj_align(img, LV_ALIGN_CENTER, loc_x, loc_y);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）
		lv_img_set_zoom(img,  size*256);
		lv_img_set_src(img, src);
}


/**
 * @brief 创建圆角矩形
 * @param size_x, size_y: 矩形的大小
 * @param bodern_value: 边缘圆角的像素
 * @param loc_x, loc_y: 矩形的中心坐标
 */
void create_rounded_rect(lv_obj_t * rounded_rect,lv_coord_t size_x,lv_coord_t size_y,lv_coord_t bodern_value,lv_coord_t loc_x,lv_coord_t loc_y)
{
		
		lv_obj_set_size(rounded_rect, size_x, size_y);  // 设置大小

		// 设置圆角样式
		lv_obj_set_style_radius(rounded_rect, bodern_value, LV_PART_MAIN);  // 10像素圆角半径
		lv_obj_set_style_bg_color(rounded_rect, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
		
		lv_obj_align(rounded_rect, LV_ALIGN_CENTER, loc_x, loc_y);
}


/**
 * @brief 创建开关
 * @param size_x, size_y: 开关的大小
 * @param x_ofs，y_ofs: 开关的位置
 */
void create_switch(lv_obj_t *parent,lv_obj_t ** imgbnt,lv_coord_t size_x, lv_coord_t size_y,lv_coord_t x_ofs, lv_coord_t y_ofs,lv_event_cb_t event_cb)
{
// 创建一个开关按钮
		lv_obj_t *sw = lv_switch_create(parent);
		lv_obj_set_size(sw, size_x, size_y);  // 设置大小
		lv_obj_align(sw, LV_ALIGN_CENTER, x_ofs, y_ofs);  // 居中显示

// 或者设置为关
		lv_obj_clear_state(sw, LV_STATE_CHECKED);

// 设置开关关闭时的背景颜色
		static lv_style_t style_sw_bg;
		lv_style_init(&style_sw_bg);
		lv_style_set_bg_color(&style_sw_bg, lv_color_hex(0xcccccc));
		lv_obj_add_style(sw, &style_sw_bg, LV_PART_MAIN);

// 设置开关打开时的指示器颜色
		static lv_style_t style_sw_indic;
		lv_style_init(&style_sw_indic);
		lv_style_set_bg_color(&style_sw_indic, lv_color_hex(0xffffff));
		lv_obj_add_style(sw, &style_sw_indic, LV_PART_INDICATOR);

// 设置开关按钮(滑块)的样式
		static lv_style_t style_sw_knob;
		lv_style_init(&style_sw_knob);
		lv_style_set_bg_color(&style_sw_knob, lv_color_white());
		lv_obj_add_style(sw, &style_sw_knob, LV_PART_KNOB);
		
//事件回调
		if(event_cb) {
    lv_obj_add_event_cb(sw, event_cb, LV_EVENT_ALL, NULL);
    }
		*imgbnt=sw;
		
//

}

/**
 * @brief 创建文本
 * @param screen: 选择屏幕
 * @param label: 标签指针的句柄
 * @param x_ofs，y_ofs: 文本的位置
 * @param string: 文本
 */
void show_text(lv_obj_t *screen,lv_obj_t **label,lv_coord_t x_ofs, lv_coord_t y_ofs,const char * string)
{
		lv_obj_t * label2 = lv_label_create(screen); 
		lv_label_set_text(label2,string);
		lv_obj_set_style_text_font(label2, &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(label2,lv_color_hex(0x51c4fa),0);
		lv_obj_align(label2,LV_ALIGN_CENTER,x_ofs,y_ofs);
		
		if(label) *label=label2;

}


	

//显示传感器数据
static lv_obj_t * xinlv_temp_label= NULL,*warmth_temp_label= NULL,*humi_temp_label= NULL,*Smoke_temp_label = NULL,* xueyang_temp_label= NULL,* pilaodu_temp_label= NULL,* phone_temp_label= NULL;
lv_obj_t *phone_labels[15],*phone2_labels[15];  
int32_t xinlv_show= 0,warmth_show= 0,Smoke_show = 0,xueyang_show = 0,pilaodu_show = 0,phone_show=0,phone2_show=0;
uint8_t humi_show= 0;
		
void phone_update_display(lv_timer_t * timer) 
{	
	uint16_t count=0;
  
	for(count=0;count<four.DOCTORPHONE_length;count++)
	{
		
	  phone_show=four.DATA_DOCTORPHONE[count];		
		lv_label_set_text_fmt(phone_labels[count], "%d", phone_show);

		}
	
		
		for(count=0;count<four.PHONE_length;count++)
	 {
		
		
	  phone2_show=four.DATA_PHONE[count];
		lv_label_set_text_fmt(phone2_labels[count], "%d", phone2_show);

		}
}

void xinlv_update_display(lv_timer_t * timer) 
{	
		
		xinlv_show = (int)heart.heartrate;
		xueyang_show=(int)heart.spo2;
		pilaodu_show= (int)heart.tired;
		lv_label_set_text_fmt(pilaodu_temp_label, "%d", pilaodu_show);
		lv_label_set_text_fmt(xueyang_temp_label, "%d", xueyang_show);
		lv_label_set_text_fmt(xinlv_temp_label, "%d", xinlv_show);
}
void warmth_update_display(lv_timer_t * timer) 
{	
		warmth_show = dht11.temp;
		lv_label_set_text_fmt(warmth_temp_label, "%d°C", warmth_show);
}
void humi_update_display(lv_timer_t * timer) 
{	
		humi_show = dht11.humi;
		lv_label_set_text_fmt(humi_temp_label, "%d%%", humi_show);
}
void Smoke_update_display(lv_timer_t * timer) 
{	
		Smoke_show = smoke.ratio;
		lv_label_set_text_fmt(Smoke_temp_label, "%d", Smoke_show);
}





//按钮一界面:药盒
lv_obj_t * use_btn1_screen(void)
{
		btn1_screen2= lv_obj_create(NULL);
		static lv_style_t bg_style;
		lv_style_init(&bg_style);
		lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
		lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
		lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
		lv_obj_add_style(btn1_screen2, &bg_style, LV_PART_MAIN);

    //顶部进度条 
		lv_obj_t * progress = lv_bar_create(btn1_screen2);//创建进度条
		lv_obj_set_size(progress, 160, 10);
		lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
		lv_bar_set_value(progress, 70, LV_ANIM_ON);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
	    lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
		lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
		lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
		lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角
		
		
		lv_obj_t * medicine_label0,* medicine_label1,* medicine_label2,* medicine_label3,* medicine_label4,* medicine_label5;
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn0,100,50,-120,-60,&medicine_label0,"0",medicine_btn_event_cb);
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn1,100,50,-0,-60,&medicine_label1,"1",medicine_btn_event_cb);
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn2,100,50,120,-60,&medicine_label2,"2",medicine_btn_event_cb);
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn3,100,50,-120,30,&medicine_label3,"3",medicine_btn_event_cb);
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn4,100,50,-0,30,&medicine_label4,"4",medicine_btn_event_cb);
		create_button_with_zoom_effect(btn1_screen2,&btn1_medicine_btn5,100,50,120,30,&medicine_label5,"5",medicine_btn_event_cb);
		
		show_text(btn1_screen2,&medicine_label0,-120, -60,"off");
		show_text(btn1_screen2,&medicine_label1,-0, -60,"1");
		show_text(btn1_screen2,&medicine_label2,120, -60,"2");
		show_text(btn1_screen2,&medicine_label3,-120, 30,"3");
		show_text(btn1_screen2,&medicine_label4,-0, 30,"4");
		show_text(btn1_screen2,&medicine_label5,120, 30,"5");
		
		lv_obj_t *imgbtn ;
		create_imgbtn(btn1_screen2,&imgbtn,40,40,-210,-130);
		
		return btn1_screen2;
}
//按钮二界面:温湿度
lv_obj_t * use_btn2_screen(void)
{		btn2_screen2= lv_obj_create(NULL);
		static lv_style_t bg_style;
		lv_obj_t * btn1,* btn2,* btn3,* btn4,*btn1_label1,*btn2_label1,*btn3_label1,*btn4_label1;//
		lv_obj_t * btn1_img,* btn2_img,* btn3_img,* btn4_img;//显示图像
	
		lv_style_init(&bg_style);
		lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
		lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
		lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
		lv_obj_add_style(btn2_screen2, &bg_style, LV_PART_MAIN);

    //顶部进度条 
		lv_obj_t * progress = lv_bar_create(btn2_screen2);//创建进度条
		lv_obj_set_size(progress, 160, 10);
		lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
		lv_bar_set_value(progress, 70, LV_ANIM_ON);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
	    lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
		lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
		lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
		lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角

  	//显示第一界面文字

		
		lv_obj_t * label1 = lv_label_create(btn2_screen2);
		lv_obj_set_style_text_font(label1,&wendu_font,0);
		lv_label_set_text(label1, "温度");//中文
		lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0);
		lv_obj_align(label1, LV_ALIGN_TOP_MID, -150, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
		lv_obj_t * label2 = lv_label_create(btn2_screen2); 
		lv_label_set_text(label2,"Temperature");
		lv_obj_set_style_text_font(label2, &lv_font_montserrat_14, 0);
		lv_obj_set_style_text_color(label2,lv_color_hex(0xFFFFFF),0);
		lv_obj_align(label2,LV_ALIGN_TOP_MID,-150,280);
		
		lv_obj_t * label3 = lv_label_create(btn2_screen2);
		lv_obj_set_style_text_font(label3,&shidu_font,0);
		lv_label_set_text(label3, "湿度");//中文
		lv_obj_set_style_text_color(label3, lv_color_hex(0xFFFFFF), 0);
		lv_obj_align(label3, LV_ALIGN_TOP_MID,0, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
		lv_obj_t * label4 = lv_label_create(btn2_screen2); 
		lv_label_set_text(label4,"humi");
		lv_obj_set_style_text_font(label4, &lv_font_montserrat_14, 0);
		lv_obj_set_style_text_color(label4,lv_color_hex(0xFFFFFF),0);
		lv_obj_align(label4,LV_ALIGN_TOP_MID,0,280);
		
		lv_obj_t * label5 = lv_label_create(btn2_screen2);
		lv_obj_set_style_text_font(label5,&yanwu,0);
		lv_label_set_text(label5, "烟雾");//中文
		lv_obj_set_style_text_color(label5, lv_color_hex(0xFFFFFF), 0);
		lv_obj_align(label5, LV_ALIGN_TOP_MID,150, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
		lv_obj_t * label6 = lv_label_create(btn2_screen2); 
		lv_label_set_text(label6,"smoke");
		lv_obj_set_style_text_font(label6, &lv_font_montserrat_14, 0);
		lv_obj_set_style_text_color(label6,lv_color_hex(0xFFFFFF),0);
		lv_obj_align(label6,LV_ALIGN_TOP_MID,150,280);
		
		
		//创建圆角矩形
		lv_obj_t * rounded_rect1 = lv_obj_create(btn2_screen2);
		create_rounded_rect(rounded_rect1,120,140,10,-150,-20);
		//创建圆角矩形
		lv_obj_t * rounded_rect2 = lv_obj_create(btn2_screen2);
		create_rounded_rect(rounded_rect2,120,140,10,0,-20);
		//创建圆角矩形
		lv_obj_t * rounded_rect3 = lv_obj_create(btn2_screen2);
		create_rounded_rect(rounded_rect3,120,140,10,150,-20);
		
		warmth_temp_label= lv_label_create(btn2_screen2); 		
		lv_label_set_text_fmt(warmth_temp_label, "%d°C", warmth_show);
		lv_obj_set_style_text_font(warmth_temp_label, &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(warmth_temp_label,lv_color_hex(0x000000),0);
		lv_obj_align(warmth_temp_label,LV_ALIGN_CENTER,-150,-20);

		humi_temp_label= lv_label_create(btn2_screen2); 		
		lv_label_set_text_fmt(humi_temp_label, "%d%%", humi_show);
		lv_obj_set_style_text_font(humi_temp_label, &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(humi_temp_label,lv_color_hex(0x000000),0);
		lv_obj_align(humi_temp_label,LV_ALIGN_CENTER,0,-20);
		
		Smoke_temp_label= lv_label_create(btn2_screen2); 		
		lv_label_set_text_fmt(Smoke_temp_label, "%d%%", Smoke_show);
		lv_obj_set_style_text_font(Smoke_temp_label, &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(Smoke_temp_label,lv_color_hex(0x000000),0);
		lv_obj_align(Smoke_temp_label,LV_ALIGN_CENTER,150,-20);
		lv_obj_t *imgbtn ;
		create_imgbtn(btn2_screen2,&imgbtn,40,40,-210,-130);
		
		return btn2_screen2;
}
//按钮三界面:心率
lv_obj_t * use_btn3_screen(void)
{
	btn3_screen2= lv_obj_create(NULL);
    static lv_style_t bg_style;
	lv_obj_t * btn1,* btn2,* btn3,* btn4,*btn1_label1,*btn2_label1,*btn3_label1,*btn4_label1;//
	lv_obj_t * btn1_img,* btn2_img,* btn3_img,* btn4_img;//显示图像
	
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
    lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
    lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
    lv_obj_add_style(btn3_screen2, &bg_style, LV_PART_MAIN);

    //顶部进度条 
    lv_obj_t * progress = lv_bar_create(btn3_screen2);//创建进度条
	lv_obj_set_size(progress, 160, 10);
    lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
    lv_bar_set_value(progress, 70, LV_ANIM_ON);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
	lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
	lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
	lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
	lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角

  	//显示第一界面文字
	LV_FONT_DECLARE(xinlv_font);
	LV_FONT_DECLARE(lv_font_montserrat_14);
	LV_FONT_DECLARE(lv_font_montserrat_32);
		
    lv_obj_t * label1 = lv_label_create(btn3_screen2);
	lv_obj_set_style_text_font(label1,&xinlv_font,0);
    lv_label_set_text(label1, "心率");//中文
	lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
	lv_obj_t * label2 = lv_label_create(btn3_screen2); 
	lv_label_set_text(label2,"heart rate");
	lv_obj_set_style_text_font(label2, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_color(label2,lv_color_hex(0xFFFFFF),0);
	lv_obj_align(label2,LV_ALIGN_TOP_MID,0,280);
	
	lv_obj_t * label3 = lv_label_create(btn3_screen2);
	lv_obj_set_style_text_font(label3,&xueyang,0);
    lv_label_set_text(label3, "血氧");//中文
	lv_obj_set_style_text_color(label3, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label3, LV_ALIGN_TOP_MID, -150, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
	lv_obj_t * label4 = lv_label_create(btn3_screen2); 
	lv_label_set_text(label4,"blood oxygen");
	lv_obj_set_style_text_font(label4, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_color(label4,lv_color_hex(0xFFFFFF),0);
	lv_obj_align(label4,LV_ALIGN_TOP_MID,-150,280);

	lv_obj_t * label5 = lv_label_create(btn3_screen2);
	lv_obj_set_style_text_font(label5,&pilaodu,0);
    lv_label_set_text(label5, "疲劳度");//中文
	lv_obj_set_style_text_color(label5, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label5, LV_ALIGN_TOP_MID, 150, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
	lv_obj_t * label6 = lv_label_create(btn3_screen2); 
	lv_label_set_text(label6,"fatigue level");
	lv_obj_set_style_text_font(label6, &lv_font_montserrat_14, 0);
	lv_obj_set_style_text_color(label6,lv_color_hex(0xFFFFFF),0);
	lv_obj_align(label6,LV_ALIGN_TOP_MID,150,280);
	
	//创建圆角矩形
	lv_obj_t * rounded_rect = lv_obj_create(btn3_screen2);
	create_rounded_rect(rounded_rect,120,140,10,0,-20);
//	data_show(xinlv_temp_label,xinlv_show);
	xinlv_temp_label= lv_label_create(btn3_screen2); 		
	lv_label_set_text_fmt(xinlv_temp_label, "%d", xinlv_show);
	lv_obj_set_style_text_font(xinlv_temp_label, &lv_font_montserrat_32, 0);
	lv_obj_set_style_text_color(xinlv_temp_label,lv_color_hex(0x000000),0);
	lv_obj_align(xinlv_temp_label,LV_ALIGN_CENTER,0,-20);
	
	lv_obj_t * rounded_rect0 = lv_obj_create(btn3_screen2);
	create_rounded_rect(rounded_rect0,120,140,10,-150,-20);
//	data_show(xinlv_temp_label,xinlv_show);
	xueyang_temp_label= lv_label_create(btn3_screen2); 		
	lv_label_set_text_fmt(xueyang_temp_label, "%d", xueyang_show);
	lv_obj_set_style_text_font(xueyang_temp_label, &lv_font_montserrat_32, 0);
	lv_obj_set_style_text_color(xueyang_temp_label,lv_color_hex(0x000000),0);
	lv_obj_align(xueyang_temp_label,LV_ALIGN_CENTER,-150,-20);
	
	lv_obj_t * rounded_rect1 = lv_obj_create(btn3_screen2);
	create_rounded_rect(rounded_rect1,120,140,10,150,-20);
//	data_show(xinlv_temp_label,xinlv_show);
	pilaodu_temp_label= lv_label_create(btn3_screen2); 		
	lv_label_set_text_fmt(pilaodu_temp_label, "%d", pilaodu_show);
	lv_obj_set_style_text_font(pilaodu_temp_label, &lv_font_montserrat_32, 0);
	lv_obj_set_style_text_color(pilaodu_temp_label,lv_color_hex(0x000000),0);
	lv_obj_align(pilaodu_temp_label,LV_ALIGN_CENTER,150,-20);
	
	
	

	lv_obj_t *imgbtn ;
	create_imgbtn(btn3_screen2,&imgbtn,40,40,-210,-130);
	
	return btn3_screen2;
}

//按钮四界面:控制
lv_obj_t * use_btn4_screen(void)
{
	btn4_screen2= lv_obj_create(NULL);
	static lv_style_t bg_style;
	lv_obj_t * btn1,* btn2,* btn3,* btn4,*btn1_label1,*btn2_label1,*btn3_label1,*btn4_label1;//
	lv_obj_t * btn1_img,* btn2_img,* btn3_img,* btn4_img;//显示图像
	
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
    lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
    lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
    lv_obj_add_style(btn4_screen2, &bg_style, LV_PART_MAIN);

    /* 3. 顶部进度条 */
    lv_obj_t * progress = lv_bar_create(btn4_screen2);//创建进度条
	lv_obj_set_size(progress, 160, 10);
    lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
    lv_bar_set_value(progress, 70, LV_ANIM_ON);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
    lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
	lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
	lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
	lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角
		
	create_switch(btn4_screen2,&sw1,100,50,-100,-50,control_event_cb);
	create_switch(btn4_screen2,&sw2,100,50,100,-50,control_event_cb);
	create_switch(btn4_screen2,&sw3,100,50,-100,50,control_event_cb);
	create_switch(btn4_screen2,&sw4,100,50,100,50,medicine_control_event_cb);
		
		



	lv_obj_t * label1 = lv_label_create(btn4_screen2);
	lv_obj_set_style_text_font(label1,&ziwaixian_font,0);
    lv_label_set_text(label1, "紫外线");//中文
	lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label1, LV_ALIGN_TOP_MID, -100, 50);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		
	lv_obj_t * label2 = lv_label_create(btn4_screen2);
	lv_obj_set_style_text_font(label2,&yaowushibie,0);
    lv_label_set_text(label2, "药物识别");//中文
	lv_obj_set_style_text_color(label2, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label2, LV_ALIGN_TOP_MID, 100, 150);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		
	lv_obj_t * label3 = lv_label_create(btn4_screen2);
	lv_obj_set_style_text_font(label3,&zaixian,0);
    lv_label_set_text(label3, "在线模式");//中文
	lv_obj_set_style_text_color(label3, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label3, LV_ALIGN_TOP_MID, -100, 150);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		
	lv_obj_t * label4 = lv_label_create(btn4_screen2);
	lv_obj_set_style_text_font(label4,&load_xinlv,0);
    lv_label_set_text(label4, "上传心率");//中文
	lv_obj_set_style_text_color(label4, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label4, LV_ALIGN_TOP_MID, 100, 50);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		
		
	lv_obj_t *imgbtn ;
	create_imgbtn(btn4_screen2,&imgbtn,40,40,-210,-130);
		
	return btn4_screen2;
}



//按钮五界面
lv_obj_t * use_btn5_screen(void)
{
	btn5_screen2= lv_obj_create(NULL);
	static lv_style_t bg_style;
	lv_obj_t * btn1,* btn2,* btn3,* btn4,*btn1_label1,*btn2_label1,*btn3_label1,*btn4_label1;//
	lv_obj_t * btn1_img,* btn2_img,* btn3_img,* btn4_img;//显示图像
	uint16_t count = 0;
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
    lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
    lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
    lv_obj_add_style(btn5_screen2, &bg_style, LV_PART_MAIN);

    /* 3. 顶部进度条 */
    lv_obj_t * progress = lv_bar_create(btn5_screen2);//创建进度条
	lv_obj_set_size(progress, 160, 10);
    lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
    lv_bar_set_value(progress, 70, LV_ANIM_ON);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
    lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
	lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
	lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
	lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角
		
	
	
			lv_obj_t * label1 = lv_label_create(btn5_screen2);
	lv_obj_set_style_text_font(label1,&putong,0);
    lv_label_set_text(label1, "普通联系人");//中文
	lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label1, LV_ALIGN_CENTER, -140, -70);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		
	lv_obj_t * label2 = lv_label_create(btn5_screen2);
	lv_obj_set_style_text_font(label2,&jinji,0);
    lv_label_set_text(label2, "紧急联系人");//中文
	lv_obj_set_style_text_color(label2, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label2, LV_ALIGN_CENTER, -140, -20);//第二个参数：左上角，中烟，右下角（有三个参数可以选择） 

		four.DOCTORPHONE_length=11;
		four.PHONE_length=11;
	for(count=0;count<four.DOCTORPHONE_length;count++)
	{
		
//		four.DOCTORPHONE[0]=1;
	  phone_show=four.DATA_DOCTORPHONE[count];
		phone_labels[count]= lv_label_create(btn5_screen2); 		
		lv_label_set_text_fmt(phone_labels[count], "%d", phone_show);
		lv_obj_set_style_text_font(phone_labels[count], &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(phone_labels[count],lv_color_hex(0xFFFFFF),0);
		lv_obj_align(phone_labels[count],LV_ALIGN_CENTER,-50+20*count,-20);
		}

		for(count=0;count<four.PHONE_length;count++)
	 {
		
//		four.DOCTORPHONE[0]=1;
	  phone2_show=four.DATA_PHONE[count];
		phone2_labels[count]= lv_label_create(btn5_screen2); 		
		lv_label_set_text_fmt(phone2_labels[count], "%d", phone2_show);
		lv_obj_set_style_text_font(phone2_labels[count], &lv_font_montserrat_32, 0);
		lv_obj_set_style_text_color(phone2_labels[count],lv_color_hex(0xFFFFFF),0);
		lv_obj_align(phone2_labels[count],LV_ALIGN_CENTER,-50+20*count,-70);
		}
	 
		
	lv_obj_t *imgbtn ;
	create_imgbtn(btn5_screen2,&imgbtn,40,40,-210,-130);
		
	return btn5_screen2;
}



lv_obj_t * aa_label1 = NULL;
void update_aa_label(void) {
    if (aa_label1 == NULL) return;  // 确保标签存在

    if (lvgl_medicine_reconfig_state == 2) {
        lv_obj_set_style_text_font(aa_label1, &recognize_font, 0);
        lv_label_set_text(aa_label1, "识别成功");
    } 
    else if (lvgl_medicine_reconfig_state == 1) {
        lv_obj_set_style_text_font(aa_label1, &none_recognize_font, 0);
        lv_label_set_text(aa_label1, "未识别成功");
    }

    lv_obj_set_style_text_color(aa_label1, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(aa_label1, LV_ALIGN_TOP_MID, 0, 240);
}

//开关一界面:药盒选中
lv_obj_t * use_button_screen(void)
{
		button1_screen2= lv_obj_create(NULL);
		static lv_style_t bg_style;
		lv_style_init(&bg_style);
		lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
		lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
		lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
		lv_obj_add_style(button1_screen2, &bg_style, LV_PART_MAIN);

		//顶部进度条 
		lv_obj_t * progress = lv_bar_create(button1_screen2);//创建进度条
		lv_obj_set_size(progress, 160, 10);
		lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
		lv_bar_set_value(progress, 70, LV_ANIM_ON);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
	    lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
		lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
		lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
		lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
		lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角
		
		
		lv_obj_t * medicine_label0,* medicine_label1,* medicine_label2,* medicine_label3,* medicine_label4,* medicine_label5;
		create_button_with_zoom_effect(button1_screen2,&medicine_btn0,100,50,-120,-60,&medicine_label0,"0",medicine_btn_event_cb);
		create_button_with_zoom_effect(button1_screen2,&medicine_btn1,100,50,-0,-60,&medicine_label1,"1",medicine_btn_event_cb);
		create_button_with_zoom_effect(button1_screen2,&medicine_btn2,100,50,120,-60,&medicine_label2,"2",medicine_btn_event_cb);
		create_button_with_zoom_effect(button1_screen2,&medicine_btn3,100,50,-120,30,&medicine_label3,"3",medicine_btn_event_cb);
		create_button_with_zoom_effect(button1_screen2,&medicine_btn4,100,50,-0,30,&medicine_label4,"4",medicine_btn_event_cb);
		create_button_with_zoom_effect(button1_screen2,&medicine_btn5,100,50,120,30,&medicine_label5,"5",medicine_btn_event_cb);
		
		show_text(button1_screen2,&medicine_label0,-120, -60,"off");
		show_text(button1_screen2,&medicine_label1,-0, -60,"1");
		show_text(button1_screen2,&medicine_label2,120, -60,"2");
		show_text(button1_screen2,&medicine_label3,-120, 30,"3");
		show_text(button1_screen2,&medicine_label4,-0, 30,"4");
		show_text(button1_screen2,&medicine_label5,120, 30,"5");
		
		lv_obj_t *imgbtn ;
		create_imgbtn_button(button1_screen2,&imgbtn,40,40,-210,-130);
	    if (aa_label1 == NULL) {
        aa_label1 = lv_label_create(button1_screen2);
         };
		update_aa_label();	
		return button1_screen2;
}




//初始化界面（init_screen）
lv_obj_t * use_init_screen(void)
{
		main_screen = lv_obj_create(NULL); 
	  static lv_style_t bg_style;
		lv_obj_t * btn1,* btn2,* btn3,* btn4,* btn5,*btn1_label1,*btn2_label1,*btn3_label1,*btn4_label1,*btn5_label1;//
		lv_obj_t * btn1_img,* btn2_img,* btn3_img,* btn4_img,* btn5_img;//显示图像
	
    lv_style_init(&bg_style);
    lv_style_set_bg_color(&bg_style, lv_color_hex(0x51c4fa)); // 浅蓝
    lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x43a1f7)); // 深蓝
    lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
    lv_obj_add_style(main_screen, &bg_style, LV_PART_MAIN);

    /* 3. 顶部进度条 */
    lv_obj_t * progress = lv_bar_create(main_screen);//创建进度条
		lv_obj_set_size(progress, 160, 10);
    lv_obj_align(progress, LV_ALIGN_TOP_MID, 0, 20);
    lv_bar_set_value(progress, 70, LV_ANIM_ON);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0x87CEFA), LV_PART_MAIN);//背景
	  lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_bg_color(progress, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);//进度条背景
		lv_obj_set_style_bg_opa(progress, LV_OPA_COVER, LV_PART_INDICATOR);
		lv_obj_set_style_radius(progress, 5, LV_PART_MAIN);      // 背景圆角
		lv_obj_set_style_radius(progress, 5, LV_PART_INDICATOR); // 进度条圆角

  	//显示第一界面文字
		LV_FONT_DECLARE(hanzi);
		LV_FONT_DECLARE(lv_font_montserrat_14);
    lv_obj_t * label1 = lv_label_create(main_screen);
		lv_obj_set_style_text_font(label1,&hanzi,0);
    lv_label_set_text(label1, "智能药箱系统");//中文
		lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0);
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 240);//第二个参数：左上角，中烟，右下角（有三个参数可以选择）  
		//英文
		lv_obj_t * label2 = lv_label_create(main_screen); 
		lv_label_set_text(label2,"Intelligent Medication Dispenser");
		lv_obj_set_style_text_font(label2, &lv_font_montserrat_14, 0);
		lv_obj_set_style_text_color(label2,lv_color_hex(0xFFFFFF),0);
		lv_obj_align(label2,LV_ALIGN_TOP_MID,0,280);
		
		//显示第一个按钮（获取药箱的情况）
		create_button_with_zoom_effect(main_screen,&btn1,120,70,-140,-80,&btn1_label1,"111",btn1_event_cb);
		//显示第二个按钮（获取传感器数据）（温度，湿度）
		create_button_with_zoom_effect(main_screen,&btn2,120,70,140,-80,&btn2_label1,"222",btn2_event_cb);
		//显示第三个按钮（获取传感器数据）（心率）
		create_button_with_zoom_effect(main_screen,&btn3,120,70,-140,20,&btn3_label1,"333",btn3_event_cb);
		//显示第四个按钮(控制系统)
		create_button_with_zoom_effect(main_screen,&btn4,120,70,140,20,&btn4_label1,"444",btn4_event_cb);
		//显示第五个按钮
		create_button_with_zoom_effect(main_screen,&btn5,120,70,0,-30,&btn5_label1,"444",btn5_event_cb);
		
		//显示第一个按钮图片
		create_button_init_screen(main_screen,btn1_img,-140,-80,1.25,&medicine);
		//显示第二个按钮图片
		create_button_init_screen(main_screen,btn2_img,140,-80,1.25,&warmth);
		//显示第三个按钮图片
		create_button_init_screen(main_screen,btn3_img,-140,20,1.25,&xinlv);
		//显示第四个按钮图片
		create_button_init_screen(main_screen,btn4_img,140,20,1.25,&control);
		//显示第五个按钮图片
		create_button_init_screen(main_screen,btn5_img,0,-30,1.25,&jiuyuan);

		
		
		
		return  main_screen; 
}





void init_start_screen()
{
		fact_screen.init_screen=use_init_screen();
		fact_screen.btn1_screen=use_btn1_screen();
		fact_screen.btn2_screen=use_btn2_screen();
		fact_screen.btn3_screen=use_btn3_screen();
		fact_screen.btn4_screen=use_btn4_screen();
	  fact_screen.btn5_screen=use_btn5_screen();
		fact_screen.button1_screen=use_button_screen();
		lv_scr_load_anim(fact_screen.init_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.btn1_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.btn2_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.btn3_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.btn4_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.button1_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false);
		lv_scr_load_anim(fact_screen.init_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load_anim(fact_screen.btn1_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load_anim(fact_screen.btn2_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load_anim(fact_screen.btn3_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load_anim(fact_screen.btn4_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load_anim(fact_screen.button1_screen, LV_SCR_LOAD_ANIM_OVER_TOP, 50, 0, false);
		lv_scr_load(fact_screen.init_screen);


}









