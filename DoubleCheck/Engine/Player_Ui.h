#pragma once
#include "Object.h"
class PLAYER_UI : public Object
{
public:
	void Initialize();
	Object* Get_Hp_Info()
	{
		return info_hp_bar;
	}
	Object* Get_Item_Info()
	{
		return info_item;
	}
	void Reset();
private:
	
	Object* info_hp_bar = nullptr;
	Object* info_item = nullptr;
	Object* num_life = nullptr;
};