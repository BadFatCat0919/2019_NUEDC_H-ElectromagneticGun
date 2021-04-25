///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __KEY_H
#define __KEY_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*���ð���������ƽ*/
#define KEY_PRESS   0
#define KEY_RELEASE ��KEY_PRESS
/*���ð���ռ��IO��*/
//�Ը��캽������
#define KEY_OK 		PDin(6)
#define KEY_BACK 	PDin(0)
#define KEY_UP 		PDin(4)
#define KEY_DOWN 	PDin(3)
#define KEY_LEFT 	PDin(5)
#define KEY_RIGHT	PDin(2)
#define KEY_USER	PDin(1)
//�캽������
//#define KEY_OK 		PDin(5)
//#define KEY_BACK 	PDin(6)
//#define KEY_UP 		PDin(0)
//#define KEY_DOWN 	PDin(2)
//#define KEY_LEFT 	PDin(3)
//#define KEY_RIGHT	PDin(4)
//#define KEY_USER	PDin(1)
/*��������ʱ�䣨ms��*/
#define KEY_FILTER  3
/*���ð�����ֵ*/
#define __KEY_USER  7
#define __KEY_OK 		1
#define __KEY_BACK 	2
#define __KEY_UP 		3
#define __KEY_DOWN 	4
#define __KEY_LEFT 	5
#define __KEY_RIGHT 6
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void    KEY_Init(void);       //������ʼ��
uint8_t	KEY_Scan(void);       //ɨ���USER����������
uint8_t KEY_USER_Scan(void);  //ɨ���û��Զ��尴��
uint8_t KEY_OK_Scan(void);    //ɨ��OK��
uint8_t KEY_BACK_Scan(void);  //ɨ��BACK��
uint8_t KEY_UP_Scan(void);    //ɨ��UP��
uint8_t KEY_DOWN_Scan(void);  //ɨ��DOWN��
uint8_t KEY_LEFT_Scan(void);  //ɨ��LEFT��
uint8_t KEY_RIGHT_Scan(void); //ɨ��RIGHT��
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
