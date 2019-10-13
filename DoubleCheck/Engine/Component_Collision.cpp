#include "Component_Collision.h"
#include "Physics.h"
#include "Object.h"
#include "ObjectManager.h"

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

    for (const auto& i : ObjectManager::GetObjectManager()->GetObjectManagerContainer())
    {
        objects.push_back(*i.get());
        objects_position.push_back(i.get()->GetTransform().GetTranslation());
        objects_radius.push_back(i.get()->GetTransform().GetScale().x * 100.f);
    }

    for (unsigned int i = 0; i < objects_position.size() - 1; ++i)
    {
        const float distance = sqrt((objects_position[i].x - objects_position[i + 1].x) * (objects_position[i].x - objects_position[i + 1].x) + (objects_position[i].y - objects_position[i + 1].y) * (objects_position[i].y - objects_position[i + 1].y));

        if (distance <= objects_radius[i] + objects_radius[i + 1])
        {
            physics.KnockBack(&objects[i], &objects[i + 1]);
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void Collision::Update(float dt)
{
    timer += dt;

        if (CircleToCircleCollision() == true)
        {
            printf("Collision Sex!");
            timer = 0;
        }
}