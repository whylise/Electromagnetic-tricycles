#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include  "common.h"



/**********全局变量外部申明********/
extern int16 g_ValueOfAD[5];
extern int32 g_fDirection_ControlOut ;	        //方向控制输出
extern int32 g_fDirection_ControlOutNew ;

extern float g_fDirection_Error[2]; 
extern float g_fDirection_Error_dot[2]; 

extern uint16 TIME_ROUND ;
extern uint16 Left_Round;

extern uint16 Right_Round ;
extern uint16 Round ;
/***********函数声明***********/
void ADC_Get(void);
void Direction_Control();
#endif