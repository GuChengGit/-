///////////////////////////////////////////////////////////////////////////////
// ReportCtrl.cpp
//
// CReportCtrl, a CListCtrl derived class that is specialized on "Report View"
// style. 
//
// Features:
//
// 1, Item sorting by clicking on column header.
// 2, Sub-item text edit.
// 3, Item repositioning.
// 4, Customizing checkbox styles, including "single" and "disabled".
// 5, Sending a message to parent window when user clicks on a checkbox.
// 6, Convenient item insertion, deletion, moving, and sub-item text changing.
// 7, Sub-item images and color
// 8, And much more... 
//
// This code may be used in compiled form in any way you desire. This file may be
// redistributed unmodified by any means PROVIDING it is not sold for profit without
// the authors written consent, and providing that this notice and the authors name 
// is included. If the source code in  this file is used in any commercial application 
// then acknowledgement must be made to the author of this file .
//
// This file is provided "as is" with no expressed or implied warranty.
//
// Written by Bin Liu (abinn32@yahoo.com)
//
// History
//
// Nov. 26, 2003 - Initial release.
// Dec. 03, 2003 - Fixed a bug in "EndEdit" where item text were not preperly committed.
//               - Completed the implementation of the "Sort-Separator" feature.
// Jan. 01, 2004 - Fixed a bug in "SetItemData".
//               - Added message "WM_EDIT_COMMITTED" which is sent to the parent window
//                 when an item text editing is committed.
//               - Fixed a bug in "SetItemText"(double type).
//               - Fixed a bug where item sorting does not work properly when there
//                 are multiple CReportCtrl objects on same window.
//
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ReportCtrl.h"
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Below styles MUST be present in a report ctrl
#define MUST_STYLE			(WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | LVS_REPORT)
#define MUST_EX_STYLE		(LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES)

// Below styles MUST NOT be present in a report ctrl
#define MUST_NOT_STYLE		(LVS_EDITLABELS | LVS_ICON | LVS_SMALLICON | LVS_LIST | LVS_NOSCROLL)
#define MUST_NOT_EX_STYLE	(0)

struct ROWINFO
{
	DWORD_PTR			dwData;
	DWORD				dwStates;
	CArray<int, int>	aImages;
	CStringArray		aTexts;
};

class CItemButton : public CButton
{
public:
	CItemButton();
	virtual ~CItemButton() {};

	BOOL GetItem(int& nItem, int& nSubItem);
	void SetItem(int nItem, int nSubItem);

private:
	int		m_nItem;
	int		m_nSubItem;
};

CItemButton::CItemButton()
	: m_nItem(-1)
	, m_nSubItem(-1)
{
}

BOOL CItemButton::GetItem(int& nItem, int& nSubItem) 
{
	if(-1 == m_nItem || -1 == m_nSubItem)
		return FALSE;
	
	nItem = m_nItem;
	nSubItem = m_nSubItem;

	return TRUE;
}

void CItemButton::SetItem(int nItem, int nSubItem)
{
	m_nItem = nItem;
	m_nSubItem = nSubItem;
}


//////////////////////////////////////////////////////////////////////////
// CItemData class is used for store extra information
//////////////////////////////////////////////////////////////////////////
class CItemData
{
public:
	CItemData();

	void InsertColumn(int nColumn);
	void DeleteColumn(int nColumn);

	DWORD_PTR dwData;										// The actual 32-bit user data stores here
	CArray<COLORREF, COLORREF> aTextColors;				// Sub item text colors
	CArray<COLORREF, COLORREF> aBkColors;				// Sub item backgroud colors
	CArray<CItemButton*, CItemButton*> aButtons;		// Sub item buttons

	DWORD dwReserve1;
	DWORD dwReserve2;

	DWORD dwReserve3;
	DWORD dwReserve4;
};

CItemData::CItemData()
	: dwData(0)
	, dwReserve1(0)
	, dwReserve2(0)
	, dwReserve3(0)
	, dwReserve4(0)
{
}

void CItemData::InsertColumn(int nColumn)
{
	aTextColors.InsertAt(nColumn, ::GetSysColor(COLOR_WINDOWTEXT));
	aBkColors.InsertAt(nColumn, ::GetSysColor(COLOR_WINDOW));
}

void CItemData::DeleteColumn(int nColumn)
{
	aTextColors.RemoveAt(nColumn);
	aBkColors.RemoveAt(nColumn);
}

///////////////////////////////////////////////////////////////////////
// A set of functions used for item text format determining
///////////////////////////////////////////////////////////////////////
namespace _ITEM_COMPARE_FUNCS
{
	BOOL _IsDecNumber(const CString& str, double& f);
	int _DecNumberCompare(double f1, double f2);
	BOOL _IsHexNumber(const CString& str, DWORD& dw);
	int _HexNumberCompare(DWORD dw1, DWORD dw2);
	BOOL _IsDate(const CString& str, COleDateTime& date);
	int _DateCompare(const COleDateTime& date1, const COleDateTime& date2);
};

BOOL _ITEM_COMPARE_FUNCS::_IsDecNumber(const CString& str, double& f)
{
	if (str.IsEmpty())
		return FALSE;

	LPTSTR p;
	f = _tcstod(str, &p);
	return (*p == _T('\0') || (*p == _T('%') && p[1] == _T('\0')));
}

int _ITEM_COMPARE_FUNCS::_DecNumberCompare(double f1, double f2)
{
	if(f1 < f2)
		return -1;
	
	if(f1 > f2)
		return 1;

	return 0;
}

BOOL _ITEM_COMPARE_FUNCS::_IsHexNumber(const CString& str, DWORD& dw)
{
	if (str.IsEmpty())
		return FALSE;

	LPTSTR p;
	dw = _tcstoul(str, &p, 16);
	return *p == _T('\0');
}

int _ITEM_COMPARE_FUNCS::_HexNumberCompare(DWORD dw1, DWORD dw2)
{
	if (dw1 > dw2)
		return 1;

	if (dw1 < dw2)
		return -1;

	return 0;
}

BOOL _ITEM_COMPARE_FUNCS::_IsDate(const CString& str, COleDateTime& date)
{
	return date.ParseDateTime(str);
}

