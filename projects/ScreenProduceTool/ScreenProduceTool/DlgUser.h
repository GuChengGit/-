#pragma once

#include "afxwin.h"
#include "Clb_global.h"
#include "afxcmn.h"
#include "SQLite3Wrapper.h"
#include "lb_action.h"
#include "afxinet.h"

// CDlgUser 对话框


#define LBFIELD_NUMBER     (1<<0)       //票号
#define LBFIELD_NAME       (1<<1)          //姓名
#define LBFILED_DEPARTMENTS  (1<<2)    //科室
#define LBFILED_PRISON_SECTION  (1<<3)   //监区
#define LBFILED_OUTPATIENT_SERVICE  (1<<4)     //门诊类别
#define LBFILED_DOCTOR    (1<<5)           //医生
#define LBFILED_FAMILY     (1<<6)        //家属
#define LBFIELD_ROOM_CODE  (1<<7)       //诊室编号
#define LBFILED_WINDOW  (1<<8)  //窗口
#define LBFILED_STATE   (1<<9)  //状态
#define LBFILED_DESCRIPTION   (1<<10)     //备注

#define LBFIELD_WAITING_PATIENT   (1<<11)    //等待人员
#define LBFIELD_WAITING_COUNT    (1<<12)    //等待人数
#define LBFIELD_MESSAGE    (1<<13)   //信息
#define LBFIELD_SENTRY_STATE   (1<<14)  //状态
#define LBFIELD_PRISONER    (1<<15)   //犯人
#define LBFIELD_TITLES   (1<<16)  //职称
#define LBFIELD_TOBEPATIENT_NUMBER   (1<<17)     //等待票号
#define LBFIELD_DEPARTMENT_DOCTOR    (1<<18)     //科室医生
#define LBFILED_ROOM_NMAE   (1<<19)     //诊室名称

#define LBFIELD_WAIT_DESCRIPTION (1<<20)   //等待备注
#define LBFIELD_INITSCREEN    (1<<23)  //初始化显示屏
#define LBFIELD_OPERATIONROOM (1<<24)   //手术间
#define LBFIELD_TIME  (1<<25)   //时间
#define LBFIELD_OPERATIVENAME   (1<<26)   //手术名称
#define LBFIELD_LEVEL    (1<<27)    //等级
#define LBFIELD_ANESTHESIOLOGIST (1<<28)   //麻醉医生
#define LBFIELD_LAWYER   (1<<29)   //律师
#define LBFIELD_MEETING_AREA  (1<<30)  //会见区


class CDlgUser : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUser)

