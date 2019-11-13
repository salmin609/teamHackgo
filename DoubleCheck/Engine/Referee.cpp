#include "Referee.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "ObjectManager.h"
#include "Graphic.h"
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
    player_sec_temp = new Object();
    player_sec_temp->AddComponent(new Player());
    player_sec_temp->AddComponent(new Sprite(player_sec_temp, "../Sprite/awesomeface_red.png"));
    player_sec_temp->AddComponent(new Physics());
    player_sec_temp->Set_Name("second");
    player_sec_temp->Set_Tag("player");
    player_sec_temp->SetTranslation({ 200,200 });
    

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
        
        ObjectManager::GetObjectManager()->AddObject(player_sec_temp);
        break;
    }
}
