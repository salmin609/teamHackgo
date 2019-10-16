#pragma once

#include "Component.hpp"
#include "Mesh.hpp"

class Physics : public Component
{
public:
    void Init(Object *obj) override;
    void Acceleration();
    void Acceleration2();
    void JustMove();
    void KnockBack(Object* object_1, Object* object_2);
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
	vector2 &GetAcceleration_Reference() 
	{
		return acceleration;
	}
      
private:
    std::vector<vector2> points{};
    vector2 acceleration{};
    vector2 velocity{};
    float timer = 0;
    vector2 prev_pos;
    vector2 direction_vector{};
};
