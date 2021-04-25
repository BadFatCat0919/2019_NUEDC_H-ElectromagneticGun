///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-比赛代码
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "match.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
int   Fire_Angle=0,AnticipationRL=5,AnticipationLR=5;
float target,Fire_Distance=2.0;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void OpenFire(float distance,int angle);
void OpenMV_Aim(void);
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    功能：	基础部分第一题
    参数：	无
    返回：	无
    备注：	直接开炮
*********************************************************************************/
void BasicDemand1(void)
{
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	
	OpenFire(0,0);
	
	ResetGun_Quiet();
}
/********************************************************************************
    功能：	基础部分第二题
    参数：	无
    返回：	无
    备注：	定距开炮
*********************************************************************************/
void BasicDemand2(void)
{
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	
	OpenFire(Fire_Distance+0.3,0);
	
	ResetGun_Quiet();
}
/********************************************************************************
    功能：	基础部分第三题
    参数：	无
    返回：	无
    备注：	定向定距开炮
*********************************************************************************/
void BasicDemand3(void)
{
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	
	OpenFire(Fire_Distance,Fire_Angle);
	
	ResetGun_Quiet();
}
/********************************************************************************
    功能：	发挥部分第一题
    参数：	无
    返回：	无
    备注：	搜索开炮
*********************************************************************************/
void ExtendedDemand1(void)
{
	int angle;
	
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	SetSE(0,SE_TOP_MID,1);
	delay_ms(300);
	SetSE(SE_BASE_RMAX,0,10);
	for(angle=SE_BASE_RMAX;angle<=SE_BASE_LMAX;angle++)
	{
		SE_BASE=angle;
		delay_ms(10);
		if(OpenMV_FindFlag==1)break;
	}
	OpenMV_Aim();
	
	RangeFinding_Single();
	target=RangeFinding;
	
	OpenFire(RangeFinding,666);
	ResetGun_Quiet();
}
/********************************************************************************
    功能：	发挥部分第二题
    参数：	无
    返回：	无
    备注：	往复运动开炮
*********************************************************************************/
void ExtendedDemand2(void)
{
	uint16_t i,j;
	SetSE(SE_BASE_RMAX,SE_TOP_FMAX,10);
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	for(i=SE_TOP_FMAX,j=SE_BASE_RMAX;i>=633;i--,j++)
	{
		SE_TOP=i;
		SE_BASE=j;
		delay_ms(8);
	}
	OpenMV_FindFlag=0;
	OpenMV_XErr=10;
	for(;j<=SE_BASE_LMAX;j++)
	{
		SE_BASE=j;
		if(OpenMV_FindFlag==1)
		{
			if(OpenMV_XErr>=-AnticipationRL&&OpenMV_XErr<=0)
			{
				Gun_Fire_Hold();
				for(;j<=SE_BASE_LMAX;j++)
				{
					SE_BASE=j;
					delay_ms(8);
				}
				delay_ms(500);
				Gun_Fire_Hold();
				ResetGun_Quiet();
				return;
			}
		}
		delay_ms(8);
	}
	while(1)
	{
		for(j=SE_BASE_LMAX;j>=SE_BASE_RMAX;j--)
		{
			SE_BASE=j;
			if(OpenMV_FindFlag==1)
			{
				if(OpenMV_XErr<=AnticipationLR&&OpenMV_XErr>=0)
				{
					Gun_Fire_Hold();
					for(;j>=SE_BASE_RMAX;j--)
					{
						SE_BASE=j;
						delay_ms(8);
					}
					delay_ms(500);
					Gun_Fire_Hold();
					ResetGun_Quiet();
					return;
				}
			}
			delay_ms(8);
		}
		for(j=SE_BASE_RMAX;j<=SE_BASE_LMAX;j++)
		{
			SE_BASE=j;
			if(OpenMV_FindFlag==1)
			{
				if(OpenMV_XErr>=-AnticipationRL&&OpenMV_XErr<=0)
				{
					Gun_Fire_Hold();
					for(;j<=SE_BASE_LMAX;j++)
					{
						SE_BASE=j;
						delay_ms(8);
					}
					delay_ms(500);
					Gun_Fire_Hold();
					ResetGun_Quiet();
					return;
				}
			}
			delay_ms(8);
		}
	}
	
	
	//Gun_Fire();
}
/********************************************************************************
    功能：	发挥部分第三题
    参数：	无
    返回：	无
    备注：	骚操作
*********************************************************************************/
void ExtendedDemand3(void)
{
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	
}
/********************************************************************************
    功能：	开炮
    参数：	distance 距离
          angle    角度
    返回：	无
    备注：	超过参数限制则当前参数对应舵机不改变位置
*********************************************************************************/
void OpenFire(float distance,int angle)
{
	if(distance>4&&distance<100)
		distance=2.8;
	if(angle>=-30&&angle<=30)
		
	SetSE((int)(angle*5.45)+859,0,5);
	SetSE(0,(654-(3.3-distance)*50),10);
	
	delay_ms(500);
	
	Gun_Fire();
}
/********************************************************************************
    功能：	OpenMV瞄准
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void OpenMV_Aim(void)
{
	int angle,lasterr[5],cnt;
	if(abs(OpenMV_XErr)<2)
		return;
		
	for(angle=SE_BASE;angle<=SE_BASE_LMAX;angle++)
	{
		SE_BASE=angle;
		delay_ms(3);
		if(OpenMV_FindFlag==1)break;
	}
	cnt=0;
	while(1)
	{
		SE_BASE=angle;
		if(OpenMV_XErr>1)
			angle--;
		if(OpenMV_XErr<-1)
			angle++;
		if(angle>=SE_BASE_LMAX)angle=SE_BASE_LMAX;
		if(angle<=SE_BASE_RMAX)angle=SE_BASE_RMAX;
		if(abs(OpenMV_XErr)>30)
			delay_ms(5);
		else
			delay_ms(60);
		if(cnt++>3&&abs(lasterr[0]+lasterr[1]+lasterr[2])<3)
			break;
		lasterr[2]=lasterr[1];
		lasterr[1]=lasterr[0];
		lasterr[0]=OpenMV_XErr;
	}
}
/********************************************************************************
    功能：	自动瞄准开炮
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void OpenFire_AutoAim(void)
{
	ResetGun();
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
		if(key_value==__KEY_BACK)
			return;
	}
	
	OpenMV_Aim();
	
	RangeFinding_Single();
	target=RangeFinding;
	
	OpenFire(RangeFinding,666);
}
/********************************************************************************
    功能：	上挑炮筒的炮筒重置
    参数：	无
    返回：	无
    备注：	将炮筒俯仰、偏航均复位至零度
*********************************************************************************/
void ResetGun(void)
{
	SetSE(0,SE_TOP_BMAX,1);
	delay_ms(300);
	SetSE(SE_BASE_MID,0,10);
	SetSE(0,SE_TOP_FMAX,15);
}
/********************************************************************************
    功能：	不上挑炮筒的炮筒重置
    参数：	无
    返回：	无
    备注：	将炮筒俯仰、偏航均复位至零度
*********************************************************************************/
void ResetGun_Quiet(void)
{
	SetSE(SE_BASE_MID,0,10);
	SetSE(0,SE_TOP_FMAX,15);
}
/********************************************************************************
    功能：	装弹
    参数：	无
    返回：	无
    备注：	将炮筒俯仰移动到最大，便于装弹，完成后复位
*********************************************************************************/
void ReloadGun(void)
{
	uint16_t SE_TOP_NOW;
	
	SE_TOP_NOW=SE_TOP;
	
	SetSE(0,SE_TOP_BMAX,3);
	
	OLED_ShowLogo();
	while(1)
	{
		uint8_t  key_value;
    key_value=KEY_Scan();
		
		if(key_value==__KEY_OK)
			break;
	}
	
	SetSE(0,SE_TOP_NOW,10);
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
