#include "pch.h"
#include "SceneMgr.h"
#include "Scene_Start.h"

SceneMgr::SceneMgr()
	: m_pCurScene(nullptr)
	, m_arrScene{}
{
}

SceneMgr::~SceneMgr()
{
	// ¾À ÀüºÎ »èÁ¦.
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::Init()
{
	// ¾À »ý¼º..
	m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::SCENE_01] = new Scene_01;
	//m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start;
	//m_arrScene[(UINT)SCENE_TYPE::START] = new Scene_Start;

	// ÇöÀç ¾À ÁöÁ¤
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}
