#include "define_all.h"  


float Temperature;
unsigned long SetTemperature;
unsigned long IronTemperature;
unsigned char SetTemperature_Count;

struct ADC_Struct
{
	uint16* Bufu16;		//���ݻ�������ַ	//ע���ڴ����
	uint08 SampleNeed;	//��Ҫ���������ݸ���
	uint08 SampleCount; //�Ѿ����������ݸ���
};

struct ADC_Struct ADC_Struct;


void ADC_IO_Init(void)
{
	/* PC15ģ�⹦��ѡ�� */
//	GPIO_ANASEL_PC15ANS_Set(GPIO_ANASEL_PC15ANS_ACMP2_INP0);

	/* PC13ģ�⹦��ѡ�� */
	GPIO_ANASEL_PC13ANS_Set(GPIO_ANASEL_PC13ANS_ADC_IN2);

	/* PC12ģ�⹦��ѡ�� */
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
	//ʹ�ü򵥺�������
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//ģ���·����ʱ��ʹ��
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADCʱ��ʹ��
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC����ʱ�����ã����ɸ���1M
	
	ANAC_ADC_Channel_SetEx(CH_IN4);				//ADC����ͨ��ѡ��  CH_IN2
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//�жϽ�ֹ
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC�ر�
	
//	//ʹ�ô�ͳ��ʽ����
//	ANAC_ADC_InitTypeDef ADC_InitStruct;
//	
//	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//ģ���·����ʱ��ʹ��
//	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADCʱ��ʹ��
//	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC����ʱ�����ã����ɸ���1M
//	
//	ADC_InitStruct.ADC_TRIM = const_adc_TrimV;		//�ο���ѹ����
//	ADC_InitStruct.ADC_VANA_EN = ANAC_ADCCON_ADC_VANA_EN_VOLTAGE;		//������ѹ
//	ADC_InitStruct.BUFSEL = ANAC_ADCINSEL_BUFSEL_ADC_IN2;		//����ͨ��ѡ��
//	ADC_InitStruct.BUFEN = ENABLE;			//buffer��
//	ADC_InitStruct.BUFBYP = DISABLE;		//bufferbypass�ر�
//	ADC_InitStruct.ADC_IE = DISABLE;		//�жϽ�ֹ
//	ADC_InitStruct.ADC_EN = DISABLE;		//ADC�ر�
//	
//	ANAC_ADC_Init(&ADC_InitStruct);			//����ADC

//	/*NVIC�ж�����*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//�ж����ȼ�����
//	NVIC_EnableIRQ(ADC_IRQn);	
}


void ADC_Init_TsetExVolt2(void)
{
	//ʹ�ü򵥺�������
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//ģ���·����ʱ��ʹ��
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADCʱ��ʹ��
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC����ʱ�����ã����ɸ���1M
	
	ANAC_ADC_Channel_SetEx(CH_IN5);				//ADC����ͨ��ѡ��  CH_IN2
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//�жϽ�ֹ
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC�ر�
	
//	//ʹ�ô�ͳ��ʽ����
//	ANAC_ADC_InitTypeDef ADC_InitStruct;
//	
//	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//ģ���·����ʱ��ʹ��
//	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADCʱ��ʹ��
//	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC����ʱ�����ã����ɸ���1M
//	
//	ADC_InitStruct.ADC_TRIM = const_adc_TrimV;		//�ο���ѹ����
//	ADC_InitStruct.ADC_VANA_EN = ANAC_ADCCON_ADC_VANA_EN_VOLTAGE;		//������ѹ
//	ADC_InitStruct.BUFSEL = ANAC_ADCINSEL_BUFSEL_ADC_IN2;		//����ͨ��ѡ��
//	ADC_InitStruct.BUFEN = ENABLE;			//buffer��
//	ADC_InitStruct.BUFBYP = DISABLE;		//bufferbypass�ر�
//	ADC_InitStruct.ADC_IE = DISABLE;		//�жϽ�ֹ
//	ADC_InitStruct.ADC_EN = DISABLE;		//ADC�ر�
//	
//	ANAC_ADC_Init(&ADC_InitStruct);			//����ADC

//	/*NVIC�ж�����*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//�ж����ȼ�����
//	NVIC_EnableIRQ(ADC_IRQn);	
}


