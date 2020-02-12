#include "define_all.h"  

unsigned char TimeCount;

unsigned char MS_50_FLAG;
unsigned char MS_100_FLAG;
unsigned char MS_300_FLAG;
unsigned char MS_500_FLAG;
unsigned char SECOND__FLAG;

unsigned char Run_LED_Process;	//执行刷新LED任务
unsigned char Run_Display_Process; 
unsigned char Run_Key_Process;
unsigned char Run_ADC_Process;

BTIM_InitTypeDef adjustment_para;	//参数调节变量

void BTIMER_DEMO_OUT_GPIO_init(void)//输出GPIO初始化
{
	RCC_PERCLK_SetableEx( PDCCLK, 		ENABLE );		//IO控制时钟寄存器使能
	AltFunIO(GPIOB, GPIO_Pin_6, 0);//PB6，数字特殊功能口，普通
}

void BTIMER_PWM_DEMO_init(void)//BTIMER的PWM输出示例程序
{
	//BTIM_InitTypeDef init_para;//btimer初始化结构体

	//使能BTIMER的外设时钟
	RCC_PERCLK_SetableEx( BT1CLK, 		ENABLE );		//BT1时钟使能
	BTIMER_DEMO_OUT_GPIO_init();

/*
	init_para.sig_src_para.CNTSRC = BTIMx_BTCR2_SIG2SEL_GROUP1;//计数源选择GROUP_1
	init_para.sig_src_para.CAPSRC = BTIMx_BTCR2_SIG1SEL_GROUP2;//捕捉源选择GROUP_2
	
	init_para.sig_src_para.GRP1SEL = BTIMx_BTCFG1_GRP1SEL_APBCLK;//GROUP_1选择APBCLK
	init_para.sig_src_para.GRP2SEL = BTIMx_BTCFG1_GRP2SEL_APBCLK;//GROUP_2选择APBCLK


	init_para.sig_src_para.CNTHSEL = BTIMx_BTCR2_CNTHSEL_CNTL;//组成16位计数器
	init_para.sig_src_para.SRCSEL = BTIMx_BTCR2_SRCSEL_WITHOUT_DIR;//低位计数器常使能

	init_para.ctrl_para.PRESCALE = 7;//8分频，8M->1M

	init_para.ctrl_para.PRESETL = 0;//低位计数器预置数
	init_para.ctrl_para.PRESETH = 0;//高位计数器预置数

	init_para.ctrl_para.LOADL = 0xFF;//低位比较值加载寄存器	//默认3F
	init_para.ctrl_para.LOADH = 0;
	*/

	adjustment_para.sig_src_para.CNTSRC = BTIMx_BTCR2_SIG2SEL_GROUP1;//计数源选择GROUP_1
	adjustment_para.sig_src_para.CAPSRC = BTIMx_BTCR2_SIG1SEL_GROUP2;//捕捉源选择GROUP_2
	
	adjustment_para.sig_src_para.GRP1SEL = BTIMx_BTCFG1_GRP1SEL_APBCLK;//GROUP_1选择APBCLK
	adjustment_para.sig_src_para.GRP2SEL = BTIMx_BTCFG1_GRP2SEL_APBCLK;//GROUP_2选择APBCLK


	adjustment_para.sig_src_para.CNTHSEL = BTIMx_BTCR2_CNTHSEL_CNTL;//组成16位计数器
	adjustment_para.sig_src_para.SRCSEL = BTIMx_BTCR2_SRCSEL_WITHOUT_DIR;//低位计数器常使能

	adjustment_para.ctrl_para.PRESCALE = 7;//8分频，8M->1M

	adjustment_para.ctrl_para.PRESETL = 0x0;
	adjustment_para.ctrl_para.PRESETH = 0x0;

	adjustment_para.ctrl_para.LOADL = 0xFF;
	adjustment_para.ctrl_para.LOADH = 0x0;
/*	
	init_para.ctrl_para.MODE = BTIMx_BTCR1_MODE_8BITS_TIM_CNT;//mode选择8BIT定时计数模式
	init_para.ctrl_para.EDGESEL = BTIMx_BTCR1_EDGESEL_POS;//不支持系统时钟的下降沿计数

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
	
	BTIMx_Init(BTIM1, &init_para);//初始化btimer
*/
	adjustment_para.ctrl_para.MODE = BTIMx_BTCR1_MODE_8BITS_TIM_CNT;//mode选择8BIT定时计数模式
	adjustment_para.ctrl_para.EDGESEL = BTIMx_BTCR1_EDGESEL_POS;//不支持系统时钟的下降沿计数

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
	
	BTIMx_Init(BTIM1, &adjustment_para);//初始化btimer

}

