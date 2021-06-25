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
    //ADC��ʼ��
    adc_init(AD1);   
    adc_init(AD2);   
    adc_init(AD3);   
    adc_init(AD4);
    adc_init(AD5);
    
    //OLED��ʼ��
     OLED_Init();

     
    //��������ʼ��
    gpio_init(BUZZ,GPO,0);
	    gpio_init(C7,GPO,0);
            
            
           
    //���뿪��
    gpio_init(BM1,GPI,1);         //1	
    gpio_init(BM2,GPI,1);         //2
    gpio_init(BM3,GPI,1);         //3
    gpio_init(BM4,GPI,1);         //4
        port_pull(BM1);
        port_pull(BM2);
        port_pull(BM3);
        port_pull(BM4);    
    

     
    //�ɻɹ�
    gpio_init(G1,GPI,1);         //1	
    gpio_init(G2,GPI,1);         //2
    gpio_init(G3,GPI,1);         //3
    gpio_init(G4,GPI,1);         //4
      port_pull(G1);
      port_pull(G2);
      port_pull(G3);
      port_pull(G4);

      
            
    
	//���뿪�ػ��ýӿڳ�ʼ��(����Ϊ���뿪�ػ��ýӿ�)
    gpio_init(K1,GPI,1);         //1	���뿪�أ�K1-4�����ڱ��ýӿ����ΪGPO;
    gpio_init(K2,GPI,1);         //2
    gpio_init(K3,GPI,1);         //3
    gpio_init(K4,GPI,1);         //4
    
    //�����ʼ��
    ftm_pwm_init(ftm2,ftm_ch2,12000,0);
    ftm_pwm_init(ftm2,ftm_ch3,12000,0);
    ftm_pwm_init(ftm2,ftm_ch4,12000,0);
    ftm_pwm_init(ftm2,ftm_ch5,12000,0);
    
    
    //���������ʼ��
    ftm_count_init(ftm0);
    gpio_init(Coder_dir_left,GPI,0);
    //�ұ�������ʼ��
    ftm_count_init(ftm1); 
    gpio_init(Coder_dir_right,GPI,0);

	//��ʱ1s
    systick_delay_ms(1000);
	
    //��ʱ����ʼ��
    pit_init_us(PIT0,5000);                             //�жϳ�ʼ��(5ms)
    set_irq_priority(PIT_CH0_IRQn,1);                   //�ж����ȼ�1
    enable_irq(PIT_CH0_IRQn);                           //ʹ���ж�
    
}

