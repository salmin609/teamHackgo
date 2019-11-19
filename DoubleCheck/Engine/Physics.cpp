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

void Physics::Acceleration(float max_accel, float min_accel)
{
	GLFWgamepadstate state;

	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

	if (present)
	{
		int axesCount;
		const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);

		if (axes[1] < 0)
		{
			if (axes[1] < 0 && axes[0] < 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {-max_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {-max_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {-min_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {-min_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else if (axes[1] < 0 && axes[0] > 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {min_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {min_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {max_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {max_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else
			{
				if (abs(acceleration.x) >= 0)
				{
					acceleration.x -= acceleration.x / 100;
				}
				if (acceleration.y >= 0)
				{
					acceleration += {0.00, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.y < 0)
				{
					acceleration += {0.00, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
		}
		else if (axes[0] < 0)
		{
			if (axes[0] < 0 && axes[1] < 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {-max_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {-max_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {-min_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {-min_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else if (axes[0] < 0 && axes[1] > 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {-max_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {-max_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {-min_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {-min_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else
			{
				if (acceleration.x >= 0)
				{
					acceleration.x += -max_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration.x += -min_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				if (abs(acceleration.y) >= 0)
				{
					acceleration.y -= acceleration.y / 100;
				}
			}
		}
		else if (axes[1] > 0)
		{
			if (axes[1] > 0 && axes[0] > 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {min_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {min_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {max_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {max_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}

			}
			else if (axes[1] > 0 && axes[0] < 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {-max_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {-max_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {-min_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {-min_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else
			{
				if (abs(acceleration.x) >= 0)
				{
					acceleration.x -= acceleration.x / 100;
				}
				if (acceleration.y >= 0)
				{
					acceleration.y += -max_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration.y += -min_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
		}
		else if (axes[0] > 0)
		{
			if (axes[0] > 0 && axes[1] > 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {min_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {min_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {max_accel, -max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {max_accel, -min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else if (axes[0] > 0 && axes[1] < 0)
			{
				if (acceleration.x >= 0 && acceleration.y >= 0)
				{
					acceleration += {min_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x >= 0 && acceleration.y < 0)
				{
					acceleration += {min_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else if (acceleration.x < 0 && acceleration.y >= 0)
				{
					acceleration += {max_accel, min_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration += {max_accel, max_accel};
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
			}
			else
			{
				if (acceleration.x >= 0)
				{
					acceleration.x += min_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				else
				{
					acceleration.x += max_accel;
					m_owner->GetTransform().AddTranslation(acceleration);
					m_owner->GetMesh().Get_Is_Moved() = true;
				}
				if (abs(acceleration.y) >= 0)
				{
					acceleration.y -= acceleration.y / 100;
				}
			}
		}
		else
		{
			acceleration += {-acceleration.x / 100, -acceleration.y / 100};
			m_owner->GetTransform().AddTranslation(acceleration);
			m_owner->GetMesh().Get_Is_Moved() = true;
		}
	}

    if (input.Is_Key_Pressed(GLFW_KEY_W))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-max_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-max_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-min_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-min_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_W) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {min_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {min_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {max_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {max_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (abs(acceleration.x) >= 0)
            {
                acceleration.x -= acceleration.x / 50;
            }
            if (acceleration.y >= 0)
            {
                acceleration += {0.00, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.y < 0)
            {
                acceleration += {0.00, max_accel};
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
                acceleration += {-max_accel, min_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-max_accel, max_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-min_accel, min_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-min_accel, max_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_A) && input.Is_Key_Pressed(GLFW_KEY_S))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-max_accel, -max_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-max_accel, -min_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-min_accel, -max_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-min_accel, -min_accel / 2};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += -max_accel;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += -min_accel;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            if (abs(acceleration.y) >= 0)
            {
                acceleration.y -= acceleration.y / 50;
            }
        }
    }
    else if (input.Is_Key_Pressed(GLFW_KEY_S))
    {
        if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_D))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {min_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {min_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {max_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {max_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }

        }
        else if (input.Is_Key_Pressed(GLFW_KEY_S) && input.Is_Key_Pressed(GLFW_KEY_A))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {-max_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {-max_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {-min_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {-min_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (abs(acceleration.x) >= 0)
            {
                acceleration.x -= acceleration.x / 50;
            }
            if (acceleration.y >= 0)
            {
                acceleration.y += -max_accel;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.y += -min_accel;
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
                acceleration += {min_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {min_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {max_accel / 2, -max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {max_accel / 2, -min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else if (input.Is_Key_Pressed(GLFW_KEY_D) && input.Is_Key_Pressed(GLFW_KEY_W))
        {
            if (acceleration.x >= 0 && acceleration.y >= 0)
            {
                acceleration += {min_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x >= 0 && acceleration.y < 0)
            {
                acceleration += {min_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else if (acceleration.x < 0 && acceleration.y >= 0)
            {
                acceleration += {max_accel / 2, min_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration += {max_accel / 2, max_accel};
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
        }
        else
        {
            if (acceleration.x >= 0)
            {
                acceleration.x += min_accel;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            else
            {
                acceleration.x += max_accel;
                m_owner->GetTransform().AddTranslation(acceleration);
                m_owner->GetMesh().Get_Is_Moved() = true;
            }
            if (abs(acceleration.y) >= 0)
            {
                acceleration.y -= acceleration.y / 50;
            }
        }
    }
    else
    {
        acceleration += {-acceleration.x / 100, -acceleration.y / 100};
        m_owner->GetTransform().AddTranslation(acceleration);
        m_owner->GetMesh().Get_Is_Moved() = true;
    }
}

void Physics::JustMove()
{
	acceleration += {-acceleration.x / 100, -acceleration.y / 100};
	m_owner->GetTransform().AddTranslation(acceleration);
	m_owner->GetMesh().Get_Is_Moved() = true;
}

void Physics::KnockBack(Object* object_1, Object* object_2)
{
	if (object_1->GetComponentByTemplate<Physics>() != nullptr && object_2->GetComponentByTemplate<Physics>() != nullptr)
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
}

void Physics::Dash(Object* object)
{
    vector2 acceleration = object->GetComponentByTemplate<Physics>()->GetAcceleration();
    acceleration = normalize(acceleration);

	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

	if (present)
	{
		int axesCount;
		const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);

		if (axes[5] > 0)
		{
			timer = 0;
			acceleration += {25 * acceleration.x, 25 * acceleration.y};
			object->GetComponentByTemplate<Physics>()->SetAcceleration(acceleration);
            object->GetMesh().Get_Is_Moved() = true;

			is_dashed = false;
		}
	}
    if (input.Is_Key_Pressed(GLFW_KEY_SPACE))
    {
        timer = 0;
        acceleration += {25 * acceleration.x, 25 * acceleration.y};
        object->GetComponentByTemplate<Physics>()->SetAcceleration(acceleration);
        object->GetMesh().Get_Is_Moved() = true;

        is_dashed = true;
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
	else if (input.Is_Key_Pressed(GLFW_KEY_A))
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
	else if (input.Is_Key_Pressed(GLFW_KEY_S))
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
	else if (input.Is_Key_Pressed(GLFW_KEY_D))
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

	int status = glfwJoystickPresent(GLFW_JOYSTICK_1);

	if (status == true)
	{
		int axesCount;
		const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);

		if (axes[1] < 0)
		{
			if (axes[1] < 0 && axes[0] < 0)
			{
				velocity = { -1, 1 };
				m_owner->GetTransform().AddTranslation(velocity);
				m_owner->GetMesh().Get_Is_Moved() = true;
			}
			else if (axes[1] < 0 && axes[0] > 0)
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
		else if (axes[0] < 0)
		{
			if (axes[0] < 0 && axes[1] < 0)
			{
				velocity = { -1, 1 };
				m_owner->GetTransform().AddTranslation(velocity);
				m_owner->GetMesh().Get_Is_Moved() = true;
			}
			else if (axes[0] < 0 && axes[1] > 0)
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
		else if (axes[1] > 0)
		{
			if (axes[1] > 0 && axes[0] < 0)
			{
				velocity = { -1, -1 };
				m_owner->GetTransform().AddTranslation(velocity);
				m_owner->GetMesh().Get_Is_Moved() = true;
			}
			else if (axes[1] > 0 && axes[0] > 0)
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
		else if (axes[0] > 0)
		{
			if (axes[0] > 0 && axes[1] < 0)
			{
				velocity = { 1, 1 };
				m_owner->GetTransform().AddTranslation(velocity);
				m_owner->GetMesh().Get_Is_Moved() = true;
			}
			else if (axes[0] > 0 && axes[1] > 0)
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
}

void Physics::SpeedDown(Object* object)
{
    vector2 acceleration = object->GetComponentByTemplate<Physics>()->GetAcceleration();

    acceleration /= 5;

    object->GetComponentByTemplate<Physics>()->SetAcceleration(acceleration);
    object->GetMesh().Get_Is_Moved() = true;
}

void Physics::Update(float dt)
{
    timer += dt;

    if (m_owner->GetName() == "first")
    {
        Acceleration(0.3, 0.06);

        if (is_dashed == false && timer >= 0.3)
        {
            Dash(m_owner);
        }
        else if(is_dashed == true && timer >= 0.1)
        {
            SpeedDown(m_owner);
            is_dashed = false;
        }
    }
    else
    {
        JustMove();
    }
}