void BTIMER_PWM_DEMO_stop(void)////DEMO关闭
{
	BTIMx_BTCR1_PWM_Setable(BTIM1, DISABLE);
	BTIMx_BTCR1_CHEN_Setable(BTIM1, DISABLE);//使能计数器
	BTIMx_BTCR1_CLEN_Setable(BTIM1, DISABLE);//使能计数器
}

void BTIMER_PWM_DEMO_start(void)////DEMO启动
{
	BTIMx_BTCR1_PWM_Setable(BTIM1, ENABLE);
	BTIMx_BTCR1_CHEN_Setable(BTIM1, ENABLE);//使能计数器
	BTIMx_BTCR1_CLEN_Setable(BTIM1, ENABLE);//使能计数器
}

void Test_Etimx(ETIMx_Type* ETIMx)
{
	ETIM_InitTypeDef init_para;
	volatile uint08 EtimNum;

	EtimNum = ((uint32_t)ETIMx - ETIMER1_BASE)>>5;
	

	//信号源参数
	init_para.sig_src_para.SIG1SEL = ETIMx_ETxINSEL_SIG1SEL_GROUP1;		/* 内部信号1源选择GROUP1 */
	init_para.sig_src_para.SIG2SEL = ETIMx_ETxINSEL_SIG2SEL_GROUP1;		/* 内部信号2源选择GROUP1 */
	
	switch(EtimNum)
	{
		case 0:
			//信号源参数
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET1_APBCLK;		/* GROUP1 信号选择APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF;		/* GROUP2 信号选择XTLF */			
			//ET1时钟使能	
			RCC_PERCLK_SetableEx( ET1CLK, ENABLE );		
			//NVIC中断配置
			NVIC_DisableIRQ(ETIM1_IRQn);
			NVIC_SetPriority(ETIM1_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(ETIM1_IRQn);		
			break;

		case 1:
			//信号源参数
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET2_APBCLK;		/* GROUP1 信号选择APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET2_XTLF;		/* GROUP2 信号选择XTLF */		
			//ET2时钟使能	
			RCC_PERCLK_SetableEx( ET2CLK, ENABLE );	
			//NVIC中断配置
			NVIC_DisableIRQ(ETIM2_IRQn);
			NVIC_SetPriority(ETIM2_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(ETIM2_IRQn);			
			break;

		case 2:
			//信号源参数
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET3_APBCLK;		/* GROUP1 信号选择APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET3_XTLF;		/* GROUP2 信号选择XTLF */		
			//ET3时钟使能
			RCC_PERCLK_SetableEx( ET3CLK, ENABLE );	
			//NVIC中断配置
			NVIC_DisableIRQ(ETIM3_IRQn);
			NVIC_SetPriority(ETIM3_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(ETIM3_IRQn);			
			break;

		case 3:
			//信号源参数
			init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET4_APBCLK;		/* GROUP1 信号选择APBCLK */
			init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET4_XTLF;		/* GROUP2 信号选择XTLF */		
			//ET4时钟使能
			RCC_PERCLK_SetableEx( ET4CLK, ENABLE );		
			//NVIC中断配置
			NVIC_DisableIRQ(ETIM4_IRQn);
			NVIC_SetPriority(ETIM4_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(ETIM4_IRQn);	
			break;
		
		default:
			break;
	}
	init_para.sig_src_para.PRESCALE1 = clkmode - 1 + 99;    //100分频	/* ETx预分频寄存器1 */ 00表示1分频，FF表示256分频
	init_para.sig_src_para.PRESCALE2 = clkmode - 1;    		//1分频		/* ETx预分频寄存器2 */ 00表示1分频，FF表示256分频
	
	
	//控制类参数
	init_para.ctrl_para.EXFLT = ENABLE;								/* 引脚输入数字滤波使能打开 */
	init_para.ctrl_para.MOD = ETIMx_ETxCR_MOD_COUNTER;				/* 工作模式选择计数模式 */
	init_para.ctrl_para.CASEN = DISABLE;							/* 扩展定时器级联关闭 */
	init_para.ctrl_para.EDGESEL = ETIMx_ETxCR_EDGESEL_RISING;		/* 计数模式采沿方式选择（计数时钟选择mcu_clk时该位无效，总是采用mcu_clk时钟上升沿计数） */

	init_para.ctrl_para.PWM = DISABLE;								/* PWM输出关闭 */

	init_para.ctrl_para.CAPMOD = ETIMx_ETxCR_CAPMOD_PERIOD;			/* 捕捉模式控制 */
	init_para.ctrl_para.CAPCLR = DISABLE;							/* 带清零捕捉模式控制 */
	init_para.ctrl_para.CAPONCE = DISABLE;							/* 单次捕捉控制 */
	init_para.ctrl_para.CAPEDGE = ETIMx_ETxCR_CAPEDGE_RISING;		/* 捕捉沿选择 */

	init_para.ctrl_para.CMPIE = DISABLE;		/* 扩展定时器比较中断使能 */
	init_para.ctrl_para.CAPIE = DISABLE;		/* 扩展定时器捕捉中断使能 */
	init_para.ctrl_para.OVIE = ENABLE;			/* 扩展定时器溢出中断使能 */

	init_para.ctrl_para.INITVALUE = 0xffff - 800; //计数初值，8000000的100分频 计数 8000个周期 = 100ms ;		/* ETx初值寄存器 */
	init_para.ctrl_para.CMP = 0;			/* ETx比较寄存器 */
	
	init_para.ctrl_para.CEN = DISABLE;		/* 启动控制 */
	
	//初始化ETIM
	ETIMx_Init(ETIMx, &init_para);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//启动定时器
}

Run_LED(void)
{
	if(Run_LED_Process == 1)
	{
		//GPIO_ToggleBits(GPIOA,GPIO_Pin_3);
		LED1_TOG;	
		Run_LED_Process = 0;
	}
	//LED0_Flash(5);		//太耗资源    需要用定时器做
}

void Test_GPIO_InPut(void)
{
	RCC_PERCLK_SetableEx( PDCCLK, 		ENABLE );		//IO控制时钟寄存器使能

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
			TicksDelayMs( 10, NULL );//软件延时去抖
			if(KEY0_N)
			{
				/*
				if((adjustment_para.ctrl_para.LOADL<=0xFF) &&(adjustment_para.ctrl_para.LOADL>5))
				{
					adjustment_para.ctrl_para.LOADL=adjustment_para.ctrl_para.LOADL - 5;
					//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);
					//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//低位加载值
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
			TicksDelayMs( 5, NULL );//软件延时去抖
			if(KEY0_P)
			{
				//BTIMER_PWM_DEMO_start();
				//LED0_OFF;
				if((keyup_press==1)&&(Disp_page<8))
				{
					Disp_page++;	//弹起时处理
					keyup_press = 0;		//曾经按下过
				}
				
			}
		}

		if(KEY1_N)
		{
			TicksDelayMs( 10, NULL );//软件延时去抖
			if(KEY1_N)
			{	/*
				if((adjustment_para.ctrl_para.LOADL<0xFA) &&(adjustment_para.ctrl_para.LOADL>=1))
				{
					adjustment_para.ctrl_para.LOADL=adjustment_para.ctrl_para.LOADL + 5;
					//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);
					//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//低位加载值
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
			TicksDelayMs( 5, NULL );//软件延时去抖
			if(KEY1_P)
			{
				//BTIMER_PWM_DEMO_start();
				//LED1_OFF;
				if((keydown_press==1)&&(Disp_page>6))
				{
					Disp_page--;	//弹起时处理
					keydown_press =0;		//曾经按下过
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
		Lcd_Display();   //刷新显示
		Run_Display_Process = 0;
	}
}

void Run_ADC(void)
{
	unsigned long SetTemperature_back;
	if(Run_ADC_Process == 1)
	{
		SetTemperature_back = SetTemperature;		//保存旧数据便于和新数据比对
		
		Temperature = Test_ADC_Temperature();   //刷新显示
		SetTemperature = Test_ADC_ExVolt();
		SetTemperature = SetTemperature/7+200;  //实际设定温度值
		IronTemperature = Test_ADC_ExVolt2();
		IronTemperature = IronTemperature*10/0.5/100;  //实际测试温度值
		
		if((SetTemperature<SetTemperature_back-2)||(SetTemperature>SetTemperature_back+2))
		{
			//电位器发生了变动启动调整温度设置
			//显示温度调整值
			Disp_page = 7;
			SetTemperature_Count = 10;		//启用倒计时
		}

		//升温设定 --  初始温度，上电后读取
		if(IronTemperature<SetTemperature-20)		//区间值   
		{
			//直接满PWM升温到限定值      设定350度 - 升温至320
			adjustment_para.ctrl_para.LOADL = 0;
			BTIMx_Init(BTIM1, &adjustment_para);
			BTIMER_PWM_DEMO_start();
			LED0_ON;
		}
		else if(IronTemperature>SetTemperature+5)	 
		{
			//直接空PWM进行降温
			adjustment_para.ctrl_para.LOADL = 0xff;
			BTIMx_Init(BTIM1, &adjustment_para);
			BTIMER_PWM_DEMO_start();
			LED0_OFF;
		}
		else if((IronTemperature<SetTemperature+20)||(IronTemperature>SetTemperature-20))
		{
			//经验PWM值   --  公式
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
	Init_System();				//系统初始化 
 
	BTIMER_PWM_DEMO_init();	//PWM定时器初始化
	BTIMER_PWM_DEMO_start();	//PWM输出开始
	Test_Etimx(ETIM1);	//基本定时器1
	Test_GPIO_InPut();	//按键输入

	//ADC外部输入通道测试
	Test_ADC_ExVolt();
	
	//ADC温度传感器通道测试
	Test_ADC_Temperature();

	initLCDM();
	memset( LCM_DDRAM, 0x00, 1600 );    //清显示缓冲区
	LCD_Fulldisplay();		//液晶全部显示
	LCD_on();

	Display.Number=0xff;		//设置默认显示页面
	
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
		
		//BTIMx_BTLOADH_Write(BTIM1, adjustment_para->ctrl_para.LOADH);//低位加载值
		//BTIMx_BTLOADL_Write(BTIM1, adjustment_para->ctrl_para.LOADL);//低位加载值
		//BTIMx_BTOCR_OUTMOD_Set(BTIM1, adjustment_para->out_para.OUTMOD);//输出模式选择
		//BTIMx_BTOCR_OUTSEL_Set(BTIM1, adjustment_para->out_para.OUTSEL);//输出信号选择
		//BTIMx_BTOUTCNT_Write(BTIM1, adjustment_para->out_para.OUTCNT);//输出脉冲宽度设置
		//BTIMx_BTOCR_OUTINV_Set(BTIM1, adjustment_para->out_para.OUTINV);//输出电平反向选择
		Run_LED();
		Run_KEY();
		Run_DISPLAY();
		Run_ADC();
		IWDT_Clr();		//清系统看门狗
		//TicksDelayMs( 50, NULL );		//软件延时	
	}	
}


