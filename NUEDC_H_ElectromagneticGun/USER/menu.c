///////////////////////////////////////////////////////////////////-=505-Tech=-///
//����H��-ģ����������-�˵�
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//�汾��V3.0
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "menu.h"
#include "main.h"
#include "data.h"
#include "modes.h"
#include "match.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void Test_PID(void);
void SE_Reset(void);
void SE_Limit(void);
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//ע�⣡�����½���ҳ�涼��Ҫ���������:
MENU_PAGE Homepage,
              Match,
							    __BasicDemand1,
							    __BasicDemand2,
							    __BasicDemand3,
									__ExtendedDemand1,
									__ExtendedDemand2,
									__ExtendedDemand3,
              Modes,
						      Mode1,
						      Mode2,
						      Mode3,
					    Settings,
									SESet,
									FireSet,
					    Author;
/********************************************************************************
  ҳ������	��ҳ
  ��ҳ�棺	��
*********************************************************************************/
__M_PAGE(Homepage,"HOMEPAGE",PAGE_NULL,
{
	SOLGUI_Cursor(6,0,7);
	
  SOLGUI_Widget_GotoPage(0,&Match);
  SOLGUI_Widget_GotoPage(1,&Settings);
  SOLGUI_Widget_GotoPage(2,&Modes);
  SOLGUI_Widget_GotoPage(3,&Author);
	
	SOLGUI_Widget_Button(4,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(5,"TEST AUTO",&OpenFire_AutoAim);
	SOLGUI_Widget_OptionText(6,"%f,%f",target,(613-(target-2.3)*40));
	
	
	
	RangeFinding_Stop();
});
/********************************************************************************
  ҳ������	����
  ��ҳ�棺	��ҳ
*********************************************************************************/
__M_PAGE(Match,"MATCH",&Homepage,
{
	SOLGUI_Cursor(6,0,7);
	
	SOLGUI_Widget_Button(0,"RELOAD GUN",&ReloadGun);
  SOLGUI_Widget_GotoPage(1,&__BasicDemand1);
  SOLGUI_Widget_GotoPage(2,&__BasicDemand2);
  SOLGUI_Widget_GotoPage(3,&__BasicDemand3);
  SOLGUI_Widget_GotoPage(4,&__ExtendedDemand1);
  SOLGUI_Widget_GotoPage(5,&__ExtendedDemand2);
  SOLGUI_Widget_GotoPage(6,&__ExtendedDemand3);
});
/********************************************************************************
  ҳ������	�������ֵ�һ��
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__BasicDemand1,"BasicDemand1",&Match,
{
	SOLGUI_Cursor(6,0,1);
	SOLGUI_Widget_Button(0,"START",&BasicDemand1);
});
/********************************************************************************
  ҳ������	�������ֵڶ���
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__BasicDemand2,"BasicDemand2",&Match,
{
	SOLGUI_Cursor(6,0,3);
	
	SOLGUI_Widget_Spin(0,"DISTANCE",FLT16,3.0,2.0,&Fire_Distance);
	SOLGUI_Widget_Button(1,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(2,"START",&BasicDemand2);
});
/********************************************************************************
  ҳ������	�������ֵ�����
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__BasicDemand3,"BasicDemand3",&Match,
{
	SOLGUI_Cursor(6,0,4);
	
	SOLGUI_Widget_Spin(0,"DISTANCE",FLT16,3.0,2.0,&Fire_Distance);
	SOLGUI_Widget_Spin(1,"ANGLE(L-R+)",INT32,30,-30,&Fire_Angle);
	SOLGUI_Widget_Button(2,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(3,"START",&BasicDemand3);
});
/********************************************************************************
  ҳ������	���Ӳ��ֵ�һ��
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__ExtendedDemand1,"ExtendedDemand1",&Match,
{
	SOLGUI_Cursor(6,0,2);
	
	SOLGUI_Widget_Button(0,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(1,"START",&ExtendedDemand1);
});
/********************************************************************************
  ҳ������	���Ӳ��ֵڶ���
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__ExtendedDemand2,"ExtendedDemand2",&Match,
{
	SOLGUI_Cursor(6,0,5);
	
	
	SOLGUI_Widget_Spin(0,"AnticipationRL",INT32,100,0,&AnticipationRL);
	SOLGUI_Widget_Spin(1,"AnticipationLR",INT32,100,0,&AnticipationLR);
	SOLGUI_Widget_Button(2,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(3,"START",&ExtendedDemand2);
	SOLGUI_Widget_OptionText(4,(const u8*)(OpenMV_XErr>0?"XErr:+%3d":"XErr: -%3d"),abs(OpenMV_XErr));
});
/********************************************************************************
  ҳ������	���Ӳ��ֵ�����
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(__ExtendedDemand3,"ExtendedDemand3",&Match,
{
	SOLGUI_Cursor(6,0,1);
	
	SOLGUI_Widget_Button(0,"START",&ExtendedDemand3);
});
/********************************************************************************
  ҳ������	ģʽ
  ��ҳ�棺	��ҳ
*********************************************************************************/
__M_PAGE(Modes,"MODES",&Homepage,
{
	SOLGUI_Cursor(6,0,3);
	
  SOLGUI_Widget_GotoPage(0,&Mode1);
  SOLGUI_Widget_GotoPage(1,&Mode2);
  SOLGUI_Widget_GotoPage(2,&Mode3);
	
	RangeFinding_Stop();
	
});
/********************************************************************************
  ҳ������	ģʽһ
  ��ҳ�棺	ģʽ
*********************************************************************************/
__M_PAGE(Mode1,"MODE1",&Modes,
{
	SOLGUI_Cursor(6,0,7);
	
	SOLGUI_Widget_Button(0,"RUN MODE1",&MODE1);
	SOLGUI_Widget_Button(1,"SE Reset",&SE_Reset);
	SOLGUI_Widget_OptionText(2,"EdgeL :%d",EdgeL);
	SOLGUI_Widget_OptionText(3,"EdgeR :%d",EdgeR);
	SOLGUI_Widget_OptionText(4,"AimValue:%d",AimValue);
	SOLGUI_Widget_OptionText(5,"ValueR:%.3f",ValueR);
	SOLGUI_Widget_OptionText(6,"ValueL:%.3f",ValueL);
	
	RangeFinding_Start();
	SE_Limit();
});
/********************************************************************************
  ҳ������	ģʽ��
  ��ҳ�棺	ģʽ
*********************************************************************************/
__M_PAGE(Mode2,"MODE2",&Modes,
{
	SOLGUI_Cursor(6,0,4);
	
	SOLGUI_Widget_Button(0,"RUN MODE2",&MODE2);
	SOLGUI_Widget_Button(1,"SE Reset",&SE_Reset);
	SOLGUI_Widget_OptionText(2,(const u8*)(OpenMV_XErr>0?"XErr:Right%3d":"XErr: Left%3d"),abs(OpenMV_XErr));
	SOLGUI_Widget_OptionText(3,(const u8*)(OpenMV_YErr>0?"YErr: Down%3d":"YErr:   Up%3d"),abs(OpenMV_YErr));
	
	SE_Limit();
});
/********************************************************************************
  ҳ������	ģʽ��
  ��ҳ�棺	ģʽ
*********************************************************************************/
__M_PAGE(Mode3,"MODE3",&Modes,
{
	SOLGUI_Cursor(6,0,4);
	
	SOLGUI_Widget_Button(0,"RUN MODE3",&MODE3);
	SOLGUI_Widget_Button(1,"SE Reset",&SE_Reset);
	SOLGUI_Widget_OptionText(2,(const u8*)(OpenMV_XErr>0?"XErr:Right%3d":"XErr: Left%3d"),abs(OpenMV_XErr));
	SOLGUI_Widget_OptionText(3,(const u8*)(OpenMV_YErr>0?"YErr: Down%3d":"YErr:   Up%3d"),abs(OpenMV_YErr));
	
	SE_Limit();
});
/********************************************************************************
  ҳ������	����
  ��ҳ�棺	��ҳ
*********************************************************************************/
__M_PAGE(Settings,"SETTINGS",&Homepage,
{
	SOLGUI_Cursor(6,0,2);
	
  SOLGUI_Widget_GotoPage(0,&FireSet);
  SOLGUI_Widget_GotoPage(1,&SESet);
	
	SE_TOP_TEST=SE_TOP;
	SE_BASE_TEST=SE_BASE;
	
	RangeFinding_Stop();
});
/********************************************************************************
  ҳ������	�������
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(SESet,"SE",&Settings,
{
	SOLGUI_Cursor(6,0,5);
	
	SOLGUI_Widget_Spin(0,"SE_BASE",INT16,SE_BASE_LMAX,SE_BASE_RMAX,&SE_BASE_TEST);
	SOLGUI_Widget_Spin(1,"SE_TOP ",INT16,SE_TOP_FMAX,SE_TOP_BMAX,&SE_TOP_TEST);
	SOLGUI_Widget_OptionText(2,"%f",RangeFinding);
	SOLGUI_Widget_OptionText(3,(const u8*)(OpenMV_XErr>0?"XErr:Right%3d":"XErr: Left%3d"),abs(OpenMV_XErr));
	SOLGUI_Widget_OptionText(4,(const u8*)(OpenMV_YErr>0?"YErr: Down%3d":"YErr:   Up%3d"),abs(OpenMV_YErr));
	
	RangeFinding_Start();
	SE_TOP = SE_TOP_TEST;
	SE_BASE= SE_BASE_TEST;
});
/********************************************************************************
  ҳ������	��������
  ��ҳ�棺	����
*********************************************************************************/
__M_PAGE(FireSet,"FIRE",&Settings,
{
	SOLGUI_Cursor(6,0,7);
	
	SOLGUI_Widget_Spin(0,"SE_TOP ",INT16,SE_TOP_FMAX,SE_TOP_BMAX,&SE_TOP_TEST);
	SOLGUI_Widget_Button(1,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(2,"Fire",&Gun_Fire);
	SOLGUI_Widget_Button(3,"",&RangeFinding_Single);
	SOLGUI_Widget_OptionText(3,"GetRange:     %f",RangeFinding);
	SOLGUI_Widget_Spin(4,"SE_BASE",INT16,SE_BASE_LMAX,SE_BASE_RMAX,&SE_BASE_TEST);
	SOLGUI_Widget_Spin(5,"Relay HoldTime",INT16,1000,RELAY_TimeMin,&RelayTime);
	SOLGUI_Widget_Button(6,"Relay Hold",&Gun_Fire_Hold);
	
	SE_TOP = SE_TOP_TEST;
	SE_BASE= SE_BASE_TEST;
});
/********************************************************************************
  ҳ������	������Ϣ
  ��ҳ�棺	��ҳ
*********************************************************************************/
__M_PAGE(Author,"AUTHOR",&Homepage,
{
	SOLGUI_Widget_OptionText(0,"COMPANY:   505_Tech");
	SOLGUI_Widget_OptionText(1,"QQ:      2843067579");
});
/*===========================�½��˵�ҳ���ʽ�����ú���=============================
__M_PAGE(name(),pageTitle,parentPage,
//����ҳ�����ƣ���ҳ����⡱��&�ϼ�ҳ������
{

    SOLGUI_Cursor( uint8_t rowBorder_Top, uint8_t rowBorder_Bottom, uint8_t option_num)
    //���ϱ߽��У��±߽��У�ѡ�������

    ҳ����ת�ؼ�:
    SOLGUI_Widget_GotoPage( uint8_t USN,MENU_PAGE *page)
    //(��ѡ������λ��,	&ҳ���ַ)

    �����ؼ���
    SOLGUI_Widget_Button( uint8_t USN,const  uint8_t *name,void (*func)(void))
    //(��ѡ������λ��,"��ѡ����ʾ������",&���¸ð���ʱִ�е��޲���void���ͺ���);

    ������ť�ؼ���
    SOLGUI_Widget_Spin( uint8_t USN,const  uint8_t *name, uint8_t type,double max,double min,void* value)
    //(��ѡ������λ��,"��ѡ����ʾ������",�������ͣ���INT32��,�仯����,�仯����,&������ַ);

    �����ı��ؼ���
    SOLGUI_Widget_Text( uint32_t x0, uint32_t y0, uint8_t mode,const  uint8_t* str,...)
    //(������,������,�ֺţ���F4X6��,"��Ҫ��ʾ�����֣���ʽͬprintf��",�÷�ͬprintf�ַ�����Ĳ���);

});
================================================================================*/
/********************************************************************************
    ���ܣ�	����PID
    ������	��
    ���أ�	��
    ��ע��	�ڲ˵��е��ã�Ϊ�շ����޲�������
*********************************************************************************/
void Test_PID(void)
{
	
}
/********************************************************************************
    ���ܣ�	�����λ
    ������	��
    ���أ�	��
    ��ע��	�ڲ˵��е��ã�Ϊ�շ����޲�������
*********************************************************************************/
void SE_Reset(void)
{
	SE_TOP = SE_TOP_MID;
	SE_BASE= SE_BASE_MID;
}
/********************************************************************************
    ���ܣ�	����޷�
    ������	��
    ���أ�	��
    ��ע��	�ڲ˵��е��ã�Ϊ�շ����޲�������
*********************************************************************************/
void SE_Limit(void)
{
	if(SE_BASE>=SE_BASE_LMAX)SE_BASE=SE_BASE_LMAX;
	if(SE_BASE<=SE_BASE_RMAX)SE_BASE=SE_BASE_RMAX;
	if(SE_TOP>=SE_TOP_FMAX)SE_TOP=SE_TOP_FMAX;
	if(SE_TOP<=SE_TOP_BMAX)SE_TOP=SE_TOP_BMAX;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