int _ITEM_COMPARE_FUNCS::_DateCompare(const COleDateTime& date1, const COleDateTime& date2)
{
	if (date1 < date2)
		return -1;

	if (date1 > date2)
		return 1;

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CReportCtrl Implementation
/////////////////////////////////////////////////////////////////////////////
CReportCtrl::CReportCtrl()
	: m_pWndEdit(NULL)
{
	m_pWndEdit = new CEdit;
	VERIFY(m_pWndEdit != NULL);
	m_pszSeparator = NULL;
	m_bAllowEdit = FALSE;
	m_ptEditting.x = -1;
	m_ptEditting.y = -1;
	m_nChkStyle = RC_CHKBOX_NORMAL;
	m_dwPrevEditFmt = ES_LEFT;
	m_nSortCol = -1;
	m_bSortAscending = TRUE;

	m_hItemBnNotifyWnd = NULL;
}

CReportCtrl::~CReportCtrl()
{	
	if (m_pszSeparator != NULL)
		delete [] m_pszSeparator;

	if (m_pWndEdit != NULL)
		delete m_pWndEdit;
}


BEGIN_MESSAGE_MAP(CReportCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CReportCtrl)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	//ON_WM_MEASUREITEM()
	ON_WM_MEASUREITEM_REFLECT()
	ON_NOTIFY_REFLECT(LVN_ODCACHEHINT, &CReportCtrl::OnLvnOdcachehint)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_KILLFOCUS()
	ON_NOTIFY(HDN_BEGINTRACKA, 0, &CReportCtrl::OnHdnBegintrack)
	ON_NOTIFY(HDN_BEGINTRACKW, 0, &CReportCtrl::OnHdnBegintrack)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReportCtrl message handlers
void CReportCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)pNMHDR;

	if (lplvcd->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
	    *pResult = CDRF_NOTIFYITEMDRAW;
	}
    else if (lplvcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
	    *pResult = CDRF_NOTIFYSUBITEMDRAW;
	}	
    else if(lplvcd->nmcd.dwDrawStage == (CDDS_ITEMPREPAINT | CDDS_SUBITEM))
    {
		CItemData* p = (CItemData*)(CListCtrl::GetItemData((int)(lplvcd->nmcd.dwItemSpec)));
		ASSERT(p != NULL);
		ASSERT(lplvcd->iSubItem >= 0 && lplvcd->iSubItem < p->aTextColors.GetSize());

		if(NULL == p)
		{
			*pResult = CDRF_DODEFAULT;
			return;
		}	
		
		if (p->aTextColors.GetSize() > lplvcd->iSubItem)
			lplvcd->clrText = p->aTextColors[lplvcd->iSubItem];

		if (p->aBkColors.GetSize() > lplvcd->iSubItem)
			lplvcd->clrTextBk = p->aBkColors[lplvcd->iSubItem];

		*pResult = CDRF_NOTIFYPOSTPAINT;
	}
	else if(lplvcd->nmcd.dwDrawStage == (CDDS_ITEMPOSTPAINT | CDDS_SUBITEM))
    {
        // If this item is selected, re-draw the icon in its normal
        // color (not blended with the highlight color).

        int nItem = static_cast<int>(lplvcd->nmcd.dwItemSpec);

        // Get the image index and state of this item.  Note that we need to
        // check the selected state manually.  The docs _say_ that the
        // item's state is in pLVCD->nmcd.uItemState, but during my testing
        // it was always equal to 0x0201, which doesn't make sense, since
        // the max CDIS_* constant in commctrl.h is 0x0100.

		LVITEM rItem = {0};
        rItem.mask  = LVIF_IMAGE | LVIF_STATE;
        rItem.iItem = nItem;
		rItem.iSubItem = lplvcd->iSubItem ;
        rItem.stateMask = LVIS_SELECTED;
        GetItem(&rItem);

		/*
		if (1 == lplvcd->iSubItem) // test
		{
			int nItem = lplvcd->nmcd.dwItemSpec;
			int nSubItem = lplvcd->iSubItem;
		
			CRect rcSubItem;
			this->GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rcSubItem);

			//CProgressCtrl* pCtrl = (CProgressCtrl*)this->GetItemData(nItem);
			CButton* pCtrl = (CButton*)this->GetItemData(nItem);
			if (NULL == pCtrl)
			{
				//pCtrl = new CProgressCtrl;
				pCtrl = new CButton;
				if (rcSubItem.Width() > 100)
					rcSubItem.right = rcSubItem.left + 100;

				CString strTxt ;
				strTxt.Format(TEXT("bn:%d"), nItem) ;

				rcSubItem.DeflateRect(5, 2) ;
				pCtrl->Create(strTxt, WS_CHILD|WS_VISIBLE|PBS_SMOOTH, rcSubItem, 
					this, 0x1000 + nItem);
				ASSERT(pCtrl->GetSafeHwnd());
				//pCtrl->SetPos( nItem*10 % 100 );
				this->SetItemData(nItem, (DWORD)pCtrl);
			}

			if (rcSubItem.Width() > 100)
				rcSubItem.right = rcSubItem.left + 100;
			rcSubItem.DeflateRect(5, 2) ;
			pCtrl->MoveWindow(rcSubItem);
			pCtrl->ShowWindow(SW_SHOW);
		}
		*/

		/*
		if (1 && 1 == lplvcd->iSubItem)
		{
			int nItem = lplvcd->nmcd.dwItemSpec;
			int nSubItem = lplvcd->iSubItem;

			CRect rcSubItem;
			this->GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rcSubItem);

			CString strTxt ;
			
			CDC*  pDC = CDC::FromHandle ( lplvcd->nmcd.hdc );
			//pDC->FillSolidRect(rcSubItem, RGB(255, 128, 128)) ;
			
			//::SelectObject(lplvcd->nmcd.hdc, m_fontLink.m_hObject);
		}
		else
		{
			//::SelectObject(lplvcd->nmcd.hdc, m_fontNoLink.m_hObject);
		}
		*/

		/* Check button item */
		{
			int nItem = (int)(lplvcd->nmcd.dwItemSpec);
			int nSubItem = lplvcd->iSubItem;
			int i = nSubItem;

			CRect rcSubItem;
			this->GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rcSubItem);

			CItemData* pData = (CItemData*)CListCtrl::GetItemData(nItem);
			if (pData && pData->aButtons[i])
			{
				if (rcSubItem.Width() > 100)
					rcSubItem.right = rcSubItem.left + 100;
				rcSubItem.DeflateRect(5, 2);
				pData->aButtons[i]->MoveWindow(rcSubItem);
				pData->aButtons[i]->ShowWindow(SW_SHOW);
			}
		}

        // If this item is selected, redraw the icon with its normal colors.
        if(rItem.state & LVIS_SELECTED)
        {
            CDC* pDC = CDC::FromHandle(lplvcd->nmcd.hdc);
            CRect rcIcon;

			CImageList* pImageList = GetImageList();
			if(NULL == pImageList)
			{
				*pResult = CDRF_DODEFAULT;
				return;
			}

			int nImage = GetItemImage(nItem, lplvcd->iSubItem);
			if(nImage < 0)
			{
				*pResult = CDRF_DODEFAULT;
				return;
			}
#if 0
            // Get the rect that holds the item's icon.
            GetItemRect(nItem, &rcIcon, LVIR_ICON);

            // Draw the icon.
            GetImageList()->Draw(pDC, rItem.iImage, rcIcon.TopLeft(), ILD_TRANSPARENT);
#else
			GetSubItemRect(nItem, lplvcd->iSubItem, LVIR_ICON, rcIcon);

			pImageList->Draw(pDC, nImage, rcIcon.TopLeft(), ILD_TRANSPARENT);
#endif

            *pResult = CDRF_SKIPDEFAULT;
        }
		else
		{
			*pResult = CDRF_DODEFAULT;
		}
		// TRACE("-------CDDS_ITEMPOSTPAINT-----------\n") ;
    }
}

void CReportCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
#if 0 /* Disable this for test */
	const int COL = pNMListView->iSubItem;
	SortItems(COL, COL == m_nSortCol ? !m_bSortAscending : TRUE);
#endif
	*pResult = 0;
}

void CReportCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_LBUTTONDOWN, nFlags, point, TRUE);
}

void CReportCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_LBUTTONDBLCLK, nFlags, point, TRUE);
}

void CReportCtrl::OnMButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_MBUTTONDOWN, nFlags, point, FALSE);
}

void CReportCtrl::OnMButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_MBUTTONDBLCLK, nFlags, point, FALSE);
}

void CReportCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_RBUTTONDOWN, nFlags, point, FALSE);
}

void CReportCtrl::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	_MouseClkMonitor(WM_RBUTTONDBLCLK, nFlags, point, FALSE);
}

int CReportCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	lpCreateStruct->style &= ~MUST_NOT_STYLE;
	lpCreateStruct->style |= MUST_STYLE;

	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetExtendedStyle(GetExtendedStyle());
	ASSERT(GetHeaderCtrl() != NULL);

	return 0;
}

void CReportCtrl::OnDestroy() 
{
	DeleteAllItems();

	m_pWndEdit->DestroyWindow();
	m_imgList.DeleteImageList();
	m_headerImgList.DeleteImageList();

	CListCtrl::OnDestroy();
	// TODO: Add your message handler code here	
}

BOOL CReportCtrl::_IsValidIndex(int nIndex) const
{
	return nIndex >= 0 && nIndex < CListCtrl::GetItemCount();
}

// the heading text is in the format of "text,width,format;text,width,format;..."
BOOL CReportCtrl::SetColumnHeader(const CString& strHeadings)
{
	DeleteAllItems();
	DeleteAllColumns();
	EndEdit(TRUE);
	BOOL bInserted = FALSE;
	CStringArray aLong, aShort;
	_StringSplit(strHeadings, aLong, _T(';'));
	for (int i = 0; i < aLong.GetSize(); i++)
	{
		_StringSplit(aLong[i], aShort, _T(','));
		if (aShort.GetSize() > 0)
		{
			const int WIDTH = aShort.GetSize() > 1 ? _ttoi(aShort[1]) : 100;
			int nFormat = aShort.GetSize() > 2 ? _ttoi(aShort[2]) : 0;

			if (nFormat == 1)
				nFormat = LVCFMT_CENTER;
			else if (nFormat == 2)
				nFormat = LVCFMT_RIGHT;
			else
				nFormat = LVCFMT_LEFT;

//			TRACE("[%d]: nFormat: [%d]\n", GetColumnCount(), nFormat) ;
			
			bInserted |= (InsertColumn(GetColumnCount()+0, aShort[0], nFormat, WIDTH) >= 0);

			m_arrayAllowEditPart.Add(FALSE) ;
		}
	}
	return bInserted;
}

int CReportCtrl::InsertItem(int nIndex, LPCTSTR lpText)
{	
	EndEdit(TRUE);

	_UnsetSortedColumn();

	const int IDX = CListCtrl::InsertItem(nIndex, lpText);
	if (IDX >= 0)
		_AllocItemMemory(IDX);

	return IDX;
}

BOOL CReportCtrl::DeleteItem(int nItem, BOOL bSelectNextItem)
{
	BOOL bRet = FALSE ;
	EndEdit(m_ptEditting.x != nItem);
	
	if (bSelectNextItem)
		SetItemStates(nItem + 1, RC_ITEM_SELECTED);

	_FreeItemMemory(nItem);

	bRet = CListCtrl::DeleteItem(nItem);
	Invalidate(FALSE) ;
	return bRet ;
}

int CReportCtrl::DeleteAllItems(DWORD dwStates)
{
	EndEdit(FALSE);

	int nItemCount = CListCtrl::GetItemCount();
	if (dwStates & RC_ITEM_ALL)
	{
		LockWindowUpdate();
		for (int i = 0; i < nItemCount; i++)
			_FreeItemMemory(i);
		CListCtrl::DeleteAllItems();
		UnlockWindowUpdate();
		return nItemCount;		
	}
	
	int nDelCount = 0;
	LockWindowUpdate();

	for (int i = 0; i < nItemCount; i++)
	{
		if (ExamItemStates(i, dwStates))
		{
			DeleteItem(i--);
			nItemCount--;
			nDelCount++;
		}
	}	

	UnlockWindowUpdate();

	return nDelCount;
}

