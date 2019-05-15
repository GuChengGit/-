// DlgFactory.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScreenProduceTool.h"
#include "DlgFactory.h"
#include "afxdialogex.h"


// CDlgFactory �Ի���

IMPLEMENT_DYNAMIC(CDlgFactory, CDialogEx)

CDlgFactory::CDlgFactory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgFactory::IDD, pParent)
{

}

CDlgFactory::~CDlgFactory()
{
}

void CDlgFactory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FACTORY_LISTCTRL, m_FactoryListCtrl);
}


BEGIN_MESSAGE_MAP(CDlgFactory, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONFACTORYLEADINFO, &CDlgFactory::OnBnClickedButtonfactoryleadinfo)
END_MESSAGE_MAP()


// CDlgFactory ��Ϣ�������


void CDlgFactory::InitFactoryListCtrl()
{
	m_FactoryListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_FactoryListCtrl.InsertColumn(0, _T("CPU(ID)"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(1, _T("WiFi(MAC)"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(2, _T("LAN(MAC)"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(3, _T("�ڴ�"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(4, _T("EMMC"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(5, _T("License"), LVCFMT_CENTER, 120);
	m_FactoryListCtrl.InsertColumn(6, _T("����״̬"), LVCFMT_CENTER, 120);

}

int CDlgFactory::splitString(CString strInfo, CString *strReturn)
{
	CStringArray strArray;
	CString strGet;
	int num = 0;
	int i = 0,j = 0;
	//while (AfxExtractSubString(strGet,strInfo,i++,_T(',')))
	//{
	//	strArray.Add(strGet);
	//}
	//num = strArray.GetSize();
	//for (j = 0; j < num; j++)
	//{
		//AfxExtractSubString(strReturn[j],strInfo,j,_T(','));
	//}
	//MessageBox(strGet);
	return num;
}


void CDlgFactory::OnBnClickedButtonfactoryleadinfo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//������Ϣ
	CString *strReturnInfo = NULL;
	int InfoNum = 0;
	BOOL isOpen = true;
	CString defaultDir = _T("D:"); 
	CString fileName = _T("DEVINFO.TXT");  //Ĭ�ϴ򿪵��ļ���
	CString filter = _T("�ļ�(*.doc;*.ppt;*.xls;*.txt)|*.doc;*.ppt;*.xls;*.txt||");   //�ļ����˵�����
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = _T("D:\\LB_DEVINFO.txt");
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK)
	{
		filePath = openFileDlg.GetPathName();
		CString strDir = filePath;
		CString szLine;
		CString sztext;
		CStdioFile file;
		file.Open(strDir,CFile::modeRead);

		while (file.ReadString(szLine))
		{
			InfoNum = splitString(szLine,strReturnInfo);
			//sztext += szLine;
		}
		//MessageBox(sztext);
		file.Close();
	}
	MessageBox(_T("�����ļ��ɹ���"));
}
