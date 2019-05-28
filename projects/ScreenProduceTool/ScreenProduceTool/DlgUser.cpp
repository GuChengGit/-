// DlgUser.cpp : 实现文件
//

#include "stdafx.h"
#include "ScreenProduceTool.h"
#include "DlgUser.h"
#include "afxdialogex.h"
#define  IDC_EDIT 0xffff

int m_Item, m_SubItem;
// CDlgUser 对话框

IMPLEMENT_DYNAMIC(CDlgUser, CDialogEx)

CDlgUser::CDlgUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgUser::IDD, pParent)
	, m_button_radio(FALSE)
{

}

CDlgUser::~CDlgUser()
{
}

void CDlgUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER, m_UserReportCtrl);
	DDX_Control(pDX, IDC_COMBOUSER, m_UserComboBox);
	DDX_Control(pDX, IDC_MODEL, m_template);
	DDX_Control(pDX, IDC_LISTTABLE, m_listtable);
	DDX_Control(pDX, IDC_EDITTITLE, m_title);
	DDX_Control(pDX, IDC_EDITSUBTITLE, m_subtitle);
	DDX_Control(pDX, IDC_EDITPOSITIONX, m_x);
	DDX_Control(pDX, IDC_EDITPOSITIONY, m_Y);
	DDX_Control(pDX, IDC_EDITHEIGHT, m_height);
	DDX_Control(pDX, IDC_EDITWIDTH, m_width);
	DDX_Control(pDX, IDC_EDITPERCENT, m_percent);
	DDX_Control(pDX, IDC_EDITVOICE, m_voice);
	DDX_Control(pDX, IDC_EDITROW, m_row);
	DDX_Control(pDX, IDC_CHECKMEDADV, m_mediaAdv);
	DDX_Control(pDX, IDC_CHECKVIDEOADV, m_videoAdv);
	DDX_Control(pDX, IDC_CHECKCHARACTERADV, m_characterAdv);
	DDX_Control(pDX, IDC_EDITCONSULTNAME, m_consultname);
	DDX_Control(pDX, IDC_CHECKHIDETITLE, m_hidetitle);
	DDX_Control(pDX, IDC_EDIT3, m_address_box);
	DDX_Control(pDX, IDC_EDIT12, m_master_number);
	DDX_Control(pDX, IDC_EDIT13, m_slave_number);
	DDX_Control(pDX, IDC_EDIT14, m_device_number);
	DDX_Control(pDX, IDC_EDIT_15, m_device_ip);
	DDX_Control(pDX, IDC_CHECKWINDOWORDER, m_windoworder);
	DDX_Control(pDX, IDC_LETTER, m_letter);
	DDX_Control(pDX, IDC_CHECKHIDEPATIENT, m_HidePatient);
	DDX_Control(pDX, IDC_CHECKHIDWINDOW, m_HideWindow);
	DDX_Control(pDX, IDC_CHECKSHOWRIGHT, m_ShowRight);
	DDX_Control(pDX, IDC_CHECKCONSULTORDER, m_ConsultOrder);
	DDX_Control(pDX, IDC_CHECK_MEANS, m_checkmeans);
	DDX_Control(pDX, IDC_EDIT_DEVICE_IP, m_Means_DeviceIP);
	DDX_Control(pDX, IDC_COMBOAPP, m_ComboBox_App);
	DDX_Control(pDX, IDC_CHECK_HIDE_BOTTOM, m_isHideBottom);
	DDX_Control(pDX, IDC_COMBO_BACKGROUND, m_backgroundcolor);
	DDX_Control(pDX, IDC_COMBOFONTCOLOR, m_fontcolor);
	DDX_Control(pDX, IDC_EDIT_INFO_PORT, m_info_server_port);
	DDX_Control(pDX, IDC_BUTTON_RADIO3, m_button_radio3);
	DDX_Radio(pDX, IDC_BUTTON_RADIO3, m_button_radio);
	DDX_Control(pDX, IDC_BAD_SET, m_bad_set);
	DDX_Control(pDX, IDC_STATIC_BADNUM, m_badnum);
	DDX_Control(pDX, IDC_BADNUM, m_badnum_set);
	DDX_Control(pDX, IDC_STATIC_BACKGROUND2, m_modename);
	DDX_Control(pDX, IDC_TYPEMODE, m_Typemode);
	DDX_Control(pDX, IDC_EDIT_FILEPATH, m_filepath);
	DDX_Control(pDX, IDC_BUTTON_VIEW, m_buttonview);
	DDX_Control(pDX, IDC_BUTTON_UPLOAD, m_buttonupload);
}


BEGIN_MESSAGE_MAP(CDlgUser, CDialogEx)
	
	ON_CBN_SELCHANGE(IDC_COMBOUSER, &CDlgUser::OnCbnSelchangeCombouser)
	ON_MESSAGE(WM_DEVICENUM_MSG, &CDlgUser::OnCountDeviceNumMsg)
	ON_BN_CLICKED(IDC_BUTTONREFRESHLIST, &CDlgUser::OnBnClickedButtonrefreshlist)
	ON_BN_CLICKED(IDC_USERSETTEMPLATE, &CDlgUser::OnBnClickedUsersettemplate)
	ON_BN_CLICKED(IDC_CHECKMEDADV, &CDlgUser::OnBnClickedCheckmedadv)

	ON_BN_CLICKED(IDC_CHECKVIDEOADV, &CDlgUser::OnBnClickedCheckvideoadv)
	ON_BN_CLICKED(IDC_CHECKCHARACTERADV, &CDlgUser::OnBnClickedCheckcharacteradv)
	ON_BN_CLICKED(IDC_CHECKHIDETITLE, &CDlgUser::OnBnClickedCheckhidetitle)

	ON_NOTIFY(NM_DBLCLK, IDC_LISTTABLE, &CDlgUser::OnNMDblclkListtable)
	ON_NOTIFY(NM_CLICK, IDC_LISTTABLE, &CDlgUser::OnNMClickListtable)

	ON_BN_CLICKED(IDC_BUTTON_NUM_SET, &CDlgUser::OnBnClickedButtonNumSet)

	ON_BN_CLICKED(IDC_CHECKWINDOWORDER, &CDlgUser::OnBnClickedCheckwindoworder)

	ON_BN_CLICKED(IDC_CHECKHIDEPATIENT, &CDlgUser::OnBnClickedCheckhidepatient)
	ON_BN_CLICKED(IDC_CHECKHIDWINDOW, &CDlgUser::OnBnClickedCheckhidwindow)
	ON_BN_CLICKED(IDC_CHECKSHOWRIGHT, &CDlgUser::OnBnClickedCheckshowright)
	ON_BN_CLICKED(IDC_CHECKCONSULTORDER, &CDlgUser::OnBnClickedCheckconsultorder)
	ON_BN_CLICKED(IDC_CHECK_MEANS, &CDlgUser::OnBnClickedCheckMeans)
	ON_CBN_SELCHANGE(IDC_COMBOAPP, &CDlgUser::OnCbnSelchangeComboapp)
	ON_BN_CLICKED(IDC_CHECK_HIDE_BOTTOM, &CDlgUser::OnBnClickedCheckHideBottom)
	ON_CBN_SELCHANGE(IDC_COMBO_BACKGROUND, &CDlgUser::OnCbnSelchangeComboBackground)
	ON_CBN_SELCHANGE(IDC_COMBOFONTCOLOR, &CDlgUser::OnCbnSelchangeCombofontcolor)
	ON_BN_CLICKED(IDC_BUTTON_RADIO3, &CDlgUser::OnBnClickedButtonRadio3)
	ON_BN_CLICKED(IDC_BUTTON_RADIO4, &CDlgUser::OnBnClickedButtonRadio4)
	ON_BN_CLICKED(IDC_BUTTON_RADIO5, &CDlgUser::OnBnClickedButtonRadio5)
	ON_CBN_SELCHANGE(IDC_TYPEMODE, &CDlgUser::OnCbnSelchangeTypemode)
	ON_BN_CLICKED(IDC_BUTTON_VIEW, &CDlgUser::OnBnClickedButtonView)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD, &CDlgUser::OnBnClickedButtonUpload)
END_MESSAGE_MAP()


// CDlgUser 消息处理程序

void CDlgUser::InitUserReportCtrl()
{
	UINT nColWidth = 50;
	m_UserReportCtrl.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);
	m_UserReportCtrl.InsertColumn(0, _T("选择"), LVCFMT_CENTER, nColWidth);
	//m_UserReportCtrl.InsertColumn(1, _T("序号"), LVCFMT_CENTER, nColWidth);
	m_UserReportCtrl.InsertColumn(1, _T("主机号"), LVCFMT_CENTER, nColWidth * 1.7);
	m_UserReportCtrl.InsertColumn(2, _T("语音箱号"), LVCFMT_CENTER, nColWidth*1.7);
	m_UserReportCtrl.InsertColumn(3, _T("IP"), LVCFMT_CENTER, nColWidth * 1.7);

	InitListTable();
	InitListTable_ConsultingRoom();
	InitUserComBox();

	m_x.SetWindowText(_T("0"));
	m_Y.SetWindowText(_T("0"));
	m_height.SetWindowText(_T("1080"));
	m_width.SetWindowText(_T("1920"));
	m_row.SetWindowText(_T("4"));
	m_voice.SetWindowText(_T("5"));
	m_percent.SetWindowText(_T("33"));

}
//one 
void CDlgUser::backgroundcolor()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("默认"));
	m_backgroundcolor.AddString(_T("红色"));
	m_backgroundcolor.AddString(_T("橙色"));
	m_backgroundcolor.AddString(_T("黄色"));
	m_backgroundcolor.AddString(_T("绿色"));
	m_backgroundcolor.AddString(_T("青色"));
	m_backgroundcolor.AddString(_T("蓝色"));
	m_backgroundcolor.AddString(_T("紫色"));
	m_backgroundcolor.AddString(_T("白色"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("默认"));
}

void CDlgUser::patientsimpleshow()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("简易图标"));
	m_backgroundcolor.AddString(_T("经典模式"));
	m_backgroundcolor.AddString(_T("标准模式"));
	m_backgroundcolor.AddString(_T("大屏翻页"));
	m_backgroundcolor.AddString(_T("信息统计模式"));
	m_backgroundcolor.AddString(_T("简约模式"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("简易图标"));
}

void CDlgUser::InformationStatueMode()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("复位取消模式"));
	m_backgroundcolor.AddString(_T("更新模式"));
	m_backgroundcolor.AddString(_T("记录模式"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("复位取消模式"));
}

void CDlgUser::InformationBorderMassage()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("本地数据源"));
	m_backgroundcolor.AddString(_T("HIS数据源(不含本地留言)"));
	m_backgroundcolor.AddString(_T("HIS数据源(含本地留言)"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("本地数据源"));
}

