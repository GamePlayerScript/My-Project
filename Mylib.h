#pragma once
#define COFIGPATH "C:\\Users\\Administrator\\Desktop\\INI\\Cofig.ini"
class CMylib
{
public:
	CMylib();
	~CMylib();
};


void StringSplit(CString source, CStringArray& dest, TCHAR division);
void RunApp(CString path);
long WriteIni(LPCTSTR lpAppName, LPCTSTR lpKeyName, LPCTSTR lpString, LPCTSTR lpFileName);
BSTR ReadIni(LPCTSTR lpAppName, LPCTSTR lpKeyName, LPCTSTR lpFileName);
CString Str(int i);
