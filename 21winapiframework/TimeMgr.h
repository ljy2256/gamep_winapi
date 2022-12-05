#pragma once
class TimeMgr
{
	// fps
	// 1프레임당 시간(delta time)
private:
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	double			m_dDT; // 프레임간의 시간 값
	UINT			m_iCallCount; // 함수 호출 횟수 체크
	double			m_dAcc;
	UINT			m_iFPS;
public:
	double			GetDT() { return m_dDT; }
	float			GetfDT() { return (float)m_dDT; }
public:
	SINGLE(TimeMgr);
private:
	TimeMgr();
	~TimeMgr();
public:
	//int a= QueryPerformanceCounter();
	//int b = QueryPerformanceFrequency();
	void		Init();
	void		Update();
	void		Render();
};

