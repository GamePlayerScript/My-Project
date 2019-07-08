#pragma once
#include "afxwin.h"


// CPage1 对话框

class CPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage1)

public:
	CPage1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CListBox m_TaskList;
	CListBox m_ExeList;
	afx_msg void OnAddTask();
	afx_msg void OnBnClickedWizfinish();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnLbnSelchangeList2();
	
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton7();
	CComboBox m_AcountList;
	bool WriteFileData(CString nAcountSelone);
	CButton m_CreatAcount;
	CComboBox m_Race;
	CComboBox m_Role;
	
	CEdit m_GamePath;
	CEdit m_CustomRoleName;
	CEdit m_LoginNumber;
};
