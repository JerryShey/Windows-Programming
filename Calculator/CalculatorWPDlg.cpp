/******************************
4103056035 周彤 第六次作業12/21
******************************/
// CalculatorWPDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "CalculatorWP.h"
#include "CalculatorWPDlg.h"
#include "afxdialogex.h"
//#include "calculate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CCalculatorWPDlg 對話方塊



CCalculatorWPDlg::CCalculatorWPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorWPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorWPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorWPDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_seven, &CCalculatorWPDlg::OnBnClickedseven)
	ON_BN_CLICKED(btn_nine, &CCalculatorWPDlg::OnBnClickednine)
	ON_BN_CLICKED(btn_eight, &CCalculatorWPDlg::OnBnClickedeight)
	ON_BN_CLICKED(btn_six, &CCalculatorWPDlg::OnBnClickedsix)
	ON_BN_CLICKED(btn_five, &CCalculatorWPDlg::OnBnClickedfive)
	ON_BN_CLICKED(btn_four, &CCalculatorWPDlg::OnBnClickedfour)
	ON_BN_CLICKED(btn_three, &CCalculatorWPDlg::OnBnClickedthree)
	ON_BN_CLICKED(btn_two, &CCalculatorWPDlg::OnBnClickedtwo)
	ON_BN_CLICKED(btn_one, &CCalculatorWPDlg::OnBnClickedone)
	ON_BN_CLICKED(btn_zero, &CCalculatorWPDlg::OnBnClickedzero)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CCalculatorWPDlg::OnDeltaposSpin1)
	ON_BN_CLICKED(btn_dot, &CCalculatorWPDlg::OnBnClickeddot)
	ON_BN_CLICKED(btn_del, &CCalculatorWPDlg::OnBnClickeddel)
	ON_BN_CLICKED(clear, &CCalculatorWPDlg::OnBnClickedclear)
	ON_BN_CLICKED(btn_plus, &CCalculatorWPDlg::OnBnClickedplus)
	ON_BN_CLICKED(btn_minus, &CCalculatorWPDlg::OnBnClickedminus)
	ON_BN_CLICKED(btn_div, &CCalculatorWPDlg::OnBnClickeddiv)
	ON_BN_CLICKED(btn_mul, &CCalculatorWPDlg::OnBnClickedmul)
	ON_BN_CLICKED(btn_calc, &CCalculatorWPDlg::OnBnClickedcalc)
	ON_BN_CLICKED(btn_power, &CCalculatorWPDlg::OnBnClickedpower)
	ON_BN_CLICKED(btn_e, &CCalculatorWPDlg::OnBnClickede)
	ON_BN_CLICKED(btn_fact, &CCalculatorWPDlg::OnBnClickedfact)
	ON_BN_CLICKED(btn_squa, &CCalculatorWPDlg::OnBnClickedsqua)
	ON_BN_CLICKED(btn_parL, &CCalculatorWPDlg::OnBnClickedparl)
	ON_BN_CLICKED(btn_parR, &CCalculatorWPDlg::OnBnClickedparr)
	ON_BN_CLICKED(btn_log, &CCalculatorWPDlg::OnBnClickedlog)
	ON_LBN_SELCHANGE(IDC_LIST1, &CCalculatorWPDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()

// CCalculatorWPDlg 訊息處理常式

BOOL CCalculatorWPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CCalculatorWPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CCalculatorWPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CCalculatorWPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorWPDlg::OnBnClickednine()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow||brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "9";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}

void CCalculatorWPDlg::OnBnClickedeight()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "8";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}

void CCalculatorWPDlg::OnBnClickedseven()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "7";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}

void CCalculatorWPDlg::OnBnClickedsix()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "6";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedfive()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "5";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedfour()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "4";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedthree()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "3";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedtwo()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "2";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedone()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	str += "1";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}


void CCalculatorWPDlg::OnBnClickedzero()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str = CString("");
	UpdateData(true);
	if (inputnow || brackt)
		GetDlgItem(edit_calc)->GetWindowText(str);
	if (str.GetAt(str.GetLength()-1) == L'0'){
		return;
	}
	str += "0";
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	inputnow = true;
}



void CCalculatorWPDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO:  在此加入控制項告知處理常式程式碼
	*pResult = 0;
}


void CCalculatorWPDlg::OnBnClickeddot()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str;
	if (dot){
		return;
	}
	UpdateData(true);
	GetDlgItem(edit_calc)->GetWindowText(str);
	if (str == ""){
		str += "0.";
	}
	else
		str += ".";
	dot = true;
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
	return;

}


