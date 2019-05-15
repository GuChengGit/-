#pragma once
#include "afxcmn.h"


// CDlgFactory �Ի���

class CDlgFactory : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFactory)

public:
	CDlgFactory(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFactory();

// �Ի�������
	enum { IDD = IDD_DLG_FACTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_FactoryListCtrl;
	void InitFactoryListCtrl();
	afx_msg void OnBnClickedButtonfactoryleadinfo();
    int splitString(CString strInfo,CString *strReturn);
	HWND FactoryScreen;
};
