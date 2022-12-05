#pragma once
class Object;

class Collider
{
private:
	Object* m_pOwner;     // collider를 소유하는 오브젝트
	Vec2    m_vOffsetPos; // 위치
	Vec2    m_vFinalPos; // 매 프레임 계산된 최종 위치
	Vec2    m_vScale; // 크기
	friend class Object;
	UINT	m_ID;   // 충돌체 고유 ID(키값)
	static UINT g_iNextID;
	bool	m_iCheck;
public:
	Collider();
	Collider(const Collider& _origin);
	~Collider();
public:
	void SetOffSetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }
	UINT GetID() { return m_ID; }
	Vec2 GetFinalPos() { return m_vFinalPos; }
public:
	void FinalUpdate();
	void Render(HDC _dc);
	void EnterCollision(Collider* _pOther);
	void StayCollision(Collider* _pOther);
	void ExitCollision(Collider* _pOther);

public:
	Collider& operator = (Collider& _origin) = delete;
};


