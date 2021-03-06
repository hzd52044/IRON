/**
  ******************************************************************************
  * @file    fm33a0xx_uart.c
  * @author  
  * @version V3.02
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Universal synchronous asynchronous receiver
  *          transmitter (UART):           
  *           
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_uart.h" 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


//Code_Start
//2018-04-02-13-17-16
//FM33A0XX_Driver_Gen_V1.4

/********************************
红外调制发送数据极性选择函数
功能:红外调制发送数据极性选择
输入:控制红外调制发送数据时的极性选择
********************************/
void UART_IRCON_IRFLAG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		UART->IRCON |= (UART_IRCON_IRFLAG_Msk);
	}
	else
	{
		UART->IRCON &= ~(UART_IRCON_IRFLAG_Msk);
	}
}
/********************************
读取红外调制发送数据极性选择函数
功能:读取红外调制发送数据极性选择
输出:控制红外调制发送数据时的极性选择
********************************/
FunState UART_IRCON_IRFLAG_Getable(void)
{
	if (UART->IRCON & (UART_IRCON_IRFLAG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
红外占空比调制参数设置函数
功能:红外占空比调制参数设置
输入:红外占空比调制参数
********************************/
void UART_IRCON_TH_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UART->IRCON;
	tmpreg &= ~(UART_IRCON_TH_Msk);
	tmpreg |= (SetValue & UART_IRCON_TH_Msk);
	UART->IRCON = tmpreg;
}
/********************************
读取红外占空比调制参数函数
功能:读取红外占空比调制参数
输出:红外占空比调制参数
********************************/
uint32_t UART_IRCON_TH_Get(void)
{
	return (UART->IRCON & UART_IRCON_TH_Msk);
}

/********************************
红外调制频率设置函数
功能:红外调制频率的设置
输入:红外调制频率
********************************/
void UART_IRCON_TZBRG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UART->IRCON;
	tmpreg &= ~(UART_IRCON_TZBRG_Msk);
	tmpreg |= (SetValue & UART_IRCON_TZBRG_Msk);
	UART->IRCON = tmpreg;
}

/********************************
读取红外调制频率设置函数
功能:读取红外调制频率的设置
输出:红外调制频率
********************************/
uint32_t UART_IRCON_TZBRG_Get(void)
{
	return (UART->IRCON & UART_IRCON_TZBRG_Msk);
}

/********************************
模式选择位设置函数
功能:模式选择位的设置
输入:模式选择位
00 = 8位数据，无奇偶校验；
01 = 8位数据，偶校验；
10 = 8位数据，奇校验。
11 = 9位数据， 无奇偶校验；
********************************/
void UARTx_RXSTA_PDSEL_Set(UARTx_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->RXSTA;
	tmpreg &= ~(UARTx_RXSTA_PDSEL_Msk);
	tmpreg |= (SetValue & UARTx_RXSTA_PDSEL_Msk);
	UARTx->RXSTA = tmpreg;
}

/********************************
读取模式选择位设置函数
功能:读取模式选择位的设置
输出:模式选择位
00 = 8位数据，无奇偶校验；
01 = 8位数据，偶校验；
10 = 8位数据，奇校验。
11 = 9位数据， 无奇偶校验；
********************************/
uint32_t UARTx_RXSTA_PDSEL_Get(UARTx_Type* UARTx)
{
	return (UARTx->RXSTA & UARTx_RXSTA_PDSEL_Msk);
}

/********************************
错误中断允许位设置函数
功能:错误中断允许位设置
输入:错误中断允许位
奇偶校验错，帧格式错，溢出错
********************************/
void UARTx_RXSTA_ERRIE_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->RXSTA |= (UARTx_RXSTA_ERRIE_Msk);
	}
	else
	{
		UARTx->RXSTA &= ~(UARTx_RXSTA_ERRIE_Msk);
	}
}
/********************************
读取错误中断允许位设置函数
功能:读取错误中断允许位设置
输出:错误中断允许位
奇偶校验错，帧格式错，溢出错
********************************/
FunState UARTx_RXSTA_ERRIE_Getable(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & (UARTx_RXSTA_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/********************************
接收模块使能位设置函数
功能:接收模块使能位设置
输入:接收模块使能位
1 = 使能接收模块；
0 = 禁止接收模块，接收模块被复位。
********************************/
void UARTx_RXSTA_RXEN_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->RXSTA |= (UARTx_RXSTA_RXEN_Msk);
	}
	else
	{
		UARTx->RXSTA &= ~(UARTx_RXSTA_RXEN_Msk);
	}
}

