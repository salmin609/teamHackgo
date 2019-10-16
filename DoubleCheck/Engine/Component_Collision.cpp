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
    //std::vector<Object> objects;
    //std::vector<vector2> objects_position;
    //std::vector<float> objects_radius;
    bool if_it_is_collide = false;

    //for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
    //{
    //    objects.push_back(*i.get());
    //    objects_position.push_back(i.get()->GetTransform().GetTranslation());
    //    objects_radius.push_back(i.get()->GetTransform().GetScale().x * 100.f);
    //}

    unsigned int object_position_size = ObjectManager::GetObjectManager()->GetObjectManagerContainer().size();

    //for (unsigned int i = 0; i < objects_position.size(); ++i)
    for (unsigned int i = 0; i < object_position_size; ++i)
    {
        Object* obj_i = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[i].get();
        vector2 obj_i_trans = obj_i->GetTransform().GetTranslation();
        float obj_i_radius = obj_i->GetTransform().GetScale().x * 100.f;

        //for (unsigned int j = 0; j < objects_position.size(); ++j)
        for (unsigned int j = 0; j < object_position_size; ++j)
        {
            Object* obj_j = ObjectManager::GetObjectManager()->GetObjectManagerContainer()[j].get();
            vector2 obj_j_trans = obj_j->GetTransform().GetTranslation();
            float obj_j_radius = obj_j->GetTransform().GetScale().x * 100.f;
            if (i != j)
            {
                //const float distance = sqrt((objects_position[i].x - objects_position[j].x) * (objects_position[i].x - objects_position[j].x) + (objects_position[i].y - objects_position[j].y) * (objects_position[i].y - objects_position[j].y));
                const float distance = sqrt((obj_i_trans.x - obj_j_trans.x) * (obj_i_trans.x - obj_j_trans.x) + (obj_i_trans.y - obj_j_trans.y) * (obj_i_trans.y - obj_j_trans.y));

                if (distance <= obj_i_radius + obj_j_radius)
                {
                    if_it_is_collide = true;
                    physics.KnockBack(obj_i, obj_j);
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