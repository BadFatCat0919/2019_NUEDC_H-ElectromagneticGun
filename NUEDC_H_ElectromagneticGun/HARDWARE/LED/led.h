///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-LED驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __LED_H__
#define __LED_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置LED触发电平*/
#define LED_ON         0
#define LED_OFF        !LED_ON
/*设置LED占用IO口*/
#define LED1        PBout(5)
#define LED2        PEout(5)
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void LED_Init(void);                  //LED初始化
void LED1_Flash( uint16_t time);   //LED1闪烁
void LED2_Flash( uint16_t time); //LED2闪烁
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