void CReportCtrl::SortItems(int nColumn, BOOL bAscending)
{
	EndEdit(TRUE);
	if (nColumn < 0 || nColumn >= GetColumnCount() || !IsSortable())
		return;	

	// do the sorting	
	m_nSortCol = nColumn;
	m_bSortAscending = bAscending;
	
	BOOL bEnd = FALSE;
	int nSep1 = -1;
	int nSep2 = _FindSeparator(-1, nColumn);
	do
	{
		if (nSep2 < 0)
		{
			nSep2 = GetItemCount();
			bEnd = TRUE;
		}
		_PartialSort(nSep1 + 1, nSep2 - 1);
		nSep1 = _FindSeparator(nSep2 - 1, nColumn);
		nSep2 = _FindSeparator(nSep1, nColumn);
	} while (!bEnd && nSep1 >= 0);

	GetParent()->SendMessage(WM_ITEM_SORTED, (WPARAM)m_nSortCol, (LPARAM)m_bSortAscending);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, LPCTSTR lpText)
{
	EndEdit(TRUE);
	_UnsetSortedColumn();
	return CListCtrl::SetItemText(nItem, nSubItem, lpText);
}

int CReportCtrl::GetColumnCount() const
{
	return GetHeaderCtrl()->GetItemCount();
}

int CReportCtrl::InsertItem(const LVITEM *pItem)
{
	EndEdit(TRUE);
	_UnsetSortedColumn();
	const int IDX = CListCtrl::InsertItem(pItem);
	if (IDX >= 0)
		_AllocItemMemory(IDX);
	return IDX;
}

int CReportCtrl::InsertItem(int nItem, LPCTSTR lpItem, int nImage)
{	
	EndEdit(TRUE);
	_UnsetSortedColumn();
	const int IDX = CListCtrl::InsertItem(nItem, lpItem, nImage);
	if (IDX >= 0)
		_AllocItemMemory(IDX);
	return IDX;
}

int CReportCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam)
{
	EndEdit(TRUE);
	_UnsetSortedColumn();
	const int IDX = CListCtrl::InsertItem(nMask, nItem, lpItem, nState, nStateMask, nImage, lParam);
	if (IDX >= 0)
		_AllocItemMemory(IDX);
	return IDX;
}

void CReportCtrl::SetGridLines(BOOL bSet)
{
	DWORD dwStype = GetExtendedStyle();

	if (bSet)
		dwStype |= LVS_EX_GRIDLINES;
	else
		dwStype &= ~LVS_EX_GRIDLINES;

	SetExtendedStyle(dwStype);	
}

int CReportCtrl::InsertColumn(int nCol, const LVCOLUMN *pColumn)
{
	EndEdit(TRUE);
	const int IDX = CListCtrl::InsertColumn(nCol, pColumn);
	if (IDX >= 0)
		_UpdateColumn(IDX, TRUE);
	return IDX;
}

int CReportCtrl::InsertColumn(int nCol, LPCTSTR lpColumnHeading, int nFormat, int nWidth, int nSubItem)
{
	EndEdit(TRUE);
	const int IDX = CListCtrl::InsertColumn(nCol, lpColumnHeading, nFormat, nWidth, nSubItem);
	if (IDX >= 0)
		_UpdateColumn(IDX, TRUE);
	return IDX;
}

BOOL CReportCtrl::DeleteColumn(int nCol)
{
	EndEdit(TRUE);
	const BOOL RES = CListCtrl::DeleteColumn(nCol);
	if (RES)
		_UpdateColumn(nCol, FALSE);
	return RES;
}

void CReportCtrl::SetCheckboxeStyle(int nStyle)
{
	m_nChkStyle = nStyle;
	EndEdit(TRUE);
	DWORD dwStype = GetExtendedStyle();
	if (nStyle == 0)
	{
		dwStype &= ~LVS_EX_CHECKBOXES;		
	}
	else
	{
		dwStype |= LVS_EX_CHECKBOXES;
		_EnsureSingleCheck(-1);
	}

	SetExtendedStyle(dwStype);
}

int CReportCtrl::MoveTo(int nItem, int nNewPosition)
{
	if (!_IsValidIndex(nItem))
		return -1;

	EndEdit(TRUE);
	const int ITEMS = CListCtrl::GetItemCount();
	nNewPosition = max(0, nNewPosition);
	nNewPosition  = min(ITEMS - 1, nNewPosition);

	if (nItem == nNewPosition)
		return nNewPosition;

	_UnsetSortedColumn();

	// Backup all states and attributes
	const int COLS = GetColumnCount();
	const DWORD STATES = GetItemStates(nItem);
	const DWORD_PTR DATA = CListCtrl::GetItemData(nItem);
	CArray<int, int> aImages;
	CStringArray aTexts;
	aImages.SetSize(COLS);
	aTexts.SetSize(COLS);
	for (int i = 0; i < COLS; i++)
	{
		aImages[i] = GetItemImage(nItem, i);
		aTexts[i] = GetItemText(nItem, i);
	}	

	// Delete the item
	CListCtrl::DeleteItem(nItem);

	// Insert a new item to the new position
	const int IDX = CListCtrl::InsertItem(nNewPosition, TEXT(""));

	// Restore all states & attributes to the newly inserted item
	for (int j = 0; j < COLS; j++)
	{
		CListCtrl::SetItemText(IDX, j, aTexts[j]);
		SetItemImage(IDX, j, aImages[j]);
	}
	CListCtrl::SetItemData(IDX, DATA);
	SetItemStates(IDX, STATES);
	return IDX;
}

int CReportCtrl::MoveUp(int nItem, int nCount)
{	
	return MoveTo(nItem, nItem - nCount);
}

BOOL CReportCtrl::MoveDown(int nItem, int nCount)
{
	return MoveTo(nItem, nItem + nCount);
}

BOOL CReportCtrl::SwapItems(int nItem1, int nItem2)
{
	EndEdit(TRUE);
	if (!_IsValidIndex(nItem1) || !_IsValidIndex(nItem2))
		return FALSE;

	if (nItem1 == nItem2)
		return TRUE;

	_UnsetSortedColumn();

	// record previous states first
	const DWORD STATES1 = GetItemStates(nItem1);
	const DWORD STATES2 = GetItemStates(nItem2);
	const DWORD_PTR DATA1 = CListCtrl::GetItemData(nItem1);
	const DWORD_PTR DATA2 = CListCtrl::GetItemData(nItem2);

	// swap item texts and images
	for (int i = 0; i < GetColumnCount(); i++)
	{
		CString str = GetItemText(nItem1, i);
		CListCtrl::SetItemText(nItem1, i, GetItemText(nItem2, i));
		CListCtrl::SetItemText(nItem2, i, str);
		UINT nImg = GetItemImage(nItem1, i);
		SetItemImage(nItem1, i, GetItemImage(nItem2, i));
		SetItemImage(nItem2, i, nImg);
	}
	
	// swap item data
	CListCtrl::SetItemData(nItem1, DATA2);
	CListCtrl::SetItemData(nItem2, DATA1);

	// restore states
	SetItemStates(nItem1, STATES2);
	SetItemStates(nItem2, STATES1);

	return TRUE;
}

int CReportCtrl::MoveToTop(int nItem)
{
	return MoveTo(nItem, -1);
}

int CReportCtrl::MoveToBottom(int nItem)
{
	return MoveTo(nItem, INT_MAX);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, TCHAR val)
{
	return SetItemText(nItem, nSubItem, CString(val));
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, INT val)
{	
	return SetItemText(nItem, nSubItem, (LONG)val);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, UINT val)
{
	return SetItemText(nItem, nSubItem, (ULONG)val);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, DOUBLE val, int nPrecision)
{
	CString sText, sFmt;
	
	if (nPrecision >= 0)
	{
		sFmt.Format(_T("%%.%df"), nPrecision);
		sText.Format(sFmt, val);
	}
	else
	{
		sText.Format(_T("%f"), val);
		sText.TrimRight(_T('0'));
		sText.TrimRight(_T('.'));
	}
	
	return SetItemText(nItem, nSubItem, sText);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, const COleDateTime &dateTime, DWORD dwFlags)
{
	return SetItemText(nItem, nSubItem, dateTime.GetStatus() == COleDateTime::valid ? dateTime.Format(dwFlags) : _T(""));
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, LONG val)
{
	CString str;
	str.Format(_T("%d"), val);
	return SetItemText(nItem, nSubItem, str);
}

BOOL CReportCtrl::SetItemText(int nItem, int nSubItem, ULONG val)
{
	CString str;
	str.Format(_T("%u"), val);
	return SetItemText(nItem, nSubItem, str);
}

BOOL CReportCtrl::SetItemButtonText(int nItem, int nSubItem, LPCTSTR lpszButtonText, LPCTSTR lpszSubItemText /*= TEXT("")*/)
{
	int nColCount = GetColumnCount();
	if (nSubItem < 0 || nSubItem > nColCount - 1)
		return FALSE;

	CItemData* pData = (CItemData*)CListCtrl::GetItemData(nItem);
	if (NULL == pData)
		return FALSE;

	if(!pData->aButtons[nSubItem])
	{
		CRect rcSubItem;
		GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rcSubItem);

		CItemButton* pCtrl = new CItemButton;
		if (NULL == pCtrl)
			return FALSE;

		if (rcSubItem.Width() > 100)
			rcSubItem.right = rcSubItem.left + 100;

		rcSubItem.DeflateRect(5, 2);
		pCtrl->Create(lpszButtonText, WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rcSubItem, this, nItem);
		ASSERT(pCtrl->GetSafeHwnd());
		pCtrl->ShowWindow(SW_HIDE);
		pData->aButtons[nSubItem] = pCtrl;

		pCtrl->SetItem(nItem, nSubItem);

		//pCtrl->SetPos( nItem*10 % 100 );
		//this->SetItemData(nItem, (DWORD)pData);
	}

	return SetItemText(nItem, nSubItem, lpszSubItemText);
}

BOOL CReportCtrl::DeleteAllColumns()
{
	while (GetColumnCount() > 0)
		DeleteColumn(0);

	return TRUE;
}

