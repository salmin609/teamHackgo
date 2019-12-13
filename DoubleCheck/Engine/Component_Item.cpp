
/*
 * Author		:suhwan.kim
 * File			:Component_Item.cpp
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Basic ai movement for item object is implemented in here.
 */
#include "Component_Item.h"
#include "time.h"
#include "Object.h"

void Item::Init(Object* obj)
{
	m_owner = obj;
}

void Item::Update(float dt)
{
	srand(time(NULL));
	int random = rand() % 8;

	switch(random)
	{
	case 0:
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().x += 0.1f;
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().y += 0.1f;
		break;

	case 1:
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().x -= 0.1f;
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().y += 0.1f;
		break;

	case 2:

		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().x += 0.1f;
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().y -= 0.1f;
		break;

	case 3:

		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().x -= 0.1f;
		m_owner->GetComponentByTemplate<Physics>()->GetAcceleration_Reference().y -= 0.1f;
		break;
	}
}

void Item::Set_Kind(Item_Kind kind)
{
	this->this_kind = kind;
}

Item::Item_Kind Item::Get_Kind()
{
	return this_kind;
}
