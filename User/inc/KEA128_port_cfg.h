/*********************************************************************************************************************
 * 
 * @file       		KEA128_port_cfg.h
 *  				KEA引脚配置
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/

#ifndef _KEA128_port_cfg_h
#define _KEA128_port_cfg_h


//---------------------------------  MY Define  --------------------------------
#define    ON                   1
#define    OFF  		0

//---------------------------------  BUZZ  --------------------------------
#define    BUZZ    		F1


//---------------------------------  按键  --------------------------------
#define    K1			E2
#define    K2			I2
#define    K3			E3
#define    K4			I3



//---------------------------------  编码器方向  -------------------------------
#define Coder_dir_left			H5
#define Coder_dir_right			C5


//---------------------------------  ADC  -------------------------------
#define AD1                       ADC0_SE7
#define AD2	                  ADC0_SE15
#define AD3                       ADC0_SE6
#define AD4	                  ADC0_SE13
#define AD5                       ADC0_SE12


//-----------------------------------  拨码开关 -----------------------------------
//     模块通道                端口      可选范围              建议


#define  G1                    D4
#define  G2                    D2
#define  G3                    F0
#define  G4                    D3

#define  BM1                    E4
#define  BM2                    A6
#define  BM3                    A7
#define  BM4                    B0

//-----------------------------------  OLED -----------------------------------
//     模块通道                端口      可选范围              建议

#define  OLED_SCL_PIN	        H0
#define  OLED_SDA_PIN	        H1
#define  OLED_RST_PIN	        E5
#define  OLED_DC_PIN	        E6


//-----------------------------------  IRQ  ------------------------------------
//      模块通道               端口      可选范围                   建议
#define IRQ_PIN                 I5        //A5 I0 I1 I2 I3 I4 I5 I6  A5不要用（与复位按键冲突）   

//-----------------------------------  UART  -----------------------------------

//      模块通道               端口      可选范围                建议
//在切换引脚时，务必成对切换。编号相邻得两个引脚为一对
#define UART0_RX_PIN            B0        //A2 B0
#define UART0_TX_PIN            B1        //A3 B1
                                       
#define UART1_RX_PIN            F3        //C6 F2
#define UART1_TX_PIN            F2        //C7 F3
                                       
#define UART2_RX_PIN            I0        //D6 I0
#define UART2_TX_PIN            I1        //D7 I1

//-----------------------------------  FTM  ------------------------------------

//      模块通道               端口      可选范围                建议
#define FTM0_CH0_PIN            A0        //B2 A0
#define FTM0_CH1_PIN            A1        //B3 A1

//      模块通道               端口      可选范围                建议
#define FTM1_CH0_PIN            H2        //H2 C4
#define FTM1_CH1_PIN            C5        //E7 C5

//      模块通道               端口      可选范围                建议
#define FTM2_CH0_PIN            H0        //C0  H0 F0              
#define FTM2_CH1_PIN            H1        //C1  H1 F1  
#define FTM2_CH2_PIN            G4        //C2  G4 D0  
#define FTM2_CH3_PIN            G5        //C3  G5 D1
#define FTM2_CH4_PIN            G6        //B4  G6  
#define FTM2_CH5_PIN            G7        //B5  G7              


//外部计数模块通道             端口      可选范围                建议
#define FTM0_COUNT_PIN          E0        //E7 A5  E0             A5不要用（与复位按键冲突）                
                                           
#define FTM1_COUNT_PIN          E7        //E0 A5  E7             A5不要用（与复位按键冲突）
                                           

#endif
