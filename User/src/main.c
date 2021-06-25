/*********************************************************************************************************************
 * 
 * @file       		main.c
 *  				主函数
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
  get_clk();              //获取时钟频率
  DisableInterrupts;
  
  car_init();
 
  EnableInterrupts;
  
  while(1)
  {
    
    
    //显示OLED电感参数
    if(gpio_get(BM1)==0)
    {
      BM1_Flag = ON;
      Flag_Speed = OFF;
      Flag_Direction   =  OFF;
      
//OLED显示电感参数     
    OLED_Print_Num1(10  ,5  ,   g_ValueOfAD[0]);
    OLED_Print_Num1(70  ,5  ,   g_ValueOfAD[1]);
    OLED_Print_Num1(10  ,6  ,   g_ValueOfAD[2]);
    OLED_Print_Num1(70  ,6  ,   g_ValueOfAD[3]);
    OLED_Print_Num1(50  ,7  ,   g_ValueOfAD[4]);
    
//OLED显示方向速度控制量
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
//一档速度
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==10))
    {
     Gears = 1;
     
      g_fExpect_Speed = 1800;
      g_dir_C_Control_P = 26;		         //方向控制圆环P  35
      g_dir_C_Control_D = 28; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 35;		         //方向控制P  33
       g_dirControl_D = 40; 	                 //方向控制D   40
      
      
      speed_location_P = 0.08;		                                //速度P
      speed_location_I = 0.014;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    
 //二档速度   
     if(((BM2_Flag + BM3_Flag + BM4_Flag)==100))
    {
      Gears = 2;
     
      g_fExpect_Speed = 2000;
      g_dir_C_Control_P = 26;		         //方向控制圆环P  35
      g_dir_C_Control_D = 35; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 35;		         //方向控制P  33
       g_dirControl_D = 40; 	                 //方向控制D   40
      
      
      speed_location_P = 0.10;		                                //速度P
      speed_location_I = 0.015;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    

    //三档速度       
     if(((BM2_Flag + BM3_Flag + BM4_Flag)==110))
    {
      Gears = 3;
     
      g_fExpect_Speed = 2200;
      g_dir_C_Control_P = 29;		         //方向控制圆环P  35
      g_dir_C_Control_D = 35; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 38;		         //方向控制P  33
       g_dirControl_D = 42; 	                 //方向控制D   40
      
      
      speed_location_P = 0.12;		                                //速度P
      speed_location_I = 0.015;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
  
        //四档速度 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1000))
    {
      Gears = 4;
     
      g_fExpect_Speed = 2300;
      g_dir_C_Control_P = 32;		         //方向控制圆环P  35
      g_dir_C_Control_D = 38; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 39;		         //方向控制P  33
       g_dirControl_D = 42; 	                 //方向控制D   40
      
      
      speed_location_P = 0.12;		                                //速度P
      speed_location_I = 0.016;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    
            //五档速度 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1010))
    {
      Gears = 5;
     
      g_fExpect_Speed = 2400;
      g_dir_C_Control_P = 35;		         //方向控制圆环P  35
      g_dir_C_Control_D = 38; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 38;		         //方向控制P  33
       g_dirControl_D = 43; 	                 //方向控制D   40
      
      
      speed_location_P = 0.12;		                                //速度P
      speed_location_I = 0.017;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    
            //六档速度 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1100))
    {
      Gears = 6;
     
      g_fExpect_Speed = 2500;
      g_dir_C_Control_P = 38;		         //方向控制圆环P  35
      g_dir_C_Control_D = 40; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 40;		         //方向控制P  33
       g_dirControl_D = 42; 	                 //方向控制D   40
      
      
      speed_location_P = 0.12;		                                //速度P
      speed_location_I = 0.019;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    
                //七档速度 
    if(((BM2_Flag + BM3_Flag + BM4_Flag)==1110))
    {
      Gears = 6;
     
      g_fExpect_Speed = 2600;
      g_dir_C_Control_P = 39;		         //方向控制圆环P  35
      g_dir_C_Control_D = 40; 	                 //方向控制圆环D   45
      
       g_dirControl_P = 44;		         //方向控制P  33
       g_dirControl_D = 43; 	                 //方向控制D   40
      
      
      speed_location_P = 0.12;		                                //速度P
      speed_location_I = 0.02;		                                //速度I
      speed_location_D = 0.02;		                                //速度I
      
    }
    
   }
    
    
   //干簧管停车 
    
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