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
    m_exits(exits)
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

    std::string inventory = Inventory();
    if(inventory != "")
    {
        renderer.DrawText("You see : ");
        renderer.DrawText(inventory + "\n");
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
