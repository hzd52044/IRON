#include "define_all.h"  




int main (void)
{	
	Init_System();				//系统初始化
	
	for( ; ; )
    {
		IWDT_Clr();             //清系统看门狗	
		
        LED0_TOG;	            //LED0闪烁
		TicksDelayMs( 50, NULL );//软件延时
    }
}
