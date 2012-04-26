#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "drawable.h"

class Renderer;


class Object
{
    public:
        typedef std::unique_ptr<Object> ObjectPtr;
        virtual ~Object(){};
        virtual std::string Examine() = 0;
        virtual std::string Open() = 0;
        virtual std::string UseWith(Object &obj) = 0;
        virtual std::string SetLock(bool lock);
        virtual std::string AddItem(ObjectPtr object);


        const std::string& GetName() const { return m_name; }
        const std::string& GetDescription() const { return m_description; }
    protected:
        Object(const std::string& name, const std::string& description);

    private:
        std::string m_name;
        std::string m_description;
};

typedef std::shared_ptr<Object> ObjectPtr;

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
    Chest(std::string a_name, std::string a_description);

    std::string addItem(Object &obj);
    std::string open();
};

#endif // OBJECT_H
