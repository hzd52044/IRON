#ifndef	__DEFINEALL_H__
#define __DEFINEALL_H__

//定义常量, 常数
extern unsigned char TimeCount;

extern unsigned char MS_50_FLAG;
extern unsigned char MS_100_FLAG;
extern unsigned char MS_300_FLAG;
extern unsigned char MS_500_FLAG;
extern unsigned char SECOND__FLAG;

extern unsigned char Run_LED_Process;	//执行刷新LED任务
extern unsigned char Run_Display_Process; 
extern unsigned char Run_Key_Process;
extern unsigned char Run_ADC_Process;


//显示变量

extern unsigned char   zk_hz14[];
extern unsigned char   zk_hz12[];
extern unsigned char   asc36[];
extern unsigned char kWh[];
extern unsigned char kW[];
extern unsigned char W[];
extern unsigned char V[];
extern unsigned char A[];
extern unsigned char C[];
extern unsigned char mA[];
extern unsigned char VA[];
extern unsigned char MY[];
extern unsigned char BC[];
extern unsigned char XS[];
extern unsigned char DH[];
extern unsigned char DC[];
extern unsigned char FX[];
extern unsigned char ZB[];
extern unsigned char FLV[];
extern unsigned char JTV[];

#define true  0xA5
#define fault 0x5A

union  WORD_UN
{
    unsigned int  vv;
    unsigned char v[2];
};

struct VALUE_STRUCT
{
    unsigned char  width;
    unsigned char    xsd;
    unsigned char      x;
    unsigned char      y;
    unsigned long       v;
    unsigned char    len;
    unsigned char  lenbk;
};

struct DISPALY_FRM
{
    unsigned char      Number;             //显示号
    unsigned char      Timer;              //显示时间
    unsigned char      Status;             //状态
};

extern unsigned char  china_page/*汉字显示标志*/,hextohex_flag;
extern unsigned char  noflash,changes,len_change; /*实时页面不刷新、实时页面切换刷新标志*/
extern unsigned char  tmp_len;
extern unsigned char  tmp_int[8];

extern unsigned char    asc16_flag;
extern unsigned char    china_edit_flag;
extern unsigned char    china_md_flag;
extern unsigned char   select_state;           /*编辑状态标志  */

extern unsigned char asc_val[20];
                 /* 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F  S, D, G, T*/
extern unsigned char asc_val36[13];
                 /* 0  1  2  3  4  5  6  7  8  9  .  - :  */
                 
extern unsigned int tmp_string[8];  /*数据展开缓冲区*/
				 
extern unsigned char Disp_page;

extern unsigned char LCM_DDRAM[10][160];  

extern unsigned char mouse_flag;
extern unsigned char mouse_x,mouse_y;


extern struct VALUE_STRUCT *current_val_pointer; 
extern struct VALUE_STRUCT *edit_val_pointer;
extern struct VALUE_STRUCT password_val;    //密码问题  wd宽度 xsd 小数点 xx  yy   位置   数据1111
//struct VALUE_STRUCT disptemp_val={8,07,1,16,15555555};   //长度不能使用08
extern struct VALUE_STRUCT disptemp_val;

extern struct  DISPALY_FRM     Display;

extern float Temperature;
extern unsigned long SetTemperature;
extern unsigned long IronTemperature;
extern unsigned char SetTemperature_Count;


//系统时钟默认使用RCHF
#define RCHFCLKCFG	8	//8, 16, 24, 30MHz

//define_all.h中RCHFCLKCFG控制系统时钟
#if( RCHFCLKCFG == 8 )//8.0MHz
#define clkmode   1
#define SYSCLKdef RCC_RCHFCON_FSEL_8MHZ//RCHF中心频率8MHz
#elif( RCHFCLKCFG == 16 )//16.0MHz
#define clkmode   2
#define SYSCLKdef RCC_RCHFCON_FSEL_16MHZ//RCHF中心频率16MHz
#elif( RCHFCLKCFG == 24 )//24.0MHz
#define clkmode   3
#define SYSCLKdef RCC_RCHFCON_FSEL_24MHZ//RCHF中心频率24MHz
#elif( RCHFCLKCFG == 30 )//30.0MHz
#define clkmode   4
#define SYSCLKdef RCC_RCHFCON_FSEL_30MHZ//RCHF中心频率30MHz
#endif

/*变量类型定义*/
typedef union
{
  unsigned char B08;
  struct
  {
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
  }Bit;
}B08_Bit;
#define	uint08 uint8_t
#define	uint16 uint16_t
#define uint32 uint32_t
#define	int08 int8_t		
#define	int16 int16_t
#define	int32 int32_t

/*功能IO宏定义*/
#define LED0_GPIO		GPIOA	//原定义 GPIOB			//PA3  LED3 
#define LED0_PIN		GPIO_Pin_3	//原定义 GPIO_Pin_6		//PA4  LED4

#define LED1_GPIO		GPIOA	//原定义 GPIOB			//PA3  LED3 
#define LED1_PIN		GPIO_Pin_4	//原定义 GPIO_Pin_6		//PA4  LED4

#define KEY0_GPIO		GPIOA
#define KEY0_PIN		GPIO_Pin_13

#define KEY1_GPIO		GPIOA
#define KEY1_PIN		GPIO_Pin_12

