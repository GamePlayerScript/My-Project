#pragma once


// CPgae1 �Ի���

class CPgae1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPgae1)

public:
	CPgae1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPgae1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
