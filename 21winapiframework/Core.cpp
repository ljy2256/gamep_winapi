#include "pch.h"
#include "Core.h"
#include "Object.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "PathMgr.h"
#include "CollisionMgr.h"

Core::Core()
	: m_hDC(0)
	, m_ptResolution{}
	, m_memDC(0)
	, m_hBit(0)
	, m_arrBrush{}
	, m_arrPen{}
{
}
void Core::CreateBrushPen()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

}
Core::~Core()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int Core::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	m_hDC = GetDC(m_hWnd);
	m_memDC = CreateCompatibleDC(m_hDC);
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	SelectObject(m_memDC, m_hBit);

	// 필요한 펜 브러쉬 생성
	CreateBrushPen();

	// =====Mgr 초기화=====
	TimeMgr::GetInst()->Init();
	KeyMgr::GetInst()->Init();
	PathMgr::GetInst()->Init();
	SceneMgr::GetInst()->Init();

	// 해상도 맞게 조절
	RECT rt = { 0,0,m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd,nullptr, 100,100
		,rt.right-rt.left
	    ,rt.bottom-rt.top,0);
	return S_OK;
}

void Core::Progress()
{
	Update();
	Render();
}

void Core::Update()
{
	// ==== Mgr Update ====
	TimeMgr::GetInst()->Update();
	KeyMgr::GetInst()->Update();
	SceneMgr::GetInst()->Update();
	CollisionMgr::GetInst()->Update();
}

void Core::Render()
{
	PatBlt(m_memDC, 0,0, m_ptResolution.x, m_ptResolution.y, WHITENESS);

	SceneMgr::GetInst()->Render(m_memDC);

	BitBlt(m_hDC, 0,0, m_ptResolution.x, m_ptResolution.y
	,m_memDC, 0,0,SRCCOPY);

	// 제목에 dt 띄우는 render()
	TimeMgr::GetInst()->Render();

}


