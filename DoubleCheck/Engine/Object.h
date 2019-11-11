#pragma once
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Component.hpp"
#include <string>
#include "Object_Component_Info.h"
#include "Physics.h"
#include <iostream>

inline int object_id_increment = 1;

class Object
{
private:
    Transform m_transform;
    Mesh m_mesh;
    Mesh m_debug_mesh;

    std::vector<Component*>components_;
    bool is_dead{};
    std::string m_name;
    vector2 center_pos;
    std::vector<vector2> object_points;
    std::vector<vector2> normalize_points;
    int m_id;
    bool need_change_translation = false;
    vector2 convert_translation;
    Object_Component_Info component_info;
    
    //IMGUI
    bool is_selected = false;
    std::string tag;
    bool need_update_points = false;
    bool is_debug_mode = true;
	std::string m_path;
    
    

public:
    Object_Component_Info& Get_Component_Info_Reference()
    {
        return component_info;
    }
	void Set_path(std::string path)
	{
		m_path = path;
	}

	std::string Get_Path()
    {
		return m_path;
    }

    std::string Get_Tag()
    {
        return tag;
    }
    void Set_Tag(std::string tag)
    {
        this->tag = tag;
    }
    std::vector<vector2>& Get_Normalize_Points()
    {
        return normalize_points;
    }
    void Set_Need_Update_Points(bool toggle)
    {
        need_update_points = toggle;
    }
    bool Get_Need_Update_Points()
    {
        return need_update_points;
    }
    vector2 Get_Center()
    {
        return center_pos;
    }
    void Set_Center(vector2 new_center)
    {
        center_pos = new_center;
    }
    Object() : component_info(this)
    {
        tag = "none";
        m_id = object_id_increment;
        object_id_increment++;
    }
    Transform& GetTransform() { return m_transform; }
    Transform GetTransform_Value() { return m_transform; }
    std::vector<Component*>GetComponentContainer() { return components_; }
    std::vector<vector2>& Get_Object_Points()
    {
        return object_points;
    }
    std::vector<vector2> Get_Object_Points_Value()
    {
        return object_points;
    }
    void Set_Object_Point(int index, vector2 value)
    {
        object_points[index] = value;
    }

    Mesh& GetMesh() { return m_mesh; }
    Mesh& Get_Debug_Mesh()
    {
        return m_debug_mesh;
    }
    bool& Get_Is_Need_Convert_Translation()
    {
        return need_change_translation;
    }
    vector2& Get_Convert_Translation()
    {
        return convert_translation;
    }

    template <typename COMPONENT>
    COMPONENT* GetComponentByTemplate() const;

    void Set_Name(std::string name)
    {
        m_name = name;
    }
    std::string Get_Name()
    {
        return m_name;
    }
    void Set_Id(int id)
    {
        m_id = id;
    }
    int Get_Id()
    {
        return m_id;
    }
    vector2 GetScale() const
    {
        return m_transform.GetScale();
    }

    //IMGUI
    bool& Get_Is_Selected()
    {
        return is_selected;
    }
    bool& Get_Is_Debugmode()
    {
        return is_debug_mode;
    }
    

    char name_buf[64];

public:
    void SetDeadCondition(bool condition) { is_dead = condition; }
    bool IsDead() { return is_dead; }
    void AddComponent(Component* comp);
    void DeleteComponent(Component* comp);

    void SetTranslation(vector2 pos);
	
    void SetRotation(float angle);
    void SetScale(vector2 scale);
    void SetScale(float scale);
    void SetDepth(float depth);
    void SetMesh(Mesh mesh);
    void Set_Debug_Mesh(Mesh mesh);
    std::string GetName();

    /*bool IsDead()
    {
        return is_dead;
    }*/
};

template <typename COMPONENT>
COMPONENT* Object::GetComponentByTemplate() const
{
    for(auto i : components_)
    {
        if(typeid(COMPONENT) == typeid(*i))
        {
            return dynamic_cast<COMPONENT*>(i);
        }
    }

    return nullptr;
}