#include "object.h"
#include "renderer.h"


Object::Object(const std::string& name, const std::string& description) :
    m_name(name),
    m_description(description)
{

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

// ========== Hammer ===============

std::string Hammer::Examine()
{
    return "This is an old hammer. Probably not worth 1 gp.";
}

std::string Hammer::Open()
{
    return "Can't open a hammer.";
}

std::string Hammer::UseWith(Object &obj)
{
    return "This is not useful";
}

std::shared_ptr<Object> Hammer::GetObjectByName(const std::string& name)
{
    if(Object::m_name == name) return shared_from_this();
    return std::shared_ptr<Object>();
}

// =============== Chest =============

Chest::Chest():
    Object("a chest", "This is a sturdy wooden chest."),
    m_container(),
    m_locked(true) {}

std::string Chest::Examine()
{
    std::string description = GetDescription();
    if(m_locked) description += "\nThe chest seems to be locked.";
    if(!m_container.empty() && !m_locked)
    {
        description += "\nThe chest is not empty. It contains : ";
        for(auto& pObject : m_container) description += pObject->GetName() + ", ";

        return description;
    }

}

std::string Chest::Open()
{
    m_locked = false;
    return "You unlocked the chest. Now you could examine its content.";
}

std::string Chest::AddItem(ObjectPtr object)
{
    m_container.push_back(object);
    return "";
}

std::shared_ptr<Object> Chest::GetObjectByName(const std::string& name)
{
    if(m_name == name) return shared_from_this();

    for(auto p_object : m_container)
    {
        auto p_foundObject = p_object->GetObjectByName(name);
        if(p_foundObject) return p_foundObject;
    }
    return std::shared_ptr<Object>();
}
