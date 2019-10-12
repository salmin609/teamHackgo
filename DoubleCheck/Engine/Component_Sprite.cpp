#include "Component_Sprite.h"
#include "angles.hpp"
#include "Mesh.hpp"
#include <GL/glew.h>
#include "StockShaders.hpp"
#include "Graphic.h"
#include "Object.h"


void Helper_Addpoint_Circle(std::size_t& point_count, Mesh& mesh, float& radius, float position_x = 0, float position_y = 0, bool move_up_down = true)
{
    float theta;
    float location_x;
    float location_y;
    for (int i = 1; i <= point_count + 1; i++)
    {
        theta = (TWO_PI * i) / static_cast<float>(point_count);
        location_x = (radius * cosf(theta)) - position_x;
        location_y = (radius * sinf(theta)) - position_y;
        mesh.AddPoint({ location_x,location_y });
        if (move_up_down)
        {
            mesh.AddTextureCoordinate({ to_radians(270.f), 10.f });
        }
        else if (!move_up_down)
        {
            mesh.AddTextureCoordinate({ to_radians(180.f), 10.f });
        }
    }

}
void Helper_Addpoint_Ellipse(std::size_t& point_count, Mesh& mesh, float& radius, float position_x = 0, float position_y = 0)
{
    float theta;
    float location_y;
    float location_x;
    for (int i = 1; i <= point_count + 1; i++)
    {
        theta = (TWO_PI * i) / static_cast<float>(point_count);
        location_x = (radius * cosf(theta)) - position_x;
        location_y = (radius * sinf(theta) / 2) - position_y;
        mesh.AddPoint({ location_x ,location_y });
        mesh.AddTextureCoordinate({ to_radians(270.f), 10.f });
    }
}

Mesh m_create_circle(float radius, Color4ub color, std::size_t point_count, vector2 origin = { 0.1f, 0.1f }, bool is_ellipse = false, float location_x = 0, float location_y = 0, bool move_up_down = true) noexcept
{
    Mesh temp_mesh;
    (origin);
    temp_mesh.AddColor(color);
    temp_mesh.SetPointListType(PointListPattern::TriangleFan);
    if (!is_ellipse)
    {
        Helper_Addpoint_Circle(point_count, temp_mesh, radius, location_x, location_y, move_up_down);
    }
    else if (is_ellipse)
    {
        Helper_Addpoint_Ellipse(point_count, temp_mesh, radius, location_x, location_y);
    }

    return temp_mesh;
}

Mesh m_create_wire_circle(float radius, Color4ub color, std::size_t point_count) noexcept
{
    Mesh temp_mesh;
    temp_mesh.SetPointListType(PointListPattern::LineLoop);
    temp_mesh.AddColor(color);
    Helper_Addpoint_Circle(point_count, temp_mesh, radius);

    return temp_mesh;
}

bool Sprite::Can_Load_To_Texture(Texture& texture, const char* file_path)
{
    const bool is_okay = texture.LoadFromPNG(file_path);
    if (!is_okay)
    {
        std::cerr << "Failed to load \"" << file_path << "\"\n";
    }
    return is_okay;
}


void Sprite::Init(Object* obj)
{
    m_owner = obj;
/*
	const auto path = staticSpritePath;
    material.shader = &(SHADER::textured());
    if(!Can_Load_To_Texture(texture, path))
    {
        std::cout << "fail to load texture" << std::endl;
    }
    texture.SelectTextureForSlot(texture);
    material.textureUniforms["texture_to_sample"] = {&(texture)};
    material.color4fUniforms["color"] = { 1.0f };
    material.matrix3Uniforms["to_ndc"] = MATRIX3::build_scale(2.0f / width, 2.0f / height);

    Mesh square;
    square = MESH::create_box(100, { 100,100,100,255 });
    shape.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());

    m_owner->SetMesh(square);
    m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();

    int size_for_normal = m_owner->GetMesh().Get_Points().size();

    std::vector<vector2> vector_for_normal = m_owner->GetMesh().Get_Points();
    for(int i = 0 ; i < size_for_normal; ++i)
    {
        vector2 normal_vec = vector_for_normal[i];

        normal_vec.x = normal_vec.x / abs(normal_vec.x);
        normal_vec.y = normal_vec.y / abs(normal_vec.y);
        m_owner->Get_Normalize_Points().push_back(normal_vec);
    }
    m_owner->Set_Center({ 0.0f , 0.0f});*/
    
}
/*
 * Original
 */


