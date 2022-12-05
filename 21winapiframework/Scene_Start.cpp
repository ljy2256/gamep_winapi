#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	// Image 로딩
	

	Vec2 vResolution = Core::GetInst()->GetResolution();
	// Object 생성.
	Object* pObj = new Player;
	pObj->SetPos(Vec2(vResolution.x/2, vResolution.y/2));
	pObj->SetScale(Vec2(100.f, 100.f));
//	m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// Monster 추가.
	Monster* pMonsterObj = nullptr;
	int iMonster = 5;
	float fObjScale = 50.f;
	float fMoveDist = 10.f;
	float fTerm = (vResolution.x - ((fMoveDist+fObjScale /2.f) * 2)) / (float)(iMonster - 1);
	for (int i = 0; i < iMonster; ++i)
	{
		pMonsterObj = new Monster;
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) +(float)i*fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDis(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
}

void Scene_Start::Exit()
{
	CollisionMgr::GetInst()->CheckReset();
}
