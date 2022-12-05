#pragma once
class Collider;
class Object
{
private:
	//POINT		m_ptPos;
	//POINT		m_ptScale;
	Vec2		m_vPos;
	Vec2		m_vScale;
	Collider*   m_pCollider;

public:
	Object();
	virtual ~Object();

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	const Vec2& GetPos() { return m_vPos; }
	const Vec2& GetScale() { return m_vScale; }
	Collider* GetCollider() { return m_pCollider; }
public:
//	virtual void	Update() = 0;
	virtual void	Update() abstract;
	virtual void	Render(HDC _dc);
	void Component_Render(HDC _dc);
public:
	void CreateCollider();
	virtual void FinalUpdate() final;
};

// 재정의 -> 오버라이딩
// 중복정의 -> 오버로딩
