#include "define_all.h"  




int main (void)
{	
	Init_System();				//ϵͳ��ʼ��
	
	for( ; ; )
    {
		IWDT_Clr();             //��ϵͳ���Ź�	
		
        LED0_TOG;	            //LED0��˸
		TicksDelayMs( 50, NULL );//�����ʱ
    }
}