LPCTSTR CReportCtrl::GetSortSeparator() const
{
	return m_pszSeparator;
}

void CReportCtrl::SetSortSeparator(LPCTSTR lpSortSeparator)
{
	if (m_pszSeparator != NULL)
	{
		delete [] m_pszSeparator;
		m_pszSeparator = NULL;
	}

	if (lpSortSeparator != NULL)
		m_pszSeparator = _tcsdup(lpSortSeparator);
}

int CReportCtrl::InsertItemEx(int nItem, LPCTSTR lpText, ...)
{
	EndEdit(TRUE);
	_UnsetSortedColumn();
	const int IDX = CListCtrl::InsertItem(nItem, lpText);
	if (IDX < 0)
		return -1;

 	va_list list;
	va_start(list, lpText);

	for(int iColumn = 1; iColumn < GetColumnCount(); iColumn++)
	{
		LPCTSTR lp = va_arg(list, LPCTSTR);
		if (lp != NULL)
		{
			CListCtrl::SetItemText(IDX, iColumn, lp);
		}
		else
		{
			break;
		}
	}

	va_end(list);

	if (IDX >= 0)
		_AllocItemMemory(IDX);

	return IDX;
}

BOOL CReportCtrl::_IsEditVisible() const
{
#if 0
	return m_bAllowEdit
		&& m_ptEditting.x >= 0 && m_ptEditting.x < CListCtrl::GetItemCount()
		&& m_ptEditting.y >= 0 && m_ptEditting.y < GetColumnCount();
#else
	if (m_bAllowEdit)
	{
		return 
		m_ptEditting.x >= 0 && m_ptEditting.x < CListCtrl::GetItemCount()
		&& m_ptEditting.y >= 0 && m_ptEditting.y < GetColumnCount();
	}
	else
	{
		BOOL bEdit = FALSE ;
		for (int i=0;i <= m_arrayAllowEditPart.GetUpperBound(); i++)
		{
			if (m_arrayAllowEditPart.GetAt(i))
			{
				bEdit = TRUE ;
				break ;
			}
		} 

		return bEdit
		&& m_ptEditting.x >= 0 && m_ptEditting.x < CListCtrl::GetItemCount()
		&& m_ptEditting.y >= 0 && m_ptEditting.y < GetColumnCount();

	}
#endif
}

void CReportCtrl::SetEditable(BOOL bSet)
{	
	if (!bSet)
		EndEdit(TRUE);
	m_bAllowEdit = bSet;
}

void CReportCtrl::SetEditablePart(int nSubItem, BOOL bSet) 
{
	if (!bSet)
		EndEdit(TRUE);

	m_arrayAllowEditPart.SetAt(nSubItem, bSet) ;
}

BOOL CReportCtrl::IsEditable() const
{
	return m_bAllowEdit;
}

BOOL CReportCtrl::_ItemCheckMonitor(int nIndex, BOOL bBefore, BOOL bAfter, UINT nMsg)
{
	if (!_IsValidIndex(nIndex)
		|| m_nChkStyle == RC_CHKBOX_NONE
		|| (bBefore && bAfter)
		|| (!bBefore && !bAfter))
	{
		return FALSE;
	}

	if (m_nChkStyle == RC_CHKBOX_SINGLE)
	{
		// Only one item can be checked
		if (!bBefore && bAfter)
		{
			SetAllItemStates(RC_ITEM_CHECKED, RC_ITEM_UNCHECKED); // uncheck all
			SetItemStates(nIndex, RC_ITEM_CHECKED);
		}		
	}
	else if (m_nChkStyle == RC_CHKBOX_DISABLED)
	{
		// Cannot change the item checked/unchecked states by mouse clicks
		SetItemStates(nIndex, bBefore ? RC_ITEM_CHECKED : RC_ITEM_UNCHECKED);
		return TRUE;
	}	

	SetAllItemStates(RC_ITEM_SELECTED, RC_ITEM_UNSELECTED); // unselect all
	SetItemStates(nIndex, RC_ITEM_SELECTED | RC_ITEM_FOCUSED);
	GetParent()->SendMessage(WM_ON_CHKBOX, (WPARAM)nIndex, (LPARAM)nMsg);
	return TRUE;
}

int CReportCtrl::GetCheckboxStyle() const
{
	return m_nChkStyle;
}

void CReportCtrl::_StringSplit(const CString &str, CStringArray &arr, TCHAR chDelimitior)
{
	int nStart = 0, nEnd = 0;
	arr.RemoveAll();

	while (nEnd < str.GetLength())
	{
		// determine the paragraph ("xxx,xxx,xxx;")
		nEnd = str.Find(chDelimitior, nStart);
		if( nEnd == -1 )
		{
			// reached the end of string
			nEnd = str.GetLength();
		}

		CString s = str.Mid(nStart, nEnd - nStart);
		if (!s.IsEmpty())
			arr.Add(s);

		nStart = nEnd + 1;
	}
}

BOOL CReportCtrl::SetSortable(BOOL bSet)
{
	if (!HasColumnHeader())
		return FALSE;

	LONG lStyle = ::GetWindowLong(GetHeaderCtrl()->GetSafeHwnd(), GWL_STYLE);
	if (bSet)
	{
		lStyle |= HDS_BUTTONS;
	}
	else
	{
		lStyle &= ~HDS_BUTTONS;
		_UnsetSortedColumn();
	}
	::SetWindowLong(GetHeaderCtrl()->GetSafeHwnd(), GWL_STYLE, lStyle);
	CListCtrl::GetHeaderCtrl()->RedrawWindow();
	return TRUE;
}

DWORD CReportCtrl::SetExtendedStyle(DWORD dwNewStyle)
{
	dwNewStyle &= ~MUST_NOT_EX_STYLE;
	dwNewStyle |= MUST_EX_STYLE;
	return CListCtrl::SetExtendedStyle(dwNewStyle);
}

BOOL CReportCtrl::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style &= ~MUST_NOT_STYLE;
	cs.style |= MUST_STYLE;

	return CListCtrl::PreCreateWindow(cs);
}

BOOL CReportCtrl::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if (!_IsEditVisible())
		{
			// disable user from check/uncheck the checkboxes using space key
			// things get nasty if the user is HOLDING the space bar down
			if (pMsg->wParam == VK_SPACE)
				return TRUE;
		}
		else
		{
			POINT pt = m_ptEditting;
			switch (pMsg->wParam)
			{
			case VK_ESCAPE: // Cancel edit
				EndEdit(FALSE);
				return TRUE;

			case VK_RETURN: // Commit edit
				EndEdit(TRUE);
				return TRUE;

			case VK_TAB: // switch edit sub items
				if (pt.y == GetColumnCount() - 1)
					pt.y = 0;
				else
					pt.y++;
				EndEdit(TRUE);
				StartEdit(pt.x, pt.y);
				return TRUE;

			case VK_UP: // edit upper item
				if (pt.x > 0)
				{
					pt.x--;
					EndEdit(TRUE);					
					EnsureVisible(pt.x, FALSE);
					StartEdit(pt.x, pt.y);
					return TRUE;
				}
				break;
				
			case VK_DOWN: // edit lower item
				if (pt.x < CListCtrl::GetItemCount() - 1)
				{
					pt.x++;
					EndEdit(TRUE);					
					EnsureVisible(pt.x, FALSE);
					StartEdit(pt.x, pt.y);
					return TRUE;
				}
				break;			

			default:
				break;				
			}
		}
	}

	return CListCtrl::PreTranslateMessage(pMsg);
}

CEdit* CReportCtrl::GetEditControl()
{
	return m_pWndEdit;
}

BOOL CReportCtrl::Create(CWnd* pParentWnd, UINT nID, LPCRECT lpRect, DWORD dwStyle) 
{
	// TODO: Add your specialized code here and/or call the base class
	ASSERT(pParentWnd != NULL);

	dwStyle &= ~MUST_NOT_STYLE;
	dwStyle |= MUST_STYLE;

	CRect rect;
	if (lpRect == NULL)
		pParentWnd->GetClientRect(&rect);
	else
		rect = *lpRect;

	return CListCtrl::Create(dwStyle, rect, pParentWnd, nID);
}

void CReportCtrl::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	LONG lStyle = ::GetWindowLong(GetSafeHwnd(), GWL_STYLE);
	lStyle &= ~MUST_NOT_STYLE;
	lStyle |= MUST_STYLE;
	::SetWindowLong(GetSafeHwnd(), GWL_STYLE, lStyle);
	SetExtendedStyle(0);
	ASSERT(GetHeaderCtrl() != NULL);
	CListCtrl::PreSubclassWindow();

	InitFont(TRUE, &m_fontLink);
	InitFont(FALSE, &m_fontNoLink);
}

BOOL CReportCtrl::IsSortable() const
{
	if (!HasColumnHeader())
		return FALSE;

	LONG lStyle = ::GetWindowLong(GetHeaderCtrl()->GetSafeHwnd(), GWL_STYLE);
	return (lStyle & HDS_BUTTONS) != 0;
}

BOOL CReportCtrl::HasColumnHeader() const
{
	return (GetStyle() & LVS_NOCOLUMNHEADER) == 0;
}

void CReportCtrl::ResizeToFitParent()
{
	// resize the list ctrl to fit parent client area
	if (GetSafeHwnd() != NULL)
	{
		CRect rect;
		GetParent()->GetClientRect(&rect);
		MoveWindow(&rect);
	}
}

