#pragma once
class TimeMgr
{
	// fps
	// 1�����Ӵ� �ð�(delta time)
private:
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	double			m_dDT; // �����Ӱ��� �ð� ��
	UINT			m_iCallCount; // �Լ� ȣ�� Ƚ�� üũ
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

