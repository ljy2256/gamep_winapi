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
	// ��� Ȯ�ο�
	//	SetWindowText(Core::GetInst()->GetWndHandle(), m_szResPath);
	int Length = wcslen(m_szResPath);
	
	// ���� ������ ���� �����ž�.
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
