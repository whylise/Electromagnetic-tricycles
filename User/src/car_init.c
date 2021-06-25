/*********************************************************************************************************************
 * 
 * @file       		car_init.c
 *  		
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/


#include "include_file.h"


void car_init()
{
    //ADC初始化
    adc_init(AD1);   
    adc_init(AD2);   
    adc_init(AD3);   
    adc_init(AD4);
    adc_init(AD5);
    
    //OLED初始化
     OLED_Init();

     
    //蜂鸣器初始化
    gpio_init(BUZZ,GPO,0);
	    gpio_init(C7,GPO,0);
            
            
           
    //编码开关
    gpio_init(BM1,GPI,1);         //1	
    gpio_init(BM2,GPI,1);         //2
    gpio_init(BM3,GPI,1);         //3
    gpio_init(BM4,GPI,1);         //4
        port_pull(BM1);
        port_pull(BM2);
        port_pull(BM3);
        port_pull(BM4);    
    

     
    //干簧管
    gpio_init(G1,GPI,1);         //1	
    gpio_init(G2,GPI,1);         //2
    gpio_init(G3,GPI,1);         //3
    gpio_init(G4,GPI,1);         //4
      port_pull(G1);
      port_pull(G2);
      port_pull(G3);
      port_pull(G4);

      
            
    
	//拨码开关或备用接口初始化(复用为拨码开关或备用接口)
    gpio_init(K1,GPI,1);         //1	拨码开关，K1-4若用于备用接口则改为GPO;
    gpio_init(K2,GPI,1);         //2
    gpio_init(K3,GPI,1);         //3
    gpio_init(K4,GPI,1);         //4
    
    //电机初始化
    ftm_pwm_init(ftm2,ftm_ch2,12000,0);
    ftm_pwm_init(ftm2,ftm_ch3,12000,0);
    ftm_pwm_init(ftm2,ftm_ch4,12000,0);
    ftm_pwm_init(ftm2,ftm_ch5,12000,0);
    
    
    //左编码器初始化
    ftm_count_init(ftm0);
    gpio_init(Coder_dir_left,GPI,0);
    //右编码器初始化
    ftm_count_init(ftm1); 
    gpio_init(Coder_dir_right,GPI,0);

	//延时1s
    systick_delay_ms(1000);
	
    //定时器初始化
    pit_init_us(PIT0,5000);                             //中断初始化(5ms)
    set_irq_priority(PIT_CH0_IRQn,1);                   //中断优先级1
    enable_irq(PIT_CH0_IRQn);                           //使能中断
    
}

