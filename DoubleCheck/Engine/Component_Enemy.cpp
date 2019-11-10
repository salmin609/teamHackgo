#include "Component_Enemy.h"

void Component_Enemy::Init(Object* obj)
{

    m_owner = obj;
}

void Component_Enemy::Update(float dt)
{
    if(hp <= 0)
    {

        m_owner->SetDeadCondition(true);
    }
}

void Component_Enemy::Decrease_HP(int dmg)
{
    hp -= dmg;

}
