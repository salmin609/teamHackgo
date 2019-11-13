#include "Level1.h"
#include "Component_Collision.h"
#include "Referee.h"
#include "Component_Text.h"


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

    player = new Object();
    player->Set_Name("first");
    player->Set_Tag("player");

    player->AddComponent(new Player());
    player->AddComponent(new Sprite(player, "../Sprite/awesomeface.png"));
    player->AddComponent(new Physics());
    
    ObjectManager::GetObjectManager()->AddObject(player);


    player_sec = new Object();
    player_sec->Set_Name("second");
    player_sec->Set_Tag("player");

    player_sec->SetTranslation({ 200,200 });
    player_sec->AddComponent(new Player());
    player_sec->AddComponent(new Sprite(player_sec, "../Sprite/awesomeface_red.png"));
    player_sec->AddComponent(new Physics());

    referee->AddComponent(new Collision());

    ObjectManager::GetObjectManager()->AddObject(player_sec);

    /*text = new Object();
    text->AddComponent(new TextComp(text, L"dmg", { 255,0,0,255 }, { 50,50 }));
    text->SetTranslation({ 200,200 });;
    text->Set_Name("text");*/

    //object_manager->AddObject(text);
}

void Level1::Update(float dt)
{
    referee->Update(dt);
}