#define LCDPOWER_GPIO		GPIOC
#define LCDPOWER_PIN		GPIO_Pin_3

#define LCDCS_GPIO		GPIOC
#define LCDCS_PIN		GPIO_Pin_6

#define LCDA0_GPIO		 GPIOC
#define LCDA0_PIN		GPIO_Pin_15

#define LCDRST_GPIO		 GPIOC
#define LCDRST_PIN		GPIO_Pin_14	

#define LCDSCL_GPIO		GPIOC
#define LCDSCL_PIN		GPIO_Pin_7

#define LCDSDA_GPIO		GPIOC
#define LCDSDA_PIN		GPIO_Pin_9

#define LCDBACKLIGHT_GPIO		GPIOG
#define LCDBACKLIGHT_PIN		GPIO_Pin_6


/*操作宏定义*/
#define LED0_ON			GPIO_ResetBits(LED0_GPIO, LED0_PIN)
#define LED0_OFF		GPIO_SetBits(LED0_GPIO, LED0_PIN)
#define LED0_TOG		GPIO_ToggleBits(LED0_GPIO, LED0_PIN)

#define LED1_ON			GPIO_ResetBits(LED1_GPIO, LED1_PIN)
#define LED1_OFF		GPIO_SetBits(LED1_GPIO, LED1_PIN)
#define LED1_TOG		GPIO_ToggleBits(LED1_GPIO, LED1_PIN)

#define KEY0_P 			(SET == GPIO_ReadInputDataBit(KEY0_GPIO, KEY0_PIN))
#define KEY0_N 			(RESET == GPIO_ReadInputDataBit(KEY0_GPIO, KEY0_PIN))

#define KEY1_P 			(SET == GPIO_ReadInputDataBit(KEY1_GPIO, KEY1_PIN))
#define KEY1_N 			(RESET == GPIO_ReadInputDataBit(KEY1_GPIO, KEY1_PIN))

#define LcdPowerClos		GPIO_SetBits(LCDPOWER_GPIO, LCDPOWER_PIN)
#define LcdPowerOpen	GPIO_ResetBits(LCDPOWER_GPIO, LCDPOWER_PIN)

#define LcdCLKHigh		GPIO_SetBits(LCDSCL_GPIO, LCDSCL_PIN)
#define LcdCLKLow		GPIO_ResetBits(LCDSCL_GPIO, LCDSCL_PIN)

#define LcdSDAHigh		GPIO_SetBits(LCDSDA_GPIO, LCDSDA_PIN)
#define LcdSDALow		GPIO_ResetBits(LCDSDA_GPIO, LCDSDA_PIN)

#define LcdCSHigh		GPIO_SetBits(LCDCS_GPIO, LCDCS_PIN)
#define LcdCSLow		GPIO_ResetBits(LCDCS_GPIO, LCDCS_PIN)

#define LcdA0High		GPIO_SetBits(LCDA0_GPIO, LCDA0_PIN)
#define LcdA0Low		GPIO_ResetBits(LCDA0_GPIO, LCDA0_PIN)

#define LcdRSTHigh		GPIO_SetBits(LCDRST_GPIO, LCDRST_PIN)
#define LcdRSTLow		GPIO_ResetBits(LCDRST_GPIO, LCDRST_PIN)

#define BackLampOpen		GPIO_ResetBits(LCDBACKLIGHT_GPIO, LCDBACKLIGHT_PIN)
#define BackLampClos		GPIO_SetBits(LCDBACKLIGHT_GPIO, LCDBACKLIGHT_PIN)

#define EA_OFF	((__get_PRIMASK()&0x00000001) == 0x00000001)
#define EA_ON	((__get_PRIMASK()&0x00000001) == 0x00000000)


/* GPIO配置函数参数宏定义 */
//IO输入口配置 
//type 0 = 普通 
//type 1 = 上拉
#define IN_NORMAL	0
#define IN_PULLUP	1

//IO输出口配置 
//type 0 = 普通 
//type 1 = OD
#define OUT_PUSHPULL	0
#define OUT_OPENDRAIN	1

//IO数字特殊功能口 
//type 0 = 普通 
//type 1 = OD (OD功能仅部分特殊功能支持)
//type 2 = 普通+上拉 
//type 3 = OD+上拉
#define ALTFUN_NORMAL			0
#define ALTFUN_OPENDRAIN		1
#define ALTFUN_PULLUP			2
#define ALTFUN_OPENDRAIN_PULLUP	3


/*include*/
#include "FM33A0XX.h"
#include "fm33a0xx_include_all.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "bintohex.h"
#include "user_init.h"

extern BTIM_InitTypeDef adjustment_para;	//参数调节变量

extern void ADC_IO_Init(void);
extern void ADC_Init_TsetExVolt(void);
extern void ADC_Init_TsetTemperature(void);
extern uint08 ADC_Wait_Finish(void);
extern float Test_ADC_ExVolt(void);
extern float Test_ADC_ExVolt2(void);
extern float Test_ADC_Temperature(void);

extern void initLCDM(void);
extern void LCD_Fulldisplay(void);
extern void LCD_on(void);
extern void Lcd_Display(void);  
extern void show_asc36(unsigned char x,unsigned char y,unsigned char c,unsigned char xs);

#endif