BOOL CReportCtrl::ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags)
{
	dwRemove &= ~MUST_EX_STYLE;
	dwRemove |= MUST_NOT_EX_STYLE;
	dwAdd &= ~MUST_NOT_EX_STYLE;
	dwAdd |= MUST_EX_STYLE;
	return CListCtrl::ModifyStyleEx(dwRemove, dwAdd, nFlags);
}

BOOL CReportCtrl::ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags)
{
	dwRemove &= ~MUST_STYLE;
	dwRemove |= MUST_NOT_STYLE;
	dwAdd &= ~MUST_NOT_STYLE;
	dwAdd |= MUST_STYLE;
	return CListCtrl::ModifyStyle(dwRemove, dwAdd, nFlags);
}

void CReportCtrl::_MouseClkMonitor(UINT nMsg, UINT nFlags, CPoint point, BOOL bTriggerEdit)
{
	LVHITTESTINFO hti;
	hti.pt = point;
	const int IDX = SubItemHitTest(&hti);
	const BOOL BEFORE = CListCtrl::GetCheck(IDX) > 0;
	const BOOL WAS_EDIT = _IsEditVisible();
	EndEdit(TRUE);
	const BOOL WASACTIVE = bTriggerEdit ? ExamItemStates(IDX, RC_ITEM_FOCUSED | RC_ITEM_SELECTED) : FALSE;

	switch (nMsg)
	{
	case WM_LBUTTONDOWN:
		CListCtrl::OnLButtonDown(nFlags, point);
		break;
	
	case WM_LBUTTONDBLCLK:
		CListCtrl::OnLButtonDblClk(nFlags, point);
		break;

	case WM_MBUTTONDOWN:
		CListCtrl::OnMButtonDown(nFlags, point);
		break;

	case WM_MBUTTONDBLCLK:
		CListCtrl::OnMButtonDblClk(nFlags, point);
		break;

	case WM_RBUTTONDOWN:
		CListCtrl::OnRButtonDown(nFlags, point);
		break;

	case WM_RBUTTONDBLCLK:
		CListCtrl::OnRButtonDblClk(nFlags, point);
		break;

	default:
		break;		
	}
	
	const BOOL STATSCHANGED = _ItemCheckMonitor(IDX, BEFORE, CListCtrl::GetCheck(IDX) > 0, nMsg);

	if (bTriggerEdit && m_bAllowEdit && !STATSCHANGED && !WAS_EDIT && WASACTIVE)
	{
		StartEdit(IDX, hti.iSubItem);
	}
	else if (bTriggerEdit && !m_bAllowEdit && !STATSCHANGED && !WAS_EDIT && WASACTIVE)
	{
		if (m_arrayAllowEditPart.GetAt(hti.iSubItem))
			StartEdit(IDX, hti.iSubItem);
		else
			EndEdit(TRUE);
	}
}

BOOL CReportCtrl::SetItemImage(int nItem, int nSubItem, int nImageIndex)
{
	return CListCtrl::SetItem(nItem, nSubItem, LVIF_IMAGE, NULL, nImageIndex, 0, 0, 0);
}

int CReportCtrl::GetItemImage(int nItem, int nSubItem) const
{
	LVITEM lvi;
	lvi.iItem = nItem;
	lvi.iSubItem = nSubItem;
	lvi.mask = LVIF_IMAGE;
	return CListCtrl::GetItem(&lvi) ? lvi.iImage : -1;
}

CImageList* CReportCtrl::SetImageList(CImageList *pImageList)
{
	return CListCtrl::SetImageList(pImageList, LVSIL_SMALL);
}

CImageList* CReportCtrl::GetImageList() const
{
	return CListCtrl::GetImageList(LVSIL_SMALL);
}

CImageList* CReportCtrl::SetImageList(UINT nBitmapID, COLORREF crMask)
{
	m_imgList.DeleteImageList();
	m_imgList.Create(nBitmapID, 16, 4, crMask);	
//	m_imgList.Create(16, 16, ILC_COLOR24, 0, 4);
	return CListCtrl::SetImageList(&m_imgList, LVSIL_SMALL);
}

BOOL CReportCtrl::StartEdit(int nItem, int nSubItem)
{
	// Get the grid width and height
	if (!m_bAllowEdit || !_IsValidIndex(nItem) || nSubItem < 0 || nSubItem >= GetColumnCount())
	{
		if (!m_arrayAllowEditPart.GetAt(nSubItem))
			return FALSE;
	}		
	
	if (m_ptEditting.x == nItem && m_ptEditting.y == nSubItem)
		return TRUE;

	EndEdit(TRUE);
	m_ptEditting.x = nItem;
	m_ptEditting.y = nSubItem;
	SetAllItemStates(RC_ITEM_SELECTED, RC_ITEM_UNSELECTED); // unselect all
	SetItemStates(m_ptEditting.x, RC_ITEM_SELECTED | RC_ITEM_FOCUSED);

	// determine editbox font and alignment
	const DWORD FMT = _GetHeaderTextFormat(nSubItem);
	if (FMT != m_dwPrevEditFmt)
	{
		m_dwPrevEditFmt = FMT;

		// Funny thing:
		// Changing CEdit style among ES_LEFT, ES_CENTER, ES_RIGHT at runtime works
		// sometimes and fails other times. It just cannot guarantee to be succeed.
		// So I decided to destroy and recreate the CEdit every time when the text
		// format changes.
		if (m_pWndEdit->GetSafeHwnd() != NULL)
			m_pWndEdit->DestroyWindow();

		if (!m_pWndEdit->Create(ES_AUTOHSCROLL | ES_NOHIDESEL | WS_CHILD | WS_BORDER | FMT, CRect(0, 0, 1, 1), this, 0))
			return FALSE;
	}
	else
	{
		if (m_pWndEdit->GetSafeHwnd() == NULL
			&& !m_pWndEdit->Create(ES_AUTOHSCROLL | ES_NOHIDESEL | WS_CHILD | WS_BORDER | FMT, CRect(0, 0, 1, 1), this, 0))
		{
			return FALSE;
		}
	}

	m_pWndEdit->SetFont(GetFont());

	CRect rcEdit;
	ListView_GetSubItemRect(GetSafeHwnd(), m_ptEditting.x, m_ptEditting.y, LVIR_LABEL, &rcEdit);
	if (m_ptEditting.y > 0 && GetImageList() != NULL && GetItemImage(m_ptEditting.x, m_ptEditting.y) >= 0)
		rcEdit.DeflateRect(16, 0, 0, 0);

	// Move the editbox to that grid, obtain text from the grid, display the
	// editbox, and, finally, highlights all text in the editbox and set the
	// windows focus to the editbox.
	m_pWndEdit->MoveWindow(&rcEdit);
	m_pWndEdit->SetWindowText(GetItemText(m_ptEditting.x, m_ptEditting.y));
	m_pWndEdit->ShowWindow(SW_SHOW);
	m_pWndEdit->SetSel(0, -1);
	m_pWndEdit->SetFocus();

	return TRUE;
}

BOOL CReportCtrl::EndEdit(BOOL bCommit)
{
	if (!_IsEditVisible())
		return FALSE;

	LRESULT ret = 0 ;
	CString str;
	m_pWndEdit->GetWindowText(str);
	BOOL bChanged = bCommit && str.Compare(GetItemText(m_ptEditting.x, m_ptEditting.y)) != 0;
	if (bChanged)
	{
		ret = GetParent()->SendMessage(WM_EDIT_PRECOMMITTED, (WPARAM)str.GetBuffer(), (LPARAM)MAKELONG(m_ptEditting.x, m_ptEditting.y)) ;
		if (ret < 0)
		{
			m_pWndEdit->ShowWindow(SW_HIDE);
			m_ptEditting.x = -1;
			m_ptEditting.y = -1;
			return FALSE ;
		}

		// update the list item
		CListCtrl::SetItemText(m_ptEditting.x, m_ptEditting.y, str);
		_UnsetSortedColumn();
		GetParent()->SendMessage(WM_EDIT_COMMITTED, (WPARAM)m_ptEditting.x, (LPARAM)m_ptEditting.y);
	}
	m_pWndEdit->ShowWindow(SW_HIDE);
	m_ptEditting.x = -1;
	m_ptEditting.y = -1;
	return bChanged;
}

BOOL CReportCtrl::SetHeaderImage(int nColumn, int nImageIndex, BOOL bLeftSide)
{
	if (GetHeaderCtrl()->GetImageList() == NULL)
		CListCtrl::GetHeaderCtrl()->SetImageList(GetImageList());
	
	HDITEM hi;
	::memset(&hi, 0, sizeof(HDITEM));
	hi.mask = HDI_FORMAT;
	if (!GetHeaderCtrl()->GetItem(nColumn, &hi))
		return FALSE;
	
	hi.mask |= HDI_IMAGE;		
	hi.fmt |= HDF_IMAGE;

	if (!bLeftSide)
		hi.fmt |= HDF_BITMAP_ON_RIGHT; // draw the image on right side of text

	hi.iImage = nImageIndex;
	return CListCtrl::GetHeaderCtrl()->SetItem(nColumn, &hi);
}

int CReportCtrl::GetSortedColumn() const
{
	return m_nSortCol;
}

BOOL CReportCtrl::IsSortAscending() const
{
	return m_bSortAscending;
}

void CReportCtrl::_UnsetSortedColumn()
{
	m_nSortCol = -1;
	m_bSortAscending = TRUE;
}

