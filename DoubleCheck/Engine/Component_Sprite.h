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
    void Init(Object *obj) override;
    void Update(float dt) override;
	bool can_load_to_texture(Texture& texture, const char* file_path);
private:
    Shader shader;
    Vertices shape;
    material material;
    Texture texture;
    Image image;

    float seconds = 0;
    int width = 1280, height = 720;
};