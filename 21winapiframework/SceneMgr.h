#pragma once
class Scene;
class SceneMgr
{
public:
	SINGLE(SceneMgr);
private:
	// �� ���
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];
	Scene* m_pCurScene; // ���� ��
private:
	SceneMgr();
	~SceneMgr();
public:
	void	Init();
	void	Update();
	void	Render(HDC _dc);
public:
	Scene* GetCurScene() { return m_pCurScene; }
};

