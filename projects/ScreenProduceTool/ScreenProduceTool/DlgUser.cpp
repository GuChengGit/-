// DlgUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScreenProduceTool.h"
#include "DlgUser.h"
#include "afxdialogex.h"
#define  IDC_EDIT 0xffff

int m_Item, m_SubItem;
// CDlgUser �Ի���

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


// CDlgUser ��Ϣ�������

void CDlgUser::InitUserReportCtrl()
{
	UINT nColWidth = 50;
	m_UserReportCtrl.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);
	m_UserReportCtrl.InsertColumn(0, _T("ѡ��"), LVCFMT_CENTER, nColWidth);
	//m_UserReportCtrl.InsertColumn(1, _T("���"), LVCFMT_CENTER, nColWidth);
	m_UserReportCtrl.InsertColumn(1, _T("������"), LVCFMT_CENTER, nColWidth * 1.7);
	m_UserReportCtrl.InsertColumn(2, _T("�������"), LVCFMT_CENTER, nColWidth*1.7);
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
	m_backgroundcolor.AddString(_T("Ĭ��"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	m_backgroundcolor.AddString(_T("��ɫ"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("Ĭ��"));
}

void CDlgUser::patientsimpleshow()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("����ͼ��"));
	m_backgroundcolor.AddString(_T("����ģʽ"));
	m_backgroundcolor.AddString(_T("��׼ģʽ"));
	m_backgroundcolor.AddString(_T("������ҳ"));
	m_backgroundcolor.AddString(_T("��Ϣͳ��ģʽ"));
	m_backgroundcolor.AddString(_T("��Լģʽ"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("����ͼ��"));
}

void CDlgUser::InformationStatueMode()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("��λȡ��ģʽ"));
	m_backgroundcolor.AddString(_T("����ģʽ"));
	m_backgroundcolor.AddString(_T("��¼ģʽ"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("��λȡ��ģʽ"));
}

