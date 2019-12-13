
/*
 * Author		:sangmin.kim
 * File			:ObjectManager.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:header file for ObjectManager.cpp
 */

#pragma once
#include <vector>
#include "Object.h"
#include <memory>
#include <unordered_map>

class ObjectManager
{
public:
    static ObjectManager* GetObjectManager();

    void Init();
    void Update(float dt);
    void Delete();
    void Clear();

    void AddObject(Object* obj);
    void DeleteObject(std::shared_ptr<Object> obj);

    std::vector<Object*> Find_Objects_By_Tag(std::string tag);
    Object* Find_Object_By_Name(std::string name);

    std::vector<std::shared_ptr<Object>>& GetObjectManagerContainer()
    {
        return objects;
    }
    std::vector<std::shared_ptr<Object>> GetObjectManagerContainer_Value()
    {
        return objects;
    }
private:
    static ObjectManager* object_manager;
    std::vector<std::shared_ptr<Object>> objects{};
    std::vector<std::shared_ptr<Object>> delete_obj{};
	
    //std::unordered_map<std::string, std::unique_ptr<Object>> objects{};
};