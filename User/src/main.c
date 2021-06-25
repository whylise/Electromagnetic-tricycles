/*********************************************************************************************************************
 * 
 * @file       		main.c
 *  				������
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/

#include "include_file.h"
extern int16 g_ValueOfAD[5]; 

int32 date_heard[2] = {0x03,0xfc};
uint16 Gears = 0;
uint16 SET_flag = 0;

int main(void)
{
  get_clk();              //��ȡʱ��Ƶ��
  DisableInterrupts;
  
  car_init();
 
  EnableInterrupts;
  
  while(1)
  {
    
    
    //��ʾOLED��в���
    if(gpio_get(BM1)==0)
    {
      BM1_Flag = ON;
      Flag_Speed = OFF;
      Flag_Direction   =  OFF;
      
//OLED��ʾ��в���     
    OLED_Print_Num1(10  ,5  ,   g_ValueOfAD[0]);
    OLED_Print_Num1(70  ,5  ,   g_ValueOfAD[1]);
    OLED_Print_Num1(10  ,6  ,   g_ValueOfAD[2]);
    OLED_Print_Num1(70  ,6  ,   g_ValueOfAD[3]);
    OLED_Print_Num1(50  ,7  ,   g_ValueOfAD[4]);
    
//OLED��ʾ�����ٶȿ�����
    OLED_Print_Num1(10  ,1  ,   g_fSpeed_ControlOut);
    OLED_Print_Num1(70  ,1  ,   g_fDirection_ControlOutNew);  
 
    
    }
    
    if((gpio_get(BM2)==0))   BM2_Flag = 10;
    else BM2_Flag = 0;
   
    if((gpio_get(BM3)==0))   BM3_Flag = 100;
    else BM3_Flag = 0;
    
    if((gpio_get(BM4)==0))   BM4_Flag = 1000;
    else BM4_Flag = 0;
    
 
 
   if(SET_flag <= 10)
   {
     SET_flag++;
//һ���ٶ�
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==10))
    {
     Gears = 1;
     
      g_fExpect_Speed = 1800;
      g_dir_C_Control_P = 26;		         //�������Բ��P  35
      g_dir_C_Control_D = 28; 	                 //�������Բ��D   45
      
       g_dirControl_P = 35;		         //�������P  33
       g_dirControl_D = 40; 	                 //�������D   40
      
      
      speed_location_P = 0.08;		                                //�ٶ�P
      speed_location_I = 0.014;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    
 //�����ٶ�   
     if(((BM2_Flag + BM3_Flag + BM4_Flag)==100))
    {
      Gears = 2;
     
      g_fExpect_Speed = 2000;
      g_dir_C_Control_P = 26;		         //�������Բ��P  35
      g_dir_C_Control_D = 35; 	                 //�������Բ��D   45
      
       g_dirControl_P = 35;		         //�������P  33
       g_dirControl_D = 40; 	                 //�������D   40
      
      
      speed_location_P = 0.10;		                                //�ٶ�P
      speed_location_I = 0.015;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    

    //�����ٶ�       
     if(((BM2_Flag + BM3_Flag + BM4_Flag)==110))
    {
      Gears = 3;
     
      g_fExpect_Speed = 2200;
      g_dir_C_Control_P = 29;		         //�������Բ��P  35
      g_dir_C_Control_D = 35; 	                 //�������Բ��D   45
      
       g_dirControl_P = 38;		         //�������P  33
       g_dirControl_D = 42; 	                 //�������D   40
      
      
      speed_location_P = 0.12;		                                //�ٶ�P
      speed_location_I = 0.015;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
  
        //�ĵ��ٶ� 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1000))
    {
      Gears = 4;
     
      g_fExpect_Speed = 2300;
      g_dir_C_Control_P = 32;		         //�������Բ��P  35
      g_dir_C_Control_D = 38; 	                 //�������Բ��D   45
      
       g_dirControl_P = 39;		         //�������P  33
       g_dirControl_D = 42; 	                 //�������D   40
      
      
      speed_location_P = 0.12;		                                //�ٶ�P
      speed_location_I = 0.016;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    
            //�嵵�ٶ� 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1010))
    {
      Gears = 5;
     
      g_fExpect_Speed = 2400;
      g_dir_C_Control_P = 35;		         //�������Բ��P  35
      g_dir_C_Control_D = 38; 	                 //�������Բ��D   45
      
       g_dirControl_P = 38;		         //�������P  33
       g_dirControl_D = 43; 	                 //�������D   40
      
      
      speed_location_P = 0.12;		                                //�ٶ�P
      speed_location_I = 0.017;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    
            //�����ٶ� 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1100))
    {
      Gears = 6;
     
      g_fExpect_Speed = 2500;
      g_dir_C_Control_P = 38;		         //�������Բ��P  35
      g_dir_C_Control_D = 40; 	                 //�������Բ��D   45
      
       g_dirControl_P = 40;		         //�������P  33
       g_dirControl_D = 42; 	                 //�������D   40
      
      
      speed_location_P = 0.12;		                                //�ٶ�P
      speed_location_I = 0.019;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    
                //�ߵ��ٶ� 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1110))
    {
      Gears = 6;
     
      g_fExpect_Speed = 2600;
      g_dir_C_Control_P = 39;		         //�������Բ��P  35
      g_dir_C_Control_D = 40; 	                 //�������Բ��D   45
      
       g_dirControl_P = 44;		         //�������P  33
       g_dirControl_D = 43; 	                 //�������D   40
      
      
      speed_location_P = 0.12;		                                //�ٶ�P
      speed_location_I = 0.02;		                                //�ٶ�I
      speed_location_D = 0.02;		                                //�ٶ�I
      
    }
    
   }
    
    
   //�ɻɹ�ͣ�� 
    
     if(((gpio_get(G4)== 0)||(gpio_get(G3)== 0)||(gpio_get(G2)== 0))&&(G_STOP>=600))
      {
     G_STOP = 0;
     systick_delay(800);
     g_fExpect_Speed = 0;
     Flag_Speed = OFF;
     Flag_Direction   =  ON;
    
       }
    
    
  }
  
}