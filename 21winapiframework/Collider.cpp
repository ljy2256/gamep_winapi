#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "SelectGDI.h"
UINT Collider::g_iNextID = 0;
Collider::Collider()
	: m_pOwner(nullptr)
	, m_ID(g_iNextID++)
{
}

Collider::Collider(const Collider& _origin)
	: m_pOwner(_origin.m_pOwner)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_vScale(_origin.m_vScale)
	, m_ID(g_iNextID++)
{

}

Collider::~Collider()
{
}
void Collider::FinalUpdate()
{
	// Object¸¦ ÂÑ¾Æ°£´Ù.
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void Collider::Render(HDC _dc)
{
	//HPEN hGreenPen = Core::GetInst()->GetPen(PEN_TYPE::GREEN);
	//HPEN hDefaultPen = (HPEN)SelectObject(_dc, hGreenPen); 
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_iCheck)
		ePen = PEN_TYPE::RED;
	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, (int)m_vFinalPos.x - m_vScale.x / 2.f
		, (int)m_vFinalPos.y - m_vScale.y / 2.f
		, (int)m_vFinalPos.x + m_vScale.x / 2.f
		, (int)m_vFinalPos.y + m_vScale.y / 2.f);
	//SelectObject(_dc, hDefaultPen);

}

void Collider::EnterCollision(Collider* _pOther)
{
	m_iCheck = true;
}

void Collider::StayCollision(Collider* _pOther)
{

}

void Collider::ExitCollision(Collider* _pOther)
{
	m_iCheck = false;
}
