
// angrybirdDlg.cpp : ��@��
//

#include "stdafx.h"
#include "angrybird.h"
#include "angrybirdDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CangrybirdDlg ��ܤ��


string winSet[16]; //used to write config.lua
int winMode=-1;
int setMode=-1;
CComboBox* setList;
int setWidth , setHeight;

CangrybirdDlg::CangrybirdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CangrybirdDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CangrybirdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CangrybirdDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CangrybirdDlg::OnBnClickedOk)
//	ON_BN_CLICKED(IDC_RADIO1, &CangrybirdDlg::OnBnClickedRadio1)
//	ON_EN_CHANGE(IDC_EDIT1, &CangrybirdDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_RADIO1, &CangrybirdDlg::OnBnClickedRadio1)
ON_BN_CLICKED(IDC_RADIO2, &CangrybirdDlg::OnBnClickedRadio2)
//ON_CBN_SELCHANGE(IDC_COMBO1, &CangrybirdDlg::OnCbnSelchangeCombo1)
ON_BN_CLICKED(IDC_RADIO3, &CangrybirdDlg::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_RADIO4, &CangrybirdDlg::OnBnClickedRadio4)
//ON_EN_CHANGE(IDC_EDIT1, &CangrybirdDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON1, &CangrybirdDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CangrybirdDlg �T���B�z�`��

BOOL CangrybirdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	winSet[0]="product = \"Angry Birds\"";
	winSet[1]="publisher = \"Rovio\"";
	winSet[2]="name = \"Angry Birds\"";
	winSet[3]="width = 1024";
	winSet[4]="height = 600";
	winSet[5]="orientation = 0";
	winSet[6]="datapath = \"data\"";
	winSet[7]="imagePath = \"images/pc_build\"";
	winSet[8]="fontPath = \"fonts/pc_build\"";
	winSet[9]="audioPath = \"audio\"";
	winSet[10]="localizationPath = \"localization\"";
	winSet[11]="levelPath = \"levels\"";
	winSet[12]="scriptPath = \"scripts\"";
	winSet[13]="deviceModel = \"windows\"";
	winSet[14]="fullscreen = false";
	winSet[15]="showCursor = false";
	setList = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	// TODO: �b���[�J�B�~����l�]�w

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CangrybirdDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CangrybirdDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CangrybirdDlg::OnBnClickedOk()
{
	bool changeConfig = false;
	if(winMode==0){ //write fullscreen set to config
		winSet[14]="fullscreen = true";
		changeConfig = true;
	}else if(winMode==1){//write window set to config
		winSet[14]="fullscreen = false";
		if(setMode==0){
			int selectSet=setList->GetCurSel();
			if(selectSet!=-1){
				switch(selectSet){
					case 0: winSet[3]="width = 1366"; winSet[4]="height = 768";
						break;
					case 1: winSet[3]="width = 1280"; winSet[4]="height = 768";
						break;
					case 2: winSet[3]="width = 1024"; winSet[4]="height = 768";
						break;
					case 3: winSet[3]="width = 1024"; winSet[4]="height = 600";
						break;
					case 4: winSet[3]="width = 800"; winSet[4]="height = 600";
						break;
					case 5: winSet[3]="width = 640"; winSet[4]="height = 480";
						break;
					default: winSet[3]="width = 1024"; winSet[4]="height = 600";
				}
				changeConfig = true;
			}
		}else if(setMode==1){
			setWidth=GetDlgItemInt(IDC_EDIT1);
			setHeight=GetDlgItemInt(IDC_EDIT2);
			if(setWidth>0 && setHeight>0){
				string temp;
				stringstream w(temp);
				w << setWidth;
				winSet[3]="width = "+w.str();
				stringstream h(temp);
				h << setHeight;
				winSet[4]="height = "+h.str();
				changeConfig = true;
			}
		}
	}
	if(changeConfig==true) {//file io
		fstream fWrite("config.lua",ios::out);
		for(int i=0;i<16;i++){
			fWrite << winSet[i] << endl;
		}
		fWrite.close();
	}
	system("start AngryBirds.bin");
	// TODO: �b���[�J����i���B�z�`���{���X
	CDialogEx::OnOK();
}

void CangrybirdDlg::OnBnClickedRadio1()
{
	winMode=0;
	// TODO: �b���[�J����i���B�z�`���{���X
}


void CangrybirdDlg::OnBnClickedRadio2()
{
	winMode=1;
	// TODO: �b���[�J����i���B�z�`���{���X
}


void CangrybirdDlg::OnBnClickedRadio3()
{
	setMode=0;
	// TODO: �b���[�J����i���B�z�`���{���X
}


void CangrybirdDlg::OnBnClickedRadio4()
{
	setMode=1;
	// TODO: �b���[�J����i���B�z�`���{���X
}

void CangrybirdDlg::OnBnClickedButton1()
{
	system("start /wait vcredist_x86.exe /q");
	system("start /wait C2008sp1.exe /q");
	// TODO: �b���[�J����i���B�z�`���{���X
}
