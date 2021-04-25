///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-�̵�������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ�����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "relay.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint16_t RelayTime=900;
/********************************************************************************
  ���ܣ�	�̵������ų�ʼ��
  ������	��
  ���أ�	��
  ��ע��	�ߵ�ƽ����
*********************************************************************************/
void RELAY_Init()
{
  GPIO_InitTypeDef  GPIO_InitStructure;										//������ʼ���ṹ��
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
                                                          //��GPIOʱ��
  GPIO_StructInit(&GPIO_InitStructure);                   //Ϊ��ʼ���ṹ�帳ȱʡֵ
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_5;             //���ó�ʼ�����ű��
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;       //����IOģʽΪ�������
  GPIO_Init(GPIOC, &GPIO_InitStructure);							    //��ȡ��ʼ���ṹ���ֵ
  
  RELAY = RELAY_OFF;                                      //IO��ʼ����ɺ�ر�LED
}
/********************************************************************************
	���ܣ�	�̵������ƿ���
	������	��
	���أ�	��
	��ע��	��
*********************************************************************************/
void Gun_Fire(void)
{
	RELAY=RELAY_ON;
	delay_ms(RelayTime);
	RELAY=RELAY_OFF;
}
/********************************************************************************
	���ܣ�	�̵������ƿ���
	������	��
	���أ�	��
	��ע��	��
*********************************************************************************/
void Gun_Fire_Hold(void)
{
	static u8 cmd=0;
	cmd=!cmd;
	RELAY=cmd;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///