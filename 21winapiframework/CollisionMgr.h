#pragma once
class Collider;
union COLLIDER_ID
{
	struct
	{
		UINT Left_id;
		UINT Right_id;
	};
	ULONGLONG ID;
};
class CollisionMgr
{
private:
	UINT m_arrCheck[(UINT)GROUP_TYPE::END];
	map<ULONGLONG, bool> m_mapColInfo;
public:
	SINGLE(CollisionMgr);
private:
	CollisionMgr();
	~CollisionMgr();
	bool IsCollision(Collider* _pLeft, Collider* _pRight);
public:
	void Update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void CheckReset();
	void CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
};

