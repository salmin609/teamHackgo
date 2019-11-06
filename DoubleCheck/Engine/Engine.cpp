#include <fstream>
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
#include "Component_Transform.h"
#include "Component_TopDownMovement.h"
#include "GL.hpp"
#include "Physics.h"
#include "Message_Manager.h"
#include "Sound_Manager.h"
#include "Windows.h"
#include "Component_Enemy.h"

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
	

	Object* temp = new Object();
	temp->AddComponent(new Physics);
	temp->AddComponent(new Collision);
	temp->AddComponent(new Sprite(temp, "../sprite/anime.png", true, 6));
	temp->AddComponent(new Player());
	temp->AddComponent(new Component_Transform());
	temp->Set_Name("first");
	ifstream readFile("../Data/Objects/Object1.txt");


	if (readFile.is_open())
	{
		std::string line;
		std::string type;
		int value_x, value_y;;
		while (std::getline(readFile, line))
		{
			std::stringstream keystream(line);
			keystream >> type;

			if (type == "position")
			{
				keystream >> value_x;
				keystream >> value_y;

				temp->SetTranslation(vector2(value_x, value_y));
			}
			else if (type == "scale")
			{
				keystream >> value_x;
				keystream >> value_y;

				temp->SetScale(vector2(value_x, value_y));
				//.?????
			}
		}
	}



	Object* temp_sec = new Object();
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

	object_manager->AddObject(temp);
	object_manager->AddObject(temp_sec);
	object_manager->AddObject(temp_third);
	object_manager->AddObject(temp_fourth);


	ofstream fileOut;
	temp->Get_Is_Debugmode();
	fileOut.open("../Data/Objects/Object1.txt");
	if (fileOut.fail())
	{
		cout << "Can't read the file " << endl;
	}
	fileOut << "position " << temp->GetTransform().GetTranslation_Reference().x << " ";
	fileOut << temp->GetTransform().GetTranslation_Reference().y << endl;
	fileOut << "scale " << temp->GetTransform().GetScale_Reference().x << " ";
	fileOut << temp->GetTransform().GetScale_Reference().y << endl;
	fileOut.close();

	game_timer.Reset();
}


void Engine::Update()
{
    m_dt = game_timer.GetElapsedSeconds();
    game_timer.Reset();


    //std::thread thread_app(app_->Update);
    //std::thread thread_obj(&Update_Obj, m_dt);
    
    //thread_app = std::thread(&Update_App, m_dt);
    //thread_app.join();
    //thread_app = thread_app(&app_->Update, app_->Update());
    //Update_App(m_dt);
    app_->Update(m_dt);
    state_manager->Update(m_dt);
    graphic->Update(m_dt);
    //std::thread thread_graphic(&Update_Graphic, m_dt);
    object_manager->Update(m_dt);
    msg_manager->Update(m_dt);
    //std::thread thread_msg(&Update_Msg, m_dt);
    //Reset camera zoom
    Reset();

    if (input.Is_Key_Triggered(GLFW_KEY_1))
        state_manager->is_pause = !state_manager->is_pause;
    if (input.Is_Key_Triggered(GLFW_KEY_N))
    {
        Clear();
        StateManager::GetStateManager()->Get_States().at("Level1").get()->Load();
    }
   /* if(thread_app.joinable())
    {
        thread_app.join();
    }*/

    
    //thread_graphic.detach();
    //thread_obj.detach();
    //thread_msg.detach();
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
