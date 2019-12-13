
/*
 * Author		:chulseung.lee
 * File			:Component_Collision.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:header file for Component_Collision.cpp.
 */

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
