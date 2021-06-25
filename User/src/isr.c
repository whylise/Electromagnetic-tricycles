/*********************************************************************************************************************
 * 
 * @file       		isr.c
 *  				中断服务函数
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/
#include "include_file.h"


/****************全局变量定义******************/
    static uint16 ATtime = 0;
//     static uint16 N=0;
//     static uint16 K=0;
    uint16 G_STOP = 0;
    
void PIT_CH0_IRQHandler(void)
{
  
     PIT_FLAG_CLR(PIT0);
    //标志变量定义  
     G_STOP++;
       
    if(TIME_ROUND )                 //圆环控制
        {
          ATtime++;

          if(ATtime >= 200)  
          {
          //  ATtime = 0;
              TIME_ROUND = 2;

          }
          
          if(ATtime>= 400)    //660
          {
              ATtime = 0;
              TIME_ROUND = 0;
          }


       } 

 
     if(Flag_Stop == ON) 								//如果Flag_Stop == ON电机输出0
      {
          g_nLeftPWM = 0;g_nRightPWM = 0;
       }
    
    static uint16 Flag_Speed_Control = 0;    
    
    Flag_Speed_Control++;
    if(Flag_Speed_Control >= 4)         //20ms进行一次速度控制
    {
      Flag_Speed_Control = 0;
      
      Speed_Control_location();
      
    }
    
    
    Direction_Control();	        //方向控制
      

    PWMOut();    //最终PWM输出

    
}


void PIT_CH1_IRQHandler(void)
{
    PIT_FLAG_CLR(PIT1); 
    
    
    
    
}

void IRQ_IRQHandler(void)
{  
    CLEAR_IRQ_FLAG; 
}

void KBI0_IRQHandler(void)
{
    CLEAN_KBI0_FLAG;

}

/*
记得进入中断后清除标志位
FTMRE_IRQHandler      
PMC_IRQHandler        
IRQ_IRQHandler        
I2C0_IRQHandler       
I2C1_IRQHandler       
SPI0_IRQHandler       
SPI1_IRQHandler       
UART0_IRQHandler 
UART1_IRQHandler 
UART2_IRQHandler 
ADC0_IRQHandler       
ACMP0_IRQHandler      
FTM0_IRQHandler       
FTM1_IRQHandler       
FTM2_IRQHandler       
RTC_IRQHandler        
ACMP1_IRQHandler      
PIT_CH0_IRQHandler    
PIT_CH1_IRQHandler    
KBI0_IRQHandler       
KBI1_IRQHandler       
Reserved26_IRQHandler 
ICS_IRQHandler        
WDG_IRQHandler        
PWT_IRQHandler        
MSCAN_Rx_IRQHandler   
MSCAN_Tx_IRQHandler   
*/

