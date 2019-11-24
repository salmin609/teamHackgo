#include "Message_Manager.h"

Message_Manager* Message_Manager::msg_manager = nullptr;

Message_Manager* Message_Manager::Get_Message_Manager()
{
    if (msg_manager == nullptr)
        msg_manager = new Message_Manager();

    return msg_manager;
}
void Message_Manager::Save_Message(Message* msg)
{
    messages.push_back(msg);
}


void Message_Manager::Init()
{

}
void Message_Manager::Update(float dt)
{
    if(!messages.empty())
    {
        delete_msg.clear();

        for(int i = 0; i < messages.size(); i++)
        {
            messages[i]->Update(dt);

            if(messages[i]->Get_Should_Delete())
            {
                delete_msg.push_back(messages[i]);
            }
        }
        for(auto& delete_msg : this->delete_msg)
        {
            messages.erase(std::find(messages.begin(), messages.end(), delete_msg));
        }

        //messages.clear();
    }
}
void Message_Manager::Delete()
{

}
