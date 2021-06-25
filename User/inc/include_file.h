/*********************************************************************************************************************
 * 
 * @file       		includefile.h
 *  				头文件
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/



//#include "gpio_icf.h"
#include "stdio.h"


//--------函数库--------//(Chip)
#include "common.h"
#include "KEA128_ftm.h"
#include "KEA128_pit.h"
#include "KEA128_gpio.h"
#include "KEA128_port.h"
#include "KEA128_adc.h"
#include "KEA128_irq.h"
#include "KEA128_uart.h"
#include "KEA128_kbi.h"
#include "KEA128_flash.h"
#include "KEA128_systick.h"
#include "SEEKFREE_OLED.h"


//--------用户函数--------//(User)
#include "KEA128_port_cfg.h"
#include "car_init.h"
#include "isr.h"
#include "speed.h"
#include "parameter_file.h"
#include "direction.h"
#include "bluetooth.h"


