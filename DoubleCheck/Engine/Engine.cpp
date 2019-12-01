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
#include "Component_Text.h"
#include "Component_Transform.h"
#include "Component_TopDownMovement.h"
#include "GL.hpp"
#include "Physics.h"
#include "Message_Manager.h"
#include "Sound_Manager.h"
#include "Windows.h"
#include "Component_Enemy.h"
#include "BitmapFont.hpp"
#include "Shader.hpp"


#include <thread>

Sound sound;

namespace
{
	Application* app_ = nullptr;
	ObjectManager* object_manager = nullptr;
	StateManager* state_manager = nullptr;
	Graphic* graphic = nullptr;
	Message_Manager* msg_manager = nullptr;
}

void Update_App(float dt)
{
    //Invoke();

    app_->Update(dt);
}
void Update_Graphic(float dt)
{
    graphic->Update(dt);
}
void Update_Obj(float dt)
{
    object_manager->Update(dt);
}
void Update_Msg(float dt)
{
    msg_manager->Update(dt);
}

void Engine::Init()
{
	//sound.initialize();
	//sound.load();
	//sound.play(0);
	//sound.volume(0, 1);
	//Sleep(1400);
	//sound.play(2);
	//sound.volume(2, 8);

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

	state_manager->AddState("Menu", new MainMenu);
	state_manager->AddState("Level1", new Level1);

	StateManager::GetStateManager()->Get_States().at("Level1").get()->Load();

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

    StateManager::GetStateManager()->Get_States().at("Level1").get()->Update(m_dt);

    //Reset();
    
	if (input.Is_Key_Triggered(GLFW_KEY_1))
		state_manager->is_pause = !state_manager->is_pause;
	if (input.Is_Key_Triggered(GLFW_KEY_N))
	{
		Clear();
		StateManager::GetStateManager()->Get_States().at("Level1").get()->Load();
	}
}

void Engine::Delete()
{
	object_manager->Delete();
}

void Engine::Reset()
{
	if (Graphic::GetGraphic()->get_need_update_sprite())
	{
		Graphic::GetGraphic()->get_need_update_sprite() = false;
	}
}

void Engine::Clear()
{
	object_manager->Clear();
	//app_->Clear();
}

