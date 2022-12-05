#pragma once
#include "Object.h"
class Monster :
    public Object
{
private:
    float m_fSpeed; // 몬스터 스피드
    float m_fMaxDis; // 이동할 수 있는 최대거리
    float m_fDir; // 방향 1(오른쪽), -1(왼쪽)
    Vec2  m_vCenterPos; // 중심 위치

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