void CDlgUser::InformationBorderMassage()
{
	m_backgroundcolor.ResetContent();
	m_backgroundcolor.AddString(_T("��������Դ"));
	m_backgroundcolor.AddString(_T("HIS����Դ(������������)"));
	m_backgroundcolor.AddString(_T("HIS����Դ(����������)"));
	SetDlgItemText(IDC_COMBO_BACKGROUND, _T("��������Դ"));
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
	//���
	GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowText(_T(""));
	GetDlgItem(IDC_LETTER)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T(""));
	GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("���ع��Ų�����ʾ"));
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
			m_listtable.InsertColumn(0, _T("�Ƿ����"), LVCFMT_CENTER, nColWidth*2.5);
			m_listtable.InsertColumn(1, _T("���%"), LVCFMT_CENTER, nColWidth * 3);
			m_listtable.InsertColumn(2, _T("�б���"), LVCFMT_CENTER, nColWidth * 2.7);
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
			m_listtable.InsertColumn(0, _T("����"), LVCFMT_CENTER, nColWidth*1.5);
			m_listtable.InsertColumn(1, _T("��ͷ"), LVCFMT_CENTER, nColWidth * 3);
			m_listtable.InsertColumn(2, _T("���%"), LVCFMT_CENTER, nColWidth * 2.2);
			m_listtable.InsertColumn(3, _T("˳��"), LVCFMT_CENTER, nColWidth * 1.5);
		}
	}
	//mode Ϊ�޸�CListCtrl�ı�ͷ��־λ
	mode = 0;
	//���ø�ѡ��Ĭ�ϲ���ѡ��
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
	m_fontcolor.AddString(_T("Ĭ��"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	m_fontcolor.AddString(_T("��ɫ"));
	SetDlgItemText(IDC_COMBOFONTCOLOR, _T("Ĭ��"));
}

void  CDlgUser::typemode()
{
	m_Typemode.ResetContent();
	m_Typemode.AddString(_T("��׼ģʽ"));
	m_Typemode.AddString(_T("����ģʽ"));
	SetDlgItemText(IDC_TYPEMODE, _T("����ģʽ"));
}

BOOL CDlgUser::InitUserComBox()
{
	m_ComboBox_App.AddString(_T("ҽԺ"));
	m_ComboBox_App.AddString(_T("����"));
	m_ComboBox_App.AddString(_T("����"));
	m_ComboBox_App.AddString(_T("����Խ�"));
	m_ComboBox_App.AddString(_T("����Ժ"));  
	m_ComboBox_App.AddString(_T("��Ϣ����"));

	SetDlgItemText(IDC_COMBO1, _T("Ĭ��"));
	
	BackGroundColor = "fdf705";
	FontColor = "fdf705";
	Typemode = "��׼ģʽ";

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;

	m_UserComboBox.GetLBText(m_UserComboBox.GetCurSel(), templetstr);
	if (strcmp(T2A(templetstr), "����/��� - ������ʾ��") == 0)
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
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("�������ƣ�"));
	}
	else if (strcmp(T2A(templetstr), "����/��� - ��������ʾ��") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - �Ⱥ���ʾ��") == 0)
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
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("�Ƿ�ҳ��ʾ"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP��"));
	}
	else if (strcmp(T2A(templetstr),"�����Ŷ� - ������ʾ��") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("ʱ��ͬ��������IP��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("�ϴ���ͣ��Ϣ����"));
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("���ںţ�"));
		GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDWINDOW)->SetWindowText(_T("���ؽк���ʾ��"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  ������ɫ
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("������ɫ"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
		//IDC_STATIC_FONTCOLOR: IDC_COMBOFONTCOLOR   ������ɫ
		GetDlgItem(IDC_STATIC_FONTCOLOR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FONTCOLOR)->SetWindowText(_T("������ɫ"));
		GetDlgItem(IDC_COMBOFONTCOLOR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("�ϴ�ͼƬ��"));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "��Ϣ����ϵͳ�ͻ���") == 0)
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
	else if (strcmp(T2A(templetstr), "����������ʾ��") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ   ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("�б���⣺"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "����/��� - ���︨��ʾ��2") == 0)
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
	else if (strcmp(T2A(templetstr), "ȡҩ/��Һ - �Ⱥ���ʾ��") == 0)
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
	else if (strcmp(T2A(templetstr), "ȡҩ/��Һ - ������ʾ��") == 0)
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
	else if (strcmp(T2A(templetstr), "ȡҩ/��Һ - �Ⱥ���ʾ��2") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDWINDOW)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "ȡҩ/��Һ - ������ʾ��") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_HIDE);
	}
	else if (strcmp(T2A(templetstr), "ȡҩ - Һ������ʾ��3") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - ������ʾ��5") == 0)  //changed
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("�������ƣ�"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("logoͼƬ��"));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "����/��� - ��������ʾ��2") == 0)  //changed
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
	else if (strcmp(T2A(templetstr), "���� - ������ʾ��2") == 0)  //changed
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("�������ƣ�"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("logoͼƬ��"));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "����/��� - ���︨��ʾ��") == 0)
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

	else if (strcmp(T2A(templetstr), "���� - ���ҽк���") == 0)
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
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME:IDC_EDITCONSULTNAME
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("�б���⣺"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("�б����"));
	}
	else if (strcmp(T2A(templetstr), "���� - ��������ʾ��2") == 0)
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
	else if (strcmp(T2A(templetstr), "�Ⱥ���ʾ��(������)") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - ����������ʾ��2") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - ����������ʾ��3") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - ����������ʾ��5") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - ����������ʾ��6") == 0)
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
		GetDlgItem(IDC_STATIC_BACKGROUND2)->SetWindowText(_T("��ʾ��"));
		GetDlgItem(IDC_TYPEMODE)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "���� - Һ��������ʾ��") == 0)
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
	else if (strcmp(T2A(templetstr), "���� - Һ��������ʾ��2") == 0)
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
	else if (strcmp(T2A(templetstr), "��Ϣ����") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		//����Ϊ1
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
		//IDC_CHECKWINDOWORDER  ���������� 
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("��ʾ��ͻ�����"));
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    ��������  (����û�д���ȥ������)
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("����:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("0"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND������ɫ
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("����Դ:"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
		//IDC_BAD_SET   ������ʾ����
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("������ʾ����"));
		//IDC_BUTTON_RADIO3   ����������ʾ������
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("����������ʾ������"));
		//IDC_BUTTON_RADIO4	�Զ���ʾ������
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("�Զ���ʾ������"));
		//IDC_BUTTON_RADIO5 �ֶ����ò�����
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("�ֶ����ò�����"));
	}
	else if (strcmp(T2A(templetstr), "��Ա--����") == 0)
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
		
		//IDC_CHECKWINDOWORDER  ����������
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("���ý�����Ժ"));
		//IDC_CHECKHIDEPATIENT    ���ع�����ʾ
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("��ʾ�մ���Ϣ"));
		//IDC_CHECK_HIDE_BOTTOM    �Ƿ�ҳ��ʾ
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("��ҳҳ������Ӧ"));
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("������͸����:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_LETTER)->SetWindowText(_T("255"));
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  �˿�
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("������ͣ��ʱ��(��):"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    ��������
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("��ܰ��ʾ:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDITCONSULTNAME)->SetWindowText(_T("�뱣�ְ���~��������"));
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  ������ɫ
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("��ʾ��"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "ɨ��ǩ����ʾ��") == 0)
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
	else if (strcmp(T2A(templetstr), "������ʾ��") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP39);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 300;   //-------------
		HideAllSHOW();
		InitNetwork_intercom();  //----------  IDC_CHECKWINDOWORDER����������
		
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("�Ƿ��޺��м�¼��ʾ"));
	}
	else if (strcmp(T2A(templetstr), "��ͤ��ʾ��") == 0)
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
	else if (strcmp(T2A(templetstr), "������ʾ - ����") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP41);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 302;   //-------------
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_STATIC_LETEER  : IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "ʵʱ�����ʾ��") == 0)
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
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʵʱ��Ƶ��ش���ͼƬ�ϴ�"));
		GetDlgItem(IDC_STATIC_LOGO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LOGO)->SetWindowText(_T("�ϴ�ͼƬ��"));
		GetDlgItem(IDC_EDIT_FILEPATH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_VIEW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_UPLOAD)->ShowWindow(SW_SHOW);
		m_buttonupload.EnableWindow(0);
	}
	else if (strcmp(T2A(templetstr), "������ʾ��(������)") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP43);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 304;   //-------------
		HideAllSHOW();
		InitNetwork_intercom();  //----------
		
		//IDC_STATIC_LETEER  : IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�豸��Ϣ״̬ - ����") == 0)
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
		
		//IDC_STATIC_LETEER  : IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_BACKGROUND  :IDC_COMBO_BACKGROUND  ������ɫ
		GetDlgItem(IDC_STATIC_BACKGROUND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BACKGROUND)->SetWindowText(_T("ģʽ��"));
		GetDlgItem(IDC_COMBO_BACKGROUND)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - ������ʾ��2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP45);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 202;   //-------------
		mode = 1; //���ı�ͷ
		HideAllSHOW();
		InitListTable_MedicineScreen1();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("������Ϣ:"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  �˿�
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    ��������
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("��ͣ������Ϣ��"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - ������ʾ��3") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP46);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 206;   //-------------
		HideAllSHOW();
		InitBanksort_Window3();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - �к���") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP47);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 205;   //-------------
		HideAllSHOW();
		InitBanksort();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - ����ʾ��2") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP48);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 203;   //-------------
		HideAllSHOW();
		InitListTable_Bankshow2();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "�����Ŷ� - ������ʾ��(������)") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP49);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 204;   //-------------
		HideAllSHOW();
		InitBankWindow();  //----------
		
		//IDC_STATIC_LETEER: IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("ʱ��ͬ��������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    ��������
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("���ں�:"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
	}
	else if (strcmp(T2A(templetstr), "������ס - ����") == 0)
	{
		CBitmap bitmap;
		HBITMAP hBmp;
		bitmap.LoadBitmap(IDB_BITMAP50);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 400;   //-------------
		HideAllSHOW();
		m_listtable.DeleteAllItems();  //----------
		
		//IDC_CHECKWINDOWORDER���������� 
		GetDlgItem(IDC_CHECKWINDOWORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKWINDOWORDER)->SetWindowText(_T("���ý�����Ժ"));
		//IDC_CHECKHIDEPATIENT���ع�����ʾ
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("��ʾ���ʣ�������ָ��"));
		//IDC_DEP_NAME : IDC_EDITCONSULTNAME    ��������
		GetDlgItem(IDC_DEP_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DEP_NAME)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_EDITCONSULTNAME)->ShowWindow(SW_SHOW);
		//IDC_STATIC_LETTER  : IDC_LETTER    ����
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("���У�����������ͣ��ʱ��(��)��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  �˿�
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("��λҳ�淭���л�ʱ��(��)��"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T("10"));
		//IDC_BAD_SET   ������ʾ����
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("��λ��ʾ����"));
		//IDC_BUTTON_RADIO3   ����������ʾ������
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("����������ʾ��λ��"));
		//IDC_BADNUM	�Զ���ʾ������
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("��ʾ��ס��λ���մ�λ����ʾ"));
	}
	else if (strcmp(T2A(templetstr), "̽���Ŷ� - �Ⱥ���ʾ��") == 0)
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
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("�Ƿ�ҳ��ʾ"));
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
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
	//CString Item[6] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�ȴ���Ա"),_T("�ȴ�Ʊ��"),_T("�ȴ�����") };
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
	CString Item[6] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�ȴ���Ա"),_T("�ȴ�Ʊ��"),_T("�ȴ�����") };
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

	CString Item[4] = { _T("Ʊ��"), _T("����"), _T("�ȴ���Ա"), _T("�ȴ�Ʊ��") };
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

	CString Item[2] = { _T("Ʊ��"), _T("����") };
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

	CString Item[4] = { _T("Ʊ��"), _T("����"), _T("����"), _T("״̬") };
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
	CString Item[5] = {_T("���ұ��"),_T("Ʊ��"),_T("����"),_T("�ȴ�Ʊ��"),_T("�ȴ���Ա")};
	CString num[5] = {_T("0"),_T("1"),_T("2"),_T("3"),_T("4")};
	m_listtable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);


	//m_listtable.InsertColumn(0, _T("����"), LVCFMT_CENTER, nColWidth);
	//m_listtable.InsertColumn(1, _T("��ͷ"), LVCFMT_CENTER, nColWidth*4);
	//m_listtable.InsertColumn(2, _T("���%"), LVCFMT_CENTER, nColWidth * 3);
	//m_listtable.InsertColumn(3, _T("˳��"), LVCFMT_CENTER, nColWidth * 2);

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
	m_listtable.InsertColumn(0, _T("����"), LVCFMT_CENTER, nColWidth*1.5);
	m_listtable.InsertColumn(1, _T("��ͷ"), LVCFMT_CENTER, nColWidth * 3);
	m_listtable.InsertColumn(2, _T("���%"), LVCFMT_CENTER, nColWidth * 2.2);
	m_listtable.InsertColumn(3, _T("˳��"), LVCFMT_CENTER, nColWidth * 1.5);

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

	CString Item[5] = { _T("���ұ��"), _T("Ʊ��"), _T("����"), _T("�ȴ�Ʊ��"), _T("�ȴ���Ա") };
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

