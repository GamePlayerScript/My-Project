// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "助手.h"
#include "Page1.h"
#include "afxdialogex.h"
#include "Mylib.h"

//bool WriteFileData(CString nAcountSelone);
// CPage1 对话框

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_TaskList);
	DDX_Control(pDX, IDC_LIST2, m_ExeList);
	DDX_Control(pDX, IDC_COMBO3, m_AcountList);
	DDX_Control(pDX, IDC_CHECK1, m_CreatAcount);
	DDX_Control(pDX, IDC_COMBO1, m_Race);
	DDX_Control(pDX, IDC_COMBO2, m_Role);

	DDX_Control(pDX, IDC_EDIT1, m_GamePath);
	DDX_Control(pDX, IDC_EDIT2, m_CustomRoleName);
	DDX_Control(pDX, IDC_EDIT3, m_LoginNumber);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CPage1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage1::OnAddTask)
	ON_BN_CLICKED(ID_WIZFINISH, &CPage1::OnBnClickedWizfinish)
	ON_BN_CLICKED(IDC_BUTTON3, &CPage1::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CPage1::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPage1::OnBnClickedButton6)
	ON_LBN_SELCHANGE(IDC_LIST2, &CPage1::OnLbnSelchangeList2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPage1::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON7, &CPage1::OnBnClickedButton7)
END_MESSAGE_MAP()


// CPage1 消息处理程序


void CPage1::OnBnClickedButton2()//move down
{
	CString str;
	int listNumber  = m_ExeList.GetCount();// Gets the number of list controls
	if (listNumber != 0)
	{
		int line = m_ExeList.GetCurSel();
		
		if (line > 0)
		{
			m_ExeList.GetText(line, str);
			m_ExeList.DeleteString(line);
			m_ExeList.InsertString(line - 1, str);
			m_ExeList.SetCurSel(line - 1);
		}
		else
		{
			if (line < 0)
			{
				MessageBox("请选择上移的任务");
			}
			else
			{
				MessageBox("已经到最上端了");
			}
		}
	}
	else 
	{
		MessageBox("执行列表不能为空，请添加任务");
	
	}
}


void CPage1::OnAddTask()
{
	
	CString m_strEdtSrcFile;
	CFileDialog hFileDlg(false, NULL,
		
		NULL,
		OFN_FILEMUSTEXIST | OFN_READONLY | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR,
		TEXT("Text Files (*.txt)|*.txt|All Files(*.*)|*.*|"),
		NULL);
	// TODO: 在此添加控件通知处理程序代码
	if (hFileDlg.DoModal() == IDOK) {
		m_strEdtSrcFile = hFileDlg.GetPathName();
		/*UpdateData(FALSE);*/
	}
	/*m_GamePath.GetWindowTextA(m_strEdtSrcFile);*/
		SetDlgItemText(IDC_EDIT1, m_strEdtSrcFile);
	
	
	RunApp(m_strEdtSrcFile);
	
}


void CPage1::OnBnClickedWizfinish()//Add
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int line = m_TaskList.GetCurSel();//Get selection of list
	m_TaskList.GetText(line, str);//Gets the text of the current selection
	m_ExeList.AddString(str);//Adds text data
	OnLbnSelchangeList2();
}


void CPage1::OnBnClickedButton3()// move up
{
	CString str;
	int listNumber = m_ExeList.GetCount();// Gets the number of list controls
	if (listNumber != 0)
	{
		int line = m_ExeList.GetCurSel();

		if (line < listNumber -1)
		{
			m_ExeList.GetText(line, str);
			m_ExeList.DeleteString(line);
			m_ExeList.InsertString(line + 1, str);
			m_ExeList.SetCurSel(line + 1);
		}
		else
		{
			if (line > listNumber - 1)
			{
				MessageBox("请选择下移的任务");
			}
			else
			{
				MessageBox("已经到最上端了");
			}
		}
	}
	else
	{
		MessageBox("执行列表不能为空，请添加任务");

	}
}


void CPage1::OnBnClickedButton5()//Delete task list
{
	
	CString str;
	int listNumber = m_ExeList.GetCount();// Gets the number of list controls
	if (listNumber != 0)
	{
		int line = m_ExeList.GetCurSel();

		if (line >= 0)
		{

			m_ExeList.DeleteString(line);
		
		}
		
	}
	
}


void CPage1::OnBnClickedButton6()
{
	m_ExeList.ResetContent();
}


void CPage1::OnLbnSelchangeList2()
{
	UpdateData(TRUE);
	int nBottomLine = 0;
	while (TRUE)
	{
		int nListNumber = m_ExeList.GetCount();
		if (nBottomLine == nListNumber)
		{
			break;
		}
		CString strBuffer;
		m_ExeList.GetText(nBottomLine, strBuffer);
		for (int i = nListNumber - 1; i > nBottomLine; i--)
		{
			CString strTemp;
			m_ExeList.GetText(i, strTemp);
			if (strBuffer == strTemp)
			{
				m_ExeList.DeleteString(i);
			}
			
		}
		nBottomLine++;

	}
	
}



void CPage1::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CPage1::OnBnClickedButton7()
{
	CStdioFile file;
	CString cstrText;
	CString cstrFileLine;
	CString nAcountSelection;
	CStringArray arr1;
	CStringArray arr2;
	int i = 0;
		switch (m_AcountList.GetCurSel())
		{
		case 0:
			nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号1.txt";
			break;
		case 1:
			nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号2.txt";
			break;
		case 2:
			nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号3.txt";
			break;
		case 3:
			nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号4.txt";
			break;
		case 4:
			nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号5.txt";
			break;


		}
		WriteFileData(nAcountSelection);
		if (file.Open(nAcountSelection = "C:\\Users\\Administrator\\Documents\\Visual Studio 2015\\Projects\\助手\\Debug\\config\\账号1.txt", CFile::modeNoTruncate | CFile::modeCreate | CFile::modeReadWrite))
		{
			while (file.ReadString(cstrFileLine))
			{
				arr1.Add(cstrFileLine);
				i++;

			}
			
			for (i = 0; i <5; i++)
			{
				StringSplit(arr1[i], arr2, _T('|'));
				MessageBox(arr2[0]);
				MessageBox(arr2[1]);
				MessageBox(arr2[2]);
				arr2.RemoveAll();
			}
		}
	}

	
bool CPage1::WriteFileData(CString nAcountSelone)
{
	CStdioFile file;
	if (file.Open(nAcountSelone, CFile::modeNoTruncate|CFile::modeCreate | CFile::modeReadWrite))
	{
		file.SeekToEnd();
		
		CString cstrAcount, cstrPassWd, cstrServer,SerialNumber = "1";

		GetDlgItemText(IDC_EDIT4, cstrAcount);
		GetDlgItemText(IDC_EDIT5, cstrPassWd);
		GetDlgItemText(IDC_EDIT6, cstrServer);

		file.WriteString(cstrAcount + "|" + cstrPassWd + "|" + cstrServer + "|""\n");
		file.Close();
	}
	return TRUE;
}