void CDlgUser::HideAllSHOW()
{
	GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LETTER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKSHOWRIGHT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKCONSULTORDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_FONTCOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBOFONTCOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_BACKGROUND2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TYPEMODE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BADNUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_HIDE);
	//清空
	GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(_T(""));
	GetDlgItem(IDC_LETTER)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T(""));
	GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("隐藏过号病人显示"));
	UINT nColWidth = 25;
	if (mode == 1)
	{
		if (sum<1)
		{
			sum++;
			int nCols = m_listtable.GetHeaderCtrl()->GetItemCount();
			for (int j = 0; j < nCols; j++)
			{
				m_listtable.DeleteColumn(0);
			}
			m_listtable.DeleteAllItems();
			m_listtable.InsertColumn(0, _T("是否居中"), LVCFMT_CENTER, nColWidth*2.5);
			m_listtable.InsertColumn(1, _T("宽度%"), LVCFMT_CENTER, nColWidth * 3);
			m_listtable.InsertColumn(2, _T("列标题"), LVCFMT_CENTER, nColWidth * 2.7);
		}
	}
	if (mode == 0)
	{
		if (sum >0)
		{
			sum = 0;
			int nCols = m_listtable.GetHeaderCtrl()->GetItemCount();
			for (int j = 0; j < nCols; j++)
			{
				m_listtable.DeleteColumn(0);
			}
			m_listtable.DeleteAllItems();
			m_listtable.InsertColumn(0, _T("启用"), LVCFMT_CENTER, nColWidth*1.5);
			m_listtable.InsertColumn(1, _T("表头"), LVCFMT_CENTER, nColWidth * 3);
			m_listtable.InsertColumn(2, _T("宽度%"), LVCFMT_CENTER, nColWidth * 2.2);
			m_listtable.InsertColumn(3, _T("顺序"), LVCFMT_CENTER, nColWidth * 1.5);
		}
	}
	//mode 为修改CListCtrl的表头标志位
	mode = 0;
	//设置复选框默认不被选中
	m_windoworder.SetCheck(0);
	m_HidePatient.SetCheck(0);
	m_HideWindow.SetCheck(0);
	m_isHideBottom.SetCheck(0);
	m_ShowRight.SetCheck(0);
	m_ConsultOrder.SetCheck(0);
}

void  CDlgUser::fontcolorcolor()
{
	m_fontcolor.ResetContent();
	m_fontcolor.AddString(_T("默认"));
	m_fontcolor.AddString(_T("红色"));
	m_fontcolor.AddString(_T("橙色"));
	m_fontcolor.AddString(_T("黄色"));
	m_fontcolor.AddString(_T("绿色"));
	m_fontcolor.AddString(_T("青色"));
	m_fontcolor.AddString(_T("蓝色"));
	m_fontcolor.AddString(_T("紫色"));
	m_fontcolor.AddString(_T("白色"));
	SetDlgItemText(IDC_COMBOFONTCOLOR, _T("默认"));
}

void  CDlgUser::typemode()
{
	m_Typemode.ResetContent();
	m_Typemode.AddString(_T("标准模式"));
	m_Typemode.AddString(_T("经典模式"));
	SetDlgItemText(IDC_TYPEMODE, _T("经典模式"));
}

BOOL CDlgUser::InitUserComBox()
{
	m_ComboBox_App.AddString(_T("医院"));
	m_ComboBox_App.AddString(_T("银行"));
	m_ComboBox_App.AddString(_T("监狱"));
	m_ComboBox_App.AddString(_T("网络对讲"));
	m_ComboBox_App.AddString(_T("养老院"));  
	m_ComboBox_App.AddString(_T("信息发布"));

	SetDlgItemText(IDC_COMBO1, _T("默认"));
	
	BackGroundColor = "fdf705";
	FontColor = "fdf705";
	Typemode = "标准模式";

	GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_FONTCOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBOFONTCOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_HIDE);
	return TRUE;
}


void CDlgUser::OnCbnSelchangeCombouser()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;

	m_UserComboBox.GetLBText(m_UserComboBox.GetCurSel(), templetstr);
	if (strcmp(T2A(templetstr), "门诊/体检 - 诊室显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP2);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 14;
		HideAllSHOW();
		InitListTable_ConsultingRoom();
		
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("诊室名称："));
	}
	else if (strcmp(T2A(templetstr), "门诊/体检 - 候诊主显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP4);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 0;
		HideAllSHOW();
		InitListTable_WaitingRoom();
		
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 等候显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP7);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 200;
		HideAllSHOW();
		InitListTable_BankWaitingRoom();
		
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("是否翻页显示"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP："));
	}
	else if (strcmp(T2A(templetstr),"银行排队 - 窗口显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP23);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 201;
		fontcolorcolor();
		backgroundcolor();

		HideAllSHOW();
		InitBankWindow();
		
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("时间同步服务器IP："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("上传暂停信息设置"));
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("窗口号："));
		GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDWINDOW)->SetWindowText(_T("隐藏叫号显示框"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  背景颜色
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("背景颜色"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
		//IDC_STATIC_FONTCOLOR: IDC_COMBOFONTCOLOR   字体颜色
		GetDlgItem(IDC_STATIC_FONTCOLOR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FONTCOLOR)->SetWindowText(_T("字体颜色"));
		GetDlgItem(IDC_COMBOFONTCOLOR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("上传图片："));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "信息发布系统客户端") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP3);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 29;
		HideAllSHOW();
		m_listtable.DeleteAllItems();
		
	}
	else if (strcmp(T2A(templetstr), "手术公告显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP10);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 35;
		HideAllSHOW();
		InitListTable_HospitalRoom();
		

		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示   ："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("列表标题："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "门诊/体检 - 候诊辅显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP13);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 22;

		HideAllSHOW();
		InitListTable_WaitingRoom2();
		
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKSHOWRIGHT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "取药/输液 - 等候显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP15);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 5;

		HideAllSHOW();
		InitListTable_MedicineWaitingRoom();
		
	}
	else if (strcmp(T2A(templetstr), "取药/输液 - 窗口显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP17);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 6;

		HideAllSHOW();
		InitListTable_MedicineWindow();
		
	}
	else if (strcmp(T2A(templetstr), "取药/输液 - 等候显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP19);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 30;
		HideAllSHOW();
		InitListTable_MedicineWaitingRoom2();
		
		
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "取药/输液 - 过号显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP20);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 31;
		HideAllSHOW();
		InitListTable_MedicineWindow();   //Same as Window
		
		
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_HIDE);
	}
	else if (strcmp(T2A(templetstr), "取药 - 液晶主显示屏3") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP21);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 20;
		HideAllSHOW();
		InitListTable_MedicineScreen();
		
	}  
	//--------------------------------------------------------------------
	else if (strcmp(T2A(templetstr), "门诊 - 诊室显示屏5") == 0)  //changed
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP69);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 39;   //-------------
		HideAllSHOW();
		InitListTable_ShowRoom5();  //----------
		//IDC_STATIC_LETTER: IDC_LETTER
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("诊室名称："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("logo图片："));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "门诊/体检 - 候诊主显示屏2") == 0)  //changed
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP24);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 23;   //-------------
		HideAllSHOW();
		InitListTable_WaitingRoom();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "门诊 - 诊室显示屏2") == 0)  //changed
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP68);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 34;   //-------------
		HideAllSHOW();
		InitListTable_ConsultingRoom();  //----------
		
		//IDC_STATIC_LETTER: IDC_LETTER
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("诊室名称："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("logo图片："));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "门诊/体检 - 候诊辅显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP25);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 8;   //-------------
		HideAllSHOW();
		InitListTable_SecondWaitingRoom();  //----------
		
	}

	else if (strcmp(T2A(templetstr), "门诊 - 诊室叫号屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP26);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 36;   //-------------
		HideAllSHOW();
		InitListTable_call();  //----------
		
		//IDC_STATIC_LETTER: IDC_LETTER
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("列表标题："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("列表标题"));
	}
	else if (strcmp(T2A(templetstr), "门诊 - 候诊主显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP27);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 19;   //-------------
		HideAllSHOW();
		InitListTable_WaitShow2();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "等候显示屏(条形屏)") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP28);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 37;   //-------------
		HideAllSHOW();
		InitListTable_ConsultingRoom();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "分诊 - 候诊区辅显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP30);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 10;   //-------------
		HideAllSHOW();
		InitListTable_WaitSecond2();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "分诊 - 候诊区辅显示屏3") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP31);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 12;   //-------------
		HideAllSHOW();
		InitListTable_WaitSecond3();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "分诊 - 候诊区辅显示屏5") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP32);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 16;   //-------------
		HideAllSHOW();
		InitListTable_WaitSecond5();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "分诊 - 候诊区辅显示屏6") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP33);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 21;   //-------------
		typemode();
		HideAllSHOW();
		InitListTable_WaitSecond6();  //----------D
		
		GetDlgItem(IDC_STATIC_BACKGROUND2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND2)->SetWindowText(_T("显示："));
		GetDlgItem(IDC_TYPEMODE)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "分诊 - 液晶诊室显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP34);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 4;   //-------------
		HideAllSHOW();
		InitListTable_TriageShow();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "分诊 - 液晶诊室显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP35);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 11;   //-------------
		HideAllSHOW();
		InitListTable_TriageShow2();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "信息看板") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		//设置为1
		OnBnClickedButtonRadio3();

		bitmap.LoadBitmap(IDB_BITMAP36);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 7;   //-------------
		InformationBorderMassage();
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_BADNUM)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_SHOW);
		//IDC_CHECKWINDOWORDER  按窗口排序 
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("显示最低护理级别"));
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    诊室名称  (区号没有传过去！！！)
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("区号:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("0"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND背景颜色
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("数据源:"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
		//IDC_BAD_SET   病床显示设置
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("病床显示设置"));
		//IDC_BUTTON_RADIO3   根据主机显示病床数
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("根据主机显示病床数"));
		//IDC_BUTTON_RADIO4	自动显示病床数
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("自动显示病床数"));
		//IDC_BUTTON_RADIO5 手动设置病床数
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("手动设置病床数"));
	}
	else if (strcmp(T2A(templetstr), "病员--览表") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP37);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 13;   //-------------
		patientsimpleshow();
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_CHECKWINDOWORDER  按窗口排序
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("启用今日入院"));
		//IDC_CHECKHIDEPATIENT    隐藏过号显示
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("显示空床信息"));
		//IDC_CHECK_HIDE_BOTTOM    是否翻页显示
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("分页页卡自适应"));
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("弹出框透明度:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_LETTER)->SetWindowText(_T("255"));
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  端口
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("弹出框停留时间(秒):"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    诊室名称
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("温馨提示:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("请保持安静~！！！！"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  背景颜色
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("显示："));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "扫码签到显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP38);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 38;   //-------------
		HideAllSHOW();
		InitListTable_ScanCheck();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "走廊显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP39);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 300;   //-------------
		HideAllSHOW();
		InitNetwork_intercom();  //----------  IDC_CHECKWINDOWORDER按窗口排序
		
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("是否无呼叫记录显示"));
	}
	else if (strcmp(T2A(templetstr), "岗亭显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP40);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 301;   //-------------
		HideAllSHOW();
		InitNetwork_intercom();  //----------
		
	}
	else if (strcmp(T2A(templetstr), "开门提示 - 览表") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP41);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 302;   //-------------
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_STATIC_LETEER  : IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "实时监控显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP42);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 303;   //-------------
		HideAllSHOW();
		m_listtable.DeleteAllItems(); //----------
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("实时视频监控待机图片上传"));
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("上传图片："));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "走廊显示屏(条形屏)") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP43);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 304;   //-------------
		HideAllSHOW();
		InitNetwork_intercom();  //----------
		
		//IDC_STATIC_LETEER  : IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "设备信息状态 - 览表") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP44);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 305;   //-------------
		InformationStatueMode();
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_STATIC_LETEER  : IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  背景颜色
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("模式："));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 窗口显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP45);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 202;   //-------------
		mode = 1; //更改表头
		HideAllSHOW();
		InitListTable_MedicineScreen1();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("评价信息:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  端口
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    诊室名称
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("暂停服务信息："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 窗口显示屏3") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP46);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 206;   //-------------
		HideAllSHOW();
		InitBanksort_Window3();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 叫号屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP47);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 205;   //-------------
		HideAllSHOW();
		InitBanksort();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 主显示屏2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP48);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 203;   //-------------
		HideAllSHOW();
		InitListTable_Bankshow2();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "银行排队 - 窗口显示屏(条形屏)") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP49);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 204;   //-------------
		HideAllSHOW();
		InitBankWindow();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("时间同步服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    诊室名称
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("窗口号:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "养老入住 - 览表") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP50);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 400;   //-------------
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_CHECKWINDOWORDER按窗口排序 
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("启用今日入院"));
		//IDC_CHECKHIDEPATIENT隐藏过号显示
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("显示心率，呼吸率指标"));
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    诊室名称
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		//IDC_STATIC_LETTER  : IDC_LETTER    留言
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("呼叫，报警弹出框停留时间(秒)："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  端口
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("床位页面翻动切换时间(秒)："));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T("10"));
		//IDC_BAD_SET   病床显示设置
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("床位显示设置"));
		//IDC_BUTTON_RADIO3   根据主机显示病床数
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("根据主机显示床位数"));
		//IDC_BADNUM	自动显示病床数
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("显示入住床位，空床位不显示"));
	}
	else if (strcmp(T2A(templetstr), "探访排队 - 等候显示屏") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP22);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 100;
		HideAllSHOW();
		InitListTable_Prison();
		
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("是否翻页显示"));
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
	}
	else
	{
		m_template.SetBitmap(NULL);
		TemplateStyle = -1;
	}
}

