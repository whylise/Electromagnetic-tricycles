/*********************************************************************************************************************
 * 
 * @file       		direction.c
 *  				�������
 * @core			S9KEA128
 * @date       		2018
 ********************************************************************************************************************/
#include  "include_file.h"
extern int32 g_fSpeed_ControlOut;
extern uint16 Gears;

/**********ȫ�ֱ�������********/ 
float g_fDirection_Error[2];		//����ƫ�g_fDirectionError[0]Ϊһ��ˮƽ��еĲ�Ⱥ�ƫ�
								//		         ��g_fDirectionError[1]Ϊһ�Դ�ֱ��еĲ�Ⱥ�ƫ�
float g_fDirection_Error_dot[2];         //����ƫ��΢�֣�g_fDirectionError_dot[0]Ϊһ��ˮƽ��еĲ�Ⱥ�ƫ��΢�֣�
								//			 ��g_fDirectionError_dot[1]Ϊһ�Դ�ֱ��еĲ�Ⱥ�ƫ��΢�֣�
int32 g_fDirection_ControlOut = 1.0;	        //����������
long double g_fDirection_ControlOut_Date = 1.0;

int16 g_ValueOfAD[5]={0};		//��ȡ�ĵ��ֵ
int16 g_ValueOfADFilter[5]={0};	        //�����˲��ĵ��ֵ


long double Dir_error_Value =1.0;
int32 g_fDirection_ControlOutNew = 1.0;
int32 g_fDirection_ControlOutOld = 1.0;      

 uint16 TIME_ROUND = 0;
 uint16 Left_Round = 0;
 uint16 Right_Round = 0;
 uint16 Round = 0;
//static uint16 LEFTROUND =  0;



/*********************************************
 * @file		����źŲɼ��ʹ���
 * @note      	
 * @date		2018
 ********************************************/
void ADC_Get(void)
{
  int16  i,j,k,temp;
  int16  ad_valu[5][5],ad_valu1[5],ad_sum[5];
  int16 ValueOfADOld[5],ValueOfADNew[5];

  for(i=0;i<5;i++)
  {
    ad_valu[0][i]=ad_ave(AD1, ADC_12bit, 5);  			// AD1ˮƽ��
    ad_valu[1][i]=ad_ave(AD2, ADC_12bit, 5);     		// AD2ˮƽ��
    ad_valu[2][i]=ad_ave(AD3, ADC_12bit, 5);  			// AD3��ֱ��
    ad_valu[3][i]=ad_ave(AD4, ADC_12bit, 5);     		// AD4��ֱ��
    ad_valu[4][i]=ad_ave(AD5, ADC_12bit, 5);     		// AD5ˮƽ�м�
  }
  
/*=========================ð����������==========================*///�������ֵ����Сֵ
  for(i=0;i<5;i++)
  {
    for(j=0;j<4;j++)
    {
      for(k=0;k<4-j;k++)
      {
        if(ad_valu[i][k] > ad_valu[i][k+1])        //ǰ��ıȺ���Ĵ�  ����н���
        {
          temp = ad_valu[i][k+1];
          ad_valu[i][k+1] = ad_valu[i][k];
          ad_valu[i][k] = temp;
        }
      }
    }
  }
  
/*===========================��ֵ�˲�=================================*/
  for(i=0;i<5;i++)   
  {
    ad_sum[i] = ad_valu[i][1] + ad_valu[i][2] + ad_valu[i][3];
    ad_valu1[i] = ad_sum[i] / 3;
  }

	
  for(i=0;i<5;i++)         
  {
    g_ValueOfAD[i] = (int16)(ad_valu1[i]/10*10);

    ValueOfADOld[i] = g_ValueOfADFilter[i];
    ValueOfADNew[i] = g_ValueOfAD[i];
		
    if(ValueOfADNew[i]>=ValueOfADOld[i])
      g_ValueOfADFilter[i] = ((ValueOfADNew[i]-ValueOfADOld[i])>50?(ValueOfADOld[i]+50):ValueOfADNew[i]);
    else
      g_ValueOfADFilter[i] = ((ValueOfADNew[i]-ValueOfADOld[i])<-60?(ValueOfADOld[i]-60):ValueOfADNew[i]);
  }  
  
}