DWORD CReportCtrl::_GetHeaderTextFormat(int nColumn) const
{
	if (!HasColumnHeader())
		return ES_LEFT;

	HDITEM hd;
	hd.mask = HDI_FORMAT;
	if (!GetHeaderCtrl()->GetItem(nColumn, &hd))
		return ES_LEFT;

	if (hd.fmt & HDF_CENTER)
	{	
		return ES_CENTER;
	}
	else if (hd.fmt & HDF_RIGHT)
	{
		return ES_RIGHT;
	}
	else
	{
		return ES_LEFT;
	}
}

int CReportCtrl::GetHeaderImage(int nColumn) const
{
	HDITEM hi;
	::memset(&hi, 0, sizeof(HDITEM));
	hi.mask = HDI_IMAGE;
	return !GetHeaderCtrl()->GetItem(nColumn, &hi) ? hi.iImage : -1;
}

CImageList* CReportCtrl::SetHeaderImageList(CImageList *pImageList)
{
	return CListCtrl::GetHeaderCtrl()->SetImageList(pImageList);
}

CImageList* CReportCtrl::SetHeaderImageList(UINT nBitmapID, COLORREF crMask)
{
	m_headerImgList.Create(nBitmapID, 16, 4, crMask);
	return SetHeaderImageList(&m_headerImgList);
}

BOOL CReportCtrl::ExamItemStates(int nItem, DWORD dwStates) const
{
	if (dwStates == RC_ITEM_NONE)
		return FALSE;

	if (dwStates & RC_ITEM_ALL)
		return TRUE;

	return (GetItemStates(nItem) & dwStates) == dwStates;
}

int CReportCtrl::GetItemCount(DWORD dwStates) const
{
	const int ITEMS = CListCtrl::GetItemCount();
	if (dwStates == RC_ITEM_ALL)
		return ITEMS;

	int nCount = 0;
	for (int i = 0; i <ITEMS; i++)
	{
		if (ExamItemStates(i, dwStates))
			nCount++;
	}
	return nCount;
}

int CReportCtrl::GetFirstItem(DWORD dwStates, int nStartAfter) const
{
	const int ITEMS = CListCtrl::GetItemCount();
	nStartAfter = max(-1, nStartAfter);
	for (int i = nStartAfter + 1; i <ITEMS; i++)
	{
		if (ExamItemStates(i, dwStates))
			return i;
	}
	return -1;
}

int CReportCtrl::GetLastItem(DWORD dwStates, int nStartBefore) const
{
	const int ITEMS = CListCtrl::GetItemCount();
	nStartBefore = nStartBefore < 0 ? ITEMS - 1 : min(ITEMS, nStartBefore);
	for (int i = nStartBefore - 1; i >= 0; i--)
	{
		if (ExamItemStates(i, dwStates))
			return i;
	}
	return -1;
}

void CReportCtrl::InvertItems(int nType)
{
	const int ITEMS = CListCtrl::GetItemCount();
	if (nType == RC_INVERT_SELECTION)
	{
		for (int i = 0; i < ITEMS; i++)
			SetItemStates(i, ExamItemStates(i, RC_ITEM_SELECTED) ? RC_ITEM_UNSELECTED : RC_ITEM_SELECTED);
	}
	else if (nType == RC_INVERT_CHECKMARK)
	{
		for (int i = 0; i < ITEMS; i++)
			SetItemStates(i, ExamItemStates(i, RC_ITEM_CHECKED) ? RC_ITEM_UNCHECKED : RC_ITEM_CHECKED);
	}
}

DWORD CReportCtrl::GetItemStates(int nItem) const
{
	DWORD dwStates = 0;

	if (CListCtrl::GetItemState(nItem, LVIS_SELECTED))
		dwStates |= RC_ITEM_SELECTED;
	else
		dwStates |= RC_ITEM_UNSELECTED;

	if (CListCtrl::GetCheck(nItem) > 0)
		dwStates |= RC_ITEM_CHECKED;
	else
		dwStates |= RC_ITEM_UNCHECKED;

	if (CListCtrl::GetItemState(nItem, LVIS_FOCUSED))
		dwStates |= RC_ITEM_FOCUSED;
	else
		dwStates |= RC_ITEM_UNFOCUSED;

	return dwStates;
}

BOOL CReportCtrl::SetItemStates(int nItem, DWORD dwNewStates)
{
	BOOL bResult = _SetItemStatesNoVerify(nItem, dwNewStates);
	if (dwNewStates & RC_ITEM_CHECKED)
		_EnsureSingleCheck(nItem);
	return bResult;
}

int CReportCtrl::SetAllItemStates(DWORD dwOldStates, DWORD dwNewStates)
{
	if (dwNewStates == RC_ITEM_NONE || dwOldStates == RC_ITEM_NONE)
		return 0;

	int nCount = 0;
	const int ITEMS = CListCtrl::GetItemCount();
	for (int i = 0; i < ITEMS; i++)
	{
		if (dwOldStates == RC_ITEM_ALL || ExamItemStates(i, dwOldStates))
		{
			SetItemStates(i, dwNewStates);
			nCount++;
		}
	}

	if (dwNewStates & RC_ITEM_CHECKED)
		_EnsureSingleCheck(-1);

	return nCount;
}

void CReportCtrl::_EnsureSingleCheck(int nItem)
{
	if (m_nChkStyle == RC_CHKBOX_SINGLE)
	{
		const int FIRST = nItem < 0 ? GetFirstItem(RC_ITEM_CHECKED) : nItem;
		if (FIRST >= 0)
		{
			const int ITEMS = CListCtrl::GetItemCount();
			for (int i = FIRST + 1; i < ITEMS; i++)
			{
				if (CListCtrl::GetCheck(i))
					CListCtrl::SetCheck(i, FALSE);
			}
		}		
	}
}

BOOL CReportCtrl::_SetItemStatesNoVerify(int nItem, DWORD dwNewStates)
{
	if (dwNewStates == RC_ITEM_NONE)
		return FALSE;
	
	BOOL bResult = TRUE;
	
	if (dwNewStates & RC_ITEM_SELECTED)
		bResult &= CListCtrl::SetItemState(nItem, LVIS_SELECTED, LVIS_SELECTED);

	if (dwNewStates & RC_ITEM_UNSELECTED)
		bResult &= CListCtrl::SetItemState(nItem, 0, LVIS_SELECTED);

	if (dwNewStates & RC_ITEM_CHECKED)
		bResult &= CListCtrl::SetCheck(nItem, TRUE);

	if (dwNewStates & RC_ITEM_UNCHECKED)
		bResult &= CListCtrl::SetCheck(nItem, FALSE);

	if (dwNewStates & RC_ITEM_FOCUSED)
		bResult &= CListCtrl::SetItemState(nItem, LVIS_FOCUSED, LVIS_FOCUSED);

	if (dwNewStates & RC_ITEM_UNFOCUSED)
		bResult &= CListCtrl::SetItemState(nItem, 0, LVIS_FOCUSED);

	return bResult;
}

BOOL CReportCtrl::SetCheck(int nItem, BOOL bCheck)
{
	const BOOL RES = CListCtrl::SetCheck(nItem, bCheck);
	if (RES && bCheck)
		_EnsureSingleCheck(nItem);
	return RES;
}

CString CReportCtrl::GetHeaderText(int nColumn) const
{
	if (!HasColumnHeader())
		return _T("");

	HDITEM hd;
	TCHAR  szBuffer[256] = _T("");
	hd.mask = HDI_TEXT;
	hd.pszText = szBuffer;
	hd.cchTextMax = 255;
	return GetHeaderCtrl()->GetItem(nColumn, &hd) ? hd.pszText : _T("");
}

BOOL CReportCtrl::SetHeaderText(int nColumn, LPCTSTR lpText)
{
	if (!HasColumnHeader())
		return FALSE;

	LPTSTR psz = NULL;
	if (lpText == NULL)
	{
		psz = new TCHAR[1];
		*psz = _T('\0');
	}
	else
	{
		psz = _tcsdup(lpText);
	}
	HDITEM hd;
	hd.mask = HDI_TEXT;
	hd.pszText = psz;
	hd.cchTextMax = int(_tcslen(psz));
	const BOOL RES = CListCtrl::GetHeaderCtrl()->SetItem(nColumn, &hd);
	delete [] psz;
	return RES;
}

const CHeaderCtrl* CReportCtrl::GetHeaderCtrl() const
{
	// Yes, CListCtrl already provides "GetHeaderCtrl", but not const.	
	// I desperately need a "const" version of "GetHeaderCtrl" because that's the
	// only way to make "GetColumnCount" const, which, in turn, is being called by
	// A LOT of const member functions. So if "GetHeaderCtrl" is not const, there will
	// be almost no const member function at all in this class. Terrible.
	return (const CHeaderCtrl*)(CWnd::FromHandle(ListView_GetHeader(GetSafeHwnd())));
}

void CReportCtrl::_FreeItemMemory(int nItem)
{
	const int COLS = GetColumnCount();
	CWnd * pCtrl = NULL ;
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	if (p != NULL)
	{
		for (int i = 0; i < COLS; i++)
		{
			pCtrl = p->aButtons[i] ;
			if (NULL != pCtrl)
			{
				pCtrl->DestroyWindow() ;
				delete pCtrl ;
				p->aButtons[i] = NULL ;
			}
		}

		CListCtrl::SetItemData(nItem, 0);
		delete p;
	}
}

