 #include <algorithm>
#include "Object.h"

void Object::AddComponent(Component* comp)
{
    comp->Init(this);
    components_.push_back(comp);
}


void Object::DeleteComponent(Component* comp)
{
	Component* for_erase = comp;
    components_.erase(std::find(components_.begin(), components_.end(), comp));
	delete for_erase;
}

void Object::SetTranslation(vector2 pos)
{
    m_transform.SetTranslation(pos);
}

void Object::SetRotation(float angle)
{
    m_transform.SetRotation(angle);
}

void Object::SetScale(vector2 scale)
{
    m_transform.SetScale(scale);
}

void Object::SetScale(float scale)
{
    m_transform.SetScale(scale);
}

void Object::SetDepth(float depth)
{
    m_transform.SetDepth(depth);
}

void Object::SetMesh(Mesh mesh)
{
    m_mesh = mesh;
}

void Object::Set_Debug_Mesh(Mesh mesh)
{
    m_debug_mesh = mesh;
}

std::string Object::GetName()
{
    return m_name;
}

bool Object::Get_Need_To_Update()
{
    return need_to_update;
}

Object* Object::Get_Belong_Object_By_Name(std::string name)
{
    if(!belongs_object.empty())
    {
        for(Object* obj : belongs_object)
        {
            if(obj->GetName() == name)
            {
                return obj;
            }
        }
    }
    return nullptr;
}

Object* Object::Get_Belong_Object_By_Tag(std::string tag)
{
    if (!belongs_object.empty())
    {
        for (Object* obj : belongs_object)
        {
            if (obj->Get_Tag() == tag)
            {
                return obj;
            }
        }
    }
    return nullptr;
}
