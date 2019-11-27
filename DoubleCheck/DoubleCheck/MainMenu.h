#pragma once
#include "State.h"
#include "GLFW/glfw3.h"

//#include <string>
//#include <iostream>
//#include "Input.h"
//#include <GLFW/glfw3.h>
class Object;

class MainMenu : public State
{
public:
	MainMenu()
    {
        current_state = GameState::Menu;
    }

	virtual void Load();
	virtual void Update(float dt);
    virtual void UnLoad()
    {
        next_level = {};
        is_next = false;
    }
private:
	Object* text;
};