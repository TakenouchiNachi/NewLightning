#pragma once
#include "BaseClass.h"
class Player :
    public GameObject
{
private:
    

public:
    Player();
    ~Player();
    
    void RenderInitialize(int texID) override;
    void Update() override;
    void Draw(Vector2 pos) override;
};

