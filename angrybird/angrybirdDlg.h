
// angrybirdDlg.h : ���Y��
//

#pragma once


// CangrybirdDlg ��ܤ��
class CangrybirdDlg : public CDialogEx
{
// �غc
public:
	CangrybirdDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_ANGRYBIRD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
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
