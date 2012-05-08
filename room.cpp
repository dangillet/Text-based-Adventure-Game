#include "room.h"
#include "renderer.h"
#include "world.h"
#include "object.h"
#include <algorithm>

Room::Room(World& world, int ID, const std::string& name, const std::string& description,
             const std::unordered_set<int>& exits) :
    m_world(world),
    m_ID(ID),
    m_name(name),
    m_description(description),
    m_exits(exits),
    m_loot()
{
    //ctor
}

Room::~Room()
{
    for(auto roomID : m_exits)
    {
        m_world.GetRoomById(roomID)->RemoveExit(m_ID);
    }
}

void Room::Draw(Renderer& renderer) const
{
    renderer.DrawText("-----------------------------------------------------------------\n");
    renderer.DrawText(m_name + "\n");
    renderer.DrawText("-----------------------------------------------------------------\n\n");
    renderer.DrawText(m_description + "\n");
    if(!m_loot.empty())
    {
        renderer.DrawText("You see : ");
        auto iterObject = m_loot.cbegin(), iterEnd = m_loot.cend();
        while(true)
        {
            renderer.DrawText(iterObject->second->GetName());
            if(++iterObject == iterEnd) break;
            renderer.DrawText(", ");
        }
        renderer.DrawText("\n");
    }
    if(!m_exits.empty())
    {
        renderer.DrawText("From here you can go to : ");
        auto iterRoom = m_exits.cbegin(), iterEnd = m_exits.cend();
        while(true)
        {
            renderer.DrawText(m_world.GetRoomById(*iterRoom)->GetName());
            if(++iterRoom == iterEnd) break;
            renderer.DrawText(", ");
        }
        renderer.DrawText("\n");
    }
}

/*
ObjectPtr Room::PickUp(const std::string& name)
{
    ObjectPtr temp = m_loot[name];
    m_loot.erase(name);
    return temp;
}
*/

void Room::RemoveExit(int roomID)
{
    m_exits.erase(roomID);
}

std::shared_ptr<Room> Room::GetExitTo(const std::string& exitName)
{
    auto room = std::find_if(m_exits.begin(), m_exits.end(),
                             [&](int id)
                             {
                                 if(m_world.GetRoomName(id) == exitName) return true;
                                 return false;
                             }
                             );
    if(room == m_exits.end()) return nullptr;
    return m_world.GetRoomById(*room);
}

void Room::AddObject(const std::string& name, ObjectPtr object)
{
    m_loot[name] = std::move(object);
}

bool Room::IsObjectAvailable(const std::string& name) const
{
    auto iterObject = m_loot.find(name);
    if(iterObject == m_loot.end()) return false;
    return true;
}

const std::unique_ptr<Object>& Room::GetObjectByName(const std::string& name) const
{
    return m_loot.at(name);
}
