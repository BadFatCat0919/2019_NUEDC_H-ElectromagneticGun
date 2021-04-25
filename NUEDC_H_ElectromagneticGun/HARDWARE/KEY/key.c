///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-按键驱动
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "key.h"
/********************************************************************************
  功能：	按键初始化
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;                     //建立初始化结构体
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);     //打开GPIO时钟

  GPIO_StructInit(&GPIO_InitStructure);                    //为初始化结构体赋缺省值
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|    //设置初始化引脚编号
                                 GPIO_Pin_2|GPIO_Pin_3|
                                 GPIO_Pin_4|GPIO_Pin_5|
                                 GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;            //设置IO模式为上拉输入
  GPIO_Init(GPIOD, &GPIO_InitStructure);							     //读取初始化结构体的值
}
/********************************************************************************
  功能：	扫描七个按键
  参数：	无
  返回：	键值
  备注：	消抖时间可通过KEY_FILTER更改
*********************************************************************************/
uint8_t KEY_Scan(void)
{
  uint8_t value=0;                                          //设置键值缺省为0
  
  if ( KEY_OK   == KEY_PRESS || KEY_BACK  == KEY_PRESS ||
       KEY_UP   == KEY_PRESS || KEY_LEFT  == KEY_PRESS ||
       KEY_DOWN == KEY_PRESS || KEY_RIGHT == KEY_PRESS ||
       KEY_USER == KEY_PRESS )
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if      (KEY_UP 		== KEY_PRESS)value = __KEY_UP;      //判断键值
    else if (KEY_DOWN 	== KEY_PRESS)value = __KEY_DOWN;
    else if (KEY_LEFT 	== KEY_PRESS)value = __KEY_LEFT;
    else if (KEY_RIGHT	== KEY_PRESS)value = __KEY_RIGHT;
    else if (KEY_OK 		== KEY_PRESS)value = __KEY_OK;
    else if (KEY_BACK	  == KEY_PRESS)value = __KEY_BACK;
    else if (KEY_USER	  == KEY_PRESS)value = __KEY_USER;
  }
  
  while( KEY_OK   == KEY_PRESS || KEY_BACK  == KEY_PRESS || //等待按键释放
         KEY_UP   == KEY_PRESS || KEY_LEFT  == KEY_PRESS ||
         KEY_DOWN == KEY_PRESS || KEY_RIGHT == KEY_PRESS ||
         KEY_USER == KEY_PRESS  );
  
  return value;                                             //返回键值
}
/********************************************************************************
  功能：	扫描用户自定义按键
  参数：	无
  返回： 1 被按下
        0 未按下
  备注：	带消抖，消抖时间可通过KEY_FILTER更改
*********************************************************************************/
uint8_t KEY_USER_Scan(void)
{
  if(KEY_USER == KEY_PRESS)                                 //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_USER == KEY_PRESS)
    {
      while(KEY_USER == KEY_PRESS);                         //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描OK键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_OK_Scan(void)
{
  if(KEY_OK == KEY_PRESS)                                   //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_OK == KEY_PRESS)
    {
      while(KEY_OK == KEY_PRESS);                           //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描BACK键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_BACK_Scan(void)
{
  if(KEY_BACK == KEY_PRESS)                                 //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_BACK == KEY_PRESS)
    {
      while(KEY_BACK == KEY_PRESS);                         //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描UP键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_UP_Scan(void)
{
  if(KEY_UP == KEY_PRESS)                                   //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_UP == KEY_PRESS)
    {
      while(KEY_UP == KEY_PRESS);                           //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描RIGHT键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_RIGHT_Scan(void)
{
  if(KEY_RIGHT == KEY_PRESS)                                //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_RIGHT == KEY_PRESS)
    {
      while(KEY_RIGHT == KEY_PRESS);                        //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描DOWN键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_DOWN_Scan(void)
{
  if(KEY_DOWN == KEY_PRESS)                                 //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_DOWN == KEY_PRESS)
    {
      while(KEY_DOWN == KEY_PRESS);                         //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
/********************************************************************************
  功能：	扫描LEFT键
  参数：	无
  返回：	1	被按下
        0 未按下
  备注：	无
*********************************************************************************/
uint8_t KEY_LEFT_Scan(void)
{
  if(KEY_LEFT == KEY_PRESS)                                 //判断按键是否按下
  {
    delay_ms(KEY_FILTER);                                   //消抖
    
    if(KEY_LEFT == KEY_PRESS)
    {
      while(KEY_LEFT == KEY_PRESS);                         //等待按键释放
      return 1;
    }
  }
  
  return 0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
