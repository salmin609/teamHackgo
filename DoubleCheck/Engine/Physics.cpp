#include "Physics.h"
#include "ObjectManager.h"
#include <cmath>
#include "../Math_lib/vector2.hpp"
#include "Input.h"
#include "Engine.hpp"

void Physics::Init(Object* obj)
{
    m_owner = obj;
    m_owner->Get_Component_Info_Reference().component_info_physics = true;

}

void Physics::Acceleration()
{
    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.15, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.15, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.06, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.06, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.06, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.06, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.15, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.15, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration += {0.00, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.y < 0)
            {
                acceleration += {0.00, 0.15};
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
                acceleration += {-0.15, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.15, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.06, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.06, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.15, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.15, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.06, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.06, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += -0.15;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += -0.06;
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
                acceleration += {0.06, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.06, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.15, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.15, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }

        }
        else if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-0.15, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-0.15, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-0.06, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-0.06, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.y >= 0)
            {
                acceleration.y += -0.15;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.y += -0.06;
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
                acceleration += {0.06, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.06, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.15, -0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.15, -0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {0.06, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {0.06, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {0.15, 0.06};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {0.15, 0.15};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += 0.06;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += 0.15;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
    }
    else
    {
        acceleration += {-acceleration.x / 100, -acceleration.y / 100};
        m_owner->GetTransform().AddTranslation(acceleration);
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
    printf("first translation = %f,  %f\n", acceleration.x, acceleration.y);
}

void Physics::JustMove()
{
    acceleration += {-acceleration.x / 100, -acceleration.y / 100};
    m_owner->GetTransform().AddTranslation(acceleration);
    m_owner->GetMesh().Get_Is_Moved() = true;
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
        direction_to_go = normalize(object_1_pos - object_2_pos);

        object_1->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go * object_2_speed);
        object_1->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_1->GetMesh().Get_Is_Moved() = true;

        object_2->GetComponentByTemplate<Physics>()->SetAcceleration(-direction_to_go);
        object_2->GetTransform().AddTranslation(object_2->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_2->GetMesh().Get_Is_Moved() = true;
    }
    else if (object_2_speed < object_1_speed)
    {
        direction_to_go = normalize(object_2_pos - object_1_pos);

        object_2->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go * object_1_speed);
        object_2->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_2->GetMesh().Get_Is_Moved() = true;

        object_1->GetComponentByTemplate<Physics>()->SetAcceleration(-direction_to_go);
        object_1->GetTransform().AddTranslation(object_1->GetComponentByTemplate<Physics>()->GetAcceleration());
        object_1->GetMesh().Get_Is_Moved() = true;
    }
}

void Physics::Dash(Object* object)
{
    vector2 acceleration = object->GetComponentByTemplate<Physics>()->GetAcceleration();
    acceleration = normalize(acceleration);
    if (input.Is_Key_Pressed(GLFW_KEY_SPACE))
    {
        timer = 0;
        acceleration += {50 * acceleration.x, 50 * acceleration.y};
        object->GetComponentByTemplate<Physics>()->SetAcceleration(acceleration);
        is_dashed = false;
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

void Physics::Update(float dt)
{
    timer += dt;

    if (m_owner->GetName() == "first")
    {
        Acceleration();

        if (is_dashed == false && timer >= 1)
        {
            Dash(m_owner);
        }
    }
    else
    {
        JustMove();
    }
}