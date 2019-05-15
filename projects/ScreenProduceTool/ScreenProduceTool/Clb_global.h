#pragma once

extern HWND FactoryScreenHwnd;
extern HWND  UserHwnd;
extern CString DeviceModelstr;
extern CString templetstr;

#define WM_COUNTINCREASE_MSG WM_USER+100
#define WM_DEVICENUM_MSG     WM_USER+150
//数据库
#define LB_SCREEN_DB  "LBScreen.db"
//表LBScreenInfo
#define LB_SCREENINFO "LBScreenInfo"

#define ID             "id"
#define LBScreentemplate_ID  "Screentemplate_id"
#define LB_DEVICEMODEL "Devicemodel"
#define LB_HARDID    "hardId"
#define LB_MAC       "mac"
#define MASTER_NUMBER      "master_number"
#define SLAVE_NUMBER       "slave_number"
#define IP                 "ip"
#define LB_SCREENINFOLICENSE  "License"
#define LB_SCREENINFOACTIVATE  "Activate"

//表LBScreentemplate
#define LB_SCREENTEMPLATE  "LBScreentemplate"

#define ID                 "id"
#define ISADENABLED        "isAdEnabled"
#define ISADVIDEOENABLED   "isAdVideoEnabled"
#define ISADTEXTENABLED    "isAdTextEnabled"
#define ADAREAPERCENT      "adAreaPercent"
#define IVIDEOSIZE         "iVideoSize"
#define IVIDEOSOURCE       "iVideoSource"
#define VIDEOURL           "videoUrl"

#define DEFINED_VALUE      "defined_value"
#define TYPE               "type"
#define MODEL              "model"
#define STYLE              "style"
#define ROTATION           "rotation"
#define NUMBER_OF_COLUMNS  "number_of_columns"
#define NUMBER_OF_ROWS     "number_of_rows"
#define NUMBER_OF_NOW_ROWS "number_of_now_rows"
#define NUMBER_OF_SCREEN   "number_of_screen"
#define X0                 "x0"
#define Y0                 "y0"
#define WIDTH              "width"
#define HEIGHT             "height"
#define ISHIDENTITLE       "isHidenTitle"
#define TITLE              "title"
#define SUB_TITLE          "sub_title"
#define TABLEHEADS_STR     "tableheads_str"
#define TV_MESSAGE         "tv_message"

#define ISHIDEBOTTOM       "isHideBottom"
#define ISHIDECALLINFO     "isHideCallInfo"
#define ISDISPLAYDATASOURCE "isDisplayDataSource"
#define ISSHOWLOWESTLEVEL   "isShowLowestLevel"
#define ISSHOWOLDSTYLE      "isShowOldStyle"
#define LB_QUEUE_TIME       "lb_queue_time"
#define ISTODAYINPATIENT     "isTodayInPatient"
#define SHOWCALLINFOBYRIGHT  "ShowCallInfoByRight"
#define SORTBYOFFICE        "SortByOffice"
#define SYSTEMVOICE         "SystemVoice"
#define STAYTIME            "StayTime"
#define SHOWMODEL           "ShowModel"

class Clb_global
{
public:
	Clb_global();
	~Clb_global();
	
};

