#include "Component_Collision.h"
#include "Physics.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Engine.hpp"
#include "Component_Hpbar.h"
#include "Message_Manager.h"

#define  PI  3.14159265359
float RadianToDegree(float radian)
{
	float degree = radian * (180 / PI);

	return degree;
}

float DegreeToRadian(float degree)
{
	float radian = degree * (PI / 180);

	return radian;
}
void Collision::Init(Object* obj)
{
	m_owner = obj;
}

bool Collision::BoxToBoxCollision(Mesh mesh) const
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

bool Collision::CircleToCircleCollision()
{
    bool if_it_is_collide = false;
    unsigned int object_position_size = ObjectManager::GetObjectManager()->GetObjectManagerContainer().size();

    for (unsigned int i = 0; i < object_position_size; ++i)
    {
        Object* obj_i = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[i].get();
        if (obj_i->Get_Need_To_Update())
        {
            vector2 obj_i_trans = obj_i->GetTransform().GetTranslation();
            float obj_i_radius = obj_i->GetTransform().GetScale().x * 70.f;

            for (unsigned int j = 0; j < object_position_size; ++j)
            {
                Object* obj_j = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[j].get();
                if (obj_j->Get_Need_To_Update())
                {
                    vector2 obj_j_trans = obj_j->GetTransform().GetTranslation();
                    float obj_j_radius = obj_j->GetTransform().GetScale().x * 70.f;
                    if (i != j)
                    {
                        const float distance = sqrt((obj_i_trans.x - obj_j_trans.x) * (obj_i_trans.x - obj_j_trans.x) + (obj_i_trans.y - obj_j_trans.y) * (obj_i_trans.y - obj_j_trans.y));

                        if (distance <= obj_i_radius + obj_j_radius)
                        {
                            if_it_is_collide = true;
                            if (obj_i->GetComponentByTemplate<Physics>() != nullptr && obj_j->GetComponentByTemplate<Physics>() != nullptr)
                            {
                                obj_i->GetComponentByTemplate<Physics>()->Get_Save_Acceleration_Reference().x = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration().x;
                                obj_i->GetComponentByTemplate<Physics>()->Get_Save_Acceleration_Reference().y = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration().y;
                                obj_j->GetComponentByTemplate<Physics>()->Get_Save_Acceleration_Reference().x = obj_j->GetComponentByTemplate<Physics>()->GetAcceleration().x;
                                obj_j->GetComponentByTemplate<Physics>()->Get_Save_Acceleration_Reference().y = obj_j->GetComponentByTemplate<Physics>()->GetAcceleration().y;
                            }
                            physics.KnockBack(obj_i, obj_j);

                            Message_Manager::Get_Message_Manager()->Save_Message(new Message(obj_j, obj_i, "collision"));
                        }
                    }
                }
            }
        }
    }
    return if_it_is_collide;
}

void Collision::CircleArenaCollision()
{
	const unsigned int object_position_size = ObjectManager::GetObjectManager()->GetObjectManagerContainer().size();

	for (unsigned int i = 0; i < object_position_size; ++i)
	{
		Object* obj_i = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[i].get();
		vector2 obj_i_trans = obj_i->GetTransform().GetTranslation();

		const float distance = sqrt((obj_i_trans.x * obj_i_trans.x) + (obj_i_trans.y * obj_i_trans.y));

		if (distance >= 10000)
		{
			const vector2 direction_to_go = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration();
			obj_i->GetComponentByTemplate<Physics>()->SetAcceleration(-direction_to_go);
		}
	}
}

void Collision::SquareArenaCollision()
{
	const unsigned int object_position_size = ObjectManager::GetObjectManager()->GetObjectManagerContainer().size();
	const float line_max_point = 5000;
	const float line_min_point = -5000;
	float angle = 0;
	float angle2 = 0;
	for (unsigned int i = 0; i < object_position_size; ++i)
	{
		Object* obj_i = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[i].get();
		vector2 obj_i_trans = obj_i->GetTransform().GetTranslation();

		const float max_x = obj_i_trans.x + 70.0;
		const float min_x = obj_i_trans.x - 70.0;
		const float max_y = obj_i_trans.y + 70.0;
		const float min_y = obj_i_trans.y - 70.0;

		if (line_max_point - max_x <= 0)
		{
			vector2 direction_to_go = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration();

			angle = RadianToDegree(angle_between({ 0,1 }, direction_to_go));
			angle2 = 2 * (180 - angle);
			angle = 360 - angle2;
			direction_to_go = rotate_by(DegreeToRadian(angle), direction_to_go);
			obj_i->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go);
		}
		else if (line_max_point - max_y <= 0)
		{
			vector2 direction_to_go = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration();
			angle = RadianToDegree(angle_between({ -1,0 }, direction_to_go));

			angle2 = 2 * (180 - angle);
			angle = 360 - angle2;
			direction_to_go = rotate_by(DegreeToRadian(angle), direction_to_go);
			obj_i->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go);
		}
		else if (line_min_point - min_x >= 0)
		{
			vector2 direction_to_go = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration();
			angle = RadianToDegree(angle_between({ 0,-1 }, direction_to_go));

			angle2 = 2 * (180 - angle);
			angle = 360 - angle2;
			direction_to_go = rotate_by(DegreeToRadian(angle), direction_to_go);
			obj_i->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go);
		}
		else if (line_min_point - min_y >= 0)
		{
			vector2 direction_to_go = obj_i->GetComponentByTemplate<Physics>()->GetAcceleration();
			angle = RadianToDegree(angle_between({ 1,0 }, direction_to_go));

			angle2 = 2 * (180 - angle);
			angle = 360 - angle2;
			direction_to_go = rotate_by(DegreeToRadian(angle), direction_to_go);
			obj_i->GetComponentByTemplate<Physics>()->SetAcceleration(direction_to_go);
		}
	}
}

void Collision::Update(float dt)
{
	sound_timer += dt;

	if (CircleToCircleCollision() == true && sound_timer >= 0.2)
	{
		sound.play(1);
		sound.volume(1, 1);
		sound_timer = 0;
	}
	SquareArenaCollision();
}
