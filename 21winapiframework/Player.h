#pragma once
#include "Object.h"
class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
public:
    Player();
    ~Player();
private:
    void CreateBullet();
public:
    void Update() override;
    void Render(HDC _dc) override;
};

