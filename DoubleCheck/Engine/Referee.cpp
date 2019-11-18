#include "Referee.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "ObjectManager.h"
#include "Graphic.h"
#include "Component_Collision.h"

Referee* Referee::referee = nullptr;


Referee* Referee::Get_Referee()
{
	if (referee == nullptr)
	{
		referee = new Referee();
	}
	return referee;
}

void Referee::Init()
{

	stage_statements.clear();
	player_first_temp = new Object * [player_first_life]();
	player_sec_temp = new Object * [player_sec_life]();


	for (int i = 0; i < player_first_life; i++)
	{
		player_first_temp[i] = new Object();
		player_first_temp[i]->AddComponent(new Player());
		player_first_temp[i]->AddComponent(new Sprite(player_first_temp[i], "../Sprite/awesomeface.png"));
		player_first_temp[i]->AddComponent(new Physics());
		player_first_temp[i]->Set_Name("first");
		player_first_temp[i]->Set_Tag("player");
		player_first_temp[i]->SetTranslation({ 200,200 });
	}

	for (int i = 0; i < player_sec_life; i++)
	{
		player_sec_temp[i] = new Object();
		player_sec_temp[i]->AddComponent(new Player());
		player_sec_temp[i]->AddComponent(new Sprite(player_sec_temp[i], "../Sprite/awesomeface_red.png"));
		player_sec_temp[i]->AddComponent(new Physics());
		player_sec_temp[i]->Set_Name("second");
		player_sec_temp[i]->Set_Tag("player");
		player_sec_temp[i]->SetTranslation({ 200,200 });
	}

}

void Referee::Update(float dt)
{

	if (!stage_statements.empty())
	{
		for (auto i : stage_statements)
		{
			if (i == PLAYER_SECOND_DIE && player_sec_life > 0)
			{
				player_second_respawn_timer -= dt;

				if (player_second_respawn_timer <= 0.0f)
				{
					player_second_respawn_timer = 3.0f;
					Respawn(i);
					player_sec_life--;
					stage_statements.erase(std::find(stage_statements.begin(), stage_statements.end(), i));
				}
			}
			if (i == PLAYER_FIRST_DIE && player_first_life > 0)
			{
				player_first_respawn_timer -= dt;

				if (player_first_respawn_timer <= 0.0f)
				{
					player_first_respawn_timer = 3.0f;
					Respawn(i);
					player_first_life--;
					stage_statements.erase(std::find(stage_statements.begin(), stage_statements.end(), i));
				}
			}
		}

	}

	if (this->GetComponentByTemplate<Collision>() != nullptr)
	{
		this->GetComponentByTemplate<Collision>()->Update(dt);
	}
}

void Referee::Delete()
{
}

void Referee::Respawn(Stage_Statement statement)
{
	switch (statement)
	{
	case PLAYER_SECOND_DIE:

		ObjectManager::GetObjectManager()->AddObject(player_sec_temp[player_sec_life - 1]);
		break;

	case PLAYER_FIRST_DIE:
		ObjectManager::GetObjectManager()->AddObject(player_first_temp[player_first_life - 1]);
		break;
	}
}
