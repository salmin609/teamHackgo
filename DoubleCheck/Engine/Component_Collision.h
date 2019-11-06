#pragma once

#include "Component.hpp"
#include "Mesh.hpp"
#include "Physics.h"

class Collision : public Component
{
public:
    void Init(Object *obj) override;
    bool BoxToBoxCollision(Mesh mesh) const;
    bool CircleToCircleCollision();
    void Update(float dt) override;
    void CircleArenaCollision();
    void SquareArenaCollision();
private:
    Physics physics;
    float timer = 0;
};