public:
	CDlgUser(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgUser();

// 对话框数据
	enum { IDD = IDD_DLG_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_UserReportCtrl;
	CStatic m_template;
	CListCtrl m_listtable;
	void InitUserReportCtrl();
	void InitCheckTYPEStatus();

	void backgroundcolor();
	void fontcolorcolor();
	void typemode();
	void InformationStatueMode();
	void InformationBorderMassage();
	void patientsimpleshow();
	void HideAllSHOW();

	afx_msg void OnEnChangeEdit1();
	CComboBox m_UserComboBox;
	BOOL InitUserComBox();
	BOOL InitListTable();
	BOOL InitListTable_ConsultingRoom();
	BOOL InitListTable_WaitingRoom();
	BOOL InitListTable_WaitingRoom2();
	BOOL InitListTable_BankWaitingRoom();
	BOOL InitListTable_HospitalRoom();
	BOOL InitListTable_MedicineWaitingRoom();
	BOOL InitListTable_MedicineWindow();
	BOOL InitListTable_MedicineWaitingRoom2();
	BOOL InitListTable_MedicineScreen();
	BOOL InitListTable_Prison();
	BOOL InitBankWindow();
	BOOL RefreshDeviceList();
	BOOL SendScreenProperty(CString ScreenIp);
	BOOL SendScreenSystemSet(CString ScreenIp);
	BOOL checkadv();

	BOOL InitListTable_SecondWaitingRoom();
	BOOL InitListTable_WaitSecond3();
	BOOL InitListTable_WaitSecond5();
	BOOL InitListTable_WaitSecond6();
	BOOL InitListTable_WaitSecond2();
	BOOL InitListTable_WaitShow2();
	BOOL InitListTable_call();
	BOOL InitListTable_TriageShow();
	BOOL InitListTable_TriageShow2();
	BOOL InitNetwork_intercom();
	BOOL InitBanksort_Window3();
	BOOL InitBanksort();
	BOOL InitListTable_Bankshow2();
	BOOL InitListTable_ScanCheck();
	BOOL InitListTable_MedicineScreen1();
	BOOL InitListTable_ShowRoom5();

	afx_msg void OnCbnSelchangeCombouser();
	afx_msg void OnStnClickedStaticheadline();
	afx_msg void OnBnClickedCheckheadline1();
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	
	afx_msg void OnBnClickedUserbutton();
	afx_msg void OnLvnItemchangedUser(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT OnCountDeviceNumMsg(WPARAM, LPARAM);

	afx_msg void OnBnClickedButtonrefreshlist();
	afx_msg void OnBnClickedUsersettemplate();
	CEdit m_title;
	CEdit m_subtitle;
	CEdit m_x;
	CEdit m_Y;
	CEdit m_height;
	CEdit m_width;
	CEdit m_percent;
	CEdit m_voice;
	CEdit m_row;
	CButton m_mediaAdv;
	CButton m_videoAdv;
	CButton m_characterAdv;
	afx_msg void OnBnClickedCheckmedadv();
	CEdit m_consultname;
	
	afx_msg void OnBnClickedCheckvideoadv();
	afx_msg void OnBnClickedCheckcharacteradv();
	afx_msg void OnBnClickedCheckhidetitle();
	CButton m_hidetitle;
	int TemplateStyle = -1;
	int Check = 1;
	int isHidenTitle = 0, isAdEnabled = 0, isAdVideoEnabled = 0, isAdTextEnabled = 0, isWindowOrder = 0, isHideBottom = 0, isHideCallInfo = 0, ShowCallInfoByRight = 0, SortByOffice = 0, CheckMeans = 0, isHidePrisonBottom = 0, isRadio3Button = 0, isRadio4Button = 0, isRadio5Button = 0,isBadnum = 0;
	CString BackGroundColor;
	CString FontColor;
	CString Typemode;
	CString strFilePath;
	
	afx_msg void OnNMDblclkListtable(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_EditVirtual;
	afx_msg void OnNMClickListtable(NMHDR *pNMHDR, LRESULT *pResult);
	CString master_num, slave_num;
	afx_msg void OnBnClickedButtonNumSet();
	CEdit m_address_box;
	CEdit m_master_number;
	CEdit m_slave_number;
	CEdit m_device_number;
	CEdit m_device_ip;
	
	CButton m_windoworder;
	afx_msg void OnBnClickedCheckwindoworder();
	
	
	CEdit m_letter;
	CButton m_HidePatient;
	CButton m_HideWindow;
	CButton m_ShowRight;
	CButton m_ConsultOrder;

	afx_msg void OnBnClickedCheckhidepatient();
	afx_msg void OnBnClickedCheckhidwindow();
	afx_msg void OnBnClickedCheckshowright();
	afx_msg void OnBnClickedCheckconsultorder();
	afx_msg void OnBnClickedCheckMeans();
	CButton m_checkmeans;
	CEdit m_Means_DeviceIP;
	CComboBox m_ComboBox_App;
	afx_msg void OnCbnSelchangeComboapp();
	CButton m_isHideBottom;
	afx_msg void OnBnClickedCheckHideBottom();
	afx_msg void OnCbnSelchangeComboBackground();
	CComboBox m_backgroundcolor;
	CComboBox m_fontcolor;
	afx_msg void OnCbnSelchangeCombofontcolor();
	CEdit m_info_server_port;
	afx_msg void OnStnClickedStaticBackground2();
	afx_msg void OnCbnSelchangeCombo1();

	CButton m_button_radio3;
	BOOL m_button_radio;
	afx_msg void OnBnClickedButtonRadio3();
	afx_msg void OnBnClickedButtonRadio4();
	afx_msg void OnBnClickedButtonRadio5();
	CStatic m_bad_set;

	CStatic m_badnum;
	CEdit m_badnum_set;

	CStatic m_modename;
	CComboBox m_Typemode;
	afx_msg void OnCbnSelchangeTypemode();
	int mode=0,sum=0;
	CEdit m_filepath;
	CButton m_buttonview;
	CButton m_buttonupload;
	afx_msg void OnBnClickedButtonView();
	afx_msg void OnBnClickedButtonUpload();

	CInternetSession *pInternetSession;
	CFtpConnection *pFtpConnection;
	//增加获取上一次ip，主机号等等
	CString Address_box_ip, Master_number, Slave_number, Device_number, Device_ip;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonHelp();
};
