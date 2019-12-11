#pragma once
#include "vector2.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Object.h"
#include <functional>
#include "Component_Sprite.h"
#include "Physics.h"


class Message
{
private:
	std::string message_name;
	Object* m_target = nullptr;
	Object* m_from = nullptr;
	bool should_delete = false;
	float timer = 1.f;

	Object* dash_effect = nullptr;

public:
	Message(Object* target, Object* from, std::string message_name_) :
		m_target(target), m_from(from), message_name(message_name_) {}

	Message(Object* target, Object* from, std::string message_name_, float timer) :
		m_target(target), m_from(from), message_name(message_name_), timer(timer)
	{
	}


	bool Get_Should_Delete()
	{
		return should_delete;
	}
	std::pair<float, float> Damaege_Calculation(Object target, Object from);
	void Init();
	void Update(float dt);
	void Delete();
};
