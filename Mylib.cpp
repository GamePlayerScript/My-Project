#include "stdafx.h"
#include "Mylib.h"


CMylib::CMylib()
{
}


CMylib::~CMylib()
{
}

void StringSplit(CString source, CStringArray& dest, TCHAR division)
{
	if (source.IsEmpty())
	{

	}
	else
	{
		int pos = source.Find(division);
		if (pos == -1)
		{
			dest.Add(source);
		}
		else
		{
			dest.Add(source.Left(pos));
			source = source.Mid(pos + 1);
			StringSplit(source, dest, division);
		}
	}
}

void RunApp(CString path)
{
	ShellExecute(NULL, "open", path, NULL, NULL, SW_SHOWNORMAL);
}

long WriteIni(LPCTSTR lpAppName,LPCTSTR lpKeyName,LPCTSTR lpString,LPCTSTR lpFileName)
{
	return WritePrivateProfileString(lpAppName, lpKeyName,lpString,lpFileName);
}

BSTR ReadIni(LPCTSTR lpAppName, LPCTSTR lpKeyName, LPCTSTR lpFileName)
{
	CString strResult;
	char cBuffer[4096] = {0};
	GetPrivateProfileString(lpAppName, lpKeyName,"",cBuffer,sizeof(cBuffer),lpFileName);
	strResult = cBuffer;
	return strResult.AllocSysString();

}

CString Str(int i)
{
	CString c;
	c.Format("%d", i);
	return c;
}