#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Object.h"
#include <functional>


class Message
{
private:
    std::string message_name;
    Object* m_target = nullptr;
    Object* m_from = nullptr;
    bool should_delete = false;

public:
    Message(Object* target, Object* from, std::string message_name_) : 
    m_target(target), m_from(from), message_name(message_name_) {}

    bool Get_Should_Delete()
    {
        return should_delete;
    }
    void Init();
    void Update(float dt);
    void Delete();
};
