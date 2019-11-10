#include "Message.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "Component_Enemy.h"
#include "Message_Manager.h"
#include "Component_Hpbar.h"

void Message::Init()
{
}

void Message::Update(float dt)
{
    if(message_name == "attack")
    {
        m_target->GetComponentByTemplate<Component_Enemy>()->Decrease_HP(m_from->GetComponentByTemplate<Player>()->Get_Damage());
    }
    if(message_name == "collision")
    {
        Object* target_hp_bar = m_target->Get_Belong_Object_By_Name("hp_bar");
        if(target_hp_bar != nullptr)
        {
            if(target_hp_bar->GetComponentByTemplate<Hp_Bar>() != nullptr)
            {
                float damage_to_target = 0;
                Physics* temp_physics = m_from->GetComponentByTemplate<Physics>();
                damage_to_target = (sqrt((temp_physics->GetAcceleration().x * temp_physics->GetAcceleration().x) +
                    (temp_physics->GetAcceleration().y * temp_physics->GetAcceleration().y)));

                std::cout << "damage to target : " << damage_to_target << std::endl;

                target_hp_bar->GetComponentByTemplate<Hp_Bar>()->Decrease(damage_to_target / 10);
            }
        }
    }

    std::string log = m_from->Get_Name() + " " + message_name + " " + m_target->Get_Name();

    Message_Manager::Get_Message_Manager()->Get_Log().push_back(log);

    delete(this);
}

void Message::Delete()
{
}
