/*********************************************************************************************************************
 * 
 * @file       		speed.c
 *  				速度控制
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/

#include  "include_file.h"


/**********输入参数定义********/
   
/**********公用参数********/       
int32 program_Time = 5;                                                 //程序周期（ms）
uint8 Flag_Stop = OFF;			                                //=ON停车
uint8 Flag_Speed = ON;			                                //=ON增加速度控制
uint8 Flag_Direction = ON;	        	                        //=ON增加方向控制

int8   speed_pattern = 1;
    
 uint16 BM1_Flag = OFF;
 uint16 BM2_Flag = OFF;
 uint16 BM3_Flag = OFF;
 uint16 BM4_Flag = OFF;


/**********speed.c********/
//int32 LeftDead = 0;                                                   //左 电机启动值(pwm)
//int32 RighDead = 0;                                                   //右 电机启动值(pwm)

float   g_fExpect_Speed = 2000;
float speed_Control_P = 0.40;		                                //速度P
float speed_Control_I = 0.2;		                                //速度I
float speed_Control_D = 0.2;		                                //速度I

//位置式
float speed_location_P = 0.08;		                                //速度P
float speed_location_I = 0.011;		                                //速度I
float speed_location_D = 0.02;		                                //速度I

/**********direction.c********/
float g_dirControl_P = 37;		         //方向控制P  33
float g_dirControl_D = 42; 	                 //方向控制D   40
uint8 Flag_Round = OFF;			                                 //进入环岛的标志（在环岛里为ON）

float g_dir_C_Control_P = 25;		         //方向控制圆环P  35
float g_dir_C_Control_D = 29; 	                 //方向控制圆环D   45






/**********比例参数定义********/


/**********speed.c********/
float Ratio_Encoder_Left = 8.922;// 左 轮速度=counter*左 轮周长(mm)/(左 轮转一圈对应的脉冲数*程序周期)  = 207/(1160*0.02)
float Ratio_Encoder_Right = 8.922;// 右 轮速度=counter*右 轮周长(mm)/(右 轮转一圈对应的脉冲数*程序周期)  = 207/(1160*0.02)