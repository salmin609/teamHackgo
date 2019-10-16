#include "Physics.h"
#include "ObjectManager.h"
#include <cmath>
#include <vector>
#include "../Math_lib/vector2.hpp"
#include "Input.h"
#include "Sound_Manager.h"
#include "Engine.hpp"

void Physics::Init(Object* obj)
{
    m_owner = obj;
    m_owner->Get_Component_Info_Reference().component_info_physics = true;
}
//void Physics::Set

void Physics::Acceleration()
{
    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration += {0.00, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.y < 0)
            {
                acceleration += {0.00, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_A))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += -0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += -0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_S))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }

        }
        else if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration.y += -0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.y += -0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_D))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += 0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += 0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else
    {
        if (acceleration.x >= 0 && acceleration.y >= 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x >= 0 && acceleration.y < 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x < 0 && acceleration.y >= 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x < 0 && acceleration.y < 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    printf("first translation = %f,  %f\n", acceleration.x, acceleration.y);
}

void Physics::Acceleration2()
{
    if (input.Is_Key_Pressed(GLFW_KEY_KP_5))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_5) && input.Is_Key_Pressed(GLFW_KEY_KP_1))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_5) && input.Is_Key_Pressed(GLFW_KEY_KP_3))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration += {0.00, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.y < 0)
            {
                acceleration += {0.00, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_KP_1))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_1) && input.Is_Key_Pressed(GLFW_KEY_KP_5))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_1) && input.Is_Key_Pressed(GLFW_KEY_KP_2))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += -0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += -0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_KP_2))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_2) && input.Is_Key_Pressed(GLFW_KEY_KP_3))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }

        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_2) && input.Is_Key_Pressed(GLFW_KEY_KP_1))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration.y += -0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.y += -0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_KP_3))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_3) && input.Is_Key_Pressed(GLFW_KEY_KP_2))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, -0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, -0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_3) && input.Is_Key_Pressed(GLFW_KEY_KP_2))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.01, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.01, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.03, 0.01};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += 0.01;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += 0.03;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else
    {
        if (acceleration.x >= 0 && acceleration.y >= 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x >= 0 && acceleration.y < 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x < 0 && acceleration.y >= 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (acceleration.x < 0 && acceleration.y < 0)
        {
            acceleration += {-acceleration.x / 100, -acceleration.y / 100};
            m_owner->GetTransform().AddTranslation(acceleration);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
<<<<<<< HEAD

    printf("Second translation = %f,  %f\n", acceleration.x, acceleration.y);
}

void Physics::JustMove()
{
    acceleration += {-acceleration.x / 100, -acceleration.y / 100};
    m_owner->GetTransform().AddTranslation(acceleration);
    m_owner->GetMesh().Get_Is_Moved() = true;
=======
   /* printf("%f, %f \n", acceleration.x, acceleration.y);
    printf("translation = %f, %f\n\n\n", m_owner->GetTransform().GetTranslation().x, m_owner->GetTransform().GetTranslation().y);*/
>>>>>>> master
}

void Physics::KnockBack(Object* object_1, Object* object_2)
{
    vector2 object_1_pos = object_1->GetTransform().GetTranslation();
    vector2 object_2_pos = object_2->GetTransform().GetTranslation();
    vector2 object_1_acceleration = object_1->GetComponentByTemplate<Physics>()->GetAcceleration();
    vector2 object_2_acceleration = object_2->GetComponentByTemplate<Physics>()->GetAcceleration();
    vector2 direction_to_go;

    float object_1_speed = sqrt((object_1_acceleration.x * object_1_acceleration.x) + (object_1_acceleration.y * object_1_acceleration.y));
    float object_2_speed = sqrt((object_2_acceleration.x * object_2_acceleration.x) + (object_2_acceleration.y * object_2_acceleration.y));

    

    if (object_2_speed >= object_1_speed)
    {
<<<<<<< HEAD
        direction_to_go = normalize(object_1_pos - object_2_pos);

        object_1->GetComponentByTemplate<Physics>()->SetAcceleration({ direction_to_go.x * object_2_speed, direction_to_go.y * object_2_speed });
        object_1->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_1->GetMesh().Get_Is_Moved() = true;

        object_2->GetComponentByTemplate<Physics>()->SetAcceleration(-direction_to_go / 2.f);
        object_2->GetTransform().AddTranslation(object_2->GetComponentByTemplate<Physics>()->GetAcceleration());
=======
        object_1->GetComponentByTemplate<Physics>()->SetAcceleration(object_2_acceleration * 2.f);
        //object_1->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_1->GetMesh().Get_Is_Moved() = true;

        object_2->GetComponentByTemplate<Physics>()->SetAcceleration({ 0, 0 });
        //object_2->GetTransform().AddTranslation({0, 0});
>>>>>>> master
        object_2->GetMesh().Get_Is_Moved() = true;
    }
    else if (object_2_speed < object_1_speed)
    {
<<<<<<< HEAD
        direction_to_go = normalize(object_2_pos - object_1_pos);

        object_2->GetComponentByTemplate<Physics>()->SetAcceleration({ direction_to_go.x * object_1_speed, direction_to_go.y * object_1_speed });
        object_2->GetTransform().AddTranslation(object_2->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_2->GetMesh().Get_Is_Moved() = true;

        object_1->GetComponentByTemplate<Physics>()->SetAcceleration(-direction_to_go / 2.f);
        object_1->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
=======
        object_2->GetComponentByTemplate<Physics>()->SetAcceleration(object_1_acceleration * 2.f);
        //object_2->GetTransform().AddTranslation(object_2->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_2->GetMesh().Get_Is_Moved() = true;

        object_1->GetComponentByTemplate<Physics>()->SetAcceleration({ 0, 0 });
        //object_1->GetTransform().AddTranslation({ 0, 0 });
>>>>>>> master
        object_1->GetMesh().Get_Is_Moved() = true;
    }
}

void Physics::BasicMovement()
{
    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            velocity = { -1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            velocity = { 1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 0, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_A))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            velocity = { -1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            velocity = { -1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 1, 0 };
            velocity = { -1, 0 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_S))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            velocity = { -1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            velocity = { 1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 0, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_D))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            velocity = { 1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            velocity = { 1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 1, 0 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    //printf("%f, %f\n", velocity.x, velocity.y);
}

void Physics::BasicMovement2()
{
    if (input.Is_Key_Pressed(GLFW_KEY_KP_5))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_5) && input.Is_Key_Pressed(GLFW_KEY_KP_1))
        {
            velocity = { -1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_5) && input.Is_Key_Pressed(GLFW_KEY_KP_3))
        {
            velocity = { 1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 0, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_KP_1))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_1) && input.Is_Key_Pressed(GLFW_KEY_KP_5))
        {
            velocity = { -1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_1) && input.Is_Key_Pressed(GLFW_KEY_KP_2))
        {
            velocity = { -1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { -1, 0 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_KP_2))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_2) && input.Is_Key_Pressed(GLFW_KEY_KP_1))
        {
            velocity = { -1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_2) && input.Is_Key_Pressed(GLFW_KEY_KP_3))
        {
            velocity = { 1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 0, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
    if (input.Is_Key_Pressed(GLFW_KEY_KP_3))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_KP_3) && input.Is_Key_Pressed(GLFW_KEY_KP_5))
        {
            velocity = { 1, 1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_KP_3) && input.Is_Key_Pressed(GLFW_KEY_KP_2))
        {
            velocity = { 1, -1 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else
        {
            velocity = { 1, 0 };
            m_owner->GetTransform().AddTranslation(velocity);
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
    }
}

void Physics::Update(float dt)
{
<<<<<<< HEAD
    if (m_owner->GetName() == "first")
=======
    //timer += dt;

    //if(timer > 0.1f)
    //{
    //    prev_pos = m_owner->GetTransform().GetTranslation();
    //    timer = 0.f;
    //    std::cout << "reset" << std::endl;
    //}
    //direction_vector.x = m_owner->GetTransform().GetTranslation().x - prev_pos.x;
    //direction_vector.y = m_owner->GetTransform().GetTranslation().y - prev_pos.y;
    //std::cout << "dir vec x : " << direction_vector.x << std::endl;
    //std::cout << "dir vec y : " << direction_vector.y << std::endl;

    if(!m_owner->Get_Component_Info_Reference().component_info_physics)
    {
        m_owner->DeleteComponent(this);
    }

    for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
>>>>>>> master
    {
        Acceleration();
    }
    else if (m_owner->GetName() == "second")
    {
        Acceleration2();
    }
}