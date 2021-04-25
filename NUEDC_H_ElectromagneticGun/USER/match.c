///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
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
    ���ܣ�	�������ֵ�һ��
    ������	��
    ���أ�	��
    ��ע��	ֱ�ӿ���
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
    ���ܣ�	�������ֵڶ���
    ������	��
    ���أ�	��
    ��ע��	���࿪��
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
    ���ܣ�	�������ֵ�����
    ������	��
    ���أ�	��
    ��ע��	���򶨾࿪��
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
    ���ܣ�	���Ӳ��ֵ�һ��
    ������	��
    ���أ�	��
    ��ע��	��������
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
    ���ܣ�	���Ӳ��ֵڶ���
    ������	��
    ���أ�	��
    ��ע��	�����˶�����
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
    ���ܣ�	���Ӳ��ֵ�����
    ������	��
    ���أ�	��
    ��ע��	ɧ����
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
    ���ܣ�	����
    ������	distance ����
          angle    �Ƕ�
    ���أ�	��
    ��ע��	��������������ǰ������Ӧ������ı�λ��
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
    ���ܣ�	OpenMV��׼
    ������	��
    ���أ�	��
    ��ע��	��
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
    ���ܣ�	�Զ���׼����
    ������	��
    ���أ�	��
    ��ע��	��
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
    ���ܣ�	������Ͳ����Ͳ����
    ������	��
    ���أ�	��
    ��ע��	����Ͳ������ƫ������λ�����
*********************************************************************************/
void ResetGun(void)
{
	SetSE(0,SE_TOP_BMAX,1);
	delay_ms(300);
	SetSE(SE_BASE_MID,0,10);
	SetSE(0,SE_TOP_FMAX,15);
}
/********************************************************************************
    ���ܣ�	��������Ͳ����Ͳ����
    ������	��
    ���أ�	��
    ��ע��	����Ͳ������ƫ������λ�����
*********************************************************************************/
void ResetGun_Quiet(void)
{
	SetSE(SE_BASE_MID,0,10);
	SetSE(0,SE_TOP_FMAX,15);
}
/********************************************************************************
    ���ܣ�	װ��
    ������	��
    ���أ�	��
    ��ע��	����Ͳ�����ƶ�����󣬱���װ������ɺ�λ
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
