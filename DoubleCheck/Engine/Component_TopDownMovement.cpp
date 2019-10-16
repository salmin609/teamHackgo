#include "Component_TopDownMovement.h"



void Component_TopDownMovement::Init(Object* obj)
{
    m_owner = obj;
    m_owner->Get_Component_Info_Reference().component_info_top_down_movement = true;
}

void Component_TopDownMovement::Update(float dt)
{
    if(!m_owner->Get_Component_Info_Reference().component_info_top_down_movement)
    {
        m_owner->DeleteComponent(this);
    }


    //WASD pressed movement
    if (input.Is_Key_Pressed(GLFW_KEY_I))
    {
        m_owner->GetTransform().AddTranslation({ 0.0f, 1.0f });

        if (input.Is_Key_Pressed((GLFW_KEY_L)))
        {
            m_owner->GetTransform().AddTranslation({ 1.0f, 0.0f });
        }
        else if (input.Is_Key_Pressed((GLFW_KEY_J)))
        {
            m_owner->GetTransform().AddTranslation({ -1.0f, 0.0f });
        }

        m_owner->GetMesh().Get_Is_Moved() = true;
        m_owner->Set_Need_Update_Points(true);
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_K))
    {
        m_owner->GetTransform().AddTranslation({ 0.0f, -1.0f });
        m_owner->GetMesh().Get_Is_Moved() = true;
        m_owner->Set_Need_Update_Points(true);
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_J)))
    {
        m_owner->GetTransform().AddTranslation({ -1.0f, 0.0f });

        //Graphic::GetGraphic()->get_need_update_sprite() = true;
        m_owner->GetMesh().Get_Is_Moved() = true;
        m_owner->Set_Need_Update_Points(true);
    }
    else if (input.Is_Key_Pressed((GLFW_KEY_L)))
    {
        m_owner->GetTransform().AddTranslation({ 1.0f, 0.0f });

       // Graphic::GetGraphic()->get_need_update_sprite() = true;
        m_owner->GetMesh().Get_Is_Moved() = true;
        m_owner->Set_Need_Update_Points(true);
    }
    else
    {
        //m_owner->GetTransform().SetTranslation({ 0.0f, 0.0f });
    }
}
