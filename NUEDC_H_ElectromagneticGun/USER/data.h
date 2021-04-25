///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-数据处理
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __DATA_H
#define __DATA_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
#include "pid.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置PID数据存储的flash页面及数据宽度*/
#define PID_DATA_PAGE   ADDR_FLASH_PAGE_127
#define PID_DATA_LENGTH 10
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置PIDA默认参数*/
#define PIDA_Default_Kp           100 //菜单中点击default以后的Kp值
#define PIDA_Default_Ki           0   //菜单中点击default以后的Ki值
#define PIDA_Default_Kd           0   //菜单中点击default以后的Kd值
#define PIDA_Default_KiSec_Inner  5   //菜单中点击default以后的KiSec_Inner值
#define PIDA_Default_KiSec_Width  30  //菜单中点击default以后的KiSec_Width值
/*设置PIDB默认参数*/
#define PIDB_Default_Kp           100 //菜单中点击default以后的Kp值
#define PIDB_Default_Ki           0   //菜单中点击default以后的Ki值
#define PIDB_Default_Kd           0   //菜单中点击default以后的Kd值
#define PIDB_Default_KiSec_Inner  5   //菜单中点击default以后的KiSec_Inner值
#define PIDB_Default_KiSec_Width  30  //菜单中点击default以后的KiSec_Width值
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern MyPID PIDA,PIDB; //定义PID结构体
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void DATA_Load(void);   //加载数据
void PIDA_Save(void);    //储存PID参数
void PIDA_Load(void);    //加载PID参数
void PIDA_Default(void); //加载PID缺省参数
void PIDB_Save(void);    //储存PID参数
void PIDB_Load(void);    //加载PID参数
void PIDB_Default(void); //加载PID缺省参数
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
