///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-继电器驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "relay.h"
#include "delay.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
uint16_t RelayTime=900;
/********************************************************************************
  功能：	继电器引脚初始化
  参数：	无
  返回：	无
  备注：	高电平触发
*********************************************************************************/
void RELAY_Init()
{
  GPIO_InitTypeDef  GPIO_InitStructure;										//建立初始化结构体
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
                                                          //打开GPIO时钟
  GPIO_StructInit(&GPIO_InitStructure);                   //为初始化结构体赋缺省值
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_5;             //设置初始化引脚编号
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;       //设置IO模式为推挽输出
  GPIO_Init(GPIOC, &GPIO_InitStructure);							    //读取初始化结构体的值
  
  RELAY = RELAY_OFF;                                      //IO初始化完成后关闭LED
}
/********************************************************************************
	功能：	继电器控制开炮
	参数：	无
	返回：	无
	备注：	无
*********************************************************************************/
void Gun_Fire(void)
{
	RELAY=RELAY_ON;
	delay_ms(RelayTime);
	RELAY=RELAY_OFF;
}
/********************************************************************************
	功能：	继电器控制开炮
	参数：	无
	返回：	无
	备注：	无
*********************************************************************************/
void Gun_Fire_Hold(void)
{
	static u8 cmd=0;
	cmd=!cmd;
	RELAY=cmd;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