BOOL CDlgUser::InitListTable_WaitingRoom()    //0     ����
{
	m_listtable.DeleteAllItems();
	
	CString Item[8] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�������"),_T("���ұ��"),_T("��������"),_T("ҽ��"),_T("��ע") };
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
	CString Item[7] = {  _T("����"), _T("��������"), _T("���ұ��"), _T("��ע"), _T("�ȴ���Ա"), _T("�ȴ�����"), _T("��Ϣ") };
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

	CString Item[10] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�������"),_T("���ұ��"),_T("��������"),_T("ҽ��"),_T("�ȴ�����"),_T("�ȴ���Ա"),_T("�ȴ�Ʊ��") };
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

	CString Item[7] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�������"),_T("ҽ��"),_T("���ұ��"),_T("��������") };
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

	CString Item[9] = { _T("Ʊ��"), _T("����"), _T("����"),_T("ҽ��"),_T("���ұ��"),_T("��������"),_T("�ȴ���Ա"),_T("�ȴ�Ʊ��"),_T("��ע") };
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

	CString Item[10] = { _T("Ʊ��"), _T("����"), _T("����"),_T("ҽ��"),_T("���ұ��"),_T("��������"),_T("�ȴ���Ա"),_T("�ȴ�Ʊ��"), _T("��ע"), _T("��ʼ����ʾ��") };
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

	CString Item[9] = { _T("���ұ��"), _T("��������"), _T("ҽ��"), _T("����"),_T("�������"),_T("Ʊ��"),_T("����"),_T("�ȴ�Ʊ��"),_T("�ȴ���Ա") };
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

	CString Item[9] = { _T("Ʊ��"), _T("����"), _T("����"), _T("�������"),_T("���ұ��"),_T("��������"),_T("ҽ��"),_T("��ע"),_T("״̬") };
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

	CString Item[5] = { _T("����"), _T("����"), _T("ҽ��"),_T("�ȴ���Ա"),_T("��������") };
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
	
	CString Item[3] = { _T("���ұ��"),_T("Ʊ��"),_T("����")};
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

	CString Item[6] = { _T("ҽ��"),_T("ְ��"),_T("Ʊ��"),_T("����"),_T("�ȴ�Ʊ��"),_T("�ȴ���Ա") };
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

	CString Item[9] = { _T("Ʊ��"), _T("����"), _T("����ҽ��"), _T("���ұ��"), _T("��������"), _T("�ȴ���Ա"), _T("�ȴ�Ʊ��"), _T("��ע"), _T("�ȴ���ע")};
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
	CString Item[5] = { _T("Ʊ��"), _T("����"), _T("�������"), _T("״̬"), _T("�ȴ�����") };
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

BOOL CDlgUser::InitListTable_Bankshow2()  //203   ��
{
	m_listtable.DeleteAllItems();
	CString Item[3] = { _T("Ʊ��"),_T("����"),_T("״̬")};
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
	CString Item[5] = { _T("Ʊ��"), _T("����"), _T("����"), _T("����"), _T("����") };
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

BOOL CDlgUser::InitListTable_HospitalRoom()   //��
{

	m_listtable.DeleteAllItems();
	CString Item[9] = { _T("ʱ��"), _T("������"), _T("����"), _T("����"), _T("��������"), _T("ҽ��"), _T("�ȼ�"), _T("����ҽ��"), _T("״̬") };
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
	CString Item[2] = { _T("����"), _T("Ʊ��") };
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
	CString Item[2] = { _T("��Ϣ"), _T("״̬") };
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
	CString Item[4] = { _T("����"), _T("Ʊ��"), _T("���ұ��"), _T("��Ϣ") };
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

BOOL CDlgUser::InitBanksort()    //205    ������Աû��  1<<0,1<<1,1<<  ,1<<8,1<<13,1<<10
{
	m_listtable.DeleteAllItems();	//LBFIELD_NUMBER +LBFIELD_NAME +  +LBFIELD_WINDOW +LBFIELD_MESSAGE +LBFIELD_DESCRIPTION 
	CString Item[6] = { _T("Ʊ��"), _T("����"), _T("������Ա"), _T("����") ,_T("��Ϣ"), _T("��ע") };
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

LRESULT CDlgUser::OnCountDeviceNumMsg(WPARAM wParam, LPARAM lParam)  //��Ӧ��Ϣˢ�½���
{
	RefreshDeviceList();

	return TRUE;
}

void CDlgUser::OnBnClickedButtonrefreshlist()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//RefreshDeviceList();
	lb_broadcast_screen();
}


void CDlgUser::OnBnClickedUsersettemplate()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	int checknum = 0;
	CString Ip;
	for (int i = 0; i < m_UserReportCtrl.GetItemCount(); i++)
	{
		BOOL bchecked = m_UserReportCtrl.GetCheck(i);  //m_UserReportCtrl��ѡ����check���͵�
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
			MessageBox(_T("����ָ��λ������Ҫ����ģ���IP��"));
		}
		
	}
	else if (checknum < 1 && CheckMeans == 0)
	{
		MessageBox(_T("����ѡ��Ҫ����ģ����豸����ʹ�÷�ʽ������ָ���豸��IP��"));
	}
	
	//else if (TemplateStyle >= 0 && Check != 0)
	//{
		//MessageBox(_T("����ģ��ɹ���"));
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
	m_title.GetWindowText(title);     //������
	m_subtitle.GetWindowText(Subtitle);    //������
	m_x.GetWindowText(X);     //���Ͻ�X��
	m_Y.GetWindowText(Y);     ////���Ͻ�Y��
	m_height.GetWindowText(height);    //��ʾ���߶�
	m_width.GetWindowText(width);      //��ʾ�����
	m_row.GetWindowText(row);      //����
	m_voice.GetWindowText(voice);  //����
	m_percent.GetWindowText(percent);     //������
	
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
	if (TemplateStyle == 35 || TemplateStyle == 36 || TemplateStyle == 100 || TemplateStyle == 200)     //200�Ļ���һ���Ƿ�ҳ��ʾ
	{
		m_letter.GetWindowText(consultname);            //���Կ����
		m_consultname.GetWindowText(lb_list_title);    //�������ƺ����
	}
	else
	{
		m_consultname.GetWindowText(consultname);     //�������ƺ����
		m_letter.GetWindowText(server_directory);    //���Կ����
	}

	if (TemplateStyle == 7 || TemplateStyle == 13 || TemplateStyle == 29 || TemplateStyle == 30 || TemplateStyle == 31 || TemplateStyle == 200 || TemplateStyle == 202 || TemplateStyle == 203 || TemplateStyle == 205 || TemplateStyle == 206 || TemplateStyle == 204)
	{
		m_letter.GetWindowText(server_directory);     //���Կ����
		m_info_server_port.GetWindowText(Infoserver_port);     //�˿ں����
	}
	if (TemplateStyle == 7)
	{
		m_consultname.GetWindowText(area_number);   //�������ƺ����
	}
	if (TemplateStyle == 201)    
	{
		m_letter.GetWindowText(Infoserver_port);       //�˿ں����
		//m_consultname.GetWindowText(server_directory);    //���Կ���� 
	}
	if (TemplateStyle == -1)
	{
		MessageBox(_T("����ѡ��ģ�壡"));
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
			sprintf(pos, "lb_clinic_name:%s\r\n", T2A(consultname));   //�������ƺ����


			if (TemplateStyle == 14 || TemplateStyle == 35 || TemplateStyle == 36 || TemplateStyle == 205 || TemplateStyle == 29 || TemplateStyle == 100 || TemplateStyle == 200 || TemplateStyle == 201 || TemplateStyle == 13 || TemplateStyle == 400)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "tv_message:%s\r\n", T2A(consultname));    //�������ƺ����
			}
			else
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "tv_message:%s\r\n", T2A(server_directory));    //���Ժ����
			}

			if (TemplateStyle == 201)   
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "number_of_screen:%s\r\n", T2A(consultname));    //���Ժ����

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_ntpserverIp:%s\r\n", T2A(Infoserver_port));    //���Ժ����

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_background_style:%s\r\n", T2A(BackGroundColor));   //������ɫ

				pos = lb_str_getTail(pos);
				sprintf(pos, "lb_font_style:%s\r\n", T2A(FontColor));    //������ɫ
			}
			if (TemplateStyle == 13)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "boxstay_opacity:%s\r\n", T2A(server_directory));    
				pos = lb_str_getTail(pos);
				sprintf(pos, "StayTime:%s\r\n", T2A(Infoserver_port));    
			}
			pos = lb_str_getTail(pos);
			sprintf(pos, "isHidenTitle:%d\r\n", isHidenTitle);    //���ر�����
			pos = lb_str_getTail(pos);
			sprintf(pos, "title:%s\r\n", T2A(title));     //������
			pos = lb_str_getTail(pos);
			sprintf(pos, "sub_title:%s\r\n",T2A(Subtitle));    //������

			pos = lb_str_getTail(pos);
			sprintf(pos, "x0:%d\r\n", _ttoi(X));    //x
			pos = lb_str_getTail(pos);
			sprintf(pos, "y0:%d\r\n", _ttoi(Y));    //y
			pos = lb_str_getTail(pos);
			sprintf(pos, "width:%d\r\n", _ttoi(width));    //width
			pos = lb_str_getTail(pos);
			sprintf(pos, "height:%d\r\n", _ttoi(height));    //height

			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdEnabled:%d\r\n", isAdEnabled);   //��濪��
			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdVideoEnabled:%d\r\n", isAdVideoEnabled);  //��Ƶ��濪��
			pos = lb_str_getTail(pos);
			sprintf(pos, "isAdTextEnabled:%d\r\n", isAdTextEnabled);    //���ֹ�濪��
			pos = lb_str_getTail(pos);
			sprintf(pos, "adAreaPercent:%d\r\n", _ttoi(percent));     //������

			pos = lb_str_getTail(pos);
			sprintf(pos, "SystemVoice:%d\r\n", _ttoi(voice));    //����
			pos = lb_str_getTail(pos);
			sprintf(pos, "number_of_rows:%d\r\n", _ttoi(row));   //��

			pos = lb_str_getTail(pos);
			sprintf(pos, "tableheads_str:%s\r\n", head_string);    //ƴ��������(���ƣ����ң�ҽ���ȵ�)
			pos = lb_str_getTail(pos);
			sprintf(pos, "SortByOffice:%d\r\n", isWindowOrder);   //����������
			pos = lb_str_getTail(pos);
			sprintf(pos, "defined_value:%d\r\n", definedValue);    //��λ��ƴ��(1<<1��)
			pos = lb_str_getTail(pos);
			sprintf(pos, "server_directory:%s\r\n", T2A(server_directory));   //���Ժ����   ������Ŀ¼
			pos = lb_str_getTail(pos);
			sprintf(pos, "lb_list_title:%s\r\n", T2A(lb_list_title));    //���Һ����   �б����
			pos = lb_str_getTail(pos);
			sprintf(pos, "lb_infoserver_port:%d\r\n", _ttoi(Infoserver_port));    //�˿ں����   �������˿�
			pos = lb_str_getTail(pos);
			sprintf(pos, "area_number:%d\r\n", _ttoi(area_number));    //���Һ���   ����
		//-------------  
			if (TemplateStyle == 22 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //���ع��Ų���
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideCallInfo:%d\r\n", isHideCallInfo);   //���ش�����ʾ��
				pos = lb_str_getTail(pos);
				sprintf(pos, "ShowCallInfoByRight:%d\r\n", ShowCallInfoByRight);   //�����ҿ����ʾ
			}
			else if (TemplateStyle == 30 || TemplateStyle == 201)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHideCallInfo:%d\r\n", isHideCallInfo);   //���ش�����ʾ��
			}
			else if (TemplateStyle == 100 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isHidePrisonBottom:%d\r\n", isHidePrisonBottom);   //�Ƿ�ҳ��ʾ  û�й涨Э���ַ�
			}
			else if (TemplateStyle == 13)  //û��isHidePrisonBottom��������Ա--����
			{
				if ( BackGroundColor == "����ģʽ" || BackGroundColor == "����ģʽ")
				{
					pos = lb_str_getTail(pos);
					sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //����������
					pos = lb_str_getTail(pos);
					sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //���ع��Ų���
					pos = lb_str_getTail(pos);
					sprintf(pos, "ShowModel:%s\r\n", T2A(BackGroundColor));   //������ɫ(�൱����ʾ)
				}
				else
				{
					pos = lb_str_getTail(pos);
					sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //����������

				}
			}
			else if (TemplateStyle == 21)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "ShowModel:%s\r\n", T2A(Typemode));   //������ɫ(�൱����ʾ)
			}
			else if (TemplateStyle == 7)   //ȱ�ٲ�����ʾ����
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isShowLowestLevel:%d\r\n", isWindowOrder);   //����������
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "lb_background_style:%s\r\n", T2A(BackGroundColor));   //������ɫ(�൱����ʾ)
			}
			else if (TemplateStyle == 300)
			{
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "isWindowOrder:%d\r\n", isWindowOrder);   //�Ƿ��޺��м�¼��ʾ
			}
			else if (TemplateStyle == 200 )
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isWindowOrder:%d\r\n", isWindowOrder);   //����������
			}
			else if (TemplateStyle == 305)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "model:%s\r\n", T2A(BackGroundColor));   //������ɫ(�൱����ʾ)
			}
			else if (TemplateStyle == 400)
			{
				pos = lb_str_getTail(pos);
				sprintf(pos, "isTodayInPatient:%d\r\n", isWindowOrder);   //����������
				//pos = lb_str_getTail(pos);
				//sprintf(pos, "isHideBottom:%d\r\n", isHideBottom);   //���ع��Ų���    ��ʾ����ָ��
			}
			
			lb_netio_msg_sendto3(msg, sizeof(msg), T2A(ScreenIp), PORT_NUM_SETTEMPLATE);
			printf("the message is:\n %s\n",msg);
			printf("the screen ip is %s\n", T2A(ScreenIp));

			//�����ݿ�
			CppSQLite3DB db;
			db.open(LB_SCREEN_DB);
			sprintf(sql, "update LBScreentemplate set style = %d,tv_message = '%s',isHidenTitle = %d, title = '%s',sub_title = '%s',x0 = %d, y0 = %d,width = %d,height = %d,isAdEnabled = %d,isAdVideoEnabled = %d,isAdTextEnabled = %d,adAreaPercent = %d,SystemVoice = %d,number_of_columns = %d,tableheads_str = '%s',defined_value = %d where id in(select Screentemplate_id from LBScreenInfo where master_number = %d and slave_number = %d)",
				TemplateStyle, T2A(consultname), isHidenTitle, T2A(title), T2A(Subtitle), _ttoi(X), _ttoi(Y), _ttoi(width), _ttoi(height), isAdEnabled, isAdVideoEnabled, isAdTextEnabled, _ttoi(percent), _ttoi(voice), _ttoi(row), head_string, definedValue, _ttoi(master_num), _ttoi(slave_num));
			db.execDML(sql);
			printf("the sql is %s\n",sql);
			db.close();
			FreeConsole();
			MessageBox(_T("����ģ���ѷ���"));
			
		}
		
	}
	return TRUE;
}

