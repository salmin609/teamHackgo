#pragma once
#include "Object.h"


class Referee : public Object
{
public:
	enum Refree_Statement
	{

	};
	enum Stage_Statement
	{
		NONE = 99,
		PLAYER_FIRST_DIE = 100,
		PLAYER_SECOND_DIE = 101,
		PLAYER_THIRD_DIE = 102,
		PLAYER_FOURTH_DIE = 103
	};

	static Referee* Get_Referee();
	void Init();
	void Update(float dt);
	void Delete();
	std::vector<Stage_Statement>& Get_Stage_Statement()
	{
		return stage_statements;
	}
	void Respawn(Stage_Statement statement);

private:
    Referee(){}
    static Referee* referee;


    std::vector<Stage_Statement> stage_statements;

    float player_second_respawn_timer = 3.0f;
    float player_first_respawn_timer = 3.0f;

    float player_third_respawn_timer = 3.0f;
    float player_fourth_respawn_timer = 3.0f;

    Object** player_sec_temp;
    Object** player_first_temp;

    Object** player_third_temp;
    Object** player_fourth_temp;

    int player_sec_life = 3;
    int player_first_life = 3;

    int player_third_life = 3;
    int player_fourth_life = 3;

    Object** item_save;
    float item_respawn_timer = 0.0f;
    int item_num = 5;
};