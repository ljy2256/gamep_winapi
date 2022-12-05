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
	// 내 창(윈도우)의 포커싱을 알고싶은거야.
	//HWND hMainWnd = Core::GetInst()->GetWndHandle();
	HWND hWnd = GetFocus();
	// 포커싱 상태. 띄움.
	if(nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::LAST; i++)
		{
			// 키가 눌렸어.
			if (GetAsyncKeyState(g_arrVK[i]))
			{
				// 이전에 눌렸어.
				if (m_vecKey[i].bPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				// 이전에 안눌렸어.
				else
				{
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
				m_vecKey[i].bPrevCheck = true;
			}
			// 키가 안눌렸어.
			else
			{
				// 이전에 눌려있었어.
				if (m_vecKey[i].bPrevCheck)
				{
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				//이전에도 안눌렸어.
				else
				{
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
				m_vecKey[i].bPrevCheck = false;
			}
		}
	}
	// 포커싱 해제. alt + tab
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


