#include "room.h"
#include "renderer.h"
#include <algorithm>

Room::Room(int ID, const std::string& name, const std::string& description,
             const std::vector<int>& exits, const Loot& objects,
             Renderer& renderer) :
    Drawable(renderer),
    m_ID(ID),
    m_name(name),
    m_description(description),
    m_exits(exits),
    m_loot(objects)
{
    //ctor
}

Room::~Room()
{
    //dtor
}

void Room::Draw() const
{
    m_renderer.DrawRoom(*this);
}

ObjectPtr Room::PickUp(const std::string& name)
{
    ObjectPtr temp = m_loot[name];
    m_loot.erase(name);
    return temp;
}
