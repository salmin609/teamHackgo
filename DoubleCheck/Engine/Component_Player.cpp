#include "Component_Player.h"
#include "Message_Manager.h"
#include "ObjectManager.h"
#include "Input.h"
#include "Component_Enemy.h"
#include "Component_Sprite.h"
#include "Component_Hpbar.h"

void Player::Init(Object* obj)
{
	m_owner = obj;
	m_owner->Get_Component_Info_Reference().component_info_player = true;

	Object* hp_bar = new Object(false);


	hp_bar->GetMesh().Get_Is_Moved() = true;
	vector2 hp_bar_pos = m_owner->GetTransform().GetTranslation();
	hp_bar_pos.y -= 100;
	hp_bar->SetTranslation(hp_bar_pos);

	hp_bar->AddComponent(new Sprite(hp_bar, "../Sprite/HP.png", hp_bar_pos, false));
	hp_bar->AddComponent(new Hp_Bar());

	hp_bar->Get_Is_Debugmode() = false;
	hp_bar->Set_Name(m_owner->Get_Name() + "hp_bar");
	hp_bar->Set_Tag("hp_bar");
	hp_bar->Set_This_Obj_Owner(m_owner);

	this->hp_bar = hp_bar;
	m_owner->Get_Belongs_Objects().push_back(hp_bar);

	ObjectManager::GetObjectManager()->AddObject(hp_bar);
}

void Player::Update(float dt)
{
	Attack();

	if (input.Is_Key_Triggered(GLFW_KEY_U))
	{
		std::cout << "center_pos_x :" << m_owner->GetTransform().GetTranslation().x << std::endl;
		std::cout << "center_pos_y :" << m_owner->GetTransform().GetTranslation().y << std::endl;
		std::cout << std::endl;
	}

	if (input.Is_Key_Triggered(GLFW_KEY_L))
	{
		Object* obj = ObjectManager::GetObjectManager()->Find_Object_By_Name("hp_bar");

		//obj->GetComponentByTemplate<Hp_Bar>()->Decrease();

	}
}

void Player::Attack()
{
}

Item::Item_Kind Player::Get_Item_State()
{
	return belong_item;
}

void Player::Set_This_UI_info(PLAYER_UI* ui)
{
	this_ui = ui;
}

void Player::Set_Item_State(Item::Item_Kind state)
{
	this->belong_item = state;
}

PLAYER_UI* Player::Get_Ui()
{
	return this_ui;
}
