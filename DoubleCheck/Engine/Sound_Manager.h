
/*
   \file        Sound_Manager.h
   \project     Shooting Craft
   \author(s)   Chulseung Lee
   \copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/
#pragma once
#define SOUND_NUM 20


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
    void play(int Sound_Num);
    void volume(int Channel_Num, float Volume);
    void stop(int Sound_Num);
};