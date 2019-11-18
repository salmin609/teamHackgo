#pragma once


#include "Texture.hpp"
class Messagebox
{
public:

	static void Init_Box(const std::filesystem::path& file_path);
	void Process(const std::string& fileName);
};