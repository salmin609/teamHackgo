#include "BitmapFont.hpp"
#include "Mesh.hpp"
#include "StockShaders.hpp"
#include "Text.hpp"

    Text::Text(std::wstring text_string, const BitmapFont& text_font) noexcept 
    {
        string = text_string;
        font   = &text_font;
        InitializeWithEmptyVertices();
    }

    std::vector<std::pair<const Vertices*, const Texture*>> Text::GetVerticesWithMatchingTextures() const noexcept
    {
        std::vector<std::pair<const Vertices*, const Texture*>> newMesh;

        for (int i = 0; i < font->GetInformation().pagesCount; i++)
        {
            std::pair pairVerticesTexture(&vertices.at(i), &font->GetTexture(i));
            newMesh.push_back(pairVerticesTexture);
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
            string        = text_string;
            needNewMeshes = true;
            BuildNewMeshesIfNeeded();
        }
    }

    const BitmapFont* Text::GetFont() const noexcept
    { 
        return font;
    }

    void Text::SetFont(const BitmapFont& text_font) noexcept
    {
        vertices.clear();
        font          = &text_font;
        needNewMeshes = true;
    }

    void Text::InitializeWithEmptyVertices() const noexcept
    {
        Mesh mesh;
        for (int i = 0; i < font->GetInformation().pagesCount; i++)
        {
            vertices.insert_or_assign(font->GetInformation().pagesCount,
                                      Vertices(mesh, SHADER::textured_vertex_layout())); 
        }       
    }

    void Text::BuildNewMeshesIfNeeded() const noexcept
    { 
        if (needNewMeshes)
        {
            Mesh                  png0;
            Mesh                  png2;
            Mesh                  png3;
            BitmapFont::character characterNumber;
            std::pair<int, int>   cursor = {0, 0};

            for (int count = 0; count < string.size(); count++)
            {
                float left  = static_cast<float>(cursor.first) + font->GetCharacter(string[count]).xOffset;
                float right = left + font->GetCharacter(string[count]).width;
                float bottom =
                    (font->GetCharacter(string[count]).yOffset + font->GetCharacter(string[count]).height) * -1 +
                    font->GetLineHeight() + static_cast<float>(cursor.second);
                float top              = bottom + font->GetCharacter(string[count]).height;
                float left_up_point    = font->GetCharacter(string[count]).x;
                float left_Uvec        = left_up_point / font->GetInformation().imageWidth;
                float right_up_point   = left_up_point + font->GetCharacter(string[count]).width;
                float right_Uvec       = right_up_point / font->GetInformation().imageWidth;
                float left_down_point  = font->GetCharacter(string[count]).y;
                float top_Vvec         = left_down_point / font->GetInformation().imageHeight;
                float right_down_point = left_down_point + font->GetCharacter(string[count]).height;
                float bottom_Vvec      = right_down_point / font->GetInformation().imageHeight;
                characterNumber = font->GetCharacter(string[static_cast<wchar_t>(count)]);

                if (string[count] == L' ')
                {
                    cursor.first += font->GetCharacter(string[count]).xAdvance;
                }
                else if (string[count] == L'\t')
                {
                    cursor.first += 4 * font->GetCharacter(string[count]).xAdvance;
                }
                else if (string[count] == L'\n')
                {
                    cursor.first = 0;
                    cursor.second -= font->GetLineHeight();
                }
                else
                {
                    if (characterNumber.page == 0)
                    {
                        png0.SetPointListType(PointListPattern::Triangles);

                        png0.AddPoint(vector2{left, top});
                        png0.AddTextureCoordinate(vector2{left_Uvec, top_Vvec});
                        png0.AddPoint(vector2{left, bottom});
                        png0.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png0.AddPoint(vector2{right, top});
                        png0.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png0.AddPoint(vector2{right, top});
                        png0.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png0.AddPoint(vector2{left, bottom});
                        png0.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png0.AddPoint(vector2{right, bottom});
                        png0.AddTextureCoordinate(vector2{right_Uvec, bottom_Vvec});

                        vertices[characterNumber.page].InitializeWithMeshAndLayout(png0,                                                                                SHADER::textured_vertex_layout());
                    }
                    if (characterNumber.page == 1)
                    {
                        png2.SetPointListType(PointListPattern::Triangles);

                        png2.AddPoint(vector2{left, top});
                        png2.AddTextureCoordinate(vector2{left_Uvec, top_Vvec});
                        png2.AddPoint(vector2{left, bottom});
                        png2.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png2.AddPoint(vector2{right, top});
                        png2.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png2.AddPoint(vector2{right, top});
                        png2.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png2.AddPoint(vector2{left, bottom});
                        png2.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png2.AddPoint(vector2{right, bottom});
                        png2.AddTextureCoordinate(vector2{right_Uvec, bottom_Vvec});

                        vertices[characterNumber.page].InitializeWithMeshAndLayout(png2,                                                                                SHADER::textured_vertex_layout());
                    }
                    if (characterNumber.page == 2)
                    {
                        png3.SetPointListType(PointListPattern::Triangles);

                        png3.AddPoint(vector2{left, top});
                        png3.AddTextureCoordinate(vector2{left_Uvec, top_Vvec});
                        png3.AddPoint(vector2{left, bottom});
                        png3.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png3.AddPoint(vector2{right, top});
                        png3.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png3.AddPoint(vector2{right, top});
                        png3.AddTextureCoordinate(vector2{right_Uvec, top_Vvec});
                        png3.AddPoint(vector2{left, bottom});
                        png3.AddTextureCoordinate(vector2{left_Uvec, bottom_Vvec});
                        png3.AddPoint(vector2{right, bottom});
                        png3.AddTextureCoordinate(vector2{right_Uvec, bottom_Vvec});

                        vertices[characterNumber.page].InitializeWithMeshAndLayout(png3,
                                                                                SHADER::textured_vertex_layout());
                    }
                    cursor.first += font->GetCharacter(string[count]).xAdvance;                }
            }
        }
     }