BOOL CDlgUser::InitListTable_MedicineScreen1()
{
	m_listtable.DeleteAllItems();

	CString Item[5] = { _T(""), _T(""), _T(""), _T(""), _T("") };
	//CString Item[6] = { _T("票号"), _T("姓名"), _T("窗口"), _T("等待人员"),_T("等待票号"),_T("等待人数") };
	CString num[5] = { _T("0"), _T("1"), _T("2"), _T("3"),_T("4") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, _T("20"));
		m_listtable.SetItemText(j, 2, Item[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}
BOOL CDlgUser::InitListTable_MedicineScreen()
{
	m_listtable.DeleteAllItems();

	//CString Item[5] = { _T(""), _T(""), _T(""), _T(""), _T("") };
	CString Item[6] = { _T("票号"), _T("姓名"), _T("窗口"), _T("等待人员"),_T("等待票号"),_T("等待人数") };
	CString num[6] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"), _T("5") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 6; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 6; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_MedicineWaitingRoom2()
{
	m_listtable.DeleteAllItems();

	CString Item[4] = { _T("票号"), _T("姓名"), _T("等待人员"), _T("等待票号") };
	CString num[4] = { _T("0"), _T("1"),_T("2"), _T("3") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 4; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 4; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_MedicineWindow()
{
	m_listtable.DeleteAllItems();

	CString Item[2] = { _T("票号"), _T("姓名") };
	CString num[2] = {_T("0"),_T("1")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 2; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 2; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
	
}

BOOL CDlgUser::InitListTable_MedicineWaitingRoom()
{
	m_listtable.DeleteAllItems();

	CString Item[4] = { _T("票号"), _T("姓名"), _T("窗口"), _T("状态") };
	CString num[4] = {_T("0"),_T("1"),_T("2"),_T("3")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 4; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 4; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_ConsultingRoom()
{	
	m_listtable.DeleteAllItems();
	//UINT nColWidth = 50;
	CString Item[5] = {_T("诊室编号"),_T("票号"),_T("姓名"),_T("等待票号"),_T("等待人员")};
	CString num[5] = {_T("0"),_T("1"),_T("2"),_T("3"),_T("4")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);


	//m_listtable.InsertColumn(0, _T("启用"), LVCFMT_CENTER, nColWidth);
	//m_listtable.InsertColumn(1, _T("表头"), LVCFMT_CENTER, nColWidth*4);
	//m_listtable.InsertColumn(2, _T("宽度%"), LVCFMT_CENTER, nColWidth * 3);
	//m_listtable.InsertColumn(3, _T("顺序"), LVCFMT_CENTER, nColWidth * 2);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}
	
	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}
		
	return TRUE;
}

BOOL CDlgUser::InitListTable()
{
	UINT nColWidth = 25;
	m_listtable.InsertColumn(0, _T("启用"), LVCFMT_CENTER, nColWidth*1.5);
	m_listtable.InsertColumn(1, _T("表头"), LVCFMT_CENTER, nColWidth * 3);
	m_listtable.InsertColumn(2, _T("宽度%"), LVCFMT_CENTER, nColWidth * 2.2);
	m_listtable.InsertColumn(3, _T("顺序"), LVCFMT_CENTER, nColWidth * 1.5);

	m_videoAdv.EnableWindow(false);
	m_characterAdv.EnableWindow(false);
	GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LETTER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKSHOWRIGHT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECKCONSULTORDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_DEVICE_IP)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_15)->ShowWindow(SW_HIDE);

	return TRUE;
}
BOOL CDlgUser::InitListTable_ShowRoom5()   //39    1<<7,1<<0,1<<11,1<<17,1<<1
{
	m_listtable.DeleteAllItems();  //LBFIELD_ROOM_CODE +LBFIELD_NUMBER +LBFIELD_NAME +LBFIELD_TOBEPATIENT_NUMBER +LBFIELD_WAITING_PATIENT

	CString Item[5] = { _T("诊室编号"), _T("票号"), _T("姓名"), _T("等待票号"), _T("等待人员") };
	CString num[5] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitingRoom()    //0     有了
{
	m_listtable.DeleteAllItems();
	
	CString Item[8] = { _T("票号"), _T("姓名"), _T("科室"), _T("门诊类别"),_T("诊室编号"),_T("诊室名称"),_T("医生"),_T("备注") };
	CString num[8] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 8; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 8; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_ScanCheck()
{
	m_listtable.DeleteAllItems();	
	//    LBFIELD_NAME+ LBFILED_ROOM_NMAE+ LBFIELD_ROOM_CODE+ LBFIELD_DESCRIPTION  + LBFIELD_WAITING_PATIENT+ LBFIELD_WAITING_COUNT+ LBFIELD_MESSAGE
	CString Item[7] = {  _T("姓名"), _T("诊室名称"), _T("诊室编号"), _T("备注"), _T("等待人员"), _T("等待人数"), _T("信息") };
	CString num[7] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"), _T("5"), _T("6") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 7; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 7; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_SecondWaitingRoom()   //8      1<<0,1<<1,1<<2,1<<4,1<<7,1<<19,1<<5,1<<12,1<<11,1<<17
{
	m_listtable.DeleteAllItems();		//LBFIELD_NUMBER +LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_OUTPATIENT_SERVICE +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFILED_DOCTOR +LBFIELD_WAITING_COUNT +LBFIELD_WAITING_PATIENT +LBFIELD_TOBEPATIENT_NUMBER 

	CString Item[10] = { _T("票号"), _T("姓名"), _T("科室"), _T("门诊类别"),_T("诊室编号"),_T("诊室名称"),_T("医生"),_T("等待人数"),_T("等待人员"),_T("等待票号") };
	CString num[10] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7"),_T("8"),_T("9") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 10; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 10; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitSecond3()    //12       1<<0,1<<1,1<<2,1<<4,1<<5,1<<7,1<<19
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_OUTPATIENT_SERVICE +LBFILED_DOCTOR  +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE 

	CString Item[7] = { _T("票号"), _T("姓名"), _T("科室"), _T("门诊类别"),_T("医生"),_T("诊室编号"),_T("诊室名称") };
	CString num[7] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 7; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 7; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitSecond5()  //16   1<<0,1<<1,1<<2,1<<5,1<<7,1<<19,1<<11,1<<17,1<<10
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_DOCTOR +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFIELD_WAITING_PATIENT +LBFIELD_TOBEPATIENT_NUMBER +LBFIELD_DESCRIPTION 

	CString Item[9] = { _T("票号"), _T("姓名"), _T("科室"),_T("医生"),_T("诊室编号"),_T("诊室名称"),_T("等待人员"),_T("等待票号"),_T("备注") };
	CString num[9] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7"),_T("8") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 9; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 9; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitSecond6()  //21    1<<0,1<<1,1<<2,1<<5,1<<7,1<<19,1<<11,1<<17,1<<10,1<<23
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_DOCTOR +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFIELD_WAITING_PATIENT +LBFIELD_TOBEPATIENT_NUMBER +LBFIELD_DESCRIPTION +LBFIELD_INITSCREEN 

	CString Item[10] = { _T("票号"), _T("姓名"), _T("科室"),_T("医生"),_T("诊室编号"),_T("诊室名称"),_T("等待人员"),_T("等待票号"), _T("备注"), _T("初始化显示屏") };
	CString num[10] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7"),_T("8"),_T("9") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 10; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 10; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitSecond2()    //10   1<<7,1<<19,1<<5,1<<2,1<<4,1<<0,1<<1,1<<17,1<<11
{
	m_listtable.DeleteAllItems();	//LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFILED_DOCTOR +LBFILED_DEPARTMENTS +LBFILED_OUTPATIENT_SERVICE +LBFIELD_NUMBER +LBFIELD_NAME +LBFIELD_TOBEPATIENT_NUMBER +LBFIELD_WAITING_PATIENT 

	CString Item[9] = { _T("诊室编号"), _T("诊室名称"), _T("医生"), _T("科室"),_T("门诊类别"),_T("票号"),_T("姓名"),_T("等待票号"),_T("等待人员") };
	CString num[9] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7"),_T("8") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 9; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 9; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitShow2()   //19     1<<0,1<<1,1<<2,1<<4,1<<7,1<<19,1<<5,1<<10,1<<14
{
	m_listtable.DeleteAllItems();	////LBFIELD_NUMBER +LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_OUTPATIENT_SERVICE +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFILED_DOCTOR +LBFIELD_DESCRIPTION +LBFIELD_SENTRY_STATE 

	CString Item[9] = { _T("票号"), _T("姓名"), _T("科室"), _T("门诊类别"),_T("诊室编号"),_T("诊室名称"),_T("医生"),_T("备注"),_T("状态") };
	CString num[9] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"),_T("5"),_T("6"),_T("7"),_T("8") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 9; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 9; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_call()   //36    1<<1,1<<2,1<<5,1<<11,1<<19
{
	m_listtable.DeleteAllItems();	//LBFIELD_NAME +LBFILED_DEPARTMENTS +LBFILED_DOCTOR +LBFIELD_WAITING_PATIENT +LBFILED_ROOM_NMAE 

	CString Item[5] = { _T("姓名"), _T("科室"), _T("医生"),_T("等待人员"),_T("诊室名称") };
	CString num[5] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_TriageShow()   //4    1<<7,1<<0,1<<1
{
	m_listtable.DeleteAllItems();  //LBFIELD_ROOM_CODE +LBFIELD_NUMBER +LBFIELD_NAME 
	
	CString Item[3] = { _T("诊室编号"),_T("票号"),_T("姓名")};
	CString num[3] = { _T("0"),_T("1"),_T("2") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 3; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 3; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_TriageShow2()   //11   1<<5,1<<16,1<<0,1<<1,1<<17.1<<11
{
	m_listtable.DeleteAllItems();	//LBFILED_DOCTOR +LBFIELD_TITLES +LBFIELD_NUMBER +LBFIELD_NAME +LBFIELD_TOBEPATIENT_NUMBER +LBFIELD_WAITING_PATIENT 

	CString Item[6] = { _T("医生"),_T("职称"),_T("票号"),_T("姓名"),_T("等待票号"),_T("等待人员") };
	CString num[6] = { _T("0"),_T("1"),_T("2"),_T("3"),_T("4"),_T("5") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 6; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 6; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_WaitingRoom2()  //22    1<<0,1<<1,1<<18,1<<7,1<<19,1<<11,1<<17,1<<10,1<<20
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +LBFIELD_DEPARTMENT_DOCTOR +LBFIELD_ROOM_CODE +LBFILED_ROOM_NMAE +LBFIELD_WAITING_PATIENT +LBFIELD_TOBEPATIENT_NUMBER +LBFILED_DESCRIPTION +LBFIELD_WAIT_DESCRIPTION 

	CString Item[9] = { _T("票号"), _T("姓名"), _T("科室医生"), _T("诊室编号"), _T("诊室名称"), _T("等待人员"), _T("等待票号"), _T("备注"), _T("等待备注")};
	CString num[9] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("7"), _T("8")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 9; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 9; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("10"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_BankWaitingRoom()  //200     1<<0,1<<9,1<<8,1<<4,1<<9,1<<12
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFILED_STATE +LBFILED_WINDOW+LBFILED_OUTPATIENT_SERVICE+LBFILED_STATE +LBFIELD_WAITING_COUNT
	CString Item[5] = { _T("票号"), _T("窗口"), _T("门诊类别"), _T("状态"), _T("等待人数") };
	CString num[5] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_Bankshow2()  //203   有
{
	m_listtable.DeleteAllItems();
	CString Item[3] = { _T("票号"),_T("窗口"),_T("状态")};
	CString num[3] = { _T("0"), _T("1"), _T("2")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 3; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 3; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitListTable_Prison()   //100  1<<0,1<<6,1<<1,1<<8,1<<3
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_FAMILY +LBFIELD_NAME +LBFIELD_WINDOW +LBFIELD_PRISON_SECTITON 
	CString Item[5] = { _T("票号"), _T("家属"), _T("姓名"), _T("窗口"), _T("监区") };
	CString num[5] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 5; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 5; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}
	
	return TRUE;
}

BOOL CDlgUser::InitListTable_HospitalRoom()   //有
{

	m_listtable.DeleteAllItems();
	CString Item[9] = { _T("时间"), _T("手术间"), _T("姓名"), _T("科室"), _T("手术名称"), _T("医生"), _T("等级"), _T("麻醉医生"), _T("状态") };
	CString num[9] = { _T("0"), _T("1"), _T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("7"), _T("8") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 9; i++)
	{
		m_listtable.InsertItem(i,_T(""));
	}

	for (int j = 0; j < 9; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitBankWindow()    //204    1<<8,1<<0
{
	m_listtable.DeleteAllItems();	//LBFIELD_WINDOW +LBFIELD_NUMBER 
	CString Item[2] = { _T("窗口"), _T("票号") };
	CString num[2] = { _T("0"), _T("1") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 2; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 2; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitNetwork_intercom()   //300,301,304   1<<13,1<<9
{
	m_listtable.DeleteAllItems();	//LBFIELD_MESSAGE +LBFIELD_STATE 
	CString Item[2] = { _T("信息"), _T("状态") };
	CString num[2] = { _T("0"), _T("1") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 2; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 2; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitBanksort_Window3()   //206   1<<1,1<<0,1<<7,1<<13
{
	m_listtable.DeleteAllItems();	//LBFIELD_NAME +LBFIELD_NUMBER +LBFIELD_ROOM_CODE +LBFIELD_MESSAGE 
	CString Item[4] = { _T("姓名"), _T("票号"), _T("诊室编号"), _T("信息") };
	CString num[4] = { _T("0"), _T("1"), _T("2"), _T("3") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 4; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 4; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::InitBanksort()    //205    操作人员没有  1<<0,1<<1,1<<  ,1<<8,1<<13,1<<10
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +  +LBFIELD_WINDOW +LBFIELD_MESSAGE +LBFIELD_DESCRIPTION 
	CString Item[6] = { _T("票号"), _T("姓名"), _T("操作人员"), _T("窗口") ,_T("信息"), _T("备注") };
	CString num[6] = { _T("0"), _T("1"), _T("2") ,_T("3"), _T("4") ,_T("5") };
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	for (int i = 0; i < 6; i++)
	{
		m_listtable.InsertItem(i, _T(""));
	}

	for (int j = 0; j < 6; j++)
	{
		m_listtable.SetItemText(j, 1, Item[j]);
		m_listtable.SetItemText(j, 2, _T("100"));
		m_listtable.SetItemText(j, 3, num[j]);
		m_listtable.SetCheck(j);
	}

	return TRUE;
}

BOOL CDlgUser::RefreshDeviceList()
{
	m_UserReportCtrl.DeleteAllItems();

	CppSQLite3DB db;
	CppSQLite3Table table;
	CString str;
	int num;
	char sql[512] = { 0 };

	db.open(LB_SCREEN_DB);

	sprintf(sql, "select DISTINCT master_number, slave_number, ip from %s ", LB_SCREENINFO);
	table = db.getTable(sql);
	for (int i = 0; i < table.numRows(); ++i)
	{
		table.setRow(i);

		m_UserReportCtrl.InsertItem(i, _T(""));

		num = table.getIntField(0);
		str.Format(_T("%d"), num);
		m_UserReportCtrl.SetItemText(i, 1, str);

		num = table.getIntField(1);
		str.Format(_T("%d"), num);
		m_UserReportCtrl.SetItemText(i, 2, str);

		//num = table.getIntField(2);
		//str.Format(_T("%d"), num);
		//m_UserReportCtrl.SetItemText(i, 3, str);

		str = table.getStringField(2);
		m_UserReportCtrl.SetItemText(i, 3, str);
	}

	db.close();
	return TRUE;
}

LRESULT CDlgUser::OnCountDeviceNumMsg(WPARAM wParam, LPARAM lParam)  //响应消息刷新界面
{
	RefreshDeviceList();

	return TRUE;
}

void CDlgUser::OnBnClickedButtonrefreshlist()
{
	// TODO:  在此添加控件通知处理程序代码
	//RefreshDeviceList();
	lb_broadcast_screen();
}


void CDlgUser::OnBnClickedUsersettemplate()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;
	int checknum = 0;
	CString Ip;
	for (int i = 0; i < m_UserReportCtrl.GetItemCount(); i++)
	{
		BOOL bchecked = m_UserReportCtrl.GetCheck(i);  //m_UserReportCtrl的选择是check类型的
		if (bchecked)
		{
			checknum++;
			Ip = m_UserReportCtrl.GetItemText(i, 3);
			master_num = m_UserReportCtrl.GetItemText(i,1);
			slave_num = m_UserReportCtrl.GetItemText(i,2);
			SendScreenProperty(Ip);
		}
	}
	if (CheckMeans == 1)
	{
		m_Means_DeviceIP.GetWindowText(Ip);
		if (strlen(T2A(Ip)) > 0)
		{
			SendScreenProperty(Ip);
		}
		else
		{
			MessageBox(_T("请在指定位置输入要设置模板的IP！"));
		}
		
	}
	else if (checknum < 1 && CheckMeans == 0)
	{
		MessageBox(_T("请先选择要设置模板的设备或者使用方式二输入指定设备的IP！"));
	}
	
	//else if (TemplateStyle >= 0 && Check != 0)
	//{
		//MessageBox(_T("设置模板成功！"));
	//}
}

BOOL CDlgUser::SendScreenProperty(CString ScreenIp)
{
	::AllocConsole();
	FILE *fp;
	freopen_s(&fp, "CONOUT$", "w+t", stdout);
	char msg[1024];
	char sql[2048] = { 0 };
	char *pos = NULL;
	char head_string[1024] = { 0 };
	int definedValue = 0;
	USES_CONVERSION;
	CString title, Subtitle, X, Y, height, width, row, voice, percent, consultname, head_name, head_width, head_seq, server_directory,lb_list_title,Infoserver_port,area_number;
	//MessageBox(ScreenIp);
	m_title.GetWindowText(title);     //主标题
	m_subtitle.GetWindowText(Subtitle);    //副标题
	m_x.GetWindowText(X);     //左上角X轴
	m_Y.GetWindowText(Y);     ////左上角Y轴
	m_height.GetWindowText(height);    //显示屏高度
	m_width.GetWindowText(width);      //显示屏宽度
	m_row.GetWindowText(row);      //行数
	m_voice.GetWindowText(voice);  //声音
	m_percent.GetWindowText(percent);     //广告比例
	
	if (TemplateStyle == 14 || TemplateStyle == 34)
	{
		int head_title_name[5] = { 1<<7, 1<<0, 1<<1, 1<<17, 1<<11 };
		definedValue = LBFIELD_ROOM_CODE + LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_TOBEPATIENT_NUMBER + LBFIELD_WAITING_PATIENT;
		char string[5][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4]);
	}
	else if (TemplateStyle == 0)
	{
		int head_title_name[8] = { 1<<0, 1<<1, 1<<2, 1<<4, 1<<7, 1<<19, 1<<5, 1<<10 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFILED_DOCTOR + LBFILED_DESCRIPTION;
		char string[8][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s", string[0],string[1],string[2],string[3],string[4],string[5],string[6],string[7]);
	}
	else if (TemplateStyle == 203 )//|| TemplateStyle == 200
	{
		int head_title_name[3] = { 1<<0, 1<<8, 1<<9 };
		definedValue = LBFIELD_NUMBER + LBFILED_WINDOW + LBFILED_STATE;
		char string[3][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s", string[0],string[1],string[2]);
	}
	else if (TemplateStyle == 39)
	{
		int head_title_name[5] = { 1 << 7, 1 << 0, 1 << 11, 1 << 17, 1 << 1 };
		definedValue = LBFIELD_ROOM_CODE + LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_TOBEPATIENT_NUMBER + LBFIELD_WAITING_PATIENT;
		char string[5][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4]);

	}
	else if (TemplateStyle == 35)
	{
		int head_title_name[9] = { 1<<25,1<<24,1<<1,1<<2,1<<26,1<<5,1<<27,1<<28,1<<9 };
		definedValue = LBFILED_TIME + LBFILED_OPERATION_ROOM + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OPERATION_NAME + LBFILED_DOCTOR + LBFILED_LEVEL + LBFILED_ANESTHETIST + LBFILED_STATE;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7],string[8]);

	}
	else if (TemplateStyle == 22)
	{
		int head_title_name[9] = { 1<<0, 1<<1, 1<<18, 1<<7, 1<<19, 1<<11, 1<<17, 1<<10, 1<<20 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_DEPARTMENT_DOCTOR + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER + LBFILED_DESCRIPTION + LBFILED_WAIT_DESCRIPTION;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);
	}
	else if (TemplateStyle == 23)
	{
		int head_title_name[8] = { 1 << 0, 1 << 1, 1 << 2, 1 << 4, 1 << 7, 1 << 19, 1 << 5, 1 << 20 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFILED_DOCTOR + LBFILED_WAIT_DESCRIPTION;
		char string[8][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7]);
	}
	else if (TemplateStyle == 5)
	{   
		int head_title_name[4] = { 1<<0, 1<<1, 1<<8, 1<<9 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_WINDOW + LBFILED_STATE;
		char string[4][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s", string[0], string[1], string[2], string[3]);
	}
	else if (TemplateStyle == 6 || TemplateStyle == 31)
	{
		int head_title_name[2] = { 1 << 0, 1 << 1 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME;
		char string[2][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s", string[0], string[1]);
	}
	else if (TemplateStyle == 30)
	{
		int head_title_name[4] = { 1 << 0, 1 << 1, 1<<11, 1<<17 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER;
		char string[4][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s", string[0], string[1],string[2],string[3]);
	}
	else if (TemplateStyle == 20)
	{
		int head_title_name[6] = { 1 << 0, 1 << 1, 1<<8, 1<<11,1<<17,1<<12};
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_WINDOW + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER + LBFIELD_WAITING_COUNT;
		char string[6][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3],string[4],string[5]);
	}
	else if (TemplateStyle == 100)
	{
		int head_title_name[5] = { 1 << 0, 1 << 6, 1 << 1, 1 << 8, 1 << 3 };
		definedValue = LBFIELD_NUMBER + LBFILED_FAMILY + LBFIELD_NAME + LBFILED_WINDOW + LBFILED_PRISON_SECTION;
		char string[5][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4]);

	}
	else if (TemplateStyle == 200)
	{
		int head_title_name[5] = { 1 << 0, 1 << 8, 1 << 4, 1 << 9, 1 << 12 };
		definedValue = LBFIELD_NUMBER  + LBFILED_WINDOW + LBFILED_OUTPATIENT_SERVICE + LBFILED_STATE + LBFIELD_WAITING_COUNT;
		char string[5][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4]);
	}
	else if (TemplateStyle == 201)
	{
		int head_title_name[2] = { 1 << 8, 1 << 0};
		definedValue = LBFILED_WINDOW + LBFIELD_NUMBER;
		char string[2][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s", string[0], string[1]);
	}
	else if (TemplateStyle == 8)
	{
		int head_title_name[10] = { 1 << 0, 1 << 1, 1 << 2, 1 << 4, 1 << 7, 1 << 19, 1 << 5, 1 << 12, 1 << 11, 1 << 17 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFILED_DOCTOR + LBFIELD_WAITING_COUNT + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER;
		char string[8][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7]);
	}
	else if (TemplateStyle == 12)
	{
		int head_title_name[7] = { 1 << 0, 1 << 1, 1 << 2, 1 << 4, 1 << 5, 1 << 7, 1 << 19 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFILED_DOCTOR + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE;
		char string[7][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6]);
	} //1<<0,1<<1,1<<2,1<<5,1<<7,1<<19,1<<11,1<<17,1<<10
	else if (TemplateStyle == 16)
	{
		int head_title_name[9] = { 1 << 0, 1 << 1, 1 << 2, 1 << 5, 1 << 7, 1 << 19, 1 << 11, 1 << 17, 1 << 10 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_DOCTOR + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER + LBFILED_DESCRIPTION;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);
	}
	else if (TemplateStyle == 10)
	{
		int head_title_name[9] = { 1 << 7, 1 << 19, 1 << 5, 1 << 2, 1 << 4, 1 << 0, 1 << 1, 1 << 17, 1 << 11 };
		definedValue = LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFILED_DOCTOR + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_TOBEPATIENT_NUMBER + LBFIELD_WAITING_PATIENT;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);
	}
	else if (TemplateStyle == 19)
	{
		int head_title_name[9] = { 1 << 0, 1 << 1, 1 << 2, 1 << 4, 1 << 7, 1 << 19, 1 << 5, 1 << 10, 1 << 14 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_OUTPATIENT_SERVICE + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFILED_DOCTOR + LBFILED_DESCRIPTION + LBFIELD_SENTRY_STATE;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);
	}
	else if (TemplateStyle == 36)
	{
		int head_title_name[5] = { 1 << 1, 1 << 2, 1 << 5, 1 << 11, 1 << 19 };
		definedValue = LBFIELD_NAME + LBFILED_DEPARTMENTS + LBFILED_DOCTOR + LBFIELD_WAITING_PATIENT + LBFILED_ROOM_NMAE;
		char string[5][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3],string[4]);
	}
	else if (TemplateStyle == 38)
	{
		int head_title_name[7] = { 1 << 1, 1 << 19, 1 << 7, 1 << 10 , 1 << 11, 1 << 12, 1 << 13 };
		definedValue = LBFIELD_NAME + LBFILED_ROOM_NMAE + LBFIELD_ROOM_CODE + LBFILED_DESCRIPTION + LBFIELD_WAITING_PATIENT + LBFIELD_WAITING_COUNT + LBFIELD_MESSAGE;
		char string[7][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6]);
	}
	else if (TemplateStyle == 4)
	{
		int head_title_name[3] = { 1 << 7, 1 << 0, 1 << 1 };
		definedValue = LBFIELD_ROOM_CODE + LBFIELD_NUMBER + LBFIELD_NAME;
		char string[3][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s", string[0], string[1], string[2]);
	}
	else if (TemplateStyle == 11)
	{
		int head_title_name[6] = { 1 << 5, 1 << 16, 1 << 0, 1 << 1, 1 << 17,1 << 11 };
		definedValue = LBFILED_DOCTOR + LBFIELD_TITLES + LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_TOBEPATIENT_NUMBER + LBFIELD_WAITING_PATIENT;
		char string[6][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5]);
	}
	else if (TemplateStyle == 22)
	{
		int head_title_name[9] = { 1 << 0, 1 << 1, 1 << 18, 1 << 7, 1 << 19, 1 << 11, 1 << 17, 1 << 10, 1 << 20 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFIELD_DEPARTMENT_DOCTOR + LBFIELD_ROOM_CODE + LBFILED_ROOM_NMAE + LBFIELD_WAITING_PATIENT + LBFIELD_TOBEPATIENT_NUMBER + LBFILED_DESCRIPTION + LBFIELD_WAIT_DESCRIPTION;
		char string[9][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);
	}
	else if (TemplateStyle == 204)
	{
		int head_title_name[2] = { 1 << 8, 1 << 0 };
		definedValue = LBFILED_WINDOW + LBFIELD_NUMBER;
		char string[2][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s", string[0], string[1]);
	}
	else if (TemplateStyle == 300 || TemplateStyle == 301 || TemplateStyle == 304)
	{
		int head_title_name[2] = { 1 << 13, 1 << 9 };
		definedValue = LBFIELD_MESSAGE + LBFILED_STATE;
		char string[2][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s", string[0], string[1]);
	}
	else if (TemplateStyle == 206)
	{
		int head_title_name[4] = { 1 << 1, 1 << 0, 1 << 7, 1 << 13 };
		definedValue = LBFIELD_NAME + LBFIELD_NUMBER + LBFIELD_ROOM_CODE + LBFIELD_MESSAGE;
		char string[4][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s", string[0], string[1], string[2], string[3]);
	}
	else if (TemplateStyle == 205)
	{
		int head_title_name[6] = { 1 << 0, 1 << 1, 1 << 5, 1 << 8, 1 << 13, 1 << 10 };
		definedValue = LBFIELD_NUMBER + LBFIELD_NAME + LBFILED_DOCTOR +LBFILED_WINDOW + LBFIELD_MESSAGE + LBFILED_DESCRIPTION;
		char string[6][128];
		for (int i = 0; i < m_listtable.GetItemCount(); i++)
		{
			head_name = m_listtable.GetItemText(i, 1);
			head_width = m_listtable.GetItemText(i, 2);
			head_seq = m_listtable.GetItemText(i, 3);

			BOOL bchecked = m_listtable.GetCheck(i);
			if (bchecked)
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 1, _ttoi(head_seq), head_title_name[i]);
			}
			else
			{
				sprintf(string[i], "%s_%d_%d_%d_%d", T2A(head_name), _ttoi(head_width), 0, _ttoi(head_seq), head_title_name[i]);
			}
		}

		sprintf(head_string, "%s|%s|%s|%s|%s|%s", string[0], string[1], string[2], string[3], string[4], string[5]);
	}
	if (TemplateStyle == 35 || TemplateStyle == 36 || TemplateStyle == 100 || TemplateStyle == 200)     //200的还差一个是否翻页显示
	{
		m_letter.GetWindowText(consultname);            //留言框后面
		m_consultname.GetWindowText(lb_list_title);    //诊室名称后面的
	}
	else
	{
		m_consultname.GetWindowText(consultname);     //诊室名称后面的
		m_letter.GetWindowText(server_directory);    //留言框后面
	}

	if (TemplateStyle == 7 || TemplateStyle == 13 || TemplateStyle == 29 || TemplateStyle == 30 || TemplateStyle == 31 || TemplateStyle == 200 || TemplateStyle == 202 || TemplateStyle == 203 || TemplateStyle == 205 || TemplateStyle == 206 || TemplateStyle == 204)
	{
		m_letter.GetWindowText(server_directory);     //留言框后面
		m_info_server_port.GetWindowText(Infoserver_port);     //端口后面的
	}
	if (TemplateStyle == 7)
	{
		m_consultname.GetWindowText(area_number);   //诊室名称后面的
	}
	if (TemplateStyle == 201)    
	{
		m_letter.GetWindowText(Infoserver_port);       //端口后面的
		//m_consultname.GetWindowText(server_directory);    //留言框后面 
	}
	if (TemplateStyle == -1)
	{
		MessageBox(_T("请先选择模板！"));
	}
	else
	{
		checkadv();
		if (Check != 0)
		{
			sprintf(msg, "%s", "Action:NlvDcInfoData\r\n");
			pos = lb_str_getTail(msg);
			sprintf(pos, "%s", "message:2007\r\n");
			pos = lb_str_getTail(pos);
			sprintf(pos, "style:%d\r\n", TemplateStyle);
			pos = lb_str_getTail(pos);
			sprintf(pos, "lb_clinic_name:%s\r\n", T2A(consultname));   //诊室名称后面的


			if (TemplateStyle == 14 || TemplateStyle == 35 || TemplateStyle == 36 || TemplateStyle == 205 || TemplateStyle == 29 || TemplateStyle == 100 || TemplateStyle == 200 || TemplateStyle == 201 || TemplateStyle == 13 || TemplateStyle == 400)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "tv_message:%s\r\n", T2A(consultname));    //诊室名称后面的
			}
			else
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "tv_message:%s\r\n", T2A(server_directory));    //留言后面的
			}

			if (TemplateStyle == 201)   
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "number_of_screen:%s\r\n", T2A(consultname));    //留言后面的

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_ntpserverIp:%s\r\n", T2A(Infoserver_port));    //留言后面的

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_background_style:%s\r\n", T2A(BackGroundColor));   //背景颜色

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_font_style:%s\r\n", T2A(FontColor));    //字体颜色
			}
			if (TemplateStyle == 13)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "boxstay_opacity:%s\r\n", T2A(server_directory));    
				pos = lb_str_getTail(pos);
				sprintf(pos, "StayTime:%s\r\n", T2A(Infoserver_port));    
			}
			pos = lb_str_getTail(pos);
			sprintf(pos, "isHidenTitle:%d\r\n", isHidenTitle);    //隐藏标题栏
			pos = lb_str_getTail(pos);
			sprintf(pos, "title:%s\r\n", T2A(title));     //主标题
			pos = lb_str_getTail(pos);
			sprintf(pos, "sub_title:%s\r\n",T2A(Subtitle));    //副标题

			pos = lb_str_getTail(pos);
			sprintf(pos, "x0:%d\r\n", _ttoi(X));    //x
			pos = lb_str_getTail(pos);
			sprintf(pos, "y0:%d\r\n", _ttoi(Y));    //y
			pos = lb_str_getTail(pos);
			sprintf(pos, "width:%d\r\n", _ttoi(width));    //width
			pos = lb_str_getTail(pos);
			sprintf(pos, "height:%d\r\n", _ttoi(height));    //height

			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdEnabled:%d\r\n", isAdEnabled);   //广告开关
			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdVideoEnabled:%d\r\n", isAdVideoEnabled);  //视频广告开关
			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdTextEnabled:%d\r\n", isAdTextEnabled);    //文字广告开关
			pos = lb_str_getTail(pos);
			sprintf(pos, "adAreaPercent:%d\r\n", _ttoi(percent));     //广告比例

			pos = lb_str_getTail(pos);
			sprintf(pos, "SystemVoice:%d\r\n", _ttoi(voice));    //声音
			pos = lb_str_getTail(pos);
			sprintf(pos, "number_of_rows:%d\r\n", _ttoi(row));   //行

			pos = lb_str_getTail(pos);
			sprintf(pos, "tableheads_str:%s\r\n", head_string);    //拼接起来的(名称，诊室，医生等等)
			pos = lb_str_getTail(pos);
			sprintf(pos, "SortByOffice:%d\r\n", isWindowOrder);   //按窗口排序
			pos = lb_str_getTail(pos);
			sprintf(pos, "defined_value:%d\r\n", definedValue);    //移位数拼接(1<<1等)
			pos = lb_str_getTail(pos);
			sprintf(pos, "server_directory:%s\r\n", T2A(server_directory));   //留言后面的   服务器目录
			pos = lb_str_getTail(pos);
			sprintf(pos, "lb_list_title:%s\r\n", T2A(lb_list_title));    //诊室后面的   列表标题
			pos = lb_str_getTail(pos);
			sprintf(pos, "lb_infoserver_port:%d\r\n", _ttoi(Infoserver_port));    //端口后面的   服务器端口
			pos = lb_str_getTail(pos);
			sprintf(pos, "area_number:%d\r\n", _ttoi(area_number));    //诊室后面   区号
		//-------------  
			if (TemplateStyle == 22 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //隐藏过号病人
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideCallInfo:%d\r\n", isHideCallInfo);   //隐藏窗口显示框
				pos = lb_str_getTail(pos);
				sprintf(pos, "ShowCallInfoByRight:%d\r\n", ShowCallInfoByRight);   //呼叫右框侧显示
			}
			else if (TemplateStyle == 30 || TemplateStyle == 201)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideCallInfo:%d\r\n", isHideCallInfo);   //隐藏窗口显示框
			}
			else if (TemplateStyle == 100 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHidePrisonBottom:%d\r\n", isHidePrisonBottom);   //是否翻页显示  没有规定协议字符
			}
			else if (TemplateStyle == 13)  //没有isHidePrisonBottom？？？病员--览表
			{
				if ( BackGroundColor == "经典模式" || BackGroundColor == "经典模式")
				{
					pos = lb_str_getTail(pos);
					sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //按窗口排序
					pos = lb_str_getTail(pos);
					sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //隐藏过号病人
					pos = lb_str_getTail(pos);
					sprintf(pos, "ShowModel:%s\r\n", T2A(BackGroundColor));   //背景颜色(相当于显示)
				}
				else
				{
					pos = lb_str_getTail(pos);
					sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //按窗口排序

				}
			}
			else if (TemplateStyle == 21)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "ShowModel:%s\r\n", T2A(Typemode));   //背景颜色(相当于显示)
			}
			else if (TemplateStyle == 7)   //缺少病床显示设置
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isShowLowestLevel:%d\r\n", isWindowOrder);   //按窗口排序
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "lb_background_style:%s\r\n", T2A(BackGroundColor));   //背景颜色(相当于显示)
			}
			else if (TemplateStyle == 300)
			{
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "isWindowOrder:%d\r\n", isWindowOrder);   //是否无呼叫记录显示
			}
			else if (TemplateStyle == 200 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isWindowOrder:%d\r\n", isWindowOrder);   //按窗口排序
			}
			else if (TemplateStyle == 305)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "model:%s\r\n", T2A(BackGroundColor));   //背景颜色(相当于显示)
			}
			else if (TemplateStyle == 400)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //按窗口排序
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //隐藏过号病人    显示心率指标
			}
			
			lb_netio_msg_sendto3(msg, sizeof(msg), T2A(ScreenIp), PORT_NUM_SETTEMPLATE);
			printf("the message is:\n %s\n",msg);
			printf("the screen ip is %s\n", T2A(ScreenIp));

			//存数据库
			CppSQLite3DB db;
			db.open(LB_SCREEN_DB);
			sprintf(sql, "update LBScreentemplate set style = %d,tv_message = '%s',isHidenTitle = %d, title = '%s',sub_title = '%s',x0 = %d, y0 = %d,width = %d,height = %d,isAdEnabled = %d,isAdVideoEnabled = %d,isAdTextEnabled = %d,adAreaPercent = %d,SystemVoice = %d,number_of_columns = %d,tableheads_str = '%s',defined_value = %d where id in(select Screentemplate_id from LBScreenInfo where master_number = %d and slave_number = %d)",
				TemplateStyle, T2A(consultname), isHidenTitle, T2A(title), T2A(Subtitle), _ttoi(X), _ttoi(Y), _ttoi(width), _ttoi(height), isAdEnabled, isAdVideoEnabled, isAdTextEnabled, _ttoi(percent), _ttoi(voice), _ttoi(row), head_string, definedValue, _ttoi(master_num), _ttoi(slave_num));
			db.execDML(sql);
			printf("the sql is %s\n",sql);
			db.close();
			FreeConsole();
			MessageBox(_T("设置模板已发起！"));
			
		}
		
	}
	return TRUE;
}

BOOL CDlgUser::checkadv()
{
	BOOL bcheckhidetitle = m_hidetitle.GetCheck();    //隐藏标题栏
	BOOL bcheckmedadv = m_mediaAdv.GetCheck();    //多媒体广告区
	BOOL bcheckvideoadv = m_videoAdv.GetCheck();    //视频广告
	BOOL bcheckcharacteradv = m_characterAdv.GetCheck();   //文字广告
	if (bcheckhidetitle)
	{
		isHidenTitle = 1;       //隐藏标题栏
	}
	if (bcheckmedadv)
	{
		if (!bcheckcharacteradv && !bcheckvideoadv)
		{
			Check = 0;
			MessageBox(_T("请选择显示的广告类型（视频广告或者文本广告）！"));
		}
		else
		{
			isAdEnabled = 1;   //多媒体广告开关开了
			Check = 1;
		}
	}
	if (bcheckvideoadv)
	{
		if (!bcheckmedadv)
		{
			Check = 0;
			MessageBox(_T("请先选择显示多媒体广告区！"));
		}
		else
		{
			isAdVideoEnabled = 1;     //视频广告开了
			Check = 1;
		}
	}
	else
	{
		isAdVideoEnabled = 0;
		Check = 1;
	}
	if (bcheckcharacteradv)
	{
		if (!bcheckmedadv)
		{
			Check = 0;
			MessageBox(_T("请先选择显示多媒体广告区！"));
		}
		else
		{
			isAdTextEnabled = 1;   //文字广告开了
			Check = 1;
		}
	}
	else
	{
		isAdTextEnabled = 0;
		Check = 1;
	}
	if ((!bcheckcharacteradv) && (!bcheckvideoadv) && (!bcheckmedadv))
	{
		isAdEnabled = 0;
		isAdVideoEnabled = 0;
		isAdTextEnabled = 0;
		Check = 1;
	}
	return TRUE;
}


void CDlgUser::OnBnClickedCheckmedadv()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckmedadv = m_mediaAdv.GetCheck();
	CBitmap bitmap;
	HBITMAP hBmp;
	if (bcheckmedadv)
	{
		m_percent.SetReadOnly(false);
		m_voice.SetReadOnly(false);
		isAdEnabled = 1;
		
		if (TemplateStyle == 0)
		{
			bitmap.LoadBitmap(IDB_BITMAP5);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 200)
		{
			bitmap.LoadBitmap(IDB_BITMAP8);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 5)
		{
			bitmap.LoadBitmap(IDB_BITMAP16);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 6)
		{
			bitmap.LoadBitmap(IDB_BITMAP18);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
//-------------------------------------------------------------
		else if (TemplateStyle == 4)
		{
			bitmap.LoadBitmap(IDB_BITMAP52);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 7)
		{
			bitmap.LoadBitmap(IDB_BITMAP53);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 8)
		{
			bitmap.LoadBitmap(IDB_BITMAP54);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 10)
		{
			bitmap.LoadBitmap(IDB_BITMAP55);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 11)
		{
			bitmap.LoadBitmap(IDB_BITMAP56);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 12)
		{
			bitmap.LoadBitmap(IDB_BITMAP57);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 19)
		{
			bitmap.LoadBitmap(IDB_BITMAP58);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 23)
		{
			bitmap.LoadBitmap(IDB_BITMAP59);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 34)
		{
			bitmap.LoadBitmap(IDB_BITMAP60);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 35)
		{
			bitmap.LoadBitmap(IDB_BITMAP61);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 36)
		{
			bitmap.LoadBitmap(IDB_BITMAP62);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 37)
		{
			bitmap.LoadBitmap(IDB_BITMAP63);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 38)
		{
			bitmap.LoadBitmap(IDB_BITMAP64);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 300)
		{
			bitmap.LoadBitmap(IDB_BITMAP65);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 301)
		{
			bitmap.LoadBitmap(IDB_BITMAP66);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 500)
		{
			bitmap.LoadBitmap(IDB_BITMAP67);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		m_videoAdv.EnableWindow(true);
		m_characterAdv.EnableWindow(true);
		m_videoAdv.SetCheck(1);
		m_characterAdv.SetCheck(1);
	}
	else
	{
		m_percent.SetReadOnly(true);
		m_voice.SetReadOnly(true);
		isAdEnabled = 0;

		if (TemplateStyle == 0)
		{
			bitmap.LoadBitmap(IDB_BITMAP4);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 200)
		{
			bitmap.LoadBitmap(IDB_BITMAP7);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 5)
		{
			bitmap.LoadBitmap(IDB_BITMAP15);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 6)
		{
			bitmap.LoadBitmap(IDB_BITMAP17);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		//-------------------------------------------------------------
		else if (TemplateStyle == 4)
		{
			bitmap.LoadBitmap(IDB_BITMAP34);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 7)
		{
			bitmap.LoadBitmap(IDB_BITMAP36);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 8)
		{
			bitmap.LoadBitmap(IDB_BITMAP25);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 10)
		{
			bitmap.LoadBitmap(IDB_BITMAP30);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 11)
		{
			bitmap.LoadBitmap(IDB_BITMAP35);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 12)
		{
			bitmap.LoadBitmap(IDB_BITMAP31);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 19)
		{
			bitmap.LoadBitmap(IDB_BITMAP27);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 23)
		{
			bitmap.LoadBitmap(IDB_BITMAP24);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 34)
		{
			bitmap.LoadBitmap(IDB_BITMAP60);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 35)
		{
			bitmap.LoadBitmap(IDB_BITMAP10);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 36)
		{
			bitmap.LoadBitmap(IDB_BITMAP26);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 37)
		{
			bitmap.LoadBitmap(IDB_BITMAP28);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 38)
		{
			bitmap.LoadBitmap(IDB_BITMAP38);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 300)
		{
			bitmap.LoadBitmap(IDB_BITMAP65);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 301)
		{
			bitmap.LoadBitmap(IDB_BITMAP39);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		else if (TemplateStyle == 500)
		{
			bitmap.LoadBitmap(IDB_BITMAP3);
			hBmp = (HBITMAP)bitmap.GetSafeHandle();
			m_template.SetBitmap(hBmp);
		}
		m_videoAdv.EnableWindow(false);
		m_characterAdv.EnableWindow(false);
		m_videoAdv.SetCheck(0);
		m_characterAdv.SetCheck(0);
	}
	
}


void CDlgUser::OnBnClickedCheckvideoadv()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckvideoadv = m_videoAdv.GetCheck();
	if (bcheckvideoadv)
	{
		isAdVideoEnabled = 1;
		BOOL bcheckmedadv = m_mediaAdv.GetCheck();
		if (!bcheckmedadv)
		{
			isAdVideoEnabled = 0;
			//m_mediaAdv.SetCheck(false);
			MessageBox(_T("请先选择显示多媒体广告区！"));
		}
	}
	else
	{
		isAdVideoEnabled = 0;
	}
}


void CDlgUser::OnBnClickedCheckcharacteradv()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckcharacteradv = m_characterAdv.GetCheck();
	if (bcheckcharacteradv)
	{
		isAdTextEnabled = 1;
		BOOL bcheckmedadv = m_mediaAdv.GetCheck();
		if (!bcheckmedadv)
		{
			isAdTextEnabled = 0;
			//m_mediaAdv.SetCheck(false);
			MessageBox(_T("请先选择显示多媒体广告区！"));
		}
	}
	else
	{
		isAdTextEnabled = 0;
	}
}


void CDlgUser::OnBnClickedCheckhidetitle()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckhidetitle = m_hidetitle.GetCheck();
	if (bcheckhidetitle)
	{
		m_title.SetReadOnly(TRUE);
		m_subtitle.SetReadOnly(TRUE);
		isHidenTitle = 1;
	}
	else
	{
		m_title.SetReadOnly(false);
		m_subtitle.SetReadOnly(false);
		isHidenTitle = 0;
	}
}

void CDlgUser::OnNMDblclkListtable(NMHDR *pNMHDR, LRESULT *pResult)  //更改编辑框里面的内容
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
	BOOL needSave = false;
	int rowCount = m_listtable.GetItemCount();

	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	CRect  EditRect;    //一个坐标参数

	if (needSave)
	{
		CString  EditStr;
		m_EditVirtual.GetWindowText(EditStr); //获取输入的内容  
		m_listtable.SetItemText(m_Item, m_SubItem, EditStr); //m_Item,m_SubItem这两个变量的值是原来的单元格的值  
	}

	m_Item = pEditCtrl->iItem;
	m_SubItem = pEditCtrl->iSubItem;

	if (m_Item == -1)
	{
		return;
	}

	if (m_Item < rowCount)
	{
		if (m_SubItem >= 1)
		{
			m_listtable.GetSubItemRect(m_Item, m_SubItem, LVIR_LABEL, EditRect);
			needSave = true;
			if (m_EditVirtual.m_hWnd == NULL)
			{
				//创建一个新
				m_EditVirtual.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER,
					CRect(0, 0, 0, 0), this, IDC_EDIT);

				m_EditVirtual.ShowWindow(SW_HIDE);

				CFont tpFont;
				tpFont.CreateStockObject(SYSTEM_FONT);
				m_EditVirtual.SetFont(&tpFont);
				tpFont.DeleteObject();

			}
			m_EditVirtual.SetParent(&m_listtable);

			EditRect.SetRect(EditRect.left, EditRect.top, EditRect.left + m_listtable.GetColumnWidth(m_SubItem), EditRect.bottom);

			CString strItem = m_listtable.GetItemText(m_Item, m_SubItem);
			m_EditVirtual.MoveWindow(&EditRect);
			m_EditVirtual.ShowWindow(SW_SHOW);
			m_EditVirtual.SetWindowText(strItem);
			m_EditVirtual.SetFocus();		//设置为焦点  
			m_EditVirtual.SetSel(0, -1);	//0,-1表示单元格内容全选中  

			needSave = false;
		}
	}
	else
		m_EditVirtual.ShowWindow(SW_HIDE);

	*pResult = 0;

}

void CDlgUser::OnNMClickListtable(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	if (m_EditVirtual.m_hWnd != NULL)
	{
		m_EditVirtual.ShowWindow(SW_HIDE);
		CString  EditStr;
		m_EditVirtual.GetWindowText(EditStr);
		m_listtable.SetItemText(m_Item, m_SubItem, EditStr);

		m_EditVirtual.DestroyWindow();
	}
	*pResult = 0;
}


void CDlgUser::OnBnClickedButtonNumSet()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;
	int checknum = 0;
	CString Ip;
	for (int i = 0; i < m_UserReportCtrl.GetItemCount(); i++)
	{
		BOOL bchecked = m_UserReportCtrl.GetCheck(i);
		if (bchecked)
		{
			checknum++;
			if (checknum < 2)
			{
				Ip = m_UserReportCtrl.GetItemText(i, 3);
				master_num = m_UserReportCtrl.GetItemText(i, 1);
				slave_num = m_UserReportCtrl.GetItemText(i, 2);
				SendScreenSystemSet(Ip);
			}
		}
	}
	if (CheckMeans == 1)
	{
		m_Means_DeviceIP.GetWindowText(Ip);
		if (strlen(T2A(Ip)) > 0)
		{
			SendScreenSystemSet(Ip);
		}
		else
		{
			MessageBox(_T("请在指定位置输入要设置编号信息的设备的IP！"));
		}

	}
	if ((checknum < 1) && (CheckMeans == 0))
	{
		MessageBox(_T("请先选择要设置编号信息的设备！"));
	}
	else if (checknum > 1)
	{
		MessageBox(_T("不能同时设置多个设备的编号信息，第一个勾住的设备设置编号信息成功！"));
	}
	//else 
	//{
	//	MessageBox(_T("设置编号信息成功！"));
	//}

}

BOOL CDlgUser::SendScreenSystemSet(CString ScreenIp)
{
	CString address_box_ip, master_number, slave_number,device_number,device_ip;
	char msg[512];
	char sql[2048] = { 0 };
	char *pos = NULL;

	USES_CONVERSION;
	m_address_box.GetWindowText(address_box_ip);
	m_master_number.GetWindowText(master_number);
	m_slave_number.GetWindowText(slave_number);
	m_device_number.GetWindowText(device_number);
	//m_device_ip.GetWindowText(device_ip);

	if ((strlen(T2A(master_number)) > 0) && (strlen(T2A(slave_number)) > 0) && (strlen(T2A(device_number)) > 0))
	{
		sprintf(msg, "%s", "Action:NlvDcSetData\r\n");
		pos = lb_str_getTail(msg);
		sprintf(pos, "addressboxip:%s\r\n", T2A(address_box_ip));

		pos = lb_str_getTail(pos);
		sprintf(pos, "masternumber:%s\r\n", T2A(master_number));

		pos = lb_str_getTail(pos);
		sprintf(pos, "slavenumber:%s\r\n", T2A(slave_number));

		pos = lb_str_getTail(pos);
		sprintf(pos, "devicenumber:%s\r\n", T2A(device_number));

		//pos = lb_str_getTail(pos);
		//sprintf(pos, "deviceip:%s\r\n", T2A(device_ip));

		lb_netio_msg_sendto3(msg, sizeof(msg), T2A(ScreenIp), PORT_NUM_SETTEMPLATE);

		//更新数据库
		CppSQLite3DB db;
		db.open(LB_SCREEN_DB);
		sprintf(sql, "update LBScreenInfo set master_number = %d,slave_number = %d where master_number = %d and slave_number = %d",
			_ttoi(master_number), _ttoi(slave_number), _ttoi(master_num), _ttoi(slave_num));
		db.execDML(sql);
		printf("the sql is %s\n", sql);
		db.close();

		RefreshDeviceList();

		MessageBox(_T("设置编号信息已发送！"));

	}
	else
	{
		MessageBox(_T("输入的某项信息为空，请检查并重新输入有效的信息 ！"));
	}

	return TRUE;
}

void CDlgUser::OnBnClickedCheckwindoworder()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckwindowOrder = m_windoworder.GetCheck();
	if (bcheckwindowOrder)
	{
		isWindowOrder = 1;
	}
	else
	{
		isWindowOrder = 0;
	}
}

void CDlgUser::OnBnClickedCheckhidepatient()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckhidePatient = m_HidePatient.GetCheck();
	if (bcheckhidePatient)
	{
		isHideBottom = 1;
	}
	else
	{
		isHideBottom = 0;
	}
}

void CDlgUser::OnBnClickedCheckhidwindow()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckhideWindow = m_HideWindow.GetCheck();
	if (bcheckhideWindow)
	{
		isHideCallInfo = 1;
	}
	else
	{
		isHideCallInfo = 0;
	}
}

void CDlgUser::OnBnClickedCheckshowright()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckShowRight = m_ShowRight.GetCheck();
	if (bcheckShowRight)
	{
		ShowCallInfoByRight = 1;
	}
	else
	{
		ShowCallInfoByRight = 0;
	}
}

void CDlgUser::OnBnClickedCheckconsultorder()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckConsultOrder = m_ConsultOrder.GetCheck();
	if (bcheckConsultOrder)
	{
		SortByOffice = 1;
	}
	else
	{
		SortByOffice = 0;
	}
}

