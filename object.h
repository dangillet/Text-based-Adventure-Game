#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

#include "drawable.h"

class Renderer;

class Object
{
    public:
        typedef std::unique_ptr<Object> ObjectPtr;
        virtual ~Object() {};
        virtual std::string Examine() = 0;
        virtual std::string Open() = 0;
        virtual std::string UseWith(Object &obj) = 0;
        // Should the following be here or only in the class where these things are possible ?
        virtual std::string SetLock(bool lock);
        virtual std::string AddItem(ObjectPtr& object);
        virtual Object* GetObjectByName(const std::string& name) const = 0;

        const std::string& GetName() const { return m_name; }
        const std::string& GetDescription() const { return m_description; }
    protected:
        Object(const std::string& name, const std::string& description);

    private:
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
        virtual Object* GetObjectByName(const std::string& name) const {return nullptr;}
};

/*
class Key : public Object
{
    public:
    Key(std::string name, std::string description);

    std::string useWith(Object &obj);
};


class Door : public Object
{
  public:
  Door(std::string name, std::string description, bool lock);

  std::string setLock(bool lock);
  private:
    bool    m_lock;
};
*/
class Chest : public Object
{
    public:
    Chest();

    std::string Examine() {}
    std::string Open() {}
    std::string UseWith(Object &obj) {}
    std::string AddItem(ObjectPtr& object);

    virtual Object* GetObjectByName(const std::string& name) const {};

    private:
    std::unordered_map<std::string, ObjectPtr> m_container;
};

#endif // OBJECT_H
