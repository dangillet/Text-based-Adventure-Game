#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

#include "object.h"
#include "drawable.h"

class World;

class Room : public Drawable
{
    public:

        typedef std::unordered_map<std::string, ObjectPtr> Loot;
        Room(World& world, int ID, const std::string& name, const std::string& description,
             const std::unordered_set<int>& exits = std::unordered_set<int>());
        ~Room();

        const std::string& GetName() const { return m_name; }
        const std::string& GetDescription() const { return m_description; }

        std::shared_ptr<Room> GetExitTo(const std::string& exitName);
        void AddObject(const std::string& name, ObjectPtr object);


        //ObjectPtr PickUp(const std::string& name);
        void Draw(Renderer& renderer) const;
    protected:
    private:
        void RemoveExit(int roomID);

        World&                      m_world;
        int                         m_ID;
        std::string                 m_name;
        std::string                 m_description;
        std::unordered_set<int>     m_exits;
        Loot                        m_loot;
};

#endif // ROOM_H
