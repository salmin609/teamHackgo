#pragma once
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Component.hpp"/
#include <string>
#include <iostream>

inline int object_id_increment = 1;

class Object
{
private:
    Transform m_transform;
    Mesh m_mesh;
    std::vector<Component*>components_;
    bool is_dead{};
    std::string m_name;
    vector2 center_pos;
    std::vector<vector2> object_points;
    int m_id;
    //IMGUI
    bool is_selected = false;
    

public:
    vector2 Get_Center()
    {
        return center_pos;
    }
    void Set_Center(vector2 new_center)
    {
        center_pos = new_center;
    }
    Object()
    {
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