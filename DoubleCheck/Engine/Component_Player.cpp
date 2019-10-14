#include "Component_Player.h"
#include "Message_Manager.h"
#include "ObjectManager.h"
#include "Input.h"
#include "Component_Enemy.h"
#include "Component_Sprite.h"

void Player::Init(Object* obj)
{
    m_owner = obj;
    m_owner->Get_Component_Info_Reference().component_info_player = true;

    Object* hp_bar = new Object();
    hp_bar->AddComponent(new Sprite(hp_bar, "../Sprite/temp.png"));
    hp_bar->SetTranslation(m_owner->GetTransform().GetTranslation());

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
}

void Player::Attack()
{
   /* if (input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_LEFT))
    {
        Object* obj = ObjectManager::GetObjectManager()->GetObjectManagerContainer_Value()[1].get();
        Message_Manager::Get_Message_Manager()->Save_Message(new Message(obj, m_owner, "attack"));
    }*/
    if(input.Is_Mouse_Triggered(GLFW_MOUSE_BUTTON_RIGHT))
    {
        std::vector<Object*> objects_with_tag;
        objects_with_tag = ObjectManager::GetObjectManager()->Find_Objects_By_Tag("enemy");
        for (auto objects : objects_with_tag)
        {
            Message_Manager::Get_Message_Manager()->Save_Message(new Message(objects, m_owner, "attack"));
        }
    }
}
