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

    hp_bar->AddComponent(new Sprite(hp_bar, "../Sprite/HP.png", false));
    hp_bar->AddComponent(new Hp_Bar());

    hp_bar->GetMesh().Get_Is_Moved() = true;
    vector2 hp_bar_pos = m_owner->GetTransform().GetTranslation();
    hp_bar_pos.y -= 100;
    hp_bar->SetTranslation(hp_bar_pos);
    hp_bar->Get_Is_Debugmode() = false;
    hp_bar->Set_Name(m_owner->Get_Name() + "hp_bar");
    hp_bar->Set_Tag("hp_bar");
    
    this->hp_bar = hp_bar;
    m_owner->Get_Belongs_Objects().push_back(hp_bar);
    
    ObjectManager::GetObjectManager()->AddObject(hp_bar);
}

void Player::Update(float dt)
{
    Attack();

    if(input.Is_Key_Triggered(GLFW_KEY_U))
    {
        std::cout << "center_pos_x :" << m_owner->GetTransform().GetTranslation().x << std::endl;
        std::cout << "center_pos_y :" << m_owner->GetTransform().GetTranslation().y << std::endl;
        std::cout << std::endl;
    }

    if(input.Is_Key_Triggered(GLFW_KEY_L))
    {
        Object* obj = ObjectManager::GetObjectManager()->Find_Object_By_Name("hp_bar");

        //obj->GetComponentByTemplate<Hp_Bar>()->Decrease();

    }
}

void Player::Attack()
{
   /* if (input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_LEFT))
    {
        Object* obj = ObjectManager::GetObjectManager()->GetObjectManagerContainer_Value()[1].get();
        Message_Manager::Get_Message_Manager()->Save_Message(new Message(obj, m_owner, "attack"));
    }*/
   /* if(input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_RIGHT))
    {
        std::vector<Object*> objects_with_tag;
        objects_with_tag = ObjectManager::GetObjectManager()->Find_Objects_By_Tag("enemy");
        for (auto objects : objects_with_tag)
        {
            Message_Manager::Get_Message_Manager()->Save_Message(new Message(objects, m_owner, "attack"));
        }
    }*/
}
