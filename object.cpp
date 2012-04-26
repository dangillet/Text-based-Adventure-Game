#include "object.h"
#include "renderer.h"


Object::Object(const std::string& name, const std::string& description) :
    m_name(name),
    m_description(description)
{

}

std::string Object::Examine()
{
    return GetDescription();
}

std::string Object::Open()
{
    return "This cannot be opened.";
}

std::string Object::UseWith(Object &obj)
{
    return "This doesn't work.";
}

std::string Object::SetLock(bool lock)
{
    return "This doesn't work.";
}
std::string Object::AddItem(ObjectPtr object)
{
    return "This item cannot store anything.";
}


/*
Key::Key(std::string name, std::string description) :
    Object(name, description)
{

}
std::string Key::useWith(Object &obj)
{
    if(obj.GetName() == "a door")
    {
        obj.SetLock(false);
        return "The door is unlocked";
    }
    return "Nothing happens.";
}

Door::Door(std::string a_name, std::string a_description, bool lock) : Object(a_name, a_description)
{
    SetLock(lock);
}
std::string Door::setLock(bool lock)
{
    return "Not implemented yet.";
}

Chest::Chest(std::string a_name, std::string a_description) : Object(a_name, a_description)
{

}
string Chest::addItem(Object &obj)
{
    container.push_back(&obj);
    return obj.Getname() + " is stored in the chest.";

}
string Chest::open()
{
    for(unsigned int i=0; i< container.size(); i++)
    {
        cout << container[i]->Getname() << endl;
        // Add these items to where the chest belong (inventory or the room).

    }
    return "The Chest is opened";
}

*/
