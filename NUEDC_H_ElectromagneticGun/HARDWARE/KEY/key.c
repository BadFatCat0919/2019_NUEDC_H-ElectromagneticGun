///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "key.h"
/********************************************************************************
  ���ܣ�	������ʼ��
  ������	��
  ���أ�	��
  ��ע��	��
*********************************************************************************/
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;                     //������ʼ���ṹ��
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);     //��GPIOʱ��

  GPIO_StructInit(&GPIO_InitStructure);                    //Ϊ��ʼ���ṹ�帳ȱʡֵ
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|    //���ó�ʼ�����ű��
                                 GPIO_Pin_2|GPIO_Pin_3|
                                 GPIO_Pin_4|GPIO_Pin_5|
                                 GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;            //����IOģʽΪ��������
  GPIO_Init(GPIOD, &GPIO_InitStructure);							     //��ȡ��ʼ���ṹ���ֵ
}
/********************************************************************************
  ���ܣ�	ɨ���߸�����
  ������	��
  ���أ�	��ֵ
  ��ע��	����ʱ���ͨ��KEY_FILTER����
*********************************************************************************/
uint8_t KEY_Scan(void)
{
  uint8_t value=0;                                          //���ü�ֵȱʡΪ0
  
  if ( KEY_OK   == KEY_PRESS || KEY_BACK  == KEY_PRESS ||
       KEY_UP   == KEY_PRESS || KEY_LEFT  == KEY_PRESS ||
       KEY_DOWN == KEY_PRESS || KEY_RIGHT == KEY_PRESS ||
       KEY_USER == KEY_PRESS )
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if      (KEY_UP 		== KEY_PRESS)value = __KEY_UP;      //�жϼ�ֵ
    else if (KEY_DOWN 	== KEY_PRESS)value = __KEY_DOWN;
    else if (KEY_LEFT 	== KEY_PRESS)value = __KEY_LEFT;
    else if (KEY_RIGHT	== KEY_PRESS)value = __KEY_RIGHT;
    else if (KEY_OK 		== KEY_PRESS)value = __KEY_OK;
    else if (KEY_BACK	  == KEY_PRESS)value = __KEY_BACK;
    else if (KEY_USER	  == KEY_PRESS)value = __KEY_USER;
  }
  
  while( KEY_OK   == KEY_PRESS || KEY_BACK  == KEY_PRESS || //�ȴ������ͷ�
         KEY_UP   == KEY_PRESS || KEY_LEFT  == KEY_PRESS ||
         KEY_DOWN == KEY_PRESS || KEY_RIGHT == KEY_PRESS ||
         KEY_USER == KEY_PRESS  );
  
  return value;                                             //���ؼ�ֵ
}
/********************************************************************************
  ���ܣ�	ɨ���û��Զ��尴��
  ������	��
  ���أ� 1 ������
        0 δ����
  ��ע��	������������ʱ���ͨ��KEY_FILTER����
*********************************************************************************/
uint8_t KEY_USER_Scan(void)
{
  if(KEY_USER == KEY_PRESS)                                 //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_USER == KEY_PRESS)
    {
      while(KEY_USER == KEY_PRESS);                         //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��OK��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_OK_Scan(void)
{
  if(KEY_OK == KEY_PRESS)                                   //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_OK == KEY_PRESS)
    {
      while(KEY_OK == KEY_PRESS);                           //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��BACK��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_BACK_Scan(void)
{
  if(KEY_BACK == KEY_PRESS)                                 //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_BACK == KEY_PRESS)
    {
      while(KEY_BACK == KEY_PRESS);                         //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��UP��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_UP_Scan(void)
{
  if(KEY_UP == KEY_PRESS)                                   //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_UP == KEY_PRESS)
    {
      while(KEY_UP == KEY_PRESS);                           //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��RIGHT��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_RIGHT_Scan(void)
{
  if(KEY_RIGHT == KEY_PRESS)                                //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_RIGHT == KEY_PRESS)
    {
      while(KEY_RIGHT == KEY_PRESS);                        //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��DOWN��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_DOWN_Scan(void)
{
  if(KEY_DOWN == KEY_PRESS)                                 //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_DOWN == KEY_PRESS)
    {
      while(KEY_DOWN == KEY_PRESS);                         //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  ���ܣ�	ɨ��LEFT��
  ������	��
  ���أ�	1	������
        0 δ����
  ��ע��	��
*********************************************************************************/
uint8_t KEY_LEFT_Scan(void)
{
  if(KEY_LEFT == KEY_PRESS)                                 //�жϰ����Ƿ���
  {
    delay_ms(KEY_FILTER);                                   //����
    
    if(KEY_LEFT == KEY_PRESS)
    {
      while(KEY_LEFT == KEY_PRESS);                         //�ȴ������ͷ�
      return 1;
    }
  }
  
  return 0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
