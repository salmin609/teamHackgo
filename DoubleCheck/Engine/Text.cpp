#include <iostream>
#include "Mesh.hpp"
#include "StockShaders.hpp"
#include "Text.hpp"

#include <exception>
#include <fstream>
#include "Messagebox.h"
Text::Text(std::wstring text_string, const BitmapFont& text_font) noexcept
{
	string = text_string;
	font = &text_font;
	InitializeWithEmptyVertices();
}

std::vector<std::pair<Vertices*, const Texture*>> Text::GetVerticesWithMatchingTextures() const noexcept
{
	BuildNewMeshesIfNeeded();
	std::vector<std::pair<Vertices*, const Texture*>> newMesh;
	for (int i = 0; i < vertices.size(); ++i)/*font->GetInformation().pagesCount*/
	{
		if (vertices.at(i).GetVerticesCount() != 0)
		{
			newMesh.push_back(std::pair<Vertices*, const Texture*>{&vertices.at(i), & font->GetTexture(i)});
		}
	}
	return newMesh;
}

std::wstring Text::GetString() const noexcept
{
	return string;
}

void Text::SetString(const std::wstring& text_string) noexcept
{
	if (text_string.compare(string))
	{
		string = text_string;
		needNewMeshes = true;
	}
}

const BitmapFont* Text::GetFont() const noexcept
{
	return font;
}

void Text::SetFont(const BitmapFont& text_font) noexcept
{
	font = &text_font;
	InitializeWithEmptyVertices();
	needNewMeshes = true;
}

void Text::InitializeWithEmptyVertices() const noexcept
{
	vertices.clear();
	Mesh mesh;
	for (int i = 0; i < font->GetInformation().pagesCount; i++)
	{
		vertices.insert_or_assign(font->GetInformation().pagesCount,
			Vertices(mesh, SHADER::textured_vertex_layout()));
	}
}

void Text::BuildNewMeshesIfNeeded() const noexcept
{
	if (needNewMeshes == false)
	{
		return;
	}

	const BitmapFont::information& information = font->GetInformation();

	for (unsigned short i = 0; i < information.pagesCount; ++i)
	{
		Mesh     png;
		Vertices vertice;
		vector2  cursor{ 0.f };
		for (const auto& element : string)
		{
			const BitmapFont::character& character = font->GetCharacter(element);
			png.SetPointListType(PointListPattern::Triangles);

			if (element == L' ')
			{
				if (font->HasCharacter(wchar_t(' ')))
				{
					cursor.x += character.xAdvance;
				}
				else
				{
					cursor.x += information.fontSize;
				}
			}
			else if (element == L'\t')
			{
				if (font->HasCharacter(wchar_t(' ')))
				{
					cursor.x = 4.f * character.xAdvance;
				}
				else
				{
					cursor.x = 4.f * information.fontSize;
				}
			}
			else if (element == L'\n')
			{
				cursor.x = 0;
				cursor.y -= information.lineHeight;
			}
			else if (character.page == i)
			{

				const float left = character.xOffset + cursor.x;
				const float bottom = (character.yOffset + character.height) * -1 + font->GetLineHeight() + cursor.y;
				const float right = left + character.width;
				const float top = bottom + character.height;

				const float left_u = static_cast<float>(character.x) / information.imageWidth;
				const float right_u = static_cast<float>(character.x + character.width) / information.imageWidth;
				const float top_v = static_cast<float>(character.y) / information.imageHeight;
				const float bottom_v = static_cast<float>(character.y + character.height) / information.imageHeight;

				png.AddPoint(vector2{ left, top });
				png.AddTextureCoordinate(vector2{ left_u, top_v });
				png.AddPoint(vector2{ right, top });
				png.AddTextureCoordinate(vector2{ right_u, top_v });
				png.AddPoint(vector2{ left, bottom });
				png.AddTextureCoordinate(vector2{ left_u, bottom_v });

				png.AddPoint(vector2{ right, top });
				png.AddTextureCoordinate(vector2{ right_u, top_v });
				png.AddPoint(vector2{ left, bottom });
				png.AddTextureCoordinate(vector2{ left_u, bottom_v });
				png.AddPoint(vector2{ right, bottom });
				png.AddTextureCoordinate(vector2{ right_u, bottom_v });

				cursor.x += character.xAdvance;
			}
			else
			{
				cursor.x += character.xAdvance;
			}
		}
		vertice.InitializeWithMeshAndLayout(png, SHADER::textured_vertex_layout());
		vertices.insert_or_assign(i, std::move(vertice));
	}
	needNewMeshes = false;
}




