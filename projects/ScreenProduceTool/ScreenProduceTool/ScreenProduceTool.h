
// ScreenProduceTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CScreenProduceToolApp: 
// �йش����ʵ�֣������ ScreenProduceTool.cpp
//

class CScreenProduceToolApp : public CWinApp
{
public:
	CScreenProduceToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CScreenProduceToolApp theApp;