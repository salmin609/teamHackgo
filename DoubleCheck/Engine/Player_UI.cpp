#include "Player_Ui.h"
#include "Component_Sprite.h"
#include "ObjectManager.h"

void PLAYER_UI::Initialize()
{
	info_hp_bar = new Object();
	info_hp_bar->GetTransform().GetTranslation_Reference().x = this->GetTransform().GetTranslation().x + 350;
	info_hp_bar->GetTransform().GetTranslation_Reference().y = this->GetTransform().GetTranslation().y;
	info_hp_bar->GetTransform().GetScale_Reference().x = 4.0f;
	info_hp_bar->GetTransform().GetScale_Reference().y = 6.0f;
	info_hp_bar->AddComponent(new Sprite(info_hp_bar, "../Sprite/HP.png", info_hp_bar->GetTransform().GetTranslation(), false));
	info_hp_bar->Set_Tag("hp_info");
	info_hp_bar->Set_Name(this->GetName() + "info_hp");
	ObjectManager::GetObjectManager()->AddObject(info_hp_bar);

	info_item = new Object();
	info_item->GetTransform().GetTranslation_Reference().x = this->GetTransform().GetTranslation().x + 200;
	info_item->GetTransform().GetTranslation_Reference().y = this->GetTransform().GetTranslation().y - 200;
	info_item->GetTransform().GetScale_Reference().x = 2.0f;
	info_item->GetTransform().GetScale_Reference().y = 2.0f;
	info_item->AddComponent(new Sprite(info_item, "../Sprite/item.png", info_item->GetTransform().GetTranslation(), false));
	info_item->Set_Tag("item_info");
	info_item->Set_Name(this->GetName() + "info_item");
	info_item->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 0.5f,0.5f,0.5f,0.5f };
	ObjectManager::GetObjectManager()->AddObject(info_item);
	
}

void PLAYER_UI::Reset()
{
	this->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
	this->GetMesh().Get_Is_Moved() = true;
	
	info_hp_bar->GetTransform().GetTranslation_Reference().x = this->GetTransform().GetTranslation().x + 400;
	info_hp_bar->GetTransform().GetTranslation_Reference().y = this->GetTransform().GetTranslation().y + 100;
	info_hp_bar->GetTransform().GetScale_Reference().x = 4.0f;
	info_hp_bar->GetTransform().GetScale_Reference().y = 8.0f;
	info_hp_bar->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
	info_hp_bar->GetMesh().Get_Is_Moved() = true;

	info_item->GetTransform().GetTranslation_Reference().x = this->GetTransform().GetTranslation().x + 400;
	info_item->GetTransform().GetTranslation_Reference().y = this->GetTransform().GetTranslation().y - 200;
	info_item->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 0.5f,0.5f,0.5f,0.5f };
	info_item->GetMesh().Get_Is_Moved() = true;
}
