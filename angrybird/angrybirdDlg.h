
// angrybirdDlg.h : 標頭檔
//

#pragma once


// CangrybirdDlg 對話方塊
class CangrybirdDlg : public CDialogEx
{
// 建構
public:
	CangrybirdDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_ANGRYBIRD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	afx_msg void OnBnClickedRadio1();
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
//	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};
