#include "Sound_Manager.h"
#include <string>

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
        return;
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/DouDouDouDoubleCheck.mp3", FMOD_DEFAULT, nullptr, &sound[1]);
    if (result != FMOD_OK)
    {
        return;
    }
    result = FMOD_System_CreateSound(f_system, "Sounds/GameBGM.mp3", FMOD_DEFAULT, nullptr, &sound[2]);
    if (result != FMOD_OK)
    {
        return;
    }
}

/* Playing specific sound */
void Sound::play(int Channel_Num)
{
    result = FMOD_System_PlaySound(f_system, sound[Channel_Num], 0, 0, &channel[Channel_Num]);
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