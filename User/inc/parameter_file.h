#ifndef __PARAMETER_FILE_H__
#define __PARAMETER_FILE_H__

#include  "common.h"



/**********ȫ�ֱ����ⲿ����********/
/**********�����������********/
extern int32 program_Time;                      //�������ڣ�ms��
extern float g_fExpect_Speed;	        	//�����ٶ�
extern float speed_Control_P;		        //�ٶ�P
extern float speed_Control_I;		        //�ٶ�I
extern float speed_Control_D;		        //�ٶ�D

//λ��ʽ
extern float speed_location_P;		                                //�ٶ�P
extern float speed_location_I;		                                //�ٶ�I
extern float speed_location_D;		                                //�ٶ�I



extern uint8 Flag_Stop;			//=OFFͣ��
extern uint8 Flag_Speed;			//=ON�����ٶȿ���
extern uint8 Flag_Direction;		        //=ON���ӷ������
extern uint8 Flag_Round;		        //���뻷���ı�־���ڻ�����ΪON��

extern float g_dirControl_P;		         //�������P
extern float g_dirControl_D;	                 //�������D

extern float g_dir_C_Control_P;		         //�������Բ��P
extern float g_dir_C_Control_D; 	                 //�������Բ��D





/**********������������********/
extern float Ratio_Encoder_Left;               //����ʵ���ٶ�ת������
extern float Ratio_Encoder_Right;               //����ʵ���ٶ�ת������



extern uint16 BM1_Flag;
extern uint16 BM2_Flag;
extern uint16 BM3_Flag;
extern uint16 BM4_Flag;



#endif