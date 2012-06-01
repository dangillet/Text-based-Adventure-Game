#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <unordered_map>
#include <string>

#include "drawable.h"

class Room;
class Character;
class Object;

typedef std::shared_ptr<Room>       RoomPtr;
typedef std::shared_ptr<Object>     ObjectPtr;

class World : public Drawable
{
    public:


        World();
        ~World();

        void AddRoom(int id, RoomPtr sp_room);
        RoomPtr GetRoomById(int id) const;
        RoomPtr GetPlayerRoom() const;
        const std::string& GetRoomName(int id);
        ObjectPtr GetObjectByName(const std::string& name) const;
        void LoadWorld(const std::string& filename);

        std::shared_ptr<Character> GetPlayer();

        void Draw(Renderer& renderer) const;

    protected:
    private:

        std::unordered_map<int, RoomPtr>    m_rooms;
        std::shared_ptr<Character>          m_player;

};

#endif // WORLD_H
