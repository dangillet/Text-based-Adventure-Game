#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "room.h"
#include "objectcontainer.h"

class Character : public ObjectContainer
{
    public:
        typedef std::shared_ptr<Object> ObjectPtr;
        Character();
        ~Character();

        std::shared_ptr<Room> GetLocation() { return m_location; }
        void SetLocation(const std::shared_ptr<Room>& the_room) { m_location = the_room; }

    protected:
    private:
        std::shared_ptr<Room>                   m_location;
};

#endif // CHARACTER_H