void CDlgUser::OnBnClickedCheckMeans()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckMeans = m_checkmeans.GetCheck();
	if (bcheckMeans)
	{
		CheckMeans = 1;
	}
	else
	{
		CheckMeans = 0;
	}
}

void CDlgUser::OnCbnSelchangeComboapp()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;
	CString appstr;

	m_ComboBox_App.GetLBText(m_ComboBox_App.GetCurSel(), appstr);
	if (strcmp(T2A(appstr), "医院") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("门诊/体检 - 诊室显示屏"));
		m_UserComboBox.AddString(_T("门诊/体检 - 候诊主显示屏"));
		m_UserComboBox.AddString(_T("信息发布系统客户端"));
		m_UserComboBox.AddString(_T("手术公告显示屏"));
		m_UserComboBox.AddString(_T("门诊/体检 - 候诊辅显示屏2"));
		m_UserComboBox.AddString(_T("取药/输液 - 等候显示屏"));
		m_UserComboBox.AddString(_T("取药/输液 - 窗口显示屏"));
		m_UserComboBox.AddString(_T("取药/输液 - 等候显示屏2"));
		m_UserComboBox.AddString(_T("取药/输液 - 过号显示屏"));
		m_UserComboBox.AddString(_T("取药 - 液晶主显示屏3"));
		m_UserComboBox.AddString(_T("门诊/体检 - 候诊主显示屏2"));
		m_UserComboBox.AddString(_T("门诊/体检 - 候诊辅显示屏"));
		m_UserComboBox.AddString(_T("门诊 - 诊室显示屏2"));
		m_UserComboBox.AddString(_T("门诊 - 诊室叫号屏"));
		m_UserComboBox.AddString(_T("门诊 - 候诊主显示屏2"));
		//m_UserComboBox.AddString(_T("等候显示屏(条形屏)"));
		m_UserComboBox.AddString(_T("门诊 - 诊室显示屏5"));
		m_UserComboBox.AddString(_T("分诊 - 候诊区辅显示屏2"));
		m_UserComboBox.AddString(_T("分诊 - 候诊区辅显示屏3"));
		m_UserComboBox.AddString(_T("分诊 - 候诊区辅显示屏5"));
		m_UserComboBox.AddString(_T("分诊 - 候诊区辅显示屏6"));
		m_UserComboBox.AddString(_T("分诊 - 液晶诊室显示屏"));
		m_UserComboBox.AddString(_T("分诊 - 液晶诊室显示屏2"));
		m_UserComboBox.AddString(_T("信息看板"));
		m_UserComboBox.AddString(_T("病员--览表"));
		//m_UserComboBox.AddString(_T("扫码签到显示屏"));
		SetDlgItemText(IDC_COMBOUSER,_T("门诊/体检 - 诊室显示屏"));
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP2);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 14;
		InitListTable_ConsultingRoom();
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr),"银行") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("银行排队 - 等候显示屏"));
		m_UserComboBox.AddString(_T("银行排队 - 窗口显示屏"));
		m_UserComboBox.AddString(_T("银行排队 - 窗口显示屏2"));
		m_UserComboBox.AddString(_T("银行排队 - 窗口显示屏3"));
		m_UserComboBox.AddString(_T("银行排队 - 叫号屏"));
		m_UserComboBox.AddString(_T("银行排队 - 主显示屏2"));
		//m_UserComboBox.AddString(_T("银行排队 - 窗口显示屏(条形屏)"));
		SetDlgItemText(IDC_COMBOUSER, _T("银行排队 - 等候显示屏"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP7);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 200;
		InitListTable_BankWaitingRoom();
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "监狱") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("探访排队 - 等候显示屏"));
		SetDlgItemText(IDC_COMBOUSER, _T("探访排队 - 等候显示屏"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP22);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 100;
		InitListTable_Prison();
		HideAllSHOW();
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("是否翻页显示"));
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("温馨提示："));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);

	}
	else if (strcmp(T2A(appstr), "网络对讲") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("走廊显示屏"));
		m_UserComboBox.AddString(_T("岗亭显示屏"));
		m_UserComboBox.AddString(_T("开门提示 - 览表"));
		m_UserComboBox.AddString(_T("实时监控显示屏"));
		m_UserComboBox.AddString(_T("走廊显示屏(条形屏)"));
		m_UserComboBox.AddString(_T("设备信息状态 - 览表"));
		SetDlgItemText(IDC_COMBOUSER, _T("走廊显示屏"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP39);   //...........
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 300;     //........
		InitNetwork_intercom();

		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "养老院") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("养老入住 - 览表"));
		SetDlgItemText(IDC_COMBOUSER, _T("养老入住 - 览表"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP50);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);
		TemplateStyle = 400;
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "信息发布") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("信息发布系统客户端"));
		SetDlgItemText(IDC_COMBOUSER, _T("信息发布系统客户端"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP3);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 29;
		HideAllSHOW();
	}
}

