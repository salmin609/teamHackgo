#include "Component_Hpbar.h"
#include "Object.h"
#include "Message_Manager.h"
#include "Referee.h"
#include "Component_Text.h"
#include "ObjectManager.h"

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

        if(Hp_Owner_Obj->Get_Name() == "first")
        {
            Object* text = ObjectManager::GetObjectManager()->Find_Object_By_Name("red_text");
            vector2 text_pos = Hp_Owner_Obj->GetTransform().GetTranslation();
            text_pos.y += 10;
            text->GetTransform().SetTranslation(text_pos);
            //ObjectManager::GetObjectManager()->AddObject(text);

        }

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
