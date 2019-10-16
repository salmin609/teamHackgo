#include "Object_Component_Info.h"

Object_Component_Info::Object_Component_Info(Object* obj)
{
    m_owner = obj;

    component_info_player = false;
    component_info_enemy = false;
    component_info_physics = false;
    component_info_collision = false;
    component_info_sprite = false;
    component_info_top_down_movement = false;
}