BOOL CDlgUser::checkadv()
{
	BOOL bcheckhidetitle = m_hidetitle.GetCheck();    //���ر�����
	BOOL bcheckmedadv = m_mediaAdv.GetCheck();    //��ý������
	BOOL bcheckvideoadv = m_videoAdv.GetCheck();    //��Ƶ���
	BOOL bcheckcharacteradv = m_characterAdv.GetCheck();   //���ֹ��
	if (bcheckhidetitle)
	{
		isHidenTitle = 1;       //���ر�����
	}
	if (bcheckmedadv)
	{
		if (!bcheckcharacteradv && !bcheckvideoadv)
		{
			Check = 0;
			MessageBox(_T("��ѡ����ʾ�Ĺ�����ͣ���Ƶ�������ı���棩��"));
		}
		else
		{
			isAdEnabled = 1;   //��ý���濪�ؿ���
			Check = 1;
		}
	}
	if (bcheckvideoadv)
	{
		if (!bcheckmedadv)
		{
			Check = 0;
			MessageBox(_T("����ѡ����ʾ��ý��������"));
		}
		else
		{
			isAdVideoEnabled = 1;     //��Ƶ��濪��
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
			MessageBox(_T("����ѡ����ʾ��ý��������"));
		}
		else
		{
			isAdTextEnabled = 1;   //���ֹ�濪��
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL bcheckvideoadv = m_videoAdv.GetCheck();
	if (bcheckvideoadv)
	{
		isAdVideoEnabled = 1;
		BOOL bcheckmedadv = m_mediaAdv.GetCheck();
		if (!bcheckmedadv)
		{
			isAdVideoEnabled = 0;
			//m_mediaAdv.SetCheck(false);
			MessageBox(_T("����ѡ����ʾ��ý��������"));
		}
	}
	else
	{
		isAdVideoEnabled = 0;
	}
}


void CDlgUser::OnBnClickedCheckcharacteradv()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	BOOL bcheckcharacteradv = m_characterAdv.GetCheck();
	if (bcheckcharacteradv)
	{
		isAdTextEnabled = 1;
		BOOL bcheckmedadv = m_mediaAdv.GetCheck();
		if (!bcheckmedadv)
		{
			isAdTextEnabled = 0;
			//m_mediaAdv.SetCheck(false);
			MessageBox(_T("����ѡ����ʾ��ý��������"));
		}
	}
	else
	{
		isAdTextEnabled = 0;
	}
}


void CDlgUser::OnBnClickedCheckhidetitle()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

void CDlgUser::OnNMDblclkListtable(NMHDR *pNMHDR, LRESULT *pResult)  //���ı༭�����������
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	BOOL needSave = false;
	int rowCount = m_listtable.GetItemCount();

	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	CRect  EditRect;    //һ���������

	if (needSave)
	{
		CString  EditStr;
		m_EditVirtual.GetWindowText(EditStr); //��ȡ���������  
		m_listtable.SetItemText(m_Item, m_SubItem, EditStr); //m_Item,m_SubItem������������ֵ��ԭ���ĵ�Ԫ���ֵ  
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
				//����һ����
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
			m_EditVirtual.SetFocus();		//����Ϊ����  
			m_EditVirtual.SetSel(0, -1);	//0,-1��ʾ��Ԫ������ȫѡ��  

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
			MessageBox(_T("����ָ��λ������Ҫ���ñ����Ϣ���豸��IP��"));
		}

	}
	if ((checknum < 1) && (CheckMeans == 0))
	{
		MessageBox(_T("����ѡ��Ҫ���ñ����Ϣ���豸��"));
	}
	else if (checknum > 1)
	{
		MessageBox(_T("����ͬʱ���ö���豸�ı����Ϣ����һ����ס���豸���ñ����Ϣ�ɹ���"));
	}
	//else 
	//{
	//	MessageBox(_T("���ñ����Ϣ�ɹ���"));
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

		//�������ݿ�
		CppSQLite3DB db;
		db.open(LB_SCREEN_DB);
		sprintf(sql, "update LBScreenInfo set master_number = %d,slave_number = %d where master_number = %d and slave_number = %d",
			_ttoi(master_number), _ttoi(slave_number), _ttoi(master_num), _ttoi(slave_num));
		db.execDML(sql);
		printf("the sql is %s\n", sql);
		db.close();

		RefreshDeviceList();

		MessageBox(_T("���ñ����Ϣ�ѷ��ͣ�"));

	}
	else
	{
		MessageBox(_T("�����ĳ����ϢΪ�գ����鲢����������Ч����Ϣ ��"));
	}

	return TRUE;
}