void CDlgUser::OnBnClickedCheckHideBottom()
{
	// TODO:  在此添加控件通知处理程序代码
	BOOL bcheckHideBottom = m_isHideBottom.GetCheck();
	if (bcheckHideBottom)
	{
		isHidePrisonBottom = 1;
	}
	else
	{
		isHidePrisonBottom = 0;
	}
}

void CDlgUser::OnCbnSelchangeComboBackground()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;
	CString backgroundcolor;

	m_backgroundcolor.GetLBText(m_backgroundcolor.GetCurSel(), backgroundcolor);

	if (strcmp(T2A(backgroundcolor), "默认") == 0)
	{
		BackGroundColor = "fdf705";
	}
	else if (strcmp(T2A(backgroundcolor), "红色") == 0)
	{
		BackGroundColor = "ff0000";
	}
	else if (strcmp(T2A(backgroundcolor), "橙色") == 0)
	{
		BackGroundColor = "fa800a";
	}
	else if (strcmp(T2A(backgroundcolor), "黄色") == 0)
	{
		BackGroundColor = "ffff00";
	}
	else if (strcmp(T2A(backgroundcolor), "绿色") == 0)
	{
		BackGroundColor = "00ff00";
	}
	else if (strcmp(T2A(backgroundcolor), "青色") == 0)
	{
		BackGroundColor = "00ffff";
	}
	else if (strcmp(T2A(backgroundcolor), "蓝色") == 0)
	{
		BackGroundColor = "0000ff";
	}
	else if (strcmp(T2A(backgroundcolor), "紫色") == 0)
	{
		BackGroundColor = "8000ff";
	}
	else if (strcmp(T2A(backgroundcolor), "白色") == 0)
	{
		BackGroundColor = "ffffff";
	}//本地数据源
	else if (strcmp(T2A(backgroundcolor), "本地数据源") == 0 )
	{
		BackGroundColor = "本地数据源";
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  端口
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T(""));
	}
	else if (strcmp(T2A(backgroundcolor), "HIS数据源(不含本地留言)") == 0 || strcmp(T2A(backgroundcolor), "HIS数据源(含本地留言)") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "HIS数据源(不含本地留言)") == 0)
		{
			BackGroundColor = "HIS数据源(不含本地留言)";
		}
		else
		{
			BackGroundColor = "HIS数据源(含本地留言)";
		}
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  端口
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("交互服务器IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T("192.167.1.0"));
	}//显示
	else if (strcmp(T2A(backgroundcolor), "标准模式") == 0 || strcmp(T2A(backgroundcolor), "经典模式") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "标准模式") == 0)
		{
			BackGroundColor = "标准模式";
		}
		else
		{
			BackGroundColor = "经典模式";
		}
		//IDC_CHECKHIDEPATIENT    隐藏过号显示
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("显示最低护理级别"));
		//IDC_BAD_SET   病床显示设置
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("病床显示设置"));
		//IDC_BUTTON_RADIO3   根据主机显示病床数
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("根据主机显示病床数"));
		//IDC_BUTTON_RADIO4	自动显示病床数
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("自动显示病床数"));
		//IDC_BUTTON_RADIO5 手动设置病床数
		GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO5)->SetWindowText(_T("手动设置病床数"));
		OnBnClickedButtonRadio3();
		//关闭分页
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_HIDE);
		
	}
	else if (strcmp(T2A(backgroundcolor), "简易图标") == 0 || strcmp(T2A(backgroundcolor), "信息统计模式") == 0 || strcmp(T2A(backgroundcolor), "简约模式") == 0 || strcmp(T2A(backgroundcolor), "大屏翻页") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "大屏翻页") == 0)
		{
			BackGroundColor = "大屏翻页";
			//IDC_CHECKHIDEPATIENT    隐藏过号显示
			GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("显示统计信息"));
			//IDC_CHECK_HIDE_BOTTOM    是否翻页显示
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("显示空床信息"));
			//有切换时间，默认显示统计信息....
		}
		else
		{
			if (strcmp(T2A(backgroundcolor), "简易图标") == 0)
			{
				BackGroundColor = "简易图标";
				//有切换时间
			}
			else if (strcmp(T2A(backgroundcolor), "信息统计模式") == 0)
			{
				BackGroundColor = "信息统计模式";
				//有切换时间
			}
			else if (strcmp(T2A(backgroundcolor), "简约模式") == 0)
			{
				BackGroundColor = "简约模式";
				//无切换时间
			}
			//IDC_CHECKHIDEPATIENT    隐藏过号显示
			GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("显示空床信息"));
			//IDC_CHECK_HIDE_BOTTOM    是否翻页显示
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("分页页卡自适应"));
		}
		//IDC_BAD_SET   病床显示设置
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BADNUM)->ShowWindow(SW_HIDE);
		//还缺少一个切换时间....
	}
}

