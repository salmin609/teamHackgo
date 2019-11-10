#include "Level1.h"
#include "Component_Collision.h"

void Level1::Load()
{
    player = new Object();
    player->AddComponent(new Player());
    player->AddComponent(new Sprite(player, "../Sprite/awesomeface.png"));
    player->AddComponent(new Physics());
    
    player->Set_Name("first");
    player->Set_Tag("player");

    player_sec = new Object();
    player_sec->SetTranslation({ 200,200 });
    player_sec->AddComponent(new Player());
    player_sec->AddComponent(new Sprite(player_sec, "../Sprite/awesomeface_red.png"));
    player_sec->AddComponent(new Physics());
    player_sec->Set_Name("second");
    player_sec->Set_Tag("player");

    player->AddComponent(new Collision());

    ObjectManager::GetObjectManager()->AddObject(player);
    ObjectManager::GetObjectManager()->AddObject(player_sec);
}

void Level1::Update(float dt)
{

}