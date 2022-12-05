#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
Player::Player()
	: m_pImage(nullptr)
{
//	m_pImage = new Image;
	/*wstring strFilePath = PathMgr::GetInst()->GetResPath();
	strFilePath += L"Image\\planem.bmp";*/
//	m_pImage->Load(strFilePath);
	m_pImage = ResMgr::GetInst()->ImgLoad(L"PlayerImg", L"Image\\planem.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));
	//GetCollider()->SetOffSetPos(Vec2(100.f, 0.f));
}
Player::~Player()
{
	//if (nullptr != m_pImage)
	//	delete m_pImage;
}

void Player::Update()
{
	Vec2 vPos = GetPos();
	//if (KeyMgr::GetInst()->GetKey(KEY::LEFT) == KEY_STATE::HOLD)
	if(KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 300.f * fDT;//TimeMgr::GetInst()->GetfDT();
	}
//	if (KeyMgr::GetInst()->GetKey(KEY::RIGHT) == KEY_STATE::HOLD)
	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 300.f * fDT; //TimeMgr::GetInst()->GetfDT();
	}

//	if (KeyMgr::GetInst()->GetKey(KEY::UP) == KEY_STATE::HOLD)
	if (KEY_HOLD(KEY::UP))
	{
		vPos.y -= 300.f * fDT; //TimeMgr::GetInst()->GetfDT();
	}
	if (KEY_HOLD(KEY::DOWN))
//	if (KeyMgr::GetInst()->GetKey(KEY::DOWN) == KEY_STATE::HOLD)
	{
		vPos.y += 300.f * fDT; //TimeMgr::GetInst()->GetfDT();
	}
//	if (KeyMgr::GetInst()->GetKey(KEY::SPACE) == KEY_STATE::TAP)
	if(KEY_TAP(KEY::ALT))
	{
		CreateBullet();
	}
	SetPos(vPos);
}

void Player::CreateBullet()
{
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;
	Bullet* pBullet = new Bullet;
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(Vec2(25.f, 25.f));
//	pBullet->SetDir(true);
	pBullet->SetDir(Vec2(-10.f, -15.f));
	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pBullet, GROUP_TYPE::BULLET);
}
void Player::Render(HDC _dc)
{
	int Width  = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();
	Vec2 vPos = GetPos();

	//BitBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//	, m_pImage->GetDC()
	//    , 0,0,SRCCOPY);
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height,
		RGB(255,0,255));
	Component_Render(_dc);
}
