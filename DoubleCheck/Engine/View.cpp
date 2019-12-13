/*
 * Author		:jeesoo.kim
 * File			:View.cpp
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:cpp file for view point of camera.
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */


#include "View.h"
#include <iostream>
#include "Input.h"
#include "Graphic.h"
#include "Application.hpp"

void View::Init()
{
	camera_view.SetViewSize(1280, 720);
	vector2 save_window_size = Application::Get_Application()->Get_Window_Size();
	ndc_matrix = MATRIX3::build_scale(save_window_size.x / 2, save_window_size.y / 2);
}

void View::Update(float dt)
{
	if (input.Mouse_Wheel_Scroll() < 0)
	{
		camera_view.AddZoom(-0.05f);
		input.Set_Mouse_Wheel(0.0, 0.0);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}
	else if (input.Mouse_Wheel_Scroll() > 0)
	{
		camera_view.AddZoom(0.05f);
		input.Set_Mouse_Wheel(0.0, 0.0);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}

	if (input.Is_Key_Pressed(GLFW_KEY_RIGHT))
	{
		vector2 new_center = camera.GetCenter();
		new_center.x += 1.0f;
		camera.SetCenter(new_center);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}
	if (input.Is_Key_Pressed(GLFW_KEY_LEFT))
	{
		vector2 new_center = camera.GetCenter();
		new_center.x -= 1.0f;
		camera.SetCenter(new_center);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}
	if (input.Is_Key_Pressed(GLFW_KEY_DOWN))
	{
		vector2 new_center = camera.GetCenter();
		new_center.y -= 1.0f;
		camera.SetCenter(new_center);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}
	if (input.Is_Key_Pressed(GLFW_KEY_UP))
	{
		vector2 new_center = camera.GetCenter();
		new_center.y += 1.0f;
		camera.SetCenter(new_center);
		Graphic::GetGraphic()->get_need_update_sprite() = true;
	}
	//Convert_Cam_Zoom();
}

bool myfunction(int i, int j)
{
	return (i < j);
}

void View::Convert_Cam_Zoom()
{
	std::vector<Object*> player_vec = ObjectManager::GetObjectManager()->Find_Objects_By_Tag("player");

	float zoom = Graphic::GetGraphic()->Get_View().Get_Camera_View().GetZoom();
	const int player_vec_size = player_vec.size();

	for (int i = 0; i < player_vec_size; i++)
	{
		player_pos.push_back(player_vec[i]->GetTransform().GetTranslation());
		x_sorted.push_back(player_vec[i]->GetTransform().GetTranslation().x);
		y_sorted.push_back(player_vec[i]->GetTransform().GetTranslation().y);
	}

	std::sort(std::begin(x_sorted), std::end(x_sorted), myfunction);
	std::sort(std::begin(y_sorted), std::end(y_sorted), myfunction);

	vector2 smallest = { x_sorted.front(), y_sorted.front() };
	vector2 largest = { x_sorted.back(), y_sorted.back() };
	vector2 prev_distance = distance;

	if (largest.x >= 0 && smallest.x >= 0)
	{
		distance.x = (largest.x - smallest.x);
		center.x = largest.x - (distance.x / 2);
	}
	else if (largest.x >= 0 && smallest.x < 0)
	{
		distance.x = (abs(largest.x) + abs(smallest.x));
		center.x = largest.x - (distance.x / 2);
	}
	else
	{
		distance.x = (abs(smallest.x) - abs(largest.x));
		center.x = largest.x - (distance.x / 2);
	}

	if (largest.y >= 0 && smallest.y >= 0)
	{
		distance.y = (largest.y - smallest.y);
		center.y = largest.y - (distance.y / 2);
	}
	else if (largest.y >= 0 && smallest.y < 0)
	{
		distance.y = (abs(largest.y) + abs(smallest.y));
		center.y = largest.y - (distance.y / 2);
	}
	else
	{
		distance.y = (abs(smallest.y) - abs(largest.y));
		center.y = largest.y - (distance.y / 2);
	}

	if (zoom > 0.8)
	{
		zoom = 0.795f;
	}
	if (zoom < -0.2)
	{
		zoom = -0.15f;
	}

	if (zoom >= -0.2 && zoom <= 0.8 && (distance != prev_distance) && player_pos.size() != 1)
	{
		if (prev_distance.x < distance.x || prev_distance.y < distance.y)
		{
			camera_view.AddZoom(-0.002f);
			//camera.SetCenter(center);

		}
		if (prev_distance.x > distance.x || prev_distance.y > distance.y)
		{
			camera_view.AddZoom(0.002f);
			//camera.SetCenter(center);
		}
		if (prev_distance == distance)
		{
			//do nothing
		}
	}
	if (player_pos.size() == 1)
	{
		camera.SetCenter({ player_pos.front().x,  player_pos.front().y });
	}
	player_pos.clear();
	x_sorted.clear();
	y_sorted.clear();
}

