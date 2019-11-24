#pragma once

#include "Component.hpp"
#include "Mesh.hpp"

class Physics : public Component
{
public:
	Physics(bool ghost_collision_mode = false);
    void Init(Object *obj) override;
    void Acceleration(float max_accel, float min_accel);
    void JustMove();
    void KnockBack(Object* object_1, Object* object_2);
    void Dash(Object* object);
    void BasicMovement();
    void SpeedDown(Object* object);
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
    vector2& Get_Save_Acceleration_Reference()
    {
        return accel_save;
    }
	bool& Get_Ghost_Collision_Reference()
    {
		return ghost_collision_mode;
    }

    bool is_collided = false;
    bool is_dashed = false;
private:
    std::vector<vector2> points{};
    vector2 acceleration{};
    vector2 velocity{};
    mutable float timer = 0;
    vector2 prev_pos;
    vector2 direction_vector{};
    vector2 accel_save{};

	bool ghost_collision_mode;
	float ghost_collision_timer = 5.0f;
	
};
