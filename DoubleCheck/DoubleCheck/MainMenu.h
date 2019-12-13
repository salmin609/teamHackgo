/*
 * Author		:Suhwan.kim
 * File			:MainMenu.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Header file of MainMenu.cpp
 */




#pragma once
#include "State.h"
#include "GLFW/glfw3.h"
#include "vector2.hpp"

class Object;

class MainMenu : public State
{
public:
	MainMenu() :State()
	{
		current_state = GameState::Menu;
	}

	virtual void Load();
	virtual void Update(float dt);
	virtual void Clear();
	virtual void UnLoad()
	{
		next_level = {};
		is_next = false;
	}
	bool MouseCollision(vector2 position_max, vector2 position_min, vector2 mouse_pos);
private:
	Object* button;
	Object* collision_button;

	//std::unordered_map<std::string, std::shared_ptr<State>> states;
};