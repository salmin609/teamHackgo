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

    std::unordered_map<std::string, std::shared_ptr<State>> Get_States()
    {
        return states;
    }

    bool is_pause = true;
private:
    static StateManager* state_manager;

    std::unordered_map<std::string, std::shared_ptr<State>> states;
    State* current_state = nullptr;
};