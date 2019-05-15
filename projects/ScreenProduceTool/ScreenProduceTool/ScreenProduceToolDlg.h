
// ScreenProduceToolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "DlgScreenFactory.h"
#include "DlgFactory.h"
#include "DlgUser.h"
#include "lb_action.h"


#define PORT_SERVER_LISTEN  5361

#define ID_SHOW 5362
#define ID_HIDE 5363
#define WM_SHOWTASK WM_USER+5


// CScreenProduceToolDlg �Ի���
class CScreenProduceToolDlg : public CDialogEx
{
// ����
public:
	CScreenProduceToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SCREENPRODUCETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	NOTIFYICONDATA nd;


// ʵ��
protected:
	HICON m_hIcon;
	BOOL PreTranslateMessage(MSG *pMsg);
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	CDlgScreenFactory ScreenFactory;
	CDlgFactory Factory;
	CDlgUser User;
	lb_action m_lb_action;
	void InitConsoleWindow();
	
	void InitTabCtrl();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//--------------------------
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM IParam);
	void DeleteTray();
	void CreateNotifyIcon();
};
