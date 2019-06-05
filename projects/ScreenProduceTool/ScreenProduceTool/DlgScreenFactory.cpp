// DlgScreenFactory.cpp : 实现文件
//

#include "stdafx.h"
#include "ScreenProduceTool.h"
#include "DlgScreenFactory.h"
#include "afxdialogex.h"


HANDLE hMutex1 = CreateMutex(NULL, FALSE, NULL);
// CDlgScreenFactory 对话框

IMPLEMENT_DYNAMIC(CDlgScreenFactory, CDialogEx)

CDlgScreenFactory::CDlgScreenFactory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgScreenFactory::IDD, pParent)
{

}

CDlgScreenFactory::~CDlgScreenFactory()
{
}

void CDlgScreenFactory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCREENFACTORY, m_ScreenFactoryListCtrl);
	DDX_Control(pDX, IDC_COMBODEVICETYPE, m_ScreenFactoryComboBox);
	DDX_Control(pDX, IDC_EDITORDERNUM, m_orderNum);
}


BEGIN_MESSAGE_MAP(CDlgScreenFactory, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONSCREENFACTORYINFO, &CDlgScreenFactory::OnBnClickedButtonscreenfactoryinfo)
	ON_CBN_SELCHANGE(IDC_COMBODEVICETYPE, &CDlgScreenFactory::OnCbnSelchangeCombodevicetype)
	ON_MESSAGE(WM_COUNTINCREASE_MSG, &CDlgScreenFactory::OnCountIncreaseMsg)
	ON_BN_CLICKED(IDC_BUTTONACTIVATE, &CDlgScreenFactory::OnBnClickedButtonactivate)
	ON_BN_CLICKED(IDC_BUTTONLICENSE, &CDlgScreenFactory::OnBnClickedButtonlicense)
	ON_BN_CLICKED(IDC_BUTTONREFRESH, &CDlgScreenFactory::OnBnClickedButtonrefresh)
END_MESSAGE_MAP()


// CDlgScreenFactory 消息处理程序

void CDlgScreenFactory::InitScreenFactoryListCtrl()
{
	m_ScreenFactoryListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE);
	m_ScreenFactoryListCtrl.InsertColumn(0, _T("DeviceModel"), LVCFMT_CENTER, 180);
	m_ScreenFactoryListCtrl.InsertColumn(1, _T("IP"),LVCFMT_CENTER,180);
	m_ScreenFactoryListCtrl.InsertColumn(2, _T("HardId"), LVCFMT_CENTER, 180);
	m_ScreenFactoryListCtrl.InsertColumn(3, _T("MAC"), LVCFMT_CENTER, 180);
	m_ScreenFactoryListCtrl.InsertColumn(4, _T("License"), LVCFMT_CENTER, 180);
	m_ScreenFactoryListCtrl.InsertColumn(5, _T("激活状态"), LVCFMT_CENTER, 120);

}


void CDlgScreenFactory::OnBnClickedButtonscreenfactoryinfo()
{
	
	// TODO:  在此添加控件通知处理程序代码
	BOOL isOpen = false;
	CString defaultDir = _T("D:") ;  //默认打开的文件路径
	CString fileName = _T("DEVINFO.TXT");  //默认打开的文件名
	CString filter = _T("文件(*.doc;*.ppt;*.xls;*.txt)|*.doc;*.ppt;*.xls;*.txt||");   //文件过滤的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = _T("D:\\LB_DEVINFO.txt");
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	CString text,orderNum;
	if (result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
		CString strDir = filePath;
		USES_CONVERSION;
		const int COL_NUM = 6;
		
		CFile file;
		file.Open(strDir, CFile::modeCreate | CFile::modeReadWrite);
		
		//get the orderNum
		m_orderNum.GetWindowText(orderNum);
		file.Write(T2A(orderNum), orderNum.GetLength());
		file.Write("\r\n", 2);

		for (int i = 0; i < m_ScreenFactoryListCtrl.GetItemCount(); i++)
		{
			text = m_ScreenFactoryListCtrl.GetItemText(i, 0);
			file.Write(T2A(text), text.GetLength());
			file.Write(",", 1);

			text = m_ScreenFactoryListCtrl.GetItemText(i, 2);
			file.Write(T2A(text), text.GetLength());
			file.Write(",", 1);

			text = m_ScreenFactoryListCtrl.GetItemText(i, 3);
			file.Write(T2A(text), text.GetLength());
			file.Write(",", 1);

			file.Write("\r\n", 2);
		}
		file.Close();
		MessageBox(_T("导出文件成功！"));
	}
	else
	{
		MessageBox(_T("导出文件失败！"));
	}
}

BOOL CDlgScreenFactory::ScreenFactoryComboBoxInit()
{
	m_ScreenFactoryComboBox.AddString(_T("NF-DCV"));
	SetDlgItemText(IDC_COMBODEVICETYPE, _T("NF-DCV"));
	DeviceModelstr = "NF-DCV";

	//m_ScreenFactoryComboBox.AddString(_T("NLV-DCV"));
	//SetDlgItemText(IDC_COMBODEVICETYPE, _T("NLV-DCV"));
	//DeviceModelstr = "NLV-DCV";

	//m_ScreenFactoryComboBox.AddString(_T("NLV-DC22V"));
	//m_ScreenFactoryComboBox.AddString(_T("NLV-DC32V"));
	//m_ScreenFactoryComboBox.AddString(_T("NLV-DC42V"));
	//m_ScreenFactoryComboBox.AddString(_T("NLV-DC50V"));
	//m_ScreenFactoryComboBox.AddString(_T("NLV-DC55V"));
	

	return TRUE;
}

