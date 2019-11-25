#include "MainMenu.h"
#include "Input.h"

 void MainMenu::Load()
{

}

 void MainMenu::Update(float dt)
 {
	 if (input.Is_Key_Triggered(GLFW_KEY_N))
	 {
		 is_next = true;
		 next_level = "Level1";
	 }
 }
