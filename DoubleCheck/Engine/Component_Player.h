#pragma once
#include "Component.hpp"
#include "Component_Item.h"


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
	void Set_Item_State(Item::Item_Kind state);
	Item::Item_Kind Get_Item_State();

	
private:
    Object* hp_bar = nullptr;
	Item::Item_Kind belong_item = Item::Item_Kind::None;
    int damage = 2;
};
