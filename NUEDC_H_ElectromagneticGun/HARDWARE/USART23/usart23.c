///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-����2��3����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ�����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "usart23.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint8_t  	USART2_Buf[USART2_MAX_LEN];
uint8_t  	USART3_Buf[USART3_MAX_LEN];
float    	RangeFinding;
uint8_t   RangeFinding_CMD,RangeFinding_flag;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
  ���ܣ�	����2��ʼ�������������ų�ʼ��
  ������	bound ������
  ���أ�	��
  ��ע��	�����뼤����ģ��ͨ��
*********************************************************************************/
void USART2_Init(u32 bound)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		RangeFinding_ContinuityCMD=1;

    NVIC_InitStructure.NVIC_IRQChannel						       = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate						= bound;
    USART_InitStructure.USART_WordLength					= USART_WordLength_8b;
    USART_InitStructure.USART_StopBits						= USART_StopBits_1;
    USART_InitStructure.USART_Parity						  = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode                = USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(USART2, &USART_InitStructure);

    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART2, ENABLE);
}
/********************************************************************************
  ���ܣ�	����3��ʼ��
  ������	bound ������
  ���أ�	��
  ��ע��	����DMA������ж�
*********************************************************************************/
void USART3_Init(u32 bound)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    DMA_InitTypeDef   DMA_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel						        = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority			    = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd					        = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_StructInit(&USART_InitStructure);
    USART_InitStructure.USART_BaudRate						= bound;
    USART_InitStructure.USART_WordLength					= USART_WordLength_8b;
    USART_InitStructure.USART_StopBits						= USART_StopBits_1;
    USART_InitStructure.USART_Parity						  = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode							  = USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(USART3, &USART_InitStructure);

    USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);
    USART_Cmd(USART3, ENABLE);

    DMA_StructInit(&DMA_InitStructure);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(USART3->DR));   //DMA�������ַ
    DMA_InitStructure.DMA_MemoryBaseAddr     = (uint32_t)USART3_Buf;        //DMA�ڴ����ַ
    DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize         = USART3_MAX_LEN;
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority           = DMA_Priority_Medium;
    DMA_InitStructure.DMA_M2M                = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel3, &DMA_InitStructure);
		
    DMA_ClearFlag(DMA1_FLAG_GL3);
    DMA_Cmd(DMA1_Channel3, ENABLE);
		
    USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);
}
/********************************************************************************
  ���ܣ�	��ʼ���
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void RangeFinding_Start(void)
{
	RangeFinding_CMD=1;                                //ʹ�ܱ�־λ
	RangeFinding_ContinuityCMD=0;                      //ʹ�������������
	USART_SendData(USART2,'F');												 //���Ͳ��ָ��
	while((USART2->SR&0X40)==0);                       //�ȴ��������
}
/********************************************************************************
  ���ܣ�	���β��
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void RangeFinding_Single(void)
{
	RangeFinding_flag=0;
	RangeFinding_CMD=2;                                //ʹ�ܱ�־λ
	USART_SendData(USART2,'F');												 //���Ͳ��ָ��
	while((USART2->SR&0X40)==0);                       //�ȴ��������
	while(RangeFinding_flag<=1);
}
/********************************************************************************
  ���ܣ�	ֹͣ���
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void RangeFinding_Stop(void)
{
	RangeFinding_CMD=0;                                //ʹ�ܱ�־λ
	RangeFinding_ContinuityCMD=1;                      //ʹ�������������
}
/********************************************************************************
  ���ܣ�	����2�жϷ�����
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void USART2_IRQHandler(void)
{
	u8 Res;
	static u8 CNT=0,ResFlag=0;
	if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		Res=USART_ReceiveData(USART2);
		
		if(Res==':'){ResFlag=1;CNT=0;return;}
		if(Res=='m'){ResFlag=0;return;}
		if(Res=='\n')
		{
			if(RangeFinding_CMD==1)
			{
				USART_SendData(USART2,'F');
				while((USART2->SR&0X40)==0);
			}
			if(RangeFinding_CMD==2)
			{
				USART_SendData(USART2,'F');
				while((USART2->SR&0X40)==0);
				RangeFinding_CMD=0;
			}
			return;
		}
		
		if(ResFlag==1)
			switch(CNT++)
			{
				case 0:
					if(Res=='E')
					{
						ResFlag=0;
						return;
					}
					else if(Res==' ')
					{
						RangeFinding=0;
						return;
					}
					else
					{
						RangeFinding =(Res-'0')*10;
						return;
					}
				case 1:
					RangeFinding+=(Res-'0');
					return;
				case 2:
					return;
				case 3:
					RangeFinding+=(Res-'0')/10.0;
					return;
				case 4:
					RangeFinding+=(Res-'0')/100.0;
					return;
				case 5:
					RangeFinding+=(Res-'0')/1000.0;
					RangeFinding_flag++;
					return;
			}
		
	}
}
/********************************************************************************
  ���ܣ�	����3�жϷ�����
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void USART3_IRQHandler(void)
{
//    uint8_t DATA_LEN;//�յ������ݳ���
    if (USART_GetITStatus(USART3, USART_IT_IDLE) != RESET)     //�����ж�
    {
        USART3->SR;
        USART3->DR;                                            //��������ж�
        DMA_Cmd(DMA1_Channel3, DISABLE);                       //�ر�DMA

//        DATA_LEN = USART2_MAX_LEN - DMA_GetCurrDataCounter(DMA1_Channel6);
			
			
				/////////////////////////�������д������ݴ�������/////////////////////////
				
				///////////////////////////////////END///////////////////////////////////

        DMA_SetCurrDataCounter(DMA1_Channel3, USART3_MAX_LEN); //�������ü���
        DMA_ClearFlag(DMA1_FLAG_GL3);                          //�����־λ
        DMA_ClearFlag(DMA1_FLAG_TC3);
        DMA_ClearFlag(DMA1_FLAG_TE3);
        DMA_Cmd(DMA1_Channel3, ENABLE);                        //���´�DMA
    }
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
