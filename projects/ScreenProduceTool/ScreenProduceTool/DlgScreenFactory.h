#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "Clb_global.h"
#include "SQLite3Wrapper.h"
#include "lb_action.h"

#include "ss_base/ss_base.h"



// CDlgScreenFactory 对话框

class CDlgScreenFactory : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgScreenFactory)

public:
	CDlgScreenFactory(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgScreenFactory();

// 对话框数据
	enum { IDD = IDD_DLG_SCREENFACTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void InitScreenFactoryListCtrl();
	CListCtrl m_ScreenFactoryListCtrl;
	afx_msg void OnBnClickedButtonscreenfactoryinfo();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombodevicetype();
	afx_msg LRESULT OnCountIncreaseMsg(WPARAM, LPARAM);
	CComboBox m_ScreenFactoryComboBox;
	BOOL ScreenFactoryComboBoxInit();
	afx_msg void OnBnClickedButtonactivate();
	afx_msg void OnBnClickedButtonlicense();
	BOOL InsertLicense(char *DeviceModel, char *HardId, char *Mac, char *License);
	BOOL RefreshList();
	CEdit m_orderNum;
	afx_msg void OnBnClickedButtonrefresh();
};