void ADC_Init_TsetTemperature(void)
{
	//ʹ�ü򵥺�������
	RCC_PERCLK_SetableEx(ANACCLK, ENABLE);		//ģ���·����ʱ��ʹ��
	RCC_PERCLK_SetableEx(ADCCLK, ENABLE);		//ADCʱ��ʹ��
	RCC_PERCLKCON2_ADCCKSEL_Set(RCC_PERCLKCON2_ADCCKSEL_RCHFDIV16);	//ADC����ʱ�����ã����ɸ���1M
	
	ANAC_ADC_Channel_SetEx(CH_PTAT);			//ADC����ͨ��ѡ���¶ȴ�����
	ANAC_ADCCON_ADC_IE_Setable(DISABLE);		//�жϽ�ֹ
	ANAC_ADCCON_ADC_EN_Setable(DISABLE);		//ADC�ر�
//	/*NVIC�ж�����*/
//	NVIC_DisableIRQ(ADC_IRQn);
//	NVIC_SetPriority(ADC_IRQn,2);//�ж����ȼ�����
//	NVIC_EnableIRQ(ADC_IRQn);
}

uint08 ADC_Wait_Finish(void)
{	
	Do_DelayStart();	
	{
		if(SET == ANAC_ADCIF_ADC_IF_Chk()) return 0;		
	}While_DelayMsEnd(8*clkmode);//�ȴ�8ms
	
	return 1;//��ʱ
}

//ADC�ⲿ����ͨ������
float Test_ADC_ExVolt(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Vlotage = 0;
	volatile float fVlotage = 0;

	ADC_IO_Init();							//IO������ΪADC����
	ADC_Init_TsetExVolt();					//����ADC
	
	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC����
	
	ADC_Wait_Finish();						//������һ��ת�����
	ANAC_ADCIF_ADC_IF_Clr();				//����жϱ�־
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//����жϱ�־
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//�ȴ�ת�����
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//��ȡADֵ
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//���㴦�������ȸ�,680us@8MHz
		fTempADC = TempADC/8.0;
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//ADֵת��Ϊ��ѹ
		fVlotage = ANAC_ADC_VoltageCalc2(fTempADC, 5);//����Դ��ѹ��ѹ����

		//���������ٶȿ�,120us@8MHz
		TempADC = TempADC/8;
		Vlotage = ANAC_ADC_VoltageCalcInt(TempADC);//ADֵת��Ϊ��ѹ
		Vlotage = ANAC_ADC_VoltageCalcInt2(TempADC, 5);//����Դ��ѹ��ѹ����
	}

	return Vlotage;
}


//ADC�ⲿ����ͨ��2����
float Test_ADC_ExVolt2(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Vlotage = 0;
	volatile float fVlotage = 0;

	ADC_IO_Init();							//IO������ΪADC����
	ADC_Init_TsetExVolt2();					//����ADC
	
	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC����
	
	ADC_Wait_Finish();						//������һ��ת�����
	ANAC_ADCIF_ADC_IF_Clr();				//����жϱ�־
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//����жϱ�־
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//�ȴ�ת�����
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//��ȡADֵ
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//���㴦�������ȸ�,680us@8MHz
		fTempADC = TempADC/8.0;
		fVlotage = ANAC_ADC_VoltageCalc(fTempADC);//ADֵת��Ϊ��ѹ
		fVlotage = ANAC_ADC_VoltageCalc2(fTempADC, 5);//����Դ��ѹ��ѹ����

		//���������ٶȿ�,120us@8MHz
		TempADC = TempADC/8;
		Vlotage = ANAC_ADC_VoltageCalcInt(TempADC);//ADֵת��Ϊ��ѹ
		Vlotage = ANAC_ADC_VoltageCalcInt2(TempADC, 5);//����Դ��ѹ��ѹ����
	}

	return Vlotage;
}

//ADC�¶ȴ�����ͨ������
float Test_ADC_Temperature(void)
{
	uint16 ADCData[8];
	uint08 i;
	uint32 TempADC = 0;
	float fTempADC = 0;
	volatile uint32 Temperature = 0;
	volatile float fTemperature = 0;

	ADC_Init_TsetTemperature();				//����ADC

	ANAC_ADCCON_ADC_EN_Setable(ENABLE);		//ADC����
	
	ADC_Wait_Finish();						//������һ��ת�����
	ANAC_ADCIF_ADC_IF_Clr();				//����жϱ�־
	
	TempADC = 0;
	for(i=0; i<8; i++)
	{
		ANAC_ADCIF_ADC_IF_Clr();			//����жϱ�־
		
		ADCData[i] = 0;
		if(0 == ADC_Wait_Finish())			//�ȴ�ת�����
		{
			ADCData[i] = ANAC_ADCDATA_Read();	//��ȡADֵ
			TempADC += ADCData[i];
		}
		else
		{
			break;
		}
	}
	
	if( i == 8 )
	{
		//���㴦�������ȸ�,360us@8MHz
		fTempADC = TempADC/8.0;
		fTemperature = ANAC_ADC_TemperatureCalc(fTempADC, 5);//ADֵת��Ϊ�¶�
		
		//���������ٶȿ�,120us@8MHz
		TempADC = TempADC/8;
		Temperature = ANAC_ADC_TemperatureCalcInt(TempADC, 5);//ADֵת��Ϊ�¶�
	}
	
	return fTemperature;
}

