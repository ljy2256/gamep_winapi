#include "pch.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"
Monster::Monster()
	: m_fSpeed(100.f)
	, m_fMaxDis(50.f)
	, m_vCenterPos(Vec2(0.f,0.f))
	, m_fDir(1.f)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

Monster::~Monster()
{
}

void Monster::Update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += m_fSpeed * fDT * m_fDir;

	// ���� �� �� �ִ� �Ÿ� �ִ�� ����? �׷� ���� �ٲ���
	// ���� ��ġ > �ִ�Ÿ�
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDis;
	if (fDist > 0.f)
	{
		m_fDir *= -1;
		vCurPos.x += fDist * m_fDir;
	}
	SetPos(vCurPos);
}
