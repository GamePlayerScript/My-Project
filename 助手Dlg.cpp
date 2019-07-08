
// 助手Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "助手.h"
#include "助手Dlg.h"
#include "afxdialogex.h"
#include "Page1.h"
#include "Page2.h"
#include "Mylib.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CPage1 page1;
CPage2 page2;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C助手Dlg 对话框



C助手Dlg::C助手Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C助手Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(C助手Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &C助手Dlg::OnBnClickedButton4)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C助手Dlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON3, &C助手Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// C助手Dlg 消息处理程序

BOOL C助手Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//Adds a title to the tab control
	m_tab.InsertItem(0, "基本设置");
	m_tab.InsertItem(1, "新手任务");
	m_tab.InsertItem(2, "自动抓鬼");
	//创建对话框到tab控件中
	page1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	page2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));

	CRect rect;
	//Gets rectangluar coordinates of client area of the window
	m_tab.GetClientRect(&rect);
	//设置对话框的显示位置
	rect.left += 5;
	rect.top += 25;
	rect.right -= 5;
	rect.bottom -= 5;
	//移动对话窗口到TAB控件
	page1.MoveWindow(&rect);
	page2.MoveWindow(&rect);
	//显示窗口
	page1.ShowWindow(true);
	//默认选中tap第一个选项卡
	m_tab.SetCurSel(0);
	page1.m_TaskList.InsertString(0, "自动登录");
	page1.m_TaskList.InsertString(1, "新手任务");
	page1.m_TaskList.InsertString(2, "自动抓鬼");
	page1.m_TaskList.InsertString(3, "自动五环");
	page1.m_TaskList.InsertString(4, "自动组队");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C助手Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C助手Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C助手Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C助手Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void C助手Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_tab.GetCurSel())
	{
	case 0:
	{
		page1.ShowWindow(true);
		page2.ShowWindow(false);
		break;
	}
	case 1:
		page1.ShowWindow(false);
		page2.ShowWindow(true);
		break;
	}

	*pResult = 0;
}


void C助手Dlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	CString strExeListText;
	CString strGamePath;
	CString strCustomRoleName;
	CString strLoginNumber;
	
	int nNumber = page1.m_ExeList.GetCount();
	for (int i = 0; i < nNumber; i++)
	{
		page1.m_ExeList.GetText(i,strExeListText);
		
		WriteIni("config", "Task"+ Str(i), strExeListText, COFIGPATH);
	}
	page1.m_GamePath.GetWindowTextA(strGamePath);
	page1.m_CustomRoleName.GetWindowTextA(strCustomRoleName);
	page1.m_LoginNumber.GetWindowTextA(strLoginNumber);

	//Save the configuration;
	WriteIni("config", "GamePath" , strGamePath, COFIGPATH);
	WriteIni("config", "CustomRoleName" ,strCustomRoleName, COFIGPATH);
	WriteIni("config", "LoginNumber" , strLoginNumber, COFIGPATH);

	WriteIni("config", "CreatAcount", Str(page1.m_CreatAcount.GetCheck()), COFIGPATH);
	WriteIni("config", "Role", Str(page1.m_Role.GetCurSel()), COFIGPATH);
	WriteIni("config", "Race", Str(page1.m_Race.GetCurSel()), COFIGPATH);
	WriteIni("config", "AcountList", Str(page1.m_AcountList.GetCurSel()), COFIGPATH);

}
