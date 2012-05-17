#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "drawable.h"

class Renderer;

class Object : public std::enable_shared_from_this<Object>
{
    public:
        typedef std::shared_ptr<Object> ObjectPtr;
        virtual ~Object() {};
        virtual std::string Examine() = 0;
        virtual std::string Open() = 0;
        virtual std::string UseWith(Object &obj) = 0;
        // Should the following be here or only in the class where these things are possible ?
        virtual std::string SetLock(bool lock);
        virtual std::string AddItem(ObjectPtr object);
        virtual ObjectPtr GetObjectByName(const std::string& name) = 0;

        const std::string& GetName() const { return m_name; }
        const std::string& GetDescription() const { return m_description; }
    protected:
        Object(const std::string& name, const std::string& description);
        std::string m_name;
        std::string m_description;
};



class Hammer : public Object
{
    public:
        Hammer() :
            Object("a hammer", "This is an old hammer. Probably not worth 1 gp.") {}
        std::string Examine();
        std::string Open();
        std::string UseWith(Object &obj);
        virtual ObjectPtr GetObjectByName(const std::string& name);
};

class Chest : public Object
{
    public:
    Chest();

    std::string Examine();
    std::string Open();
    std::string UseWith(Object &obj) { return ""; }
    std::string AddItem(ObjectPtr object);

    virtual ObjectPtr GetObjectByName(const std::string& name);

    private:
    std::vector<ObjectPtr>  m_container;
    bool                    m_locked;
};

#endif // OBJECT_H
