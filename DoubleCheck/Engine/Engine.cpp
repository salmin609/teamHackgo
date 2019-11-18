﻿#include <fstream>
#include <sstream>

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

using namespace std;
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

	sound.initialize();
	sound.load();
	sound.play(0);
	sound.volume(0, 1);
	Sleep(1400);
	sound.play(2);
	sound.volume(2, 8);

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

	//Object* temp = new Object();
	//
	//ifstream readFile("../Data/Objects/Objects.txt");


	//if (readFile.is_open())
	//{
	//	string line;
	//	string type;
	//	string name;
	//	string locate;
	//	string animate;
	//	int result = 0, frame = 0, value_x = 0, value_y = 0;
	//	while (std::getline(readFile, line))
	//	{
	//		std::stringstream keystream(line);
	//		keystream >> type;
	//		
	//		if(type == "Player")
	//		{
	//			temp->AddComponent(new Physics);
	//			temp->AddComponent(new Collision);
	//			temp->AddComponent(new Player());
	//			temp->AddComponent(new Component_Transform());
	//		}
	//		else if(type == "Name:")
	//		{
	//			keystream >> name;
	//			temp->Set_Name(name);
	//		}
	//		else if (type == "Sprite:")
	//		{
	//			keystream >> locate;
	//			keystream >> animate;
	//			keystream >> frame;

	//			if(animate == "true")
	//			{
	//				result = 1;
	//			}
	//			else if(animate == "false")
	//			{
	//				result = 0;
	//			}
	//		
	//			
	//			temp->AddComponent(new Sprite(temp, locate.c_str() , result, frame));
	//			temp->Set_path(locate);
	//			temp->Set_AniState(animate);
	//			temp->Set_Frame(frame);
	//		}
	//		else if (type == "Position:")
	//		{
	//			keystream >> value_x;
	//			keystream >> value_y;

	//			temp->SetTranslation(vector2(value_x, value_y));
	//		}
	//		else if (type == "Scale:")
	//		{
	//			keystream >> value_x;
	//			keystream >> value_y;

	//			temp->SetScale(vector2(value_x, value_y));
	//			//.?????
	//			result = 0; frame = 0; value_x = 0; value_y = 0;	
	//		}
	//	}
	//}



	/*Object* temp_sec = new Object();
	temp_sec->AddComponent(new Physics);
	temp_sec->AddComponent(new Sprite(temp_sec, "../sprite/salmin.png"));
	temp_sec->AddComponent(new Component_Transform());
	temp_sec->Set_Name("second");
	temp_sec->Set_Tag("enemy");


	Object* temp_third = new Object();
	temp_third->AddComponent(new Physics);
	temp_third->AddComponent(new Sprite(temp_third, "../sprite/salmin.png"));
	temp_third->AddComponent(new Component_Enemy());
	temp_third->SetTranslation({ -200, -200 });
	temp_third->Set_Name("third");
	temp_third->Set_Tag("enemy");

	Object* temp_fourth = new Object();
	temp_fourth->AddComponent(new Physics);
	temp_fourth->AddComponent(new Sprite(temp_fourth, "../sprite/salmin.png"));
	temp_fourth->SetTranslation({ -400, -400 });
	temp_fourth->AddComponent(new Component_Transform());
	temp_fourth->Set_Name("fourth");

	Object* text_obj = new Object();
	text_obj->AddComponent(new TextComp(text_obj, L"Please jump on 5th floor Suhwan! ", { 255,0,0,255 }, { 50,50 }));
	text_obj->SetTranslation({ 500,300 });
	text_obj->Set_Name("text");

	object_manager->AddObject(temp);
	object_manager->AddObject(temp_sec);
	object_manager->AddObject(temp_third);
	object_manager->AddObject(temp_fourth);
	object_manager->AddObject(text_obj);*/
	StateManager::GetStateManager()->Get_States().at("Level1").get()->Load();
	//ofstream fileOut;
	//temp->Get_Is_Debugmode();
	//fileOut.open("../Data/Objects/Objects.txt");
	//if (fileOut.fail())
	//{
	//	cout << "Can't read the file " << endl;
	//}
	//
	//fileOut << "Player " << endl;
	//fileOut << "Name: " << temp->Get_Name() << endl;
	//fileOut << "Sprite: " << temp->Get_Path() << " ";
	//fileOut << temp->Get_AnimateState() << " ";
	//fileOut << temp->Get_Frame() << endl; //오브젝트에 만들어서 패스 경로 생성
	//fileOut << "Position: " << temp->GetTransform().GetTranslation_Reference().x << " ";
	//fileOut << temp->GetTransform().GetTranslation_Reference().y << endl;
	//fileOut << "Scale: " << temp->GetTransform().GetScale_Reference().x << " ";
	//fileOut << temp->GetTransform().GetScale_Reference().y << endl;
	//fileOut.close();

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
    StateManager::GetStateManager()->Get_States().at("Level1").get()->Update(m_dt);
    
    

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

