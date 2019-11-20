﻿#include <fstream>
#include <sstream>

#include "Level1.h"
#include "Component_Collision.h"
#include "Referee.h"
#include "Component_Text.h"


using namespace std;

namespace
{
    Referee* referee = nullptr;

    ObjectManager* object_manager = nullptr;

}

void Level1::Load()
{
    referee = Referee::Get_Referee();
    referee->Init();
    object_manager = ObjectManager::GetObjectManager();

	arena = new Object(false);	
	arena->Set_Name("icearena");	
	arena->AddComponent(new Sprite(arena));


	ObjectManager::GetObjectManager()->AddObject(arena);
	
    player = new Object();


	ifstream readFile("../Data/Objects/Objects.txt");

	if (readFile.is_open())
	{
		string line;
		string type;
		string objectType;
		string name;
		string locate;
		string animate;
		int result = 0, frame = 0, value_x = 0, value_y = 0;
		while (std::getline(readFile, line))
		{
			std::stringstream keystream(line);
			keystream >> type;

			if (type == "Type:")
			{
				keystream >> objectType;
				player->AddComponent(new Player());
				player->AddComponent(new Physics());
				player->Set_Tag(objectType);

			}
			else if (type == "Name:")
			{
				keystream >> name;
				player->Set_Name(name);
			}
			else if (type == "Sprite:")
			{
				keystream >> locate;
				keystream >> animate;
				keystream >> frame;

				if (animate == "true")
				{
					result = 1;
				}
				else if (animate == "false")
				{
					result = 0;
				}


				player->AddComponent(new Sprite(player, locate.c_str(), result, frame));
				player->Set_path(locate);
				player->Set_AniState(animate);
				player->Set_Frame(frame);
			}
			else if (type == "Position:")
			{
				keystream >> value_x;
				keystream >> value_y;

				player->SetTranslation(vector2(value_x, value_y));
			}
			else if (type == "Scale:")
			{
				keystream >> value_x;
				keystream >> value_y;

				player->SetScale(vector2(value_x, value_y));
				//.?????
				result = 0; frame = 0; value_x = 0; value_y = 0;
			}
		}
	}

	ObjectManager::GetObjectManager()->AddObject(player);


	ofstream fileOut;
	player->Get_Is_Debugmode();
	fileOut.open("../Data/Objects/Objects.txt");
	if (fileOut.fail())
	{
		cout << "Can't read the file " << endl;
	}

	fileOut << "Type: " << player->Get_Tag() << endl;
	fileOut << "Name: " << player->Get_Name() << endl;
	fileOut << "Sprite: " << player->Get_Path() << " ";
	fileOut << player->Get_AnimateState() << " ";
	fileOut << player->Get_Frame() << endl; //오브젝트에 만들어서 패스 경로 생성
	fileOut << "Position: " << player->GetTransform().GetTranslation_Reference().x << " ";
	fileOut << player->GetTransform().GetTranslation_Reference().y << endl;
	fileOut << "Scale: " << player->GetTransform().GetScale_Reference().x << " ";
	fileOut << player->GetTransform().GetScale_Reference().y << endl;
	fileOut.close();

    player_sec = new Object();
    player_sec->Set_Name("second");
    player_sec->Set_Tag("player");

    player_sec->SetTranslation({ 200,200 });
    player_sec->AddComponent(new Player());
    player_sec->AddComponent(new Sprite(player_sec, "../Sprite/awesomeface_red.png"));
    player_sec->AddComponent(new Physics());
    ObjectManager::GetObjectManager()->AddObject(player_sec);


    referee->AddComponent(new Collision());
    //text = new Object();
    //text->AddComponent(new TextComp(text, L"Hitddfddffdfdffd!", { 255,0,0,255 }, { 50,50 }));
    //text->SetTranslation({ 200,200 });;
    //text->Set_Name("red_text");
    //text->Set_Tag("text");

    //object_manager->AddObject(text);
    //ObjectManager::GetObjectManager()->AddObject(text);
}

void Level1::Update(float dt)
{
    referee->Update(dt);
}