#ifndef __SPEED_H__
#define __SPEED_H__

#include  "common.h"



/**********全局变量外部申明********/
extern  int32 g_fSpeed_ControlOut;
extern int32 g_nLeftPWM, g_nRightPWM ;

extern float g_fReal_Speed; 

/***********函数声明***********/
void Round_Speed(float Round_speed);
void PWMOut(void);
void Speed_Control(void);
void Speed_Control_location(void);

#endif