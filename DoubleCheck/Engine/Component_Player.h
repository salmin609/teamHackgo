
/*
 * Author		:sangmin.kim
 * File			:Component_Player.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Header file Component_Player.cpp.
 *
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */

#pragma once
#include "Component.hpp"
#include "Component_Item.h"

class PLAYER_UI;

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
	void Set_This_UI_info(PLAYER_UI* ui);
	void Set_Item_State(Item::Item_Kind state);
	PLAYER_UI* Get_Ui();
	Item::Item_Kind Get_Item_State();
	float& Get_Regeneration_Timer()
	{
		return regeneration_timer;
	}
	float& Get_Bulkup_Timer()
	{
		return bulkup_timer;
	}

	
private:
    Object* hp_bar = nullptr;
	Item::Item_Kind belong_item = Item::Item_Kind::None;
    int damage = 2;
	PLAYER_UI* this_ui;
	float regeneration_timer = 0.f;
	float bulkup_timer = 0.f;
};
