#include "Component_Hpbar.h"
#include "Object.h"

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
    if(m_owner->GetTransform().GetScale_Reference().x > 0)
    {
        float damage = dmg;
        //if(m_owner->GetTransform().GetScale_Reference().x - damage >= 0)
        //{
            m_owner->GetTransform().GetScale_Reference().x -= damage;
            offset -= static_cast<int>(damage * 50);
        //}
        /*else
        {
            m_owner->GetTransform().GetScale_Reference().x = 0;
            m_owner->GetTransform().GetScale_Reference().y = 0;
            offset = 0;
        }*/
    }
}

int& Hp_Bar::Get_Set_Offset()
{
    return offset;
}
