/******************************
4103056035 �P�� �Ĥ����@�~12/21
******************************/
// CalculatorWPDlg.h : ���Y��
//

#pragma once


// CCalculatorWPDlg ��ܤ��
class CCalculatorWPDlg : public CDialog
{
// �غc
public:
	CCalculatorWPDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_CALCULATORWP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;
	bool inputnow = false;
	bool dot = false;
	int brackt = 0;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickednine();
	afx_msg void OnBnClickedeight();
	afx_msg void OnBnClickedseven();
	afx_msg void OnBnClickedsix();
	afx_msg void OnBnClickedfive();
	afx_msg void OnBnClickedfour();
	afx_msg void OnBnClickedthree();
	afx_msg void OnBnClickedtwo();
	afx_msg void OnBnClickedone();
	afx_msg void OnBnClickedzero();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickeddot();
	afx_msg void OnBnClickeddel();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedminus();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedmul();
	afx_msg void OnBnClickedcalc();
	afx_msg void OnBnClickedpower();
	afx_msg void OnBnClickede();
	afx_msg void OnBnClickedfact();
	afx_msg void OnBnClickedsqua();
	afx_msg void OnBnClickedparl();
	afx_msg void OnBnClickedparr();
	afx_msg void OnBnClickedlog();
	afx_msg void OnLbnSelchangeList1();
};
