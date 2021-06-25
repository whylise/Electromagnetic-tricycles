/*********************************************************************************************************************
 * 
 * @file       		bluetooth.c
 *  		
 * @core	        S9KEA128
 * @date       		2018
 ********************************************************************************************************************/

#include "include_file.h"
uint8 flag_bluetooth=0;
uint8 flag_bluetooth_control = 0;
uint8 parameter_selection = 0;

int16 change_dirControl_P = 0;
int16 change_dirControl_D = 0;

int16 change_C_dirControl_P = 0;
int16 change_C_dirControl_D = 0;

int16 change_speedControl_P = 0;
int16 change_speedControl_I = 0;

int16 change_ExpectSpeed=0;

char char_return[9];

uint8 Flag_show_computer = OFF;


void Bluethooth_Control()
{
  if(uart_querychar (uart1, &flag_bluetooth)!=0)
  {
    flag_bluetooth_control = (flag_bluetooth != 1 ? flag_bluetooth:0);
    
    if((flag_bluetooth <=250) && (flag_bluetooth>=51) ==1)      parameter_selection = flag_bluetooth;
  }


  switch(flag_bluetooth_control)
  {
    case 0x02: //�ϼ�
    {
      Flag_Stop = OFF;
      OLED_Print_Num1(70, 4 ,flag_bluetooth_control);
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x03: //�¼�
    {
      Flag_Stop = ON;
      OLED_Print_Num1(70, 4 ,flag_bluetooth_control);
      flag_bluetooth_control=0;
    }
    break;
   
    
    case 0x06: //��ת���                                   //����ת�����Ŀ���ٶ�   ��һ��+-50   //����Ҽ�
    {
      change_ExpectSpeed -= 50;
      OLED_Print_Num1(70, 7 ,g_fExpect_Speed);
      flag_bluetooth_control=0;
    }
    break;
    
    
    case 0x07: //��ת���
    {
      change_ExpectSpeed += 50;
      OLED_Print_Num1(70, 7 ,g_fExpect_Speed);
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x08:  //�����ȼ�
    {
      gpio_turn(BUZZ);
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x20:  //PC�˿����Ƿ���ʾ����
    {
      Flag_show_computer = ON;
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x21:  //PC�˿����Ƿ���ʾ����
    {
      Flag_show_computer = OFF;
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x30:  //PC�˿����Ƿ�����ٶȷ���     //�����
    {
      Flag_Speed = ON;
      flag_bluetooth_control=0;
    }
    break;
    
    case 0x31:  //PC�˿����Ƿ�����ٶȷ���     //���
    {
      Flag_Speed = OFF;
      flag_bluetooth_control=0;
    }
    break;

    
    default:
    {
      if((parameter_selection <=75) && (parameter_selection >= 51))        //����speedControl_P  //����Ҽ�+-5
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            speed_Control_P -=5;
            OLED_Print_Num1(70, 5 ,speed_Control_P);
            flag_bluetooth_control=0;
          }
          break;
    
          case 0x05: //�Ҽ�
          {
            speed_Control_P +=5;
            OLED_Print_Num1(70, 5 ,speed_Control_P);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      if((parameter_selection <=100) && (parameter_selection >= 76))       //����speedControl_I  //����Ҽ�+-1
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            speed_Control_I -=1;
            OLED_Print_Num1(70, 6 ,speed_Control_I);
            flag_bluetooth_control=0;
          }
          break;
    
          case 0x05: //�Ҽ�
          {
            speed_Control_I +=1;
            OLED_Print_Num1(70, 6 ,speed_Control_I);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      if((parameter_selection <= 125) && (parameter_selection >= 101))      //����direction_P  //����Ҽ�+-5
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            g_dirControl_P -=5;
            OLED_Print_Num1(70, 5 ,g_dirControl_P);
            flag_bluetooth_control=0;
          }
          break;
    
          case 0x05: //�Ҽ�
          {
            g_dirControl_P +=5;
            OLED_Print_Num1(70, 5 ,g_dirControl_P);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      if((parameter_selection <=150) && (parameter_selection >= 126))       //����direction_D  //����Ҽ�+-10
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            g_dirControl_D -=10;
            OLED_Print_Num1(70, 6 ,g_dirControl_D);
            flag_bluetooth_control=0;
          }  
          break;
    
          case 0x05: //�Ҽ�
          {
            g_dirControl_D +=10;
            OLED_Print_Num1(70, 6 ,g_dirControl_D);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      if((parameter_selection <=200) && (parameter_selection >= 151))       //����Բ��direction_P  //����Ҽ�+-10
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            g_dir_C_Control_P -=5;
            OLED_Print_Num1(70, 6 ,g_dir_C_Control_P);
            flag_bluetooth_control=0;
          }  
          break;
    
          case 0x05: //�Ҽ�
          {
            g_dir_C_Control_P +=5;
            OLED_Print_Num1(70, 6 ,g_dir_C_Control_P);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      if((parameter_selection <=250) && (parameter_selection >= 201))       //����Բ��direction_D  //����Ҽ�+-10
      {
        
        switch(flag_bluetooth_control)
        {
          case 0x04: //���                                       
          {
            g_dir_C_Control_D -=10;
            OLED_Print_Num1(70, 6 ,g_dir_C_Control_D);
            flag_bluetooth_control=0;
          }  
          break;
    
          
          case 0x05: //�Ҽ�
          {
            g_dir_C_Control_D +=10;
            OLED_Print_Num1(70, 6 ,g_dir_C_Control_D);
            flag_bluetooth_control=0;
          }
          break;
        }
        
      }
      
      flag_bluetooth_control=0;
    }
    break;
  }
    
}



//default:
//    {
//      OLED_Print_Num1(70, 4 ,flag_bluetooth_control);
//      
//      if( (flag_bluetooth_control>=51) && (flag_bluetooth_control<=150))
//      {
//        change_ExpectSpeed -=50;
//        OLED_Print_Num1(70, 7 ,800+change_ExpectSpeed);
//        flag_bluetooth_control=0;
//      }
//   
//      if( (flag_bluetooth_control>=151) && (flag_bluetooth_control<=250))
//      {
//        change_ExpectSpeed +=50;
//        OLED_Print_Num1(70, 7 ,800+change_ExpectSpeed);
//        flag_bluetooth_control=0;
//      }
//    }
//    break;







/**
 * @file		������������׼������
 * @note      	        �����ַ���
 * @date		2018
 */
char return_char(int8 number)
{
  switch(number)
  {
  case 0:       return '0';       break;
  case 1:       return '1';       break;
  case 2:       return '2';       break;
  case 3:       return '3';       break;
  case 4:       return '4';       break;
  case 5:       return '5';       break;
  case 6:       return '6';       break;
  case 7:       return '7';       break;
  case 8:       return '8';       break;
  case 9:       return '9';       break;
  }
}


/**
 * @file		��������������λ����ʾ
 * @note      	        �����ַ���
 * @date		2018
 */
void return_parameter(int16 parameter)
{
  int8 kilobit;
  int8 hundreds;
  int8 tens;
  int8 ones;
  
  kilobit  = (parameter/1000)%10;
  char_return[0] = return_char(kilobit);
  
  hundreds = (parameter/100)%10;
  char_return[1] = return_char(hundreds);
  
  tens     = (parameter/10)%10;
  char_return[2] = return_char(tens);
  
  ones     = parameter%10;
  char_return[3] = return_char(ones);
  
  char_return[4] = ' ';
  char_return[5] = ' ';
  char_return[6] = '\0';
  char_return[7] = '\0';

  char_return[8] = '\0';
  
}












