#include "define_all.h"  

unsigned char TimeCount;

unsigned char MS_50_FLAG;
unsigned char MS_100_FLAG;
unsigned char MS_300_FLAG;
unsigned char MS_500_FLAG;
unsigned char SECOND__FLAG;

unsigned char Run_LED_Process;	//ִ��ˢ��LED����
unsigned char Run_Display_Process; 
unsigned char Run_Key_Process;
unsigned char Run_ADC_Process;

BTIM_InitTypeDef adjustment_para;	//�������ڱ���

void BTIMER_DEMO_OUT_GPIO_init(void)//���GPIO��ʼ��
{
	RCC_PERCLK_SetableEx( PDCCLK, 		ENABLE );		//IO����ʱ�ӼĴ���ʹ��
	AltFunIO(GPIOB, GPIO_Pin_6, 0);//PB6���������⹦�ܿڣ���ͨ
}

void BTIMER_PWM_DEMO_init(void)//BTIMER��PWM���ʾ������
{
	//BTIM_InitTypeDef init_para;//btimer��ʼ���ṹ��

	//ʹ��BTIMER������ʱ��
	RCC_PERCLK_SetableEx( BT1CLK, 		ENABLE );		//BT1ʱ��ʹ��
	BTIMER_DEMO_OUT_GPIO_init();

/*
	init_para.sig_src_para.CNTSRC = BTIMx_BTCR2_SIG2SEL_GROUP1;//����Դѡ��GROUP_1
	init_para.sig_src_para.CAPSRC = BTIMx_BTCR2_SIG1SEL_GROUP2;//��׽Դѡ��GROUP_2
	
	init_para.sig_src_para.GRP1SEL = BTIMx_BTCFG1_GRP1SEL_APBCLK;//GROUP_1ѡ��APBCLK
	init_para.sig_src_para.GRP2SEL = BTIMx_BTCFG1_GRP2SEL_APBCLK;//GROUP_2ѡ��APBCLK


	init_para.sig_src_para.CNTHSEL = BTIMx_BTCR2_CNTHSEL_CNTL;//���16λ������
	init_para.sig_src_para.SRCSEL = BTIMx_BTCR2_SRCSEL_WITHOUT_DIR;//��λ��������ʹ��

	init_para.ctrl_para.PRESCALE = 7;//8��Ƶ��8M->1M

	init_para.ctrl_para.PRESETL = 0;//��λ������Ԥ����
	init_para.ctrl_para.PRESETH = 0;//��λ������Ԥ����

	init_para.ctrl_para.LOADL = 0xFF;//��λ�Ƚ�ֵ���ؼĴ���	//Ĭ��3F
	init_para.ctrl_para.LOADH = 0;
	*/

	adjustment_para.sig_src_para.CNTSRC = BTIMx_BTCR2_SIG2SEL_GROUP1;//����Դѡ��GROUP_1
	adjustment_para.sig_src_para.CAPSRC = BTIMx_BTCR2_SIG1SEL_GROUP2;//��׽Դѡ��GROUP_2
	
	adjustment_para.sig_src_para.GRP1SEL = BTIMx_BTCFG1_GRP1SEL_APBCLK;//GROUP_1ѡ��APBCLK
	adjustment_para.sig_src_para.GRP2SEL = BTIMx_BTCFG1_GRP2SEL_APBCLK;//GROUP_2ѡ��APBCLK


	adjustment_para.sig_src_para.CNTHSEL = BTIMx_BTCR2_CNTHSEL_CNTL;//���16λ������
	adjustment_para.sig_src_para.SRCSEL = BTIMx_BTCR2_SRCSEL_WITHOUT_DIR;//��λ��������ʹ��

	adjustment_para.ctrl_para.PRESCALE = 7;//8��Ƶ��8M->1M

	adjustment_para.ctrl_para.PRESETL = 0x0;
	adjustment_para.ctrl_para.PRESETH = 0x0;

	adjustment_para.ctrl_para.LOADL = 0xFF;
	adjustment_para.ctrl_para.LOADH = 0x0;
/*	
	init_para.ctrl_para.MODE = BTIMx_BTCR1_MODE_8BITS_TIM_CNT;//modeѡ��8BIT��ʱ����ģʽ
	init_para.ctrl_para.EDGESEL = BTIMx_BTCR1_EDGESEL_POS;//��֧��ϵͳʱ�ӵ��½��ؼ���

	init_para.sig_src_para.RTCSEL1 = BTIMx_BTCFG1_RTCSEL1_RTC_32768;
	init_para.sig_src_para.RTCSEL2 = BTIMx_BTCFG1_RTCSEL2_RTC_32768;
	init_para.sig_src_para.INSEL1 = BTIMx_BTCFG2_INSEL1_UART_RX0;
	init_para.sig_src_para.INSEL2 = BTIMx_BTCFG2_INSEL2_UART_RX3;
	init_para.sig_src_para.EXSEL1 = BTIMx_BTCFG2_EXSEL1_BT_IN0;
	init_para.sig_src_para.EXSEL2 = BTIMx_BTCFG2_EXSEL2_BT_IN0;

	init_para.cap_para.CAPONCE = BTIMx_BTCR1_CAPONCE_SINGLE;
	init_para.cap_para.CAPMOD = BTIMx_BTCR1_CAPMOD_PAUSE_PERIOD;
	init_para.cap_para.CAPCLR = BTIMx_BTCR1_CAPCLR_CAP_CNT_CLR;

	init_para.dir_para.DIREN = DISABLE;
	init_para.dir_para.DIRPO = BTIMx_BTCR2_DIRPO_NO_ANTI;

	init_para.out_para.OUTCNT = 0;
	init_para.out_para.OUTCLR = BTIMx_BTOCR_OUTCLR_CLR;
	init_para.out_para.OUTINV = BTIMx_BTOCR_OUTINV_NOT_ANTI;
	init_para.out_para.OUTMOD = BTIMx_BTOCR_OUTMOD_PULSE;
	init_para.out_para.OUTSEL = BTIMx_BTOCR_OUTSEL_PWM;
	
	BTIMx_Init(BTIM1, &init_para);//��ʼ��btimer
*/
	adjustment_para.ctrl_para.MODE = BTIMx_BTCR1_MODE_8BITS_TIM_CNT;//modeѡ��8BIT��ʱ����ģʽ
	adjustment_para.ctrl_para.EDGESEL = BTIMx_BTCR1_EDGESEL_POS;//��֧��ϵͳʱ�ӵ��½��ؼ���

	adjustment_para.sig_src_para.RTCSEL1 = BTIMx_BTCFG1_RTCSEL1_RTC_32768;
	adjustment_para.sig_src_para.RTCSEL2 = BTIMx_BTCFG1_RTCSEL2_RTC_32768;
	adjustment_para.sig_src_para.INSEL1 = BTIMx_BTCFG2_INSEL1_UART_RX0;
	adjustment_para.sig_src_para.INSEL2 = BTIMx_BTCFG2_INSEL2_UART_RX3;
	adjustment_para.sig_src_para.EXSEL1 = BTIMx_BTCFG2_EXSEL1_BT_IN0;
	adjustment_para.sig_src_para.EXSEL2 = BTIMx_BTCFG2_EXSEL2_BT_IN0;

	adjustment_para.cap_para.CAPONCE = BTIMx_BTCR1_CAPONCE_SINGLE;
	adjustment_para.cap_para.CAPMOD = BTIMx_BTCR1_CAPMOD_PAUSE_PERIOD;
	adjustment_para.cap_para.CAPCLR = BTIMx_BTCR1_CAPCLR_CAP_CNT_CLR;

	adjustment_para.dir_para.DIREN = DISABLE;
	adjustment_para.dir_para.DIRPO = BTIMx_BTCR2_DIRPO_NO_ANTI;

	adjustment_para.out_para.OUTCNT = 0;
	adjustment_para.out_para.OUTCLR = BTIMx_BTOCR_OUTCLR_CLR;
	adjustment_para.out_para.OUTINV = BTIMx_BTOCR_OUTINV_NOT_ANTI;
	adjustment_para.out_para.OUTMOD = BTIMx_BTOCR_OUTMOD_PULSE;
	adjustment_para.out_para.OUTSEL = BTIMx_BTOCR_OUTSEL_PWM;
	
	BTIMx_Init(BTIM1, &adjustment_para);//��ʼ��btimer

}

