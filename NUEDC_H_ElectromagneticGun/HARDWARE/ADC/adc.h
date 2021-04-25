///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-ADC驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __ADC_H
#define __ADC_H
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern  uint16_t ADC_BUFF[8];      //ADC读数缓存
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*映射ADC缓存数组元素与ADC各通道*/
#define	ADC_IN4	  ADC_BUFF[0]     //PA4
#define	ADC_IN5	  ADC_BUFF[1]     //PA5
#define	ADC_IN10	ADC_BUFF[2]     //PC0
#define	ADC_IN11	ADC_BUFF[3]     //PC1
#define	ADC_IN12	ADC_BUFF[4]     //PC2
#define	ADC_IN13	ADC_BUFF[5]     //PC3
#define	ADC_IN14	ADC_BUFF[6]     //PC4
#define	ADC_IN15	ADC_BUFF[7]     //PC5
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void ADC1_Init(void);           //ADC初始化
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
