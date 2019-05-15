#pragma once
#include "afxcmn.h"


// CDlgFactory 对话框

class CDlgFactory : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFactory)

public:
	CDlgFactory(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFactory();

// 对话框数据
	enum { IDD = IDD_DLG_FACTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_FactoryListCtrl;
	void InitFactoryListCtrl();
	afx_msg void OnBnClickedButtonfactoryleadinfo();
    int splitString(CString strInfo,CString *strReturn);
	HWND FactoryScreen;
};
