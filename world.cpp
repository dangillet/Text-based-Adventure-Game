#include "world.h"
#include "room.h"
#include "object.h"
#include "character.h"
#include "objectcontainer.h"

#include <fstream>
#include <cassert>
#include <iterator>

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

RoomPtr World::GetRoomById(int id) const
{
    return m_rooms.at(id);
}

ObjectPtr World::GetObjectByName(const std::string& name, bool lookInPlayerInventory) const
{
    RoomPtr playerRoom = GetPlayerRoom();
    auto object = playerRoom->GetObjectByName(name);
    if(!object && lookInPlayerInventory)
    {
        object = m_player->GetObjectByName(name);
    }
    return object;
}

RoomPtr World::GetPlayerRoom() const
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
                std::ws(file);
                std::getline(file, str);
                if(str == "a hammer")
                {
                    std::shared_ptr<Object> chest(new Chest());
                    room->AddObject(chest);
                    chest->AddItem(std::shared_ptr<Object>(new Hammer()));
                }
                file >> str;
            }
        }
    }
    m_player->SetLocation(GetRoomById(1));
}

std::shared_ptr<Character> World::GetPlayer()
{
    return m_player;
}

void World::PickUpObject(ObjectPtr object)
{
    TransferObject(object, GetPlayerRoom(), m_player);
}

void World::TransferObject(ObjectPtr object, std::shared_ptr<ObjectContainer> from, std::shared_ptr<ObjectContainer> to)
{
    to->AddObject(object);
    from->RemoveObject(object);
}
