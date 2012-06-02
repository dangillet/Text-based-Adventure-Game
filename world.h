#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <unordered_map>
#include <string>

#include "drawable.h"

class Room;
class Character;
class Object;
class ObjectContainer;

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
        ObjectPtr GetObjectByName(const std::string& name, bool lookInPlayerInventory = true) const;
        void LoadWorld(const std::string& filename);

        std::shared_ptr<Character> GetPlayer();
        void PickUpObject(ObjectPtr object);

        void Draw(Renderer& renderer) const;

    protected:
    private:
        void TransferObject(ObjectPtr object, std::shared_ptr<ObjectContainer> from, std::shared_ptr<ObjectContainer> to);

        std::unordered_map<int, RoomPtr>    m_rooms;
        std::shared_ptr<Character>          m_player;

};

#endif // WORLD_H
