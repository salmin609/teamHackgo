#include "Engine.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include "Messagebox.h"
int main()
{
	/*std::ifstream f;
	f.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		Engine engine;
		engine.Init();
		while (!engine.IsDone())
			engine.Update();

		engine.Delete();
		return 0;
	}
	catch (std::system_error & e)
	{
		std::cerr << e.code().message() << std::endl;
		Messagebox::Init_Box(file_path);
	}*/
	
	Engine engine;
	engine.Init();
	while (!engine.IsDone())
		engine.Update();

	engine.Delete();
	return 0;
}
