#pragma once
#include "Component.hpp"

class Item : public Component
{
public:
    enum class Item_Kind
    {
        None,
        Dash
    };

    void Init(Object *obj) override;
    void Update(float dt) override;
    void Set_Kind(Item_Kind kind);

private:
    Item_Kind this_kind = Item_Kind::None;

};