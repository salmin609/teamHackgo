#pragma once
#include "State.h"
#include "vector2.hpp"

class Object;

class Logo : public State
{
public:
    Logo() :State()
    {
        current_state = GameState::Logo;
    }

    virtual void Load();
    virtual void Update(float dt);
    virtual void Clear();
    virtual void UnLoad()
    {
        next_level = {};
        is_next = false;
    }
private:
    bool logo_on = true;
    bool logo_on2 = false;
    bool logo_on3 = false;
    bool logo_dead = true;
    bool logo_dead2 = false;
    bool logo_dead3 = false;

    bool next = false;
    float logo_timer = 0;
    Object* digipen_logo;
    Object* fmod_logo;
    Object* team_logo;
};