void CDlgUser::OnBnClickedCheckwindoworder()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	CString appstr;

	m_ComboBox_App.GetLBText(m_ComboBox_App.GetCurSel(), appstr);
	if (strcmp(T2A(appstr), "ҽԺ") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("����/��� - ������ʾ��"));
		m_UserComboBox.AddString(_T("����/��� - ��������ʾ��"));
		m_UserComboBox.AddString(_T("��Ϣ����ϵͳ�ͻ���"));
		m_UserComboBox.AddString(_T("����������ʾ��"));
		m_UserComboBox.AddString(_T("����/��� - ���︨��ʾ��2"));
		m_UserComboBox.AddString(_T("ȡҩ/��Һ - �Ⱥ���ʾ��"));
		m_UserComboBox.AddString(_T("ȡҩ/��Һ - ������ʾ��"));
		m_UserComboBox.AddString(_T("ȡҩ/��Һ - �Ⱥ���ʾ��2"));
		m_UserComboBox.AddString(_T("ȡҩ/��Һ - ������ʾ��"));
		m_UserComboBox.AddString(_T("ȡҩ - Һ������ʾ��3"));
		m_UserComboBox.AddString(_T("����/��� - ��������ʾ��2"));
		m_UserComboBox.AddString(_T("����/��� - ���︨��ʾ��"));
		m_UserComboBox.AddString(_T("���� - ������ʾ��2"));
		m_UserComboBox.AddString(_T("���� - ���ҽк���"));
		m_UserComboBox.AddString(_T("���� - ��������ʾ��2"));
		//m_UserComboBox.AddString(_T("�Ⱥ���ʾ��(������)"));
		m_UserComboBox.AddString(_T("���� - ������ʾ��5"));
		m_UserComboBox.AddString(_T("���� - ����������ʾ��2"));
		m_UserComboBox.AddString(_T("���� - ����������ʾ��3"));
		m_UserComboBox.AddString(_T("���� - ����������ʾ��5"));
		m_UserComboBox.AddString(_T("���� - ����������ʾ��6"));
		m_UserComboBox.AddString(_T("���� - Һ��������ʾ��"));
		m_UserComboBox.AddString(_T("���� - Һ��������ʾ��2"));
		m_UserComboBox.AddString(_T("��Ϣ����"));
		m_UserComboBox.AddString(_T("��Ա--����"));
		//m_UserComboBox.AddString(_T("ɨ��ǩ����ʾ��"));
		SetDlgItemText(IDC_COMBOUSER,_T("����/��� - ������ʾ��"));
		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP2);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 14;
		InitListTable_ConsultingRoom();
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr),"����") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("�����Ŷ� - �Ⱥ���ʾ��"));
		m_UserComboBox.AddString(_T("�����Ŷ� - ������ʾ��"));
		m_UserComboBox.AddString(_T("�����Ŷ� - ������ʾ��2"));
		m_UserComboBox.AddString(_T("�����Ŷ� - ������ʾ��3"));
		m_UserComboBox.AddString(_T("�����Ŷ� - �к���"));
		m_UserComboBox.AddString(_T("�����Ŷ� - ����ʾ��2"));
		//m_UserComboBox.AddString(_T("�����Ŷ� - ������ʾ��(������)"));
		SetDlgItemText(IDC_COMBOUSER, _T("�����Ŷ� - �Ⱥ���ʾ��"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP7);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 200;
		InitListTable_BankWaitingRoom();
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "����") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("̽���Ŷ� - �Ⱥ���ʾ��"));
		SetDlgItemText(IDC_COMBOUSER, _T("̽���Ŷ� - �Ⱥ���ʾ��"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP22);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 100;
		InitListTable_Prison();
		HideAllSHOW();
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("�Ƿ�ҳ��ʾ"));
		GetDlgItem(IDC_STATIC_LETTER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LETTER)->SetWindowText(_T("��ܰ��ʾ��"));
		GetDlgItem(IDC_LETTER)->ShowWindow(SW_SHOW);

	}
	else if (strcmp(T2A(appstr), "����Խ�") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("������ʾ��"));
		m_UserComboBox.AddString(_T("��ͤ��ʾ��"));
		m_UserComboBox.AddString(_T("������ʾ - ����"));
		m_UserComboBox.AddString(_T("ʵʱ�����ʾ��"));
		m_UserComboBox.AddString(_T("������ʾ��(������)"));
		m_UserComboBox.AddString(_T("�豸��Ϣ״̬ - ����"));
		SetDlgItemText(IDC_COMBOUSER, _T("������ʾ��"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP39);   //...........
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);

		TemplateStyle = 300;     //........
		InitNetwork_intercom();

		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "����Ժ") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("������ס - ����"));
		SetDlgItemText(IDC_COMBOUSER, _T("������ס - ����"));

		CBitmap bitmap;
		HBITMAP hBmp;

		bitmap.LoadBitmap(IDB_BITMAP50);
		hBmp = (HBITMAP)bitmap.GetSafeHandle();
		m_template.SetBitmap(hBmp);
		TemplateStyle = 400;
		HideAllSHOW();
	}
	else if (strcmp(T2A(appstr), "��Ϣ����") == 0)
	{
		m_UserComboBox.ResetContent();
		m_UserComboBox.AddString(_T("��Ϣ����ϵͳ�ͻ���"));
		SetDlgItemText(IDC_COMBOUSER, _T("��Ϣ����ϵͳ�ͻ���"));

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	CString backgroundcolor;

	m_backgroundcolor.GetLBText(m_backgroundcolor.GetCurSel(), backgroundcolor);

	if (strcmp(T2A(backgroundcolor), "Ĭ��") == 0)
	{
		BackGroundColor = "fdf705";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "ff0000";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "fa800a";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "ffff00";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "00ff00";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "00ffff";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "0000ff";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "8000ff";
	}
	else if (strcmp(T2A(backgroundcolor), "��ɫ") == 0)
	{
		BackGroundColor = "ffffff";
	}//��������Դ
	else if (strcmp(T2A(backgroundcolor), "��������Դ") == 0 )
	{
		BackGroundColor = "��������Դ";
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  �˿�
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T(""));
	}
	else if (strcmp(T2A(backgroundcolor), "HIS����Դ(������������)") == 0 || strcmp(T2A(backgroundcolor), "HIS����Դ(����������)") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "HIS����Դ(������������)") == 0)
		{
			BackGroundColor = "HIS����Դ(������������)";
		}
		else
		{
			BackGroundColor = "HIS����Դ(����������)";
		}
		//IDC_STATIC_PORT  :  IDC_EDIT_INFO_PORT  �˿�
		GetDlgItem(IDC_STATIC_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(_T("����������IP:"));
		GetDlgItem(IDC_EDIT_INFO_PORT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INFO_PORT)->SetWindowText(_T("192.167.1.0"));
	}//��ʾ
	else if (strcmp(T2A(backgroundcolor), "��׼ģʽ") == 0 || strcmp(T2A(backgroundcolor), "����ģʽ") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "��׼ģʽ") == 0)
		{
			BackGroundColor = "��׼ģʽ";
		}
		else
		{
			BackGroundColor = "����ģʽ";
		}
		//IDC_CHECKHIDEPATIENT    ���ع�����ʾ
		GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("��ʾ��ͻ�����"));
		//IDC_BAD_SET   ������ʾ����
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BAD_SET)->SetWindowText(_T("������ʾ����"));
		//IDC_BUTTON_RADIO3   ����������ʾ������
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO3)->SetWindowText(_T("����������ʾ������"));
		//IDC_BUTTON_RADIO4	�Զ���ʾ������
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO4)->SetWindowText(_T("�Զ���ʾ������"));
		//IDC_BUTTON_RADIO5 �ֶ����ò�����
		GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RADIO5)->SetWindowText(_T("�ֶ����ò�����"));
		OnBnClickedButtonRadio3();
		//�رշ�ҳ
		GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_HIDE);
		
	}
	else if (strcmp(T2A(backgroundcolor), "����ͼ��") == 0 || strcmp(T2A(backgroundcolor), "��Ϣͳ��ģʽ") == 0 || strcmp(T2A(backgroundcolor), "��Լģʽ") == 0 || strcmp(T2A(backgroundcolor), "������ҳ") == 0)
	{
		if (strcmp(T2A(backgroundcolor), "������ҳ") == 0)
		{
			BackGroundColor = "������ҳ";
			//IDC_CHECKHIDEPATIENT    ���ع�����ʾ
			GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("��ʾͳ����Ϣ"));
			//IDC_CHECK_HIDE_BOTTOM    �Ƿ�ҳ��ʾ
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("��ʾ�մ���Ϣ"));
			//���л�ʱ�䣬Ĭ����ʾͳ����Ϣ....
		}
		else
		{
			if (strcmp(T2A(backgroundcolor), "����ͼ��") == 0)
			{
				BackGroundColor = "����ͼ��";
				//���л�ʱ��
			}
			else if (strcmp(T2A(backgroundcolor), "��Ϣͳ��ģʽ") == 0)
			{
				BackGroundColor = "��Ϣͳ��ģʽ";
				//���л�ʱ��
			}
			else if (strcmp(T2A(backgroundcolor), "��Լģʽ") == 0)
			{
				BackGroundColor = "��Լģʽ";
				//���л�ʱ��
			}
			//IDC_CHECKHIDEPATIENT    ���ع�����ʾ
			GetDlgItem(IDC_CHECKHIDEPATIENT)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECKHIDEPATIENT)->SetWindowText(_T("��ʾ�մ���Ϣ"));
			//IDC_CHECK_HIDE_BOTTOM    �Ƿ�ҳ��ʾ
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_CHECK_HIDE_BOTTOM)->SetWindowText(_T("��ҳҳ������Ӧ"));
		}
		//IDC_BAD_SET   ������ʾ����
		GetDlgItem(IDC_BAD_SET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RADIO5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_BADNUM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BADNUM)->ShowWindow(SW_HIDE);
		//��ȱ��һ���л�ʱ��....
	}
}

