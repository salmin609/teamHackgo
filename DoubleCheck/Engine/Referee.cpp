#include "Referee.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "ObjectManager.h"
#include "Graphic.h"
#include "Component_Collision.h"
#include "Component_Item.h"


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
    player_first_temp = new Object*[player_first_life]();
    player_sec_temp = new Object*[player_sec_life]();
    item_save = new Object*[item_num]();

    for (int i = 0; i < player_first_life; i++)
    {
        player_first_temp[i] = new Object();
        player_first_temp[i]->AddComponent(new Player());
        player_first_temp[i]->AddComponent(new Sprite(player_first_temp[i], "../Sprite/awesomeface.png", {0,0}));
        player_first_temp[i]->AddComponent(new Physics(true));
        player_first_temp[i]->Set_Name("first");
        player_first_temp[i]->Set_Tag("player");
    }

    for(int i = 0 ; i < player_sec_life; i++)
    {
        player_sec_temp[i] = new Object();
        player_sec_temp[i]->AddComponent(new Player());
        player_sec_temp[i]->AddComponent(new Sprite(player_sec_temp[i], "../Sprite/awesomeface_red.png", {200,200}));
        player_sec_temp[i]->AddComponent(new Physics(true));
        player_sec_temp[i]->Set_Name("second");
        player_sec_temp[i]->Set_Tag("player");
    }


    for(int i = 0; i < item_num; i++)
    {
        item_save[i] = new Object();
        item_save[i]->AddComponent(new Sprite(item_save[i], "../Sprite/awesomeface_green.png", {-100,-100}));
        item_save[i]->AddComponent(new Item());
        item_save[i]->AddComponent(new Physics());
        item_save[i]->Set_Name("item");
        item_save[i]->Set_Tag("item");
        item_save[i]->SetTranslation({ -200,-200 });
		item_save[i]->GetComponentByTemplate<Item>()->Set_Kind(Item::Item_Kind::Dash);
    }
}

void Referee::Update(float dt)
{

    if(!stage_statements.empty())
    {
        for(auto i : stage_statements)
        {
            if(i == PLAYER_SECOND_DIE && player_sec_life > 0)
            {
                player_second_respawn_timer -= dt;

                if(player_second_respawn_timer <= 0.0f)
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
    item_respawn_timer -= dt;
    if(item_respawn_timer <= 0.0f && item_num > 0)
    {
        item_respawn_timer = 10.0f;
        ObjectManager::GetObjectManager()->AddObject(item_save[item_num - 1]);
        item_num--;
    }
    
    if(this->GetComponentByTemplate<Collision>() != nullptr)
    {
        this->GetComponentByTemplate<Collision>()->Update(dt);
    }
}

void Referee::Delete()
{
	
}

void Referee::Respawn(Stage_Statement statement)
{
    switch(statement)
    {
    case PLAYER_SECOND_DIE:
        ObjectManager::GetObjectManager()->AddObject(player_sec_temp[player_sec_life - 1]);
        break;

    case PLAYER_FIRST_DIE:
        ObjectManager::GetObjectManager()->AddObject(player_first_temp[player_first_life - 1]);
        break;
    }

}