void CCalculatorWPDlg::OnBnClickeddel()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str;
	UpdateData(true);
	GetDlgItem(edit_calc)->GetWindowText(str);
	if (str.IsEmpty())
		return;
	else{
		if (str.GetAt(str.GetLength() - 1) == '.'){
			dot = false;
		}
		str.Delete(str.GetLength() - 1);
	}
	GetDlgItem(edit_calc)->SetWindowText(str);
	UpdateData(false);
}

/*
CString str;
UpdateData(true);
GetDlgItem(edit_calc)->GetWindowText(str);

GetDlgItem(edit_calc)->SetWindowText(str);
UpdateData(false);
*/


void CCalculatorWPDlg::OnBnClickedclear()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString str("");
	GetDlgItem(edit_calc)->SetWindowText(str);
	GetDlgItem(edit_str)->SetWindowText(str);
	UpdateData(false);
}


void CCalculatorWPDlg::OnBnClickedplus()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			calc += "+";
			GetDlgItem(edit_calc)->SetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty()&&calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		str += "+";
		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}
	else{
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			if ((str.GetAt(str.GetLength() - 1)) == 40){
				str += "+";
				brackt--;
			}
			else if (!checkisdigit(calc.GetAt(calc.GetLength() - 1))){
				calc = str.Left(calc.GetLength() - 1);
				calc += "+";
			}
			else
				calc += "+";
			GetDlgItem(edit_calc)->GetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_str)->GetWindowText(str);
		
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str += "+";
		}
		else
			str += "+";
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedminus()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			calc += "-";
			GetDlgItem(edit_calc)->SetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		str += "-";

		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}
	else{
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			if ((str.GetAt(str.GetLength() - 1)) == 40){
				calc = str.Left(calc.GetLength() - 1);
				calc += "-";
				brackt--;
			}
			else if (!checkisdigit(calc.GetAt(calc.GetLength() - 1))){
				calc = str.Left(calc.GetLength() - 1);
				calc += "-";
			}
			else
				calc += "-";
			GetDlgItem(edit_calc)->GetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_str)->GetWindowText(str);
		
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str += "-";
		}
		else
			str += "-";
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickeddiv()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			calc += "/";
			GetDlgItem(edit_calc)->SetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		str += "/";
		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);

	}
	else{
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			if (!checkisdigit(calc.GetAt(calc.GetLength() - 1))){
				calc = str.Left(calc.GetLength() - 1);
				calc += "/";
			}
			else
				calc += "/";
			GetDlgItem(edit_calc)->GetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_str)->GetWindowText(str);
		
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str += "/";
		}
		else
			str += "/";
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedmul()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		if (brackt){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			calc += "*";
			GetDlgItem(edit_calc)->SetWindowText(calc);
			UpdateData(false);
			Sleep(10);
			return;
		}
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		str += "*";
		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if ((str.GetAt(str.GetLength() - 1)) == 40){
			str = str.Left(str.GetLength() - 1);
			str += "*";
			brackt--;
		}
		else if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str += "*";
		}
		else
			str += "*";
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedcalc()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		while (brackt!=0){
			str += ")";
			brackt--;
		}
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		
		if (!checkisdigit(str.GetAt(str.GetLength() - 1)))
			str = str.Left(str.GetLength() - 1);
		while (brackt != 0){
			str += ")";
			brackt--;
		}
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
	}
	calc.Format(_T("%g"), *answer);
	GetDlgItem(edit_str)->SetWindowText(str);
	GetDlgItem(edit_calc)->SetWindowText(calc);
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedpower()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		str += "^";
		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str += "^";
		}
		else
			str += "^";
		GetDlgItem(edit_str)->SetWindowText(str);
	}

	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickede()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		calc = "e";
		str += "e";
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if (checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = "";
			calc = "e";
		}

		str += "e";
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		calc.Format(_T("%g"), *answer);
		
	}
	GetDlgItem(edit_str)->SetWindowText(str);
	GetDlgItem(edit_calc)->SetWindowText(calc);
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedfact()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		str += "!";
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if (checkisdigit(str.GetAt(str.GetLength() - 1))){
			GetDlgItem(edit_calc)->GetWindowText(calc);
			str = "";
			str += calc;
			str += "!";
		}
		else
			str += "!";
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	if (brackt){
		str += ")!";
		brackt--;
	}
	inputnow = false;
	LPTSTR temp = new TCHAR[str.GetLength() + 1];
	char* strAry = new char[str.GetLength() + 1];
	_tcscpy_s(temp, str.GetLength() + 1, str);
	wcstombs_s(&i, strAry, 16, temp, 16);

	eatspaces(strAry);
	answer = expr(strAry);

	calc.Format(_T("%g"), *answer);
	GetDlgItem(edit_str)->SetWindowText(str);
	GetDlgItem(edit_calc)->SetWindowText(calc);
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedsqua()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		if (str.IsEmpty() && calc.IsEmpty())
			return;

		str = "sqrt(";
		str += calc;
		str += ")";
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str.Insert(0, L"sqrt(");
			str += ")";
		}
		else{
			str.Insert(0, L"sqrt(");
			str += ")";
		}
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	LPTSTR temp = new TCHAR[str.GetLength() + 1];
	char* strAry = new char[str.GetLength() + 1];
	_tcscpy_s(temp, str.GetLength() + 1, str);
	wcstombs_s(&i, strAry, 16, temp, 16);

	eatspaces(strAry);
	answer = expr(strAry);

	calc.Format(_T("%g"), *answer);
	GetDlgItem(edit_str)->SetWindowText(str);
	GetDlgItem(edit_calc)->SetWindowText(calc);
	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedparl()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		GetDlgItem(edit_str)->GetWindowText(str);
		if (str.IsEmpty() && calc.IsEmpty())
			return;
		str += calc;
		LPTSTR temp = new TCHAR[str.GetLength() + 1];
		char* strAry = new char[str.GetLength() + 1];
		_tcscpy_s(temp, str.GetLength() + 1, str);
		wcstombs_s(&i, strAry, 16, temp, 16);

		eatspaces(strAry);
		answer = expr(strAry);
		calc.Format(_T("%g"), *answer);
		GetDlgItem(edit_str)->SetWindowText(str);
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}
	else{
		GetDlgItem(edit_calc)->GetWindowText(calc);
		if (calc.IsEmpty()){
			calc += "(";
			brackt++;
		}
		else if (!checkisdigit(calc.GetAt(calc.GetLength() - 1))){
			calc += "(";
			brackt++;
		}
		GetDlgItem(edit_calc)->SetWindowText(calc);
	}

	UpdateData(false);
}