void Direction_Control(void)
{
  static float g_fDirection_ErrorTemp[2][4];
  
  ADC_Get();                                                    //��ȡ���ֵ
  
  if(g_ValueOfAD[0]<50 && g_ValueOfAD[1]<50)	Flag_Stop = ON;	//�������ͣ������

  g_ValueOfAD[0] = (g_ValueOfAD[0] < 20? 20:g_ValueOfAD[0]);	//�ĸ����ֵ�޷�
  g_ValueOfAD[1] = (g_ValueOfAD[1] < 20? 20:g_ValueOfAD[1]);
  g_ValueOfAD[2] = (g_ValueOfAD[2] < 20? 20:g_ValueOfAD[2]);
  g_ValueOfAD[3] = (g_ValueOfAD[3] < 20? 20:g_ValueOfAD[3]);
  g_ValueOfAD[4] = (g_ValueOfAD[4] < 20? 20:g_ValueOfAD[4]);
  
  
  
  g_fDirection_Error[0] = (float)(g_ValueOfAD[0] - g_ValueOfAD[1])/(g_ValueOfAD[0] + g_ValueOfAD[1]);//��Ⱥ���Ϊƫ��
  g_fDirection_Error[0] = (g_fDirection_Error[0]>= 1? 1:g_fDirection_Error[0]);	
  g_fDirection_Error[0] = (g_fDirection_Error[0]<=-1?-1:g_fDirection_Error[0]);
  
  g_fDirection_Error[1] = (float)(g_ValueOfAD[2] - g_ValueOfAD[3])/(g_ValueOfAD[2] + g_ValueOfAD[3]);//��Ⱥ���Ϊƫ��
  g_fDirection_Error[1] = (g_fDirection_Error[1]>= 1? 1:g_fDirection_Error[1]);	
  g_fDirection_Error[1] = (g_fDirection_Error[1]<=-1?-1:g_fDirection_Error[1]);
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  g_fDirection_ErrorTemp[0][3] = g_fDirection_ErrorTemp[0][2];
  g_fDirection_ErrorTemp[0][2] = g_fDirection_ErrorTemp[0][1];
  g_fDirection_ErrorTemp[0][1] = g_fDirection_ErrorTemp[0][0];
  g_fDirection_ErrorTemp[0][0] = g_fDirection_Error[0];
  g_fDirection_Error_dot[0] = 5*(g_fDirection_ErrorTemp[0][0]-g_fDirection_ErrorTemp[0][3]);
  g_fDirection_Error_dot[0] = (g_fDirection_Error_dot[0]> 0.7? 0.7:g_fDirection_Error_dot[0]);
  g_fDirection_Error_dot[0] = (g_fDirection_Error_dot[0]<-0.7?-0.7:g_fDirection_Error_dot[0]);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  g_fDirection_ErrorTemp[1][3] = g_fDirection_ErrorTemp[1][2];
  g_fDirection_ErrorTemp[1][2] = g_fDirection_ErrorTemp[1][1];
  g_fDirection_ErrorTemp[1][1] = g_fDirection_ErrorTemp[1][0];
  g_fDirection_ErrorTemp[1][0] = g_fDirection_Error[1];
  g_fDirection_Error_dot[1] = 5*(g_fDirection_ErrorTemp[1][0]-g_fDirection_ErrorTemp[1][3]);
  g_fDirection_Error_dot[1] = (g_fDirection_Error_dot[1]> 0.7? 0.7:g_fDirection_Error_dot[1]);
  g_fDirection_Error_dot[1] = (g_fDirection_Error_dot[1]<-0.7?-0.7:g_fDirection_Error_dot[1]);


//     if((g_ValueOfAD[2]>3680)&&(g_ValueOfAD[3]>3680)  &&(TIME_ROUND>0) ) 
//          {
//             TIME_ROUND = 0;
//
//          }
    if((g_ValueOfAD[4]>=3700)&&(TIME_ROUND == 0))  //((g_ValueOfAD[2]>600)||(g_ValueOfAD[3]>600))&&
	{
		 Flag_Round = ON;       
	          gpio_set(BUZZ,1);
                 TIME_ROUND = 1;  
                
	 }       
        
//        if((Flag_Round == ON)&&((g_ValueOfAD[2]-g_ValueOfAD[3])>800))
//          Left_Round == ON;
//        
//         if((Flag_Round == ON)&&((g_ValueOfAD[3]-g_ValueOfAD[2])>800))
//          Right_Round == ON; 
  
         if(TIME_ROUND == 2)
         {
              Flag_Round = OFF;
              gpio_set(BUZZ,0);
       
         }

 
        
       //�����㷨��λ��ʽPD��
        
       // g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.8 +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.42);  //+(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.25
        
        if(Gears == 1)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D) +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.10);  //1800
        if(Gears == 2)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D) +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.12);  //2000
        if(Gears == 3)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D) +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.15);  //2200
        if(Gears == 4)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D) +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.18);  //2300
        if(Gears == 5)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.9 +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.26);  //2400
        if(Gears == 6)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.89 +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.39);  //2500
        if(Gears == 7)
                 g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.89 +(g_fDirection_Error[1]*g_dirControl_P + g_fDirection_Error_dot[1]*g_dirControl_D)*0.46);  //2400
       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        if(Flag_Round == ON)               //////2000
//          g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.15); //+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.1
       
        if((Flag_Round == ON)&&(Gears == 1))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.12);     ///1800
        if((Flag_Round == ON)&&(Gears == 2))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.14);     //2000
        if((Flag_Round == ON)&&(Gears == 3))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.15);    //2200
        if((Flag_Round == ON)&&(Gears == 4))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.16);    //2300
        if((Flag_Round == ON)&&(Gears == 5))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.17);    //2400
        if((Flag_Round == ON)&&(Gears == 6))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.18);    //2500
        if((Flag_Round == ON)&&(Gears == 7))
           g_fDirection_ControlOut_Date = (int32)((g_fDirection_Error[1]*g_dir_C_Control_P + g_fDirection_Error_dot[1]*g_dir_C_Control_D)+(g_fDirection_Error[0]*g_dirControl_P + g_fDirection_Error_dot[0]*g_dirControl_D)*0.20);   //2600
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           
        
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
        if(g_fDirection_ControlOut_Date < 0)     
                 g_fDirection_ControlOutNew = -(int32)(g_fDirection_ControlOut_Date * g_fDirection_ControlOut_Date);      
        
        if(g_fDirection_ControlOut_Date >= 0)     
                 g_fDirection_ControlOutNew = (int32)(g_fDirection_ControlOut_Date * g_fDirection_ControlOut_Date);
        
// //********************������ƽ����� ***********  

	g_fDirection_ControlOutOld = g_fDirection_ControlOutNew;
        Dir_error_Value = g_fDirection_ControlOutNew - g_fDirection_ControlOutOld;
        g_fDirection_ControlOut  = (int32)(Dir_error_Value  + g_fDirection_ControlOutOld);

      
         
}










