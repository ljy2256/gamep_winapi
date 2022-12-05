#pragma once
class Object;
class Scene
{
public:
	Scene();
	virtual ~Scene();
private:
//	Object* m_obj; // x
	vector<Object*> m_vecObj[(UINT)GROUP_TYPE::END];
	wstring			m_strName;
	//virtual void Enter() = 0;
public:
	void AddObject(Object* _pObj, GROUP_TYPE _eType)
	{
		m_vecObj[(UINT)_eType].push_back(_pObj);
	}
public:
	const vector<Object*>& GetGroupObject(GROUP_TYPE _eType)
	{
		return m_vecObj[(UINT)_eType];
	}
public:
	virtual void Enter() abstract;
	virtual void Exit() abstract;


public:
	void	SetName(const wstring& _strName)
	{
		m_strName = _strName;
	}
	const wstring& GetName() { return m_strName; }
	void	Update();
	void	Render(HDC _dc);
	void    FinalUpdate();
};

