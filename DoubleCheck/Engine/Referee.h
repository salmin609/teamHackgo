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

};