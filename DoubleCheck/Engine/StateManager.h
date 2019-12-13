/*
 * Author		:sangmin.kim
 * File			:StateManager.h
 * Term			:2019 Fall
 * Class		:GAM200
 * Project		:GAM200 Project
 * Date			:2019/12/11
 * Description	:header file for StateManager.cpp
 * copyright   All content ?2019 DigiPen (USA) Corporation, all rights reserved
 */


#pragma once
#include "State.h"
#include <unordered_map>
#include <memory>

class StateManager
{
public:
    static StateManager* GetStateManager();
    void Init();
    void Update(float dt);
    void Delete();
    void AddState(std::string name, State* state);
    void DeleteState(std::shared_ptr<State> state);
	/*void Set_State(GameState get_states)
	{
		get_current_state = get_states;
	}
	GameState& Get_Current_States()
	{
		return get_current_state;
	}*/
    std::unordered_map<std::string, std::shared_ptr<State>> Get_States()
    {
        return states;
    }

    bool is_pause = true;
private:
    static StateManager* state_manager;
	//GameState get_current_state;
    std::unordered_map<std::string, std::shared_ptr<State>> states;
    State* current_state = nullptr;
};