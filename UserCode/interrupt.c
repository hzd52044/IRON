#include "define_all.h" 


//�������� �жϺ�����ʹ��ȫ�ֱ���  
void ETIM1_IRQHandler(void)
{	
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM1))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM1);
		TimeCount++;	//10ms  
		MS_50_FLAG++;
		MS_100_FLAG++;
		MS_300_FLAG++;
		MS_500_FLAG++;
		SECOND__FLAG++;
		if(MS_50_FLAG >= 5)
		{
			Run_Key_Process = 1;
			MS_50_FLAG = 0;
		}

		if(MS_100_FLAG >= 10)
		{
			Run_Display_Process = 1;
			MS_100_FLAG = 0;
		}

		if(MS_300_FLAG >= 30)
		{
			Run_ADC_Process = 1;
			MS_300_FLAG = 0;
		}

		if(MS_500_FLAG >= 50)
		{
			Run_LED_Process = 1;
			MS_500_FLAG = 0;
		}

		if(SECOND__FLAG >= 100)
		{
			//Run_LED_Process = 1;
			SECOND__FLAG = 0;
		}

		if(TimeCount == 10) TimeCount =0;
		
	}
}


//��ʱʱ��4000us,
void ETIM2_IRQHandler(void)
{
	//unsigned char Ch;
	//unsigned int i;

	ETIM2->ETxIF = 0x03;//���жϱ�־
	
	#if 0
	if( VectorTimer == 0 ) VectorTimer  = ms_timer_delay;
	if( VectorTimer == 1 ) run_readrtc_flag = 1;	//�����ʱ��
	if( (VectorTimer == 50) || (((VectorTimer == 20)||(VectorTimer == 80))&&display_rtc_flag) ) {run_display_flag = 1;	disp_sleep_flag = 0;}//����ˢ����ʾ
	if( VectorTimer == 100 )
	{
		run_relaychk_flag = 1;	//����̵������
		RELAYCTRLON;		//�򿪿��Ƶ�ƽ
		Clear_W_Wdt();	//�崰�ڿ��Ź�
	}
	VectorTimer--;
	
	DisKeySamp<<=1;
	if(DISKEY_N)  DisKeySamp++;	//��ʾ����ȥ���ж�

	#endif 
	
	//ADC����
}
