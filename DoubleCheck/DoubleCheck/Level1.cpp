#include "Level1.h"

void Level1::Load()
{
    player = new Object();
    player->AddComponent(new Player());
    player->AddComponent(new Sprite(player, "../Sprite/awesomeface.png"));


    player->Set_Name("first");
    player->Set_Tag("first");

    ObjectManager::GetObjectManager()->AddObject(player);
}

void Level1::Update(float dt)
{

}