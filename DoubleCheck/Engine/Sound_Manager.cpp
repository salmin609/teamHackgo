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
		Messagebox::Init_Box("Sounds/TeamDoubleCheck.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/DouDouDouDoubleCheck.mp3", FMOD_DEFAULT, nullptr, &sound[1]);
    if (result != FMOD_OK)
    {
		Messagebox::Init_Box("Sounds/DouDouDouDoubleCheck.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/BGM.mp3", FMOD_LOOP_NORMAL, nullptr, &sound[2]);
    if (result != FMOD_OK)
    {
		Messagebox::Init_Box("Sounds/Respawn.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Respawn.mp3", FMOD_DEFAULT, nullptr, &sound[3]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Bounce.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Click.mp3", FMOD_DEFAULT, nullptr, &sound[4]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Click.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/BGM2.mp3", FMOD_LOOP_NORMAL, nullptr, &sound[5]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/BGM2.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Crack.mp3", FMOD_DEFAULT, nullptr, &sound[6]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Crack.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Item.mp3", FMOD_DEFAULT, nullptr, &sound[7]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Item.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Dash.mp3", FMOD_DEFAULT, nullptr, &sound[8]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Dash.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/HP.mp3", FMOD_DEFAULT, nullptr, &sound[9]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/HP.mp3");
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/Die.mp3", FMOD_DEFAULT, nullptr, &sound[10]);
    if (result != FMOD_OK)
    {
        Messagebox::Init_Box("Sounds/Die.mp3");
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