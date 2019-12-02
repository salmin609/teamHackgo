#include "MainMenu.h"
#include "Input.h"

bool MouseCollision(vector2 position_max, vector2 position_min)
{
    Input input;
    vector2 mouse_pos = input.Get_Mouse_Pos();

    if(mouse_pos.x < position_max.x && mouse_pos.x > position_min.x && mouse_pos.y < position_max.y && mouse_pos.y > position_min.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