Sprite::Sprite(Object* obj, const char* staticSpritePath)
{
	m_owner = obj;

	const auto path = staticSpritePath;
	material.shader = &(SHADER::textured());
	if (!Can_Load_To_Texture(texture, path))
	{
		std::cout << "fail to load texture" << std::endl;
	}
	texture.SelectTextureForSlot(texture);
	material.textureUniforms["texture_to_sample"] = { &(texture) };
	material.color4fUniforms["color"] = { 1.0f };
	material.matrix3Uniforms["to_ndc"] = MATRIX3::build_scale(2.0f / width, 2.0f / height);

	Mesh square;
	square = MESH::create_box(100, { 100,100,100,255 });
	shape.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());

	m_owner->SetMesh(square);
	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();

	int size_for_normal = m_owner->GetMesh().Get_Points().size();

	std::vector<vector2> vector_for_normal = m_owner->GetMesh().Get_Points();
	for (int i = 0; i < size_for_normal; ++i)
	{
		vector2 normal_vec = vector_for_normal[i];

		normal_vec.x = normal_vec.x / abs(normal_vec.x);
		normal_vec.y = normal_vec.y / abs(normal_vec.y);
		m_owner->Get_Normalize_Points().push_back(normal_vec);
	}
	m_owner->Set_Center({ 0.0f , 0.0f });

}

Sprite::Sprite(Object* obj, const char* aniamtedSpritePath, bool animated, int frames)
{
	m_owner = obj;
	is_animated = animated;
	frame = frames;
	const auto path = aniamtedSpritePath;
	material.shader = &(SHADER::textured());
	if (!Can_Load_To_Texture(texture, path))
	{
		std::cout << "fail to load texture" << std::endl;
	}
	texture.SelectTextureForSlot(texture);
	material.textureUniforms["texture_to_sample"] = { &(texture) };
	material.color4fUniforms["color"] = { 1.0f };
	material.matrix3Uniforms["to_ndc"] = MATRIX3::build_scale(2.0f / width, 2.0f / height);

	Mesh square;
	square = MESH::create_box(100, { 100,100,100,255 });
	shape.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());

	m_owner->SetMesh(square);
	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();

	int size_for_normal = m_owner->GetMesh().Get_Points().size();

	std::vector<vector2> vector_for_normal = m_owner->GetMesh().Get_Points();
	for (int i = 0; i < size_for_normal; ++i)
	{
		vector2 normal_vec = vector_for_normal[i];

		normal_vec.x = normal_vec.x / abs(normal_vec.x);
		normal_vec.y = normal_vec.y / abs(normal_vec.y);
		m_owner->Get_Normalize_Points().push_back(normal_vec);
	}
	m_owner->Set_Center({ 0.0f , 0.0f });
}

void Sprite::Update(float dt)
{	
    shape.UpdateVerticesFromMesh(m_owner->GetMesh());

    seconds += dt;
	uint32_t ticks = seconds + 1;

	if (is_animated)
	{
		m_owner->GetMesh().ClearTextureCoordinates();		
		if (spriteWidth <= 1)
		{
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
			spriteWidth += float(1.0 / frame);
		}
		else 
		{
			spriteWidth = 0;
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
			m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
			spriteWidth += float(1.0 / frame);
		}
		m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 0 });
		m_owner->GetMesh().AddTextureCoordinate({ spriteWidth , 1 });
		m_owner->SetMesh(m_owner->GetMesh());
		shape.UpdateVerticesFromMesh(m_owner->GetMesh());
	}
    if(m_owner->GetMesh().Get_Is_Moved() || Graphic::GetGraphic()->get_need_update_sprite())
    {
        matrix3 mat_ndc = Graphic::GetGraphic()->Get_View().Get_Camera_View().GetCameraToNDCTransform();
        mat_ndc *= Graphic::GetGraphic()->Get_View().Get_Camera().WorldToCamera();
        mat_ndc *= m_owner->GetTransform().GetModelToWorld();

        m_owner->GetMesh().Get_Is_Moved() = false;
        material.matrix3Uniforms["to_ndc"] = mat_ndc;
    }

    material.floatUniforms["time"] = seconds;

    Graphic::GetGraphic()->Draw(shape, material);
}