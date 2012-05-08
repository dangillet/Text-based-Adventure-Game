#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <unordered_map>
#include <string>

#include "drawable.h"

class Room;
class Character;

class World : public Drawable
{
    public:
        typedef std::shared_ptr<Room>       RoomPtr;

        World();
        ~World();

        void AddRoom(int id, RoomPtr sp_room);
        const RoomPtr& GetRoomById(int id) const;
        RoomPtr GetPlayerRoom();
        const std::string& GetRoomName(int id);
        void LoadWorld(const std::string& filename);

        std::shared_ptr<Character> GetPlayer();

        void Draw(Renderer& renderer) const;

    protected:
    private:

        std::unordered_map<int, RoomPtr>    m_rooms;
        std::shared_ptr<Character>          m_player;

};

#endif // WORLD_H
