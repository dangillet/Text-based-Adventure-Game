#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <vector>
#include <string>

class Room;
class Player;

class World
{
    public:
        World();
        virtual ~World();

    protected:
    private:
        void LoadWorld(const std::string& filename);

        typedef std::shared_ptr<Room>       RoomPtr;
        std::vector<RoomPtr>                m_rooms;
        std::shared_ptr<Player>             m_player;

};

#endif // WORLD_H