void CReportCtrl::_AllocItemMemory(int nItem)
{
	ASSERT(_IsValidIndex(nItem));

	const int COLS = GetColumnCount();
	ASSERT(COLS > 0);

	CItemData* pData = new CItemData;
	if(!pData)
		return;

	pData->dwData = CListCtrl::GetItemData(nItem);
	pData->aTextColors.SetSize(COLS);
	pData->aBkColors.SetSize(COLS);
	pData->aButtons.SetSize(COLS);
	for(int i = 0; i < COLS; i++)
	{
		pData->aTextColors[i] = ::GetSysColor(COLOR_WINDOWTEXT);
		pData->aBkColors[i] = ::GetSysColor(COLOR_WINDOW);
		pData->aButtons[i] = NULL;
	}

	CListCtrl::SetItemData(nItem, (DWORD_PTR)pData);
}

void CReportCtrl::_UpdateColumn(int nColumn, BOOL bInsert)
{
	const int ITEMS = GetItemCount();
	for (int i = 0; i < ITEMS; i++)
	{
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(i));
		ASSERT(p != NULL);
		if (bInsert)
			p->InsertColumn(nColumn);
		else
			p->DeleteColumn(nColumn);
	}
}

BOOL CReportCtrl::SetItemData(int nItem, DWORD_PTR dwData)
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	if (p == NULL)
		return FALSE;
	p->dwData = dwData;
	return CListCtrl::SetItemData(nItem, (DWORD_PTR)p);
}

DWORD_PTR CReportCtrl::GetItemData(int nItem) const
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	return p == NULL ? 0 : p->dwData;
}

BOOL CReportCtrl::SetItemReserveData(int nItem, DWORD dwData1, DWORD dwData2)
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	if (p == NULL)
		return FALSE;

	p->dwReserve1 = dwData1;
	p->dwReserve2 = dwData2;

	return CListCtrl::SetItemData(nItem, (DWORD_PTR)p);
}

BOOL CReportCtrl::GetItemReserveData(int nItem, DWORD * pdwData1, DWORD * pdwData2)
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	if (NULL == p)
		return FALSE;

	if (pdwData1)
		* pdwData1 = p->dwReserve1;

	if (pdwData2)
		* pdwData2 = p->dwReserve2;

	return TRUE ;
}

BOOL CReportCtrl::SetItemReserveData2(int nItem, DWORD dwData3, DWORD dwData4)
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	if (p == NULL)
		return FALSE ;
	p->dwReserve3 = dwData3 ;
	p->dwReserve4 = dwData4 ;
	return CListCtrl::SetItemData(nItem, (DWORD_PTR)p);
}

BOOL CReportCtrl::GetItemReserveData2(int nItem, DWORD * pdwData3, DWORD * pdwData4)
{
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem)) ;
	if (NULL == p)
		return FALSE ;

	if (pdwData3)
		* pdwData3 = p->dwReserve3 ;
	if (pdwData4)
		* pdwData4 = p->dwReserve4 ;

	return TRUE ;
}

BOOL CReportCtrl::GetItem(LVITEM *pItem) const
{
	const BOOL RES = CListCtrl::GetItem(pItem);
	if (RES && (pItem->mask & LVIF_PARAM) != 0)
	{
		CItemData* p = (CItemData*)(pItem->lParam);
		if (p != NULL)
			pItem->lParam = p->dwData;
	}
	return RES;
}

BOOL CReportCtrl::SetItem(const LVITEM *pItem)
{
	if (pItem == NULL)
		return FALSE;
	
	LVITEM li;
	memcpy(&li, pItem, sizeof(LVITEM));
	if ((li.mask & LVIF_PARAM) != 0)
	{
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(li.iItem));
		if (p != NULL)
		{
			p->dwData = li.lParam;
			li.lParam = (LPARAM)p;
		}		
	}
	return CListCtrl::SetItem(&li);
}

BOOL CReportCtrl::SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem, int nImage, UINT nState, UINT nStateMask, LPARAM lParam)
{
	if ((nMask & LVIF_PARAM) != 0)
	{
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
		if (p != NULL)
		{
			p->dwData = lParam;
			lParam = (LPARAM)p;
		}		
	}
	return CListCtrl::SetItem(nItem, nSubItem, nMask, lpszItem, nImage, nState, nStateMask, lParam);
}

void CReportCtrl::SetItemTextColor(int nItem, int nSubItem, COLORREF color, BOOL bRedraw)
{
	if (color == COLOR_INVALID)
		color = ::GetSysColor(COLOR_WINDOWTEXT);
	const int ROWS = GetItemCount();
	const int COLS = GetColumnCount();
	BOOL bRowValid = nItem >= 0 && nItem < ROWS;
	BOOL bColValid = nSubItem >= 0 && nSubItem < COLS;

	if (bRowValid && bColValid)
	{
		// apply to individual grid
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
		ASSERT(p != NULL);
		p->aTextColors[nSubItem] = color;
	}
	else if (bRowValid && !bColValid)
	{
		// apply to whole row for the existing item
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
		ASSERT(p != NULL);
		for (int i = 0; i < COLS; i++)
			p->aTextColors[i] = color;
	}
	else if (!bRowValid && bColValid)
	{
		// apply to whole column for all existing items
		for (int i = 0; i < ROWS; i++)
		{
			CItemData* p = (CItemData*)(CListCtrl::GetItemData(i));
			ASSERT(p != NULL);
			p->aTextColors[nSubItem] = color;
		}
	}
	else
	{
		// apply to whole table for all existing items
		for (int i = 0; i < ROWS; i++)
		{
			CItemData* p = (CItemData*)(CListCtrl::GetItemData(i));
			ASSERT(p != NULL);
			for (int j = 0; j < COLS; j++)
				p->aTextColors[j] = color;
		}
	}

	if (bRedraw)
		RedrawWindow();
}

void CReportCtrl::SetItemBkColor(int nItem, int nSubItem, COLORREF color, BOOL bRedraw)
{
	if (color == COLOR_INVALID)
		color = ::GetSysColor(COLOR_WINDOW);
	const int ROWS = GetItemCount();
	const int COLS = GetColumnCount();
	BOOL bRowValid = nItem >= 0 && nItem < ROWS;
	BOOL bColValid = nSubItem >= 0 && nSubItem < COLS;

	if (bRowValid && bColValid)
	{
		// apply to individual grid
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
		ASSERT(p != NULL);
		p->aBkColors[nSubItem] = color;
	}
	else if (bRowValid && !bColValid)
	{
		// apply to whole row for the existing item
		CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
		ASSERT(p != NULL);
		for (int i = 0; i < COLS; i++)
			p->aBkColors[i] = color;
	}
	else if (!bRowValid && bColValid)
	{
		// apply to whole column for all existing items
		for (int i = 0; i < ROWS; i++)
		{
			CItemData* p = (CItemData*)(CListCtrl::GetItemData(i));
			ASSERT(p != NULL);
			p->aBkColors[nSubItem] = color;
		}
	}
	else
	{
		// apply to whole table for all existing items
		for (int i = 0; i < ROWS; i++)
		{
			CItemData* p = (CItemData*)(CListCtrl::GetItemData(i));
			ASSERT(p != NULL);
			for (int j = 0; j < COLS; j++)
				p->aBkColors[j] = color;
		}
	}

	if (bRedraw)
	{
//		RedrawWindow();
		RedrawItems(nItem, nItem) ;
	}
		
}

COLORREF CReportCtrl::GetItemTextColor(int nItem, int nSubItem) const
{
	if (!_IsValidIndex(nItem) || nSubItem < 0 || nSubItem >= GetColumnCount())
		return COLOR_INVALID;
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	ASSERT(p != NULL);
	return p->aTextColors[nSubItem];
}

COLORREF CReportCtrl::GetItemBkColor(int nItem, int nSubItem) const
{
	if (!_IsValidIndex(nItem) || nSubItem < 0 || nSubItem >= GetColumnCount())
		return COLOR_INVALID;
	CItemData* p = (CItemData*)(CListCtrl::GetItemData(nItem));
	ASSERT(p != NULL);
	return p->aBkColors[nSubItem];
}

BOOL CReportCtrl::_PartialSort(int nStart, int nEnd)
{
	if (nStart >= nEnd || !_IsValidIndex(nStart) || !_IsValidIndex(nEnd))
		return FALSE;

	const int COUNT = nEnd - nStart + 1;
	int i = 0;
	int* aIndices = new int[COUNT];
	for (i = 0; i < COUNT; i++)
		aIndices[i] = nStart + i;
	
	_QuickSortRecursive(aIndices, 0, COUNT - 1); 

	// rearrange items
	const int COLS = GetColumnCount();
	ROWINFO* aRows = new ROWINFO[COUNT];
	for (i = 0; i < COUNT; i++)
	{
		int n = aIndices[i];
		aRows[i].dwStates = GetItemStates(aIndices[i]);
		aRows[i].dwData = CListCtrl::GetItemData(aIndices[i]);
		aRows[i].aImages.SetSize(COLS);
		aRows[i].aTexts.SetSize(COLS);
		for (int j = 0; j < COLS; j++)
		{
			aRows[i].aImages[j] = GetItemImage(aIndices[i], j);
			aRows[i].aTexts[j] = GetItemText(aIndices[i], j);
		}
	}

	for (i = 0; i < COUNT; i++)
	{
		SetItemStates(nStart + i, aRows[i].dwStates);
		CListCtrl::SetItemData(nStart + i, aRows[i].dwData);
		for (int j = 0; j < COLS; j++)
		{
			SetItemImage(nStart + i, j, aRows[i].aImages[j]);			
			CListCtrl::SetItemText(nStart + i, j, aRows[i].aTexts[j]);
		}
	}
	delete [] aRows;
	delete [] aIndices;
	return TRUE;
}

