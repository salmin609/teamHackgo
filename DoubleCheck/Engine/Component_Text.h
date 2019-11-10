#pragma once
#include "Component.hpp"
#include "Text.hpp"
#include "BitmapFont.hpp"
#include "Mesh.hpp"
#include <GL/glew.h>
#include "StockShaders.hpp"
#include "Graphic.h"
#include "Shader.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "Texture.hpp"
#include "Object.h"
class TextComp : public Component
{
public:
	TextComp();
	TextComp(Object* obj, std::wstring text_string, Color4f color, vector2 size);
	void Init(Object* obj) override;
	void Update(float dt) override;

private:
	BitmapFont      font{};
	Text text{};
	material textMaterial{};
	CameraView      view{};
	Vertices        lineVertices{};
	float seconds = 0;
	int width = 1280;
	int height = 720;
	vector2 text_position;
	vector2 text_size;
};