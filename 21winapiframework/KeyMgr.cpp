#include "pch.h"
#include "KeyMgr.h"
#include "Core.h"
int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	VK_MENU, VK_LSHIFT, VK_CONTROL, VK_SPACE,
	VK_RETURN, VK_ESCAPE
};

KeyMgr::KeyMgr()
{
}

KeyMgr::~KeyMgr()
{
}

void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::LAST; i++)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE,false });
	}
}

void KeyMgr::Update()
{
	// �� â(������)�� ��Ŀ���� �˰�����ž�.
	//HWND hMainWnd = Core::GetInst()->GetWndHandle();
	HWND hWnd = GetFocus();
	// ��Ŀ�� ����. ���.
	if(nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			// Ű�� ���Ⱦ�.
			if (GetAsyncKeyState(g_arrVK[i]))
			{
				// ������ ���Ⱦ�.
				if (m_vecKey[i].bPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				// ������ �ȴ��Ⱦ�.
				else
				{
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevCheck = true;
			}
			// Ű�� �ȴ��Ⱦ�.
			else
			{
				// ������ �����־���.
				if (m_vecKey[i].bPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				//�������� �ȴ��Ⱦ�.
				else
				{
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevCheck = false;
			}
		}
	}
	// ��Ŀ�� ����. alt + tab
	else
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			m_vecKey[i].bPrevCheck = false;
			if (m_vecKey[i].eState == KEY_STATE::HOLD
				|| m_vecKey[i].eState == KEY_STATE::TAP)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (m_vecKey[i].eState == KEY_STATE::AWAY)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}


