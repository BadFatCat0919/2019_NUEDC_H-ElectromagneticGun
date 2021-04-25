///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-系统运行模式
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
#include "modes.h"
int EdgeR,EdgeL,AimValue;
double ValueR,ValueL;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    功能：	模式一
    参数：	无
    返回：	无
    备注：	激光搜索
*********************************************************************************/
void MODE1(void)
{
	int i;
	double LastRangeFinding=0;
	EdgeR=0,EdgeL=0;
	RangeFinding_Start();
	for(i=SE_BASE_RMAX;i<=SE_BASE_LMAX;i++)
	{
		if(LastRangeFinding!=0)
		{
			SE_BASE=i;
			delay_ms(50);
			if(!EdgeR)
			{
				if(RangeFinding<3.1)
				{
					EdgeR=i;
					ValueR=RangeFinding;
				}
			}
			else if(!EdgeL)
			{
				if(RangeFinding>3.1)
				{
					EdgeL=i;
					ValueL=RangeFinding;
				}
			}
			else if(i>EdgeL+10)
				break;
		}
		else
		{
			SE_BASE=SE_BASE_RMAX;
			delay_ms(500);
		}
		LastRangeFinding=RangeFinding;
	}
	RangeFinding_Stop();
	SE_BASE=(EdgeR+EdgeL)/2-3;
	AimValue=SE_BASE;
	RangeFinding_Single();
}
/********************************************************************************
    功能：	模式二
    参数：	无
    返回：	无
    备注：	OpenMV扫描搜索
*********************************************************************************/
void MODE2(void)
{
	int angle,lasterr[3],cnt,i;
	for(i=SE_BASE;i>SE_BASE_RMAX;i--)
	{
		SE_BASE=i;
		delay_ms(2);
	}
	for(angle=SE_BASE_RMAX;angle<=SE_BASE_LMAX;angle++)
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
	RangeFinding_Start();
	delay_ms(500);
	delay_ms(500);
	RangeFinding_Stop();
}
/********************************************************************************
    功能：	模式三
    参数：	无
    返回：	无
    备注：	OpenMV原地开始搜索
*********************************************************************************/
void MODE3(void)
{
	int angle,lasterr[5],cnt;
	if(abs(OpenMV_XErr)<2)
	{
		RangeFinding_Start();
		delay_ms(500);
		delay_ms(500);
		RangeFinding_Stop();
		return;
	}
		
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
	RangeFinding_Start();
	delay_ms(500);
	delay_ms(500);
	RangeFinding_Stop();
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
