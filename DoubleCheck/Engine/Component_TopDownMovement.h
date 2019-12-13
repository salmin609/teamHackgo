
/*
 * Author		:sangmin.kim
 * File			:Component_TopDownMovement.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:header file for Component_TopDownMovement.cpp
 *
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */

#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include <iostream>
#include "Object.h"
#include "Input.h"

class Component_TopDownMovement : public Component
{
public:
    void Init(Object *obj) override;
    void Update(float dt) override;
private:
};