void BTIMER_PWM_DEMO_stop(void)////DEMO�ر�
{
	BTIMx_BTCR1_PWM_Setable(BTIM1, DISABLE);
	BTIMx_BTCR1_CHEN_Setable(BTIM1, DISABLE);//ʹ�ܼ�����
	BTIMx_BTCR1_CLEN_Setable(BTIM1, DISABLE);//ʹ�ܼ�����
}

void BTIMER_PWM_DEMO_start(void)////DEMO����
{
	BTIMx_BTCR1_PWM_Setable(BTIM1, ENABLE);
	BTIMx_BTCR1_CHEN_Setable(BTIM1, ENABLE);//ʹ�ܼ�����
	BTIMx_BTCR1_CLEN_Setable(BTIM1, ENABLE);//ʹ�ܼ�����
}

void Test_Etimx(ETIMx_Type* ETIMx)
{
	ETIM_InitTypeDef init_para;
	volatile uint08 EtimNum;

	EtimNum = ((uint32_t)ETIMx - ETIMER1_BASE)>>5;
	

	//�ź�Դ����
	init_para.sig_src_para.SIG1SEL = ETIMx_ETxINSEL_SIG1SEL_GROUP1;		/* �ڲ��ź�1Դѡ��GROUP1 */
	init_para.sig_src_para.SIG2SEL = ETIMx_ETxINSEL_SIG2SEL_GROUP1;		/* �ڲ��ź�2Դѡ��GROUP1 */
	
	switch(EtimNum)
	{
		case 0:
			//�ź�Դ����
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET1_APBCLK;		/* GROUP1 �ź�ѡ��APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF;		/* GROUP2 �ź�ѡ��XTLF */			
			//ET1ʱ��ʹ��	
			RCC_PERCLK_SetableEx( ET1CLK, ENABLE );		
			//NVIC�ж�����
			NVIC_DisableIRQ(ETIM1_IRQn);
			NVIC_SetPriority(ETIM1_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(ETIM1_IRQn);		
			break;

		case 1:
			//�ź�Դ����
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET2_APBCLK;		/* GROUP1 �ź�ѡ��APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET2_XTLF;		/* GROUP2 �ź�ѡ��XTLF */		
			//ET2ʱ��ʹ��	
			RCC_PERCLK_SetableEx( ET2CLK, ENABLE );	
			//NVIC�ж�����
			NVIC_DisableIRQ(ETIM2_IRQn);
			NVIC_SetPriority(ETIM2_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(ETIM2_IRQn);			
			break;

		case 2:
			//�ź�Դ����
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET3_APBCLK;		/* GROUP1 �ź�ѡ��APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET3_XTLF;		/* GROUP2 �ź�ѡ��XTLF */		
			//ET3ʱ��ʹ��
			RCC_PERCLK_SetableEx( ET3CLK, ENABLE );	
			//NVIC�ж�����
			NVIC_DisableIRQ(ETIM3_IRQn);
			NVIC_SetPriority(ETIM3_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(ETIM3_IRQn);			
			break;

		case 3:
			//�ź�Դ����
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET4_APBCLK;		/* GROUP1 �ź�ѡ��APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET4_XTLF;		/* GROUP2 �ź�ѡ��XTLF */		
			//ET4ʱ��ʹ��
			RCC_PERCLK_SetableEx( ET4CLK, ENABLE );		
			//NVIC�ж�����
			NVIC_DisableIRQ(ETIM4_IRQn);
			NVIC_SetPriority(ETIM4_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(ETIM4_IRQn);	
			break;
		
		default:
			break;
	}
	init_para.sig_src_para.PRESCALE1 = clkmode - 1 + 99;    //100��Ƶ	/* ETxԤ��Ƶ�Ĵ���1 */ 00��ʾ1��Ƶ��FF��ʾ256��Ƶ
	init_para.sig_src_para.PRESCALE2 = clkmode - 1;    		//1��Ƶ		/* ETxԤ��Ƶ�Ĵ���2 */ 00��ʾ1��Ƶ��FF��ʾ256��Ƶ
	
	
	//���������
	init_para.ctrl_para.EXFLT = ENABLE;								/* �������������˲�ʹ�ܴ� */
	init_para.ctrl_para.MOD = ETIMx_ETxCR_MOD_COUNTER;				/* ����ģʽѡ�����ģʽ */
	init_para.ctrl_para.CASEN = DISABLE;							/* ��չ��ʱ�������ر� */
	init_para.ctrl_para.EDGESEL = ETIMx_ETxCR_EDGESEL_RISING;		/* ����ģʽ���ط�ʽѡ�񣨼���ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ����� */

	init_para.ctrl_para.PWM = DISABLE;								/* PWM����ر� */

	init_para.ctrl_para.CAPMOD = ETIMx_ETxCR_CAPMOD_PERIOD;			/* ��׽ģʽ���� */
	init_para.ctrl_para.CAPCLR = DISABLE;							/* �����㲶׽ģʽ���� */
	init_para.ctrl_para.CAPONCE = DISABLE;							/* ���β�׽���� */
	init_para.ctrl_para.CAPEDGE = ETIMx_ETxCR_CAPEDGE_RISING;		/* ��׽��ѡ�� */

	init_para.ctrl_para.CMPIE = DISABLE;		/* ��չ��ʱ���Ƚ��ж�ʹ�� */
	init_para.ctrl_para.CAPIE = DISABLE;		/* ��չ��ʱ����׽�ж�ʹ�� */
	init_para.ctrl_para.OVIE = ENABLE;			/* ��չ��ʱ������ж�ʹ�� */

	init_para.ctrl_para.INITVALUE = 0xffff - 800; //������ֵ��8000000��100��Ƶ ���� 8000������ = 100ms ;		/* ETx��ֵ�Ĵ��� */
	init_para.ctrl_para.CMP = 0;			/* ETx�ȽϼĴ��� */
	
	init_para.ctrl_para.CEN = DISABLE;		/* �������� */
	
	//��ʼ��ETIM
	ETIMx_Init(ETIMx, &init_para);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//������ʱ��
}

Run_LED(void)
{
	if(Run_LED_Process == 1)
	{
		//GPIO_ToggleBits(GPIOA,GPIO_Pin_3);
		LED1_TOG;	
		Run_LED_Process = 0;
	}
	//LED0_Flash(5);		//̫����Դ    ��Ҫ�ö�ʱ����
}

void Test_GPIO_InPut(void)
{
	RCC_PERCLK_SetableEx( PDCCLK, 		ENABLE );		//IO����ʱ�ӼĴ���ʹ��

	InputtIO( GPIOA, GPIO_Pin_12, IN_NORMAL);		//PA12; //KEY  DOWN      KEY1
	InputtIO( GPIOA, GPIO_Pin_13, IN_NORMAL);		//PA13; //KEY  UP          KEY0
}

Run_KEY(void)
{
	unsigned char keyup_press,keydown_press;
	if(Run_Key_Process == 1)
	{
		if(KEY0_N)
		{
			TicksDelayMs( 10, NULL );//�����ʱȥ��
			if(KEY0_N)
			{
				/*
				if((adjustment_para.ctrl_para.LOADL<=0xFF) &&(adjustment_para.ctrl_para.LOADL>5))
				{
					adjustment_para.ctrl_para.LOADL=adjustment_para.ctrl_para.LOADL - 5;
					//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);
					//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//��λ����ֵ
					//BTIMx_BTPRESET_PRESETH_Set(BTIM1, adjustment_para->ctrl_para.PRESETH);//
					//BTIMx_BTPRESET_PRESETL_Set(BTIM1, adjustment_para->ctrl_para.PRESETL);//
					//BTIMx_BTOUTCNT_Write(BTIM1, adjustment_para->out_para.OUTCNT);
					//BTIMx_BTCMPL_Write(BTIM1, adjustment_para->ctrl_para.CMPL);
					BTIMx_Init(BTIM1, &adjustment_para);
				}
				//BTIMER_PWM_DEMO_stop();
				//BTIMER_PWM_DEMO_start();
				LED0_ON;*/

				//keyup_press =1;
				if(KEY0_N&&(Disp_page<8))Disp_page++;
			}
		}
		
		if(KEY0_P)
		{
			TicksDelayMs( 5, NULL );//�����ʱȥ��
			if(KEY0_P)
			{
				//BTIMER_PWM_DEMO_start();
				//LED0_OFF;
				if((keyup_press==1)&&(Disp_page<8))
				{
					Disp_page++;	//����ʱ����
					keyup_press = 0;		//�������¹�
				}
				
			}
		}

		if(KEY1_N)
		{
			TicksDelayMs( 10, NULL );//�����ʱȥ��
			if(KEY1_N)
			{	/*
				if((adjustment_para.ctrl_para.LOADL<0xFA) &&(adjustment_para.ctrl_para.LOADL>=1))
				{
					adjustment_para.ctrl_para.LOADL=adjustment_para.ctrl_para.LOADL + 5;
					//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);
					//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//��λ����ֵ
					//BTIMx_BTPRESET_PRESETH_Set(BTIM1, adjustment_para->ctrl_para.PRESETH);//
					//BTIMx_BTPRESET_PRESETL_Set(BTIM1, adjustment_para->ctrl_para.PRESETL);//
					BTIMx_Init(BTIM1, &adjustment_para);
				}
				//BTIMER_PWM_DEMO_stop();
				//BTIMER_PWM_DEMO_start();
				LED1_ON;*/

				//keydown_press = 1;
				if(KEY1_N&&(Disp_page>0))Disp_page--;
			}
		}
		
		if(KEY1_P)
		{
			TicksDelayMs( 5, NULL );//�����ʱȥ��
			if(KEY1_P)
			{
				//BTIMER_PWM_DEMO_start();
				//LED1_OFF;
				if((keydown_press==1)&&(Disp_page>6))
				{
					Disp_page--;	//����ʱ����
					keydown_press =0;		//�������¹�
				}
			}
		}

		
		Run_Key_Process = 0;
	}	
}

void Run_DISPLAY(void)
{
	if(Run_Display_Process == 1)
	{
		Lcd_Display();   //ˢ����ʾ
		Run_Display_Process = 0;
	}
}

void Run_ADC(void)
{
	unsigned long SetTemperature_back;
	if(Run_ADC_Process == 1)
	{
		SetTemperature_back = SetTemperature;		//��������ݱ��ں������ݱȶ�
		
		Temperature = Test_ADC_Temperature();   //ˢ����ʾ
		SetTemperature = Test_ADC_ExVolt();
		SetTemperature = SetTemperature/7+200;  //ʵ���趨�¶�ֵ
		IronTemperature = Test_ADC_ExVolt2();
		IronTemperature = IronTemperature*10/0.5/100;  //ʵ�ʲ����¶�ֵ
		
		if((SetTemperature<SetTemperature_back-2)||(SetTemperature>SetTemperature_back+2))
		{
			//��λ�������˱䶯���������¶�����
			//��ʾ�¶ȵ���ֵ
			Disp_page = 7;
			SetTemperature_Count = 10;		//���õ���ʱ
		}

		//�����趨 --  ��ʼ�¶ȣ��ϵ���ȡ
		if(IronTemperature<SetTemperature-20)		//����ֵ   
		{
			//ֱ����PWM���µ��޶�ֵ      �趨350�� - ������320
			adjustment_para.ctrl_para.LOADL = 0;
			BTIMx_Init(BTIM1, &adjustment_para);
			BTIMER_PWM_DEMO_start();
			LED0_ON;
		}
		else if(IronTemperature>SetTemperature+5)	 
		{
			//ֱ�ӿ�PWM���н���
			adjustment_para.ctrl_para.LOADL = 0xff;
			BTIMx_Init(BTIM1, &adjustment_para);
			BTIMER_PWM_DEMO_start();
			LED0_OFF;
		}
		else if((IronTemperature<SetTemperature+20)||(IronTemperature>SetTemperature-20))
		{
			//����PWMֵ   --  ��ʽ
			adjustment_para.ctrl_para.LOADL = 0xFF - (SetTemperature + 20) / 3.3;
			BTIMx_Init(BTIM1, &adjustment_para);
			BTIMER_PWM_DEMO_start();	
			LED0_OFF;
		}
		Run_ADC_Process = 0;
	}
}

int main (void)
{	
	//uint32_t adjustment_para2;
	Init_System();				//ϵͳ��ʼ�� 
 
	BTIMER_PWM_DEMO_init();	//PWM��ʱ����ʼ��
	BTIMER_PWM_DEMO_start();	//PWM�����ʼ
	Test_Etimx(ETIM1);	//������ʱ��1
	Test_GPIO_InPut();	//��������

	//ADC�ⲿ����ͨ������
	Test_ADC_ExVolt();
	
	//ADC�¶ȴ�����ͨ������
	Test_ADC_Temperature();

	initLCDM();
	memset( LCM_DDRAM, 0x00, 1600 );    //����ʾ������
	LCD_Fulldisplay();		//Һ��ȫ����ʾ
	LCD_on();

	Display.Number=0xff;		//����Ĭ����ʾҳ��
	
	current_val_pointer=&disptemp_val;  
	//hextohex_flag = true;
	asc16_flag = true;
	hextohex_flag = fault;
	//show_asc36(1,16,1,0);
	//dis_asc36(1);

	Disp_page = 8;
	
	for( ; ; )
	{
		//BTIMx_BTPRESET_PRESETH_Set(BTIM1, adjustment_para->ctrl_para.PRESETH);//
		//BTIMx_BTPRESET_PRESETL_Set(BTIM1, adjustment_para->ctrl_para.PRESETL);//
		
		//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);//��λ����ֵ
		//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//��λ����ֵ
		//BTIMx_BTOCR_OUTMOD_Set(BTIM1, adjustment_para->out_para.OUTMOD);//���ģʽѡ��
		//BTIMx_BTOCR_OUTSEL_Set(BTIM1, adjustment_para->out_para.OUTSEL);//����ź�ѡ��
		//BTIMx_BTOUTCNT_Write(BTIM1, adjustment_para->out_para.OUTCNT);//�������������
		//BTIMx_BTOCR_OUTINV_Set(BTIM1, adjustment_para->out_para.OUTINV);//�����ƽ����ѡ��
		Run_LED();
		Run_KEY();
		Run_DISPLAY();
		Run_ADC();
		IWDT_Clr();		//��ϵͳ���Ź�
		//TicksDelayMs( 50, NULL );		//�����ʱ	
	}	
}


