#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "room.h"

class Character
{
    public:
        typedef std::shared_ptr<Object> ObjectPtr;
        Character();
        ~Character();

        std::shared_ptr<Room> GetLocation() { return m_location; }
        void SetLocation(const std::shared_ptr<Room>& the_room) { m_location = the_room; }
        void AddItemToInventory(ObjectPtr obj);

        std::string ShowInventory();
        std::vector<ObjectPtr> AccessInventory() const { return m_inventory; }
    protected:
    private:
        std::shared_ptr<Room>                   m_location;
        std::vector<ObjectPtr>                  m_inventory;
};

#endif // CHARACTER_H
