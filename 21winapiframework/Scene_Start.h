#pragma once
#include "Scene.h"
class Scene_Start :
    public Scene
{
public:
    Scene_Start();
    ~Scene_Start();
public:
    void    Enter() override;
    void    Exit() override;
};

