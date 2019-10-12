#include "Component_Enemy.h"

void Component_Enemy::Init(Object* obj)
{
    std::cout << "Component_Enemy_Init" << std::endl;
    m_owner = obj;
}

void Component_Enemy::Update(float dt)
{
    if(hp <= 0)
    {
        std::cout << "die" << std::endl;
        m_owner->SetDeadCondition(true);
    }
}

void Component_Enemy::Decrease_HP(int dmg)
{
    hp -= dmg;
    std::cout << "Enemy : " << m_owner->Get_Id() << std::endl;
    std::cout << "Current HP: " << hp << std::endl;
    std::cout << std::endl;
}
