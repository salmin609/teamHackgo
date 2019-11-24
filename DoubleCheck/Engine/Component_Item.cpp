#include "Component_Item.h"


void Item::Init(Object* obj)
{

}

void Item::Update(float dt)
{

}

void Item::Set_Kind(Item_Kind kind)
{
	this->this_kind = kind;
}

Item::Item_Kind Item::Get_Kind()
{
	return this_kind;
}