void CDlgUser::OnCbnSelchangeCombofontcolor()
{
	// TODO:  在此添加控件通知处理程序代码
	USES_CONVERSION;
	CString fontcolor;

	m_fontcolor.GetLBText(m_fontcolor.GetCurSel(), fontcolor);
	if (strcmp(T2A(fontcolor), "默认") == 0)
	{
	    FontColor = "fdf705";
	}
	else if (strcmp(T2A(fontcolor), "红色") == 0)
	{
		FontColor = "ff0000";
	}
	else if (strcmp(T2A(fontcolor), "橙色") == 0)
	{
		FontColor = "fa800a";
	}
	else if (strcmp(T2A(fontcolor), "黄色") == 0)
	{
		FontColor = "ffff00";
	}
	else if (strcmp(T2A(fontcolor), "绿色") == 0)
	{
		FontColor = "00ff00";
	}
	else if (strcmp(T2A(fontcolor), "青色") == 0)
	{
		FontColor = "00ffff";
	}
	else if (strcmp(T2A(fontcolor), "蓝色") == 0)
	{
		FontColor = "0000ff";
	}
	else if (strcmp(T2A(fontcolor), "紫色") == 0)
	{
		FontColor = "8000ff";
	}
	else if (strcmp(T2A(fontcolor), "白色") == 0)
	{
		FontColor = "ffffff";
	}
}

