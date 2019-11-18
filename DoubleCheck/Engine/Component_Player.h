#pragma once
#include "Component.hpp"
#include <iostream>

class Player : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
    void Attack();
    int Get_Damage()
    {
        return damage;
    }

private:
    Object* hp_bar = nullptr;

    int damage = 2;
};
