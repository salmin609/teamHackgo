#pragma once
#include "Timer.hpp"
#include "Sound_Manager.h"

extern Sound sound;

class Engine
{
public:
    Engine() = default;

    void Init();
    void Update();
    void Delete();
    void Reset();

	//void Test();

    bool IsDone() { return is_done; }

private:
    bool is_done = false;
    float m_dt;
    Timer game_timer;
};