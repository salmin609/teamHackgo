#pragma once

#include "Component.hpp"
#include "Object.h"
#include "Mesh.hpp"
#include "Sound_Manager.h"

class Physics : public Component
{
public:
    void Init(Object *obj) override;
    void Acceleration();
    void Acceleration2();
    bool BoxToBoxCollision(Mesh mesh) const;
    bool CircleToCircleCollision(Object* object) const;
    void KnockBack(Object* object);
    void BasicMovement();
    void BasicMovement2();
    void Update(float dt) override;

    void SetAcceleration(vector2 accel)
    {
        acceleration = accel;
    }
    vector2 GetAcceleration() const
    {
        return acceleration;
    }
      
private:
    std::vector<vector2> points{};
    vector2 acceleration{};
    vector2 velocity{};
    float timer = 0;
};
