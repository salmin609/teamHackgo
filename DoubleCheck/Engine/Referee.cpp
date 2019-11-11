#include "Referee.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "ObjectManager.h"
Referee* Referee::referee = nullptr;


Referee* Referee::Get_Referee()
{
    if(referee == nullptr)
    {
        referee = new Referee();
    }
    return referee;
}

void Referee::Init()
{
    stage_statements.clear();
}

void Referee::Update(float dt)
{
    if(!stage_statements.empty())
    {
        for(auto i : stage_statements)
        {
            if(i == PLAYER_SECOND_DIE)
            {
                player_second_respawn_timer -= dt;

                if(player_second_respawn_timer <= 0.0f)
                {
                    player_second_respawn_timer = 3.0f;
                    
                    Respawn(i);

                    stage_statements.erase(std::find(stage_statements.begin(), stage_statements.end(), i));
                }
            }
        }

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
        Object* new_player_sec = new Object();
        new_player_sec->Set_Name("second");
        new_player_sec->Set_Tag("player");
        new_player_sec->SetTranslation({ 200,200 });
        new_player_sec->AddComponent(new Player());
        new_player_sec->AddComponent(new Sprite(new_player_sec, "../Sprite/awesomeface_red.png"));
        new_player_sec->AddComponent(new Physics());
        ObjectManager::GetObjectManager()->AddObject(new_player_sec);

        break;
    }
}
