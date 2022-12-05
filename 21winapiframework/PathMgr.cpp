#include "pch.h"
#include "PathMgr.h"
#include "Core.h"
PathMgr::PathMgr()
{
}

PathMgr::~PathMgr()
{
}

void PathMgr::Init()
{
	GetCurrentDirectory(255, m_szResPath);
	// 경로 확인용
	//	SetWindowText(Core::GetInst()->GetWndHandle(), m_szResPath);
	int Length = wcslen(m_szResPath);
	
	// 상위 폴더로 가고 싶은거야.
	for (int i = Length - 1; i >= 0; i--)
	{
		if (m_szResPath[i] == '\\')
		{
			m_szResPath[i] = '\0';
			break;
		}
	}
	wcscat_s(m_szResPath, 255, L"\\bin\\Res\\");
	SetWindowText(Core::GetInst()->GetWndHandle(), m_szResPath);
}
