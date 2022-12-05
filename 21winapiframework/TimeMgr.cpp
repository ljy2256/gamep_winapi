#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"

TimeMgr::TimeMgr()
	: m_llCurCount{}
	, m_llFrequency{}
	, m_llPrevCount{}
	, m_dDT(0.)
	, m_iCallCount(0)
{
}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::Init()
{
	// 현재 카운트의 틱을 가져온다.
	QueryPerformanceCounter(&m_llPrevCount);

	// 초당 카운트 횟수(1000만) 반환.
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	// 한 프레임에 걸린 시간을 구할거야.
	QueryPerformanceCounter(&m_llCurCount);
	m_dDT= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) 
		/ (double)(m_llFrequency.QuadPart);
	// 이전 카운트 값을 현재 카운트 값으로 갱신
	// => 다음번 계산을 할수가 있겠지.

	m_llPrevCount = m_llCurCount;
	// ... = 1. /m_dDT;
}

void TimeMgr::Render()
{
	++m_iCallCount; // 호출횟수 누적

	m_dAcc += m_dDT;

	if (m_dAcc >= 1.) // 1초가 지난거잖아.
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0;
		m_iCallCount = 0;
		static wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %lf", m_iFPS, m_dDT);
		//wsprintf(szBuffer, L"FPS: %d, DT: %lf", m_iFPS, m_dDT);
		SetWindowText(Core::GetInst()->GetWndHandle(), szBuffer);
	}
}
