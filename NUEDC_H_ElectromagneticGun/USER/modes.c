///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-ϵͳ����ģʽ
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
#include "modes.h"
int EdgeR,EdgeL,AimValue;
double ValueR,ValueL;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    ���ܣ�	ģʽһ
    ������	��
    ���أ�	��
    ��ע��	��������
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
    ���ܣ�	ģʽ��
    ������	��
    ���أ�	��
    ��ע��	OpenMVɨ������
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
    ���ܣ�	ģʽ��
    ������	��
    ���أ�	��
    ��ע��	OpenMVԭ�ؿ�ʼ����
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
