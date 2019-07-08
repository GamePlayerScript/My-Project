#pragma once


// CPgae1 对话框

class CPgae1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPgae1)

public:
	CPgae1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPgae1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
