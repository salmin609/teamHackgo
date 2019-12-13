
/*
 * Author		:sangmin.kim
 * File			:Component_Transform.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Header file for Component_Transform.cpp.
 *
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */

#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include <iostream>
#include "Object.h"

class Component_Transform : public Component
{
public:  
    void Init(Object *obj) override;
    void Update(float dt) override;
};