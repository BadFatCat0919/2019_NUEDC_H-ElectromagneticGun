///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-�˵�
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ�����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __MENU_H
#define __MENU_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "SOLGUI_Include.h"
#include "main.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#define ShowADC(X,Y,ADCX,THRESHOLD)\
        SOLGUI_Widget_Text(X,Y,ADCX>THRESHOLD?R4X6:F4X6,"%04d",ADCX)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///