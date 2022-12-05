#include "pch.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Object.h"
#include "Collider.h"

CollisionMgr::CollisionMgr()
{
}

CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::IsCollision(Collider* _pLeft, Collider* _pRight)
{
	Vec2 vLeftPos = _pLeft->GetFinalPos();
	Vec2 vRightPos = _pRight->GetFinalPos();
	Vec2 vLeftScale = _pLeft->GetScale();
	Vec2 vRightScale = _pRight->GetScale();

	if (abs(vRightPos.x - vLeftPos.x) < (vLeftScale.x + vRightScale.x) / 2.f
		&& abs(vRightPos.y - vLeftPos.y) < (vLeftScale.y + vRightScale.y) / 2.f)
	{
		return true;
	}
	return false;
}

void CollisionMgr::Update()
{
	for (UINT Row = 0; Row < (UINT)GROUP_TYPE::END; Row++)
	{
		for (UINT Col = Row; Col < (UINT)GROUP_TYPE::END; Col++)
		{
			if (m_arrCheck[Row] & (1 << Col))
			{
				CollisionGroupUpdate((GROUP_TYPE)Row, (GROUP_TYPE)Col);
			}
		}
	}
}

void CollisionMgr::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	// 작은 값을 행으로 두고, 큰 값을 열(비트)로 두자.
	UINT Row = (UINT)_eLeft;
	UINT Col = (UINT)_eRight;
	if (Col < Row)
	{
		Row = (UINT)_eRight;
		Col = (UINT)_eLeft;
	}
	// 체크가 이미 되어있다면?
	if (m_arrCheck[Row] &= (1<<Col))
	{
		m_arrCheck[Row] &= ~(1 << Col);
	}
	// 체크가 안되어있다면
	else
	{
		m_arrCheck[Row] |= (1 << Col);
	}
}

void CollisionMgr::CheckReset()
{
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}

void CollisionMgr::CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<Object*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
	map<ULONGLONG, bool>::iterator iter; 
	
	for (size_t i = 0; i < vecLeft.size(); i++)
	{
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		for (size_t j = 0; j < vecRight.size(); j++)
		{
			if (nullptr == vecRight[j]->GetCollider()
				|| vecLeft[i] == vecRight[j]) // 자기 자신 충돌
				continue;

			Collider* pLeftCol = vecLeft[i]->GetCollider();
			Collider* pRightCol = vecRight[j]->GetCollider();

			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();
			iter = m_mapColInfo.find(ID.ID);

			// 충돌한적이? 없다.
			if (m_mapColInfo.end() == iter)
			{
				m_mapColInfo.insert({ ID.ID, false });
				iter = m_mapColInfo.find(ID.ID);
			}
			// 충돌하는거네?
			if (IsCollision(pLeftCol, pRightCol))
			{
				// 현재 충돌중
				if (iter->second)
				{
					pLeftCol->StayCollision(pRightCol);
					pRightCol->StayCollision(pLeftCol);
				}
				// 이전은 아닌데 현재는 충돌중이야.
				else
				{
					pLeftCol->EnterCollision(pRightCol);
					pRightCol->EnterCollision(pLeftCol);
					iter->second = true;
				}
			}

			// 충돌 안하니?
			else
			{
				if (iter->second)
				{
					pLeftCol->ExitCollision(pRightCol);
					pRightCol->ExitCollision(pLeftCol);
					iter->second = false;
				}
			}
		}
	}

}
