/*
 * Author		:Sangmin.kim
 * File			:Source.cpp
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:Containing the main function of our engine.
 */

#include "Engine.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include "Messagebox.h"
int main()
{
	Engine engine;
	engine.Init();
	while (!engine.IsDone())
		engine.Update();

	engine.Delete();
	return 0;
}
