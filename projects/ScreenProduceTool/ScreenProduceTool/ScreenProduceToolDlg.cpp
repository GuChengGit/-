
// ScreenProduceToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ScreenProduceTool.h"
#include "ScreenProduceToolDlg.h"
#include "afxdialogex.h"

#include <WinSock2.h>
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <Afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CScreenProduceToolDlg 对话框



CScreenProduceToolDlg::CScreenProduceToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenProduceToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScreenProduceToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CScreenProduceToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CScreenProduceToolDlg::OnTcnSelchangeTab)
	ON_WM_SHOWWINDOW()
	//---------------------
	ON_MESSAGE(WM_SHOWTASK, onShowTask)
END_MESSAGE_MAP()

//--------------------------------------------
void CScreenProduceToolDlg::CreateNotifyIcon()
{
	CString szToolTip;
	szToolTip = _T("显示屏生产工具");
	nd.cbSize = sizeof(NOTIFYICONDATA);
	nd.hWnd = m_hWnd;
	nd.uID = IDI_ICON1;  //更换图标
	nd.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nd.uCallbackMessage = WM_SHOWTASK;
	nd.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	_tcscpy(nd.szTip, szToolTip);   //相当于strcpy函数
	Shell_NotifyIcon(NIM_ADD,&nd);
	ShowWindow(SW_HIDE);
}

LRESULT CScreenProduceToolDlg::onShowTask(WPARAM wParam, LPARAM IParam)
{
	if (wParam != IDI_ICON1)
		return -1;
	switch (IParam)
	{
		case WM_RBUTTONUP:  //右键单击
		{
			LPPOINT Ipoint = new tagPOINT;
			GetCursorPos(Ipoint);
			CMenu menu;
			menu.CreatePopupMenu();
			menu.AppendMenu(MF_STRING, ID_SHOW,_T("打开"));
			menu.AppendMenu(MF_STRING, ID_HIDE, _T("退出"));
			SetForegroundWindow();
			//EnableMenuItem(menu, ID_HIDE, MF_GRAYED);  //菜单变黑
			int xx = TrackPopupMenu(menu, TPM_RETURNCMD, Ipoint->x, Ipoint->y, NULL, this->m_hWnd, NULL);
			if (xx == ID_SHOW)
			{
				this->ShowWindow(true);
				SetForegroundWindow();
			}
			else if (xx == ID_HIDE) 
			{
				//结束  有无内存泄漏？ 不要重复释放内存
				ScreenFactory.SendMessage(WM_CLOSE);
				ScreenFactory.DestroyWindow();

				Factory.SendMessage(WM_CLOSE);
				Factory.DestroyWindow();

				User.SendMessage(WM_CLOSE);
				User.DestroyWindow();

				this->SendMessage(WM_CLOSE);
				this->DestroyWindow();
				CDialog::OnClose();
				CDialog::OnCancel();
			}
			HMENU hmenu = menu.Detach();
			menu.DestroyMenu();
			delete Ipoint;
		}
			break;
		case WM_LBUTTONUP:   //左键单击
		{
			this->ShowWindow(true);
			SetForegroundWindow();
		}
			break;
		case WM_LBUTTONDBLCLK:  //双击
			break;
		default:
			break;
	}
	return 0;
}

void CScreenProduceToolDlg::DeleteTray()
{
	Shell_NotifyIcon(NIM_DELETE, &nd);
}

//------------------------------------------------
// CScreenProduceToolDlg 消息处理程序

BOOL CScreenProduceToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//网络监听初始化
	//InitConsoleWindow();
	if (0 != lb_netio_init_ex(NULL, PORT_SERVER_LISTEN))
	{
		printf("error,call lb_netio_init_ex function failed!\n");
		return -1;
	}
	if (-1 == m_lb_action.lb_action_monitor_init())
	{
		printf("error,call lb_action_monitor_init function failed!\n");
		return -1;
	}

	InitTabCtrl();
	ScreenFactory.InitScreenFactoryListCtrl();
	ScreenFactory.ScreenFactoryComboBoxInit();
	//Factory.InitFactoryListCtrl();
	User.InitUserReportCtrl();
	//--------------------------------
	CreateNotifyIcon();
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BOOL CScreenProduceToolDlg::PreTranslateMessage(MSG *pMsg)
{

	if (pMsg->message == WM_KEYDOWN)
	{
		int a = 0;
		++a;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CScreenProduceToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CScreenProduceToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CScreenProduceToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CScreenProduceToolDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;

	int CurSel = m_tab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		ScreenFactory.ShowWindow(true);
		//Factory.ShowWindow(false);
		User.ShowWindow(false);
		break;
	//case 1:
		//ScreenFactory.ShowWindow(false);
		//Factory.ShowWindow(true);
		//User.ShowWindow(false);
		//break;
	case 1:
		ScreenFactory.ShowWindow(false);
		//Factory.ShowWindow(false);
		User.ShowWindow(true);
	default:
		break;
	}
}

void CScreenProduceToolDlg::InitTabCtrl()
{
	CSize size;
	size.cy = 40;
	size.cx = 100;
	m_tab.SetItemSize(size);
	m_tab.SetMinTabWidth(size.cx);

	m_tab.InsertItem(0,_T("设备激活"));
	m_tab.InsertItem(1,_T("模板设置"));
	//m_tab.InsertItem(2,_T("模板设置"));

	ScreenFactory.Create(IDD_DLG_SCREENFACTORY,GetDlgItem(IDC_TAB));
	FactoryScreenHwnd = ScreenFactory.GetSafeHwnd();
	//Factory.Create(IDD_DLG_FACTORY,GetDlgItem(IDC_TAB));
	User.Create(IDD_DLG_USER,GetDlgItem(IDC_TAB));
	UserHwnd = User.GetSafeHwnd();

	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 40;
	rs.bottom -= 3;
	rs.left += 2;
	rs.right -= 2;

	ScreenFactory.MoveWindow(&rs);
	//Factory.MoveWindow(&rs);
	User.MoveWindow(&rs);

	ScreenFactory.ShowWindow(true);
	//Factory.ShowWindow(false);
	User.ShowWindow(false);

	m_tab.SetCurSel(0);

}


void CScreenProduceToolDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO:  在此处添加消息处理程序代码
	CRect rcClient;
	this->GetClientRect(&rcClient);

	CRect rcTab;
	m_tab.GetClientRect(&rcTab);

	int i = 9;

}

void CScreenProduceToolDlg::InitConsoleWindow()
{
	int nCrt = 0;
	FILE *fp;
	AllocConsole();
	nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nCrt, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}