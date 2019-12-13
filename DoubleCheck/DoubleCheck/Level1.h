/*
 * Author		:suhwan.kim
 * File			:Level1.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Header file for Level1.cpp
 * * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */


#pragma once
#include "State.h"
#include <string>
#include <iostream>
#include "Object.h"
#include "ObjectManager.h"
#include "Physics.h"
#include "Common_Header.h"
#include "BitmapFont.hpp"

class PLAYER_UI;

class Level1 : public State
{
public:

    Level1()
    {
        current_state = GameState::Game;
    }

    virtual void Load();
    virtual void Update(float dt);
    
    virtual void UnLoad()
    {
        next_level = {};
        is_next = false;
    }

private:
    Object* player;
    Object* player_sec;
    Object* player_third;
    Object* player_forth;

    Object* text;
	Object* arena;

	PLAYER_UI* player_first_ui;
	PLAYER_UI* player_second_ui;
	PLAYER_UI* player_third_ui;
	PLAYER_UI* player_fourth_ui;

	BitmapFont      font{};
};