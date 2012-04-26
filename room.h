#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "object.h"
#include "drawable.h"


class Room : public Drawable
{
    public:

        typedef std::unordered_map<std::string, ObjectPtr> Loot;
        Room(int ID, const std::string& name, const std::string& description,
             const std::vector<int>& exits, const Loot& objects,
             Renderer& renderer);
        ~Room();



        const std::string& GetName() const { return m_name; }
        const std::string& GetDescription() const { return m_description; }

        ObjectPtr PickUp(const std::string& name);
        void Draw() const;
    protected:
    private:
        int                         m_ID;
        std::string                 m_name;
        std::string                 m_description;
        std::vector<int>            m_exits;
        Loot                        m_loot;
};

#endif // ROOM_H
