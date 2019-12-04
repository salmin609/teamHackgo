#pragma once
#include "State.h"
#include <string>
#include <iostream>
#include "Object.h"
#include "ObjectManager.h"
#include "Physics.h"
#include "Common_Header.h"
#include "BitmapFont.hpp"
//#include "Component_Text.h"

class PLAYER_UI;

class Level1 : public State
{
public:
    //class TextComp;
    Level1()
    {
        current_state = GameState::Game;
    }

    virtual void Load();
    virtual void Update(float dt);
    /*
    std::cout << "Level1 Update" << std::endl;

    if (input.Is_Key_Triggered(GLFW_KEY_N))
    {
        is_next = true;
        next_level = "Menu";
    }*/

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
<<<<<<< HEAD
=======

	BitmapFont      font{};
>>>>>>> master
};