void CDlgUser::OnCbnSelchangeCombofontcolor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	CString fontcolor;

	m_fontcolor.GetLBText(m_fontcolor.GetCurSel(), fontcolor);
	if (strcmp(T2A(fontcolor), "Ĭ��") == 0)
	{
	    FontColor = "fdf705";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "ff0000";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "fa800a";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "ffff00";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "00ff00";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "00ffff";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "0000ff";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
	{
		FontColor = "8000ff";
	}
	else if (strcmp(T2A(fontcolor), "��ɫ") == 0)
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_button_radio = 0;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnBnClickedButtonRadio4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_button_radio = 1;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnBnClickedButtonRadio5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_button_radio = 2;
	UpdateData(FALSE);
	InitCheckTYPEStatus();
}

void CDlgUser::OnCbnSelchangeTypemode()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
		USES_CONVERSION;
		CString m_mode;

		m_Typemode.GetLBText(m_Typemode.GetCurSel(), m_mode);
		if (strcmp(T2A(m_mode), "Ĭ��") == 0)
		{
			Typemode = "��׼ģʽ";
		}
		else if (strcmp(T2A(m_mode), "��׼ģʽ") == 0)
		{
			Typemode = "��׼ģʽ";
		}
		else if (strcmp(T2A(m_mode), "����ģʽ") == 0)
		{
			Typemode = "����ģʽ";
		}
}

