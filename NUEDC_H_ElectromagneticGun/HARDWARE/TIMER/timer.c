///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-��ʱ������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "timer.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint16_t SE_TOP_TEST  = SE_TOP_MID;
uint16_t SE_BASE_TEST = SE_BASE_MID;
/********************************************************************************
  ���ܣ�	TIM1��ʼ��
  ������	��
  ���أ�	��
  ��ע��	����PWM���
        PWMƵ��=72000000/(Period+1)/(Prescaler+1)
        ������ȫ��ӳ��
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
  ���ܣ�	TIM6��ʱ�жϳ�ʼ��
  ������	��
  ���أ�	��
  ��ע��	Ƶ��=72000000/(Period+1)/(Prescaler+1)
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
    ���ܣ�	����˶���ָ��PWMֵ��
    ������	base �ײ����PWMλ��
          top  �������PWMλ��
          time һ֡���˶�����ʱ
    ���أ�	��
    ��ע��	����Ϊ0ʱ���ı䵱ǰ���λ��
*********************************************************************************/
void SetSE(uint16_t base,uint16_t top,uint16_t time)
{
	uint16_t SE_TOP_NOW,SE_BASE_NOW,i;
	
	SE_TOP_NOW=SE_TOP;
	SE_BASE_NOW=SE_BASE;
	
	if(time==0)//delay_ms������СΪ1�����������
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