void  CDlgUser::InitCheckTYPEStatus()
{
	//IDC_BADNUM   IDC_STATIC_BADNUM
	if (m_button_radio == 2)
	{
		GetDlgItem(IDC_BADNUM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_BADNUM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_HIDE);
	}
}

void CDlgUser::OnBnClickedButtonRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_button_radio = 0;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnBnClickedButtonRadio4()
{
	// TODO:  在此添加控件通知处理程序代码
	m_button_radio = 1;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnBnClickedButtonRadio5()
{
	// TODO:  在此添加控件通知处理程序代码
	m_button_radio = 2;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnCbnSelchangeTypemode()
{
	// TODO:  在此添加控件通知处理程序代码
		USES_CONVERSION;
		CString m_mode;

		m_Typemode.GetLBText(m_Typemode.GetCurSel(), m_mode);
		if (strcmp(T2A(m_mode), "默认") == 0)
		{
			Typemode = "标准模式";
		}
		else if (strcmp(T2A(m_mode), "标准模式") == 0)
		{
			Typemode = "标准模式";
		}
		else if (strcmp(T2A(m_mode), "经典模式") == 0)
		{
			Typemode = "经典模式";
		}
}

void CDlgUser::OnBnClickedButtonView()
{
	// TODO:  在此添加控件通知处理程序代码
	// 设置过滤器   
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*|*.jpg(*.jpg)|*.jpg|*.jpeg(*.jpeg)|*.jpeg|*.gif(*.gif)|*.gif|*.jpeg(*.jpeg)|*.jpeg|*.png(*.png)|*.png|*.htm(*.htm)|*.htm|*.html(*.html)|*.html||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("所有文件"), NULL, 0, szFilter, this);
	// 显示打开文件对话框  
	strFilePath = "";
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_FILEPATH, strFilePath);
	}
	if (strFilePath.GetLength()!=0)
	{
		m_buttonupload.EnableWindow(1);
	}
}

