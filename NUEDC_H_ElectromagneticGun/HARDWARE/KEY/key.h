///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-按键驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __KEY_H
#define __KEY_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置按键触发电平*/
#define KEY_PRESS   0
#define KEY_RELEASE ！KEY_PRESS
/*设置按键占用IO口*/
//自改领航板引脚
#define KEY_OK 		PDin(6)
#define KEY_BACK 	PDin(0)
#define KEY_UP 		PDin(4)
#define KEY_DOWN 	PDin(3)
#define KEY_LEFT 	PDin(5)
#define KEY_RIGHT	PDin(2)
#define KEY_USER	PDin(1)
//领航板引脚
//#define KEY_OK 		PDin(5)
//#define KEY_BACK 	PDin(6)
//#define KEY_UP 		PDin(0)
//#define KEY_DOWN 	PDin(2)
//#define KEY_LEFT 	PDin(3)
//#define KEY_RIGHT	PDin(4)
//#define KEY_USER	PDin(1)
/*设置消抖时间（ms）*/
#define KEY_FILTER  3
/*设置按键键值*/
#define __KEY_USER  7
#define __KEY_OK 		1
#define __KEY_BACK 	2
#define __KEY_UP 		3
#define __KEY_DOWN 	4
#define __KEY_LEFT 	5
#define __KEY_RIGHT 6
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void    KEY_Init(void);       //按键初始化
uint8_t	KEY_Scan(void);       //扫描除USER外六个按键
uint8_t KEY_USER_Scan(void);  //扫描用户自定义按键
uint8_t KEY_OK_Scan(void);    //扫描OK键
uint8_t KEY_BACK_Scan(void);  //扫描BACK键
uint8_t KEY_UP_Scan(void);    //扫描UP键
uint8_t KEY_DOWN_Scan(void);  //扫描DOWN键
uint8_t KEY_LEFT_Scan(void);  //扫描LEFT键
uint8_t KEY_RIGHT_Scan(void); //扫描RIGHT键
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
