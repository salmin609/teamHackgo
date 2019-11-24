#pragma once
#include "Component.hpp"


class Hp_Bar : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
    void Decrease(float dmg);

    int& Get_Set_Offset();

private:
    int offset;
	int hp;
};