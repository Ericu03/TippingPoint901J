#include "main.h"
#include "config.hpp"



static lv_res_t color_action(lv_obj_t * btn)
 {
	 //for red or blue side
	//lv_obj_t * btn2 = (lv_obj_t *) lv_obj_get_free_ptr(btn);
	lv_obj_t * btn2 = (lv_obj_t *) lv_obj_get_free_ptr(btn);
	static lv_style_t redstyle;
	lv_style_copy(&redstyle, &lv_style_plain);    /*Copy a built-in style to initialize the new style*/
	redstyle.body.main_color = LV_COLOR_RED;
	redstyle.body.grad_color = LV_COLOR_RED;
	redstyle.body.border.color = LV_COLOR_GRAY;
	redstyle.body.border.width = 2;
	redstyle.text.color = LV_COLOR_WHITE;

 static lv_style_t bluestyle;
 lv_style_copy(&bluestyle, &lv_style_plain);    /*Copy a built-in style to initialize the new style*/
 bluestyle.body.main_color = LV_COLOR_BLUE;
 bluestyle.body.grad_color = LV_COLOR_BLUE;
 bluestyle.body.border.color = LV_COLOR_GRAY;
 bluestyle.body.border.width = 2;
 bluestyle.text.color = LV_COLOR_WHITE;

		lv_obj_t * label1 = lv_obj_get_child(btn, NULL); /*The label is the only child*/
		if(blueSide == true){
			lv_obj_set_style(btn, &redstyle);
			blueSide = false;
			lv_label_set_text(label1, "Red");
			lv_obj_set_style(btn2,&redstyle);
      colorautonstate = 1;
			//lv_obj_set_style(btn2, &redstyle);

		} else
		{
			lv_obj_set_style(btn, &bluestyle);
			blueSide = true;
			lv_label_set_text(label1, "Blue");
			lv_obj_set_style(btn2,&bluestyle);
      colorautonstate = 2;
			//lv_obj_set_style(btn2, &bluestyle);
		}

		return LV_RES_OK;



 }

static lv_res_t side_action(lv_obj_t *btn2)
 {
	 static lv_style_t redstyle;
	 lv_style_copy(&redstyle, &lv_style_plain);    /*Copy a built-in style to initialize the new style*/
	 redstyle.body.main_color = LV_COLOR_RED;
	 redstyle.body.grad_color = LV_COLOR_RED;
	 redstyle.body.border.color = LV_COLOR_GRAY;
	 redstyle.body.border.width = 2;
	 redstyle.text.color = LV_COLOR_WHITE;

	static lv_style_t bluestyle;
	lv_style_copy(&bluestyle, &lv_style_plain);    /*Copy a built-in style to initialize the new style*/
	bluestyle.body.main_color = LV_COLOR_BLUE;
	bluestyle.body.grad_color = LV_COLOR_BLUE;
	bluestyle.body.border.color = LV_COLOR_GRAY;
	bluestyle.body.border.width = 2;
	bluestyle.text.color = LV_COLOR_WHITE;

	 //for sides (close and far)
	 static lv_style_t closestyle;
	 lv_style_copy(&closestyle, &lv_style_plain);
	 closestyle.body.main_color = LV_COLOR_RED;
	 closestyle.body.grad_color = LV_COLOR_RED;
	 closestyle.body.border.color =LV_COLOR_GRAY;
	 closestyle.body.border.width = 2;
	 closestyle.text.color = LV_COLOR_WHITE;

	 static lv_style_t farstyle;
	 lv_style_copy(&farstyle, &lv_style_plain);
	 farstyle.body.main_color = LV_COLOR_BLUE;
	 farstyle.body.grad_color = LV_COLOR_BLUE;
	 farstyle.body.border.color = LV_COLOR_GRAY;
	 farstyle.body.border.width = 2;
	 farstyle.text.color = LV_COLOR_WHITE;

	 lv_obj_t * label2 = lv_obj_get_child(btn2, NULL); /*The label is the only child*/
	 if(close == true){
		 lv_obj_set_style(btn2, &closestyle);
		 close = false;
		 lv_label_set_text(label2, "Right");
     sideautonstate = 1;
		 //lv_obj_set_style(btn2, &redstyle);

	 } else{
		 lv_obj_set_style(btn2, &farstyle);
		 close = true;
		 lv_label_set_text(label2, "Left");
     sideautonstate = 2;
		 //lv_obj_set_style(btn2, &bluestyle);

	 }
	 if(blueSide == true){
		 lv_obj_set_style(btn2, &bluestyle);
	 }
	 else{
		 lv_obj_set_style(btn2, &redstyle);
	 }

	 return LV_RES_OK;



 }


 void initialize(){
   static lv_style_t red;
  static lv_style_t blue;
  static lv_style_t close;
  static lv_style_t far;
  lv_style_copy(&red, &lv_style_plain);
  red.body.main_color = LV_COLOR_RED;
  red.body.grad_color = LV_COLOR_RED;
  red.body.border.color = LV_COLOR_GRAY;
  red.body.border.width = 2;
  red.text.color = LV_COLOR_WHITE;

  lv_style_copy(&blue, &lv_style_plain);
  blue.body.main_color = LV_COLOR_BLUE;
  blue.body.grad_color = LV_COLOR_BLUE;
  blue.body.border.color = LV_COLOR_GRAY;
  blue.body.border.width = 2;
  blue.text.color = LV_COLOR_WHITE;

  lv_style_copy(&close, &lv_style_plain);
  close.body.main_color = LV_COLOR_RED;
  close.body.grad_color = LV_COLOR_RED;
  close.body.border.color =LV_COLOR_GRAY;
  close.body.border.width = 2;
  close.text.color = LV_COLOR_WHITE;

  lv_style_copy(&far, &lv_style_plain);
  far.body.main_color = LV_COLOR_BLUE;
  far.body.grad_color = LV_COLOR_BLUE;
  far.body.border.color = LV_COLOR_GRAY;
  far.body.border.width = 2;
  far.text.color = LV_COLOR_WHITE;


  lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_style(btn1, &red);
  lv_obj_t * label = lv_label_create(btn1,NULL);
  lv_label_set_text(label, "Red");
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, color_action);
  lv_obj_align(btn1,label,LV_ALIGN_IN_TOP_LEFT,20,30);


  lv_obj_t *btn2 = lv_btn_create(lv_scr_act(),NULL);
  lv_obj_set_style(btn2, &close);
  lv_obj_t * label2 = lv_label_create(btn2,NULL);
  lv_label_set_text(label2, "Right");
  lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, side_action);
  lv_obj_align(btn2,label2,LV_ALIGN_OUT_BOTTOM_RIGHT,330,10);
  //lv_obj_set_event_cb(btn1, btn1_event_cb);
   lv_obj_set_free_ptr(btn1, btn2);





}
