#include "Level1.h"


void Level1::Load()
{
    player = new Object();
    player->AddComponent(new Player());
    player->AddComponent(new Sprite());
    //player->AddComponent(new Physics());
    //player->AddComponent(new Component_TopDownMovement());

    player->Set_Name("player");
    player->Set_Tag("player");


    ObjectManager::GetObjectManager()->AddObject(player);
}

void Level1::Update(float dt)
{

}