int CReportCtrl::_CompareItems(int nItem1, int nItem2)
{
	const CString s1 = GetItemText(nItem1, m_nSortCol);
	const CString s2 = GetItemText(nItem2, m_nSortCol);

	DWORD dw1, dw2;
	if(_ITEM_COMPARE_FUNCS::_IsHexNumber(s1, dw1) && _ITEM_COMPARE_FUNCS::_IsHexNumber(s2, dw2))
		return _ITEM_COMPARE_FUNCS::_HexNumberCompare(dw1, dw2);

	double f1, f2;
	if(_ITEM_COMPARE_FUNCS::_IsDecNumber(s1, f1) && _ITEM_COMPARE_FUNCS::_IsDecNumber(s2, f2))
		return _ITEM_COMPARE_FUNCS::_DecNumberCompare(f1, f2);

	COleDateTime date1, date2;
	if(_ITEM_COMPARE_FUNCS::_IsDate(s1, date1) && _ITEM_COMPARE_FUNCS::_IsDate(s2, date2))
		return _ITEM_COMPARE_FUNCS::_DateCompare(date1, date2);
	
	// plain text.
	return s1.Compare(s2);
}

int CReportCtrl::_FindSeparator(int nStartAfter, int nColumn) const
{
	if (m_pszSeparator == NULL)
		return -1;

	const int ITEMS = GetItemCount();
	for (int i = nStartAfter + 1; i < ITEMS; i++)
	{
		if (GetItemText(i, nColumn) == m_pszSeparator)
			return i;
	}
	return -1;
}

void CReportCtrl::_QuickSortRecursive(int* pArr, int nLow, int nHigh)
{
	int i = nHigh, j = nLow;
	int n = pArr[(nLow + nHigh) / 2];
	do
	{
		if (m_bSortAscending)
		{
			while (_CompareItems(pArr[j], n) < 0)
				j++;

			while (_CompareItems(pArr[i], n) > 0)
				i--;
		}
		else
		{
			while (_CompareItems(pArr[j], n) > 0)
				j++;

			while (_CompareItems(pArr[i], n) < 0)
				i--;
		}

		if ( i >= j )
		{
			if ( i != j )
			{
				int nTemp = pArr[i];
				pArr[i] = pArr[j];
				pArr[j] = nTemp;
			}

			i--;
			j++;
		}
		
	} while (j <= i);

	if (nLow < i)
		_QuickSortRecursive(pArr,nLow,i);

	if (j < nHigh)
		_QuickSortRecursive(pArr,j,nHigh);
}

BOOL CReportCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	{
		CListCtrl::OnMouseWheel(nFlags, zDelta, pt) ;
		InvalidateProgressCtrls() ;
	}
	return TRUE ;

	if (m_bAllowEdit)
	{
		EndEdit(TRUE) ;
	}
	else 
	{
		BOOL bEdit = FALSE ;
		for (int i=0;i <= m_arrayAllowEditPart.GetUpperBound(); i++)
		{
			if (m_arrayAllowEditPart.GetAt(i))
			{
				bEdit = TRUE ;
				break ;
			}
		} 

		if (bEdit)
			EndEdit(TRUE) ;
	}


//	
	if (0)
	{
		InvalidateProgressCtrls();
	}
	return 0 ;
	//return TRUE ;
}

void CReportCtrl::MeasureItem( LPMEASUREITEMSTRUCT lpMeasureItemStruct )
{

}

/*
void CReportCtrl::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	lpMeasureItemStruct->itemHeight = 50 ; 


	CListCtrl::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}
*/

void CReportCtrl::OnLvnOdcachehint(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCACHEHINT pCacheHint = reinterpret_cast<LPNMLVCACHEHINT>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CReportCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
//	OnMouseWheel(0, 0, 0) ;

	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
	InvalidateProgressCtrls();
}

void CReportCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
//	OnMouseWheel(0, 0, 0) ;

	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
	InvalidateProgressCtrls();
}

void CReportCtrl::OnKillFocus(CWnd* pNewWnd)
{
	CListCtrl::OnKillFocus(pNewWnd);
}

BOOL CReportCtrl::CommitEdit() 
{
	return EndEdit(TRUE) ;
}

void CReportCtrl::OnHdnBegintrack(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	/////////拖动分隔的消息/////////
	EndEdit(FALSE);
	
	*pResult = 0;
}

BOOL CReportCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: 在此添加专用代码和/或调用基类
	HD_NOTIFY *pHDN = (HD_NOTIFY*)lParam;
	
	/*
	* Disable all resizing (for test)
	*/
#if 1
	if((pHDN->hdr.code == HDN_BEGINTRACKW || pHDN->hdr.code == HDN_BEGINTRACKA))    // Prevent only first (col# 0) from resizing
	{
		*pResult = TRUE;                 // disable tracking 
		return TRUE;                     // Processed message 
	}
#else
	if((pHDN->hdr.code == HDN_BEGINTRACKW || pHDN->hdr.code == HDN_BEGINTRACKA)
		&& (0 == pHDN->iItem || 1 == pHDN->iItem))    // Prevent only first (col# 0) from resizing
	{
		*pResult = TRUE;                 // disable tracking 
		return TRUE;                     // Processed message 
	}
#endif 
	
	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

void CReportCtrl::InvalidateProgressCtrls()
{
	int nFirst = GetTopIndex();
	int nLast = nFirst + GetCountPerPage();
	int nColCount = GetColumnCount() ;
	
	int i,j ;
	//Hide the other items.
	int nCount = this->GetItemCount();
	CWnd * pCtrl;
	CItemData * pData ;
	for(i = 0; i < nFirst; i++)
	{
		pData = (CItemData*)CListCtrl::GetItemData(i);
		if (NULL != pData)
		{
			for (j = 0; j < nColCount; j ++)
			{
				pCtrl = pData->aButtons[j] ;
				if (NULL != pCtrl)
				pCtrl->ShowWindow(SW_HIDE);		
			}
		}
	}
	for(i = nLast; i < nCount; i++)
	{
		pData = (CItemData*)CListCtrl::GetItemData(i);
		if (NULL != pData)
		{
			for (j = 0; j < nColCount; j ++)
			{
				pCtrl = pData->aButtons[j] ;
				if (NULL != pCtrl)
					pCtrl->ShowWindow(SW_HIDE);		
			}
		}
	}

	//Invalidate
	CRect rc(0,0,0,0);
	CRect rcSubItem;
	for(; nFirst < nLast; nFirst++)
	{
		GetSubItemRect(nFirst, 1, LVIR_BOUNDS, rcSubItem);
		VERIFY( rc.UnionRect(rc, rcSubItem) );
	}

	//InvalidateRect(rc);
	InvalidateRect(NULL) ;

	//  Using this method, the flicker seems better that above. But I am not sure why, and think it's non-effective.
	//	for(; nFirst < nLast; nFirst++)
	//	{
	//		GetSubItemRect(nFirst, 1, LVIR_BOUNDS, rcSubItem);
	//		InvalidateRect(rcSubItem);
	//	}	
}

void CReportCtrl::InitFont(BOOL bIsLink, CFont *pFont) {
	//Initializes font according to link properties

	if (pFont == NULL) return;

	//Creates font
	if (!(HFONT)(*pFont)) {
		// first time init: create font
		LOGFONT lf;
		GetFont()->GetObject(sizeof(lf), &lf);
		lf.lfUnderline = bIsLink ;
		pFont->CreateFontIndirect(&lf);
	}
}

BOOL CReportCtrl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (BN_CLICKED == HIWORD(wParam))
	{
		CString strTxt ;
		WORD id = LOWORD(wParam) ;

		HWND hWnd = (HWND)lParam ;
	
		int nCount = CListCtrl::GetItemCount();
		int nColCount = GetColumnCount() ;
		for (int i = 0; i < nCount; i ++)
		{
			CItemData* pData = (CItemData*)CListCtrl::GetItemData(i) ;
			if (NULL == pData)
				continue ;

			for (int k = 0; k < nColCount; k ++)
			{
				CItemButton * pCtrl = pData->aButtons[k] ;
				if (NULL == pCtrl)
					continue ;
				if (pCtrl->m_hWnd == hWnd)
				{
					HWND hNotifyWnd = m_hItemBnNotifyWnd ;
					if (NULL == hNotifyWnd)
						hNotifyWnd = GetParent()->m_hWnd ;
						
					::SendMessage(hNotifyWnd, WM_LC_BN_CLICK, (WPARAM)MAKEWPARAM(k, i), (LPARAM)m_hWnd);

					//strTxt.Format(TEXT("bn click, Item:%d, nSubItem:%d"), i, k) ;
					//MessageBox(strTxt, TEXT(""), MB_OK) ;
					return TRUE ;
				}
			}
		}

		/*
		CItemButton * pCtrl = (CItemButton *)FromHandle(hWnd) ;
		if (pCtrl)
		{
			int nItem, nSubItem ;
			if (pCtrl->GetItem(nItem, nSubItem))
			{
				strTxt.Format(TEXT("bn click, Item:%d, nSubItem:%d"), nItem, nSubItem) ;
				MessageBox(strTxt, TEXT(""), MB_OK) ;
			}
		}

		*/
		return TRUE ;
	}

	return CListCtrl::OnCommand(wParam, lParam);
}

void CReportCtrl::SetItemBnNotifyWnd(HWND hNotifyWnd)
{
	m_hItemBnNotifyWnd = hNotifyWnd ;
}
