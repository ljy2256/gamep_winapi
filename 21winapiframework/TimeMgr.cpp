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
	// ���� ī��Ʈ�� ƽ�� �����´�.
	QueryPerformanceCounter(&m_llPrevCount);

	// �ʴ� ī��Ʈ Ƚ��(1000��) ��ȯ.
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	// �� �����ӿ� �ɸ� �ð��� ���Ұž�.
	QueryPerformanceCounter(&m_llCurCount);
	m_dDT= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) 
		/ (double)(m_llFrequency.QuadPart);
	// ���� ī��Ʈ ���� ���� ī��Ʈ ������ ����
	// => ������ ����� �Ҽ��� �ְ���.

	m_llPrevCount = m_llCurCount;
	// ... = 1. /m_dDT;
}

void TimeMgr::Render()
{
	++m_iCallCount; // ȣ��Ƚ�� ����

	m_dAcc += m_dDT;

	if (m_dAcc >= 1.) // 1�ʰ� �������ݾ�.
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