void CDlgScreenFactory::OnCbnSelchangeCombodevicetype()
{
	// TODO:  在此添加控件通知处理程序代码
	m_ScreenFactoryComboBox.GetLBText(m_ScreenFactoryComboBox.GetCurSel(), DeviceModelstr);
}

BOOL CDlgScreenFactory::RefreshList()
{
	CppSQLite3DB db;
	CppSQLite3Table table;
	CString str;
	char sql[512] = { 0 };
	USES_CONVERSION;

	db.open(LB_SCREEN_DB);


	sprintf(sql, "select DISTINCT Devicemodel,ip,hardId,mac,License,Activate from %s ", LB_SCREENINFO);
	table = db.getTable(sql);
	//printf("the table num is %d\n", table.numRows());

	for (int i = 0; i < table.numRows(); ++i)
	{
		table.setRow(i);

		str = _T("");
		str = table.getStringField(0);
		m_ScreenFactoryListCtrl.InsertItem(i, str);
		//printf("the str is %s\n",T2A(str));
		for (int j = 1; j < 6; j++)
		{
			str = _T("");
			str = table.getStringField(j);
			m_ScreenFactoryListCtrl.SetItemText(i, j, str);
		}
	}

	db.close();
	return TRUE;
}

LRESULT CDlgScreenFactory::OnCountIncreaseMsg(WPARAM wParam, LPARAM lParam)  //响应消息刷新界面
{
	WaitForSingleObject(hMutex1, INFINITE);
	m_ScreenFactoryListCtrl.DeleteAllItems();
	RefreshList();  
	ReleaseMutex(hMutex1);
	return TRUE;
}



void CDlgScreenFactory::OnBnClickedButtonactivate()
{
	// TODO:  在此添加控件通知处理程序代码
	CString Ip,License,Mac,HardId;
	char msg[512] = { 0 };
	char sql[512] = { 0 };
	char *pos = NULL;
	CppSQLite3DB db;
	USES_CONVERSION;

	db.open(LB_SCREEN_DB);
	
	for (int i = 0; i < m_ScreenFactoryListCtrl.GetItemCount(); i++)
	{
		Ip = m_ScreenFactoryListCtrl.GetItemText(i,1);
		HardId = m_ScreenFactoryListCtrl.GetItemText(i,2);
		Mac = m_ScreenFactoryListCtrl.GetItemText(i, 3);
		License = m_ScreenFactoryListCtrl.GetItemText(i,4);
		
		sprintf(msg, "%s", "Action:LonbonLicense\r\n");
		pos = lb_str_getTail(msg);
		sprintf(pos, "%s", "InterCmd:Activate\r\n");
		pos = lb_str_getTail(pos);
		sprintf(pos, "License:%s\r\n",T2A(License));

		lb_netio_msg_sendto3(msg, sizeof(msg), T2A(Ip), PORT_NUM_BROADCAST);

		memset(sql, 0, sizeof(sql));
		sprintf(sql, "update LBScreenInfo set Activate = '已激活' where hardId = '%s' and mac = '%s'", T2A(HardId), T2A(Mac));
		db.execDML(sql);
	}

	MessageBox(_T("设备激活成功！"));
	db.close();

	m_ScreenFactoryListCtrl.DeleteAllItems();
	RefreshList();
}



BOOL CDlgScreenFactory::InsertLicense(char *DeviceModel, char *HardId, char *Mac, char *License)
{
	CppSQLite3DB db;
	CppSQLite3Table table;
	
	char sql[512] = { 0 };

	db.open(LB_SCREEN_DB);
	sprintf(sql, "update %s set License = '%s' where Devicemodel = '%s' and hardId = '%s' and mac = '%s'", LB_SCREENINFO, License, DeviceModel, HardId, Mac);
	db.execDML(sql);

	db.close();

	m_ScreenFactoryListCtrl.DeleteAllItems();
	RefreshList();

	return TRUE;
}
void CDlgScreenFactory::OnBnClickedButtonlicense()
{
	// TODO:  在此添加控件通知处理程序代码
	int ret = 0;
	int arrayLength = 0;
	char** strArray = NULL;
	CString *strReturnInfo = NULL;
	int InfoNum = 0;
	BOOL isOpen = true;
	CString defaultDir = _T("D:");
	CString fileName = _T("DEVINFO.TXT");  //默认打开的文件名
	CString filter = _T("文件(*.doc;*.ppt;*.xls;*.txt)|*.doc;*.ppt;*.xls;*.txt||");   //文件过滤的类型
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = _T("D:\\LB_DEVINFO.txt");
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
		CString strDir = filePath;
		CString ScreenInfo, DeviceModel, HardId, Mac, License;
		CStdioFile file;
		file.Open(strDir, CFile::modeRead);
		USES_CONVERSION;

		while (file.ReadString(ScreenInfo))
		{
			AfxExtractSubString(DeviceModel,ScreenInfo,0,',');
			AfxExtractSubString(HardId,ScreenInfo,1,',');
			AfxExtractSubString(Mac,ScreenInfo,2,',');
			AfxExtractSubString(License,ScreenInfo,3,',');
			//printf("the Model is %s\nthe hardId is %s\n the Mac is %s\n the License is %s\n",T2A(DeviceModel),T2A(HardId),T2A(Mac),T2A(License));
			InsertLicense(T2A(DeviceModel), T2A(HardId), T2A(Mac), T2A(License));
		}

		file.Close();
		MessageBox(_T("导入文件成功！"));
	}
	else
	{
		MessageBox(_T("导入文件失败！"));
	}
	

}


void CDlgScreenFactory::OnBnClickedButtonrefresh()
{
	 //TODO:  在此添加控件通知处理程序代码
	lb_broadcast_screen();
	//m_ScreenFactoryListCtrl.DeleteAllItems();
	//RefreshList();
}