/*********************************************************************************************************************
 * 
 * @file       		speed.c
 *  				�ٶȿ���
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/

#include  "include_file.h"


/**********�����������********/
   
/**********���ò���********/       
int32 program_Time = 5;                                                 //�������ڣ�ms��
uint8 Flag_Stop = OFF;			                                //=ONͣ��
uint8 Flag_Speed = ON;			                                //=ON�����ٶȿ���
uint8 Flag_Direction = ON;	        	                        //=ON���ӷ������

int8   speed_pattern = 1;
    
 uint16 BM1_Flag = OFF;
 uint16 BM2_Flag = OFF;
 uint16 BM3_Flag = OFF;
 uint16 BM4_Flag = OFF;


/**********speed.c********/
//int32 LeftDead = 0;                                                   //�� �������ֵ(pwm)
//int32 RighDead = 0;                                                   //�� �������ֵ(pwm)

float   g_fExpect_Speed = 2000;
float speed_Control_P = 0.40;		                                //�ٶ�P
float speed_Control_I = 0.2;		                                //�ٶ�I
float speed_Control_D = 0.2;		                                //�ٶ�I

//λ��ʽ
float speed_location_P = 0.08;		                                //�ٶ�P
float speed_location_I = 0.011;		                                //�ٶ�I
float speed_location_D = 0.02;		                                //�ٶ�I

/**********direction.c********/
float g_dirControl_P = 37;		         //�������P  33
float g_dirControl_D = 42; 	                 //�������D   40
uint8 Flag_Round = OFF;			                                 //���뻷���ı�־���ڻ�����ΪON��

float g_dir_C_Control_P = 25;		         //�������Բ��P  35
float g_dir_C_Control_D = 29; 	                 //�������Բ��D   45






/**********������������********/


/**********speed.c********/
float Ratio_Encoder_Left = 8.922;// �� ���ٶ�=counter*�� ���ܳ�(mm)/(�� ��תһȦ��Ӧ��������*��������)  = 207/(1160*0.02)
float Ratio_Encoder_Right = 8.922;// �� ���ٶ�=counter*�� ���ܳ�(mm)/(�� ��תһȦ��Ӧ��������*��������)  = 207/(1160*0.02)