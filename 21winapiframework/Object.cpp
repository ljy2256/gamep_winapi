#include "pch.h"
#include "Object.h"
#include "Collider.h"
Object::Object()
	: m_vPos{}
	, m_vScale{}
	, m_pCollider(nullptr)
{
}

Object::~Object()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::FinalUpdate()
{
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}

void Object::Render(HDC _dc)
{
	Rectangle(_dc
		, (int)(m_vPos.x - m_vScale.x / 2.f)
		, (int)(m_vPos.y - m_vScale.y / 2.f)
		, (int)(m_vPos.x + m_vScale.x / 2.f)
		, (int)(m_vPos.y + m_vScale.y / 2.f));
	Component_Render(_dc);
}

void Object::Component_Render(HDC _dc)
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->Render(_dc);
	}
}


