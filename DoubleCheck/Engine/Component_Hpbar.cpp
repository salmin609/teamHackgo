#include "Component_Hpbar.h"
#include "Object.h"
#include "Message_Manager.h"
#include "Referee.h"

void Hp_Bar::Init(Object* obj)
{
    m_owner = obj;
    offset = 0;
}

void Hp_Bar::Update(float dt)
{

}

void Hp_Bar::Decrease(float dmg)
{
    if (m_owner->GetTransform().GetScale_Reference().x > 0)
    {
        Object* Hp_Owner_Obj = m_owner->Get_This_Obj_Owner();

        float damage = dmg;
        m_owner->GetTransform().GetScale_Reference().x -= damage;
        offset -= static_cast<int>(damage * 50);

        if(m_owner->GetTransform().GetScale_Reference().x <= 0)
        {
            m_owner->SetDeadCondition(true);
            Hp_Owner_Obj->SetDeadCondition(true);
            Message_Manager::Get_Message_Manager()->Save_Message(new Message(Referee::Get_Referee(), Hp_Owner_Obj, "respawn"));
        }
    }

}

int& Hp_Bar::Get_Set_Offset()
{
    return offset;
}
