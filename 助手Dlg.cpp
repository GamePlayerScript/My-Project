
// ����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����.h"
#include "����Dlg.h"
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C����Dlg �Ի���



C����Dlg::C����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(C����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &C����Dlg::OnBnClickedButton4)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C����Dlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON3, &C����Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// C����Dlg ��Ϣ�������

BOOL C����Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//Adds a title to the tab control
	m_tab.InsertItem(0, "��������");
	m_tab.InsertItem(1, "��������");
	m_tab.InsertItem(2, "�Զ�ץ��");
	//�����Ի���tab�ؼ���
	page1.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB1));
	page2.Create(IDD_DIALOG2, GetDlgItem(IDC_TAB1));

	CRect rect;
	//Gets rectangluar coordinates of client area of the window
	m_tab.GetClientRect(&rect);
	//���öԻ������ʾλ��
	rect.left += 5;
	rect.top += 25;
	rect.right -= 5;
	rect.bottom -= 5;
	//�ƶ��Ի����ڵ�TAB�ؼ�
	page1.MoveWindow(&rect);
	page2.MoveWindow(&rect);
	//��ʾ����
	page1.ShowWindow(true);
	//Ĭ��ѡ��tap��һ��ѡ�
	m_tab.SetCurSel(0);
	page1.m_TaskList.InsertString(0, "�Զ���¼");
	page1.m_TaskList.InsertString(1, "��������");
	page1.m_TaskList.InsertString(2, "�Զ�ץ��");
	page1.m_TaskList.InsertString(3, "�Զ��廷");
	page1.m_TaskList.InsertString(4, "�Զ����");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C����Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C����Dlg::OnBnClickedButton3()
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
