#pragma once
#include "Object.h"
class Bullet :
    public Object
{
private:
//    float m_fDir; // 총알 방향(위, 아래)
    float m_fTheta; // 총알 방향(위, 아래)
    Vec2  m_vDir;

public:
    Bullet();
    ~Bullet();
public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
public:
    //void SetDir(bool _b)
    //{
    //    if (_b) // 위
    //        m_fDir = -1.f;
    //    else
    //        m_fDir = 1.f;
    //}
    void SetDir(float _fTheta) 
    { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Normalize();
    }
};

