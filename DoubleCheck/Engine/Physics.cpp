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
}

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
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.01};
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
   // printf("%f, %f \n", acceleration.x, acceleration.y);
   // printf("translation = %f, %f\n\n\n", m_owner->GetTransform().GetTranslation().x, m_owner->GetTransform().GetTranslation().y);
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
                acceleration += {-0.03, 0.03};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.03, 0.01};
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
    printf("%f, %f \n", acceleration.x, acceleration.y);
    printf("translation = %f, %f\n\n\n", m_owner->GetTransform().GetTranslation().x, m_owner->GetTransform().GetTranslation().y);
}

bool Physics::BoxToBoxCollision(Mesh mesh) const
{
    if (m_owner->GetMesh().GetPoint(0).x > mesh.GetPoint(2).x || m_owner->GetMesh().GetPoint(0).y > mesh.GetPoint(2).y)
    {
        return false;
    }
    else if (m_owner->GetMesh().GetPoint(1).x > mesh.GetPoint(3).x || m_owner->GetMesh().GetPoint(1).y < mesh.GetPoint(3).y)
    {
        return false;
    }
    else if (m_owner->GetMesh().GetPoint(2).x < mesh.GetPoint(0).x || m_owner->GetMesh().GetPoint(2).y < mesh.GetPoint(0).y)
    {
        return false;
    }
    else if (m_owner->GetMesh().GetPoint(3).x < mesh.GetPoint(1).x || m_owner->GetMesh().GetPoint(3).y > mesh.GetPoint(1).y)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Physics::CircleToCircleCollision(Object* object) const
{
    const vector2 my_position = m_owner->GetTransform().GetTranslation();
    const vector2 position = object->GetTransform().GetTranslation();
    float distance;
    float owner_radius = m_owner->GetTransform().GetScale().x * 100.f;
    float radius = object->GetTransform().GetScale().x * 100.f;

    distance = sqrt((my_position.x - position.x) * (my_position.x - position.x) + (my_position.y - position.y) * (my_position.y - position.y));

    if (distance <= (owner_radius + radius))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void Physics::KnockBack(Object* object)
{
    vector2 object_acceleration = object->GetComponentByTemplate<Physics>()->GetAcceleration();
    vector2 owner_acceleration = m_owner->GetComponentByTemplate<Physics>()->GetAcceleration();

    float object_speed = sqrt((object_acceleration.x * object_acceleration.x) + (object_acceleration.y * object_acceleration.y));
    float owner_speed = sqrt((owner_acceleration.x * owner_acceleration.x) + (owner_acceleration.y * owner_acceleration.y));

    if (owner_speed >= object_speed)
    {
        if (object_acceleration.x >= 0 && object_acceleration.y >= 0)
        {
            object->GetComponentByTemplate<Physics>()->SetAcceleration(-owner_acceleration * 2.f);
            object->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            object->GetMesh().Get_Is_Moved() = true;
        }
        else if (object_acceleration.x >= 0 && object_acceleration.y < 0)
        {
            object->GetComponentByTemplate<Physics>()->SetAcceleration(-owner_acceleration * 2.f);
            object->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            object->GetMesh().Get_Is_Moved() = true;
        }
        else if (object_acceleration.x < 0 && object_acceleration.y >= 0)
        {
            object->GetComponentByTemplate<Physics>()->SetAcceleration((-owner_acceleration * 2.f));
            object->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            object->GetMesh().Get_Is_Moved() = true;
        }
        else if (object_acceleration.x < 0 && object_acceleration.y < 0)
        {
            object->GetComponentByTemplate<Physics>()->SetAcceleration(-owner_acceleration * 2.f);
            object->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            object->GetMesh().Get_Is_Moved() = true;
        }

        acceleration = { 0, 0 };
        m_owner->GetTransform().AddTranslation(acceleration);
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    else
    {
        if (owner_acceleration.x >= 0 && owner_acceleration.y >= 0)
        {
            m_owner->GetComponentByTemplate<Physics>()->SetAcceleration(-object_acceleration * 2.f);
            m_owner->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (owner_acceleration.x >= 0 && owner_acceleration.y < 0)
        {
            m_owner->GetComponentByTemplate<Physics>()->SetAcceleration(-object_acceleration * 2.f);
            m_owner->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (owner_acceleration.x < 0 && owner_acceleration.y >= 0)
        {
            m_owner->GetComponentByTemplate<Physics>()->SetAcceleration((-object_acceleration * 2.f));
            m_owner->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            m_owner->GetMesh().Get_Is_Moved() = true;
        }
        else if (owner_acceleration.x < 0 && owner_acceleration.y < 0)
        {
            m_owner->GetComponentByTemplate<Physics>()->SetAcceleration(-object_acceleration * 2.f);
            m_owner->GetTransform().AddTranslation(object->GetComponentByTemplate<Physics>()->GetAcceleration());
            m_owner->GetMesh().Get_Is_Moved() = true;
        }

        object->GetComponentByTemplate<Physics>()->SetAcceleration({0, 0});
        object->GetTransform().AddTranslation({0, 0});
        m_owner->GetMesh().Get_Is_Moved() = true;
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
    timer += dt;

    for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
    {
        if (m_owner->GetName() == "first")
        {
            //BasicMovement();
            Acceleration();
        }
        else if(m_owner->GetName() == "second")
        {
            Acceleration2();
            //BasicMovement2();
        }
        if (i.get()->GetName() != m_owner->GetName())
        {

            if (i->GetComponentContainer()[0]->GetComponentName() == "BoxToBoxCollision" && m_owner->GetComponentContainer()[0]->GetComponentName() == "BoxToBoxCollision")
            {
                if (BoxToBoxCollision(i.get()->GetMesh()))
                {
                    printf("fuck\n");
                }
            }
            else if (i->GetComponentContainer()[0]->GetComponentName() == "CircleToCircleCollision" && m_owner->GetComponentContainer()[0]->GetComponentName() == "CircleToCircleCollision")
            {
                if (CircleToCircleCollision(i.get()))
                {
                    KnockBack(i.get());
                    printf("collide1!!!!!!!!!\n");
                    //sound.play(1);
                }
            }
        }
    }
}
