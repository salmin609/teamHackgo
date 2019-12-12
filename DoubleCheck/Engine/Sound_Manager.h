
/*
   \file        Sound_Manager.h
   \project     Shooting Craft
   \author(s)   Chulseung Lee
   \copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#define SOUND_NUM 20

enum class SOUND
{
    TeamDoubleCheck = 0,
    DouDouDouDoubleCheck, 
    BGM,
    Respawn,
    Click,
    BGM2,
    Crack,
    Item,
    Dash,
    HP,
    Die,
    BulkUp
};

#include "fmod.hpp"
extern float sound_timer;

class Sound {
public:

     FMOD_RESULT result;
     FMOD_SYSTEM* f_system;
     FMOD_SOUND* sound[SOUND_NUM];
     FMOD_CHANNEL* channel[SOUND_NUM];

    void initialize();
    void load();
    void play(SOUND Sound_Num);
    void volume(SOUND Channel_Num, float Volume);
    void stop(SOUND Sound_Num);
};