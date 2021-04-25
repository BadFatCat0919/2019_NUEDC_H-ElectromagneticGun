///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-数据处理
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "data.h"
#include "flash.h"
#include "main.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
MyPID    PIDA,PIDB;
uint16_t PID_DATA[PID_DATA_LENGTH];
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    功能：	加载数据
    参数：	无
    返回：	无
    备注：	从flash中读取储存的参数
*********************************************************************************/
void DATA_Load(void)
{
  PIDA_Load();
  PIDB_Load();
}
/********************************************************************************
    功能：	储存PIDA参数
    参数：	无
    返回：	无
    备注：	将PIDA参数存进flash
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
    功能：	加载PIDA参数
    参数：	无
    返回：	无
    备注：	从flash中读取储存的PIDA参数
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
    功能：	设置缺省PIDA参数
    参数：	无
    返回：	无
    备注：	设置为data.h中的缺省值
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
    功能：	储存PIDB参数
    参数：	无
    返回：	无
    备注：	将PIDB参数存进flash
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
    功能：	加载PIDB参数
    参数：	无
    返回：	无
    备注：	从flash中读取储存的PIDB参数
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
    功能：	设置缺省PIDA参数
    参数：	无
    返回：	无
    备注：	设置为data.h中的缺省值
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
