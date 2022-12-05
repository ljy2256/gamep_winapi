#pragma once
class Object;

class Collider
{
private:
	Object* m_pOwner;     // collider�� �����ϴ� ������Ʈ
	Vec2    m_vOffsetPos; // ��ġ
	Vec2    m_vFinalPos; // �� ������ ���� ���� ��ġ
	Vec2    m_vScale; // ũ��
	friend class Object;
	UINT	m_ID;   // �浹ü ���� ID(Ű��)
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


