#include <Windows.h>
#include <system_error>
#include "Messagebox.h"
#include <iostream>

#include <exception>
#include <fstream>

void Messagebox::Init_Box(const std::filesystem::path& file_path)
{
	int msgboxID = MessageBox(
		NULL,
		file_path.string().c_str(),
		"Check Box",
		MB_ICONEXCLAMATION | MB_OK
	);
	if (msgboxID == MB_OK)
	{
		std::cout << file_path.string() << std::endl;
	}
}
