
/*
 * Author		:minseok.sung
 * File			:Messagebox.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:header file for Messagebox.cpp
 */

#pragma once


#include "Texture.hpp"
class Messagebox
{
public:

	static void Init_Box(const std::filesystem::path& file_path);
	void Process(const std::string& fileName);
};