void CDlgUser::OnBnClickedButtonView()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����   
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*|*.jpg(*.jpg)|*.jpg|*.jpeg(*.jpeg)|*.jpeg|*.gif(*.gif)|*.gif|*.jpeg(*.jpeg)|*.jpeg|*.png(*.png)|*.png|*.htm(*.htm)|*.htm|*.html(*.html)|*.html||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("�����ļ�"), NULL, 0, szFilter, this);
	// ��ʾ���ļ��Ի���  
	strFilePath = "";
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	pInternetSession = NULL;
	pFtpConnection = NULL;
	//��������   
	pInternetSession = new CInternetSession(AfxGetAppName());
	//   
	CString strADddress, strUserName, strPwd, strDir, strLocalFile, strRemoteFile;
	//��������ip��ַ,�û���������,�������ĸ�Ŀ¼,Ŀ���ļ���Ŀ���ļ�
	strADddress = "192.168.1.101";
	strUserName = "lonbon";
	strPwd = "lonbon";
	strDir = "\\img\\title";  //·�����ƿ���������
	pFtpConnection = pInternetSession->GetFtpConnection(strADddress, strUserName, strPwd);
	bool bRetVal = pFtpConnection->SetCurrentDirectory(strDir); 
	if (bRetVal == false)   
	{ 
		//AfxMessageBox("Ŀ¼����ʧ��");       
		return;
	}
	else
	{
		//�ѱ����ļ��ϴ�����������    
		//strLocalFile = strFilePath;
		strRemoteFile = "icon.png";      
		pFtpConnection->PutFile((LPCTSTR)strFilePath, (LPCTSTR)strRemoteFile);
	}
	//�ͷ���Դ
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
