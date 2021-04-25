///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-���ݴ���
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __DATA_H
#define __DATA_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
#include "pid.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*����PID���ݴ洢��flashҳ�漰���ݿ��*/
#define PID_DATA_PAGE   ADDR_FLASH_PAGE_127
#define PID_DATA_LENGTH 10
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*����PIDAĬ�ϲ���*/
#define PIDA_Default_Kp           100 //�˵��е��default�Ժ��Kpֵ
#define PIDA_Default_Ki           0   //�˵��е��default�Ժ��Kiֵ
#define PIDA_Default_Kd           0   //�˵��е��default�Ժ��Kdֵ
#define PIDA_Default_KiSec_Inner  5   //�˵��е��default�Ժ��KiSec_Innerֵ
#define PIDA_Default_KiSec_Width  30  //�˵��е��default�Ժ��KiSec_Widthֵ
/*����PIDBĬ�ϲ���*/
#define PIDB_Default_Kp           100 //�˵��е��default�Ժ��Kpֵ
#define PIDB_Default_Ki           0   //�˵��е��default�Ժ��Kiֵ
#define PIDB_Default_Kd           0   //�˵��е��default�Ժ��Kdֵ
#define PIDB_Default_KiSec_Inner  5   //�˵��е��default�Ժ��KiSec_Innerֵ
#define PIDB_Default_KiSec_Width  30  //�˵��е��default�Ժ��KiSec_Widthֵ
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern MyPID PIDA,PIDB; //����PID�ṹ��
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void DATA_Load(void);   //��������
void PIDA_Save(void);    //����PID����
void PIDA_Load(void);    //����PID����
void PIDA_Default(void); //����PIDȱʡ����
void PIDB_Save(void);    //����PID����
void PIDB_Load(void);    //����PID����
void PIDB_Default(void); //����PIDȱʡ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
