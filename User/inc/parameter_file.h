#ifndef __PARAMETER_FILE_H__
#define __PARAMETER_FILE_H__

#include  "common.h"



/**********全局变量外部申明********/
/**********输入参数定义********/
extern int32 program_Time;                      //程序周期（ms）
extern float g_fExpect_Speed;	        	//期望速度
extern float speed_Control_P;		        //速度P
extern float speed_Control_I;		        //速度I
extern float speed_Control_D;		        //速度D

//位置式
extern float speed_location_P;		                                //速度P
extern float speed_location_I;		                                //速度I
extern float speed_location_D;		                                //速度I



extern uint8 Flag_Stop;			//=OFF停车
extern uint8 Flag_Speed;			//=ON增加速度控制
extern uint8 Flag_Direction;		        //=ON增加方向控制
extern uint8 Flag_Round;		        //进入环岛的标志（在环岛里为ON）

extern float g_dirControl_P;		         //方向控制P
extern float g_dirControl_D;	                 //方向控制D

extern float g_dir_C_Control_P;		         //方向控制圆环P
extern float g_dir_C_Control_D; 	                 //方向控制圆环D





/**********比例参数定义********/
extern float Ratio_Encoder_Left;               //左轮实际速度转化比例
extern float Ratio_Encoder_Right;               //右轮实际速度转化比例



extern uint16 BM1_Flag;
extern uint16 BM2_Flag;
extern uint16 BM3_Flag;
extern uint16 BM4_Flag;



#endif