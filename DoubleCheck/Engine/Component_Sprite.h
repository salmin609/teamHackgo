
/*
 * Author		:jeesoo.kim
 * File			:Component_Sprite.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Header file for Component_Sprite.cpp
 *
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */

#pragma once
#include "Component.hpp"
#include "Shader.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "Image.hpp"
#include "Texture.hpp"

class Sprite : public Component
{
public:
	Sprite(Object* obj, bool need_debug_drawing = false);
	Sprite(Object* obj, const char* staticSpritePath, vector2 position, bool need_debug_drnawing = true);
    Sprite(Object* obj, const char* aniamtedSpritePath, bool animated, int frames, float m_speed, vector2 position, vector2 scale, Color4ub color = { 255,255,255,255 });
	void Init(Object* obj) override;
	void Update(float dt) override;
	bool Can_Load_To_Texture(Texture& texture, const char* file_path);

	material& Get_Material()
	{
		return material;
	}
	Vertices& Get_Shape()
	{
		return shape;
	}
private:

	Shader debug_shader;
	Vertices debug_shape;
	material debug_material;

	Shader shader;
	Vertices shape;
	material material;
	Texture texture;
	Image image;


	float seconds = 0;
	int width = 1280, height = 720;

	bool is_animated = false;
	int frame = 0;
	int speed = 100;
	float spriteWidth = 0;
};