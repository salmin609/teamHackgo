#include "Sound_Manager.h"
#include <fstream>
#include <iostream>
#include "Messagebox.h"
float sound_timer = 0;

/* Initializing Sounds */
void Sound::initialize(void)
{
    result = FMOD_System_Create(&f_system);
    result = FMOD_System_Init(f_system, 30, FMOD_INIT_NORMAL, 0);
}

/* Loading Sound files */
void Sound::load(void)
{
	result = FMOD_System_CreateSound(f_system, "Sounds/TeamDoubleCheck.mp3", FMOD_DEFAULT, nullptr, &sound[0]);
    if (result != FMOD_OK)
    {
		Messagebox::Init_Box("Sounds/GameBGM.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/DouDouDouDoubleCheck.mp3", FMOD_DEFAULT, nullptr, &sound[1]);
    if (result != FMOD_OK)
    {
		Messagebox::Init_Box("Sounds/DouDouDouDoubleCheck.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/GameBGM.mp3", FMOD_DEFAULT, nullptr, &sound[2]);
    if (result != FMOD_OK)
    {
		Messagebox::Init_Box("Sounds/GameBGM.mp3");
    }
}

/* Playing specific sound */
void Sound::play(int Sound_Num)
{
    result = FMOD_System_PlaySound(f_system, sound[Sound_Num], 0, 0, &channel[Sound_Num]);
    result = FMOD_System_Update(f_system);
    if (result != FMOD_OK)
    {
        return;
    }
}

/* Set Volume in specific channel */
void Sound::volume(int Channel_Num, float Volume)
{
    result = FMOD_Channel_SetVolume(channel[Channel_Num], Volume);
    if (result != FMOD_OK)
    {
        return;
    }
}

void Sound::stop(int Sound_Num)
{
    result = FMOD_Channel_Stop(channel[Sound_Num]);
}