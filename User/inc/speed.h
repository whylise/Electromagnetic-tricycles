#ifndef __SPEED_H__
#define __SPEED_H__

#include  "common.h"



/**********ȫ�ֱ����ⲿ����********/
extern  int32 g_fSpeed_ControlOut;
extern int32 g_nLeftPWM, g_nRightPWM ;

extern float g_fReal_Speed; 

/***********��������***********/
void Round_Speed(float Round_speed);
void PWMOut(void);
void Speed_Control(void);
void Speed_Control_location(void);

#endif