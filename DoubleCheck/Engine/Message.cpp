#include "Message.h"
#include "Component_Player.h"
#include "Component_Sprite.h"
#include "Component_Enemy.h"
#include "Message_Manager.h"
#include "Component_Hpbar.h"
#include "Referee.h"
#include "Component_Item.h"
#include "Player_Ui.h"

std::pair<float, float> Message::Damaege_Calculation(Object target, Object from)
{
	//(+,+)
	//(+,+)
	//(-,-)
	//(-,-)
	Physics* target_physics = target.GetComponentByTemplate<Physics>();
	Physics* from_physics = from.GetComponentByTemplate<Physics>();
	vector2 target_pos = target.GetTransform().GetTranslation();
	vector2 from_pos = from.GetTransform().GetTranslation();

	bool same_direction_x = false;
	bool same_direction_y = false;

	same_direction_x = (target_physics->GetAcceleration().x < 0 && from_physics->GetAcceleration().x < 0);
	same_direction_x |= (target_physics->GetAcceleration().x > 0 && from_physics->GetAcceleration().x > 0);
	same_direction_y = (target_physics->GetAcceleration().y < 0 && from_physics->GetAcceleration().y < 0);
	same_direction_y |= (target_physics->GetAcceleration().y > 0 && from_physics->GetAcceleration().y > 0);


	//both directions are same.
	if (same_direction_x && same_direction_y)
	{
		//if the positive.
		if (target_physics->GetAcceleration().x > 0)
		{
			if (target_pos.x > from_pos.x&& target_pos.y > from_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.x > target_pos.x&& from_pos.y > target_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}

			float target_dmg = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
				(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
			float from_dmg = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
				(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));

			return std::pair<float, float> {target_dmg, from_dmg};
		}
		if (target_physics->GetAcceleration().x < 0)
		{
			if (target_pos.x < from_pos.x && target_pos.y < from_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.x < target_pos.x && from_pos.y < target_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}

			float target_dmg = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
				(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
			float from_dmg = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
				(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));

			return std::pair<float, float> {target_dmg, from_dmg};
		}
	}
	else if (same_direction_x)
	{
		if (target_physics->GetAcceleration().x > 0)
		{
			if (target_pos.x > from_pos.x)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.x > target_pos.x)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}
		}
		if (target_physics->GetAcceleration().x < 0)
		{
			if (target_pos.x < from_pos.x)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.x < target_pos.x)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}
		}
		float target_dmg = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
			(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
		float from_dmg = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
			(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));

		return std::pair<float, float> {target_dmg, from_dmg};
	}
	else if (same_direction_y)
	{
		if (target_physics->GetAcceleration().y > 0)
		{
			if (target_pos.y > from_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.y > target_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}
		}
		if (target_physics->GetAcceleration().y < 0)
		{
			if (target_pos.y < from_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.first = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
					(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
				dmg.second = 0;
				return dmg;
			}
			if (from_pos.y < target_pos.y)
			{
				std::pair<float, float> dmg;
				dmg.second = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
					(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));
				dmg.first = 0;
				return dmg;
			}
		}
		float target_dmg = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
			(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
		float from_dmg = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
			(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));

		return std::pair<float, float> {target_dmg, from_dmg};
	}
	else
	{
		float target_dmg = (sqrt((from_physics->Get_Save_Acceleration_Reference().x * from_physics->Get_Save_Acceleration_Reference().x) +
			(from_physics->Get_Save_Acceleration_Reference().y * from_physics->Get_Save_Acceleration_Reference().y)));
		float from_dmg = (sqrt((target_physics->Get_Save_Acceleration_Reference().x * target_physics->Get_Save_Acceleration_Reference().x) +
			(target_physics->Get_Save_Acceleration_Reference().y * target_physics->Get_Save_Acceleration_Reference().y)));

		return std::pair<float, float> {target_dmg, from_dmg};
	}

}

void Message::Init()
{
}

