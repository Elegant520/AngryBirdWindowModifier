
// angrybirdDlg.cpp : 實作檔
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


// CangrybirdDlg 對話方塊


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


// CangrybirdDlg 訊息處理常式

BOOL CangrybirdDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

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
	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CangrybirdDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
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
	// TODO: 在此加入控制項告知處理常式程式碼
	CDialogEx::OnOK();
}

void CangrybirdDlg::OnBnClickedRadio1()
{
	winMode=0;
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CangrybirdDlg::OnBnClickedRadio2()
{
	winMode=1;
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CangrybirdDlg::OnBnClickedRadio3()
{
	setMode=0;
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CangrybirdDlg::OnBnClickedRadio4()
{
	setMode=1;
	// TODO: 在此加入控制項告知處理常式程式碼
}

void CangrybirdDlg::OnBnClickedButton1()
{
	system("start /wait vcredist_x86.exe /q");
	system("start /wait C2008sp1.exe /q");
	// TODO: 在此加入控制項告知處理常式程式碼
}
