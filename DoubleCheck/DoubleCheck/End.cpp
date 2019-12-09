//#include "MainMenu.h"
//#include "Input.h"
//#include "ObjectManager.h"
//#include "Component_Text.h"
//#include "StateManager.h"
//#include "Object.h"
//#include "Transform.hpp"
//#include <iostream>
//namespace
//{
//	ObjectManager* object_manager = nullptr;
//	StateManager* state_manager = nullptr;
//	//State* state = nullptr;
//}
//
//void MainMenu::Load()
//{
//	state_manager = StateManager::GetStateManager();
//	object_manager = ObjectManager::GetObjectManager();
//
//	Graphic::GetGraphic()->Get_View().Get_Camera_View().SetZoom(0.35f);
//	Graphic::GetGraphic()->get_need_update_sprite() = true; //draw picture(initialize)
//	button = new Object();
//	button->Set_Name("play_button");
//	button->Set_Tag("button");
//	button->AddComponent(new Sprite(button, "../Sprite/play_button.png", { 0, 0 }));
//	button->GetTransform().SetScale({ 3, 3 });
//	ObjectManager::GetObjectManager()->AddObject(button);
//
//	collision_button = new Object();
//	collision_button->Set_Name("collision_play_button");
//	collision_button->Set_Tag("collision_button");
//	collision_button->AddComponent(new Sprite(collision_button, "../Sprite/collision_play_button.png", { 0, 0 }));
//	collision_button->GetTransform().SetScale({ 3, 3 });
//}
//
//void MainMenu::Update(float dt)
//{
//	if (MouseCollision(vector2{ 54, 54 }, vector2{ -54, -54 },
//		vector2{ input.Get_Mouse_Pos().x, input.Get_Mouse_Pos().y }) == true)
//	{
//		//ObjectManager::GetObjectManager()->AddObject(collision_button);
//
//		if (input.Is_Mouse_Released(GLFW_MOUSE_BUTTON_LEFT))
//		{
//			is_next = true;
//			next_level = "Level1";
//			Clear();
//		}
//	}
//}
//
//bool MainMenu::MouseCollision(vector2 position_max, vector2 position_min, vector2 mouse_pos)
//{
//	if (mouse_pos.x < position_max.x && mouse_pos.x > position_min.x
//		&& mouse_pos.y < position_max.y && mouse_pos.y > position_min.y)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void MainMenu::Clear()
//{
//	button->SetDeadCondition(true);
//	collision_button->SetDeadCondition(true);
//}