void CDlgUser::OnBnClickedButtonUpload()
{
	// TODO:  在此添加控件通知处理程序代码
	pInternetSession = NULL;
	pFtpConnection = NULL;
	//建立连接   
	pInternetSession = new CInternetSession(AfxGetAppName());
	//   
	CString strADddress, strUserName, strPwd, strDir, strLocalFile, strRemoteFile;
	//服务器的ip地址,用户名与密码,服务器的根目录,目标文件，目的文件
	strADddress = "192.168.1.101";
	strUserName = "lonbon";
	strPwd = "lonbon";
	strDir = "\\img\\title";  //路径名称可能有问题
	pFtpConnection = pInternetSession->GetFtpConnection(strADddress, strUserName, strPwd);
	bool bRetVal = pFtpConnection->SetCurrentDirectory(strDir); 
	if (bRetVal == false)   
	{ 
		//AfxMessageBox("目录设置失败");       
		return;
	}
	else
	{
		//把本地文件上传到服务器上    
		//strLocalFile = strFilePath;
		strRemoteFile = "icon.png";      
		pFtpConnection->PutFile((LPCTSTR)strFilePath, (LPCTSTR)strRemoteFile);
	}
	//释放资源
	if(NULL != pFtpConnection)
	{        
		pFtpConnection->Close();
		delete pFtpConnection;
		pFtpConnection = NULL;
	}    
	if(NULL != pInternetSession)
	{        
		delete pInternetSession;
		pInternetSession = NULL;
	}
}