/********************************
读取接收模块使能位设置函数
功能:读取接收模块使能位设置
输出:接收模块使能位
1 = 使能接收模块；
0 = 禁止接收模块，接收模块被复位。
********************************/
FunState UARTx_RXSTA_RXEN_Getable(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & (UARTx_RXSTA_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
奇偶校验错标志位设置函数
功能:奇偶校验错标志位设置
输入:奇偶校验错标志位
1 = 校验错；
0 = 无校验错。
********************************/
void UARTx_RXSTA_PERR_Clr(UARTx_Type* UARTx)
{
	UARTx->RXSTA &= ~(UARTx_RXSTA_PERR_Msk);
}

/********************************
读取奇偶校验错标志位设置函数
功能:读取奇偶校验错标志位设置
输出:奇偶校验错标志位
1 = 校验错；
0 = 无校验错。
********************************/
FlagStatus UARTx_RXSTA_PERR_Chk(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & UARTx_RXSTA_PERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
帧格式错标志位设置函数
功能:帧格式错标志位设置
输入:帧格式错标志位
1 = 帧格式错；
0 = 无帧格式错。
********************************/
void UARTx_RXSTA_FERR_Clr(UARTx_Type* UARTx)
{
	UARTx->RXSTA &= ~(UARTx_RXSTA_FERR_Msk);
}
/********************************
读取帧格式错标志位设置函数
功能:读取帧格式错标志位设置
输出:帧格式错标志位
1 = 帧格式错；
0 = 无帧格式错。
********************************/
FlagStatus UARTx_RXSTA_FERR_Chk(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & UARTx_RXSTA_FERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
/********************************
溢出错标志位设置函数
功能:溢出错标志位设置
输入:溢出错标志位
1 = 有溢出错误；
0 = 无溢出错。
********************************/
void UARTx_RXSTA_OERR_Clr(UARTx_Type* UARTx)
{
	UARTx->RXSTA &= ~(UARTx_RXSTA_OERR_Msk);
}
/********************************
读取溢出错标志位设置函数
功能:读取溢出错标志位设置
输出:溢出错标志位
1 = 有溢出错误；
0 = 无溢出错。
********************************/
FlagStatus UARTx_RXSTA_OERR_Chk(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & UARTx_RXSTA_OERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
读取接收数据的第9位函数
功能:读取接收数据的第9位
输出:接收数据的第9位
********************************/
FlagStatus UARTx_RXSTA_RX9D_Chk(UARTx_Type* UARTx)
{
	if (UARTx->RXSTA & UARTx_RXSTA_RX9D_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
停止位选择位设置函数
功能:停止位选择位设置
输入:停止位选择位
1 = 停止位为2位；
0 = 停止位为1位
********************************/
void UARTx_TXSTA_STOPSEL_Set(UARTx_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TXSTA;
	tmpreg &= ~(UARTx_TXSTA_STOPSEL_Msk);
	tmpreg |= (SetValue & UARTx_TXSTA_STOPSEL_Msk);
	UARTx->TXSTA = tmpreg;
}
/********************************
读取停止位选择位设置函数
功能:读取停止位选择位设置
输出:停止位选择位
1 = 停止位为2位；
0 = 停止位为1位
********************************/
uint32_t UARTx_TXSTA_STOPSEL_Get(UARTx_Type* UARTx)
{
	return (UARTx->TXSTA & UARTx_TXSTA_STOPSEL_Msk);
}

/********************************
发送中断选择位设置函数
功能:发送中断选择位设置
输入:发送中断选择位
1 = 移位寄存器空产生中断；
0 = 发送缓冲器空产生中断。
********************************/
void UARTx_TXSTA_TXIS_Set(UARTx_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TXSTA;
	tmpreg &= ~(UARTx_TXSTA_TXIS_Msk);
	tmpreg |= (SetValue & UARTx_TXSTA_TXIS_Msk);
	UARTx->TXSTA = tmpreg;
}
/********************************
读取发送中断选择位设置函数
功能:读取发送中断选择位设置
输出:发送中断选择位
1 = 移位寄存器空产生中断；
0 = 发送缓冲器空产生中断。
********************************/
uint32_t UARTx_TXSTA_TXIS_Get(UARTx_Type* UARTx)
{
	return (UARTx->TXSTA & UARTx_TXSTA_TXIS_Msk);
}

/********************************
发送模块使能位设置函数
功能:发送模块使能位设置
输入:发送模块使能位
1 = 使能发送模块；
0 = 禁止发送模块，发送模块被复位。
********************************/
void UARTx_TXSTA_TXEN_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->TXSTA |= (UARTx_TXSTA_TXEN_Msk);
	}
	else
	{
		UARTx->TXSTA &= ~(UARTx_TXSTA_TXEN_Msk);
	}
}
/********************************
读取发送模块使能位设置函数
功能:读取发送模块使能位设置
输出:发送模块使能位
1 = 使能发送模块；
0 = 禁止发送模块，发送模块被复位。
********************************/
FunState UARTx_TXSTA_TXEN_Getable(UARTx_Type* UARTx)
{
	if (UARTx->TXSTA & (UARTx_TXSTA_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
发送红外调制使能位设置函数
功能:发送红外调制使能位设置
输入:发送红外调制使能位
1 = 使能发送红外调制；
0 = 禁止发送红外调制。
********************************/
void UARTx_TXSTA_IREN_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->TXSTA |= (UARTx_TXSTA_IREN_Msk);
	}
	else
	{
		UARTx->TXSTA &= ~(UARTx_TXSTA_IREN_Msk);
	}
}
/********************************
读取发送红外调制使能位设置函数
功能:读取发送红外调制使能位设置
输出:发送红外调制使能位
1 = 使能发送红外调制；
0 = 禁止发送红外调制。
********************************/
FunState UARTx_TXSTA_IREN_Getable(UARTx_Type* UARTx)
{
	if (UARTx->TXSTA & (UARTx_TXSTA_IREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
设置发送数据的第9位函数
功能:设置发送数据的第9位
输入:发送数据的第9位
********************************/
void UARTx_TXSTA_TX9D_Set(UARTx_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TXSTA;
	tmpreg &= ~(UARTx_TXSTA_TX9D_Msk);
	tmpreg |= (SetValue & UARTx_TXSTA_TX9D_Msk);
	UARTx->TXSTA = tmpreg;
}

/********************************
读取接收数据缓冲寄存器函数
功能:读取接收数据缓冲寄存器
输出:接收数据缓冲寄存器的数值
********************************/
uint32_t UARTx_RXREG_Read(UARTx_Type* UARTx)
{
	return (UARTx->RXREG & UARTx_RXREG_RXREG_Msk);
}

/********************************
写入发送数据缓冲寄存器函数
功能:写入发送数据缓冲寄存器的值
输入:要发送的数值
********************************/
void UARTx_TXREG_Write(UARTx_Type* UARTx, uint32_t SetValue)
{
	UARTx->TXREG = (SetValue & UARTx_TXREG_TXREG_Msk);
}

/********************************
写入波特率产生器寄存器函数
功能:写入波特率
输入:要设置的波特率
********************************/
void UARTx_SPBRG_Write(UARTx_Type* UARTx, uint32_t SetValue)
{
	UARTx->SPBRG = (SetValue & UARTx_SPBRG_SPBRG_Msk);
}
/********************************
读取波特率产生器寄存器函数
功能:读取波特率
输出:波特率
********************************/
uint32_t UARTx_SPBRG_Read(UARTx_Type* UARTx)
{
	return (UARTx->SPBRG & UARTx_SPBRG_SPBRG_Msk);
}

/********************************
发送中断选择位设置函数
功能:发送中断选择位 设置
输入:发送中断选择位 
11 = 不产生中断
10 = TXBUF空产生中断
01 = TXBUF空且移位寄存器空产生中断
00 =由TXIS决定发送中断在发送缓冲空或者移位寄存器空时产生
********************************/
void UARTx_TXBUFSTA_TX_INTSEL_Set(UARTx_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TXBUFSTA;
	tmpreg &= ~(UARTx_TXBUFSTA_TX_INTSEL_Msk);
	tmpreg |= (SetValue & UARTx_TXBUFSTA_TX_INTSEL_Msk);
	UARTx->TXBUFSTA = tmpreg;
}
/********************************
读取发送中断选择位设置函数
功能:读取发送中断选择位设置
输出:发送中断选择位 
11 = 不产生中断
10 = TXBUF空产生中断
01 = TXBUF空且移位寄存器空产生中断
00 =由TXIS决定发送中断在发送缓冲空或者移位寄存器空时产生
********************************/
uint32_t UARTx_TXBUFSTA_TX_INTSEL_Get(UARTx_Type* UARTx)
{
	return (UARTx->TXBUFSTA & UARTx_TXBUFSTA_TX_INTSEL_Msk);
}

/********************************
读取TXBUF状态位设置函数
功能:读取TXBUF状态位
输出:TXBUF状态位 
1 = TXBUF中有数据
0 = TXBUF空
********************************/
FlagStatus UARTx_TXBUFSTA_TXFF_Chk(UARTx_Type* UARTx)
{
	if (UARTx->TXBUFSTA & UARTx_TXBUFSTA_TXFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/********************************
读取RXBUF状态位设置函数
功能:读取RXBUF状态位
输出:RXBUF状态位 
1 = RXBUF中有1笔数据；
0 = RXBUF空；
********************************/
FlagStatus UARTx_RXBUFSTA_RXFF_Chk(UARTx_Type* UARTx)
{
	if (UARTx->RXBUFSTA & UARTx_RXBUFSTA_RXFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
收发7bit数据使能(覆盖PDSEL)设置函数
功能:收发7bit数据使能(覆盖PDSEL)的设置
输入:收发7bit数据使能(覆盖PDSEL) 
1 = 收发7位数据帧，格式为7位数据位+STOP，
收发数据为RXREG/TXREG[6:0]
0 = 正常收发；
********************************/
void UARTx_RTXCON_RTX7EN_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->RTXCON |= (UARTx_RTXCON_RTX7EN_Msk);
	}
	else
	{
		UARTx->RTXCON &= ~(UARTx_RTXCON_RTX7EN_Msk);
	}
}
/********************************
读取收发7bit数据使能(覆盖PDSEL)设置函数
功能:读取收发7bit数据使能(覆盖PDSEL)的设置
输出:收发7bit数据使能(覆盖PDSEL) 
1 = 收发7位数据帧，格式为7位数据位+STOP，
收发数据为RXREG/TXREG[6:0]
0 = 正常收发；
********************************/
FunState UARTx_RTXCON_RTX7EN_Getable(UARTx_Type* UARTx)
{
	if (UARTx->RTXCON & (UARTx_RTXCON_RTX7EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
接收数据取反控制位设置函数
功能:接收数据取反控制位的设置
输入:接收数据取反控制位 
1 = 接收数据取反；
0 = 接收数据不取反。
********************************/
void UARTx_RTXCON_RXDFLAG_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->RTXCON |= (UARTx_RTXCON_RXDFLAG_Msk);
	}
	else
	{
		UARTx->RTXCON &= ~(UARTx_RTXCON_RXDFLAG_Msk);
	}
}
/********************************
读取接收数据取反控制位设置函数
功能:读取接收数据取反控制位的设置
输出:接收数据取反控制位 
1 = 接收数据取反；
0 = 接收数据不取反。
********************************/
FunState UARTx_RTXCON_RXDFLAG_Getable(UARTx_Type* UARTx)
{
	if (UARTx->RTXCON & (UARTx_RTXCON_RXDFLAG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
发送数据取反控制位设置函数
功能:发送数据取反控制位的设置
输入:发送数据取反控制位 
1 = 发送数据取反，若红外调制开启时，则取反无效，
详见下图波形；
0 = 发送数据不取反。
********************************/
void UARTx_RTXCON_TXDFLAG_Setable(UARTx_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->RTXCON |= (UARTx_RTXCON_TXDFLAG_Msk);
	}
	else
	{
		UARTx->RTXCON &= ~(UARTx_RTXCON_TXDFLAG_Msk);
	}
}

/********************************
读取发送数据取反控制位设置函数
功能:读取发送数据取反控制位的设置
输出:发送数据取反控制位 
1 = 发送数据取反，若红外调制开启时，则取反无效，
详见下图波形；
0 = 发送数据不取反。
********************************/
FunState UARTx_RTXCON_TXDFLAG_Getable(UARTx_Type* UARTx)
{
	if (UARTx->RTXCON & (UARTx_RTXCON_TXDFLAG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
串口缺省设置函数
功能:串口缺省设置
********************************/
void UART_Deinit(void)
{
	UART->UARTIE = 0x00000000;
	//UART->UARTIF = ;
	UART->IRCON = 0x000000D2;
}
/********************************
串口缺省设置函数
功能:串口缺省设置
输入：串口号
********************************/
void UARTx_Deinit(UARTx_Type* UARTx)
{
	UARTx->RXSTA = 0x00000000;
	UARTx->TXSTA = 0x00000002;
	//UARTx->RXREG = ;
	//UARTx->TXREG = ;
	UARTx->SPBRG = 0x00000341;
	UARTx->TXBUFSTA = 0x00000000;
	UARTx->RXBUFSTA = 0x00000040;
	UARTx->RTXCON = 0x00000000;
}
//Code_End


/********************************
所有串口缺省设置函数
功能:串口缺省设置
********************************/
void UART_All_Deinit(void)
{
	UART_Deinit();
	UARTx_Deinit(UART0);
	UARTx_Deinit(UART1);
	UARTx_Deinit(UART2);
	UARTx_Deinit(UART3);
	UARTx_Deinit(UART4);
	UARTx_Deinit(UART5);
}


/********************************
uart 接收 发送 中断使能配置函数
功能:uart 接收 发送 中断使能配置
输入：串口号，中断使能，状态
********************************/
void UART_UARTIE_RxTxIE_SetableEx(UARTx_Type* UARTx, UART_IntTypeDef IntType, FunState NewState)
{
	uint32_t shiftbit;
	
	shiftbit = ((uint32_t)UARTx - UART0_BASE)>>4;
	
	if( RxInt == IntType)
	{
		shiftbit = shiftbit + 1;
	}

	if( ENABLE == NewState )
	{
		UART->UARTIE |= 0x00000001<<shiftbit;
	}
	else
	{
		UART->UARTIE &= ~(0x00000001<<shiftbit);
	}
}


/********************************
uart 接收 发送 中断使能读取函数
功能:读取uart 接收 发送 中断使能
输出：串口号，中断使能状态
********************************/
FunState UART_UARTIE_RxTxIE_GetableEx(UARTx_Type* UARTx, UART_IntTypeDef IntType)
{
	FunState tmpstate;
	uint32_t shiftbit;
	
	shiftbit = ((uint32_t)UARTx - UART0_BASE)>>4;
	
	if( RxInt == IntType)
	{
		shiftbit = shiftbit + 1;
	}

	if(UART->UARTIE & (0x00000001<<shiftbit))
	{
		tmpstate = ENABLE;
	}
	else
	{
		tmpstate = DISABLE;
	}
	
	return tmpstate;
}

/********************************
	uart 发送 中断标志清零函数
	接收中断标志 只能 通过读rxreg清零
	发送中断标志可通过写txreg或者txif写1清零
********************************/
void UART_UARTIF_RxTxIF_ClrEx(UARTx_Type* UARTx)
{
	uint32_t shiftbit;
	
	shiftbit = ((uint32_t)UARTx - UART0_BASE)>>4;
	
	UART->UARTIF = 0x00000001<<shiftbit;
}

/********************************
uart 接收 发送 中断标志读取函数
功能:读取uart 接收 发送 中断标志
输出：串口号，中断标志
********************************/
FlagStatus UART_UARTIF_RxTxIF_ChkEx(UARTx_Type* UARTx, UART_IntTypeDef IntType)
{
	FlagStatus tmpstate;
	uint32_t shiftbit;
	
	shiftbit = ((uint32_t)UARTx - UART0_BASE)>>4;
	
	if( RxInt == IntType)
	{
		shiftbit = shiftbit + 1;
	}

	if(UART->UARTIF & (0x00000001<<shiftbit))
	{
		tmpstate = SET;
	}
	else
	{
		tmpstate = RESET;
	}
	
	return tmpstate;
}

/********************************
红外调制频率占空比配置函数
功能:红外调制频率占空比配置函数
输入：红外调制频率占空比配置
********************************/
void UART_IRModulation_Init( uint32_t ModuFreq, uint8_t ModuDutyCycle, uint32_t APBClk )
{
	uint32_t tempTZBRG, tempTH;
	
	if((ModuFreq > 0)&&(APBClk >= ModuFreq)&&(ModuDutyCycle < 100))
	{
		tempTZBRG = (uint32_t)((float)APBClk/(float)ModuFreq + 0.5) - 1;
		UART_IRCON_TZBRG_Set((tempTZBRG&UART_IRCON_TZBRG_Msk)<<UART_IRCON_TZBRG_Pos);//红外调制频率配置
		
		if((tempTZBRG>>4) != 0)
		{
			
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*((float)(tempTZBRG + 1)/(float)(tempTZBRG>>4)) + 0.5);
		}
		else
		{
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*(float)(tempTZBRG + 1) + 0.5);
			
		}
		UART_IRCON_TH_Set((tempTH<<UART_IRCON_TH_Pos)&UART_IRCON_TH_Msk);//红外调制占空比配置
	}
}

/********************************
UART完整参数初始化函数
功能:UART完整参数初始化
输入：串口号 参数
********************************/
void UART_Init(UARTx_Type* UARTx, UART_InitTypeDef* para)
{
	UARTx_SPBRG_Write(UARTx, para->SPBRG);		//波特率产生器寄存器

	UARTx_RXSTA_PDSEL_Set(UARTx, para->PDSEL);		//模式选择，00 = 8位数据，无奇偶校验；01 = 8位数据，偶校验；10 = 8位数据，奇校验。11 = 9位数据， 无奇偶校验；
	UARTx_RTXCON_RTX7EN_Setable(UARTx, para->RTX7EN);		//收发7bit数据使能(覆盖PDSEL)
	
	UARTx_TXSTA_STOPSEL_Set(UARTx, para->STOPSEL);	//停止位选择
	
	UARTx_RXSTA_ERRIE_Setable(UARTx, para->ERRIE);		//错误中断使能控制
	UARTx_TXSTA_TXIS_Set(UARTx, para->TXIS);		//TX_INTSEL=0时，发送中断选择位
	UARTx_TXBUFSTA_TX_INTSEL_Set(UARTx, para->TX_INTSEL);	//发送中断选择位

	UART_UARTIE_RxTxIE_SetableEx(UARTx, RxInt, para->RXIE);		//接收中断
	UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, para->TXIE);		//发送中断
	
	UARTx_RTXCON_RXDFLAG_Setable(UARTx, para->RXDFLAG);	//接收数据取反控制位
	UARTx_RTXCON_TXDFLAG_Setable(UARTx, para->TXDFLAG);	//发送数据取反控制位

	UARTx_RXSTA_RXEN_Setable(UARTx, para->RXEN);		//接收模块使能控制
	UARTx_TXSTA_TXEN_Setable(UARTx, para->TXEN);		//发送模块使能控制
	UARTx_TXSTA_IREN_Setable(UARTx, para->IREN);		//发送红外调制使能位
}

/********************************
uart波特率寄存器值计算函数
功能:计算uart波特率
输入：uart波特率，主频率
********************************/
uint32_t UART_BaudREGCalc(uint32_t BaudRate, uint32_t APBClk)
{
	uint32_t tmpSPBRG;
	float tmpfloat;
	
	tmpfloat = (float)APBClk/(float)BaudRate;
	
	if(tmpfloat > 1)
	{
		tmpSPBRG = (uint32_t)(tmpfloat - 1.0 + 0.5);
	}
	else
	{
		tmpSPBRG = 0;
	}
	
	return tmpSPBRG;
}

/********************************
UART简单参数初始化函数函数
功能:UART简单参数初始化
输入：串口号 参数
********************************/
void UART_SInit(UARTx_Type* UARTx, UART_SInitTypeDef* para, uint32_t APBClk)
{
	UART_InitTypeDef para2;
		
	para2.SPBRG = UART_BaudREGCalc(para->BaudRate, APBClk);
		
	para2.RTX7EN = DISABLE;
	if(Eight8Bit == para->DataBit)
	{
		if(EVEN == para->ParityBit)
		{
			para2.PDSEL = UARTx_RXSTA_PDSEL_8BIT_EVEN;//8bit偶校验
		}
		else if(ODD == para->ParityBit)
		{
			para2.PDSEL = UARTx_RXSTA_PDSEL_8BIT_ODD;//8bit奇校验
		}
		else
		{
			para2.PDSEL = UARTx_RXSTA_PDSEL_8BIT_NONE;//8bit数据无校验
		}
	}
	else if(Nine9Bit == para->DataBit)
	{
		para2.PDSEL = UARTx_RXSTA_PDSEL_9BIT_NONE;//9bit数据仅支持无校验模式
	}
	else
	{
		para2.PDSEL = UARTx_RXSTA_PDSEL_8BIT_NONE;//7bit配置会直接覆盖其他配置
		para2.RTX7EN = ENABLE;//收发7bit数据使能(覆盖PDSEL)
	}
	
	if(OneBit == para->StopBit)
	{
		para2.STOPSEL = UARTx_TXSTA_STOPSEL_1STOPBIT;
	}
	else
	{
		para2.STOPSEL = UARTx_TXSTA_STOPSEL_2STOPBIT;
	}
	
	para2.RXIE = DISABLE;		//关闭接收中断
	para2.TXIE = DISABLE;		//关闭发送中断
	para2.ERRIE = DISABLE;		//关闭错误中断

	para2.TXIS = UARTx_TXSTA_TXIS_SHIFTEMPTY;		//TX_INTSEL=0时，发送中断选择位
	para2.TX_INTSEL = UARTx_TXBUFSTA_TX_INTSEL_BYTXIS;	//发送中断选择位	
	
	para2.RXDFLAG = DISABLE;	//关闭接收数据取反控制位
	para2.TXDFLAG = DISABLE;	//关闭发送数据取反控制位

	para2.RXEN = DISABLE;		//关闭接收模块使能控制
	para2.TXEN = DISABLE;		//关闭发送模块使能控制
	para2.IREN = DISABLE;		//关闭发送红外调制使能位
	
	UART_Init(UARTx, &para2);
}

/******END OF FILE****/

