#include "objectcontainer.h"
#include <algorithm>
#include "object.h"

ObjectContainer::ObjectContainer() :
    m_container()
{
    //ctor
}

ObjectContainer::~ObjectContainer()
{
    //dtor
}

void ObjectContainer::AddObject(ObjectPtr object)
{
    m_container.push_back(object);
}

void ObjectContainer::RemoveObject(ObjectPtr object)
{
    m_container.erase(std::remove(m_container.begin(), m_container.end(), object), m_container.end());
}

ObjectPtr ObjectContainer::GetObjectByName(const std::string& name)
{
    for(auto p_object : m_container)
    {
        std::shared_ptr<Object> p_foundObject = p_object->GetObjectByName(name);
        if(p_foundObject) return p_foundObject;
    }
    return std::shared_ptr<Object>();
}

std::string ObjectContainer::Inventory() const
{
    std::string inventory("");
    if(!m_container.empty())
    {
        auto iterObject = m_container.cbegin(), iterEnd = m_container.cend();
        while(true)
        {
            inventory += (*iterObject)->GetName();
            if(++iterObject == iterEnd) break;
            inventory += ", ";
        }
    }
    return inventory;
}

