#include "Engine.hpp"
#include "Application.hpp"
#include "ObjectManager.h"
#include "Input.h"

#include "Component_Collision.h"
#include "Component_Player.h"
#include "Graphic.h"
#include "StateManager.h"
#include "../DoubleCheck/MainMenu.h"
#include "../DoubleCheck/Level1.h"
#include "Component_Sprite.h"
#include "Component_Transform.h"
#include "Component_TopDownMovement.h"
#include "GL.hpp"
#include "Physics.h"
#include "Message_Manager.h"
#include "Sound_Manager.h"
#include "Windows.h"
#include "Component_Enemy.h"

Sound sound;

namespace
{
    Application* app_ = nullptr;
    ObjectManager* object_manager = nullptr;
    StateManager* state_manager = nullptr;
    Graphic* graphic = nullptr;
    Message_Manager* msg_manager = nullptr;
}

void Engine::Init()
{
    sound.initialize();
    sound.load();
    sound.play(0);
    sound.volume(0, 5);
    Sleep(1400);
    sound.play(2);
    sound.volume(2, 32);
    app_ = Application::Get_Application();
    object_manager = ObjectManager::GetObjectManager();
    state_manager = StateManager::GetStateManager();
    graphic = Graphic::GetGraphic();
    msg_manager = Message_Manager::Get_Message_Manager();

    app_->Init();
    object_manager->Init();
    state_manager->Init();
    graphic->Init();
    msg_manager->Init();

    state_manager->AddState("Menu", new Menu);
    state_manager->AddState("Level1", new Level1);

    Object* temp = new Object();
    temp->AddComponent(new Physics);
    temp->AddComponent(new Collision);
    temp->AddComponent(new Sprite(temp, "../sprite/anime.png", true, 6));
    temp->AddComponent(new Player());
    temp->AddComponent(new Component_Transform());
    //temp->AddComponent(new Component_TopDownMovement());
    temp->SetTranslation({ 200, 200 });
    temp->Set_Name("first");

    Object* temp_sec = new Object();
    temp_sec->AddComponent(new Physics);
    //temp_sec->AddComponent(new Collision);
    temp_sec->AddComponent(new Sprite(temp_sec, "../sprite/salmin.png"));
    temp_sec->AddComponent(new Component_Transform());

    //Object* fuck_me = new Object();
    //fuck_me->AddComponent(new Physics);
    //fuck_me->AddComponent(new Collision);
    //fuck_me->AddComponent(new Sprite(fuck_me, "../sprite/salmin.png"));
    //fuck_me->AddComponent(new Player());
    //fuck_me->AddComponent(new Component_Transform());
    //fuck_me->SetTranslation({ -200, -200 });
    //fuck_me->GetMesh().Get_Is_Moved() = true;

    //fuck_me->Set_Name("third");
    temp_sec->Set_Name("second");
    temp_sec->Set_Tag("enemy");

    //Object* temp_third = new Object();
    //temp_third->AddComponent(new Sprite());
    //temp_third->AddComponent(new Component_Enemy());
    //temp_third->Set_Name("third");
    //temp_third->Set_Tag("enemy");

    object_manager->AddObject(temp);
    object_manager->AddObject(temp_sec);
    //object_manager->AddObject(fuck_me);
    //object_manager->AddObject(temp_third);

    game_timer.Reset();
}

void Engine::Update()
{
    m_dt = game_timer.GetElapsedSeconds();
    game_timer.Reset();

    app_->Update(m_dt);
    state_manager->Update(m_dt);
    graphic->Update(m_dt);
    object_manager->Update(m_dt);
    msg_manager->Update(m_dt);

    //Reset camera zoom
    Reset();

    if (input.Is_Key_Triggered(GLFW_KEY_1))
        state_manager->is_pause = !state_manager->is_pause;
}

void Engine::Delete()
{

}

void Engine::Reset()
{
    if (Graphic::GetGraphic()->get_need_update_sprite())
    {
        Graphic::GetGraphic()->get_need_update_sprite() = false;
    }
}