void Message::Update(float dt)
{
	if (message_name == "attack")
	{
		m_target->GetComponentByTemplate<Component_Enemy>()->Decrease_HP(m_from->GetComponentByTemplate<Player>()->Get_Damage());
	}
	else if (message_name == "wall_collision")
	{
		if (m_target->GetComponentByTemplate<Player>() != nullptr)
		{
			Object* target_hp_bar = m_target->Get_Belong_Object_By_Tag("hp_bar");
			if (target_hp_bar != nullptr)
			{
				if (target_hp_bar->GetComponentByTemplate<Hp_Bar>() != nullptr)
				{
					float damage_to_target = 0;
					Physics* temp_physics = m_target->GetComponentByTemplate<Physics>();
					damage_to_target += (sqrt((temp_physics->Get_Save_Acceleration_Reference().x * temp_physics->Get_Save_Acceleration_Reference().x) +
						(temp_physics->Get_Save_Acceleration_Reference().y * temp_physics->Get_Save_Acceleration_Reference().y)));

					std::cout << "damage from wall : " << damage_to_target << std::endl;

					target_hp_bar->GetComponentByTemplate<Hp_Bar>()->Decrease(damage_to_target / 200);
				}
			}
		}
	}
	if (message_name == "collision")
	{
		if (m_target->Get_Tag() == "item" && m_from->Get_Tag() == "player")
		{
			std::cout << "item" << std::endl;
			if (m_target->GetComponentByTemplate<Item>()->Get_Kind() == Item::Item_Kind::Dash)
			{
				m_target->SetDeadCondition(true);
				if (m_from->GetComponentByTemplate<Player>() != nullptr)
				{
					m_from->GetComponentByTemplate<Player>()->Set_Item_State(Item::Item_Kind::Dash);
					m_from->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()
						->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
					m_from->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()->GetMesh().Get_Is_Moved() = true;
				}
			}
			if (m_target->GetComponentByTemplate<Item>()->Get_Kind() == Item::Item_Kind::HP)
			{
				m_target->SetDeadCondition(true);
				if (m_from->GetComponentByTemplate<Player>() != nullptr)
				{
					m_from->GetComponentByTemplate<Player>()->Set_Item_State(Item::Item_Kind::HP);
					m_from->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()
						->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
					m_from->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()->GetMesh().Get_Is_Moved() = true;
				}
			}
			
		}
		else if (m_from->Get_Tag() == "item" && m_target->Get_Tag() == "player")
		{
			if (m_from->GetComponentByTemplate<Item>()->Get_Kind() == Item::Item_Kind::Dash)
			{
				m_from->SetDeadCondition(true);
				if (m_target->GetComponentByTemplate<Player>() != nullptr)
				{
					m_target->GetComponentByTemplate<Player>()->Set_Item_State(Item::Item_Kind::Dash);

					m_target->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()
						->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
					m_target->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()->GetMesh().Get_Is_Moved() = true;
				}
			}
			if (m_from->GetComponentByTemplate<Item>()->Get_Kind() == Item::Item_Kind::HP)
			{
				m_from->SetDeadCondition(true);
				if (m_target->GetComponentByTemplate<Player>() != nullptr)
				{
					m_target->GetComponentByTemplate<Player>()->Set_Item_State(Item::Item_Kind::HP);

					m_target->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()
						->GetComponentByTemplate<Sprite>()->Get_Material().color4fUniforms["color"] = { 1.0f,1.0f,1.0f,1.0f };
					m_target->GetComponentByTemplate<Player>()->Get_Ui()->Get_Item_Info()->GetMesh().Get_Is_Moved() = true;
				}
			}
		}

		else
		{
			std::pair<float, float> dmg_set = Damaege_Calculation(*m_target, *m_from);
			if (m_from->GetComponentByTemplate<Player>() != nullptr)
			{
				m_target->Set_Hitted_By(m_from);
			}

			if (m_target->GetComponentByTemplate<Player>() != nullptr)
			{
				m_from->Set_Hitted_By(m_target);
			}
			Object* target_hp_bar = m_target->Get_Belong_Object_By_Tag("hp_bar");
			Object* from_hp_bar = m_from->Get_Belong_Object_By_Tag("hp_bar");

			if(target_hp_bar != nullptr || from_hp_bar != nullptr)
			{
				target_hp_bar->GetComponentByTemplate<Hp_Bar>()->Decrease(dmg_set.first / 50);
				from_hp_bar->GetComponentByTemplate<Hp_Bar>()->Decrease(dmg_set.second / 50);
			}
		}
	}
	if (message_name == "respawn")
	{
		if (m_from->GetName() == "second")
		{
			Referee::Get_Referee()->Get_Stage_Statement().push_back(Referee::PLAYER_SECOND_DIE);
		}
		if (m_from->GetName() == "first")
		{
			Referee::Get_Referee()->Get_Stage_Statement().push_back(Referee::PLAYER_FIRST_DIE);
		}
		if (m_from->GetName() == "third")
		{
			Referee::Get_Referee()->Get_Stage_Statement().push_back(Referee::PLAYER_THIRD_DIE);
		}
		if (m_from->GetName() == "forth")
		{
			Referee::Get_Referee()->Get_Stage_Statement().push_back(Referee::PLAYER_FOURTH_DIE);
		}
	}
	if (m_from != nullptr && m_target != nullptr)
	{
		std::string log = m_from->Get_Name() + " " + message_name + " " + m_target->Get_Name();

		Message_Manager::Get_Message_Manager()->Get_Log().push_back(log);
	}




	should_delete = true;
}

void Message::Delete()
{
}
