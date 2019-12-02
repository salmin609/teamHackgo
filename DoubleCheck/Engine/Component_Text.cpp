#include <GL/glew.h>
#include <iostream>
#include "Component_Text.h"

TextComp::TextComp(Object* obj, std::wstring text_string, Color4f color, vector2 size){


	view.SetViewSize(width, height);
	textMaterial.shader = &SHADER::textured();
	textMaterial.color4fUniforms[SHADER::Uniform_Color] = color;
	textMaterial.floatUniforms[SHADER::Uniform_Depth] = 0.0f;
	if (!font.LoadFromFile(L"../assets/malgungothic.fnt"))
	{
		std::cout << "Failed to Load Font!" <<std::endl;
	}
	Mesh square;
	square = MESH::create_rectangle(size.x, size.y, { 100,100,100,255 });
	lineVertices.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());
	m_owner = obj;
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
	text_size = size;
	text.SetFont(font);
	text.SetString(text_string);
	text_position = m_owner->GetTransform().GetTranslation();
}

void TextComp::Init(Object* obj)
{
	m_owner = obj;
}

void TextComp::Update(float dt)
{
	//const float left = -width * 0.5f + text_position.x;
	//const float top = height * 0.5f - text_position.y;
	///*textMaterial.matrix3Uniforms[SHADER::Uniform_ToNDC] =
	//	view.GetCameraToNDCTransform() * MATRIX3::build_translation(left, top);*/
	//matrix3 mat_ndc = Graphic::GetGraphic()->Get_View().Get_Camera_View().GetCameraToNDCTransform();
	//mat_ndc *= Graphic::GetGraphic()->Get_View().Get_Camera().WorldToCamera();
	//mat_ndc *= m_owner->GetTransform().GetModelToWorld();
	//for (const auto& vertices_texture_pair : text.GetVerticesWithMatchingTextures())
	//{
	//	const Vertices& text_vertices = *vertices_texture_pair.first;
	//	const Texture* text_texture = vertices_texture_pair.second;
	//	textMaterial.textureUniforms.insert_or_assign(SHADER::Uniform_Texture, texture_uniform{ text_texture });
	//	Graphic::GetGraphic()->Draw(lineVertices, textMaterial);
	//}
	//textMaterial.floatUniforms["time"] = seconds;


	const float left = /*-width * 0.5f + */m_owner->GetTransform().GetTranslation().x;
	const float top = /*height * 0.5f - */m_owner->GetTransform().GetTranslation().y;

	lineVertices.UpdateVerticesFromMesh(m_owner->GetMesh());

	textMaterial.matrix3Uniforms["to_ndc"] =
		view.GetCameraToNDCTransform() * MATRIX3::build_translation(left, top);
	
	for (auto& vertices_texture_pair : text.GetVerticesWithMatchingTextures())
	{
		Vertices& text_vertices = *vertices_texture_pair.first;
		const Texture* text_texture = vertices_texture_pair.second;
		textMaterial.textureUniforms.insert_or_assign(SHADER::Uniform_Texture, texture_uniform{ text_texture });
		Graphic::GetGraphic()->Draw(text_vertices, textMaterial);
	}
	textMaterial.floatUniforms["time"] = seconds;
}
