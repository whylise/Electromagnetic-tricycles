#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include  "common.h"



/**********ȫ�ֱ����ⲿ����********/
extern int16 g_ValueOfAD[5];
extern int32 g_fDirection_ControlOut ;	        //����������
extern int32 g_fDirection_ControlOutNew ;

extern float g_fDirection_Error[2]; 
extern float g_fDirection_Error_dot[2]; 

extern uint16 TIME_ROUND ;
extern uint16 Left_Round;

extern uint16 Right_Round ;
extern uint16 Round ;
/***********��������***********/
void ADC_Get(void);
void Direction_Control();
#endif