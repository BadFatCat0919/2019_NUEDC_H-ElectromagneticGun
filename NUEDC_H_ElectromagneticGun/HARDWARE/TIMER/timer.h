///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-��ʱ������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ�����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __TIMER_H
#define __TIMER_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*PWM���ͨ��*/
#define SE_BASE			TIM1->CCR1		//PE9
#define SE_TOP			TIM1->CCR3		//PE13
/*������޽Ƕ�*/
#define SE_BASE_RMAX    (694)
#define SE_BASE_MID     (859)
#define SE_BASE_LMAX    (1021)
#define SE_TOP_FMAX     (704)
#define SE_TOP_MID      (620)
#define SE_TOP_BMAX     (570)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern uint16_t SE_TOP_TEST;
extern uint16_t SE_BASE_TEST;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void PWM_Init(void);            //PWM��ʼ��
void TIM1_PWM_Init(void);       //TIM1��ʼ��
void TIM6_Interrupt_Init(void); //TIM6��ʱ�жϳ�ʼ��
void TIM7_Interrupt_Init(void); //TIM7��ʱ�жϳ�ʼ��
void TIM8_PWM_Init(void);       //TIM8��ʼ��
void SetSE(uint16_t base,uint16_t top,uint16_t time);
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///