void CCalculatorWPDlg::OnBnClickedparr()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		if (brackt){
			calc += ")";
			brackt--;
		}
		else{
			GetDlgItem(edit_calc)->GetWindowText(calc);
			GetDlgItem(edit_str)->GetWindowText(str);
			if (str.IsEmpty() && calc.IsEmpty())
				return;
			str += calc;
			LPTSTR temp = new TCHAR[str.GetLength() + 1];
			char* strAry = new char[str.GetLength() + 1];
			_tcscpy_s(temp, str.GetLength() + 1, str);
			wcstombs_s(&i, strAry, 16, temp, 16);

			eatspaces(strAry);
			answer = expr(strAry);
			calc.Format(_T("%g"), *answer);
			GetDlgItem(edit_str)->SetWindowText(str);
			GetDlgItem(edit_calc)->SetWindowText(calc);
		}
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(calc);
		if (brackt){
			if (str.GetAt(str.GetLength() - 1) == 40){
				//do nothing
			}
			else if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
				str = str.Left(str.GetLength() - 1);
				str += ")";
				brackt--;
			}
		}
		GetDlgItem(edit_str)->SetWindowText(calc);
	}

	UpdateData(false);
	Sleep(10);
}


void CCalculatorWPDlg::OnBnClickedlog()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CString calc, str;
	size_t i;
	double* answer = new double(0.0);

	UpdateData(true);
	if (inputnow){
		inputnow = false;
		GetDlgItem(edit_calc)->GetWindowText(calc);
		if (str.IsEmpty() && calc.IsEmpty())
			return;

		str = "log(";
		str += calc;
		str += ")";
	}
	else{
		GetDlgItem(edit_str)->GetWindowText(str);
		if (!checkisdigit(str.GetAt(str.GetLength() - 1))){
			str = str.Left(str.GetLength() - 1);
			str.Insert(0, L"log(");
			str += ")";
		}
		else{
			str.Insert(0, L"log(");
			str += ")";
		}
		GetDlgItem(edit_str)->SetWindowText(str);
	}
	LPTSTR temp = new TCHAR[str.GetLength() + 1];
	char* strAry = new char[str.GetLength() + 1];
	_tcscpy_s(temp, str.GetLength() + 1, str);
	wcstombs_s(&i, strAry, 16, temp, 16);

	eatspaces(strAry);
	answer = expr(strAry);

	calc.Format(_T("%g"), *answer);
	GetDlgItem(edit_str)->SetWindowText(str);
	GetDlgItem(edit_calc)->SetWindowText(calc);
	UpdateData(false);
	Sleep(10);
}


