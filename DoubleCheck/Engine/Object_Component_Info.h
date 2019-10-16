#pragma once

class Object;

class Object_Component_Info
{
public:
    Object_Component_Info(Object* obj);


    Object* m_owner;
    bool component_info_player;
    bool component_info_enemy;
    bool component_info_physics;
    bool component_info_collision;
    bool component_info_sprite;
    bool component_info_top_down_movement;

private:



};