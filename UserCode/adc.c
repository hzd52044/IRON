#include "define_all.h"  


float Temperature;
unsigned long SetTemperature;
unsigned long IronTemperature;
unsigned char SetTemperature_Count;

struct ADC_Struct
{
	uint16* Bufu16;		//数据缓冲区地址	//注意内存对齐
	uint08 SampleNeed;	//需要采样的数据个数
	uint08 SampleCount; //已经采样的数据个数
};

struct ADC_Struct ADC_Struct;


void ADC_IO_Init(void)
{
	/* PC15模拟功能选择 */
//	GPIO_ANASEL_PC15ANS_Set(GPIO_ANASEL_PC15ANS_ACMP2_INP0);

	/* PC13模拟功能选择 */
	GPIO_ANASEL_PC13ANS_Set(GPIO_ANASEL_PC13ANS_ADC_IN2);

	/* PC12模拟功能选择 */
	GPIO_ANASEL_PC12ANS_Set(GPIO_ANASEL_PC12ANS_ADC_IN1);
	
//	AnalogIO( GPIOC, GPIO_Pin_12 );	//CH_IN1	PC12
//	AnalogIO( GPIOC, GPIO_Pin_13 );	//CH_IN2	PC13
//	AnalogIO( GPIOD, GPIO_Pin_0 );	//CH_IN3	PD0
	AnalogIO( GPIOD, GPIO_Pin_1 );	//CH_IN4	PD1
	AnalogIO( GPIOF, GPIO_Pin_6 );	//CH_IN5	PF6
//	AnalogIO( GPIOC, GPIO_Pin_15 );	//CH_IN6	PC15
//	AnalogIO( GPIOB, GPIO_Pin_2 );	//CH_IN7	PB2
//	AnalogIO( GPIOB, GPIO_Pin_3 );	//CH_IN8	PB3
}

void ADC_Init_TsetExVolt(void)
{
	//使用简单函数配置
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//模拟电路总线时钟使能
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADC时钟使能
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC工作时钟配置，不可高于1M
	
	ANAC_ADC_Channel_SetEx(CH_IN4);				//ADC输入通道选择  CH_IN2
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//中断禁止
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC关闭
	
//	//使用传统方式配置
//	ANAC_ADC_InitTypeDef ADC_InitStruct;
//	
//	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//模拟电路总线时钟使能
//	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADC时钟使能
//	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC工作时钟配置，不可高于1M
//	
//	ADC_InitStruct.ADC_TRIM = const_adc_TrimV;		//参考电压配置
//	ADC_InitStruct.ADC_VANA_EN = ANAC_ADCCON_ADC_VANA_EN_VOLTAGE;		//测量电压
//	ADC_InitStruct.BUFSEL = ANAC_ADCINSEL_BUFSEL_ADC_IN2;		//输入通道选择
//	ADC_InitStruct.BUFEN = ENABLE;			//buffer打开
//	ADC_InitStruct.BUFBYP = DISABLE;		//bufferbypass关闭
//	ADC_InitStruct.ADC_IE = DISABLE;		//中断禁止
//	ADC_InitStruct.ADC_EN = DISABLE;		//ADC关闭
//	
//	ANAC_ADC_Init(&ADC_InitStruct);			//配置ADC

//	/*NVIC中断配置*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//中断优先级配置
//	NVIC_EnableIRQ(ADC_IRQn);	
}


void ADC_Init_TsetExVolt2(void)
{
	//使用简单函数配置
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//模拟电路总线时钟使能
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADC时钟使能
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC工作时钟配置，不可高于1M
	
	ANAC_ADC_Channel_SetEx(CH_IN5);				//ADC输入通道选择  CH_IN2
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//中断禁止
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC关闭
	
//	//使用传统方式配置
//	ANAC_ADC_InitTypeDef ADC_InitStruct;
//	
//	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//模拟电路总线时钟使能
//	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADC时钟使能
//	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC工作时钟配置，不可高于1M
//	
//	ADC_InitStruct.ADC_TRIM = const_adc_TrimV;		//参考电压配置
//	ADC_InitStruct.ADC_VANA_EN = ANAC_ADCCON_ADC_VANA_EN_VOLTAGE;		//测量电压
//	ADC_InitStruct.BUFSEL = ANAC_ADCINSEL_BUFSEL_ADC_IN2;		//输入通道选择
//	ADC_InitStruct.BUFEN = ENABLE;			//buffer打开
//	ADC_InitStruct.BUFBYP = DISABLE;		//bufferbypass关闭
//	ADC_InitStruct.ADC_IE = DISABLE;		//中断禁止
//	ADC_InitStruct.ADC_EN = DISABLE;		//ADC关闭
//	
//	ANAC_ADC_Init(&ADC_InitStruct);			//配置ADC

//	/*NVIC中断配置*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//中断优先级配置
//	NVIC_EnableIRQ(ADC_IRQn);	
}


