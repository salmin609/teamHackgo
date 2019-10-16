#include "Component_Collision.h"
#include "Physics.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Engine.hpp"

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
    std::vector<Object> objects;
    std::vector<vector2> objects_position;
    std::vector<float> objects_radius;
    bool if_it_is_collide = false;

    for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
    {
        objects.push_back(*i.get());
        objects_position.push_back(i.get()->GetTransform().GetTranslation());
        objects_radius.push_back(i.get()->GetTransform().GetScale().x * 100.f);
    }

    for (unsigned int i = 0; i < objects_position.size(); ++i)
    {
        for (unsigned int j = 0; j < objects_position.size(); ++j)
        {
            if (i != j)
            {
                const float distance = sqrt((objects_position[i].x - objects_position[j].x) * (objects_position[i].x - objects_position[j].x) + (objects_position[i].y - objects_position[j].y) * (objects_position[i].y - objects_position[j].y));

                if (distance <= objects_radius[i] + objects_radius[j])
                {
                    if_it_is_collide = true;
                    physics.KnockBack(&objects[i], &objects[j]);
                }
            }
        }
    }
    return if_it_is_collide;
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
}