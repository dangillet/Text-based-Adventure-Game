#include "world.h"
#include "room.h"
#include "character.h"

#include <fstream>
#include <cassert>
#include <iterator>

typedef std::shared_ptr<Room>       RoomPtr;

World::World() :
    m_rooms(),
    m_player(std::make_shared<Character>())
{
    //ctor
}

World::~World()
{
    //dtor
}

void World::AddRoom(int id, RoomPtr sp_room)
{
    m_rooms[id] = sp_room;
}

void World::Draw(Renderer& renderer) const
{
    m_player->GetLocation()->Draw(renderer);
}

const RoomPtr& World::GetRoom(int id) const
{
    return m_rooms.at(id);
}

RoomPtr World::GetPlayerRoom()
{
    return m_player->GetLocation();
}
const std::string& World::GetRoomName(int id)
{
    return m_rooms[id]->GetName();
}

void World::LoadWorld(const std::string& filename)
{
    std::ifstream file(filename);
    assert(file.is_open());

    std::string str;
    while(file >> str)
    {
        while(str == "Room:")
        {
            int id;
            file >> id;
            file >> str;
            std::string name, description;
            std::ws(file);
            std::getline(file, name);
            file >> str;
            std::ws(file);
            std::getline(file, description);
            file >> str;
            int exit;
            std::unordered_set<int> exits;
            while(file >> exit)
            {
                exits.insert(exit);
            }

            auto room = std::make_shared<Room>(*this, id, name, description, exits);
            AddRoom(id, room);
            file.clear();
            file >> str;
            while(str == "Object:")
            {
                std::getline(file, str);
                room->AddObject(str, std::make_shared<Hammer>(str));

                file >> str;
            }
        }
    }
    m_player->SetLocation(GetRoom(1));
}

std::shared_ptr<Character> World::GetPlayer()
{
    return m_player;
}
