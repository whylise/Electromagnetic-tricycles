#ifndef bluetooth_h
#define bluetooth_h


/**********ȫ�ֱ����ⲿ����********/
extern int16 change_dirControl_P;
extern int16 change_dirControl_D;

extern int16 change_C_dirControl_P;
extern int16 change_C_dirControl_D;

extern int16 change_ExpectSpeed;

extern int16 change_speedControl_P;
extern int16 change_speedControl_I;

extern char char_return[9];

extern uint8 Flag_show_computer;


/***********��������***********/
void Bluethooth_Control();
void return_parameter(int16 parameter);

#endif