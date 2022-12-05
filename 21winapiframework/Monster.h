#pragma once
#include "Object.h"
class Monster :
    public Object
{
private:
    float m_fSpeed; // ���� ���ǵ�
    float m_fMaxDis; // �̵��� �� �ִ� �ִ�Ÿ�
    float m_fDir; // ���� 1(������), -1(����)
    Vec2  m_vCenterPos; // �߽� ��ġ

public:
    Monster();
    ~Monster();
public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMoveDis(float _f) { m_fMaxDis = _f; }
public:
    void Update() override;
};

