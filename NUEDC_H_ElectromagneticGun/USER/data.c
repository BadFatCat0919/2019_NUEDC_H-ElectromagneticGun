///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-���ݴ���
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "data.h"
#include "flash.h"
#include "main.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
MyPID    PIDA,PIDB;
uint16_t PID_DATA[PID_DATA_LENGTH];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    ���ܣ�	��������
    ������	��
    ���أ�	��
    ��ע��	��flash�ж�ȡ����Ĳ���
*********************************************************************************/
void DATA_Load(void)
{
  PIDA_Load();
  PIDB_Load();
}
/********************************************************************************
    ���ܣ�	����PIDA����
    ������	��
    ���أ�	��
    ��ע��	��PIDA�������flash
*********************************************************************************/
void PIDA_Save(void)
{
	PID_DATA[0] = PIDA.Kp;
	PID_DATA[1] = PIDA.Ki;
	PID_DATA[2] = PIDA.Kd;
	PID_DATA[3] = PIDA.KiSec_Inner;
	PID_DATA[4] = PIDA.KiSec_Width;
	
  STMFLASH_Write(PID_DATA_PAGE,PID_DATA,PID_DATA_LENGTH);
}
/********************************************************************************
    ���ܣ�	����PIDA����
    ������	��
    ���أ�	��
    ��ע��	��flash�ж�ȡ�����PIDA����
*********************************************************************************/
void PIDA_Load(void)
{
  STMFLASH_Read(PID_DATA_PAGE,PID_DATA,PID_DATA_LENGTH);
	
	PIDA.Kp          = PID_DATA[0];
	PIDA.Ki          = PID_DATA[1];
	PIDA.Kd          = PID_DATA[2];
	PIDA.KiSec_Inner = PID_DATA[3];
	PIDA.KiSec_Width = PID_DATA[4];
}
/********************************************************************************
    ���ܣ�	����ȱʡPIDA����
    ������	��
    ���أ�	��
    ��ע��	����Ϊdata.h�е�ȱʡֵ
*********************************************************************************/
void PIDA_Default(void)
{
  PIDA.Kp          = PIDA_Default_Kp;
  PIDA.Ki          = PIDA_Default_Ki;
  PIDA.Kd          = PIDA_Default_Kd;
  PIDA.KiSec_Inner = PIDA_Default_KiSec_Inner;
  PIDA.KiSec_Width = PIDA_Default_KiSec_Width;
}
/********************************************************************************
    ���ܣ�	����PIDB����
    ������	��
    ���أ�	��
    ��ע��	��PIDB�������flash
*********************************************************************************/
void PIDB_Save(void)
{
	PID_DATA[5] = PIDB.Kp;
	PID_DATA[6] = PIDB.Ki;
	PID_DATA[7] = PIDB.Kd;
	PID_DATA[8] = PIDB.KiSec_Inner;
	PID_DATA[9] = PIDB.KiSec_Width;
	
  STMFLASH_Write(PID_DATA_PAGE,PID_DATA,PID_DATA_LENGTH);
}
/********************************************************************************
    ���ܣ�	����PIDB����
    ������	��
    ���أ�	��
    ��ע��	��flash�ж�ȡ�����PIDB����
*********************************************************************************/
void PIDB_Load(void)
{
  STMFLASH_Read(PID_DATA_PAGE,PID_DATA,PID_DATA_LENGTH);
	
	PIDB.Kp          = PID_DATA[5];
	PIDB.Ki          = PID_DATA[6];
	PIDB.Kd          = PID_DATA[7];
	PIDB.KiSec_Inner = PID_DATA[8];
	PIDB.KiSec_Width = PID_DATA[9];
}
/********************************************************************************
    ���ܣ�	����ȱʡPIDA����
    ������	��
    ���أ�	��
    ��ע��	����Ϊdata.h�е�ȱʡֵ
*********************************************************************************/
void PIDB_Default(void)
{
  PIDB.Kp          = PIDB_Default_Kp;
  PIDB.Ki          = PIDB_Default_Ki;
  PIDB.Kd          = PIDB_Default_Kd;
  PIDB.KiSec_Inner = PIDB_Default_KiSec_Inner;
  PIDB.KiSec_Width = PIDB_Default_KiSec_Width;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
