///////////////////////////////////////////////////////////////////-=505-Tech=-///
//电赛H题-模拟电磁曲射炮-菜单
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//版本：V3.0
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
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
//注意！所有新建的页面都需要在这里添加:
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
  页面名：	主页
  父页面：	空
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
  页面名：	比赛
  父页面：	主页
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
  页面名：	基础部分第一题
  父页面：	比赛
*********************************************************************************/
__M_PAGE(__BasicDemand1,"BasicDemand1",&Match,
{
	SOLGUI_Cursor(6,0,1);
	SOLGUI_Widget_Button(0,"START",&BasicDemand1);
});
/********************************************************************************
  页面名：	基础部分第二题
  父页面：	比赛
*********************************************************************************/
__M_PAGE(__BasicDemand2,"BasicDemand2",&Match,
{
	SOLGUI_Cursor(6,0,3);
	
	SOLGUI_Widget_Spin(0,"DISTANCE",FLT16,3.0,2.0,&Fire_Distance);
	SOLGUI_Widget_Button(1,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(2,"START",&BasicDemand2);
});
/********************************************************************************
  页面名：	基础部分第三题
  父页面：	比赛
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
  页面名：	发挥部分第一题
  父页面：	比赛
*********************************************************************************/
__M_PAGE(__ExtendedDemand1,"ExtendedDemand1",&Match,
{
	SOLGUI_Cursor(6,0,2);
	
	SOLGUI_Widget_Button(0,"RELOAD GUN",&ReloadGun);
	SOLGUI_Widget_Button(1,"START",&ExtendedDemand1);
});
/********************************************************************************
  页面名：	发挥部分第二题
  父页面：	比赛
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
  页面名：	发挥部分第三题
  父页面：	比赛
*********************************************************************************/
__M_PAGE(__ExtendedDemand3,"ExtendedDemand3",&Match,
{
	SOLGUI_Cursor(6,0,1);
	
	SOLGUI_Widget_Button(0,"START",&ExtendedDemand3);
});
/********************************************************************************
  页面名：	模式
  父页面：	主页
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
  页面名：	模式一
  父页面：	模式
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
  页面名：	模式二
  父页面：	模式
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
  页面名：	模式三
  父页面：	模式
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
  页面名：	设置
  父页面：	主页
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
  页面名：	舵机设置
  父页面：	设置
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
  页面名：	开火设置
  父页面：	设置
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
  页面名：	作者信息
  父页面：	主页
*********************************************************************************/
__M_PAGE(Author,"AUTHOR",&Homepage,
{
	SOLGUI_Widget_OptionText(0,"COMPANY:   505_Tech");
	SOLGUI_Widget_OptionText(1,"QQ:      2843067579");
});
/*===========================新建菜单页面格式及常用函数=============================
__M_PAGE(name(),pageTitle,parentPage,
//（该页面名称，“页面标题”，&上级页面名）
{

    SOLGUI_Cursor( uint8_t rowBorder_Top, uint8_t rowBorder_Bottom, uint8_t option_num)
    //（上边界行，下边界行，选项个数）

    页面跳转控件:
    SOLGUI_Widget_GotoPage( uint8_t USN,MENU_PAGE *page)
    //(该选项所处位置,	&页面地址)

    按键控件：
    SOLGUI_Widget_Button( uint8_t USN,const  uint8_t *name,void (*func)(void))
    //(该选项所处位置,"该选项显示的文字",&按下该按键时执行的无参数void类型函数);

    数字旋钮控件：
    SOLGUI_Widget_Spin( uint8_t USN,const  uint8_t *name, uint8_t type,double max,double min,void* value)
    //(该选项所处位置,"该选项显示的文字",变量类型（如INT32）,变化上限,变化下限,&变量地址);

    自由文本控件：
    SOLGUI_Widget_Text( uint32_t x0, uint32_t y0, uint8_t mode,const  uint8_t* str,...)
    //(横坐标,纵坐标,字号（如F4X6）,"需要显示的文字（格式同printf）",用法同printf字符串后的参数);

});
================================================================================*/
/********************************************************************************
    功能：	测试PID
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_PID(void)
{
	
}
/********************************************************************************
    功能：	舵机复位
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void SE_Reset(void)
{
	SE_TOP = SE_TOP_MID;
	SE_BASE= SE_BASE_MID;
}
/********************************************************************************
    功能：	舵机限幅
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void SE_Limit(void)
{
	if(SE_BASE>=SE_BASE_LMAX)SE_BASE=SE_BASE_LMAX;
	if(SE_BASE<=SE_BASE_RMAX)SE_BASE=SE_BASE_RMAX;
	if(SE_TOP>=SE_TOP_FMAX)SE_TOP=SE_TOP_FMAX;
	if(SE_TOP<=SE_TOP_BMAX)SE_TOP=SE_TOP_BMAX;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