void ADC_Init_TsetTemperature(void)
{
	//使用简单函数配置
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//模拟电路总线时钟使能
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADC时钟使能
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC工作时钟配置，不可高于1M
	
	ANAC_ADC_Channel_SetEx(CH_PTAT);			//ADC输入通道选择温度传感器
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//中断禁止
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC关闭
//	/*NVIC中断配置*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//中断优先级配置
//	NVIC_EnableIRQ(ADC_IRQn);
}

uint08 ADC_Wait_Finish(void)
{	
	Do_DelayStart();	
	{
		if(SET == ANAC_ADCIF_ADC_IF_Chk()) return 0;		
	}While_DelayMsEnd(8*clkmode);//等待8ms
	
	return 1;//超时
}

//ADC外部输入通道测试
float Test_ADC_ExVolt(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Vlotage = 0;
	volatile float fVlotage = 0;

	ADC_IO_Init();							//IO口配置为ADC输入
	ADC_Init_TsetExVolt();					//配置ADC
	
	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC启动
	
	ADC_Wait_Finish();						//丢弃第一个转换结果
	ANAC_ADCIF_ADC_IF_Clr();				//清除中断标志
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//清除中断标志
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//等待转换完成
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//读取AD值
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//浮点处理结果精度高,680us@8MHz
		fTempADC = TempADC/8.0;
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//AD值转换为电压
		fVlotage = ANAC_ADC_VoltageCalc2(fTempADC, 5);//带电源电压电压补偿

		//整数处理速度快,120us@8MHz
		TempADC = TempADC/8;
		Vlotage = ANAC_ADC_VoltageCalcInt(TempADC);//AD值转换为电压
		Vlotage = ANAC_ADC_VoltageCalcInt2(TempADC, 5);//带电源电压电压补偿
	}

	return Vlotage;
}


//ADC外部输入通道2测试
float Test_ADC_ExVolt2(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Vlotage = 0;
	volatile float fVlotage = 0;

	ADC_IO_Init();							//IO口配置为ADC输入
	ADC_Init_TsetExVolt2();					//配置ADC
	
	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC启动
	
	ADC_Wait_Finish();						//丢弃第一个转换结果
	ANAC_ADCIF_ADC_IF_Clr();				//清除中断标志
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//清除中断标志
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//等待转换完成
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//读取AD值
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//浮点处理结果精度高,680us@8MHz
		fTempADC = TempADC/8.0;
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//AD值转换为电压
		fVlotage = ANAC_ADC_VoltageCalc2(fTempADC, 5);//带电源电压电压补偿

		//整数处理速度快,120us@8MHz
		TempADC = TempADC/8;
		Vlotage = ANAC_ADC_VoltageCalcInt(TempADC);//AD值转换为电压
		Vlotage = ANAC_ADC_VoltageCalcInt2(TempADC, 5);//带电源电压电压补偿
	}

	return Vlotage;
}

//ADC温度传感器通道测试
float Test_ADC_Temperature(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Temperature = 0;
	volatile float fTemperature = 0;

	ADC_Init_TsetTemperature();				//配置ADC

	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC启动
	
	ADC_Wait_Finish();						//丢弃第一个转换结果
	ANAC_ADCIF_ADC_IF_Clr();				//清除中断标志
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//清除中断标志
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//等待转换完成
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//读取AD值
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//浮点处理结果精度高,360us@8MHz
		fTempADC = TempADC/8.0;
		fTemperature = ANAC_ADC_TemperatureCalc(fTempADC, 5);//AD值转换为温度
		
		//整数处理速度快,120us@8MHz
		TempADC = TempADC/8;
		Temperature = ANAC_ADC_TemperatureCalcInt(TempADC, 5);//AD值转换为温度
	}
	
	return fTemperature;
}

