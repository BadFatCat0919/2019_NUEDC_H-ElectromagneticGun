///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-定时器配置
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "timer.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint16_t SE_TOP_TEST  = SE_TOP_MID;
uint16_t SE_BASE_TEST = SE_BASE_MID;
/********************************************************************************
  功能：	TIM1初始化
  参数：	无
  返回：	无
  备注：	用于PWM输出
        PWM频率=72000000/(Period+1)/(Prescaler+1)
        引脚完全重映射
        CH1  PE9
        CH3  PE13
*********************************************************************************/
void TIM1_PWM_Init(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;
  TIM_OCInitTypeDef        TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
  TIM_BDTRInitTypeDef      TIM_BDTRInitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);

  GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9|GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Period        = 10000-1;
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 144-1;
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode       = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState  = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity   = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_OCIdleState  = TIM_OCIdleState_Set;
  TIM_OC1Init(TIM1, &TIM_OCInitStructure);
  TIM_OC3Init(TIM1, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_BDTRStructInit(&TIM_BDTRInitStructure);
  TIM_BDTRInitStructure.TIM_DeadTime        = 0x90;
  TIM_BDTRInitStructure.TIM_BreakPolarity   = TIM_BreakPolarity_High;
  TIM_BDTRConfig(TIM8,&TIM_BDTRInitStructure);

  TIM_ARRPreloadConfig(TIM1, ENABLE);
  TIM_CtrlPWMOutputs(TIM1,ENABLE);
  TIM_Cmd(TIM1, ENABLE);
	
	SE_TOP = SE_TOP_FMAX;
	SE_BASE= SE_BASE_MID;
}
/********************************************************************************
  功能：	TIM6定时中断初始化
  参数：	无
  返回：	无
  备注：	频率=72000000/(Period+1)/(Prescaler+1)
*********************************************************************************/
void TIM6_Interrupt_Init(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  NVIC_InitTypeDef        NVIC_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
  TIM_TimeBaseInitStructure.TIM_Prescaler     = 7200-1;
  TIM_TimeBaseInitStructure.TIM_Period        = 100-1;
  TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseInitStructure.TIM_CounterMode   = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

  NVIC_InitStructure.NVIC_IRQChannel                   = TIM6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  TIM_Cmd(TIM6, ENABLE);
}
/********************************************************************************
    功能：	舵机运动到指定PWM值处
    参数：	base 底部舵机PWM位置
          top  顶部舵机PWM位置
          time 一帧间运动的延时
    返回：	无
    备注：	参数为0时不改变当前舵机位置
*********************************************************************************/
void SetSE(uint16_t base,uint16_t top,uint16_t time)
{
	uint16_t SE_TOP_NOW,SE_BASE_NOW,i;
	
	SE_TOP_NOW=SE_TOP;
	SE_BASE_NOW=SE_BASE;
	
	if(time==0)//delay_ms参数最小为1，否则会死机
		time=1;
	
	if(base!=0)
	{
		if(base>=SE_BASE_LMAX)base=SE_BASE_LMAX;
		if(base<=SE_BASE_RMAX)base=SE_BASE_RMAX;
		if(SE_BASE_NOW>base)
			for(i=SE_BASE_NOW;i>=base;i--)
			{
				SE_BASE=i;
				delay_ms(time);
			}
		else if(SE_BASE_NOW<base)
			for(i=SE_BASE_NOW;i<=base;i++)
			{
				SE_BASE=i;
				delay_ms(time);
			}
	}
	
	if(top!=0)
	{
		if(top>=SE_TOP_FMAX)top=SE_TOP_FMAX;
		if(top<=SE_TOP_BMAX)top=SE_TOP_BMAX;
		if(SE_TOP_NOW>top)
			for(i=SE_TOP_NOW;i>=top;i--)
			{
				SE_TOP=i;
				delay_ms(time);
			}
		else if(SE_TOP_NOW<top)
			for(i=SE_TOP_NOW;i<=top;i++)
			{
				SE_TOP=i;
				delay_ms(time);
			}
	}
	
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
