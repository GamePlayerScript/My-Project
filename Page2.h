#pragma once


// CPage2 �Ի���

class CPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage2)

public:
	CPage2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
